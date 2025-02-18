#include "core/logger.h"
#include "core/asserts.h"
#include "platform/platform.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

b8 initialize_logging() {
    // TODO: Create a log file
    return TRUE;
}

void shutdown_logging() {
    // TODO: cleanup logging/write queued entries.
}

void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {
        "[FATAL]: ", "[ERROR]: ", "[WARN]:  ",
        "[INFO]:  ", "[DEBUG]: ", "[TRACE]: ",
    };

    b8 is_error = level <= LOG_LEVEL_ERROR;

    // impose a 32k character limit on a single log entry
    const i32 msg_length = 32000;
    char out_message[msg_length];
    memset(out_message, 0, sizeof(out_message));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, msg_length, message, arg_ptr);
    va_end(arg_ptr);

    char out_message2[msg_length];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    // platform-specific output.
    if (is_error) {
        platform_console_write_error(out_message2, level);
    } else {
        platform_console_write(out_message2, level);
    }
}

void report_assertion_failure(const char* expression, const char* message,
                              const char* file, i32 line) {
    log_output(LOG_LEVEL_FATAL,
               "assertion failure: %s, message: %s, in file: %s, line: %d\n",
               expression, message, file, line);
}
