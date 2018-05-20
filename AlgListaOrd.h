/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaOrd.h
 * Author: Isaac
 *
 * Created on 19 de mayo de 2018, 08:36 PM
 */

#include "pila.h"

//#include "listaOrdArr.h"
#include "ListaOrdEn.h"

//typedef ListaOrdArr<int> Lista;
typedef ListaOrdEn<int> Lista;

#ifndef ALGLISTAORD_H
#define ALGLISTAORD_H

class AlgListaOrd {
public:
    AlgListaOrd();
    AlgListaOrd(const AlgListaOrd& orig);
    virtual ~AlgListaOrd();
private:

};

#endif /* ALGLISTAORD_H */

