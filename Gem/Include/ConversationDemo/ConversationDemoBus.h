
#pragma once

#include <ConversationDemo/ConversationDemoTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace ConversationDemo
{
    class ConversationDemoRequests
    {
    public:
        AZ_RTTI(ConversationDemoRequests, ConversationDemoRequestsTypeId);
        virtual ~ConversationDemoRequests() = default;
        // Put your public methods here
    };

    class ConversationDemoBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using ConversationDemoRequestBus = AZ::EBus<ConversationDemoRequests, ConversationDemoBusTraits>;
    using ConversationDemoInterface = AZ::Interface<ConversationDemoRequests>;

} // namespace ConversationDemo
