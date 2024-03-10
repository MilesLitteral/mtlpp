#include "mtlpp.hpp"

namespace mtlpp { //MTL
    class VisibleFunctionTable : mtlpp::Resource {
        //Topics
        mtlpp::ResourceID gpuResourceID;

        //Setting a Table Entry
        void setFunction (mtlpp::FunctionHandle   handle,  int index); //Sets a table entry to point to a callable function.
        void setFunctions(mtlpp::FunctionHandle[] handles, ns::Range range);  //Sets a range of table entries to point to an array of callable functions.
    };
}