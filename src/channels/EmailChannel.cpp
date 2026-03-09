#include "EmailChannel.h"
#include <iostream>

bool EmailChannel :: send(const Notification& notification){
    if(!validateRecipient(notification.getRecipent())){
        return false;
    }
    std :: cout << "[EMAIL]"
                << notification.getMessage().getTitle()
                << "->"
                << notification.getRecipent().getEmail()
                << std :: endl;
    return true;
}

bool EmailChannel :: validateRecipient(const Recipient& recipieint){
    return !recipieint.getEmail().empty();
}