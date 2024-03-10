#pragma once

#include "CADefines.hpp"
#include "CAPrivate.hpp"

namespace CA
{
    class MetalDrawable : public mtlpp::Drawable
    {
        public:
            class MetalLayer* layer();
            mtlpp::Texture*   texture();

        CA::MetalLayer* CA::MetalDrawable::layer();
        mtlpp::Texture* CA::MetalDrawable::texture();
    };
}
