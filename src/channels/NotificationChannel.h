# pragma once
# include "../Notification.h"


enum class ChannelType {
    EMAIL,
    SMS,
    PUSH
};

class NotificationChannel {
    public:
    virtual ~NotificationChannel() = default;
    virtual bool send(const Notification& notification) = 0;
    virtual bool validateRecipient(const Recipient& recipient) =0;
};