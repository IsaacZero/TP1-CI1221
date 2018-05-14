/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaPosSimEn.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 11:09 PM
 */

#ifndef LISTAPOSSIMEN_H
#define LISTAPOSSIMEN_H

template <typename E>
class ListaPosSimEn{
    
    private: 
        template < typename Elem>
        struct Nodo{
            Elem elemento;
            Nodo* siguiente;
            Nodo(): siguiente(nullptr), anterior(nullptr){};
            Nodo(Elem nuevoElem): elemento(nuevoElem){};
            
        };
        
        int cantElem;
        Nodo<E>* inicio;
        static Nodo<E>* posNula;
    
    public:    

    typedef Nodo<E>* P;
    
    ListaPosSimEn();
    virtual ~ListaPosSimEn();
    
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
    
    //EFE: Inserta el elemento elem en la lista en la posición pos
    //REQ: La Lista inicializada, que haya una cantidad menor de elementos a la maxima
    //MOD:  La lista L
    void insertar(E elem, P pos);
    
    //EFE: Inserta el elemento elem al final de la lista
    //REQ: La Lista inicializada, que haya una cantidad menor de elementos a la maxima
    //MOD:  La lista L
    void agregarAlFinal(E elem);
    
    //EFE: Borra el elemento en la posición pos de la lista
    //REQ: La Lista inicializada, que pos sea valida en la Lista
    //MOD:  La lista L
    void borrar(P pos);
    
    //EFE: Retorna el elemento en la posicion p de la lista 
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    void recuperar(P pos);
    
    //EFE: Reemplaza el elemento e en la lista en la posición p por el que ya existía en dicha posición.
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    void modificarElemento(E elem,P pos);
    
    //EFE: Intercambia de posición a los elementos en las posiciones pos1 y pos2 de la lista
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    void  intercambiar(P pos1, P pos2);
    
    //EFE: Retorna la primer posición de la lista
    //REQ: La Lista inicializada no vacía
    //MOD:  La lista L
    P primera();
    
    //EFE: Retorna la última posición de la lista
    //REQ: La Lista inicializada no vacía
    //MOD:  La lista L
    P ultima();
    
    //EFE: Retorna la posición siguiente de la posición pos en la lista
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    P siguiente(P pos);
    
    //EFE:Retorna la posición anterior de la posición pos en la lista
    //REQ: La Lista inicializada. p válida en la Lista
    //MOD:  La lista L
    P anterior(P pos);
    
    //EFE: Retorna la cantidad de elementos en la lista.
    //REQ: L inicializada.
    //MOD:
    int numElem();
    
    
};  

    template < typename E>
    ListaPosSimEn<E>::Nodo<E>* ListaPosSimEn::posNula = nullptr;
    
    template < typename E>
    ListaPosSimEn<E>::ListaPosSimEn(){
    }
    
    template < typename E>
    ListaPosSimEn<E>::~ListaPosSimEn(){
    }
    
    template < typename E>
    void ListaPosSimEn<E>::iniciar(){
        cantElem = 0;
        inicio = posNula;
    }
    
    template < typename E>
    void ListaPosSimEn<E>::destruir(){
        Nodo<E> *iter = inicio;
        Nodo<E> *n;
        while(iter != posNula){
            n = iter;
            iter = iter->siguiente;
            delete n;
        }
        delete this;
    }
    
    template < typename E>
    void ListaPosSimEn<E>::vaciar(){
        Nodo<E> *iter = inicio;
        Nodo<E> *n;
        while(iter != posNula){
            n = iter;
            iter = iter->siguiente;
            delete n;
        }
        cantElem = 0;
    }
    
    template < typename E>
    bool ListaPosSimEn<E>::vacia(){
        bool vacia = true;
        if(inicio != posNula){
            vacia =false;
        }
        return vacia;
    }
    
    template < typename E>
    void ListaPosSimEn<E>::insertar(E elem, P pos){
        if(inicio == posNula){
             Nodo<E> *n = new Nodo<E>(elem);
             inicio = n;
        }
        else if (inicio == pos){
            Nodo<E> *j = *pos;
            pos->elemento = elem;
            pos->siguiente = j;
        }else if(pos->siguiente = posNula){
            Nodo<E> *j = *pos;
            pos->elemento = elem;
            pos->siguiente = j;
        }else{
            Nodo<E> *j = *pos;
            pos->elemento = elem;
            pos->siguiente = j;
        }
    }
   
    template < typename E>
    void ListaPosSimEn<E>::agregarAlFinal(E elem){
        Nodo<E>* ultimo = this->ultima(); 
        Nodo<E> *j = *ultimo;
        j->elemento = elem;
        ultimo->siguiente = j;
        j->siguiente = posNula;
        cantElem++;
    }
    
    template < typename E>
    void ListaPosSimEn<E>::borrar(P pos){
        if (inicio == pos){
            inicio = pos->siguiente;
            delete pos;
        }else if(pos->siguiente = posNula){
            Nodo<E>* anterior = this->anterior(pos);
            anterior->siguiente = posNula;
            delete pos;
        }else{
            Nodo<E>* anterior = this->anterior(pos);
            anterior->siguiente = pos->siguiente;
            delete pos;
        }
        cantElem--;
    }
    
    
    template < typename E>
    E ListaPosSimEn<E>::recuperar(P pos){
        return pos->elemento;
    }
    
    template < typename E>
    void ListaPosSimEn<E>::modificarElemento(E elem, P pos){
        pos->elemento = elem;
    }
    
    template < typename E>
    void ListaPosSimEn<E>::intercambiar(P pos1, P pos2){
        E aux = pos1->elemento;
        pos1 -> elemento = pos2 -> elemento;
        pos2 -> elemento = aux;        
    }
    
    template < typename E>
    P ListaPosSimEn<E>::primera(){
        return inicio;
    }
    
    template < typename E>
    P ListaPosSimEn<E>::ultima(){
        Nodo<E>* iter = inicio;
        Nodo<E>* n;
        while(iter->siguiente != posNula){
            n = iter;
            iter = iter->siguiente;
        }
        return iter;
    }
    
    template < typename E>
    P ListaPosSimEn<E>::siguiente(P pos){
        return pos->siguiente;
    }
    
    template < typename E>
    P ListaPosSimEn<E>::anterior(P pos){
        Nodo<E>* iter = inicio;
        Nodo<E>* n;
        while(iter->siguiente != pos){
            n = iter;
            iter = iter->siguiente;
        }
        return iter;
    }
    
    template < typename E>
    int ListaPosSimEn<E>::numElem(){
        return cantElem;
    }

#endif /* LISTAPOSSIMEN_H */

