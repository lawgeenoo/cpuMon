#include <stdio.h>
#include "alert.h"

#define THRESHOLD 75.0

void check_temp_alert(double temp) {
    static int triggered = 0;

    if (temp > THRESHOLD && !triggered) {
        printf("\a");
        printf("⚠ CPU OVERHEAT: %.1f°C\n", temp);
        triggered = 1;
    }

    if (temp < THRESHOLD - 5) {
        triggered = 0;
    }
}
