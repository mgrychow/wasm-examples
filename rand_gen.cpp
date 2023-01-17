#include <iostream>
#include <random>
#include <chrono>
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>

using namespace emscripten;

EMSCRIPTEN_KEEPALIVE int getRandom()
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::uniform_int_distribution<int> distribution(1,100);
    return distribution(generator); 
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("getRandom", &getRandom);
}

// int main()
// {
//     std::cout << getRandom() << std::endl;
// }