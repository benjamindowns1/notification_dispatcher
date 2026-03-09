#include "SMSChannel.h"
#include <iostream>

bool SMSChannel ::send(const Notification &notification)
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

bool SMSChannel :: validateRecipient(const Recipient &recipieint)
{
    return !recipieint.getEmail().empty();
}