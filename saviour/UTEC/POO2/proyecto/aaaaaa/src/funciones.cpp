//
// Created by Jorge Luis Vasquez on 21/07/2020.
//

#include "funciones.h"



void initDataBase(Database &db){
    db.mode = RANDOM;


    for (int i = 0; i < 10; i++) {
        db.hitRows[i] = 0;
        db.hitCols[i] = 0;
        db.hitShips[i] = 0;
        db.fireDirs[i] = 0;
        db.modes[i] = 0;
    }

    for (int i = 0; i < BOARDSIZE; i++) {
        for (int j = 0; j < BOARDSIZE; j++) {
            db.grid[i][j] = EMPTY_MARKER;
        }
    }
}

string smartIA( Database &db ){
    int nextRow;
    int nextCol;
    string nextMove = "";

    if (db.mode == RANDOM) {

        /********** mapa probabilidad **********/
        int shipSize;
        int probabilityDensity[BOARDSIZE][BOARDSIZE];
        for (int i = 0; i < BOARDSIZE; i++) {
            for (int j = 0; j < BOARDSIZE; j++) {
                probabilityDensity[i][j] = 0;
            }
        }

        /********** CALCULATE PROBABILITY DENSITY **********/
        for (int h = 0; h < 10; h++) {
            if (db.modes[h] == 0) {

                if (h + 1 == AC) { shipSize = AC_SIZE; }
                if (h + 1 == B1) { shipSize = B1_SIZE; }
                if (h + 1 == B2) { shipSize = B2_SIZE; }
                if (h + 1 == S1) { shipSize = S1_SIZE; }
                if (h + 1 == S2) { shipSize = S2_SIZE; }
                if (h + 1 == S3) { shipSize = S3_SIZE; }
                if (h + 1 == T1) { shipSize = T1_SIZE; }
                if (h + 1 == T2) { shipSize = T2_SIZE; }
                if (h + 1 == T3) { shipSize = T3_SIZE; }
                if (h + 1 == T4) { shipSize = T4_SIZE; }

                for (int i = 0; i < BOARDSIZE; i++) {
                    for (int j = 0; j < BOARDSIZE; j++) {
                        for (int k = 0; k < shipSize; k++) {
                            for (int l = 0; l < shipSize; l++) {
                                if (db.grid[i - k + l][j] == EMPTY_MARKER &&
                                    i - k + l < BOARDSIZE && i - k + l >= 0) {
                                    if (l + 1 == shipSize) {
                                        probabilityDensity[i][j] = probabilityDensity[i][j] + shipSize*shipSize;
                                    }
                                }
                                else {
                                    break;
                                }
                            }
                        }
                        for (int k = 0; k < shipSize; k++) {
                            for (int l = 0; l < shipSize; l++) {
                                if (db.grid[i][j - k + l] == EMPTY_MARKER &&
                                    j - k + l < BOARDSIZE && j - k + l >= 0) {
                                    if (l + 1 == shipSize) {
                                        probabilityDensity[i][j] = probabilityDensity[i][j] + shipSize*shipSize;
                                    }
                                }
                                else {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        /********** mayor celda de probabilidad **********/
        int highestProbability = 0;
        for (int i = 0; i < BOARDSIZE; i++) {
            for (int j = 0; j < BOARDSIZE; j++) {
                if (probabilityDensity[i][j] > highestProbability) {
                    highestProbability = probabilityDensity[i][j];
                    nextRow = i;
                    nextCol = j;
                }
            }
        }
        print_table(probabilityDensity,BOARDSIZE,BOARDSIZE);

    }

    if (db.mode == SEARCH) {
        int hitRow;
        int hitCol;
        Cord c=db._encontrados.top();
        nextCol=c.y;
        nextRow=c.x;
        db._encontrados.pop();
    }


    /***** formato del siguiente movimiento *****/
    nextMove = nextMove + (char)('A' + nextCol);
    if (nextRow == 9) {
        nextMove = nextMove + "10";
    }
    else {
        nextMove = nextMove + (char)('1' + nextRow);
    }
    cout<<"Next Row:"<<nextRow<<endl;
    cout<<"Nex Colum:"<<nextCol<<endl;
    return nextMove;

}

void updateDataBase(int row,int col, int result,Database &db) {

    if (result == FAILED) {
        db.grid[row][col] = MISS_MARKER;
        if( !db._encontrados.empty()){
            db.mode=SEARCH;
        }else{
            db.mode=RANDOM;
        }
    }
    if (result == DAMAGED) {

        db.grid[row][col] = HIT_MARKER;
        db.hitRow = row;
        db.hitCol = col;
        db.mode = SEARCH;

        //norte
        if(row-1>=0 && db.grid[row-1][col]==EMPTY_MARKER){
            db._encontrados.push(Cord(row-1,col));
        }
        //sur
        if(row+1<BOARDSIZE && db.grid[row+1][col]==EMPTY_MARKER){
            db._encontrados.push(Cord(row+1,col));
        }
        //este
        if(col-1>=0 && db.grid[row][col-1]==EMPTY_MARKER){
            db._encontrados.push(Cord(row,col-1));
        }
        //oeste
        if(col+1<BOARDSIZE && db.grid[row][col+1]==EMPTY_MARKER){
            db._encontrados.push(Cord(row,col+1));
        }
    }
    if (result == DESTROY) {

        //NORTH   1
        //SOUTH   2
        //EAST    3
        //WEST    4
        db.grid[row][col] = SUNK_MARKER;
        int shipSize;
        char shipMarker;
        bool encontro=false;
        for(int i=1; i<=4;i++) {
            vector<Cord> _econtradas = cordsofShipDirection(i, db, row, col);
            if (_econtradas.size() > 0) {
                for (int h = 0; h <= 5; h++) {
                    if (db.modes[h] == 0) {

                        if (h + 1 == AC) { shipSize = AC_SIZE; }
                        if (h + 1 == B1) { shipSize = B1_SIZE; }
                        if (h + 1 == B2) { shipSize = B2_SIZE; }
                        if (h + 1 == S1) { shipSize = S1_SIZE; }
                        if (h + 1 == S2) { shipSize = S2_SIZE; }
                        if (h + 1 == S3) { shipSize = S3_SIZE; }

                        if (shipSize == _econtradas.size() + 1) {
                            for (int i=0; i<_econtradas.size(); i++) {
                                Cord o = _econtradas[i];
                                db.grid[o.x][o.y] = SUNK_MARKER;
                                db.modes[h] = 1;
                            }
                            encontro= true;
                            break;
                        }
                    }
                }
            }
        }

        if(!encontro){
            for(int h=6;h<10;h++){
                if (db.modes[h] == 0) {
                    db.modes[h]=1;
                    break;
                }
            }
        }
        if( !db._encontrados.empty()){
            db.mode=SEARCH;
        }else{
            db.mode=RANDOM;
        }
    }
}

void printBoard(Database &db){
    //for (int i=0; i<100; i++) cout << "\n";
    cout << "\nYour own board:";
    cout << "\n  ";
    for (int i=0; i<BOARDSIZE; i++)
        cout << i+1;
    cout << "\n";
    for (int i=0; i<BOARDSIZE; i++) {
        if (i+1 < 10) cout << i+1 << " ";
        else cout << i+1;
        for (int q=0; q<BOARDSIZE; q++) {
            cout << db.grid[i][q];
        }
        cout << endl;
    }
}


vector<Cord> cordsofShipDirection(int direction, Database &db,int row, int col){
    vector<Cord> encontradas;
    bool condition;
    int k=1;
    int new_row;
    int new_col;

    if(direction==NORTH){
        condition=(row-k>=0 && db.grid[row-k][col]==HIT_MARKER);
        new_row=row-k;
        new_col=col;
    }
    //SOUTH
    if(direction==SOUTH){
        condition=(row+k<BOARDSIZE && db.grid[row+k][col]==HIT_MARKER);
        new_row=row+k;
        new_col=col;
    }
    //EAST
    if(direction==EAST ){
        condition=(col-k>=0 && db.grid[row][col-k]==HIT_MARKER);
        new_row=row;
        new_col=col-k;
    }
    //WEST
    if(direction==WEST){
        condition=(col+k<BOARDSIZE && db.grid[row][col+k]==HIT_MARKER);
        new_row=row;
        new_col=col+k;
    }

    while(condition){
        encontradas.push_back(Cord(new_row,new_col));
        k++;
        if(direction==NORTH){
            condition=(row-k>=0 && db.grid[row-k][col]==HIT_MARKER);
            new_row=row-k;
            new_col=col;
        }
        //SOUTH
        if(direction==SOUTH){
            condition=(row+k<BOARDSIZE && db.grid[row+k][col]==HIT_MARKER);
            new_row=row+k;
            new_col=col;
        }
        //EAST
        if(direction==EAST ){
            condition=(col-k>=0 && db.grid[row][col-k]==HIT_MARKER);
            new_row=row;
            new_col=col-k;
        }
        //WEST
        if(direction==WEST){
            condition=(col+k<BOARDSIZE && db.grid[row][col+k]==HIT_MARKER);
            new_row=row;
            new_col=col+k;
        }
    }

    return encontradas;
}


template <typename T>
void print_table(T grid,int row , int col){

    cout << "\nYour own board:";
    cout << "\n  ";
    for (int i=0; i<col; i++)
        cout << i+1;
    cout << "\n";
    for (int i=0; i<row; i++) {
        if (i+1 < 10) cout << i+1 << " ";
        else cout << i+1;
        for (int q=0; q<col; q++) {
            cout << grid[i][q];
        }
        cout << endl;
    }

}
