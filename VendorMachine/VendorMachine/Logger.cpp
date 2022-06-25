#include <iostream>
#include <string>
#include "Logger.h"

std::shared_ptr<Logger> Logger::instance;
std::mutex Logger::mtx;

Logger::Logger() {
    id = 1000;
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

void Logger::Log(std::string content) noexcept {
    try {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Log ID: " << std::to_string(id)
            << " Content: " << content << std::endl;
        ++id;
    }
    catch (...) {
        // do nothing, ignore log errors
    }
}

