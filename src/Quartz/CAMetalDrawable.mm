#pragma once

#include "../../mtlpp.hpp"
#include "CAMetalDrawable.hpp"

namespace CA
{
    class MetalDrawable : public mtlpp::Drawable
    {
        public:
            class MetalLayer* layer();
            mtlpp::Texture*   texture();


        CA::MetalLayer* CA::MetalDrawable::layer()
        {
            return Object::sendMessage<MetalLayer*>(this, _MTL_PRIVATE_SEL(layer));
        }

        mtlpp::Texture* CA::MetalDrawable::texture()
        {
            return Object::sendMessage<mtlpp::Texture*>(this, _MTL_PRIVATE_SEL(texture));
        }
    };
}