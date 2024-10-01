#include "Logger.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include<filesystem>

namespace LIB { 
    Logger& Logger::instance() {
        static Logger loggerInstance;
        return loggerInstance;
    }

    void Logger::set_log_level(LogLevel logLevel) {
        this->logLevel = logLevel;
    }

    void Logger::log(LogLevel logLevel, const std::string& inputStr, const std::string& file, int line) {
        if (this->logLevel > logLevel) {
            return;
        }
        this->logSink->log(logLevel, inputStr, file, line);
    }

    void Logger::load_config(const std::string& configFile) {
        std::filesystem::path filePath(configFile);
        std::fstream inputfile(filePath);
        if (not inputfile.is_open()) {
            std::cout << "Unable to open input file " << configFile << std::endl;
            return;
        }
        std::string line;
        std::map<std::string, std::string> ConfigKeyValuePairs;

        while (getline(inputfile, line)) {
            std::istringstream logLevelSS(line);
            std::string key, value;
            if (getline(logLevelSS, key, '=') && getline(logLevelSS, value)) {
                ConfigKeyValuePairs[key] = value;
            }
        }
        this->logLevel = ToLogLevel(ConfigKeyValuePairs.at("log_level"));
        auto sink = ToSink(ConfigKeyValuePairs.at("sinks"));
        auto filePathIter = ConfigKeyValuePairs.find("file_path");
        if (filePathIter != ConfigKeyValuePairs.end()) {
            this->filePath = filePathIter->second;
        }
        switch (sink) {
            case Sink::file: {
                if (not this->filePath.empty()) {
                    this->logSink = std::make_shared<FileSink>(this->filePath);
                }
            }
            break;
            case Sink::console : {
                this->logSink = std::make_shared<ConsoleSink>();
            }
            default:
                break;
        }
    }
}