// #include <getopt.h>
// #include <cstdio>
// #include <cstdlib>
// #include <ctype.h>
// #include <stdint.h>
// #include <signal.h>
#include "Top/App.hpp"

int main(int argc, char* argv[]) {
    App::Initialize();
    App::run_one_cycle();
    App::Deinitialize();
    return 0;
}
