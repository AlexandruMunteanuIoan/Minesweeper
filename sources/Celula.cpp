#include <iostream>
#include <vector>
#include <random>
#include "Celula.h"

using namespace std;

Celula::Celula()
    {
        mine = false;
        show = false;
        numMineAlaturate = 0;
    }

bool Celula::esteMine() const
    {
        return mine;
    }

bool Celula::isShow() const
    {
        return show;
    }

int Celula::getNumMineAlaturate() const
    {
        return numMineAlaturate;
    }

void Celula::setMine()
    {
        mine = true;
    }

void Celula::setShow()
    {
        show = true;
    }

void Celula::seNumMineAlaturate(int num)
    {
        numMineAlaturate = num;
    }
