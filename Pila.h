/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 11:11 PM
 */
#include <cstdlib>
#ifndef PILA_H
#define PILA_H

template < typename V >
class Pila{    
public:
    
    Pila();
    virtual ~Pila();
    
    //EFE: Inicia la Pila vacía.
    //REQ:
    //MOD:
    void iniciar();
    
    //EFE: Destruye la Pila, la deja inutilizable.
    //REQ: P inicializada
    //MOD: La Pila.
    void destruir();
    
    //EFE: Vacía la Pila pero sigue siendo accesible.
    //REQ: P inicializada.
    //MOD: La Pila.
    void vaciar();
    
    //EFE: Retorna true si la Pila esta vacía y false en caso contrario.
    //REQ: P inicializada.
    //MOD:
    bool vacia();
    
    //EFE: Agrega el elemento a la Pila.
    //REQ: La Pila inicializada.
    //MOD: La Pila.
    void meter(V elemento);
    
    //EFE: Borra el elemento en el tope de la Pila.
    //REQ: La Pila inicializada y no vacía.
    //MOD: La Pila.
    V sacar();
    
    //EFE: Retorna el elemento en el tope  de la Pila para usarlo pero no lo borra.
    //REQ: La Pila inicializada y no vacía.
    //MOD:
    V tope();
    
    //EFE: Retorna la cantidad de elementos en P.
    //REQ: La Pila inicializada.
    //MOD:
    int numElem();
    
private:
    template < typename T >
    struct Nodo{
        T elemento;
        Nodo *siguiente;
        Nodo():siguiente(nullptr){
        }
        Nodo(T newE): elemento(newE), siguiente(nullptr){
        }
    };
    int cantidadElem;
    Nodo<V> *top;
    static Nodo<V> *nodoNulo;
};

template < typename V >
Pila<V>::Nodo<V>* Pila<V>::nodoNulo = nullptr;

template < typename V >
Pila<V>::Pila(){
}

template < typename V >
Pila<V>::~Pila(){
}

template < typename V >
void Pila<V>::iniciar(){
    cantidadElem = 0;
    top = nodoNulo;
}

template < typename V >
void Pila<V>::destruir(){
    while(top != nodoNulo){
        Nodo<V> *n = top;
        top = top->siguiente;
        delete n;
    }
    delete this;
}

template < typename V >
void Pila<V>::vaciar(){
    while(top != nodoNulo){
        Nodo<V> *n = top;
        top = top->siguiente;
        delete n;
    }
}

template < typename V >
bool Pila<V>::vacia(){
    bool vacio = false;
    if (top == nodoNulo)
        vacio = true;
    return vacio;
}

template < typename V >
void Pila<V>::meter(V elemento){
    Nodo<V> *n = new Nodo<V>(elemento);
    n->siguiente = top;
    top = n;
    cantidadElem++;
}

template < typename V >
V Pila<V>::sacar(){
    V e = top->elemento;
    Nodo<V> *n = top;
    top = top->siguiente;
    delete n;
    cantidadElem--;
    return e;
}

template < typename V >
V Pila<V>::tope(){
    return top->elemento;
}

template < typename V >
int Pila<V>::numElem(){
    return cantidadElem;
}
#endif /* PILA_H */

