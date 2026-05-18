# Ticket Utility

## Overview

A simple utility script to open Jira tickets from the command line.

### Configuration

- Command to open a browser
- Base URL for Jira

### Examples

```sh
ticket ABC-123 # Opens the ticket ABC-123 in the browser
ticket 123 # Opens the ticket ABC-123 in the browser (if default project is set to ABC)
```

## Features

- [ ] Support reading configuration from envars
- [ ] Support reading configuration from a file
- [ ] Support default project (if pass just a number should open {project}-{number})
