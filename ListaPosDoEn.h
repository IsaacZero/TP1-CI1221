/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaPosDoEn.h
 * Author: Arnoldo
 *
 * Created on 7 de mayo de 2018, 11:09 PM
 */

#ifndef LISTAPOSDOEN_H
#define LISTAPOSDOEN_H



template < typename E>
class ListaPosDoEn{
public:    
    
    typedef Nodo<E>* P;
    
    ListaPosDoEn();
    virtual ~ListaPosDoEn();
    
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
    
    private: 
        template < typename E>
        struct Nodo{
            E elemento;
            Nodo* siguiente;
            Nodo* anterior;
            Nodo(): siguiente(nullptr), anterior(nullptr){};
            Nodo(E nuevoElem): elemento(nuevoElem){};
            
        };
        
        int cantElem;
        Nodo<E>* inicio;
        static Nodo<E>* posNula;
};  

    template < typename E>
    ListaPosDoEn<E>::Nodo<E>* ListaPosDoEn::posNula = nullptr;
    
    template < typename E>
    ListaPosDoEn::ListaPosDoEn(){
    }
    
    template < typename E>
    ListaPosDoEn::~ListaPosDoEn(){
    }
    
    template < typename E>
    void ListaPosDoEn::iniciar(){
        cantElem = 0;
        inicio = posNula;
    }
    
    template < typename E>
    void ListaPosDoEn::destruir(){
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
    void ListaPosDoEn::vaciar(){
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
    bool ListaPosDoEn::vacia(){
        bool vacia = true;
        if(inicio != posNula){
            vacia =false;
        }
        return vacia;
    }
    
    template < typename E>
    void ListaPosDoEn::insertar(E elem, P pos){
        if (inicio == pos){
            Nodo<E> *j = *pos;
            pos->elemento = elem;
            pos->siguiente->anterior = j;
            pos->siguiente = j;
            j->anterior = pos;
        }else if(pos->siguiente = posNula){
            Nodo<E> *j = *pos;
            pos->elemento = elem;
            pos->siguiente = j;
            j->anterior = pos;
        }else{
            Nodo<E> *j = *pos;
            pos->elemento = elem;
            pos->siguiente->anterior = j;
            pos->siguiente = j;
            j->anterior = pos;
        }
    }
    
    template < typename E>
    void ListaPosDoEn::agregarAlFinal(E elem){
        Nodo<E>* ultimo = this->ultima(); 
        Nodo<E> *j = *ultimo;
        j->elemento = elem;
        ultimo->siguiente = j;
        j->anterior = ultimo;
        j->siguiente = posNula;
        cantElem++;
    }
    
    template < typename E>
    void ListaPosDoEn::borrar(P pos){
        if (inicio == pos){
            inicio = pos->siguiente;
            delete pos;
        }else if(pos->siguiente = posNula){
            pos->anterior->siguiente = posNula;
            delete pos;
        }else{
            pos->anterior->siguiente = pos->siguiente;
            pos->siguiente->anterior = pos->anterior;
            delete pos;
        }
        cantElem--;
    }
    
    
    template < typename E>
    E ListaPosDoEn::recuperar(P pos){
        return pos->elemento;
    }
    
    template < typename E>
    void ListaPosDoEn::modificarElemento(E elem, P pos){
        pos->elemento = elem;
    }
    
    template < typename E>
    void ListaPosDoEn::intercambiar(P pos1, P pos2){
        E aux = pos1->elemento;
        pos1 -> elemento = pos2 -> elemento;
        pos2 -> elemento = aux;        
    }
    
    template < typename E>
    P ListaPosDoEn::primera(){
        return inicio;
    }
    
    template < typename E>
    P ListaPosDoEn::ultima(){
        Nodo<E> *iter = inicio;
        Nodo<E> *n;
        while(iter->siguiente != posNula){
            n = iter;
            iter = iter->siguiente;
        }
        return iter;
    }
    
    template < typename E>
    P ListaPosDoEn::siguiente(P pos){
        return pos->siguiente;
    }
    
    template < typename E>
    P ListaPosDoEn::anterior(P pos){
        return pos->anterior;
    }
    
    template < typename E>
    int ListaPosDoEn::numElem(){
        return cantElem;
    }
    
    
    

#endif /* LISTAPOSDOEN_H */

