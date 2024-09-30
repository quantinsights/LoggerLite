#ifndef COMMON_DEFS_HPP
#define COMMON_DEFS_HPP
#include<string>

namespace LIB {
    enum class LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        CRITICAL,
        FATAL,
        INVALID
    };

    enum class Sink {
        console,
        file,
        both
    };

    inline Sink ToSink(std::string sink) {
        if (sink == "file") {
            return Sink::file;
        } else if (sink == "console") {
            return Sink::console;
        } else {
            return Sink::both;
        }
    };

    inline LogLevel ToLogLevel(std::string loglevel) {
        if (loglevel == "DEBUG") {
            return LogLevel::DEBUG;
        } else if (loglevel == "INFO") {
            return LogLevel::INFO;
        } else if (loglevel == "WARNING") {
            return LogLevel::WARNING;
        } else if (loglevel == "ERROR") {
            return LogLevel::ERROR;
        } else if (loglevel == "CRITICAL") {
            return LogLevel::CRITICAL;
        } else if (loglevel == "FATAL") {
            return LogLevel::FATAL;
        }
        return LogLevel::INVALID;
    };

    inline std::string getLogLevelString(LogLevel logLevel) {
        switch (logLevel) {
            case LogLevel::DEBUG: {
                return "DEBUG";
            }
            case LogLevel::INFO: {
                return "INFO";
            }
            case LogLevel::WARNING: {
                return "WARN";
            }
            case LogLevel::ERROR: {
                return "ERR";
            }
            case LogLevel::CRITICAL: {
                return "CRIT";
            }
            case LogLevel::FATAL: {
                return "FATAL";
            }
            default:
                return std::string();
                break;
        }
    }

} // namespace LIB
#endif