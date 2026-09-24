#include <stdio.h>
#include "temp.h"

double get_cpu_temp() {
    FILE *f = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (!f) return 0;

    int temp;
    fscanf(f, "%d", &temp);
    fclose(f);

    return temp / 1000.0;
}
