#ifndef LOG4CPP_LOG_H
#define LOG4CPP_LOG_H

#include <string>

#ifdef LOG4CPP_IMPL
    class logger {
        private:
            void log(std::string str) {

            }
            
        public:
            void debug(std::string str) {

            }

            void info(std::string str) {

            }

            void sucess(std::string str) {

            }

            void warning(std::string str) {

            }

            void error(std::string str) {

            }

    }
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