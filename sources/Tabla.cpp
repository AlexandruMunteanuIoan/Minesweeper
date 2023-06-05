#include <iostream>
#include <vector>
#include <random>
#include "Tabla.h"
#include "Celula.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define GRAY    "\033[90m"
#define BLUE    "\033[34m"
#define BLACK   "\033[30m"
#define WHITE   "\033[37m"
#define BROWN   "\033[33m"

using namespace std;


Tabla::Tabla(int dim, int nr)
{
    celule.resize(dim, vector<Celula>(dim));
    BOARD_SIZE = dim;
    NUM_MINE = dim * nr;
}

void Tabla::generareMine()
{
    int numMine = 0;
    while (numMine < NUM_MINE)
    {
        int lin = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (!celule[lin][col].esteMine())
        {
            celule[lin][col].setMine();
            numMine++;
        }
    }
}

void Tabla::generareNumere()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (celule[i][j].esteMine())
            {
                continue;
            }
            int numMine = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int newLin = i + k;
                    int newCol = j + l;
                    if (newLin >= 0 && newLin < BOARD_SIZE &&
                            newCol >= 0 && newCol < BOARD_SIZE &&
                            celule[newLin][newCol].esteMine())
                    {
                        numMine++;
                    }
                }
            }
            celule[i][j].seNumMineAlaturate(numMine);
        }
    }
}

bool Tabla::gameOver() const
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (celule[i][j].esteMine() && celule[i][j].isShow())
            {
                return true;
            }
        }
    }
    return false;
}

bool Tabla::win() const
{
    int numHide = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (!celule[i][j].isShow())
            {
                numHide++;
            }
        }
    }
    return numHide == NUM_MINE;
}

void Tabla::show(int lin, int col)
{
    if (lin < 0 || lin >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        return;
    }
    if (celule[lin][col].isShow())
    {
        return;
    }
    celule[lin][col].setShow();
    if (celule[lin][col].esteMine())
    {
        return;
    }
    if (celule[lin][col].getNumMineAlaturate() == 0)
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                show(lin + i, col + j);
            }
        }
    }
}
void Tabla::afisare() const
{
    cout<<"   ";
    for (int k = 0; k < BOARD_SIZE; k++)
        if(k<10)
            cout <<" "<< k<<" ";
        else
            cout <<" "<< k;
    cout << "" << endl<<endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if(i<10)
            cout << i << "   ";
        else
            cout << i << "  ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (!celule[i][j].isShow())
            {
                    cout << GRAY << "? " << RESET;

            }
            else if (celule[i][j].esteMine())
            {
                    cout << BROWN << "X " << RESET;
            }
            else
            {
            	if(celule[i][j].getNumMineAlaturate() == 1 || celule[i][j].getNumMineAlaturate() == 0)
                    cout << BLUE << celule[i][j].getNumMineAlaturate()<<" " << RESET;
                else if(celule[i][j].getNumMineAlaturate() == 2)
                    cout << GREEN << celule[i][j].getNumMineAlaturate()<<" " << RESET;
                else
                    cout << RED << celule[i][j].getNumMineAlaturate()<<" " << RESET;
            }
            cout << " ";
        }
        cout << endl;
    }
    cout<<endl;
}
