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

string AlgListaIndex::listar(listaInd l){
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

bool AlgListaIndex::simetrica(listaInd l){
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

void AlgListaIndex::invertir(listaInd &l){
    int i = 0;
    int j = l.numElem()-1;
    while(i < j){
        l.intercambiar(i, j);
        i++;
        j--;
    }
}

bool AlgListaIndex::buscar(int elem, listaInd l){
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

void AlgListaIndex::eliminarRep(listaInd &l){
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

bool AlgListaIndex::sublista(listaInd l1, listaInd l2){
    bool esSubLista = false;
    int elem = l1.recuperar(0);
    int indice = 0;
    int i = 0;
    while(i < l2.numElem() && !esSubLista && (l2.numElem()-i) < l1.numElem()){
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

bool AlgListaIndex::iguales(listaInd l1, listaInd l2){
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

void AlgListaIndex::burbujaOri(listaInd &l){
    if(l.numElem() > 1){
        for(int i = 0; i < l.numElem()-1; i++){
            for(int j = i+1; j < l.numElem(); j++){
                if(l.recuperar(i) > l.recuperar(j))
                    l.intercambiar(i, j);
            }
        }
    }
}

void AlgListaIndex::burbujaBi(listaInd &l){
    if(l.numElem() > 1){
        int i = 0;
        int ciclo = 2;
        while((l.numElem() - ciclo) >= i){
            for (int j = i; j <= l.numElem()-ciclo; j++){
                if(l.recuperar(j) > l.recuperar(j+1))
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

void AlgListaIndex::seleccionIter(listaInd &l){
    if(l.numElem() > 1){
        int aux = 0;
        for(int i = 0; i < l.numElem()-1; i++){
            aux = i;
            for(int j = i+1; j < l.numElem(); j++){
                if(l.recuperar(aux) > l.recuperar(j))
                    aux = j;
            }
            l.intercambiar(i, aux);
        }
    }
}

void AlgListaIndex::seleccionRecUno(listaInd &l, int elem, int indice){
    if(l.numElem() > 1){
        int temp = indice;
        for(int j = indice+1; j < l.numElem(); j++){
            if(elem > l.recuperar(j) && l.recuperar(j) < l.recuperar(temp))
                temp = j;
        }
        l.intercambiar(indice, temp);
        if(indice < l.numElem()-1)
            this->seleccionRecUno(l, l.recuperar(indice+1), indice+1);
    }
}

void AlgListaIndex::seleccionRecDos(listaInd &l){
    if(l.numElem() > 1){
        pila pilaR;
        pilaR.iniciar();
        int indice = 0;
        int elem = l.recuperar(indice);
        int aux = 0;
        pilaR.meter(indice);
        while(!pilaR.vacia()){
            indice = pilaR.sacar();
            aux = indice;
            for(int j = indice+1; j < l.numElem(); j++){
                if(l.recuperar(aux) > l.recuperar(j))
                    aux = j;
            }
            l.intercambiar(indice, aux);
            if(indice < l.numElem()-1)
                pilaR.meter(indice+1);
        }
        pilaR.destruir();
    }
}

void AlgListaIndex::insercion(listaInd &l){
    for(int i = 0; i < l.numElem()-1; i++){
        int j = i+1;
        if(l.recuperar(i) > l.recuperar(j)){
            int elemAux = l.recuperar(j);
            l.borrar(j);
            while (j >= 0){
                if(elemAux < l.recuperar(j-1)){
                    j--;
                }else if(j == 0){
                    l.insertar(elemAux,j);
                    j = -1;
                }else{
                    l.insertar(elemAux, j);
                    j = -1;
                }
            }
        }
    }
}

void AlgListaIndex::quickSort(listaInd &l, int opcion){
    if(l.numElem() > 1){
        if(opcion == 1)
            this->quickSortAho(l, 0, l.numElem()-1);
        else if (opcion == 2){
            if(l.numElem() < 50)//Tamaño que varia.
                this->insercion(l);
            else
                this->quickSortDos(l, 0, l.numElem()-1);
        }
    }
}

int AlgListaIndex::pivoteAho(listaInd l, int pInicial, int pFinal){
    int pivote = -1;
    int i = pInicial;
    while(i < pFinal-1 && pivote == -1){
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

int AlgListaIndex::encontrarParticion(listaInd &l, int pInicial, int pFinal, int pivote){
    int i = pInicial;
    int j = pFinal;
    while(i < j){
        l.intercambiar(i,j);
        while(l.recuperar(i) < pivote)
            i++;
        while(l.recuperar(j) >= pivote)
            j--;
    }
    return i;
}

void AlgListaIndex::quickSortAho(listaInd &l, int pInicial, int pFinal){
    if (pInicial != pFinal){
        int pivote = this->pivoteAho(l, pInicial, pFinal);
        if (pivote != -1){
            int particion = this->encontrarParticion(l, pInicial, pFinal, l.recuperar(pivote));
            this->quickSortAho(l, pInicial, particion);
            this->quickSortAho(l, pInicial+1, pFinal);
        }
    }
}

void AlgListaIndex::quickSortDos(listaInd &l, int pInicial, int pFinal){
    if (pInicial != pFinal){
        int pivote = l.recuperar(pInicial);
        int particion = this->encontrarParticion(l, pInicial, pFinal, l.recuperar(pivote));
        this->quickSortAho(l, pInicial, particion);
        this->quickSortAho(l, pInicial+1, pFinal);
    }
}

void AlgListaIndex::mergeSort(listaInd &l){
    if(l.numElem() > 1){
        int medio = l.numElem()/2;
        listaInd izq, der;
        izq.iniciar();
        der.iniciar();
        for(int i = 0; i < medio; i++)
            izq.insertar(l.recuperar(i), i);
        for(int i = medio; i < l.numElem(); i++)
            der.insertar(l.recuperar(i), i);
        this->mergeSort(izq);
        this->mergeSort(der);
        if(izq.recuperar(izq.numElem()-1) <= der.recuperar(0)){
            int i = izq.numElem();
            for(int j = 0; j < der.numElem(); j++){
                izq.insertar(der.recuperar(j), i);
                i++;
            }
            der.destruir();
        }
        else
            this->merge(izq, der, l);
    }
}

void AlgListaIndex::merge(listaInd &izq, listaInd &der, listaInd &l){
    int i = 0, j = 0, pos = 0;
    while(i < izq.numElem() && j < der.numElem()){
        if(izq.recuperar(i) < der.recuperar(j)){
            l.modificarElemento(izq.recuperar(i), pos);
            i++;
            pos++;
        }else{
            l.modificarElemento(der.recuperar(j), pos);
            j++;
            pos++;
        }
    }
    while(i < izq.numElem() && j >= der.numElem()){
        l.modificarElemento(izq.recuperar(i), pos);
        pos++;
        i++;
    }
    while(j < der.numElem() && i >= izq.numElem()){
        l.modificarElemento(der.recuperar(j), pos);
        j++;
        pos++;
    }
}

void AlgListaIndex::unionUno(listaInd &l1, listaInd &l2){
    if(!l2.vacia() && !l1.vacia()){
        int j = 0;
        int elem = l2.recuperar(j);
        while(j < l2.numElem()){
            if(this->buscar(elem, l1)){
                j++;
                elem = l2.recuperar(j);
            }else{
                l1.insertar(elem, l1.numElem());
                j++;
                elem = l2.recuperar(j);
            }
        }
    }else if(l1.vacia() && !l2.vacia()){
        for(int i = 0; i < l2.numElem(); i++){
            l1.insertar(l2.recuperar(i), i);
        }
    }
}

void AlgListaIndex::unionDos(listaInd &l1, listaInd &l2){
    if(!l2.vacia() && !l1.vacia()){
        int j = 0;
        int elem = l2.recuperar(j);
        while(j < l2.numElem()){
            if(this->buscar(elem, l1)){
                j++;
                elem = l2.recuperar(j);
            }else{
                l1.insertar(elem, l1.numElem());
                j++;
                elem = l2.recuperar(j);
            }
        }
    }else if(l1.vacia() && !l2.vacia()){
        for(int i = 0; i < l2.numElem(); i++){
            l1.insertar(l2.recuperar(i), i);
        }
    }
}

listaInd AlgListaIndex::interseccionUno(listaInd l1, listaInd l2){
    listaInd lista;
    lista.iniciar();
    if(!l2.vacia() && !l1.vacia()){
        int j = 0, i = 0;
        int elem = l2.recuperar(j);
        while(j < l2.numElem()){
            if(this->buscar(elem, l1)){
                lista.insertar(elem, i);
                j++;
                i++;
                elem = l2.recuperar(j);
            }else{
                j++;
                elem = l2.recuperar(j);
            }
        }
    }
    return lista;
}

listaInd AlgListaIndex::interseccionDos(listaInd l1, listaInd l2){
    listaInd lista;
    lista.iniciar();
    if(!l2.vacia() && !l1.vacia()){
        int j = 0, i = 0;
        int elem = l2.recuperar(j);
        while(j < l2.numElem()){
            if(this->buscar(elem, l1)){
                lista.insertar(elem, i);
                j++;
                i++;
                elem = l2.recuperar(j);
            }else{
                j++;
                elem = l2.recuperar(j);
            }
        }
    }
    return lista;
}

void AlgListaIndex::eliminarUno(listaInd &l1, listaInd &l2){
    if(!l2.vacia() && !l1.vacia()){
        int j = 0;
        int elem = l1.recuperar(j);
        while(j < l1.numElem()){
            if(this->buscar(elem, l2)){
                elem = l1.recuperar(j+1);
                l1.borrar(j);
            }else{
                j++;
                elem = l2.recuperar(j);
            }
        }
    }
}

void AlgListaIndex::eliminarDos(listaInd &l1, listaInd &l2){
    if(!l2.vacia() && !l1.vacia()){
        int j = 0;
        int elem = l1.recuperar(j);
        while(j < l1.numElem()){
            if(this->buscar(elem, l2)){
                elem = l1.recuperar(j+1);
                l1.borrar(j);
            }else{
                j++;
                elem = l2.recuperar(j);
            }
        }
    }
}

void AlgListaIndex::llenarLista(ifstream& archivo, listaInd &l){
    int entObt;
    //ifstream archivoEnterosEntrada("dodecaedro.txt", ios::in);
    char finLinea = ' ';
    int posicion = 0;
 
    /*if (!archivoEnterosEntrada) { // operador ! sobrecargado
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        exit(1);
    }*/
    
    archivo >> entObt;
    archivo.get();
    finLinea = archivo.peek();
    while (!archivo.eof() &&(finLinea != 10)) {
        l.insertar(entObt, posicion);
        archivo >> entObt;
        archivo.get(); // consume un blanco
        finLinea = archivo.peek(); // intenta leer fin de línea
        posicion++;
    }
    l.insertar(entObt, posicion);    
}