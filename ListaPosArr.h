/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaPosArr.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 07:15 PM
 */

#ifndef LISTAPOSARR_H
#define LISTAPOSARR_H

#define MAX 100

template < typename E>
class ListaPosArr{
public:    
    typedef int Pos;
    ListaPosArr();
    virtual ~listaPosArr();
    
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
    void recuperar(Pos pos);
    
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
    //REQ: La Lista inicializada. pos válida en la Lista
    //MOD:  La lista L
    Pos siguiente(Pos pos);
    
    //EFE:Retorna la posición anterior de la posición pos en la lista
    //REQ: La Lista inicializada. p válida en la Lista
    //MOD:  La lista L
    Pos anterior(Pos pos);
    
    //EFE: Retorna la cantidad de elementos en la lista.
    //REQ: L inicializada.
    //MOD:
    int numElem();
    
    private: 
        template < typename E>
        
        E arreglo[MAX];
        int cantElem;
        Pos ultimo;
        
        static Pos posNula;   
};  

    template < typename E>
    Pos ListaPosArr<E>::posNula = -1;
    
    template < typename E>
    ListaPosArr<E>::ListaPosArr(){
    }
    
    template < typename E>
    ListaPosArr<E>::~ListaPosArr(){
    }
    
    template < typename E>
    void ListaPosArr<E>::iniciar(){
        cantElem = 0;
        ultimo = -1;
    }
    
    template < typename E>
    void ListaPosArr<E>::destruir(){
        ListaPosArr<E>::~ListaPosArr();
    }
    
    template < typename E>
    void ListaPosArr<E>::vaciar(){
        arreglo = E[MAX];
        cantElem = 0;
        ultimo = -1;
    }
    
    template < typename E>
    bool ListaPosArr<E>::vacia(){
        bool vacia = true;
        if(ultimo != 0){
            vacia =false;
        }
        return vacia;
    }
    
    template < typename E>
    void ListaPosArr<E>::insertar(E elem, P pos){
        E aux1 = arreglo[pos];
        arreglo[pos] = elem;
        cantElem++;
        ultimo++;
        for (int i = pos+1; i<cantElem; i++){
            E aux2 = arreglo[i];
            arreglo[i] = aux1;
            aux1 = aux2;
        }
        
    }
    
    template < typename E>
    void ListaPosArr<E>::agregarAlFinal(E elem){
        arreglo[ultimo] = elem;
        ultimo++;
        cantElem++;
    }
    
    template < typename E>
    void ListaPosArr<E>::borrar(P pos){
        for (int i = pos; i<cantElem; i++){
            arreglo[i] = arreglo[i+1];
        }
        ultimo--;
        cantElem--;
    }
    
    
    template < typename E>
    E ListaPosArr<E>::recuperar(Pos pos){
        return arreglo[pos];
    }
    
    template < typename E>
    void ListaPosArr<E>::modificarElemento(E elem, Pos pos){
        arreglo[pos] = elem;
    }
    
    template < typename E>
    void ListaPosArr<E>::intercambiar(Pos pos1, Pos pos2){
        E aux = arreglo[pos1];
        arreglo[pos1] = arreglo[pos2];
        arreglo[pos2] = aux;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosArr::primera(){
        return 0;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosArr::ultima(){
        return ultimo;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosArr::siguiente(Pos pos){
        return pos + 1;
    }
    
    template < typename E>
    typename ListaPosDoEn<E>::Pos ListaPosArr::anterior(Pos pos){
        return pos + 1;
    }
    
    template < typename E>
    int ListaPosArr::numElem(){
        return numElem;
    }
    
    
    
    

#endif /* LISTAPOSARR_H */

