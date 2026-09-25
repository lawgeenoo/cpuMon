#include <stdio.h>
#include "graph.h"

#define TEMP_WARN_LEVEL 50.0
#define TEMP_CRITICAL_LEVEL 75.0


static const char *COLOR_GREEN  = "\033[32m";
static const char *COLOR_YELLOW = "\033[33m";
static const char *COLOR_RED    = "\033[31m";

static const char *get_color_for_value(double value) {
    if (value < TEMP_WARN_LEVEL) {
        return COLOR_GREEN;
    } else if (value < TEMP_CRITICAL_LEVEL) {
        return COLOR_YELLOW;
    } else {
        return COLOR_RED;
    }
}

void draw_dashboard(double cpu, double temp) {
    printf("\033[H\033[J");
    printf("=== CPU MONITOR DASHBOARD ===\n\n");
    printf("CPU Usage : %.1f%%\n", cpu);
    printf("%sCPU Temp  : %.1f°C\033[0m\n", get_color_for_value(temp), temp);

    draw_graph();
}
