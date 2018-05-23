/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaIndex.h
 * Author: Isaac
 *
 * Created on 19 de mayo de 2018, 08:35 PM
 */

#include <fstream>
#include <iostream>
#include <string>
#include "pila.h"

using namespace std;

#include "ListaIndArr.h"
//#include "listaIndEn.h"

typedef ListaIndArr<int> Lista;
//typedef ListaIndEn<int> Lista;

#ifndef ALGLISTAINDEX_H
#define ALGLISTAINDEX_H

class AlgListaIndex {
public:
    AlgListaIndex();
    AlgListaIndex(const AlgListaIndex& orig);
    virtual ~AlgListaIndex();
    
    //EFE:
    //REQ:
    //MOD:
    string listar(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    bool simetrica(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void invertir(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    bool buscar(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void eliminarRep(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    bool sublista(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    bool iguales(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    void burbujaOri(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void burbujaBi(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void seleccionIter(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void seleccionRec(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void insercion(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void quickSortAho(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void quickSortDos(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void mergeSort(Lista l);
    
    //EFE:
    //REQ:
    //MOD:
    void unionUno(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    void unionDos(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    Lista interseccionUno(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    Lista interseccionDos(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    void eliminarUno(Lista l1, Lista l2);
    
    //EFE:
    //REQ:
    //MOD:
    void eliminarDos(Lista l1, Lista l2);
private:

};

#endif /* ALGLISTAINDEX_H */

