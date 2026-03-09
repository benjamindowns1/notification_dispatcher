#pragma once
#include "NotificationChannel.h"

class EmailChannel : public NotificationChannel {
    public:
    bool send(const Notification& notification) override;
    bool validateRecipient(const Recipient& recipient) override;
};