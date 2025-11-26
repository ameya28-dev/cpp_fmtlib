#include "logger.hpp"

fmtlib::Logger fmtlib::Logger::logger;

fmtlib::LogLevel fmtlib::Logger::log_level = fmtlib::LogLevel::DEBUG;

std::tuple<fmt::color, std::string> fmtlib::get_logging_style(const LogLevel& level) {
    switch (level) {
    case LogLevel::DEBUG:
        return {fmt::color::dark_cyan, "DEBUG"};
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

fmtlib::Logger& fmtlib::Logger::get_instance() {
    return logger;
}

fmtlib::Logger& fmtlib::Logger::get_instance(const fmtlib::LogLevel& level) {
    log_level = level;
    return logger;
}
