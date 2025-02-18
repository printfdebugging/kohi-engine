#include <core/logger.h>
#include <platform/platform.h>

int main() {
    KWARN("here goes the warning");
    KINFO("here goes the info");
    KDEBUG("here goes the debug");
    KTRACE("here goes the trace");

    platform_state state;
    if (platform_startup(&state, "Kohi Engine Test", 100, 100, 1280, 720)) {
        while (TRUE) {
            platform_pump_messages(&state);
        }
    }

    platform_shutdown(&state);
    return 0;
}
