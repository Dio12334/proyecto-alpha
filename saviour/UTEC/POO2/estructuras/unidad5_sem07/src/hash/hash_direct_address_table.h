//
// Author: marvin on 5/20/20.
//

#ifndef HASH_DIRECT_ADDRESS_TABLE_H
#define HASH_DIRECT_ADDRESS_TABLE_H

/*
 * 0-999
 * insert()
 * search()   -> O(1)
 * delete()
 */

int table[1000];
void insert(int x) {
    table[x] = 1;
}

bool search(int x) {
    return table[x] == 1 ? 1: 0;
}

void delete_element(int x) {
    table[x] = 0;
}

/*
 * |0| | ||||||||| 0 |
 *  0 1 2         999
 */
void client_hash_direct_address_table() {
    for (int i = 0; i < 1000; i++) {
        table[i] = 0;
    }

    cout<<"pos 10: "<<table[10]<<endl;
    insert(10);
    cout<<"pos 10: "<<table[10]<<endl;
    insert(20);
    insert(100);
    cout<<"search 20: "<<search(20)<<endl;
    cout<<"search 100: "<<search(100)<<endl;
    delete_element(100);
    cout<<"search 100: "<<search(100)<<endl;

    /*
     * Hashing:  Numeros telefonicos, nombres, numeros empleados, numeros de alumnos, xxxxxxx
     *
     *  Universo de keys ->  hash function ->  hash table
     *                                         0 <=  __  <= m-1
     *
     * 1)   h(key_muy_grande) = key_muy_grande%m
     * 2)   h(str)
     *      str = "utec";
     *      (str[0]*x + str[1]*x^1 + str[2]*x^2 + str[3]x^3)%m
     *
     *
     *
     *
     *
     *
     *
     */





}



#endif //HASH_DIRECT_ADDRESS_TABLE_H
