#define SIZE 30

static double history[SIZE];
static int index = 0;

void update_history(double cpu) {
    history[index++] = cpu;
    if (index >= SIZE) index = 0;
}

double* get_history(void) {
    return history;
}

int get_history_size(void) {
    return SIZE;
}
