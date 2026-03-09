#include "NotificationDispatcher.h"

NotificationDispatcher :: NotificationDispatcher(
    std :: unique_ptr<NotificationChannel> primary,
    std :: unique_ptr<NotificationChannel> fallback,
    RetryPolicy retry
) : primaryChannel(std :: move(primary)), fallbackChannel(std :: move(fallback)), retrypolicy(retry) {}


void NotificationDispatcher :: sendNotification(
    const Notification& notification){
    logger.info("Sending Notification");
    bool success = retrypolicy.execute([&](){
        return primaryChannel->send(notification);
    });

    if (!success && fallbackChannel){
        logger.info("Primary Failde, using Fallback");
        fallbackChannel->send(notification);
    }
}