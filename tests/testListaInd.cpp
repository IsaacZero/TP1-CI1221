/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testListaInd.cpp
 * Author: Javier
 *
 * Created on 13 de mayo de 2018, 06:23 PM
 */

#include <stdlib.h>
#include <iostream>

//#include "ListaIndArr.h"
#include "listaIndEn.h"

//typedef ListaIndArr<int> Lista;
typedef ListaIndEn<int> Lista;

/*
 * Simple C++ Test Suite
*/ 

void testIniciar() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    if (listaIndArr.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testIniciar (testListaIndArr) No inició la lista vacía" << std::endl;
    }
}

void testDestruir() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    listaIndArr.destruir();
    
    listaIndArr.iniciar();
    if (listaIndArr.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testDestruir (testListaIndArr) No destruyó la lista" << std::endl;
    }
}

void testVaciar() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    listaIndArr.vaciar();
    if (listaIndArr.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaIndArr) No vació la lista" << std::endl;
    }
}

void testVacia() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    bool result = listaIndArr.vacia();
    if (result == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaIndArr) No reconoce si la lista está vacía" << std::endl;
    }
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    result = listaIndArr.vacia();
    if (result ==  true) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaIndArr) No reconoce si la lista tiene elementos" << std::endl;
    }
}

void testInsertar() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    for(int i = 0; i < 4; i++){
        if (listaIndArr.recuperar(i) != i) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaIndArr) No reconoce insertó bien el elemento "<< i << std::endl;
        }
    }
    
}

void testBorrar() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    listaIndArr.borrar(1);
    if (listaIndArr.recuperar(1) == 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaIndArr) No eliminó bien el elemento en el segundo lugar" << std::endl;
    }
}

void testRecuperar() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    int result = listaIndArr.recuperar(2);
    if (result != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaIndArr) No recupero el 3er elemento de la lista" << std::endl;
    }
}

void testModificarElemento() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    listaIndArr.modificarElemento(7, 2);
    if (listaIndArr.recuperar(2) != 7) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaIndArr) No modifico el 3er elemento de la lista" << std::endl;
    }
}

void testIntercambiar() {
    int i;
    int j;
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);
    }
    listaIndArr.intercambiar(1,2);
    if (listaIndArr.recuperar(2) != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testIntercambiar (testListaIndArr) No intercambió el valor en el 3er elemento" << std::endl;
    }
    if (listaIndArr.recuperar(1) != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testIntercambiar (testListaIndArr) No intercambió el valor en el 2do elemento" << std::endl;
    }
}

void testNumElem() {
    Lista listaIndArr;
    listaIndArr.iniciar();
    for(int i = 0; i < 4; i++){
        listaIndArr.insertar(i,i);        
        if (listaIndArr.numElem() != i+1) {
            std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaIndArr) No cuenta hasta el elemento" << i+1 << std::endl;
        }
    }
    
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% testListaIndArr" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    
    std::cout << "%TEST_STARTED% testIniciar (testListaIndArr)" << std::endl;
    testIniciar();
    std::cout << "%TEST_FINISHED% time=0 testIniciar (testListaIndArr)" << std::endl;
    
    std::cout << "%TEST_STARTED% testDestruir (testListaIndArr)" << std::endl;
    testDestruir();
    std::cout << "%TEST_FINISHED% time=0 testDestruir (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testVaciar (testListaIndArr)" << std::endl;
    testVaciar();
    std::cout << "%TEST_FINISHED% time=0 testVaciar (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testVacia (testListaIndArr)" << std::endl;
    testVacia();
    std::cout << "%TEST_FINISHED% time=0 testVacia (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertar (testListaIndArr)" << std::endl;
    testInsertar();
    std::cout << "%TEST_FINISHED% time=0 testInsertar (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testBorrar (testListaIndArr)" << std::endl;
    testBorrar();
    std::cout << "%TEST_FINISHED% time=0 testBorrar (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testRecuperar (testListaIndArr)" << std::endl;
    testRecuperar();
    std::cout << "%TEST_FINISHED% time=0 testRecuperar (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testModificarElemento (testListaIndArr)" << std::endl;
    testModificarElemento();
    std::cout << "%TEST_FINISHED% time=0 testModificarElemento (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testIntercambiar (testListaIndArr)" << std::endl;
    testIntercambiar();
    std::cout << "%TEST_FINISHED% time=0 testIntercambiar (testListaIndArr)" << std::endl;

    std::cout << "%TEST_STARTED% testNumElem (testListaIndArr)" << std::endl;
    testNumElem();
    std::cout << "%TEST_FINISHED% time=0 testNumElem (testListaIndArr)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}