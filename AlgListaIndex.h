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

typedef ListaIndArr<int> listaInd;
//typedef ListaIndEn<int> listaInd;

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
    string listar(listaInd l);
    
    //EFE: Retorna true si la lista es simetrica y false en caso contrario.
    //REQ: L inicializado.
    //MOD:
    bool simetrica(listaInd l);
    
    //EFE: Invierte la lista.
    //REQ: L inicializado.
    //MOD: La Lista.
    void invertir(listaInd &l);
    
    //EFE: Retorna true si el elemento esta en la lista y false en caso contrario.
    //REQ: L inicializado.
    //MOD:
    bool buscar(int elem, listaInd l);
    
    //EFE: Elimina los elementos repetidos de la lista.
    //REQ: L inicializada.
    //MOD: La lista L.
    void eliminarRep(listaInd &l);
    
    //EFE: Retorna true si L1 esta contenida en L2 y false en caso contrario.
    //REQ: L1 y L2 inicializados.
    //MOD: 
    bool sublista(listaInd l1, listaInd l2);
    
    //EFE: Retorna true si las listas son iguales y false en caso contrario.
    //REQ: L1 y L2 inicializadas.
    //MOD:
    bool iguales(listaInd l1, listaInd l2);
    
    //EFE: Ordena la lista con el algoritmo Burbuja.
    //REQ: L inicializada.
    //MOD: La Lista.
    void burbujaOri(listaInd &l);
    
    //EFE: Ordena la lista con el algoritmo Burbuja bidireccional.
    //REQ: L inicializada.
    //MOD: La Lista.
    void burbujaBi(listaInd &l);
    
    //EFE: Ordena la lista con el algoritmo Selección de manera iterativa.
    //REQ: L inicializada.
    //MOD: La Lista.
    void seleccionIter(listaInd &l);
    
    //EFE: Ordena la lista con el algoritmo Seleccion de manera recursiva usando la pila del compilador.
    //REQ: L inicializada.
    //MOD: La Lista.
    void seleccionRecUno(listaInd &l, int elem, int indice);
    
    /*EFE: Recibe el elemento con el que se compara en la lista y retorna el indice de el número más pequeño.
    //REQ: L inicializada y elem contenido en L.
    //MOD:
    int seleccionRecUnoRec(Lista l, int elem);*/
    
    //EFE: Ordena la lista con el algoritmo Seleccion de manera recursiva usando el modelo pila creado.
    //REQ: L inicializada.
    //MOD: La Lista.
    void seleccionRecDos(listaInd &l);
    
    //EFE: Ordena la lista con el algoritmo Inserción.
    //REQ: L inicializada.
    //MOD: La lista.
    void insercion(listaInd &l);
    
    //EFE: Analiza la opción recibida para aplicar el quickSort deseado, ya sea quickSort por aho o quickSorDos.
    //REQ: L inicializada.
    //MOD:
    void quickSort(listaInd &l, int opcion);
    
    //EFE: Encuentra el pivote segun Aho para aplicar Quick Sort.
    //REQ: L inicializada y pInicial y pFinal validos en la l.
    //MOD:
    int pivoteAho(listaInd l, int pInicial, int pFinal);
    
    //EFE: Encuentra el sitio donde los apuntadores se traslapan y retorna la posicion.
    //REQ: L inicializada, pInicial y pFinal validos en l y elem contenido en la Lista.
    //MOD: La lista L.
    int encontrarParticion(listaInd &l, int pInicial, int pFinal, int pivote);
    
    //EFE: Ordena la lista con el algoritmo Quick Sort con la escogencia del pivote de Aho.
    //REQ: L inicializada.
    //MOD: La Lista.
    void quickSortAho(listaInd &l, int pInicial, int pFinal);
    
    //EFE: Ordena la lista con el algoritmo Quick Sort tal que si la lista contiene menos de 50 elementos
    // los ordena por inserción.
    //REQ: L inicializada.
    //MOD: La lista.
    void quickSortDos(listaInd &l, int pInicial, int pFinal);
    
    //EFE: Ordena la lista con el algoritmo Merge Sort. Este método se encarga de dividir
    // las listas en unas de la mitad del tamaño a la original.
    //REQ: L inicializada.
    //MOD: La lista.
    void mergeSort(listaInd &l);
    
    //EFE: Agrega de manera ordenada los elementos en izq y der a la lista que recibe de parametro. 
    //Se entiende que es la principal.
    //REQ: L, Izq y Der inicializadas.
    //MOD: La lista L.
    void merge(listaInd &izq, listaInd &der, listaInd &l);
    
    //EFE: Le agrega a L1 los elementos de L2, tal que no queden elementos repetidos en L1.
    //REQ: L1 y L2 inicializadas, ordenadas y sin elementos repetidos.
    //MOD: La lista L1.
    void unionUno(listaInd &l1, listaInd &l2);
    
    //EFE: Le agrega a L1 los elementos de L2, tal que no queden elementos repetidos en L1.
    //REQ: L1 y L2 inicializadas y sin elementos repetidos. No estan necesariamente ordenadas.
    //MOD: La lista L1.
    void unionDos(listaInd &l1, listaInd &l2);
    
    //EFE: Deja en L3 los elementos que estan tanto en L1 como en L2.
    //REQ: L1 y L2 inicializadas,  ordenadas y sin elementos repetidos.
    //MOD: La lista L3.
    listaInd interseccionUno(listaInd l1, listaInd l2);
    
    //EFE: Deja en L3 los elementos que estan tanto en L1 como en L2.
    //REQ: L1 y L2 inicialiadas y sin elementos repetidos. No estan necesariamente ordenadas.
    //MOD: La lista L3.
    listaInd interseccionDos(listaInd l1, listaInd l2);
    
    //EFE: Elimina de L1 los elementos que estan en L2.
    //REQ: L1 y L2 incializadas, ordenadas y sin elementos repetidos.
    //MOD: La lista L1.
    void eliminarUno(listaInd &l1, listaInd &l2);
    
    //EFE: Elimina de L1 los elementos que estan en L2.
    //REQ: L1 y L2 inicialiadas y sin elementos repetidos. No estan necesariamente ordenadas.
    //MOD: La lista L1.
    void eliminarDos(listaInd &l1, listaInd &l2);
    
    //EFE: Llena la lista con los numeros en el archivo, los números deben estar separados por espacio solamente.
    // Por ejemplo, al abrir el archivo .txt debe estar escrita la lista 2 4 6 8 si se quiere la lista {2,4,6,8}.
    // Se agregaran por el final de la lista los números.
    //REQ: Archivo valido en la carpeta del proyecto.
    //MOD: La lista
    void llenarLista(ifstream& archivo, listaInd &l);
private:

};

#endif /* ALGLISTAINDEX_H */

