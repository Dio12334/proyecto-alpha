//
// Author: marvin on 5/13/20.
//

#include "ejercicios.h"
#include "templates/dynamic/client_dynamic.cpp"
#include "templates/static/client_static.cpp"
#include "funciones.h"
#include "funciones.cpp"

void ejercicio1() {
    cout<<"Dynamic Poly"<<endl;
    Circulo c1, c2, c3;
    Line l1;

    my_draw(c1);
    cout<<"distancia: "<<distance(l1, c1)<<endl;

    vector<GeoObj*> collection;
    collection.push_back(&l1);
    collection.push_back(&c1);
    draw_elems(collection);

    cout<<"Static Poly"<<endl;
    LineSt ls;
    Circulo cs1, cs2;

    cout<<"distancia: "<<distance_static(ls, cs2)<<endl;

    draw_static(ls);
}

void ejercicio2() {
    auto a_int = absolute(-5);
    cout<<"a_int = "<<a_int<<endl;

    auto a_dou = absolute(-7.2);
    cout<<"a_double = "<<a_dou<<endl;

    auto a_long = absolute(-151651651651.3215);
    cout<<"a_long = "<<a_long<<endl;
}
void ejercicio3() {
    deque<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    auto res = split_range(v1, 3);
    for (const auto& row : res) {
        for (const auto&item : row)
            cout<<item<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void ejercicio4() {
    list<int> v1 = {1, 2, 3, 4, 5};
    list<int> v2 = {10, 20};
    auto v3 = suma_rango(v1, v2);
    for (auto const&x : v3)
        cout<<x<<" ";
    cout<<endl;
}

void ejercicio5() {
    vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 7, 5};
    auto v3 = delete_items(v1, 1);
    for (auto const&x : v3)
        cout<<x<<" ";
    cout<<endl;
}
