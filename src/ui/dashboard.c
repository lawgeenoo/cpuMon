#include <stdio.h>
#include "graph.h"

void draw_dashboard(double cpu, double temp) {
    printf("\033[H\033[J"); // clear screen

    printf("=== CPU MONITOR DASHBOARD ===\n\n");

    printf("CPU Usage : %.1f%%\n", cpu);
    printf("CPU Temp  : %.1f°C\n", temp);

    draw_graph();
}
