
#include <AzCore/Serialization/SerializeContext.h>

#include "ConversationDemoSystemComponent.h"

#include <ConversationDemo/ConversationDemoTypeIds.h>

namespace ConversationDemo
{
    AZ_COMPONENT_IMPL(ConversationDemoSystemComponent, "ConversationDemoSystemComponent",
        ConversationDemoSystemComponentTypeId);

    void ConversationDemoSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<ConversationDemoSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void ConversationDemoSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("ConversationDemoService"));
    }

    void ConversationDemoSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("ConversationDemoService"));
    }

    void ConversationDemoSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void ConversationDemoSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    ConversationDemoSystemComponent::ConversationDemoSystemComponent()
    {
        if (ConversationDemoInterface::Get() == nullptr)
        {
            ConversationDemoInterface::Register(this);
        }
    }

    ConversationDemoSystemComponent::~ConversationDemoSystemComponent()
    {
        if (ConversationDemoInterface::Get() == this)
        {
            ConversationDemoInterface::Unregister(this);
        }
    }

    void ConversationDemoSystemComponent::Init()
    {
    }

    void ConversationDemoSystemComponent::Activate()
    {
        ConversationDemoRequestBus::Handler::BusConnect();
    }

    void ConversationDemoSystemComponent::Deactivate()
    {
        ConversationDemoRequestBus::Handler::BusDisconnect();
    }
}
