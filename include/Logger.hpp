#ifndef LOGGER_HPP
#define LOGGER_HPP

#include<memory>
#include "LogSink.hpp"

#define LOG_INFO(message)     (logger).log(LIB::LogLevel::INFO, message, __FILE__, __LINE__)
#define LOG_DEBUG(message)    (logger).log(LIB::LogLevel::DEBUG, message, __FILE__, __LINE__)
#define LOG_WARN(message)     (logger).log(LIB::LogLevel::WARNING, message, __FILE__, __LINE__)
#define LOG_ERROR(message)    (logger).log(LIB::LogLevel::ERROR, message, __FILE__, __LINE__)
#define LOG_CRITICAL(message) (logger).log(LIB::LogLevel::CRITICAL, message, __FILE__, __LINE__)
#define LOG_FATAL(message)    (logger).log(LIB::LogLevel::FATAL, message, __FILE__, __LINE__)

namespace LIB {
    class Logger {
        public:
            // singleton class only one instance
            static Logger& instance();
            void load_config(const std::string& configFile);
            void set_log_level(LogLevel logLevel);
            void log(LogLevel logLevel, const std::string& inputStr, const std::string& file, int line);
            
            // deleted the copy constructor and assignement operator
            Logger(const Logger&) = delete;
            Logger& operator=(const Logger&) = delete;
        
        private:
            Logger() {};
            ~Logger() {};
            std::shared_ptr<LogSink> logSink;
            std::string filePath;
            LogLevel logLevel = LogLevel::INFO;
    };
}
#endif