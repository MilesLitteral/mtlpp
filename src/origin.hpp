namespace mtlpp {
    //Returns a new origin with the specified coordinates.

    //Initializes a new origin with the specified coordinates.
    //Getting and Setting Coordinate Values
    struct Origin {
        int x; //The x coordinate of the origin.
        int y; //The y coordinate of the origin.
        int z; //The z coordinate of the origin.
        mtlpp::Origin MTLOriginMake(int x, int y, int z);
    };
}