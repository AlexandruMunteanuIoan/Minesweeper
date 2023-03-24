#ifndef CELULA_H // include guard
#define CELULA_H
#include <bits/stdc++.h>

class Celula
{
private:
    bool mine;
    bool show;
    int numMineAlaturate;
public:
    Celula();

    bool esteMine() const;

    bool isShow() const;

    int getNumMineAlaturate() const;

    void setMine();

    void setShow();

    void seNumMineAlaturate(int );
};

#endif /* MY_CLASS_H */
