/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testListaOrd.cpp
 * Author: Isaac
 *
 * Created on 13 de mayo de 2018, 01:41 PM
 */

#include <stdlib.h>
#include <iostream>
#include "ListaOrdArr.h"
//#include "ListaOrdEn.h"

typedef ListaOrdArr<int> Lista;
//typedef ListaOrdEn<int> Lista;
/*
 * Simple C++ Test Suite
 */

void testIniciar() {
    Lista lista;
    lista.iniciar();
    if (!lista.vacia() /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testIniciar (testListaOrd) message=El operador basico inicir() o vacia() fallo" << std::endl;
    }
}

void testDestruir() {
    if(true){
        Lista lista;
        lista.iniciar();
        lista.agregar(30);
        lista.agregar(90);
        lista.agregar(27);
        lista.destruir();
    }
    Lista lista;
    lista.iniciar();
    if (!lista.vacia() /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDestruir (testListaOrd) message=El operador destruir() o vacia() no funciono correctamente" << std::endl;
    }
}

void testVaciar() {
    Lista lista;
    lista.iniciar();
    lista.vaciar();
    if (!lista.vacia() /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaOrd) message=El operador vaciar() fallo en la ejecución" << std::endl;
    }
    
    lista.agregar(10);
    lista.agregar(20);
    if (lista.vacia() /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaOrd) message=El operador vaciar() fallo en la ejecución" << std::endl;
    }
    
    lista.borrar(10);
    if (lista.vacia() /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaOrd) message=El operador vaciar() fallo en la ejecución" << std::endl;
    }
    
    lista.vaciar();
    if (!lista.vacia() /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaOrd) message=El operador vaciar() fallo en la ejecución" << std::endl;
    }
}

void testVacia() {
    Lista lista;
    lista.iniciar();
    bool result = lista.vacia();
    if (!result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaOrd) message=El operador vacia() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(30);
    lista.agregar(17);
    result = lista.vacia();
    if (result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaOrd) message=El operador vacia() o agregar() no funciono correctamente" << std::endl;
    }
    
    lista.borrar(30);
    result = lista.vacia();
    if (result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaOrd) message=El operador vacia() o borrar() o agregar() no funciono correctamente" << std::endl;
    }
    
    lista.borrar(17);
    result = lista.vacia();
    if (!result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaOrd) message=El operador vacia() o borrar() o agregar() no funciono correctamente" << std::endl;
    }
    lista.destruir();
}

void testAgregar() {
    int newE = 10;
    Lista lista;
    lista.iniciar();
    lista.agregar(newE);
    if (lista.numElem() != 1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregar (testListaOrd) message=El operador basico agregar() fallo en su ejecución" << std::endl;
    }
    
    lista.agregar(30);
    if (lista.numElem() != 2 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregar (testListaOrd) message=El operador basico agregar() fallo en su ejecución" << std::endl;
    }
    
    lista.agregar(2);
    if (lista.numElem() != 3 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregar (testListaOrd) message=El operador basico agregar() fallo en su ejecución" << std::endl;
    }
    lista.destruir();
}

void testBorrar() {
    int elem = 20;
    Lista lista;
    lista.iniciar();
    lista.agregar(elem);
    lista.borrar(elem);
    if (lista.numElem() != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaOrd) message=El operador borrar() fallo" << std::endl;
    }
    
    lista.agregar(elem);
    lista.agregar(10);
    lista.agregar(3);
    lista.borrar(elem);
    if (lista.numElem() != 2 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaOrd) message=El operador borrar() fallo" << std::endl;
    }
    
    lista.borrar(10);
    if (lista.numElem() != 1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaOrd) message=El operador borrar() fallo" << std::endl;
    }
    
    lista.borrar(3);
    if (lista.numElem() != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaOrd) message=El operador borrar() fallo" << std::endl;
    }
    lista.destruir();
}

void testPrimero() {
    Lista lista;
    lista.iniciar();
    int result = lista.primero();
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrimero (testListaOrd) message=El operador basico primero() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(4);
    result = lista.primero();
    if (result != 4 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrimero (testListaOrd) message=El operador basico primero() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(5);
    result = lista.primero();
    if (result != 4 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrimero (testListaOrd) message=El operador basico primero() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(1);
    result = lista.primero();
    if (result != 1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrimero (testListaOrd) message=El operador basico primero() no funciono correctamente" << std::endl;
    }
    lista.destruir();
}

void testUltimo() {
    Lista lista;
    lista.iniciar();
    int result = lista.ultimo();
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testUltimo (testListaOrd) message=El operador ultimo() fallo" << std::endl;
    }
    
    lista.agregar(3);
    result = lista.ultimo();
    if (result != 3 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testUltimo (testListaOrd) message=El operador ultimo() fallo" << std::endl;
    }
    
    lista.agregar(5);
    result = lista.ultimo();
    if (result != 5 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testUltimo (testListaOrd) message=El operador ultimo() fallo" << std::endl;
    }
    
    lista.agregar(1);
    result = lista.ultimo();
    if (result != 5 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testUltimo (testListaOrd) message=El operador ultimo() fallo" << std::endl;
    }
    lista.destruir();
}

void testSiguiente() {
    int elem = 30;
    Lista lista;
    lista.iniciar();
    lista.agregar(elem);
    int result = lista.siguiente(elem);
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSiguiente (testListaOrd) message=El operador básico siguiente() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(27);
    result = lista.siguiente(elem);
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSiguiente (testListaOrd) message=El operador básico siguiente() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(50);
    result = lista.siguiente(elem);
    if (result != 50 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSiguiente (testListaOrd) message=El operador básico siguiente() no funciono correctamente" << std::endl;
    }
    lista.destruir();
}

void testAnterior() {
    int elem = 30;
    Lista lista;
    lista.iniciar();
    lista.agregar(elem);
    int result = lista.anterior(elem);
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAnterior (testListaOrd) message=El operador anterior() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(27);
    result = lista.anterior(elem);
    if (result != 27 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAnterior (testListaOrd) message=El operador anterior() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(40);
    result = lista.anterior(40);
    if (result != elem /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAnterior (testListaOrd) message=El operador anterior() no funciono correctamente" << std::endl;
    }
    lista.destruir();
}

void testNumElem() {
    Lista lista;
    lista.iniciar();
    int result = lista.numElem();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaOrd) message=El Operador básico numElem() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(4);
    result = lista.numElem();
    if (result != 1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaOrd) message=El Operador básico numElem() no funciono correctamente" << std::endl;
    }
    
    lista.agregar(23);
    lista.agregar(30);
    result = lista.numElem();
    if (result != 3 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaOrd) message=El Operador básico numElem() no funciono correctamente" << std::endl;
    }
    
    lista.borrar(23);
    result = lista.numElem();
    if (result != 2 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaOrd) message=El Operador básico numElem() no funciono correctamente" << std::endl;
    }
    
    lista.vaciar();
    result = lista.numElem();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaOrd) message=El Operador básico numElem() no funciono correctamente" << std::endl;
    }
    lista.destruir();
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% testListaOrd" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testIniciar (testListaOrd)" << std::endl;
    testIniciar();
    std::cout << "%TEST_FINISHED% time=0 testIniciar (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testDestruir (testListaOrd)" << std::endl;
    testDestruir();
    std::cout << "%TEST_FINISHED% time=0 testDestruir (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testVaciar (testListaOrd)" << std::endl;
    testVaciar();
    std::cout << "%TEST_FINISHED% time=0 testVaciar (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testVacia (testListaOrd)" << std::endl;
    testVacia();
    std::cout << "%TEST_FINISHED% time=0 testVacia (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testAgregar (testListaOrd)" << std::endl;
    testAgregar();
    std::cout << "%TEST_FINISHED% time=0 testAgregar (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testBorrar (testListaOrd)" << std::endl;
    testBorrar();
    std::cout << "%TEST_FINISHED% time=0 testBorrar (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testPrimero (testListaOrd)" << std::endl;
    testPrimero();
    std::cout << "%TEST_FINISHED% time=0 testPrimero (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testUltimo (testListaOrd)" << std::endl;
    testUltimo();
    std::cout << "%TEST_FINISHED% time=0 testUltimo (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testSiguiente (testListaOrd)" << std::endl;
    testSiguiente();
    std::cout << "%TEST_FINISHED% time=0 testSiguiente (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testAnterior (testListaOrd)" << std::endl;
    testAnterior();
    std::cout << "%TEST_FINISHED% time=0 testAnterior (testListaOrd)" << std::endl;

    std::cout << "%TEST_STARTED% testNumElem (testListaOrd)" << std::endl;
    testNumElem();
    std::cout << "%TEST_FINISHED% time=0 testNumElem (testListaOrd)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

