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

typedef Pila<int> pila;

#ifndef ALGLISTAINDEX_H
#define ALGLISTAINDEX_H

class AlgListaIndex {
public:
    AlgListaIndex();
    AlgListaIndex(const AlgListaIndex& orig);
    virtual ~AlgListaIndex();
    
    //EFE: Retorna un string con los elementos de la lista.
    //REQ: L inicializado.
    //MOD:
    string listar(Lista l);
    
    //EFE: Retorna true si la lista es simetrica y false en caso contrario.
    //REQ: L inicializado.
    //MOD:
    bool simetrica(Lista l);
    
    //EFE: Invierte la lista.
    //REQ: L inicializado.
    //MOD: La Lista.
    void invertir(Lista l);
    
    //EFE: Retorna true si el elemento esta en la lista y false en caso contrario.
    //REQ: L inicializado.
    //MOD:
    bool buscar(int elem, Lista l);
    
    //EFE: Elimina los elementos repetidos de la lista.
    //REQ: L inicializada.
    //MOD: La lista L.
    void eliminarRep(Lista l);
    
    //EFE: Retorna true si L1 esta contenida en L2 y false en caso contrario.
    //REQ: L1 y L2 inicializados.
    //MOD: 
    bool sublista(Lista l1, Lista l2);
    
    //EFE: Retorna true si las listas son iguales y false en caso contrario.
    //REQ: L1 y L2 inicializadas.
    //MOD:
    bool iguales(Lista l1, Lista l2);
    
    //EFE: Ordena la lista con el algoritmo Burbuja.
    //REQ: L inicializada.
    //MOD: La Lista.
    void burbujaOri(Lista l);
    
    //EFE: Ordena la lista con el algoritmo Burbuja bidireccional.
    //REQ: L inicializada.
    //MOD: La Lista.
    void burbujaBi(Lista l);
    
    //EFE: Ordena la lista con el algoritmo Selección de manera iterativa.
    //REQ: L inicializada.
    //MOD: La Lista.
    void seleccionIter(Lista l);
    
    //EFE: Ordena la lista con el algoritmo Seleccion de manera recursiva usando la pila del compilador.
    //REQ: L inicializada.
    //MOD: La Lista.
    void seleccionRecUno(Lista l, int elem, int indice);
    
    /*EFE: Recibe el elemento con el que se compara en la lista y retorna el indice de el número más pequeño.
    //REQ: L inicializada y elem contenido en L.
    //MOD:
    int seleccionRecUnoRec(Lista l, int elem);*/
    
    //EFE: Ordena la lista con el algoritmo Seleccion de manera recursiva usando el modelo pila creado.
    //REQ: L inicializada.
    //MOD: La Lista.
    void seleccionRecDos(Lista l);
    
    //EFE: Ordena la lista con el algoritmo Inserción.
    //REQ: L inicializada.
    //MOD: La lista.
    void insercion(Lista l);
    
    //EFE: Analiza la opción recibida para aplicar el quickSort deseado, ya sea quickSort por aho o quickSorDos.
    //REQ: L inicializada.
    //MOD:
    void quickSort(Lista l, int opcion);
    
    //EFE: Encuentra el pivote segun Aho para aplicar Quick Sort.
    //REQ: L inicializada y pInicial y pFinal validos en la l.
    //MOD:
    int pivoteAho(Lista l, int pInicial, int pFinal);
    
    //EFE: Encuentra el sitio donde los apuntadores se traslapan y retorna la posicion.
    //REQ: L inicializada, pInicial y pFinal validos en l y elem contenido en la Lista.
    //MOD: La lista L.
    int encontrarParticion(Lista l, int pInicial, int pFinal, int pivote);
    
    //EFE: Ordena la lista con el algoritmo Quick Sort con la escogencia del pivote de Aho.
    //REQ: L inicializada.
    //MOD: La Lista.
    void quickSortAho(Lista l, int pInicial, int pFinal);
    
    //EFE: Ordena la lista con el algoritmo Quick Sort tal que si la lista contiene menos de 50 elementos
    // los ordena por inserción.
    //REQ: L inicializada.
    //MOD: La lista.
    void quickSortDos(Lista l, int pInicial, int pFinal);
    
    //EFE: Ordena la lista con el algoritmo Merge Sort. Este método se encarga de dividir
    // las listas en unas de la mitad del tamaño a la original.
    //REQ: L inicializada.
    //MOD: La lista.
    void mergeSort(Lista l);
    
    //EFE: Agrega de manera ordenada los elementos en izq y der a una tercera lista de resultado.
    //REQ: Izq y Der inicializadas.
    //MOD: La lista L3.
    Lista merge(Lista izq, Lista der);
    
    //EFE: Le agrega a L1 los elementos de L2, tal que no queden elementos repetidos en L1.
    //REQ: L1 y L2 inicializadas, ordenadas y sin elementos repetidos.
    //MOD: La lista L1.
    void unionUno(Lista l1, Lista l2);
    
    //EFE: Le agrega a L1 los elementos de L2, tal que no queden elementos repetidos en L1.
    //REQ: L1 y L2 inicializadas y sin elementos repetidos. No estan necesariamente ordenadas.
    //MOD: La lista L1.
    void unionDos(Lista l1, Lista l2);
    
    //EFE: Deja en L3 los elementos que estan tanto en L1 como en L2.
    //REQ: L1 y L2 inicializadas,  ordenadas y sin elementos repetidos.
    //MOD: La lista L3.
    Lista interseccionUno(Lista l1, Lista l2);
    
    //EFE: Deja en L3 los elementos que estan tanto en L1 como en L2.
    //REQ: L1 y L2 inicialiadas y sin elementos repetidos. No estan necesariamente ordenadas.
    //MOD: La lista L3.
    Lista interseccionDos(Lista l1, Lista l2);
    
    //EFE: Elimina de L1 los elementos que estan en L2.
    //REQ: L1 y L2 incializadas, ordenadas y sin elementos repetidos.
    //MOD: La lista L1.
    void eliminarUno(Lista l1, Lista l2);
    
    //EFE: Elimina de L1 los elementos que estan en L2.
    //REQ: L1 y L2 inicialiadas y sin elementos repetidos. No estan necesariamente ordenadas.
    //MOD: La lista L1.
    void eliminarDos(Lista l1, Lista l2);
private:

};

#endif /* ALGLISTAINDEX_H */

