let StackNum = require('./LinkedStack');
let StackArr = require('./Stack')
let Stack = require('./stest');
var iterations = 1000000;
StackNum.onRuntimeInitialized = _ => {
    let s1 = new StackNum.Stack();
    console.time('Function C++ Linked Stack');
    for(let i = 0; i < iterations; i++ ){
        s1.push(i);
    };
    console.timeEnd('Function C++ Linked Stack')
  
    let s2 = new StackArr.Stack(iterations);
    console.time('Function C++ Stack Arr');
    for(let i = 0; i < iterations; i++ ){
        s2.push(i);
    };
    console.timeEnd('Function C++ Stack Arr')

    let s3 = new Stack();
    console.time('Function JS');
    for(let i = 0; i < iterations; i++ ){
        s3.push(i);
    };
    console.timeEnd('Function JS')
}