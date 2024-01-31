#include "stdio.h"
#include "stdlib.h"

// #include <sys/types.h>
#include <sys/stat.h>
// #include <unistd.h>

int main(int argc, char* argv[]) {
    struct stat st = {0};
    if (stat("./abc", &st) == -1) {
        mkdir("./abc", 0700);
    }
    return 0;
}
