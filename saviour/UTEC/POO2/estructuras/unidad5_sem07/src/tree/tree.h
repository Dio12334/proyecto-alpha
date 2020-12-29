//
// Author: marvin on 5/20/20.
//

#ifndef TREE_H
#define TREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};


#endif //TREE_H
