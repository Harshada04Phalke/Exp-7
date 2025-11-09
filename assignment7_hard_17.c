/* Assignment 7 - Hard Variation 17
 * Command history (circular buffer) and status info
 * File: assignment7_hard_17.c
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toupper_inplace(char *s) { for (; *s; ++s) *s = toupper(*s); }

int main() {
    char cmd[64];
    const int HSIZE = 8;
    char history[8][64] = {{0}};
    int idx = 0, total = 0;
    printf("Assignment7 Hard #17 - Commands: START STOP STATUS HISTORY EXIT\n");
    while (1) {
        printf("> ");
        if (scanf("%63s", cmd) != 1) break;
        toupper_inplace(cmd);
        strncpy(history[idx], cmd, 63); history[idx][63] = '\0';
        idx = (idx + 1) % HSIZE; if (total < HSIZE) total++;
        if (strcmp(cmd, "START") == 0) printf("Robot Started\n");
        else if (strcmp(cmd, "STOP") == 0) printf("Robot Stopped\n");
        else if (strcmp(cmd, "STATUS") == 0) printf("Status: ACTIVE, all sensors OK\n");
        else if (strcmp(cmd, "HISTORY") == 0) { printf("Recent commands:\n"); 
            int s = total==HSIZE? idx : 0; int c=0;
            for (int i=0;i<total;i++) { printf("%d. %s\n", ++c, history[(s+i)%HSIZE]); }
        }
        else if (strcmp(cmd, "EXIT") == 0) break;
        else printf("Unknown command\n");
    }
    return 0;
}
