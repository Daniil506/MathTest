#include <iostream>
#include <ctime>
#include "MathTest.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    MathTest test(5, 1, 20);   
    test.run();

    return 0;
}