cmake_minimum_required(VERSION 3.8)

project("LoggerLite")

include_directories(include)

set(SOURCES main.cpp src/Logger.cpp)

add_executable(loggerLite ${SOURCES})

file(COPY configs/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/configs/)
# Need suggestions to add configs with relative path