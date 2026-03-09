#pragma once
#include <string>
#include <chrono>
#include "Message.h"
#include "Recipient.h"

class Notification {
    private:
    std :: string id;
    Message message;
    Recipient recipient;
    std :: chrono :: system_clock :: time_point timestamp;

    public:
    Notification(std:: string id, Message msg, Recipient rec) : id(id), message(msg), recipient(rec) {
        timestamp = std :: chrono :: system_clock :: now();
    }
    const Message& getMessage() const {return message;}
    const Recipient& getRecipent() const {return recipient;}
};