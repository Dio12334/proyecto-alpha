//
// Created by Jorge Luis Vasquez on 21/07/2020.
//

#ifndef PROYECTOFINAL_FUNCIONES_H
#define PROYECTOFINAL_FUNCIONES_H

#include "types.h"
#include "database.h"

void initDataBase(Database &db);

string smartIA(Database &db );

void updateDataBase(int row,int col, int result,Database &db);

void printBoard(Database &db);

vector<Cord> cordsofShipDirection(int direction,Database &db,int row,int col);

template <typename T>
void print_table(T grid,int row , int col);


#endif //PROYECTOFINAL_FUNCIONES_H
