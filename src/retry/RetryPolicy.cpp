#include "RetryPolicy.h"
#include <thread>
#include <chrono>

bool RetryPolicy :: execute(std :: function<bool()> operation){
    for(int i =0;i<maxRetries; i++){
        if(operation())
            return true;

        std::this_thread ::sleep_for
        (std::chrono::milliseconds(delaysMs));
    }
    return false;
}