#include<iostream>
#include<memory>
#include "Notification_channel.cpp"
using namespace std;


class NotificationDispacter {
    public:
    NotificationDispacter(
        unique_ptr<NotificationChannel> primary;
        unique_ptr<NotificationChannel> fallback;
        RetryPolicy retry;
    )
}