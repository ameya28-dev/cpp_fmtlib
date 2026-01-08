#include "logger.hpp"

fmtlib::Logger fmtlib::Logger::logger_;

fmtlib::LogLevel fmtlib::Logger::logLevel_ = fmtlib::LogLevel::DEBUG;

std::tuple<fmt::color, std::string> fmtlib::getLoggingStyle(const LogLevel& level) {
    switch (level) {
    case LogLevel::DEBUG:
        return {fmt::color::royal_blue, "DEBUG"};
    case LogLevel::INFO:
        return {fmt::color::green, "INFO"};
    case LogLevel::WARNING:
        return {fmt::color::dark_magenta, "WARNING"};
    case LogLevel::ERR:
        return {fmt::color::red, "ERROR"};
    default:
        return {fmt::color::yellow_green, "UNKNOWN"};
    }
}

fmtlib::Logger& fmtlib::Logger::getInstance() {
    return logger_;
}

fmtlib::Logger& fmtlib::Logger::getInstance(const fmtlib::LogLevel& level) {
    logLevel_ = level;
    return logger_;
}
