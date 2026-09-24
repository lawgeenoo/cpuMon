#include <unistd.h>

#include "cpu.h"
#include "temp.h"
#include "alert.h"
#include "dashboard.h"
#include "history.h"

int main() {
    while (1) {
        double cpu = get_cpu_usage();
        double temp = get_cpu_temp();

        update_history(cpu);
        check_temp_alert(temp);
        draw_dashboard(cpu, temp);

        usleep(500000); // 0.5s refresh
    }

    return 0;
}
