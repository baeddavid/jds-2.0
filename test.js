class sLink {
    constructor(object) {
        this.object = object;
        // next pointer default is null
        this.next = null;
        // prev pointer default is null
    }
}
const helper = Symbol('helper');

class sLinkedList {
    constructor() {
        this.head = null;
        this.length = 0;
    }

    add(object) {
        let newLink = new sLink(object);
        newLink.next = this.head;
        this.head = newLink;
        this.length++;
        return true;
    }

    removeFirst() {
        let temp = this.head;
        this.head = this.head.next;
        this.length--;
        return temp;
    }

    removeKey(key) {
        let current = this.head;
        let prev = this.head;
        while(current.object != key) {
            if(current.next == null)
                return false;
            prev = current; 
            current = current.next;
        }
        if(current == this.head)
            this.head = this.head.next;
        else
            prev.next = current.next;
        this.length--;
        return current;
    }

    search(key) {
        return this[helper](this.head, key);
    }   

    contains(key) {
        let current = this.head;
        while(current.object != key) {
            current = current.next;
            if(current == null)
                return false;
        }
        return true;
    }

    get(index) {
        let current = this.head;
        let i = 0;
        while(i < index && current != null) {
            current = current.next;
            if(current == null)
                return false;
            i++;
        }
        return current;
    }

    indexOf(key) {
        let current = this.head, index = 0;
        while(current.object != key && current != null) {
            current = current.next;
            index++;
            if(current == null)
                return -1;
        }
        return index;
    }

    lastIndexOf(key) {
        let current = this.tail, index = this.length - 1;
        while(current.object != key && current != null) {
            current = current.prev;
            index--;
            if(current == null)
                return -1;
        }
        return index;
    }

    set(index, key) {
        let current = this.get(index);
        current.object = key;
        return true;
    }

    peekHead() {
        return this.head;
    }

    toArray() {
        let array = [];
        let current = this.head;
        while(current != null) {
            array.push(current.object);
            current = current.next;
        }
        return array;
    }

    copy() {
        let shallowList = this;
        return shallowList;
    }

    deepCopy() {
        let copyList = new LinkedList();
        let current = this.head;
        while(current != null) {
            copyList.add(current.object);
            current = current.next;
        }
        return copyList;
    }

    isEmpty() {
        return this.length == 0;
    }

    size() {
        return this.length;
    }

    [helper](node, key) {
        if(node == null)
            return false;
        if(node.object == key)
            return node;
        return this[helper](node.next , key);
    }
}

module.exports = sLinkedList;