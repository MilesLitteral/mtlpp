/*
 * Copyright 2016-2017 Nikolay Aleksiev. All rights reserved.
 * License: https://github.com/naleksiev/mtlpp/blob/master/LICENSE
 */

#include "library.hpp"
#include "device.hpp"
#include "function_constant_values.hpp"
#include <Metal/MTLLibrary.h>

namespace mtlpp
{

        (id<MTLDevice>)* DynamicLibrary::GetDevice(){
                return [(id<MTLDevice> device)m_ptr device]
        };

        NSString* mtlpp::DynamicLibrary::GetLabel(){
                return [(NSString dylib)m_ptr label)]
        }

        void mtlpp::DynamicLibrary::SetLabel(ns::String* _label){
             [(NSString device)m_ptr label.GetPtr()]
        }

        NSString* mtlpp::DynamicLibrary::GetInstallName(){
                return [(id<MTLDevice> device)m_ptr installName]
        }

        NSString* mtlpp::DynamicLibrary::SetInstallName(){
                return [(id<MTLDevice> device)m_ptr installName.GetPtr()]
        }

        bool DynamicLibrary::SerializeToURL(const ns::URL* url, ns::Error** error){
             Validate();
             [(__bridge id<MTLDynamicLibrary>)m_ptr serializeToURL:(NSURL*)url 
                                                        error:error)]
        };
}
