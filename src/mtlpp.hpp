/*
 * Copyright 2016-2017 Nikolay Aleksiev. All rights reserved.
 * License: https://github.com/naleksiev/mtlpp/blob/master/LICENSE
 */

/*
 * Copyright 2016-2017 Nikolay Aleksiev. All rights reserved.
 * License: https://github.com/MilesLitteral/mtlpp/blob/master/LICENSE
 */

#pragma once

#include "defines.hpp"
#include "blit_command_encoder.hpp"
#include "buffer.hpp"
#include "command_buffer.hpp"
#include "compute_pipeline.hpp"
#include "compute_encoder.hpp"
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

//mtlpp 2.0
# include "ns.hpp"
# include "binary_archive.hpp"
# include "dynamic_library.hpp"

// METALENGINE 
#include "metalEngine.hpp" 

// QUARTZPP
#include "Quartz/QuartzCore.hpp" 
#include "Quartz/CADefines.hpp" 
#include "Quartz/CAPrivate.hpp" 
#include "Quartz/CAMetalDrawable.hpp" 
