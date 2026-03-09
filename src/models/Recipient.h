#pragma once
#include <string>

class Recipient {
    private:
    std :: string userId;
    std :: string email;
    std :: string phone;
    std :: string deviceId;

    public:
    Recipient( std :: string uid, std :: string mail, std :: string ph, std :: string dev): userId(uid), email(mail),phone(ph), deviceId(dev) {}

    const std :: string& getEmail() const {return email;}
    const std ::string &getPhone() const { return phone; }
    const std ::string &getDeviceId() const { return deviceId; }
};