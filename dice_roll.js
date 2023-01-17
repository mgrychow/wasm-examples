var Module = require('./rand_gen_c.js');
function run(){
    console.log('getRandom result: ' + Module.__Z9getRandomv());
}

Module.onRuntimeInitialized = () => {
    run()
}

