# pragma once
#include <string>

class Message {
    private:
    std:: string title;
    std:: string body;

    public:
    Message(std:: string title, std:: string body) : title(title), body(body) {}
    const std::string &getTitle() const {return title;}
    const std::string &getBody() const {return body;}
};

