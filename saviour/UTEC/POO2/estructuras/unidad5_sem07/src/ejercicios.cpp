//
// Author: marvin on 5/20/20.
//

#include "ejercicios.h"
#include "funciones.h"
#include "hash/hash_direct_address_table.h"
#include "hash/hash_chaining.h"

void ejercicio1() {
    cout<<"hashing"<<endl;
    client_hash_direct_address_table();
}

void ejercicio2() {
    my_hash myHash(7);
    myHash.insert(53);
    myHash.insert(7);
    myHash.insert(21);
    myHash.insert(58);
    myHash.insert(25);
    myHash.insert(24);
    myHash.insert(17);
    myHash.insert(56);
    myHash.insert(56);
    myHash.print();
    cout<<"search 25: "<<myHash.search(25)<<endl;
    myHash.delete_key(25);
    cout<<"search 25: "<<myHash.search(25)<<endl;
    myHash.print();

}

void ejercicio3() {
    int arr[] = {19, 12, 19, 12, 13, 13, 18};
    cout<<"count distinct elements: "<<count_distinct(arr, 7)<<endl;
    cout<<"count distinct elements: "<<count_distinct_optima(arr, 7)<<endl;
}

void ejercicio4() {
    cout<<"Quicksort"<<endl;
    /*
     *  Best          |     Average     |   Worst
     *  Omega(nlogn)      theta(nlogn)       O(n^2)
     */

    cout<<"Mergesort"<<endl;
    /*
 *  Best          |     Average     |   Worst
 *  Omega(nlogn)      theta(nlogn)       O(nlogn)

     1.- Divide and conquer
     2.- Stable
     3.- theta(nlogn) time, O(n) space
 */
    int arr[] = {10, 5, 30, 15, 7};
    print(arr, 5);
    merge_sort(arr, 0, 4);
    print(arr, 5);
}

void ejercicio5() {
    Node* root = new Node(10);
    root->left = new Node(20);

    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    /*
     *                     10
     *                   /   \
     *                  20    30
     *                       /  \
     *                      40  50
     *
     *            inorder:       20 10 40 30 50
     *            preorder:      10 20 30 40 50
     *            postorder:     20 40 50 30 10
     */
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);

}

void ejercicio6() {
    cout<<"Calculate the median of a sequence"<<endl;
    /*
     * int arr[] = {25, 7, 10, 15,  20}
     *              25 16  10  12.5  15
     *
     *
     * Mantener un tmp (sorted)
     * tmp[] = |25|            -> size  = 1 -> 25
     * tmp[] = |7|25|          -> size = 2 -> 16
     * tmp[] = |7|10|25|       -> size = 3 -> 10
     * tmp[] = |7|10|15|25|    -> size = 4 -> 12.5
     * tmp[] = |7|10|15|20|25| -> size = 5 -> 15
     *
     * if (size%2 != 0)
     *    return tmp[size/2];
     * else
     *    return (tmp[size/2] + tmp[(size-1)/2])/2;
     *
     *
     *
     */
    int arr[] = {25, 7, 10, 15,  20};
    print_medians(arr, 5);
}

void ejercicio7() {
    cout<<"Heap Sort"<<endl;
    /*
     * int arr[] = {10, 15, 50, 4, 20}
     * int arr[] = {4, 10, 15, 20, 50}
     *
     */
    int arr[] = {10, 15, 50, 4, 20};
    print(arr, 5);
    heap_sort(arr, 5);
    print(arr, 5);
}

