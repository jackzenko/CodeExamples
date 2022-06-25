#include <iostream>
#include <string>
#include "Logger.h"
#include "stdarg.h"

std::shared_ptr<Logger> Logger::instance;
std::mutex Logger::mtx;

Logger::Logger() {
    Logger::logPath = "D:\\temp\\LogSystemOutput.txt";
    Logger::debugLevel = DebugLevel::ERROR;
    Logger::id = 0;
    Logger::logFileHandle = fopen(logPath.c_str(), "a");
}

Logger::~Logger()
{
    if (Logger::logFileHandle) {
        fflush(Logger::logFileHandle);
        fclose(Logger::logFileHandle);
    }
}

std::shared_ptr<Logger> Logger::GetInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance == nullptr) {
            instance = std::make_shared<Logger>();
        }
    }
    return instance;
}

void Logger::WriteLog(int debugLevel, const char* format, ...) noexcept
{
    try {
        va_list args;
        if (Logger::logFileHandle && (debugLevel <= Logger::debugLevel)) {
            
            const char* debugLevelStr = "INFO";
            if (debugLevel == DebugLevel::ERROR)
                debugLevelStr = "ERROR";
            else if (debugLevel == DebugLevel::WARNING)
                debugLevelStr = "WARNING";

            size_t len = strlen(format);
            char* newFormat = (char*)malloc(len) + 10;
            if (newFormat) {
                memset(newFormat, '\0', len);
                // sprintf(newFormat, "%s %s: %s", std::to_string(id), debugLevelStr, format);

                va_start(args, format);
                vfprintf(Logger::logFileHandle, newFormat, args);
                va_end(args);
                fflush(Logger::logFileHandle);

                free(newFormat);
            }
        }
    }
    catch (...) { } // do nothing, ignore log errors
}

