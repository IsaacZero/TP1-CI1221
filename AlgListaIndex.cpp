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
        int ciclo = 2;
        while((l.numElem() - ciclo) >= i){
            for (int j = i; j <= l.numElem()-ciclo; j++){
                if(l.recuperar(j) < l.recuperar(j+1))
                    l.intercambiar(j, (j+1));
            }
            for(int j = l.numElem()-ciclo; j > i; j--){
                if(l.recuperar(j-1) > l.recuperar(j))
                    l.intercambiar(j-1, j);
            }
            ciclo++;
            i++;
        }
    }
}

void AlgListaIndex::seleccionIter(Lista l){
    if(l.numElem() > 1){
        int aux = 0;
        for(int i = 0; i < l.numElem()-1; i++){
            for(int j = i+1; j < l.numElem(); j++){
                if(l.recuperar(i) < l.recuperar(j))
                    aux = j;
            }
            l.intercambiar(i, aux);
        }
    }
}

void AlgListaIndex::seleccionRecUno(Lista l, int elem, int indice){
    if(l.numElem() > 1){
        int temp = 0;
        for(int j = indice+1; j < l.numElem(); j++){
            if(elem > l.recuperar(j))
                temp = j;
        }
        l.intercambiar(indice, temp);
        if(indice < l.numElem()-1)
            this->seleccionRecUno(l, l.recuperar(indice+1), indice+1);
    }
}

void AlgListaIndex::seleccionRecDos(Lista l){
    if(l.numElem() > 1){
        pila pilaR;
        pilaR.iniciar();
        int indice = 0;
        int elem = l.recuperar(indice);
        int aux = 0;
        pilaR.meter(indice);
        while(!pilaR.vacia()){
            indice = pilaR.sacar();
            for(int j = indice+1; j < l.numElem(); j++){
                if(l.recuperar(indice) > l.recuperar(j))
                    aux = j;
            }
            l.intercambiar(indice, aux);
            if(indice < l.numElem()-1)
                pilaR.meter(indice+1);
        }
        pilaR.destruir();
    }
}

void AlgListaIndex::insercion(Lista l){
    for(int i = 0; i < l.numElem()-1; i++){
        int j = i+1;
        if(l.recuperar(i) > l.recuperar(j)){
            int elemAux = l.recuperar(j);
            while (j > 0){
                if(l.recuperar(i+1) < l.recuperar(j-1)){
                    j--;
                }else{
                    l.insertar(elemAux, j);
                    j = 0;
                }
            }
        }
    }
}

void AlgListaIndex::quickSort(Lista l, int opcion){
    if(l.numElem() > 1){
        if(opcion == 1)
            this->quickSortAho(l, 0, l.numElem()-1);
        else
            this->quickSortDos(l, 0, l.numElem()-1);
    }
}

int AlgListaIndex::pivoteAho(Lista l, int pInicial, int pFinal){
    int pivote = -1;
    int i = pInicial;
    while(i < pFinal-1 && pivote != -1){
        int primElem = l.recuperar(i);
        if(primElem < l.recuperar(i+1))
            pivote = i;
        else if(primElem > l.recuperar(i+1))
            pivote = i+1;
        else
            i++;
    }
    return pivote;
}

int AlgListaIndex::encontrarParticion(Lista l, int pInicial, int pFinal, int pivote){
    int i = pInicial;
    int j = pFinal;
    while(i <= j){
        l.intercambiar(i,j);
        while(l.recuperar(i) < pivote)
            i++;
        while(l.recuperar(j) >= pivote)
            j++;
    }
    return i;
}

void AlgListaIndex::quickSortAho(Lista l, int pInicial, int pFinal){
    if (pInicial != pFinal){
        int pivote = this->pivoteAho(l, pInicial, pFinal);
        if (pivote != -1){
            int particion = this->encontrarParticion(l, pInicial, pFinal, l.recuperar(pivote));
            this->quickSortAho(l, pInicial, particion);
            this->quickSortAho(l, pInicial+1, pFinal);
        }
    }
}

void AlgListaIndex::quickSortDos(Lista l, int pInicial, int pFinal){
    if (pInicial != pFinal){
        int pivote = l.recuperar(pInicial);
        int particion = this->encontrarParticion(l, pInicial, pFinal, l.recuperar(pivote));
        this->quickSortAho(l, pInicial, particion);
        this->quickSortAho(l, pInicial+1, pFinal);
    }
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