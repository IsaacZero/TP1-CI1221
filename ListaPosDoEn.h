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
    
    private: 
        template < typename V>
        struct Nodo{
            V elemento;
            Nodo* siguiente;
            Nodo* anterior;
            Nodo(): siguiente(posNula), anterior(posNula){};
            Nodo(V nuevoElem): elemento(nuevoElem), siguiente(posNula), anterior(posNula){};
            
        };
        
        int cantElem;
        Nodo<E>* inicio;
        static Nodo<E>* posNula;
        
    public:    
    
    typedef Nodo<E>* Pos;
    
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
    void insertar(E elem, Pos pos);
    
    //EFE: Inserta el elemento elem al final de la lista
    //REQ: La Lista inicializada, que haya una cantidad menor de elementos a la maxima
    //MOD:  La lista L
    void agregarAlFinal(E elem);
    
    //EFE: Borra el elemento en la posición pos de la lista
    //REQ: La Lista inicializada, que pos sea valida en la Lista
    //MOD:  La lista L
    void borrar(Pos pos);
    
    //EFE: Retorna el elemento en la posicion p de la lista 
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    E recuperar(Pos pos);
    
    //EFE: Reemplaza el elemento e en la lista en la posición p por el que ya existía en dicha posición.
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    void modificarElemento(E elem,Pos pos);
    
    //EFE: Intercambia de posición a los elementos en las posiciones pos1 y pos2 de la lista
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    void  intercambiar(Pos pos1, Pos pos2);
    
    //EFE: Retorna la primer posición de la lista
    //REQ: La Lista inicializada no vacía
    //MOD:  La lista L
    Pos primera();
    
    //EFE: Retorna la última posición de la lista
    //REQ: La Lista inicializada no vacía
    //MOD:  La lista L
    Pos ultima();
    
    //EFE: Retorna la posición siguiente de la posición pos en la lista
    //REQ: La Lista inicializada. pos válida en la Lista h y pos no es el ultimo 
    //MOD:  La lista L
    Pos siguiente(Pos pos);
    
    //EFE:Retorna la posición anterior de la posición pos en la lista
    //REQ: La Lista inicializada. p válida en la Lista y pos no es el
    //MOD:  La lista L
    Pos anterior(Pos pos);
    
    //EFE: Retorna la cantidad de elementos en la lista.
    //REQ: L inicializada.
    //MOD:
    int numElem();
};  
    
    template < typename E>
    ListaPosDoEn<E>::Nodo<E>* ListaPosDoEn<E>::posNula = nullptr;
    
    template < typename E>
    ListaPosDoEn<E>::ListaPosDoEn(){
    }
    
    template < typename E>
    ListaPosDoEn<E>::~ListaPosDoEn(){
    }
    
    template < typename E>
    void ListaPosDoEn<E>::iniciar(){
        cantElem = 0;
        inicio = posNula;
    }
    
    template < typename E>
    void ListaPosDoEn<E>::destruir(){
        if(cantElem != 0){
            Nodo<E> *iter = inicio;
            Nodo<E> *n;
            while(iter != posNula){
                n = iter;
                iter = iter->siguiente;
                delete n;
            }
        delete iter;
        }
        cantElem = 0;
        inicio = posNula;
    }
    
    template < typename E>
    void ListaPosDoEn<E>::vaciar(){
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
    bool ListaPosDoEn<E>::vacia(){
        bool vacia = true;
        if(inicio != posNula){
            vacia =false;
        }
        return vacia;
    }
    
    template < typename E>
    void ListaPosDoEn<E>::insertar(E elem, Pos pos){
        if (inicio == pos){
            Nodo<E> *n = new Nodo<E>(elem);
            Nodo<E> *j = inicio;
            inicio = n;
            j->anterior = inicio;
            n->siguiente = j;
            cantElem++;
        }else if(pos->siguiente == posNula){
            Nodo<E> *n = new Nodo<E>(pos->elemento);
            pos->elemento = elem;
            pos->siguiente = n;
            n->anterior = pos;
            cantElem++;
        }else{
            Nodo<E> *n = new Nodo<E>(elem);
            n->siguiente = pos;
            n->anterior = pos->anterior;
            pos->anterior->siguiente = n;
            pos->anterior = n;
            cantElem++;
        }
    }
    
    template < typename E>
    void ListaPosDoEn<E>::agregarAlFinal(E elem){
        if(cantElem == 0){
            Nodo<E> *n = new Nodo<E>(elem);
            inicio = n;
        }
        else{
            Nodo<E>* ultimo = this->ultima();
            Nodo<E> *n = new Nodo<E>(elem);
            ultimo->siguiente = n;
            n->anterior = ultimo;
        }
        cantElem++;
    }
    
    template < typename E>
    void ListaPosDoEn<E>::borrar(Pos pos){
        if (inicio == pos && pos->siguiente != posNula){
            inicio = pos->siguiente;
            inicio->anterior = posNula;
            delete pos;
        }else if (inicio == pos && pos->siguiente == posNula){
            inicio = pos->siguiente;
            delete pos;
        }else if(pos->siguiente == posNula){
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
    E ListaPosDoEn<E>::recuperar(Pos pos){
        return pos->elemento;
    }
    
    template < typename E>
    void ListaPosDoEn<E>::modificarElemento(E elem, Pos pos){
        pos->elemento = elem;
    }
    
    template < typename E>
    void ListaPosDoEn<E>::intercambiar(Pos pos1, Pos pos2){
        E aux = pos1->elemento;
        pos1 -> elemento = pos2 -> elemento;
        pos2 -> elemento = aux;        
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosDoEn<E>::primera(){
        return inicio;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosDoEn<E>::ultima(){
        Nodo<E> *iter = inicio;
        while(iter->siguiente != posNula){
            iter = iter->siguiente;
        }
        return iter;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosDoEn<E>::siguiente(Pos pos){
        return pos->siguiente;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosDoEn<E>::anterior(Pos pos){
        return pos->anterior;
    }
    
    template < typename E>
    int ListaPosDoEn<E>::numElem(){
        return cantElem;
    }
    
    
    

#endif /* LISTAPOSDOEN_H */

