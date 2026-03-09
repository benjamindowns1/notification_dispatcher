#pragma once
#include <functional>


class RetryPolicy {
    private:
    int maxRetries;
    int delaysMs;

    public:
    RetryPolicy(int retries, int delay) : maxRetries(retries), delaysMs(delay) {}

    bool execute(std ::function<bool()> operation);
};