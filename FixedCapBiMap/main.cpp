#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

int main() {
    testAll();
    testAllExtended();
    std::cout << "That's all!" << std::endl;
    return 0;
}
