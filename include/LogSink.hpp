#ifndef LOG_SINK_HPP
#define LOG_SINK_HPP

#include<iostream>
#include<fstream>
#include<sstream>
#include "CommonDefs.hpp"


namespace LIB {
    class LogSink {
        public:
            virtual ~LogSink() = default;
            virtual void log(LogLevel level, const std::string& message, const std::string& file, int line) = 0;
    };

    class ConsoleSink : public LogSink {
        public:
            ConsoleSink() {}
            ~ConsoleSink() {}
            void log(LogLevel level, const std::string& message, const std::string& file, int line) override {
                std::cout << "[" << getLogLevelString(level) << "]: "
                                << message << "(" << file << ":" << line << ")" << std::endl;
            }
    };

    class FileSink : public LogSink {
        public:
            FileSink(const std::string& inputFile) : filePath(inputFile){}

            void log(LogLevel level, const std::string& message, const std::string& file, int line) override {
                std::ofstream outFile(filePath, std::ios_base::app);
                if (outFile.is_open()) {
                    std::stringstream formattedMessage;
                    formattedMessage << "[" << getLogLevelString(level) << "]: "
                                    << message << "(" << file << ":" << line << ")";
                    outFile << formattedMessage.str() << std::endl;
                    outFile.close();
                } else {
                    std::cerr << "Unable to open file: " << filePath << std::endl;
                }
            }
            ~FileSink() {}
        private:
            std::string filePath;
    };
}

#endif