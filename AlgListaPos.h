/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaPos.h
 * Author: Arnoldo
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
#include "pila.h"
using namespace std;


//typedef ListaPosDoEn<int> listaPos;
//typedef ListaPosDoEn<int>::Pos Position;


//typedef ListaPosSimEn<int> listaPos;
//typedef ListaPosSimEn<int>::Pos Position;

typedef ListaPosArr<int> listaPos;
typedef listaPos::Pos Position;


#ifndef ALGLISTAPOS_H
#define ALGLISTAPOS_H

class AlgListaPos {
public:
    
    AlgListaPos();
    
    AlgListaPos(const AlgListaPos& orig);
    
    virtual ~AlgListaPos();
    
    //EFE: Organiza la Lista según el algoritmo de burbuja;
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista
    void burbuja(listaPos listaPos1);
    
    //EFE: Organiza la Lista según el algoritmo de burbuja;
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista
    void burbujaBidireccional(listaPos listaPos1);
    
    //EFE: Devuelve verdadero si un elemento está en la lista
    //REQ: La Lista inicializada no vacía;
    //MOD: 
    bool buscar(listaPos listaPos, int elem);
    
    //EFE: Elimina los elementos repetidos en una lista 
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista.
    void eliminarRepetidos(listaPos listaPos1);
    
    //EFE: Elimina los elementos de la ListaPos1 que esten en la Lista listaPos2  
    //REQ: Las Listas inicializada no vacías, ordenadas y sin repetidos;
    //MOD: La Lista listaPos1.
    void eliminarElementosListaConOrden(listaPos listaPos1, listaPos listaPos2);
    
    //EFE: Elimina los elementos de la ListaPos1 que esten en la Lista listaPos2  
    //REQ: Las Listas inicializada no vacías y sin repetidos;
    //MOD: La Lista listaPos1.
    void eliminarElementosListaSinOrden(listaPos listaPos1, listaPos listaPos2);
    
    
    //EFE: Averigua si la Lista listaPos1 es igaul a la Lista listaPos2
    //REQ: Las Lista inicializadas y no vacías;
    //MOD: 
    bool iguales(listaPos listaPos1, listaPos listaPos2);
    
    //EFE: Organiza la Lista según el algoritmo de insercion;
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista
    void insercion(listaPos listaPos1);
    
    //EFE: Agrega a la Lista listaPos3 los elementos en la intersección de las Listas listaPos1 y listaPos2;
    //REQ: Las 3 Listas inicializadas no vacías y las listas listaPos1 y listaPos2 ordenadas y sin repetidos;
    //MOD: La Lista listaPos3;
    void interseccionConOrden(listaPos listaPos1, listaPos listaPos2, listaPos listaPos3);
    
    //EFE: Agrega a la Lista listaPos3 los elementos en la intersección de las Listas listaPos1 y listaPos2;
    //REQ: Las 3 Listas inicializadas no vacías y las listas listaPos1 y listaPos2 sin repetidos;
    //MOD: La Lista listaPos3;
    void interseccionSinOrden(listaPos listaPos1, listaPos listaPos2, listaPos listaPos3);
        
    //EFE: Invierte la Lista
    //REQ: La Lista inicializada y no vacía;
    //MOD: La Lista.
    void invertirLista(listaPos listaPos1);
    
    //EFE: Devuelve una sting con la Lista;
    //REQ: La Lista inicializada;
    //MOD: 
    string listar(listaPos listaPos1);
    
    //EFE: Organiza la Lista según el algoritmo de seleccción de manera Iterativa;
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista
    void selecccionIterativa(listaPos listaPos1);
    
    //EFE: Organiza la Lista según el algoritmo de seleccción de manera Recursiva usando al compilador;
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista
    void selecccionIterativaRecComp(listaPos listaPos1);
    
    void selecccionIterativaRecCompR(listaPos listaPos1,Position actual,int faltantes);
    
    //EFE: Organiza la Lista según el algoritmo de seleccción de manera Recursiva usando el modelo Pila;
    //REQ: La Lista inicializada no vacía;
    //MOD: La Lista
    void selecccionIterativaRecPila(listaPos listaPos1);    
    
    //EFE: Averigua si la Lista es simetrica
    //REQ: La Lista inicializada y no vacía;
    //MOD: 
    bool simetrica(listaPos listaPos1);
        
    //EFE: Averigua si la Lista listaPos1 está contenida en la Lista listaPos2
    //REQ: Las Listas inicializadas ;
    //MOD: La Lista.
    bool subLista(listaPos listaPos1,listaPos listaPos2);
    
    //EFE: Agrega a la Lista listaPos1 los elementos de la   la Lista listaPos2
    //REQ: Las Listas inicializadas, ordenadas, no vacías y sin elementos repetidos;
    //MOD: La Lista listaPos1.
    void unionConOrden(listaPos listaPos1,listaPos listaPos2);
    
    //EFE: Agrega a la Lista listaPos1 los elementos de la   la Lista listaPos2
    //REQ: Las Listas inicializadas, no vacías y sin elementos repetidos;
    //MOD: La Lista listaPos1.
    void unionSinOrden(listaPos listaPos1,listaPos listaPos2);
    
private:
    
};    
    
    

#endif /* ALGLISTAPOS_H */



