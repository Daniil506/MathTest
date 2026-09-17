#include <iostream>
#include <ctime>
#include "MathTest.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    MathTest test(5, 1, 20);   // 5 §Ó§à§á§â§à§ã§à§Ó, §é§Ú§ã§Ý§Ñ §à§ä 1 §Õ§à 20
    test.run();

    return 0;
}