
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "ConversationDemoSystemComponent.h"

#include <ConversationDemo/ConversationDemoTypeIds.h>

namespace ConversationDemo
{
    class ConversationDemoModule : public AZ::Module
    {
    public:
        AZ_RTTI(ConversationDemoModule, ConversationDemoModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(ConversationDemoModule, AZ::SystemAllocator);

        ConversationDemoModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(
                m_descriptors.end(),
                {
                    ConversationDemoSystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<ConversationDemoSystemComponent>(),
            };
        }
    };
} // namespace ConversationDemo

AZ_DECLARE_MODULE_CLASS(Gem_ConversationDemo, ConversationDemo::ConversationDemoModule)
