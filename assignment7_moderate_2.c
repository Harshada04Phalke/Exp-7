/* Assignment 7 - Moderate Variation 2
 * Case-insensitive parsing and loop with EXIT
 * File: assignment7_moderate_2.c
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toupper_inplace(char *s) { for (; *s; ++s) *s = toupper(*s); }

int main() {
    char cmd[64];
    printf("Assignment7 Moderate #2 - Commands: START, STOP, STATUS, EXIT\n");
    while (1) {
        printf("> ");
        if (scanf("%63s", cmd) != 1) break;
        toupper_inplace(cmd);
        if (strcmp(cmd, "START") == 0) printf("Robot Started\n");
        else if (strcmp(cmd, "STOP") == 0) printf("Robot Stopped\n");
        else if (strcmp(cmd, "STATUS") == 0) printf("All systems nominal\n");
        else if (strcmp(cmd, "EXIT") == 0) break;
        else printf("Unknown command\n");
    }
    return 0;
}
