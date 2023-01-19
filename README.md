# Prerequisites
* Emscripten: https://emscripten.org/docs/getting_started/downloads.html
* NodeJS: https://nodejs.org/en/download/
* Python3: https://www.python.org/downloads/

# Steps
* Set up emscripten (see prerequisites) and make sure the compiler is present: `which emcc`
* Compile `rand_gen.cpp` to WASM (one of the following options):
  1. Bare metal: `emcc -lembind -DENABLE_WASM -o rand_gen_c.js rand_gen.cpp`.
  2. Docker compilation: `docker run --rm -v $(pwd):/src -u $(id -u):$(id -g) emscripten/emsdk emcc -lembind -DENABLE_WASM -o rand_gen_c.js rand_gen.cpp`

  This should generate `gen_rand_c.wasm`
  file with WebAssembly code and `gen_rand_c.js` with JS "glue" code.
* `dice_roll.js` imports the glue code which instantiates WASM module and runs a function compiled to WASM from C++: `node dice_roll.js`
* `test.html` also runs this function but in the web environment, emulating a frontend environment:
`python3 -m http.server`, then open browser at `http://localhost:8000/test.html`. In console (ctrl+shift+c) the random number generation is visible (try refreshing for random testing)