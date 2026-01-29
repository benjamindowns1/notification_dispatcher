#include <iostream>
using namespace std;

// Retry Policy -> Strategy
class RetryPolicy
{
public:
    explicit RetryPolicy(int maxRetries) : maxRetries_(maxRetries) {}

    template <typename Func>
    bool execute(Func &&func)
    {
        for (int attempt = 1; attempt <= maxRetries_; ++attempt)
        {
            if (func())
            {
                return true;
            }
        }
        return false;
    }

private:
    int maxRetries_;
};
