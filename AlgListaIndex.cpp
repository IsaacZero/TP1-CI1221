/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaIndex.cpp
 * Author: Isaac
 * 
 * Created on 19 de mayo de 2018, 08:35 PM
 */

#include "AlgListaIndex.h"

AlgListaIndex::AlgListaIndex() {
}

AlgListaIndex::AlgListaIndex(const AlgListaIndex& orig) {
}

AlgListaIndex::~AlgListaIndex() {
}

string AlgListaIndex::listar(Lista l){
    string listado = "";
    if(l.numElem() > 0){
        listado = "La lista tiene como elementos: \n";
        for(int i = 0; i < l.numElem(); i++){
            listado += "->";
            listado += std::to_string(l.recuperar(i));
        }
    }else{
        listado = "La lista esta vacía.";
    }
    return listado;
}

bool AlgListaIndex::simetrica(Lista l){
    bool esSim = true;
    int i = 0;
    int j = l.numElem()-1;
    while(i < j && esSim){
        if(l.recuperar(i) != l.recuperar(j))
            esSim = false;
        else{
            i++;
            j--;
        }
    }
    return esSim;
}

void AlgListaIndex::invertir(Lista l){
    int i = 0;
    int j = l.numElem()-1;
    while(i < j){
        l.intercambiar(i, j);
        i++;
        j--;
    }
}

bool AlgListaIndex::buscar(int elem, Lista l){
    bool encontrado = false;
    int i = 0;
    while (i < l.numElem() && !encontrado){
        if(l.recuperar(i) == elem)
            encontrado = true;
        else
            i++;
    }
    return encontrado;
}

void AlgListaIndex::eliminarRep(Lista l){
    for(int i = 0; i < l.numElem()-1; i++){
        int elem = l.recuperar(i);
        for(int j = i+1; j < l.numElem(); j++){
            if(elem == l.recuperar(j)){
                l.borrar(j);
                j--;
            }
        }
    }
}

bool AlgListaIndex::sublista(Lista l1, Lista l2){
    bool esSubLista = false;
    int elem = l1.recuperar(0);
    int indice = 0;
    int i = 0;
    while(i < l2.numElem() && !esSubLista){
        if(elem == l2.recuperar(i)){
            indice++;
            i++;
            elem = l1.recuperar(indice);
            if(indice == l1.numElem())
                esSubLista = true;
        }else{
            i++;
            indice = 0;
            elem = l1.recuperar(0);
        }
    }
    return esSubLista;
}

bool AlgListaIndex::iguales(Lista l1, Lista l2){
    bool igualdad = true;
    if (l1.numElem() != l2.numElem())
        igualdad = false;
    else{
        int i = 0;
        while (i < l1.numElem() && igualdad){
            if(l1.recuperar(i) != l2.recuperar(i))
                igualdad = false;
            else
                i++;
        }
    }
    return igualdad;
}

void AlgListaIndex::burbujaOri(Lista l){
    if(l.numElem() > 1){
        for(int i = 0; i < l.numElem()-1; i++){
            for(int j = i+1; j < l.numElem(); j++){
                if(l.recuperar(i) < l.recuperar(j))
                    l.intercambiar(i, j);
            }
        }
    }
}

void AlgListaIndex::burbujaBi(Lista l){
    if(l.numElem() > 1){
        int i = 0;
        int ciclo = 1;
        while(ciclo < l.numElem()){
            for (int j = i+1; j < l.numElem()-ciclo; j++){
                if(l.recuperar(j) < l.recuperar(j+1))
                    l.intercambiar(j, (j+1));
            }
        }
    }
}

void AlgListaIndex::seleccionIter(Lista l){
    
}

void AlgListaIndex::seleccionRecUno(Lista l){
    
}

void AlgListaIndex::seleccionRecDos(Lista l){
    
}

void AlgListaIndex::insercion(Lista l){
    
}

void AlgListaIndex::quickSort(Lista l, int opcion){
    
}

int AlgListaIndex::pivoteAho(Lista l, int pInicial, int pFinal){
    
}

int AlgListaIndex::encontrarParticion(Lista l, int pInicial, int pFinal, int elem){
    
}

void AlgListaIndex::quickSortAho(Lista l){
    
}

void AlgListaIndex::quickSortDos(Lista l){
    
}

void AlgListaIndex::mergeSort(Lista l){
    
}

Lista AlgListaIndex::merge(Lista izq, Lista der){
    
}

void AlgListaIndex::unionUno(Lista l1, Lista l2){
    
}

void AlgListaIndex::unionDos(Lista l1, Lista l2){
    
}

Lista AlgListaIndex::interseccionUno(Lista l1, Lista l2){
    
}

Lista AlgListaIndex::interseccionDos(Lista l1, Lista l2){
    
}

void AlgListaIndex::eliminarUno(Lista l1, Lista l2){
    
}

void AlgListaIndex::eliminarDos(Lista l1, Lista l2){
    
}