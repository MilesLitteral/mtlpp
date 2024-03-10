#include "mtlpp.hpp"
#include <Metal/MTLVisibleFunctionTable.h>

namespace mtlpp {
    VisibleFunctionTable::setFunction(mtlpp::FunctionHandle handle, int index){
        Validate();
        [(__bridge MTLVisibleFunctionTable*)m_ptr setFunction:MTLFunctionHandle(handle)];
    } //Sets a table entry to point to a callable function, Required.

    VisibleFunctionTable::setFunctions(mtlpp::FunctionHandle[] handles, Range<Int> range){
        Validate();
        [(__bridge MTLVisibleFunctionTable*)m_ptr setFunctions:MTLFunctionHandle(handles) range:range];
    } //Sets a range of table entries to point to an array of callable functions.
}