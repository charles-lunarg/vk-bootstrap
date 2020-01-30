#pragma once

#include <cassert>

#include <array>
#include <string>
#include <vector>

#include <vulkan/vulkan.h>

namespace vkbs
{

namespace detail
{

template <typename T> struct Error
{
	T error_code;
	const char* msg;
};
template <typename E, typename U> class Expected
{
	public:
	Expected (const E& expect) : m_expect{ expect }, m_init{ true } {}
	Expected (E&& expect) : m_expect{ std::move (expect) }, m_init{ true } {}
	Expected (const Error<U>& error) : m_error{ error }, m_init{ false } {}
	Expected (Error<U>&& error) : m_error{ std::move (error) }, m_init{ false } {}
	~Expected () { destroy (); }
	Expected (Expected const& expected) : m_init (expected.m_init)
	{
		if (m_init)
			new (&m_expect) E{ expected.m_expect };
		else
			new (&m_error) Error<U>{ expected.m_error };
	}
	Expected (Expected&& expected) : m_init (expected.m_init)
	{
		if (m_init)
			new (&m_expect) E{ std::move (expected.m_expect) };
		else
			new (&m_error) Error<U>{ std::move (expected.m_error) };
		expected.destroy ();
	}

	Expected& operator= (const E& expect)
	{
		destroy ();
		m_init = true;
		new (&m_expect) E{ expect };
		return *this;
	}
	Expected& operator= (E&& expect)
	{
		destroy ();
		m_init = true;
		new (&m_expect) E{ std::move (expect) };
		return *this;
	}
	Expected& operator= (const Error<U>& error)
	{
		destroy ();
		m_init = false;
		new (&m_error) Error<U>{ error };
		return *this;
	}
	Expected& operator= (Error<U>&& error)
	{
		destroy ();
		m_init = false;
		new (&m_error) Error<U>{ std::move (error) };
		return *this;
	}
	// clang-format off
	const E* operator-> () const { assert (m_init); return &m_expect; }
	E*       operator-> ()       { assert (m_init); return &m_expect; }
	const E& operator* () const& { assert (m_init);	return m_expect; }
	E&       operator* () &      { assert (m_init); return m_expect; }
	E&&      operator* () &&	 { assert (m_init); return std::move (m_expect); }
	const E&  value () const&    { assert (m_init); return m_expect; }
	E&        value () &         { assert (m_init); return m_expect; }
	const E&& value () const&&   { assert (m_init); return std::move (m_expect); }
	E&&       value () &&        { assert (m_init); return std::move (m_expect); }
	const Error<U>&  error () const&  { assert (!m_init); return m_error; }
	Error<U>&        error () &       { assert (!m_init); return m_error; }
	const Error<U>&& error () const&& { assert (!m_init); return std::move (m_error); }
	Error<U>&&       error () &&      { assert (!m_init); return move (m_error); }
	// clang-format on
	bool has_value () const { return m_init; }
	explicit operator bool () const { return m_init; }

	private:
	void destroy ()
	{
		if (m_init)
			m_expect.~E ();
		else
			m_error.~Error<U> ();
	}
	union
	{
		E m_expect;
		Error<U> m_error;
	};
	bool m_init;
};

/* TODO implement operator == and operator != as friend or global */


// Helper for robustly executing the two-call pattern
template <typename T, typename F, typename... Ts>
auto get_vector_init (F&& f, T init, Ts&&... ts) -> Expected<std::vector<T>, VkResult>
{
	uint32_t count = 0;
	std::vector<T> results;
	VkResult err;
	do
	{
		err = f (ts..., &count, nullptr);
		if (err)
		{
			return Error<VkResult>{ err, "" };
		};
		results.resize (count, init);
		err = f (ts..., &count, results.data ());
	} while (err == VK_INCOMPLETE);
	if (err)
	{
		return Error<VkResult>{ err, "" };
	};
	return results;
}

template <typename T, typename F, typename... Ts>
auto get_vector (F&& f, Ts&&... ts) -> Expected<std::vector<T>, VkResult>
{
	return get_vector_init (f, T (), ts...);
}

template <typename T, typename F, typename... Ts>
auto get_vector_noerror (F&& f, T init, Ts&&... ts) -> std::vector<T>
{
	uint32_t count = 0;
	std::vector<T> results;
	f (ts..., &count, nullptr);
	results.resize (count, init);
	f (ts..., &count, results.data ());
	return results;
}
template <typename T, typename F, typename... Ts>
auto get_vector_noerror (F&& f, Ts&&... ts) -> std::vector<T>
{
	return get_vector_noerror (f, T (), ts...);
}

template <typename T> void pNext_append (VkBaseOutStructure* chain, T* structure)
{
	if (chain == nullptr) return;

	while (chain->pNext != nullptr)
	{
		chain = chain->pNext;
	}
	chain->pNext = (VkBaseOutStructure*)structure;
}

} // namespace detail

} // namespace vkbs