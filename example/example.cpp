#define LOG4CPP_IMPL
#include <Log4CPP/logger.hpp>

int main() {
    logger Logger;

    Logger.debug("This is a debug message");
    Logger.info("This is a info message");
    Logger.success("This is a sucess message");
    Logger.warning("This is a warning message");
    Logger.error("This is an error message");

    return 0;
}
