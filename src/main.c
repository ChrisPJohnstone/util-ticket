#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ENVAR_COMMAND "BROWSER"
#define ENVAR_BASE_URL "JIRA_BASE_URL"
#define ENVAR_DEFAULT_PROJECT "JIRA_DEFAULT_PROJECT"

void print_usage() {
    printf("Usage: program [TICKET_ID]\n");
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
    char *ticket,
    char *command,
    char *base_url,
    char *default_project
) {
    char *full_id;
    if (isdigit(ticket[0])) {
        if (!default_project) {
            printf("Error: Project unspecified and default project not set.\n");
            exit(1);
        }
        asprintf(&full_id, "%s-%s", default_project, ticket);
    } else {
        full_id = strdup(ticket);
    }
    char *url;
    asprintf(&url, "%s/browse/%s", base_url, full_id);
    char *final_command;
    asprintf(&final_command, "%s %s", command, url);
    system(final_command);
    free(full_id);
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
