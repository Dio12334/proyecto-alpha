//
// Author: marvin on 5/20/20.
//

#include "funciones.h"

/*
 * O(n^2) time
 * O(1) aux space
 */
int count_distinct(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] == arr[i]) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            res++;
        }
    }
    return res;
}

/*
 * O(n) time
 * O(n) aux space
 */
int count_distinct_optima(int arr[], int n) {
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
        us.insert(arr[i]);
    return us.size();
}

/*
 *  l <=  m < r
 *  O(n1+n2) = O(n) aux space
 */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

/*
 * O(nlogn) time
 *
 */
void merge_sort(int arr[], int l, int r) {
    if (l < r) { // como minimo tengo que tener dos elementos
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//----------------------------------------------
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

/*
 *            int arr[] = {...}
 *     |   12 15  53  |                  |  63   89  100   |
 */
void print_medians(int arr[], int n) {
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    s.push(arr[0]);
    cout<<arr[0]<<endl;
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        if (s.size() > g.size()) {
            if (s.top() > x) {
                g.push(s.top());
                s.pop();
                s.push(x);
            } else {
                g.push(x);
            }
            cout<<((s.top() + g.top())/2)<<endl;
        } else {
            if (x <= s.top()) {
                s.push(x);
            } else {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<endl;
        }
    }
}

/*
 *
 *
 *                       10(0)
 *                    /        \
 *                 20(1)       30(2)
 *                /   \         /
 *              40(3)  50(4)   60(6)
 *
 *
 *              |10|20|30|40|50|60|
 *                0  1  2  3  4  5
 *
 *                Child i:
 *                index = i
 *                left = 2*i+1
 *                right = 2*i + 2
 *                parent (i) = |_(i-1)/2_|
 *
 *                i = 1
 *                left(i) = 2*1+1 = 3
 *                right(i) = 2*1+2 = 4
 *
 *          {10, 15, 50, 4, 20}
 *           0   1   2   3   4
 *
 *                10(0)                          10(0)                                  50(0)
 *               /    \                         /    \                                 /    \
 *             15(1)  50(2)  -> heapify(1)->  20(1)  50(2)   -> heapify(0)  ->       20(1)  10(2)
 *           /    \                         /   \                                  /   \
 *         4(3)   20(4)                   4(3)  15(1)                            4(3)  15(1)
 *
 *
            {10, 15, 50, 4, 20}          |10|20|50|4|15|                          |50|20|10|4|15|
 *           0   1   2   3   4             0 1  2  3  4                             0  1  2 3  4
 *
 *
 */
void max_heapify(int arr[], int n, int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[largest], arr[i]);
        max_heapify(arr, n, largest);
    }
}

/*
 * Last node: n-1
 * parent(n-1)  = ((n-1)-1)/2 = (n-2)/2
 *
 */

void build_heap(int arr[], int n) {
    for (int i = ((n-2)/2); i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

/*
 *
 *
 *
 */


void heap_sort(int arr[], int n) {
    build_heap(arr, n);
    for (int i = n-1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}

/*
 *             50(0)
 *           /     \       swap(root[0], arr[4])
 *         20(1)   10(2)   -------------------->
 *       /     \           remover arr[4] from heap
 *      4(3)   15(4)
 *
 *      |50|20|10|4|15|
 *
 *
 *
 *            15(0)
 *          /      \           heapify(0)
 *        20(1)   10(2)      ---------->
 *      /
 *    4(3)
 *
 *           20(0)
 *          /     \
 *        15(1)   10(2)
 *       /
 *      4(3)
 *
 *
 *    |20|15|10|4|{50}|
 */
