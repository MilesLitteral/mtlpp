/*
 * Copyright 2016-2017 Nikolay Aleksiev. All rights reserved.
 * License: https://github.com/naleksiev/mtlpp/blob/master/LICENSE
 */

/*
 * Copyright 2020-2021 Miles J. Litteral All rights reserved.
 * License: https://github.com/MilesLitteral/mtlpp/blob/master/LICENSE
 */

#pragma once
#include "defines.hpp"
#include "blit_command_encoder.hpp"
#include "buffer.hpp"
#include "command_buffer.hpp"
#include "compute_pipeline.hpp"
#include "compute_command_encoder.hpp"
#include "command_queue.hpp"
#include "device.hpp"
#include "depth_stencil.hpp"
#include "drawable.hpp"
#include "render_pass.hpp"
#include "library.hpp"
#include "pixel_format.hpp"
#include "render_pipeline.hpp"
#include "vertex_descriptor.hpp"
#include "parallel_render_command_encoder.hpp"
#include "render_command_encoder.hpp"
#include "sampler.hpp"
#include "texture.hpp"
#include "heap.hpp"
#include "stage_input_output_descriptor.hpp"

// MTLPP 2.0
#include "ns.hpp"
#include "argument.hpp"
#include "function.hpp"
#include "counters.hpp"
#include "compute_pass.hpp"
#include "binary_archive.hpp"
#include "dynamic_library.hpp"
#include "vertex_attribute.hpp"
#include "linked_functions.hpp"
#include "function_constant_values.hpp"

#include "fence.hpp"
#include "resource.hpp"
#include "resource_id.hpp"
#include "resource_usage.hpp"
#include "types.hpp"

// MTLPP 3.0
#include "data_type.hpp"
#include "argument_encoder.hpp"
#include "indirect_command_type.hpp"
#include "indirect_command_buffer.hpp"
#include "indirect_render_command.hpp"
#include "indirect_compute_command.hpp"
#include "indirect_command_buffer_descriptor.hpp"

#include "origin.hpp"
#include "region.hpp"
#include "render_stages.hpp"
#include "motion_border_mode.hpp"
#include "primitive_type.hpp"

#include "visible_function_table.hpp"
#include "acceleration_structure.hpp"
#include "intersection_function_table.hpp"
#include "acceleration_structure_geometry_descriptor.hpp"
#include "instance_acceleration_structure_descriptor.hpp"
#include "primitive_acceleration_structure_descriptor.hpp"
#include "acceleration_structure_triangle_geometry_descriptor.hpp"
#include "acceleration_structure_bounding_box_geometry_descriptor.hpp"
#include "acceleration_structure_triangle_geometry_descriptor.hpp"

// METALENGINE 
#include "metalEngine.hpp" 

// QUARTZPP
#include "Quartz/QuartzCore.hpp" 
#include "Quartz/CADefines.hpp" 
#include "Quartz/CAPrivate.hpp" 
#include "Quartz/CAMetalDrawable.hpp" 
