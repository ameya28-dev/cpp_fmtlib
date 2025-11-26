#ifndef CPP_FMTLIB_LOGGER_HPP
#define CPP_FMTLIB_LOGGER_HPP

#include <cstdio>
#include <mutex>
#include <string>
#include <string_view>
#include <utility>

#include "core.hpp"

namespace fmtlib {
    enum class LogLevel { DEBUG, INFO, WARNING, ERR };

    std::tuple<fmt::color, std::string> get_logging_style(const LogLevel&);

    class Logger {
    public:
        Logger(const Logger&)            = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&)                 = delete;
        Logger& operator=(Logger&&)      = delete;

        static Logger& get_instance();

        static Logger& get_instance(const LogLevel&);

        template <typename... Args>
        void debug(std::string_view, Args&&...);

        template <typename... Args>
        void info(std::string_view, Args&&...);

        template <typename... Args>
        void warning(std::string_view, Args&&...);

        template <typename... Args>
        void error(std::string_view, Args&&...);

    private:
        Logger()  = default;
        ~Logger() = default;

        template <typename... Args>
        void log_msg(const LogLevel&, std::string_view, Args&&...);

        template <typename... Args>
        void log(const LogLevel&, std::string_view, Args&&...);

    private:
        static Logger logger;
        std::mutex mtx;
        static LogLevel log_level;
    };

    template <typename... Args>
    void Logger::debug(std::string_view fmt_str, Args&&... args) {
        log(LogLevel::DEBUG, fmt_str, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void Logger::info(std::string_view fmt_str, Args&&... args) {
        log(LogLevel::INFO, fmt_str, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void Logger::warning(std::string_view fmt_str, Args&&... args) {
        log(LogLevel::WARNING, fmt_str, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void Logger::error(std::string_view fmt_str, Args&&... args) {
        log(LogLevel::ERR, fmt_str, std::forward<Args>(args)...);
    }


    template <typename... Args>
    void Logger::log_msg(const LogLevel& level, const std::string_view fmt_str, Args&&... args) {
        auto [color, level_name] = get_logging_style(level);

        if (level != LogLevel::ERR) {
            fmt::print(fg(color), "[{}] ", level_name);
            fmt::print(fg(color), "{}\n", fmt::vformat(fmt_str, fmt::make_format_args(args...)));
        } else {
            fmt::print(stderr, fmt::emphasis::bold | fg(color), "[{}] ", level_name);
            fmt::print(
                stderr, fmt::emphasis::bold | fg(color), "{}\n", fmt::vformat(fmt_str, fmt::make_format_args(args...)));
        }
    }

    template <typename... Args>
    void Logger::log(const LogLevel& level, std::string_view fmt_str, Args&&... args) {
#ifdef NDEBUG
        return;
#endif
        if (log_level > level) {
            return;
        }

        std::scoped_lock<std::mutex> lock(mtx);
        log_msg(level, fmt_str, std::forward<Args>(args)...);
    }
} // namespace fmtlib

#endif // CPP_FMTLIB_LOGGER_HPP
