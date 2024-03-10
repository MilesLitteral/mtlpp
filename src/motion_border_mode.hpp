namespace mtlpp{
    enum MotionBorderMode {
        Clamp,  //A mode that specifies treating times outside the specified endpoint as if they were at the endpoint.
        Vanish  //A mode that specifies that times outside the specified endpoint need to prevent any ray-intersections with the primitive.
    };
}