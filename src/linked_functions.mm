#include "ns.hpp"
#include "mtlpp.hpp" 

namespace mtlpp {
    class LinkedFunctions : public ns::Object
    {
        public:
            LinkedFunctions();

            ns::Array<mtlpp::Function>*   GetFunctions(){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions.GetPtr()];
            };

            void                          SetFunctions(const ns::Array<mtlpp::Function>* functions){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions.GetPtr()];
            };

            ns::Array<mtlpp::Function>*   GetBinaryFunctions(){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions:(__bridge MTLFunctions*)functions.GetPtr()]
            }

            void                          SetBinaryFunctions(const ns:Array<mtlpp::Function>* binaryFunctions){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions.GetPtr()];
            };
            
            ns::Array<mtlpp::Function>*   GetPrivateFunctions(){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions.GetPtr()];
            };

            void                          SetPrivateFunctions(const ns::Array<mtlpp::Function>* privateFunctions){
                return [(__bridge id<MTLFunction>)m_ptr privateFunctions:(__bridge MTLFunctions*)privateFunctions.GetPtr()]
            };

            ns::Array<ns::Dictionary<ns::String*, ns::Array<mtlpp::Function>>* GetGroups(){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions.GetPtr()];
            };

            void                          SetGroups(const ns::Array<ns::Dictionary<ns::String*, ns::Array<mtlpp::Function>>* groups){
                return [(__bridge id<MTLFunction>)m_ptr binaryFunctions.GetPtr()];
            };
    };
}
