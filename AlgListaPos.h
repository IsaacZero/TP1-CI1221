/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaPos.h
 * Author: Isaac
 *
 * Created on 19 de mayo de 2018, 08:35 PM
 */
#include "pila.h"

//#include "ListaPosDoEn.h"
//#include "ListaPosSimEn.h"
#include "ListaPosArr.h"

//typedef ListaPosDoEn<int> Lista;
//typedef ListaPosDoEn<int>::Pos Position;

//typedef ListaPosSimEn<int> Lista;
//typedef ListaPosSimEn<int>::Pos Position;

typedef ListaPosArr<int> Lista;
typedef ListaPosArr<int>::Pos Position;

#ifndef ALGLISTAPOS_H
#define ALGLISTAPOS_H

class AlgListaPos {
public:
    AlgListaPos();
    AlgListaPos(const AlgListaPos& orig);
    virtual ~AlgListaPos();
private:

};

#endif /* ALGLISTAPOS_H */

