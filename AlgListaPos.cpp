/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlgListaPos.cpp
 * Author: Arnoldo
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
void AlgListaPos::burbuja(listaPos listaPos1){
    int largo = listaPos1.numElem();
    int contFaltantes = largo - 1;
    for(int i = 0; i < largo; i++){
        Position iter1 = listaPos1.primera();
        Position iter2 = listaPos1.siguiente(iter1);
        for(int j = contFaltantes; j > 0; j--){
            if(listaPos1.recuperar(iter1) <listaPos1.recuperar(iter2)){
                listaPos1.intercambiar(iter1,iter2);
            }
            iter1 = iter2;
            iter2 = listaPos1.siguiente(iter1);
        }
        contFaltantes--;
    }
}

void AlgListaPos::burbujaBidireccional(listaPos listaPos1){
    int largo = listaPos1.numElem();
    int contFaltantes = largo - 1;
    bool haciaElFondo = true;
    Position iter1 = listaPos1.primera();
    Position iter2 = listaPos1.siguiente(iter1);
    for(int i = 0; i < largo; i++){
        if(haciaElFondo == true){
            for(int j = contFaltantes; j > 0; j--){
                if(listaPos1.recuperar(iter1) > listaPos1.recuperar(iter2)){
                    listaPos1.intercambiar(iter1,iter2);
                }
                if(j != 1){
                    iter1 = iter2;
                    iter2 = listaPos1.siguiente(iter1);
                }else{
                    iter2 = iter1;
                    iter1 = listaPos1.anterior(iter1);
                }
            }
            haciaElFondo = false;
        }else{
            for(int j = contFaltantes; j > 0; j--){
                if(listaPos1.recuperar(iter1) > listaPos1.recuperar(iter2)){
                    listaPos1.intercambiar(iter1,iter2);
                }
                if(j == 1){
                    iter1 = iter2;
                    iter2 = listaPos1.siguiente(iter1);
                }else{
                    iter2 = iter1;
                    iter1 = listaPos1.anterior(iter1);
                }
            }
            haciaElFondo = true;
        }
        contFaltantes--;
    }
}

bool AlgListaPos::buscar(listaPos listaPos1, int elem) {
    bool existe = false;
    Position iter = listaPos1.primera();
    Position fin = listaPos1.ultima();
    while ((existe == false) && (iter != listaPos1.siguiente(fin))){
        if(listaPos1.recuperar(iter) == elem){
            existe ==true;
        }else{
            iter = listaPos1.siguiente(iter);
        }
    }
    return existe;
}
void AlgListaPos::eliminarRepetidos(listaPos listaPos1){
    Position iter1 = listaPos1.primera();
    Position fin = listaPos1.ultima();
    while (iter1 != fin){
        Position iter2 = listaPos1.siguiente(iter1);
        while (iter2 != listaPos1.siguiente(fin)){
            if ((listaPos1.recuperar(iter2) == listaPos1.recuperar(iter1)) && (iter2 == fin)){
                listaPos1.borrar(iter2);
                fin = listaPos1.ultima();
            }else if(listaPos1.recuperar(iter2) == listaPos1.recuperar(iter1)){
                listaPos1.borrar(iter2);
            }
            else{
                iter2 = listaPos1.siguiente(iter2);
            } 
        }
        iter1 = listaPos1.siguiente(iter1);
    }
}

void AlgListaPos::eliminarElementosListaConOrden(listaPos listaPos1, listaPos listaPos2){
    bool estaInterseccion = false;
    Position iter1 = listaPos1.primera();
    Position iter2 = listaPos2.primera();
    int largo1 = listaPos1.numElem();
    int largo2 = listaPos2.numElem();
    int i = 0;
    int j = 0;
    while((i<largo1)&&(j<largo2)){
        if(listaPos1.recuperar(iter1) == listaPos2.recuperar(iter2)){
            Position aux = listaPos1.siguiente(iter1);
            listaPos1.borrar(iter1);
            largo1--;
            iter1 = aux;
            iter2 = listaPos2.siguiente(iter2);
            j++;
        }else if(listaPos1.recuperar(iter1) > listaPos2.recuperar(iter2) ){
            iter2 = listaPos2.siguiente(iter2);
            j++;
        }else{
            iter1 = listaPos1.siguiente(iter1);
            i++;
        }
    }
}

void AlgListaPos::eliminarElementosListaSinOrden(listaPos listaPos1, listaPos listaPos2){
    bool estaInterseccion = false;
    Position iter2 = listaPos2.primera();
    int largo1 = listaPos1.numElem();
    int largo2 = listaPos2.numElem();
    int i = 0;
    int j = 0;
    while((listaPos1.vacia() == false) && ( j < largo2 )){
        int i = 0;
        Position iter1 = listaPos1.primera();
        bool eliminar = false;
        while((i < largo1)&&(eliminar == false)){
            if(listaPos1.recuperar(iter1) == listaPos2.recuperar(iter2)){
                eliminar = true;
            }else{
                iter1= listaPos1.siguiente(iter1);
                i++;
            }
        }
        j++;
        iter2 = listaPos2.siguiente(iter2);
    }
}

bool AlgListaPos::iguales(listaPos listaPos1,listaPos listaPos2){
    bool iguales = true;
    int largo1 = listaPos1.numElem();
    if(largo1 != listaPos2.numElem()){
        iguales = false;
    }else if (largo1 > 0){
        Position iter1 = listaPos1.primera();
        Position fin1 = listaPos1.ultima();
        Position iter2 = listaPos2.primera();
        Position fin2 = listaPos2.ultima();
        int i = 0;
        while((i<largo1)&&(iguales == true)){
            if(listaPos1.recuperar(iter1) != listaPos2.recuperar(iter2)){
                iguales = false;
            }
            else{
                iter1 = listaPos1.siguiente(iter1);
                iter2 = listaPos2.siguiente(iter2);
            }
        }
    }
    return iguales;
}

void AlgListaPos::insercion(listaPos listaPos1){
    int largo = listaPos1.numElem();
    Position actual = listaPos1.primera();
        
    for(int i = 1; i <= largo; i++){
        int j = i-1;
        bool bienPuesto = false;
        if(j > 0){
            Position iter1 = actual;
            Position iter2 = listaPos1.anterior(iter1);
            do{
                if(listaPos1.recuperar(iter2) > listaPos1.recuperar(iter1)){
                    listaPos1.intercambiar(iter1,iter2);
                    iter1 = iter2;
                    iter2 = listaPos1.anterior(iter2);
                    j--;
                }else{
                    bienPuesto=true;
                }
                if(j == 0){
                    bienPuesto=true;
                }
            }while((j>0) && (bienPuesto == false));                        
        }
        actual = listaPos1.siguiente(actual);
    }
}

void AlgListaPos::interseccionConOrden(listaPos listaPos1, listaPos listaPos2, listaPos listaPos3){
    bool estaInterseccion = false;
    Position iter1 = listaPos1.primera();
    
    Position iter2 = listaPos2.primera();
    
    int largo1 = listaPos1.numElem();
    int largo2 = listaPos2.numElem();
    if(largo1 <= largo2){
        for(int i = 0; i < largo1; i++){
            int j = 0;
            while( (j<largo2) && (estaInterseccion == false)){
                if(listaPos2.recuperar(iter2) == listaPos1.recuperar(iter1)){
                    estaInterseccion = true;
                    listaPos3.agregarAlFinal(listaPos2.recuperar(iter2));
                }
                iter2 = listaPos2.siguiente(iter2);
            }
            iter1 = listaPos1.siguiente(iter1);
        }
    }else{
        for(int i = 0; i < largo2; i++){
            int j = 0;
            while( (j<largo1) && (estaInterseccion == false)){
                if(listaPos1.recuperar(iter1) == listaPos2.recuperar(iter2)){
                    estaInterseccion = true;
                    listaPos3.agregarAlFinal(listaPos2.recuperar(iter1));
                }
                iter1 = listaPos1.siguiente(iter1);
            }
            iter2 = listaPos2.siguiente(iter2);
        }
    }
}

void AlgListaPos::interseccionSinOrden(listaPos listaPos1, listaPos listaPos2, listaPos listaPos3){
    bool estaInterseccion = false;
    Position iter1 = listaPos1.primera();
    Position fin1 = listaPos1.ultima();
    Position iter2 = listaPos2.primera();
    Position fin2 = listaPos2.ultima();
    int largo1 = listaPos1.numElem();
    int largo2 = listaPos2.numElem();
    if(largo1 <= largo2){
        for(int i = 0; i < largo1; i++){
            int j = 0;
            while( (j<largo2) && (estaInterseccion == false)){
                if(listaPos2.recuperar(iter2) == listaPos1.recuperar(iter1)){
                    estaInterseccion = true;
                    listaPos3.agregarAlFinal(listaPos2.recuperar(iter2));
                }
                iter2 = listaPos2.siguiente(iter2);
            }
            iter1 = listaPos1.siguiente(iter1);
        }
    }else{
        for(int i = 0; i < largo2; i++){
            int j = 0;
            while( (j<largo1) && (estaInterseccion == false)){
                if(listaPos1.recuperar(iter1) == listaPos2.recuperar(iter2)){
                    estaInterseccion = true;
                    listaPos3.agregarAlFinal(listaPos2.recuperar(iter1));
                }
                iter1 = listaPos1.siguiente(iter1);
            }
            iter2 = listaPos2.siguiente(iter2);
        }
    }
}

void AlgListaPos::invertirLista(listaPos listaPos1){
    Position iter = listaPos1.primera();
    int largo = listaPos1.numElem();
    int aux[largo];
    for(int i = largo-1; i >= 0; i--){
        aux[i] = listaPos1.recuperar(iter);
    }
    listaPos1.vaciar();
    for(int i = 0; i < largo; i++){
        listaPos1.agregarAlFinal(aux[i]); 
    }
}

string AlgListaPos::listar(listaPos listaPos1){
    string listaString = "";
    if(listaPos1.vacia() == true){
        listaString = "La lista está vacía";
    }else{
        Position iter = listaPos1.primera();
        Position fin = listaPos1.ultima();
        listaString = "La lista tiene como elementos: \n";
        while (iter != fin){
            listaString += "-> " + std::to_string(listaPos1.recuperar(iter)) + " \n";
            iter = listaPos1.siguiente(iter);
        }
    }
    return listaString;
}

void AlgListaPos::selecccionIterativa(listaPos listaPos1){
    int largo = listaPos1.numElem();
    Position actual = listaPos1.primera();
    for(int i = 0; i < largo; i++){
        Position iter = listaPos1.siguiente(actual);
        Position masPeque = actual;
        for(int j = i+1; j < largo; j++){
            if(listaPos1.recuperar(iter) < listaPos1.recuperar(masPeque)){
                masPeque = iter;
            }
            iter = listaPos1.siguiente(iter);
        }
        if(masPeque != actual){
            listaPos1.intercambiar(masPeque,actual);
        }
        actual = listaPos1.siguiente(actual);
    }
}

void AlgListaPos::selecccionIterativaRecComp(listaPos listaPos1){
    int largo = listaPos1.numElem();
    Position actual = listaPos1.primera();
    Position iter = listaPos1.siguiente(actual);
    Position masPeque = actual;
    for(int j = 1; j < largo; j++){
        if(listaPos1.recuperar(iter) < listaPos1.recuperar(masPeque)){
            masPeque = iter;
        }
        iter = listaPos1.siguiente(iter);
    }
    if(masPeque != actual){
            listaPos1.intercambiar(masPeque,actual);
    }
    actual = listaPos1.siguiente(actual);
    selecccionIterativaRecCompR( listaPos1, actual,largo-1);
}
    
void AlgListaPos::selecccionIterativaRecCompR(listaPos listaPos1,Position actual,int faltantes){
    if(faltantes == 0){
        Position iter = listaPos1.siguiente(actual);
        Position masPeque = actual;
        for(int j = 1; j < faltantes; j++){
            if(listaPos1.recuperar(iter) < listaPos1.recuperar(masPeque)){
                masPeque = iter;
            }
            iter = listaPos1.siguiente(iter);
        }if(masPeque != actual){
            listaPos1.intercambiar(masPeque,actual);
        }
        actual = listaPos1.siguiente(actual);
        selecccionIterativaRecCompR( listaPos1, actual,faltantes-1);
    }
}
    


bool AlgListaPos::simetrica(listaPos listaPos1){
    bool esSimetrica = true;
    Position punteroIzq = listaPos1.primera();
    Position punteroDer = listaPos1.ultima();
    while((punteroIzq != punteroDer)&&(listaPos1.siguiente(punteroDer) != punteroIzq)&&(esSimetrica == true)){
        if(listaPos1.recuperar(punteroIzq) != listaPos1.recuperar(punteroDer)){
            esSimetrica = false;
        }else{
            punteroIzq = listaPos1.siguiente(punteroIzq);
            punteroDer = listaPos1.anterior(punteroDer);
        }
    }
    return esSimetrica;
}

bool AlgListaPos::subLista(listaPos listaPos1,listaPos listaPos2){
    bool esSubLista = false;
    Position iter1 = listaPos1.primera();
    Position fin1 = listaPos1.ultima();
    Position iter2 = listaPos2.primera();
    Position fin2 = listaPos2.ultima();
    while ((iter2 != listaPos2.siguiente(fin2))&&(esSubLista == false)){
        if(listaPos2.recuperar(iter2) == listaPos1.recuperar(iter1)){
            if(iter1 == fin1){
                esSubLista = true;
            }else{
                iter1 = listaPos1.siguiente(iter1);
            }
        }else if(iter1 != listaPos1.primera()){
            iter1 == listaPos1.primera();
        }
        iter2 = listaPos2.siguiente(iter2);    
    }
    return esSubLista;
}

void AlgListaPos::unionConOrden(listaPos listaPos1,listaPos listaPos2){
    Position iter1 = listaPos1.primera();
    Position fin1 = listaPos1.ultima();
    Position iter2 = listaPos2.primera();
    Position fin2 = listaPos2.ultima();
    while (iter2 != listaPos2.siguiente(fin2)){
        if(iter1 == listaPos1.siguiente(fin1)){
            listaPos1.agregarAlFinal(listaPos2.recuperar(iter2));
            iter2 = listaPos2.siguiente(iter2);
        }else if(listaPos1.recuperar(iter1) < listaPos2.recuperar(iter2)){
            listaPos1.insertar(listaPos2.recuperar(iter2),iter1);
            iter1 = listaPos1.siguiente(iter1);
            iter2 = listaPos2.siguiente(iter2);
        }else{
            iter1 = listaPos1.siguiente(iter1);
        }
    }
}

void AlgListaPos::unionSinOrden(listaPos listaPos1,listaPos listaPos2){
    Position iter1 = listaPos1.primera();
    Position fin1 = listaPos1.ultima();
    Position iter2 = listaPos2.primera();
    Position fin2 = listaPos2.ultima();
    int largo1 = listaPos1.numElem();
    while (iter2 != listaPos2.siguiente(fin2)){
        bool existe = false;
        int i = 0;
        while ((i < largo1)&&(existe == false)){
            Position iter3 = listaPos1.primera();
            if(listaPos1.recuperar(iter3) == listaPos2.recuperar(iter2)){
                existe = true;
            }
            iter3 = listaPos1.siguiente(iter3);
            i++;
        }
        if(existe == true){
            if(iter1 == listaPos1.siguiente(fin1)){
                listaPos1.agregarAlFinal(listaPos2.recuperar(iter2));
                iter2 = listaPos2.siguiente(iter2);
            }else if(listaPos1.recuperar(iter1) < listaPos2.recuperar(iter2)){
                listaPos1.insertar(listaPos2.recuperar(iter2),iter1);
                iter1 = listaPos1.siguiente(iter1);
                iter2 = listaPos2.siguiente(iter2);
            }else{
                iter1 = listaPos1.siguiente(iter1);
            }
        }else{
            iter2 = listaPos2.siguiente(iter2);
        }
    }
}