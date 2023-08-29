#ifndef LOG4CPP_LOG_H
#define LOG4CPP_LOG_H

#include <string>

#define LOG4CPP_IMPL

#ifdef LOG4CPP_IMPL
#include <iostream>
#include <chrono>
#include <iomanip>

#define COLOR_RESET "\033[0m"

    class logger {
        private:
            void log(std::string type, char* typeColor, std::string str, char* strColor) {                
                auto currentTime = std::chrono::system_clock::now();
                auto currentTimePoint = std::chrono::system_clock::to_time_t(currentTime);
                std::tm timeInfo = *std::localtime(&currentTimePoint);
                std::string space_str = "";

                size_t len = type.length() -1;


                for (; len < 8; len++)
                    space_str += " ";
                
                // Format and print the time
                std::cout   << std::put_time(&timeInfo, "%H:%M:%S")
                            << " | "
                            << "\033[1m" << typeColor << type << "\033[21m" COLOR_RESET << space_str
                            << strColor << str
                            << COLOR_RESET << std::endl;
            }

        public:
            void debug(std::string str) {
                this->log("DEBUG", "\033[39m", str, "");
            }

            void info(std::string str) {
                this->log("INFO", "\033[34m", str, "");
            }

            void sucess(std::string str) {
                this->log("SUCESS", "\033[32m", str, "");
            }

            void warning(std::string str) {
                this->log("WARNING", "\033[35m", str, "");
            }

            void error(std::string str) {
                this->log("ERROR", "\033[31m", str, "");
            }

    };
#else
    class logger {
        private:
            void log(std::string str);
        public:
            void debug(std::string str);
            void info(std::string str);
            void sucess(std::string str);
            void warning(std::string str);
            void error(std::string str);
    };
#endif

#endif