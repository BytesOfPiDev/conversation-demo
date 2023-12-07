
#pragma once

#include <AzCore/Component/Component.h>

#include <ConversationDemo/ConversationDemoBus.h>

namespace ConversationDemo
{
    class ConversationDemoSystemComponent
        : public AZ::Component
        , protected ConversationDemoRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(ConversationDemoSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        ConversationDemoSystemComponent();
        ~ConversationDemoSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // ConversationDemoRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
