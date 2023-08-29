#ifndef LOG4CPP_LOG_H
#define LOG4CPP_LOG_H

#include <string>

#ifdef LOG4CPP_IMPL
#include <iostream>
#include <chrono>
#include <iomanip>

#define COLOR_RESET "\033[0m"

    class logger {
        private:
            void log(std::string type, const char* typeColor, std::string str) {                
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
                            << str
                            << COLOR_RESET << std::endl;
            }

        public:
            void debug(std::string str) {
                this->log(std::string("DEBUG"), "\033[39m", str);
            }

            void info(std::string str) {
                this->log(std::string("INFO"), "\033[34m", str);
            }

            void success(std::string str) {
                this->log(std::string("SUCESS"), "\e[0;32m", str);
            }

            void warning(std::string str) {
                this->log(std::string("WARNING"), "\033[35m", str);
            }

            void error(std::string str) {
                this->log(std::string("ERROR"), "\033[31m", str);
            }

    };
#else
    class logger {
        private:
            void log(std::string type, const char* typeColor, std::string str);
        public:
            void debug(std::string str);
            void info(std::string str);
            void sucess(std::string str);
            void warning(std::string str);
            void error(std::string str);
    };
#endif

#endif