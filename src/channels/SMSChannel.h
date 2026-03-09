#pragma once
#include "NotificationChannel.h"

class SMSChannel : public NotificationChannel
{
public:
    bool send(const Notification &notification) override;
    bool validateRecipient(const Recipient &recipient) override;
};