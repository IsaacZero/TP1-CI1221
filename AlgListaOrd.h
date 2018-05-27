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

#include <fstream>
#include <iostream>
#include <string>
#include "pila.h"

using namespace std;

#include "listaOrdArr.h"
//#include "ListaOrdEn.h"

typedef ListaOrdArr<int> listaOrd;
//typedef ListaOrdEn<int> listaOrd;

#ifndef ALGLISTAORD_H
#define ALGLISTAORD_H

class AlgListaOrd {
public:
    AlgListaOrd();
    AlgListaOrd(const AlgListaOrd& orig);
    virtual ~AlgListaOrd();
    
    //EFE: Averigua si L1 es igual a L2 y devuelve true si lo son y false en caso contrario.
    //REQ: L1 y L2 inicializadas.
    //MOD:
    bool iguales(listaOrd l1, listaOrd l2);
    
    //EFE: Hace a L2 igual a L1.
    //REQ: L1 y L2 inicializados.
    //MOD: La lista L2.
    void copiar(listaOrd l1, listaOrd &l2);
    
    //EFE: Retorna true si todos los elementos en L1 estan en L2 y false en caso contrario.
    //REQ: L1 y L2 inicializadas.
    //MOD: 
    bool contenida(listaOrd l1, listaOrd l2);
    
    //EFE: Retorna true si el elemento pertene a la Lista y false en caso contrario.
    //REQ: L inicializada.
    //MOD:
    bool pertene(int elemento, listaOrd l);
    
    //EFE: Elimina de L1 los elementos que estan en L2.
    //REQ: L1 y L2 inicializada.
    //MOD: La Lista L1.
    void eliminarElemRep(listaOrd &l1, listaOrd l2);
    
    //EFE: Le agrega a L1 los elementos de L2.
    //REQ: L1 y L2 inicializados.
    //MOD: La lista L1.
    void unionPrim(listaOrd &l1, listaOrd l2);
    
    //EFE: Crea una lista L3 donde se agregan los elementos diferentes de L1 y L2.
    //REQ: L1 y L2 incializada.
    //MOD: La Lista L3.
    listaOrd unionSeg(listaOrd l1, listaOrd l2);
    
    //EFE: Crea una lista L3 donde se agregar los elementos que estan tanto en L1 como en L2. Usa el algoritmo
    //Pertene() para saber si se encuentran en la lista los elementos.
    //REQ: L1 y L2 inicializada.
    //MOD: La Lista L3.
    listaOrd interseccionPrim(listaOrd l1, listaOrd l2);
    
    //EFE: Crea una lista L3 donde se agregar los elementos que estan tanto en L1 como en L2. El algoritmo se mueve
    //simultaneamente entre ambas listas.
    //REQ: L1 y L2 inicializada.
    //MOD: La Lista L3.
    listaOrd interseccionSeg(listaOrd l1, listaOrd l2);
    
    //EFE: Llena la lista con los numeros en el archivo, los números deben estar separados por espacio solamente.
    // Por ejemplo, al abrir el archivo .txt debe estar escrita la lista 2 4 6 8 si se quiere la lista {2,4,6,8}.
    // Se agregaran por el final de la lista los números.
    //REQ: Archivo valido en la carpeta del proyecto.
    //MOD: La lista
    void llenarLista(ifstream& archivo, listaOrd &l);
    
private:

};

#endif /* ALGLISTAORD_H */

