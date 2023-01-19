#include <iostream>
#include <random>
#include <chrono>
#ifdef ENABLE_WASM
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
using namespace emscripten;
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

class IncrementalRandom
{
public:
    IncrementalRandom(): increments(0) {}
    int getRandom()
    {
        unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed1);
        std::uniform_int_distribution<int> distribution(10*increments,10*increments+100);
        ++increments;
        return distribution(generator);
    }
private:
    int increments;
};

#ifdef ENABLE_WASM
EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<IncrementalRandom>("IncrementalRandom")
    .constructor()
    .function("getRandom", &IncrementalRandom::getRandom)
    ;
}
#endif

#ifndef ENABLE_WASM
int main()
{
    IncrementalRandom incrementalRandom =  IncrementalRandom();
    for(int i = 0; i < 10; ++i)
        std::cout << incrementalRandom.getRandom() << std::endl;
}
#endif