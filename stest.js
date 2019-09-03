
class Stack {
    constructor() {
        this.stackArr = [];
        this.length = 0;
    }
    
    push(object) {
        this.stackArr.push(object);
        this.length++;
        return true;
    }
    
    pop() {
        this.length--;
        return this.stackArr.pop();
    }
    
    peek() {
        return this.stackArr[this.stackArr.length - 1];
    }
    
    empty() {
        return this.length == 0;
    }
    
    contains(object) {
        for(let i = this.stackArr.length - 1; i >= 0; i--)
        if(this.stackArr[i] == object)
            return true;
        return false;
    }
    
    size() {
        return this.length;
    }
}

module.exports = Stack;