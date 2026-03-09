#pragma once
#include <memory>
#include "../channels/NotificationChannel.h"
#include "../retry/RetryPolicy.h"
#include "../models/Notification.h"
#include "../utils/Logger.h"

class NotificationDispatcher
{
private:
    std ::unique_ptr<NotificationChannel> primaryChannel;
    std ::unique_ptr<NotificationChannel> fallbackChannel;

    RetryPolicy retrypolicy;

    Logger logger;

public:
    NotificationDispatcher(
        std ::unique_ptr<NotificationChannel> primary,
        std ::unique_ptr<NotificationChannel> fallback,
        RetryPolicy retry);

    void sendNotification(const Notification &notification);
};