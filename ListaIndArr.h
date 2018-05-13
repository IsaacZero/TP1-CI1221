/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaIndArr.h
 * Author: Arnoldo
 *
 * Created on 7 de mayo de 2018, 11:11 PM
 */

#ifndef LISTAINDARR_H
#define LISTAINDARR_H

#define MAX 100
template < typename E >
class ListaIndArr{

public:    
    
    ListaIndArr();
    virtual ~ListaIndArr();
    
    // EFE: Inicia la Lista vacía.
    // REQ: 
    // MOD: 
    void iniciar();
    
    // EFE: Destruye la Lista, la deja inutilizable.
    // REQ: La Lista inicializada.
    // MOD: La Lista.
    void destruir();
    
    // EFE: Vacia la Lista pero sigue siendo utilizable.
    // REQ: La Lista inicializada.
    // MOD: La Lista.
    void vaciar();
    
    // EFE: Retorna true si la Lista esta vacía y false en caso contrario.
    // REQ: La Lista inicializada.
    // MOD:
    bool vacia();
    
    // EFE: Inserta el elemento e de i-ésimo en la lista L
    // REQ: L inicializada, i <= NumElem(L)
    // MOD:: L
    void insertar(E elem, int i);
    
    // EFE: Borra el elemento e i-ésimo de la lista L
    // REQ: L inicializada
    // MOD:: L
    void borrar(int i);
    
    // EFE: Retorna el elemento i-ésimo de la lista L\\
    // REQ: Lista L inicializada, p válida en L\\
    // MOD:: \\

    E recuperar(int i);
    
    // EFE: Reemplaza el elemento por el elemento i-ésimo de la lista.
    // REQ: Lista L inicializada, i <= NumElem(L)
    // MOD:: L
    void modificarElemento(E elem,int i);
    
    // EFE: Intercambia de posición a los elementos i-ésimo y j-ésimo de la lista L.
    // REQ: L inicializada, i <= NumElem(L), j <= NumElem(L)
    // MOD:: L
    void intercambiar(int i,int j);
    
    // EFE: Retorna la cantidad de elementos en la lista L.\\
     // REQ: L inicializada\\
     // MOD:
     int numElem();
     
private:
    
    E arreglo[MAX];
    int cantidadElem;
    static E elemNulo;
};

template < typename E >
E ListaIndArr<E>::elemNulo = -1;

template < typename E >
ListaIndArr<E>::ListaIndArr(){
}

template < typename E >
ListaIndArr<E>::~ListaIndArr(){
}

template < typename E >
void ListaIndArr<E>::iniciar(){
    int cantidadElem = 0;
}

template < typename E >
void ListaIndArr<E>::destruir(){
    ListaIndArr<E>::~ListaIndArr();
}

template < typename E >
void ListaIndArr<E>::vaciar(){
    arreglo = E[MAX];
    int cantidadElem = 0;
}
    
template < typename E >
bool ListaIndArr<E>::vacia(){
    bool vacia = true;
    if(arreglo[0] != elemNulo){
        vacia = false;
    }
    return vacia;
}


template < typename E >
void ListaIndArr<E>::insertar(E elem, int i){
    arreglo[i] = elem;
}

template < typename E >
void ListaIndArr<E>::borrar(int i){
    for(int m = i; m < cantidadElem; m++){
        if (m < (cantidadElem-1) {
            arreglo[m] = arreglo[m+1];
        } else if ((m == (MAX - 1)) || (m == (cantidadElem - 1)) ){
            arreglo[m] = elemNulo;
        }
    }
}

template < typename E >
void ListaIndArr<E>::recuperar(int i){
    return arreglo[i];
}

template < typename E >
void ListaIndArr<E>::modificarElemento(E elem, int i){
    arreglo[i] = elem;
}

template < typename E >
void ListaIndArr<E>::intercambiar(int i, int j){
    E aux = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = aux;
}

template < typename E >
void ListaIndArr<E>::numElem(){
    return cantidadElem;

#endif /* LISTAINDARR_H */

