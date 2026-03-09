#include "PushChannel.h"
#include <iostream>

bool PushChannel ::send(const Notification &notification)
{
    if (!validateRecipient(notification.getRecipent()))
    {
        return false;
    }
    std ::cout << "[EMAIL]"
               << notification.getMessage().getTitle()
               << "->"
               << notification.getRecipent().getEmail()
               << std ::endl;
    return true;
}

bool PushChannel ::validateRecipient(const Recipient &recipieint)
{
    return !recipieint.getEmail().empty();
}