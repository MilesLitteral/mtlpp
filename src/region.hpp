#include "mtlpp.hpp"

namespace mtlpp{
    struct Region{
        // % Overview
        // % Metal has many object types that represent arrays of discrete elements. For example, a texture has an array of pixel elements, and a thread grid has an array of computational threads. Use MTLRegion instances to describe subsets of these objects.

        // % The origin is the front upper-left corner of the region, and its extents go towards the back lower-right corner. Conceptually, when using a MTLRegion instance to describe a subset of an object, treat the object as a 3D array of elements, even if it has fewer dimensions. For a 2D object, set the z coordinate of the origin to 0 and the depth to 1. For a 1D object, set the y and z coordinates of the origin to 0 and the height and depth to 1.

        //Topics
        //Creating Regions
        Region init();
        //Initializes a new region.
        Region init(mtlpp::Origin origin, mtlpp::Size size);
        //Initializes a new region with the specified origin and size.
        mtlpp::Region MTLRegionMake1D(int, int);
        //Creates a 3D representation of a 1D region.
        mtlpp::Region MTLRegionMake2D(int, int, int, int);
        //Creates a 3D representation of a 2D region.
        mtlpp::Region MTLRegionMake3D(int, int, int, int, int, int);

        //Creates a 3D region.
        //Getting and Setting Region Information
        mtlpp::Origin origin;
        //The coordinates of the front upper-left corner of the region.
        mtlpp::Size size;
        //The dimensions of the region.
    }
}