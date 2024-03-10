#include "ns.hpp"

namespace mtlpp
{
    class ComputePassSampleBufferAttachmentDescriptor : public ns::Object
    {
    public:
        ComputePassSampleBufferAttachmentDescriptor();

        CounterSampleBuffer*                                      GetSampleBuffer();
        void                                                      SetSampleBuffer(const CounterSampleBuffer* sampleBuffer);

        ns::UInteger                                              GetStartOfEncoderSampleIndex() const;
        void                                                      SetStartOfEncoderSampleIndex(ns::UInteger startOfEncoderSampleIndex);

        ns::UInteger                                              GetEndOfEncoderSampleIndex() const;
        void                                                      SetEndOfEncoderSampleIndex(ns::UInteger endOfEncoderSampleIndex);
    };

    class ComputePassSampleBufferAttachmentDescriptorArray : public ns::Object
    {
    public:
        ComputePassSampleBufferAttachmentDescriptorArray();
        ComputePassSampleBufferAttachmentDescriptor*                   GetObject(unsigned int attachmentIndex);
        void                                                           SetObject(const ComputePassSampleBufferAttachmentDescriptor* attachment, unsigned int attachmentIndex);
    };

    class ComputePassDescriptor : public ns::Object
    {
    public:
        ComputePassDescriptor();
        ComputePassDescriptor*                                  GetComputePassDescriptor();

        mtlpp::DispatchType                                     GetDispatchType();
        void                                                    SetDispatchType(mtlpp::DispatchType dispatchType);

        ComputePassSampleBufferAttachmentDescriptorArray*       SampleBufferAttachments();
    };

}
