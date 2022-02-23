#pragma once

#include "ns.hpp"
#include "mtlpp.hpp" 
//#include <Foundation/Foundation.hpp> //maybe?

namespace mtlpp
{
    enum class BinaryArchiveError {
        BinaryArchiveErrorNone = 0,
        BinaryArchiveErrorInvalidFile = 1,
        BinaryArchiveErrorUnexpectedElement = 2,
        BinaryArchiveErrorCompilationFailure = 3,
    };

    class BinaryArchiveDescriptor : public ns::Object
    {
    public:
        static class BinaryArchiveDescriptor* alloc();

        class BinaryArchiveDescriptor*        init();

        ns::URL*                              url() const;
        void                                  setUrl(const ns::URL* url);
    };

    class BinaryArchive : public ns::Object
    {
    private:
        ns::String*   label;

    public:
        ns::String*   GetLabel();
        void          setLabel(const ns::String* label);

        class Device* device() const;

        bool          addComputePipelineFunctions(const class ComputePipelineDescriptor* descriptor, ns::Error** error);

        bool          addRenderPipelineFunctions(const class RenderPipelineDescriptor* descriptor, ns::Error** error);

        bool          addTileRenderPipelineFunctions(const class TileRenderPipelineDescriptor* descriptor, ns::Error** error);

        bool          serializeToURL(const ns::URL* url, ns::Error** error);

        bool          addFunction(const class FunctionDescriptor* descriptor, const class Library* library, ns::Error** error);
    };

    

    // static method: alloc
    _MTL_INLINE MTL::BinaryArchiveDescriptor* MTL::BinaryArchiveDescriptor::alloc()
    {
        return NS::Object::alloc<MTL::BinaryArchiveDescriptor>(_MTL_PRIVATE_CLS(MTLBinaryArchiveDescriptor));
    }

    // method: init
    _MTL_INLINE MTL::BinaryArchiveDescriptor* MTL::BinaryArchiveDescriptor::init()
    {
        return NS::Object::init<MTL::BinaryArchiveDescriptor>();
    }

    // property: url
    _MTL_INLINE NS::URL* MTL::BinaryArchiveDescriptor::url() const
    {
        return Object::sendMessage<NS::URL*>(this, _MTL_PRIVATE_SEL(url));
    }

    _MTL_INLINE void MTL::BinaryArchiveDescriptor::setUrl(const NS::URL* url)
    {
        Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(setUrl_), url);
    }

    // property: label
    _MTL_INLINE NS::String* MTL::BinaryArchive::label() const
    {
        return Object::sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
    }

    _MTL_INLINE void MTL::BinaryArchive::setLabel(const NS::String* label)
    {
        Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
    }

    // property: device
    _MTL_INLINE MTL::Device* MTL::BinaryArchive::device() const
    {
        return Object::sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
    }

    // method: addComputePipelineFunctionsWithDescriptor:error:
    _MTL_INLINE bool MTL::BinaryArchive::addComputePipelineFunctions(const MTL::ComputePipelineDescriptor* descriptor, NS::Error** error)
    {
        return Object::sendMessage<bool>(this, _MTL_PRIVATE_SEL(addComputePipelineFunctionsWithDescriptor_error_), descriptor, error);
    }

    // method: addRenderPipelineFunctionsWithDescriptor:error:
    _MTL_INLINE bool MTL::BinaryArchive::addRenderPipelineFunctions(const MTL::RenderPipelineDescriptor* descriptor, NS::Error** error)
    {
        return Object::sendMessage<bool>(this, _MTL_PRIVATE_SEL(addRenderPipelineFunctionsWithDescriptor_error_), descriptor, error);
    }

    // method: addTileRenderPipelineFunctionsWithDescriptor:error:
    _MTL_INLINE bool MTL::BinaryArchive::addTileRenderPipelineFunctions(const MTL::TileRenderPipelineDescriptor* descriptor, NS::Error** error)
    {
        return Object::sendMessage<bool>(this, _MTL_PRIVATE_SEL(addTileRenderPipelineFunctionsWithDescriptor_error_), descriptor, error);
    }

    // method: serializeToURL:error:
    _MTL_INLINE bool MTL::BinaryArchive::serializeToURL(const NS::URL* url, NS::Error** error)
    {
        return Object::sendMessage<bool>(this, _MTL_PRIVATE_SEL(serializeToURL_error_), url, error);
    }

    // method: addFunctionWithDescriptor:library:error:
    _MTL_INLINE bool MTL::BinaryArchive::addFunction(const MTL::FunctionDescriptor* descriptor, const MTL::Library* library, NS::Error** error)
    {
        return Object::sendMessage<bool>(this, _MTL_PRIVATE_SEL(addFunctionWithDescriptor_library_error_), descriptor, library, error);
    }
}
