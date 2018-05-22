/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaOrd.cpp
 * Author: Isaac
 * 
 * Created on 19 de mayo de 2018, 08:36 PM
 */

#include "AlgListaOrd.h"

AlgListaOrd::AlgListaOrd() {
}

AlgListaOrd::AlgListaOrd(const AlgListaOrd& orig) {
}

AlgListaOrd::~AlgListaOrd() {
}

bool AlgListaOrd::iguales(Lista l1, Lista l2){
    bool igual = true;
    int elemUno = l1.primero();
    int elemDos = l2.primero();
    while (elemUno != -1 && elemDos != -1 && igual){
        if (elemUno == elemDos){
            elemUno = l1.siguiente(elemUno);
            elemDos = l2.siguiente(elemDos);
        }
        else
            igual = false;
    }
    return igual;
}

void AlgListaOrd::copiar(Lista l1, Lista l2){
    l2.vaciar();
    int elem = l1.primero();
    while(elem != -1){
        l2.agregar(elem);
        elem = l1.siguiente(elem);
    }
}

bool AlgListaOrd::contenida(Lista l1, Lista l2){
    bool content = true;
    if ((l1.vacia() && !l2.vacia()) || (!l1.vacia() && l2.vacia()))
        content = false;
    else {
        int elemUno = l1.primero();
        int elemDos = l2.primero();
        while(elemUno != -1 && elemDos != -1 && content){
            if(elemUno == elemDos){
                elemUno = l1.siguiente(elemUno);
                elemDos = l2.siguiente(elemDos);
            }else if (elemUno > elemDos)
                elemDos = l2.siguiente(elemDos);
            else
                content = false;
        }
        if (elemUno != -1 && elemDos == -1)
            content = false;
    }
    return content;
}

bool AlgListaOrd::pertene(int elemento, Lista l){
    bool belong = false;
    int elem = l.primero();
    while(elem != -1 && belong){
        if (elem < elemento)
            elem = l.siguiente(elem);
        else if(elem > elemento)
            elem = -1;
        else
            belong = true;
    }
    return belong;
}

void AlgListaOrd::eliminarElemRep(Lista l1, Lista l2){
    if(!l1.vacia() && !l2.vacia()){
        int elemUno = l1.primero();
        int elemDos = l2.primero();
        int saved;
        while(elemUno != -1){
            if(elemUno == elemDos){
                saved = elemUno;
                elemUno = l1.siguiente(elemUno);
                l1.borrar(saved);
                elemDos = l2.primero();
            }else if(elemUno > elemDos && elemDos != -1)
                elemDos = l2.siguiente(elemDos);
            else {
                elemDos = l2.primero();
                elemUno = l1.siguiente(elemUno);
            }
        }
    }
}

void AlgListaOrd::unionPrim(Lista l1, Lista l2){
    if(!l2.vacia()){
        int elem = l2.primero();
        while(elem != -1){
            l1.agregar(elem);
            elem = l2.siguiente(elem);
        }
    }
}

Lista AlgListaOrd::unionSeg(Lista l1, Lista l2){
    Lista l3;
    l3.iniciar();
    int elemUno = l1.primero();
    int elemDos = l2.primero();
    while (elemUno != -1 && elemDos != -1){
        if(elemUno == elemDos)
            l3.agregar(elemUno);
        else{
            l3.agregar(elemUno);
            l3.agregar(elemDos);
        }
        elemUno = l1.siguiente(elemUno);
        elemDos = l2.siguiente(elemDos);
    }
    if (elemUno != -1 && elemDos == -1){
        while (elemUno != -1){
            l3.agregar(elemUno);
            elemUno = l1.siguiente(elemUno);
        }
    }else {
        while (elemDos != -1){
            l3.agregar(elemDos);
            elemDos = l2.siguiente(elemDos);
        }
    }
    return l3;
}

Lista AlgListaOrd::interseccionPrim(Lista l1, Lista l2){//uso  de  un  algoritmo  auxiliar  de  búsqueda (Pertenece)
    Lista l3;
    l3.iniciar();
    if(!l1.vacia() && !l2.vacia()){
        bool belong;
        int elem = l1.primero();
        while(elem != -1){
            belong = this->pertene(elem, l2);
            if(belong){
                l3.agregar(elem);
                elem = l1.siguiente(elem);
            }else
                elem = l1.siguiente(elem);
        }
    }
    return l3;
}

Lista AlgListaOrd::interseccionSeg(Lista l1, Lista l2){//se moverá simultáneamente en ambas listas.
    Lista l3;
    l3.iniciar();
    if(!l1.vacia() && !l2.vacia()){
        int elemUno = l1.primero();
        int elemDos = l2.primero();
        while(elemUno != -1 && elemDos != -1){
            if(elemUno == elemDos){
                l3.agregar(elemUno);
                elemUno = l1.siguiente(elemUno);
                elemDos = l2.siguiente(elemDos);
            }else if(elemUno < elemDos)
                elemUno = l1.siguiente(elemUno);
            else
                elemDos = l2.siguiente(elemDos);
        }
    }
    return l3;
}