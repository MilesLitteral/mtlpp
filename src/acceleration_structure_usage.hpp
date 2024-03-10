namespace mtlpp {
    struct AccelerationStructureUsage{
        // Topics
        // Creating Usage Options
        //init(rawValue: UInt);

        //Creates new usage options from a raw integer value.
        //Usage Options
        static mtlpp::AccelerationStructureUsage refit;
        //An option that specifies that you can refit the acceleration structure if the geometry changes.
        static mtlpp::AccelerationStructureUsage preferFastBuild;
        //An option that specifies that Metal needs to build the acceleration structure quickly, even if that reduces ray-tracing performance.
        static mtlpp::AccelerationStructureUsage extendedLimits;
        //A structure usage option that indicates you intend to use larger ray-tracing limits for the acceleration structure.
    };
}