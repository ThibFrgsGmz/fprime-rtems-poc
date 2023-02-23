// #include <getopt.h>
// #include <cstdio>
// #include <cstdlib>
// #include <ctype.h>
// #include <stdint.h>
// #include <signal.h>
#include "Top/App.hpp"
#include <stdio.h>
int main(int argc, char* argv[]) {
    App::Initialize();
    printf("Hello World\n");
    App::run_one_cycle();
    App::Deinitialize();
    return 0;
}
