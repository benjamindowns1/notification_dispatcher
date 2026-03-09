#pragma once
#include "NotificationChannel.h"

class PushChannel : public NotificationChannel
{
public:
    bool send(const Notification &notification) override;
    bool validateRecipient(const Recipient &recipient) override;
};