#ifndef TABLA_H // include guard
#define TABLA_H
#include <iostream>
#include <vector>
#include "Celula.h"

using namespace std;

class Tabla
{
private:
    vector<vector<Celula>> celule;
    int BOARD_SIZE ;
    int NUM_MINE;
public:
    Tabla(int);
    void generareMine();
    void generareNumere();
    bool gameOver() const;
    bool win() const;
    void show(int , int );
    void afisare() const;
};

#endif /* MY_CLASS_H */
