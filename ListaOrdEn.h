/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaOrdEn.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 11:11 PM
 */

#ifndef LISTAORDEN_H
#define LISTAORDEN_H

template < typename V >
class ListaOrdEn{
public:    
    
    ListaOrdEn();
    virtual ~ListaOrdEn();
    
    //EFE: Inicia la Lista vacía.
    //REQ:
    //MOD:
    void iniciar();
    
    //EFE: Destruye la Lista, la deja inutilizable.
    //REQ: La Lista inicializada.
    //MOD: La Lista.
    void destruir();
    
    //EFE: Vacia la Lista pero sigue siendo utilizable.
    //REQ: La Lista inicializada.
    //MOD: La Lista.
    void vaciar();
    
    //EFE: Retorna true si la Lista esta vacía y false en caso contrario.
    //REQ: La Lista inicializada.
    //MOD:
    bool vacia();
    
    //EFE: Agrega el elemento ordenadamente en la Lista.
    //REQ: L inicializada.
    //MOD: La Lista.
    void agregar(V newE);
    
    //EFE: Borra el elemento de la Lista.
    //REQ: L inicializada y elem existente en la Lista.
    //MOD: La Lista.
    void borrar(V elem);
    
    //EFE: Retorna el primer elemento de la Lista.
    //REQ: L inicializada.
    //MOD:
    V primero();
    
    //EFE: Retorna el ultimo elemento en la Lista.
    //REQ: L inicializada.
    //MOD:
    V ultimo();
    
    //EFE: Retorna el siguiente elemento a elem.
    //REQ: L inicializada y elem existente en la Lista.
    //MOD:
    V siguiente(V elem);
    
    //EFE: Retorna el elemento anterior a elem.
    //REQ: L inicializada y elem existente en la Lista.
    //MOD:
    V anterior(V elem);
    
    //EFE: Retorna la cantidad de elementos en la lista.
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
ListaOrdEn<V>::ListaOrdEn(){
}

template < typename V >
ListaOrdEn<V>::~ListaOrdEn(){
}

template < typename V >
void ListaOrdEn<V>::iniciar(){
    cantidadElem = 0;
    inicio = nodoNulo;
}

template < typename V >
void ListaOrdEn<V>::destruir(){
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
void ListaOrdEn<V>::vaciar(){
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
bool ListaOrdEn<V>::vacia(){
    bool vacio = false;
    if(inicio == nodoNulo)
        vacio = true;
    return vacio;
}

template < typename V >
void ListaOrdEn<V>::agregar(V newE){
    if (inicio == nodoNulo){
        Nodo<V> *n = new Nodo<V>(newE);
        inicio = n;
        cantidadElem++;
    }else if(inicio->elemento > newE){
        Nodo<V> *n = new Nodo<V>(newE);
        n->siguiente = inicio;
        inicio = n;
        cantidadElem++;
    }else{
        bool inserted = false;
        Nodo<V> *iter = inicio;
        Nodo<V> *n = new Nodo<V>(newE);
        while(!inserted){
            if (iter->siguiente->elemento > n->elemento && iter->elemento != n->elemento){
                n->siguiente = iter->siguiente;
                iter->siguiente = n;
                inserted = true;
                cantidadElem++;
            }else if(iter->siguiente == nodoNulo && iter->elemento != n->elemento){
                iter->siguiente = n;
                inserted = true;
                cantidadElem++;
            }else if (iter->elemento == n->elemento){
                inserted = true;
                delete n;
            }else{
                iter = iter->siguiente;
            }
        }
    }
}

template < typename V >
void ListaOrdEn<V>::borrar(V elem){
    if (inicio->elemento == elem){
        Nodo<V> *n = inicio;
        inicio = inicio->siguiente;
        delete n;
        cantidadElem--;
    }
    else{
        Nodo<V> *iter = inicio;
        Nodo<V> *n;
        while(iter->siguiente->elemento != elem){
            iter = iter->siguiente;
        }
        n = iter->siguiente;
        iter->siguiente = n->siguiente;
        delete n;
        cantidadElem--;
    }
}

template < typename V >
V ListaOrdEn<V>::primero(){
    V elem = inicio->elemento;
    return elem;
}

template < typename V >
V ListaOrdEn<V>::ultimo(){
    Nodo<V> *iter = inicio;
    while(iter->siguiente != nodoNulo)
        iter = iter->siguiente;
    return iter->elemento;
}

template < typename V >
V ListaOrdEn<V>::siguiente(V elem){
    V sig;
    if(inicio->elemento == elem && inicio->siguiente != nodoNulo)
        sig = inicio->siguiente->elemento;
    else{
        Nodo<V> *iter = inicio;
        while(iter->elemento != elem)
            iter = iter->siguiente;
        if(iter->siguiente == nodoNulo)
            sig = -1;
        else
            sig = iter->siguiente->elemento;
    }
    return sig;
}

template < typename V >
V ListaOrdEn<V>::anterior(V elem){
    V ant;
    if (elem == inicio->elemento)
        ant = -1;
    else{
        Nodo<V> *iter = inicio;
        while(iter->siguiente->elemento != elem)
            iter = iter->siguiente;
        ant = iter;
    }
    return ant;
}

template < typename V >
int ListaOrdEn<V>::numElem(){
    return cantidadElem;
}
#endif /* LISTAORDEN_H */

