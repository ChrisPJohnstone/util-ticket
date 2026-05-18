#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ENVAR_COMMAND "BROWSER"
#define ENVAR_BASE_URL "JIRA_BASE_URL"
#define ENVAR_DEFAULT_PROJECT "JIRA_DEFAULT_PROJECT"

void print_usage() {
    printf("Usage: program [arguments]\n");
    printf("Provide arguments or input through stdin.\n");
}

char *get_command() {
    const char *command = getenv(ENVAR_COMMAND);
    if (command) {
        return strdup(command);
    }
    printf("Error: Environment variable %s not set.\n", ENVAR_COMMAND);
    exit(1);
}

char *get_base_url() {
    // TODO: Support config
    const char *command = getenv(ENVAR_BASE_URL);
    if (command) {
        return strdup(command);
    }
    printf("Error: Environment variable %s not set.\n", ENVAR_BASE_URL);
    exit(1);
}

char *get_default_project() {
    // TODO: Support config
    const char *command = getenv(ENVAR_DEFAULT_PROJECT);
    if (command) {
        return strdup(command);
    }
    return NULL;
}

void open_ticket(
    char *arg,
    char *command,
    char *base_url,
    char *default_project
) {
    printf("Opening ticket for: %s\n", arg);
    // Simulate ticket opening logic here
}

int main(int argc, char *argv[]) {
    char *command = get_command();
    char *base_url = get_base_url();
    char *default_project = get_default_project();
    bool has_input = false;
    char line[256];
    if (argc > 1) {
        has_input = true;
        for (int i = 1; i < argc; i++) {
            open_ticket(argv[i], command, base_url, default_project);
        }
    }
    if (!isatty(0)) {
        has_input = true;
        while (fgets(line, sizeof(line), stdin)) {
            line[strcspn(line, "\n")] = '\0';
            open_ticket(line, command, base_url, default_project);
        }
    }
    if (!has_input) {
        print_usage();
        return 1;
    }
    return 0;
}
