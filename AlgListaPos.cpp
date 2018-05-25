/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaPos.cpp
 * Author: Isaac
 * 
 * Created on 19 de mayo de 2018, 08:35 PM
 */

#include "AlgListaPos.h"

AlgListaPos::AlgListaPos() {
}

AlgListaPos::AlgListaPos(const AlgListaPos& orig) {
}

AlgListaPos::~AlgListaPos() {
}

bool AlgListaPos::buscar(Lista listaPos, Elemento elem) {
    bool existe = false;
    Position iter = listaPos.primera();
    Position fin = listaPos.ultima();
    while ((existe == false) && (iter != listaPos.siguiente(fin))){
        if(listaPos.recuperar(iter) == elem){
            existe ==true;
        }else{
            iter = listaPos.siguiente(iter);
        }
    }
    return existe;
}
void AlgListaPos::eliminarRepetidos(Lista listaPos){
    Position iter1 = listaPos.primera();
    Position fin = listaPos.ultima();
    while (iter1 != fin){
        Position iter2 = listaPos.siguiente(iter1);
        while (iter2 != listaPos.siguiente(fin)){
            if ((listaPos.recuperar(iter2) == listaPos.recuperar(iter1)) && (iter2 == fin)){
                listaPos.borrar(iter2);
                fin = listaPos.ultima();
            }else if(listaPos.recuperar(iter2) == listaPos.recuperar(iter1)){
                listaPos.borrar(iter2);
            }
            else{
                iter2 = listaPos.siguiente(iter2);
            } 
        }
        iter1 = listaPos.siguiente(iter1);
    }
}

void AlgListaPos::invertir(Lista listaPos){
    Position iter = listaPos.primera();
    int largo = listaPos.numElem();
    Elemento aux[largo];
    for(int i = largo-1; i >= 0; i--){
        aux[i] = listaPos.recuperar(iter);
    }
    listaPos.vaciar();
    for(int i = 0; i < largo; i++){
        listaPos.agregarAlFinal(aux[i]); 
    }
}

string AlgListaPos::listar(Lista listaPos){
    string listaString = "";
    if(listaPos.vacia() == true){
        listaString = "La lista está vacía";
    }else{
        Position iter = listaPos.primera();
        Position fin = listaPos.ultima();
        listaString = "La lista tiene como elementos: \n";
        while (iter != fin){
            listaString += "->";
            listaString += std::to_string(listaPos.recuperar(iter));
            listaString += "\n";
            iter = listaPos.siguiente(iter);
        }
    }
    return listaString;
}

bool AlgListaPos::simetrica(Lista listaPos){
    bool esSimetrica = true;
    Position punteroIzq = listaPos.primera();
    Position punteroDer = listaPos.ultima();
    while((punteroIzq != punteroDer)&&(listaPos.siguiente(punteroDer) != punteroIzq)&&(esSimetrica == true)){
        if(listaPos.recuperar(punteroIzq) != listaPos.recuperar(punteroDer)){
            esSimetrica = false;
        }else{
            punteroIzq = listaPos.siguiente(punteroIzq);
            punteroDer = listaPos.anterior(punteroDer);
        }
    }
    return esSimetrica;
}

bool AlgListaPos::subLista(Lista listaPos1,Lista listaPos2){
    bool esSubLista = false;
    Position iter1 = listaPos1.primera();
    Position fin1 = listaPos1.ultima();
    Position iter2 = listaPos2.primera();
    Position fin2 = listaPos2.ultima();
    while (iter2 != fin2){
        //if(listaPos2.recuperar(iter1) == )
    }
    return esSubLista;
}