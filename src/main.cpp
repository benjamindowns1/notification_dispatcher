#include "dispatcher/NotificationDispatcher.h"
#include "factory/ChannelFactory.h"
#include "models/Notification.h"
#include "models/Recipient.h"
#include "models/Message.h"
#include "retry/RetryPolicy.h"

int main()
{

    Recipient recipient("user1", "test@email.com", "9876543210", "device123");

    Message message("Order Update", "Your order has been shipped.");

    Notification notification("notif-1", message, recipient);

    auto primary = ChannelFactory::createChannel(ChannelType::EMAIL);
    auto fallback = ChannelFactory::createChannel(ChannelType::SMS);

    RetryPolicy retry(3, 1000);

    NotificationDispatcher dispatcher(std::move(primary), std::move(fallback), retry);

    dispatcher.sendNotification(notification);

    return 0;
}