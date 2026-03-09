#pragma once
#include <memory>
#include "../channels/NotificationChannel.h"

class ChannelFactory {
    public:
    static std :: unique_ptr<NotificationChannel>
    createChannel(ChannelType type);
};