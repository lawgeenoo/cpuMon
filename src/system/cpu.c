#include <stdio.h>
#include "cpu.h"

double get_cpu_usage() {
    static long prev_total = 0, prev_idle = 0;

    FILE *f = fopen("/proc/stat", "r");
    if (!f) return 0;

    long user, nice, system, idle, iowait, irq, softirq, steal;

    fscanf(f, "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &system, &idle,
           &iowait, &irq, &softirq, &steal);

    fclose(f);

    long idle_all = idle + iowait;
    long non_idle = user + nice + system + irq + softirq + steal;
    long total = idle_all + non_idle;

    long totald = total - prev_total;
    long idled = idle_all - prev_idle;

    prev_total = total;
    prev_idle = idle_all;

    if (totald == 0) return 0;

    return (double)(totald - idled) * 100.0 / totald;
}
