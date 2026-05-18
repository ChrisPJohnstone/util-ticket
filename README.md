# Ticket Utility

## Overview

A simple utility script to open Jira tickets from the command line.

### Configuration

- Command to open a browser
    - Environment variable: `BROWSER`
- Base URL for Jira
    - Environment variable: `JIRA_BASE_URL`
- Defalt project key (optional)
    - Environment variable: `JIRA_DEFAULT_PROJECT`

### Examples

```sh
# Open a ticket with the default project key
./ticket 123

# Open a ticket with a specific project key
./ticket ABC-123

# Provide args over stdin
printf '%s\n' 123 ABC-456 | ./ticket

# Open multiple tickets
printf '%s\n' 123 ABC-456 | ./ticket ABC-789 ZYX-987
```

## Roadmap

- [x] Support reading args from argv
- [x] Support reading args from stdin
- [x] Support reading configuration from envars
- [ ] Support reading configuration from a file
- [ ] Figure out packaging and distribution
- [ ] Tests
