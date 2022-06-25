#pragma once
#include <mutex>
#include <memory>

#define LOG_MSG(logLevel, logMessage) Logger::GetInstance()->WriteLog(logLevel, logMessage);
#define LOG_MSG_VAL1(logLevel, logMessage, val1) Logger::GetInstance()->WriteLog(logLevel, logMessage, val1);
#define LOG_MSG_VAL2(logLevel, logMessage, val1, val2) Logger::GetInstance()->WriteLog(logLevel, logMessage, val1, val2);
#define LOG_MSG_BY_EXPR(logLevel, expr, logMessage) \
	do{ \
        if (!expr) { \
            LOG_MSG(logLevel, logMessage); \
        } \
    } while (0);
#define LOG_MSG_RETURN(logLevel, expr, logMessage) \
    do { \
        LOG_MSG(logLevel, logMessage); \
        if (!expr) { \
            return -1; \
        } \
    } while (0);

enum DebugLevel {
    UNDEFINED = 0,
    ERROR,
    WARNING,
    INFO
};

class Logger {
private:
    static std::shared_ptr<Logger> instance;
    static std::mutex mtx;
    DebugLevel debugLevel = DebugLevel::UNDEFINED;
    std::string logPath = "";
    FILE* logFileHandle = nullptr;
    int id = 0;

public:
    Logger();
    ~Logger();

    Logger(const Logger& other) = delete;
    auto operator=(const Logger& other) = delete;

    static std::shared_ptr<Logger> GetInstance();
    void WriteLog(int devugLevel, const char* format, ...) noexcept;
};

