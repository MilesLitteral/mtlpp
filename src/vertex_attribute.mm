#include "ns.hpp"
#include <Metal/MTLVertexAttribute.h>

namespace mtlpp {
    VertexAttribute::VertexAttribute() : ns::Object(ns::Handle{ (__bridge void*)[[MTLVertexAttribute alloc] init] }){};
    VertexAttribute::VertexAttribute(ns::String name, int index, mtlpp::DataType attributeT, bool active, bool patchControl, bool patchData) {
        return ns::Handle{ (__bridge void*)[MTLVertexAttribute name:name
                                                                attributeIndex:width
                                                                attributeType:attributeT
                                                                isActive:active
                                                                isPatchControlPointData:patchControl
                                                                isPatchData:patchData] };
    };
}