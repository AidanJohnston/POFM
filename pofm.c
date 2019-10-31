#include <stdio.h>

int main(int agrc, char* args[]) {
    printf("%d", agrc);
    for(int i = 0; i < agrc; i ++) {
        printf("%s\n", args[i]);
    }
    return 0;
}