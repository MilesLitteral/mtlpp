namespace mtlpp {
    enum class DataType {
        // Boolean Data Types
        bool1,                          // A Boolean value.
        bool2,                          // A two-component vector with Boolean values.
        bool3,                          // A three-component vector with Boolean values.
        bool4,                          // A four-component vector with Boolean values.
        // Integer Data Types
        char1,                          // A signed 8-bit integer value.
        char2,                          // A two-component vector with signed 8-bit integer values.
        char3,                          // A three-component vector with signed 8-bit integer values.
        char4,                          // A four-component vector with signed 8-bit integer values.
        uchar,                          // An unsigned 8-bit integer value.
        uchar2,                         // A two-component vector with unsigned 8-bit integer values.
        uchar3,                         // A three-component vector with unsigned 8-bit integer values.
        uchar4,                         // A three-component vector with unsigned 8-bit integer values.
        short1,                         // A signed 16-bit integer value.
        short2,                         // A two-component vector with signed 16-bit integer values.
        short3,                         // A three-component vector with signed 16-bit integer values.
        short4,                         // A four-component vector with signed 16-bit integer values.
        ushort,                         // An unsigned 16-bit integer value.
        ushort2,                        // A two-component vector with unsigned 16-bit integer values.
        ushort3,                        // A three-component vector with unsigned 16-bit integer values.
        ushort4,                        // A four-component vector with unsigned 16-bit integer values.
        int1,                           // A signed 32-bit integer value.
        int2,                           // A two-component vector with signed 32-bit integer values.
        int3,                           // A three-component vector with signed 32-bit integer values.
        int4,                           // A four-component vector with signed 32-bit integer values.
        uint,                           // An unsigned 32-bit integer value.
        uint2,                          // A two-component vector with unsigned 32-bit integer values.
        uint3,                          // A three-component vector with unsigned 32-bit integer values.
        uint4,                          // A four-component vector with unsigned 32-bit integer values.
        long1,                          // A signed 64-bit integer value.
        long2,                          // A two-component vector with signed 64-bit integer values.
        long3,                          // A three-component vector with signed 64-bit integer values.
        long4,                          // A four-component vector with signed 64-bit integer values.
        ulong,                          // An unsigned 64-bit integer value.
        ulong2,                         // A two-component vector with unsigned 64-bit integer values.
        ulong3,                         // A three-component vector with unsigned 64-bit integer values.
        ulong4,                         // A four-component vector with unsigned 64-bit integer values.
        // Floating-Point Data Types
        float1,                         // A 32-bit floating-point value.
        float2,                         // A two-component vector with 32-bit floating-point values.
        float3,                         // A three-component vector with 32-bit floating-point values.
        float4,                         // A four-component vector with 32-bit floating-point values.
        float2x2,                       // A 2x2 component matrix with 32-bit floating-point values.
        float2x3,                       // A 2x3 component matrix with 32-bit floating-point values.
        float2x4,                       // A 2x4 component matrix with 32-bit floating-point values.
        float3x2,                       // A 3x2 component matrix with 32-bit floating-point values.
        float3x3,                       // A 3x3 component matrix with 32-bit floating-point values.
        float3x4,                       // A 3x4 component matrix with 32-bit floating-point values.
        float4x2,                       // A 4x2 component matrix with 32-bit floating-point values.
        float4x3,                       // A 4x3 component matrix with 32-bit floating-point values.
        float4x4,                       // A 4x4 component matrix with 32-bit floating-point values.
        half,                           // A 16-bit floating-point value.
        half2,                          // A two-component vector with 16-bit floating-point values.
        half3,                          // A three-component vector with 16-bit floating-point values.
        half4,                          // A four-component vector with 16-bit floating-point values.
        half2x2,                        // A 2x2 component matrix with 16-bit floating-point values.
        half2x3,                        // A 2x3 component matrix with 16-bit floating-point values.
        half2x4,                        // A 2x4 component matrix with 16-bit floating-point values.
        half3x2,                        // A 3x2 component matrix with 16-bit floating-point values.
        half3x3,                        // A 3x3 component matrix with 16-bit floating-point values.
        half3x4,                        // A 3x4 component matrix with 16-bit floating-point values.
        half4x2,                        // A 4x2 component matrix with 16-bit floating-point values.
        half4x3,                        // A 4x3 component matrix with 16-bit floating-point values.
        half4x4,                        // A 4x4 component matrix with 16-bit floating-point values.
        // Pixel Format Data Types
        r8Snorm,                        // An ordinary format with one 8-bit, normalized, signed integer component.
        r8Unorm,                        // An ordinary format with one 8-bit, normalized, unsigned integer component.
        rg8Snorm,                       // An ordinary format with two 8-bit, normalized, signed integer components.
        rg8Unorm,                       // An ordinary format with two 8-bit, normalized, unsigned integer components.
        rgba8Snorm,                     // An ordinary format with four 8-bit, normalized, signed integer components in RGBA order.
        rgba8Unorm,                     // An ordinary format with four 8-bit, normalized, unsigned integer components in RGBA order.
        rgba8Unorm_srgb,                // An ordinary format with four 8-bit, normalized, unsigned integer components in RGBA order with conversion between sRGB and linear space.
        r16Snorm,                       // An ordinary format with one 16-bit, normalized, signed integer component.
        r16Unorm,                       // An ordinary format with one 16-bit, normalized, unsigned integer component.
        rg16Snorm,                      // An ordinary format with two 16-bit, normalized, signed integer components.
        rg16Unorm,                      // An ordinary format with two 16-bit, normalized, unsigned integer components.
        rgba16Snorm,                    // An ordinary format with four 16-bit, normalized, signed integer components in RGBA order.
        rgba16Unorm,                    // An ordinary format with four 16-bit, normalized, unsigned integer components in RGBA order.
        rgb9e5Float,                    // A packed 32-bit format with three 9-bit, floating-point color components.
        rgb10a2Unorm,                   // A packed 32-bit format with normalized, unsigned integer color components.
        rg11b10Float,                   // A packed 32-bit format with two 11-bit (for red and green) and one 10-bit (for blue) floating-point color components.
        // Metal Object Data Types
        texture,                        // A texture.
        sampler,                        // A texture sampler.
        indirectCommandBuffer,          // An indirect command buffer.
        renderPipeline,                 // A render pipeline.
        computePipeline,                // A compute pipeline.
        visibleFunctionTable,           // A table of visible functions that the pipeline can call.
        intersectionFunctionTable,      // A table of intersection functions that the pipeline can call.
        primitiveAccelerationStructure, // A low-level ray-tracing acceleration structure for a set of primitives.
        instanceAccelerationStructure,  // A high-level ray-tracing acceleration structure for a set of instances of low-level primitives.
        // Composed Data Types
        none,                           // The argument doesn't have a valid data type.
        structure,                      // A (Data) structure.
        array,                          // An array.
        pointer                         // A pointer.
    };
}