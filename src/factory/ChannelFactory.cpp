#include "ChannelFactory.h"
#include "../channels/EmailChannel.h"
#include "../channels/PushChannel.h"
#include "../channels/SMSChannel.h"

std :: unique_ptr<NotificationChannel>
ChannelFactory :: createChannel(ChannelType type){
    switch(type) {
        case ChannelType :: EMAIL:
            return std :: make_unique<EmailChannel>();

        case ChannelType ::SMS:
            return std ::make_unique<SMSChannel>();

        case ChannelType ::PUSH:
            return std ::make_unique<PushChannel>();
        
        default:
            return nullptr;

        }
        
}