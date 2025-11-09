/* Assignment 7 - Easy Variation 18
 * START/STOP basic parsing (case-sensitive)
 * File: assignment7_easy_18.c
 */
#include <stdio.h>
#include <string.h>

int main() {
    char cmd[32];
    printf("Assignment7 Easy #18 - Enter Command (START/STOP): ");
    if (scanf("%31s", cmd) != 1) return 1;
    if (strcmp(cmd, "START") == 0) printf("Robot Started\n");
    else if (strcmp(cmd, "STOP") == 0) printf("Robot Stopped\n");
    else printf("Invalid Command\n");
    return 0;
}
