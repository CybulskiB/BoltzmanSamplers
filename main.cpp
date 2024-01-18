#include <iostream>
#include "boltzmann_samplers.h"
#include "train_saver.h"
#include "alg.h"
#include "train_researcher.h"
#include "tests.h"



int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //single_train_test();
    sizes_test();
    //functionality_test();
    //gf_value_test();
    return 0;
}
