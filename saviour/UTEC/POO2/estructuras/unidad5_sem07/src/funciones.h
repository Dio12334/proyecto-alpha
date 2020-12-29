//
// Author: marvin on 5/20/20.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "lib.h"
#include "tree/tree.h"

int count_distinct(int arr[], int n);

int count_distinct_optima(int arr[], int n);

void merge_sort(int arr[], int l, int r);

void print(int arr[], int n);


void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

void print_medians(int arr[], int n);


void build_heap(int arr[], int n);

void heap_sort(int arr[], int n);


#endif //FUNCIONES_H
