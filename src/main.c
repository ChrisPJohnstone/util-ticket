#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void print_usage() {
    printf("Usage: program [arguments]\n");
    printf("Provide arguments or input through stdin.\n");
}

int main(int argc, char *argv[]) {
    bool has_input = false;
    char line[256];
    if (argc > 1) {
        has_input = true;
        for (int i = 1; i < argc; i++) {
            printf("Argument %d: %s\n", i, argv[i]);
        }
    }
    if (!isatty(0)) {
        has_input = true;
        while (fgets(line, sizeof(line), stdin)) {
            printf("Input: %s", line);
        }
    }
    if (!has_input) {
        print_usage();
        return 1;
    }
    return 0;
}
