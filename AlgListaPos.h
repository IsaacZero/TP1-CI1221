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
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "pila.h"

//#include "ListaPosDoEn.h"
//#include "ListaPosSimEn.h"
#include "ListaPosArr.h"
using namespace std;

//typedef int Elemento;
//typedef ListaPosDoEn<Elemento> Lista;
//typedef ListaPosDoEn<Elemento>::Pos Position;

//typedef int Elemento;
//typedef ListaPosSimEn<Elemento> Lista;
//typedef ListaPosSimEn<Elemento>::Pos Position;

typedef int Elemento;
typedef ListaPosArr<Elemento> Lista;
typedef Lista::Pos Position;

#ifndef ALGLISTAPOS_H
#define ALGLISTAPOS_H

class AlgListaPos {
public:
    
    AlgListaPos();
    
    AlgListaPos(const AlgListaPos& orig);
    
    virtual ~AlgListaPos();
    
    //EFE: Devuelve verdadero si un elemento está en la lista
    //REQ: La Lista inicializada;
    //MOD: La Lista.
    bool buscar(Lista listaPos, Elemento elem);
    
    //EFE: Elimina los elementos repetidos en una lista 
    //REQ: La Lista inicializada;
    //MOD: La Lista.
    void eliminarRepetidos(Lista listaPos);
    
    //EFE: Invierte la Lista
    //REQ: La Lista inicializada y no vacía;
    //MOD: La Lista.
    void invertir(Lista listaPos);
    
    //EFE: Devuelve una sting con la Lista;
    //REQ: La Lista inicializada;
    //MOD: La Lista.
    string listar(Lista listaPos);
    
    //EFE: Averigua si la Lista es simetrica
    //REQ: La Lista inicializada y no vacía;
    //MOD: La Lista.
    bool simetrica(Lista listaPos);
    
    //EFE: Averigua si la Lista listaPos1 está contenida en la Lista listaPos2
    //REQ: La Lista inicializada y no vacía;
    //MOD: La Lista.
    bool subLista(Lista listaPos1,Lista listaPos2);
    
private:
    
};    
    
    

#endif /* ALGLISTAPOS_H */

