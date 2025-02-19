/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Header for a user-generated dynamic library.
*/

#ifndef AAPLUserDylib_h
#define AAPLUserDylib_h
#include "AAPLMathUtilities.h"
// By default, a dynamic library exports all symbols and this can cause namespace clashes.
// The sample selectively exports only the symbol that the app code looks for.
#define EXPORT __attribute__((visibility("default")))
namespace AAPLUserDylib
{
    EXPORT vector_float4 getFullScreenColor(vector_float4 inColor);
}
#undef EXPORT

#endif /* UserDylib_h */
