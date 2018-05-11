/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaIndEn.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 11:10 PM
 */

#ifndef LISTAINDEN_H
#define LISTAINDEN_H

template < typename V >
class ListaIndEn{
public:    
    
    ListaIndEn();
    virtual ~ListaIndEn();
    
    //EFE: Inicializa la Lista.
    //REQ:
    //MOD:
    void iniciar();
    
    //EFE: Destruye la Lista, la deja inutilizable.
    //REQ: L inicializado.
    //MOD: La Lista.
    void destruir();
    
    //EFE: Elimina todos los elementos de la Lista.
    //REQ: L inicializado.
    //MOD: La Lista.
    void vaciar();
    
    //EFE: Retorna true si esta vacia y false en caso contrario.
    //REQ: La Lista inicializada.
    //MOD:
    bool vacia();
    
    //EFE: Inserta el elemento de i-ésimo en la Lista.
    //REQ: L inicializada, i <= NumElem.
    //MOD: La Lista.
    void insertar(V elemento, int indice);
    
    //EFE: Borra el elemento i-ésimo de la Lista.
    //REQ: L inicializada.
    //MOD: La Lista.
    void borrar(int indice);
    
    //EFE: Retorna el elemento i-ésimo de la Lista.
    //REQ: L inicializada e i valida en L.
    //MOD:
    V recuperar(int indice);
    
    //EFE: Reemplaza el elemento de la i-ésima posición por el nuevo elemento.
    //REQ: L inicializada y no vacía, i valida en L.
    //MOD: La Lista.
    void modificarElemento(V newE, int indice);
    
    //EFE: Intercambia de posición los elementos i-ésimo y j-ésimo de la Lista.
    //REQ: L inicializada, i y j validos en L.
    //MOD: La Lista.
    void intercambiar(int i, int j);
    
    //EFE: Retorna la cantidad de elementos en la Lista.
    //REQ: L inicializada.
    //MOD:
    int numElem();
    
private:
    template < typename T >
    struct Nodo{
        T elemento;
        Nodo *siguiente;
        Nodo(): siguiente(nullptr){
        }
        Nodo(T newE): elemento(newE){
        }
    };
    int cantidadElem;
    Nodo<V> *inicio;
    static Nodo<V> *nodoNulo;
};

template < typename V >
ListaIndEn<V>::Nodo<V>* ListaIndEn<V>::nodoNulo = nullptr;

template < typename V >
ListaIndEn<V>::ListaIndEn(){
}

template < typename V >
ListaIndEn<V>::~ListaIndEn(){
}

template < typename V >
void ListaIndEn<V>::iniciar(){
    cantidadElem = 0;
    inicio = nodoNulo;
}

template < typename V >
void ListaIndEn<V>::destruir(){
    Nodo<V> *iter = inicio;
    Nodo<V> *n;
    while(iter != nodoNulo){
        n = iter;
        iter = iter->siguiente;
        delete n;
    }
    delete this;
}

template < typename V >
void ListaIndEn<V>::vaciar(){
    Nodo<V> *iter = inicio;
    Nodo<V> *n;
    while(iter != nodoNulo){
        n = iter;
        iter = iter->siguiente;
        delete n;
    }
    cantidadElem = 0;
}

template < typename V >
bool ListaIndEn<V>::vacia(){
    bool empty = false;
    if(inicio == nodoNulo)
        empty = true;
    return empty;
}

template < typename V >
void ListaIndEn<V>::insertar(V elemento, int indice){
    if (indice == 1){
        Nodo<V> *n = new Nodo<V>(elemento);
        inicio = n;
        cantidadElem++;
    }
    else{
        int i = 1;
        Nodo<V> *n = new Nodo<V>(elemento);
        Nodo<V> *iter = inicio;
        while(i != indice){
            iter = iter->siguiente;
            i++;
        }
        n->siguiente = iter->siguiente;
        iter->siguiente = n;
        cantidadElem++;
    }
}

template < typename V >
void ListaIndEn<V>::borrar(int indice){
    if (indice == 1){
        Nodo<V> *n = inicio;
        inicio = inicio->siguiente;
        delete n;
        cantidadElem--;
    }
    else{
        int i = 1;
        Nodo<V> *n = inicio;
        Nodo<V> *ns;
        while(i != indice-1){
            n = n->siguiente;
            ns = n->siguiente;
            i++;
        }
        n->siguiente = ns->siguiente;
        delete ns;
        cantidadElem--;
    }
}

template < typename V >
V ListaIndEn<V>::recuperar(int indice){
    V elem;
    if (indice == 1)
        elem = inicio->elemento;
    else{
        int i = 1;
        Nodo<V> *n = inicio;
        while(i != indice){
            n = n->siguiente;
            i++;
        }
        elem = n->elemento;
    }
    return elem;
}

template < typename V >
void ListaIndEn<V>::modificarElemento(V newE, int indice){
    if(indice == 1)
        inicio->elemento = newE;
    else{
        int i = 1;
        Nodo<V> *n = inicio;
        while(i != indice){
            n = n->siguiente;
            i++;
        }
        n->elemento = newE;
    }
}

template < typename V >
void ListaIndEn<V>::intercambiar(int i, int j){
    Nodo<V> *ni;
    Nodo<V> *nj;
    Nodo<V> *iterator = inicio;
    if(i > j){
        for(int iter = 1; iter <= i; iter++){
            if (iter == j)
                nj = iterator;
            else if(iter == i)
                ni = iterator;
            iterator = iterator->siguiente;
        }
    }
    else{
        for(int iter = 1; iter <= j; iter++){
            if (iter == i)
                ni = iterator;
            else if(iter == j)
                nj = iterator;
            iterator = iterator->siguiente;
        }
    }
    iterator->elemento = ni->elemento;
    ni->elemento = nj->elemento;
    nj->elemento = iterator->elemento;
}

template < typename V >
int ListaIndEn<V>::numElem(){
    return cantidadElem;
}
#endif /* LISTAINDEN_H */

