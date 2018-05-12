/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaOrdArr.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 11:11 PM
 */

#ifndef LISTAORDARR_H
#define LISTAORDARR_H

#define MAX 100
template < typename V >
class ListaOrdArr{
public:    
    
    ListaOrdArr();
    virtual ~ListaOrdArr();
    
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
    V arreglo[MAX];
    int ultimo;
    int cantidadElem;
    static V elemNulo;
};

template < typename V >
V ListaOrdArr<V>::elemNulo = -1;

template < typename V >
ListaOrdArr<V>::ListaOrdArr(){
}

template < typename V >
ListaOrdArr<V>::~ListaOrdArr(){
}

template < typename V >
void ListaOrdArr<V>::iniciar(){
    int cantidadElem = 0;
    int ultimo = 0;
}

template < typename V >
void ListaOrdArr<V>::destruir(){
    delete this;
}

template < typename V >
void ListaOrdArr<V>::vaciar(){
    for(int i = 0; i < cantidadElem; i++)
        arreglo[i] = -1;
    int cantidadElem = 0;
    int ultimo = 0;
}

template < typename V >
bool ListaOrdArr<V>::vacia(){
    bool vacio = false;
    if(cantidadElem == 0)
        vacio = true;
    return vacio;
}

template < typename V >
void ListaOrdArr<V>::agregar(V newE){
    if(cantidadElem == 0)
        arreglo[ultimo] = newE;
    else{
        arreglo[ultimo+1] = newE;
        ultimo++;
    }
    cantidadElem++;
}

template < typename V >
void ListaOrdArr<V>::borrar(V elem){
    int i = 0;
    bool encontrado = false;
    while(i < cantidadElem){
        if (arreglo[i] == elem){
            encontrado = true;
            arreglo[i] = arreglo[i+1];
        }
        else if(encontrado)
            arreglo[i] = arreglo[i+1];
        i++; 
    }
    cantidadElem--;
    ultimo--;
}

template < typename V >
V ListaOrdArr<V>::primero(){
    return arreglo[0];
}

template < typename V >
V ListaOrdArr<V>::ultimo(){
    return arreglo[ultimo];
}

template < typename V >
V ListaOrdArr<V>::siguiente(V elem){
    V elemSig;
    if (arreglo[0] == elem)
        elemSig = elemNulo;
    else{
        int antI = 0;
        while(arreglo[antI] != elem)
            antI++;
        if(antI == ultimo)
            elemSig = -1;
        else
            elemSig = arreglo[antI+1];
    }
    return elemSig;
}

template < typename V >
V ListaOrdArr<V>::anterior(V elem){
    int antI = 0;
    V elemAnt;
    if (arreglo[0] == elem)
        elemAnt = elemNulo;
    else{
        while(arreglo[antI] != elem)
            antI++;
        elemAnt = arreglo[antI-1];
    }
    return elemAnt;
}

template < typename V >
int ListaOrdArr<V>::numElem(){
    return cantidadElem;
}
#endif /* LISTAORDARR_H */

