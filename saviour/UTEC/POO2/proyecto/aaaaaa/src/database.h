//
// Created by Jorge Luis Vasquez on 21/07/2020.
//

#ifndef PROYECTOFINAL_DATABASE_H
#define PROYECTOFINAL_DATABASE_H

#define RANDOM  1
#define SEARCH  2
#define DESTROY 3

#define NONE    0
#define NORTH   1
#define SOUTH   2
#define EAST    3
#define WEST    4


#define FAILED  1
#define DAMAGED 2
#define DESTROYED 3
#define GAMEOVER 4
#define WINNER 5

const   char  HIT_MARKER = 'H';
const   char  MISS_MARKER = '*';
const   char  SUNK_MARKER = 'X';
const   char  EMPTY_MARKER = ' ';

// constanst of ships
const   int   AC = 1;
const   int   B1 = 2;
const   int   B2 = 3;
const   int   S1 = 4;
const   int   S2 = 5;
const   int   S3 = 6;
const   int   T1 = 7;
const   int   T2 = 8;
const   int   T3 = 9;
const   int   T4 = 10;

// ship sizes
const   int   AC_SIZE = 4;
const   int   B1_SIZE = 3;
const   int   B2_SIZE = 3;
const   int   S1_SIZE = 2;
const   int   S2_SIZE = 2;
const   int   S3_SIZE = 2;
const   int   T1_SIZE = 1;
const   int   T2_SIZE = 1;
const   int   T3_SIZE = 1;
const   int   T4_SIZE = 1;

const int BOARDSIZE=10;

struct Cord{
    int x;
    int y;
    Cord(int x, int y){
        this->x=x;
        this->y=y;
    }
};


struct Database{

    int  hitRow, hitCol;
    int  hitShip;
    int  fireDir;
    int  fireDist;
    int  lastResult;
    int  mode;
    char grid[BOARDSIZE][BOARDSIZE];
    stack<Cord> _encontrados;

    int  depth;
    int  hitRows[10], hitCols[10];
    int  hitShips[10];
    int  fireDirs[10];
    int  fireDists[10];
    int  lastResults[10];
    int  modes[10];
    char symbols[10];
    int sizes[10];



    //0 si no esta encontrado, 1 si es encontrado

};



#endif //PROYECTOFINAL_DATABASE_H
