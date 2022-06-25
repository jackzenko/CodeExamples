#include <iostream>
#include "Logger.h"

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (int i = 0; i < 20; ++i) {
        Logger::GetInstance()->WriteLog(DebugLevel::ERROR, "ThreadFoooo");
    }
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (int i = 0; i < 20; ++i) {
        Logger::GetInstance()->WriteLog(DebugLevel::ERROR, "ThreadBar");
    }
}

int main() {
    Logger::GetInstance()->WriteLog(DebugLevel::ERROR, "Test S1");
    LOG_MSG(DebugLevel::ERROR, "Test S2");
    LOG_MSG_RETURN(DebugLevel::ERROR, true, "Test S3");

    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}

