#include <metal_stdlib>;
using namespace metal;

kernel void sqr(float *vIn [[buffer(0)]], float *vOut [[buffer(1)]], uint id[[thread_position_in_grid]]){
    vOut[id] = vIn[id] * vIn[id];       
};