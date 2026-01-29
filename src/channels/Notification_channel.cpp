#include <iostream>
#include<memory>
using namespace std;

enum class ChannelType
{
    EMAIL,
    SMS,
    PUSH
};

struct Recipient
{
    string email;
    string phone;
    string deviceId;
};

class Notification
{
public:
    Notification(string message, Recipient recipient) : message_(move(message)), recipient_(move(recipient)) {}

    const string &message() const { return message_; }
    const Recipient &recipient() const { return recipient_; }

private:
    string message_;
    Recipient recipient_;
};

class NotificationChannel
{
public:
    virtual ~NotificationChannel() = default;
    virtual bool send(const Notification &notification) = 0;
};



// Concrete Channels

// Email Channel
class EmailChannel: public NotificationChannel{
    public:
    bool send(const Notification& notification) override {
        if(notification.recipient().email.empty()){
            return false;
        }
        cout << "[EMAIL] Sending: " << notification.message() << "\n";
        return true;
    }
};


// SMS Channel
class SMSChannel : public NotificationChannel {
    public:
    bool send(const Notification& notification) override {
        if(notification.recipient().phone.empty()){
            return false;
        }
        cout << "[SMS] Sending: " << notification.message() << "\n";
        return true;
    }
};

// PUSH Channel
class PUSHChannel : public NotificationChannel{
    public:
    bool send(const Notification& notification) override {
        cout << "[PUSH] Sending: " << notification.message() << "\n";
        return true;
    }
};


// Channel Factory
class ChannelFactory {
    public:
    static std :: unique_ptr<NotificationChannel> create(ChannelType type){
        switch (type)
        {
        case ChannelType :: EMAIL:
            return make_unique<EmailChannel>();
        case ChannelType :: SMS:
            return make_unique<SMSChannel>();
        case ChannelType :: PUSH :
            return make_unique<PUSHChannel>();        
        default:
            
            // throw std :: invalid_arguement("Unsupported Channel");
        }
    }
};




