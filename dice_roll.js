var Module = require('./rand_gen_c.js');
function run(){
    var instance = new Module["IncrementalRandom"]();
    for (let i = 0; i < 10; i++)
    {
        console.log('instance[getRandom] result: ' + instance["getRandom"]());
    }
}

Module.onRuntimeInitialized = () => {
    run();
}

