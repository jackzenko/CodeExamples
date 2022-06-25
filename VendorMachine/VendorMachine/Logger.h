#pragma once
#include <mutex>
#include <memory>

#define LOG(info) Logger::GetInstance()->Log(info);
#define LOG_RETURN(expr, info) \
    do { \
        LOG(info); \
        if (!expr) { \
            return -1; \
        } \
    } while (0);

class Logger {
private:
    static std::shared_ptr<Logger> instance;
    static std::mutex mtx;
    int id;

public:
    Logger();

    Logger(Logger& other) = delete;
    void operator=(const Logger&) = delete;

    static std::shared_ptr<Logger> GetInstance();
    void Log(std::string content) noexcept;
};

