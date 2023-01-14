/*
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the “Software”), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Copyright © 2020 Charles Giessen (charles@lunarg.com)
 */

#pragma once

#include "VkBootstrap.h"

namespace vkb {
class PipelineLayoutBuilder {
	public:
	// Construct a PipelineLayoutBuilder with a 'vkb::Device'
	explicit PipelineLayoutBuilder(Device const& device);
	// Construct a PipelineLayoutBuilder with a specific VkDevice handle
	explicit PipelineLayoutBuilder(VkDevice const device);

	Result<VkPipelineLayout> build() const;

	// Set the bitmask of the pipeline layout creation flags.
	PipelineLayoutBuilder& set_pipeline_layout_flags(VkPipelineLayoutCreateFlags layout_flags);

	// Add descriptor set layout(s) to the list of descriptor set layouts to be applied to pipeline layout.
	PipelineLayoutBuilder& add_descriptor_layout(VkDescriptorSetLayout descriptor_set_layout);
	PipelineLayoutBuilder& add_descriptor_layouts(std::vector<VkDescriptorSetLayout> descriptor_set_layouts);
	PipelineLayoutBuilder& clear_descriptor_layouts();

	// Add push constant range(s) to the list of push constant ranges to be applied to pipeline layout.
	PipelineLayoutBuilder& add_push_constant_range(VkPushConstantRange push_constant_range);
	PipelineLayoutBuilder& add_push_constant_ranges(std::vector<VkPushConstantRange> push_constant_ranges);
	PipelineLayoutBuilder& clear_push_constant_ranges();

	// Add a structure to the pNext chain of vkPipelineLayoutCreateInfo.
	// The structure must be valid when PipelineLayoutBuilder::build() is called.
	template <typename T> PipelineLayoutBuilder& add_pNext(T* structure) {
		info.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	PipelineLayoutBuilder& clear_pNext_chain();

	// Provide custom allocation callbacks.
	PipelineLayoutBuilder& set_allocation_callbacks(VkAllocationCallbacks* callbacks);

	private:
	struct PipelineLayoutInfo {
		VkDevice device = VK_NULL_HANDLE;
		VkAllocationCallbacks* allocation_callbacks = nullptr;
		VkPipelineLayoutCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_chain;
		std::vector<VkDescriptorSetLayout> descriptor_layouts;
		std::vector<VkPushConstantRange> push_constant_ranges;
		PFN_vkCreatePipelineLayout pipeline_layout_create_proc = nullptr;
	} info;
};

class GraphicsPipelineBuilder {
	public:
	GraphicsPipelineBuilder(Device const& device, VkPipelineCache pipeline_cache = VK_NULL_HANDLE);
	GraphicsPipelineBuilder(VkDevice const device, VkPipelineCache pipeline_cache = VK_NULL_HANDLE);

	Result<VkPipeline> build() const;

	template <typename T> GraphicsPipelineBuilder& add_pNext(T* structure) {
		info.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_pNext();
	GraphicsPipelineBuilder& set_pipeline_create_flags(VkPipelineCreateFlags pipeline_create_flags);
	GraphicsPipelineBuilder& set_pipeline_layout(VkPipelineLayout pipeline_layout);
	GraphicsPipelineBuilder& set_renderpass(VkRenderPass renderpass, uint32_t subpass_index);
	GraphicsPipelineBuilder& set_base_pipeline(VkPipeline base_pipeline, uint32_t base_pipeline_index);
	GraphicsPipelineBuilder& add_additional_shader_stage(VkPipelineShaderStageCreateInfo& shader_stage_info);
	GraphicsPipelineBuilder& add_additional_shader_stages(std::vector<VkPipelineShaderStageCreateInfo> shader_stage_infos);
	GraphicsPipelineBuilder& clear_additional_shader_stages();

	// Vertex input state
	template <typename T> GraphicsPipelineBuilder& add_vertex_input_pNext(T* structure) {
		info.vertex_input.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_vertex_input_pNext();
	GraphicsPipelineBuilder& add_vertex_input_binding_desc(VkVertexInputBindingDescription vertex_input_binding_desc);
	GraphicsPipelineBuilder& add_vertex_input_binding_descs(std::vector<VkVertexInputBindingDescription> vertex_input_binding_descs);
	GraphicsPipelineBuilder& clear_vertex_input_binding_descs();
	GraphicsPipelineBuilder& add_vertex_input_attrib_desc(VkVertexInputAttributeDescription vertex_input_attrib_desc);
	GraphicsPipelineBuilder& add_vertex_input_attrib_descs(std::vector<VkVertexInputAttributeDescription> vertex_input_attrib_descs);
	GraphicsPipelineBuilder& clear_vertex_input_attrib_descs();

	// Input assembly state
	GraphicsPipelineBuilder& set_input_assembly_primitive_topology(VkPrimitiveTopology topology);
	GraphicsPipelineBuilder& set_input_assembly_primitive_restart(bool enable_primitive_restart);

	// Vertex shader
	template <typename T> GraphicsPipelineBuilder& add_vertex_shader_pNext(T* structure) {
		info.vertex_shader.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_vertex_shader_pNext();
	GraphicsPipelineBuilder& set_vertex_shader_flags(VkPipelineShaderStageCreateFlags flags);
	GraphicsPipelineBuilder& set_vertex_shader_module(VkShaderModule shader_module);
	GraphicsPipelineBuilder& set_vertex_shader_entrypoint_name(const char* name);
	GraphicsPipelineBuilder& set_vertex_shader_specialization_info(VkSpecializationInfo& specialization_info);
	GraphicsPipelineBuilder& clear_vertex_shader();

	// Tessellation control shader
	template <typename T> GraphicsPipelineBuilder& add_tessellation_control_shader_pNext(T* structure) {
		info.tessellation_control_shader.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_tessellation_control_shader_pNext();
	GraphicsPipelineBuilder& set_tessellation_control_shader_flags(VkPipelineShaderStageCreateFlags flags);
	GraphicsPipelineBuilder& set_tessellation_control_shader_module(VkShaderModule shader_module);
	GraphicsPipelineBuilder& set_tessellation_control_shader_name(const char* name);
	GraphicsPipelineBuilder& set_tessellation_control_shader_specialization_info(VkSpecializationInfo& specialization_info);
	GraphicsPipelineBuilder& clear_tessellation_control_shader();

	// Tessellation evaluation shader
	template <typename T> GraphicsPipelineBuilder& add_tessellation_eval_shader_pNext(T* structure) {
		info.tessellation_eval_shader.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_tessellation_eval_shader_pNext();
	GraphicsPipelineBuilder& set_tessellation_eval_shader_flags(VkPipelineShaderStageCreateFlags flags);
	GraphicsPipelineBuilder& set_tessellation_eval_shader_module(VkShaderModule shader_module);
	GraphicsPipelineBuilder& set_tessellation_eval_shader_name(const char* name);
	GraphicsPipelineBuilder& set_tessellation_eval_shader_specialization_info(VkSpecializationInfo& specialization_info);
	GraphicsPipelineBuilder& clear_tessellation_eval_shader();

	// Tessellation state
	template <typename T> GraphicsPipelineBuilder& add_tessellation_state_pNext(T* structure) {
		info.tessellation_state.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_tessellation_state_pNext();
	GraphicsPipelineBuilder& set_tessellation_state_patch_control_points(uint32_t patch_control_points);

	// Geometry shader
	template <typename T> GraphicsPipelineBuilder& add_geometry_shader_pNext(T* structure) {
		info.geometry_shader.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_geometry_shader_pNext();
	GraphicsPipelineBuilder& set_geometry_shader_flags(VkPipelineShaderStageCreateFlags flags);
	GraphicsPipelineBuilder& set_geometry_shader_module(VkShaderModule shader_module);
	GraphicsPipelineBuilder& set_geometry_shader_name(const char* name);
	GraphicsPipelineBuilder& set_geometry_shader_specialization_info(VkSpecializationInfo& specialization_info);
	GraphicsPipelineBuilder& clear_geometry_shader();

	// Viewport state
	template <typename T> GraphicsPipelineBuilder& add_viewport_state_pNext(T* structure) {
		info.viewport_state.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_viewport_state_pNext();
	GraphicsPipelineBuilder& add_viewport_state_viewport(VkViewport viewport);
	GraphicsPipelineBuilder& add_viewport_state_viewports(std::vector<VkViewport> viewports);
	GraphicsPipelineBuilder& clear_viewport_state_viewports();
	GraphicsPipelineBuilder& add_viewport_state_scissor(VkRect2D scissor);
	GraphicsPipelineBuilder& add_viewport_state_scissors(std::vector<VkRect2D> scissors);
	GraphicsPipelineBuilder& clear_viewport_state_scissors();

	// Fragment shader
	template <typename T> GraphicsPipelineBuilder& add_fragment_shader_pNext(T* structure) {
		info.fragment_shader.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_fragment_shader_pNext();
	GraphicsPipelineBuilder& set_fragment_shader_flags(VkPipelineShaderStageCreateFlags flags);
	GraphicsPipelineBuilder& set_fragment_shader_module(VkShaderModule shader_module);
	GraphicsPipelineBuilder& set_fragment_shader_name(const char* name);
	GraphicsPipelineBuilder& set_fragment_shader_specialization_info(VkSpecializationInfo& specialization_info);
	GraphicsPipelineBuilder& clear_fragment_shader();

	// Rasterization state
	template <typename T> GraphicsPipelineBuilder& add_rasterization_state_pNext(T* structure) {
		info.rasterization_state.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_rasterization_state_pNext();
	GraphicsPipelineBuilder& enable_rasterization_state_depth_clamp(bool enable_depth_clamp);
	GraphicsPipelineBuilder& enable_rasterization_state_discard(bool enable_rasterizer_discard);
	GraphicsPipelineBuilder& set_rasterization_state_polygon_mode(VkPolygonMode polygon_mode);
	GraphicsPipelineBuilder& set_rasterization_state_cull_mode_flags(VkCullModeFlags cull_mode_flags);
	GraphicsPipelineBuilder& set_rasterization_state_front_face(VkFrontFace front_face);
	GraphicsPipelineBuilder& enable_rasterization_state_depth_bias(bool enable_depth_bias);
	GraphicsPipelineBuilder& set_rasterization_state_depth_bias_constant_factor(float depth_bias_constant_factor);
	GraphicsPipelineBuilder& set_rasterization_state_depth_bias_clamp(float depth_bias_clamp);
	GraphicsPipelineBuilder& set_rasterization_state_depth_bias_slope_factor(float depth_bias_slope_factor);
	GraphicsPipelineBuilder& set_rasterization_state_line_width(float line_width);

	// Multisample state
	template <typename T> GraphicsPipelineBuilder& add_multisample_state_pNext(T* structure) {
		info.multisample_state.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_multisample_state_pNext();
	GraphicsPipelineBuilder& set_multisample_state_sample_count(VkSampleCountFlagBits sample_count);
	GraphicsPipelineBuilder& enable_multisample_state_sample_shading(bool enable_sample_shading);
	GraphicsPipelineBuilder& set_multisample_state_min_sample_shading(float min_sample_shading);
	GraphicsPipelineBuilder& set_multisample_state_sample_mask(VkSampleMask sample_mask);
	GraphicsPipelineBuilder& enable_multisample_state_alpha_to_coverage(bool enable_alpha_to_coverage);
	GraphicsPipelineBuilder& enable_multisample_state_alpha_to_one(bool enable_alpha_to_one);

	// Depth stencil state
	template <typename T> GraphicsPipelineBuilder& add_depth_stencil_state_pNext(T* structure) {
		info.depth_stencil_state.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_depth_stencil_state_pNext();
	GraphicsPipelineBuilder& set_depth_stencil_state_flags(VkPipelineDepthStencilStateCreateFlags flags);
	GraphicsPipelineBuilder& enable_depth_stencil_depth_testing(bool enable_depth_testing);
	GraphicsPipelineBuilder& enable_depth_stencil_depth_write(bool enable_depth_write);
	GraphicsPipelineBuilder& set_depth_stencil_compare_op(VkCompareOp compare_op);
	GraphicsPipelineBuilder& enable_depth_stencil_depth_bounds_test(bool enable_depth_bounds_test);
	GraphicsPipelineBuilder& enable_depth_stencil_stencil_test(bool enable_stencil_test);
	GraphicsPipelineBuilder& set_depth_stencil_front_stencil_op_state(VkStencilOpState front);
	GraphicsPipelineBuilder& set_depth_stencil_back_stencil_op_state(VkStencilOpState back);
	GraphicsPipelineBuilder& set_depth_stencil_min_depth_bounds(float min_depth_bounds);
	GraphicsPipelineBuilder& set_depth_stencil_max_depth_bounds(float max_depth_bounds);

	// Color blend state
	template <typename T> GraphicsPipelineBuilder& add_color_blend_state_pNext(T* structure) {
		info.color_blend_state.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}
	GraphicsPipelineBuilder& clear_color_blend_state_pNext();
	GraphicsPipelineBuilder& set_color_blend_state_flags(VkPipelineColorBlendStateCreateFlags flags);
	GraphicsPipelineBuilder& enable_color_blend_state_logic_op(bool enable_logic_op);
	GraphicsPipelineBuilder& set_color_blend_state_logic_op(VkLogicOp logic_op);
	GraphicsPipelineBuilder& add_color_blend_state_color_blend_attachment(VkPipelineColorBlendAttachmentState attachment);
	GraphicsPipelineBuilder& add_color_blend_state_color_blend_attachments(std::vector<VkPipelineColorBlendAttachmentState> attachments);
	GraphicsPipelineBuilder& clear_color_blend_state_color_blend_attachments();
	GraphicsPipelineBuilder& set_color_blend_state_blend_constants(float red, float green, float blue, float alpha);

	// Dynamic state
	GraphicsPipelineBuilder& clear_dynamic_state_pNext();
	GraphicsPipelineBuilder& add_dynamic_state(VkDynamicState& dynamic_state);
	GraphicsPipelineBuilder& add_dynamic_states(std::vector<VkDynamicState> dynamic_states);
	GraphicsPipelineBuilder& clear_dynamic_states();

	// Provide custom allocation callbacks.
	GraphicsPipelineBuilder& set_allocation_callbacks(VkAllocationCallbacks* callbacks);

	private:
	struct ShaderInfo {
		VkPipelineShaderStageCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_chain;
		VkShaderModule shader_module = VK_NULL_HANDLE;
		const char* name = "main"; // assumed default is "main"
		VkSpecializationInfo specialization_info = {};
	};

	struct GraphicsPipelineInfo {
		VkDevice device = VK_NULL_HANDLE;
		VkPipelineCache pipeline_cache = VK_NULL_HANDLE;
		VkAllocationCallbacks* allocation_callbacks = nullptr;
		VkPipelineCreateFlags flags = 0;
		VkPipelineLayout pipeline_layout = VK_NULL_HANDLE;
		VkRenderPass renderpass = VK_NULL_HANDLE;
		uint32_t subpass = 0;
		VkPipeline base_pipeline = VK_NULL_HANDLE;
		uint32_t base_pipeline_index = 0;
		std::vector<VkBaseOutStructure*> pNext_chain;
		std::vector<VkPipelineShaderStageCreateInfo> additional_shader_stages;
		PFN_vkCreateGraphicsPipelines graphics_pipeline_create_proc = nullptr;

		struct VertexInput { // Vertex input state
			std::vector<VkBaseOutStructure*> pNext_chain;
			std::vector<VkVertexInputBindingDescription> binding_descs;
			std::vector<VkVertexInputAttributeDescription> attrib_descs;
		} vertex_input;

		struct InputAssembly { // Input assembly state
			VkPrimitiveTopology topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
			VkBool32 primitiveRestartEnable = VK_FALSE;
		} input_assembly;

		ShaderInfo vertex_shader;
		ShaderInfo fragment_shader;
		ShaderInfo tessellation_control_shader;
		ShaderInfo tessellation_eval_shader;
		ShaderInfo geometry_shader;

		struct TessellationState {
			std::vector<VkBaseOutStructure*> pNext_chain;
			uint32_t patch_control_points;
		} tessellation_state;


		struct ViewportState { // Viewport state
			std::vector<VkBaseOutStructure*> pNext_chain;
			std::vector<VkViewport> viewports;
			std::vector<VkRect2D> scissors;
		} viewport_state;


		struct RasterizationState { // Rasterization state
			std::vector<VkBaseOutStructure*> pNext_chain;
			VkBool32 depth_clamp_enable = VK_FALSE;
			VkBool32 rasterizer_discard_enable = VK_FALSE;
			VkPolygonMode polygon_mode = VK_POLYGON_MODE_FILL;
			VkCullModeFlags cull_mode_flags = VK_CULL_MODE_BACK_BIT;
			VkFrontFace front_face = VK_FRONT_FACE_COUNTER_CLOCKWISE;
			VkBool32 depth_bias_enable = VK_FALSE;
			float depth_bias_constant_factor = 0.0f;
			float depth_bias_clamp = 0.0f;
			float depth_bias_slope_factor = 0.0f;
			float line_width = 0.0f;
		} rasterization_state;

		struct MultisampleState {
			std::vector<VkBaseOutStructure*> pNext_chain;
			VkSampleCountFlagBits sample_count = VK_SAMPLE_COUNT_1_BIT;
			VkBool32 sample_shading = VK_FALSE;
			float min_sample_shading = 0.0f;
			VkSampleMask sample_mask = 0;
			VkBool32 alpha_to_coverage = VK_FALSE;
			VkBool32 alpha_to_one = VK_FALSE;
		} multisample_state;

		struct DepthStencilState {
			std::vector<VkBaseOutStructure*> pNext_chain;
			VkPipelineDepthStencilStateCreateFlags flags = 0;
			VkBool32 depth_test = VK_FALSE;
			VkBool32 depth_write = VK_FALSE;
			VkCompareOp depth_compare_operation = VK_COMPARE_OP_GREATER;
			VkBool32 depth_bounds_test = VK_FALSE;
			VkBool32 stencil_test = VK_FALSE;
			VkStencilOpState front_stencil_op_state = {};
			VkStencilOpState back_stencil_op_state = {};
			float min_depth_bounds = 0.0f;
			float max_depth_bounds = 0.0f;
		} depth_stencil_state;

		struct ColorBlendState {
			std::vector<VkBaseOutStructure*> pNext_chain;
			VkPipelineColorBlendStateCreateFlags flags = 0;
			VkBool32 logic_op_enable = VK_FALSE;
			VkLogicOp logic_op = {};
			std::vector<VkPipelineColorBlendAttachmentState> attachments;
			float blend_constants[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		} color_blend_state;

		std::vector<VkDynamicState> dynamic_states;


	} info;
};
}; // namespace vkb
