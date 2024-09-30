#include<iostream>
#include "Logger.hpp"

int main() {
    LIB::Logger& logger = LIB::Logger::instance();

    logger.load_config("configs/GoldenConfigFile.txt");

    // Testing Valid Scenarios
    logger.set_log_level(LIB::LogLevel::DEBUG);
    
    LOG_DEBUG("This is a DEBUG message.");

    logger.set_log_level(LIB::LogLevel::INFO);
    LOG_INFO("This is an INFO message.");

    logger.set_log_level(LIB::LogLevel::WARNING);
    LOG_WARN("This is a WARNING message.");

    logger.set_log_level(LIB::LogLevel::ERROR);
    LOG_ERROR("This is an ERROR message.");

    logger.set_log_level(LIB::LogLevel::CRITICAL);
    LOG_CRITICAL("This is a CRITICAL message.");

    logger.set_log_level(LIB::LogLevel::FATAL);
    LOG_FATAL("This is a FATAL message.");

    // Testing wrong scenario
    logger.set_log_level(LIB::LogLevel::INFO);
    LOG_DEBUG("This is a DEBUG message.");
}