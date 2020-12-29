//
// Author: marvin on 5/20/20.
//

#ifndef HASH_CHAINING_H
#define HASH_CHAINING_H

#include "../lib.h"

struct my_hash {
    int BUCKET;
    list<int> *table;
    my_hash(int b) {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }
    int hash(int key) {
        return key%BUCKET;
    }

    bool search(int key) {
        int i = hash(key);
        for (auto x : table[i]) {
            if (x == key)
                return true;
        }
        return false;
    }

    void insert(int key) {
        int i = hash(key);
        table[i].push_back(key);
    }

    void delete_key(int key) {
        int i = hash(key);
        table[i].remove(key);
    }

    void print() {
        for (int i = 0; i < BUCKET; i++) {
            list<int> l = table[i];
            cout<<i<<" : ";
            for (auto x : l)
                cout<<x<<" -> ";
            cout<<endl;
        }
        cout<<endl;
    }


};



#endif //HASH_CHAINING_H
