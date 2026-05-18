#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void print_usage() {
    printf("Usage: program [arguments]\n");
    printf("Provide arguments or input through stdin.\n");
}

void open_ticket(char *arg) {
    printf("Opening ticket for: %s\n", arg);
    // Simulate ticket opening logic here
}

int main(int argc, char *argv[]) {
    bool has_input = false;
    char line[256];
    if (argc > 1) {
        has_input = true;
        for (int i = 1; i < argc; i++) {
            open_ticket(argv[i]);
        }
    }
    if (!isatty(0)) {
        has_input = true;
        while (fgets(line, sizeof(line), stdin)) {
            line[strcspn(line, "\n")] = '\0';
            open_ticket(line);
        }
    }
    if (!has_input) {
        print_usage();
        return 1;
    }
    return 0;
}
