#include "ns.hpp"
#include "defines.hpp"

namespace mtlpp {
    enum PrimitiveType {
        point, //Rasterize a point at each vertex. The vertex shader must provide [[point_size]], or the point size is undefined.
        line, //Rasterize a line between each separate pair of vertices, resulting in a series of unconnected lines. If there are an odd number of vertices, the last vertex is ignored.
        lineStrip, //Rasterize a line between each pair of adjacent vertices, resulting in a series of connected lines (also called a polyline).
        triangle, //For every separate set of three vertices, rasterize a triangle. If the number of vertices is not a multiple of three, either one or two vertices is ignored.
        triangleStrip //For every three adjacent vertices, rasterize a triangle.
    };
}