/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tertPila.cpp
 * Author: Isaac
 *
 * Created on 13 de mayo de 2018, 04:03 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Pila.h"

/*
 * Simple C++ Test Suite
 */

void testIniciar() {
    Pila<int> pila;
    pila.iniciar();
    if (pila.numElem() != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testIniciar (tertPila) message=El operador iniciar() o numElem() no funciono correctamente" << std::endl;
    }
}

void testDestruir() {
    if(true){
        Pila<int> pila;
        pila.iniciar();
        pila.meter(40);
        pila.meter(10);
        pila.meter(15);
        pila.destruir();
    }
    Pila<int> pila;
    pila.iniciar();
    if (pila.numElem() != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDestruir (tertPila) message=El Operador destruir() fallo" << std::endl;
    }
}

void testVaciar() {
    Pila<int> pila;
    pila.iniciar();
    pila.meter(15);
    pila.meter(10);
    pila.meter(23);
    pila.vaciar();
    if (pila.numElem() != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (tertPila) message=El operador vaciar() fallo en la ejecución" << std::endl;
    }
}

void testVacia() {
    Pila<int> pila;
    pila.iniciar();
    bool result = pila.vacia();
    if (!result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (tertPila) message=El operador vacia() no funciono correctamente" << std::endl;
    }
    
    pila.meter(45);
    pila.meter(20);
    result = pila.vacia();
    if (result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (tertPila) message=El operador vacia() no funciono correctamente" << std::endl;
    }
    
    pila.sacar();
    result = pila.vacia();
    if (result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (tertPila) message=El operador vacia() no funciono correctamente" << std::endl;
    }
    
    pila.vaciar();
    result = pila.vacia();
    if (!result /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (tertPila) message=El operador vacia() no funciono correctamente" << std::endl;
    }
    pila.destruir();
}

void testMeter() {
    int elemento = 27;
    Pila<int> pila;
    pila.iniciar();
    pila.meter(elemento);
    if (pila.vacia() || pila.numElem() != 1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testMeter (tertPila) message=El operador meter() fallo" << std::endl;
    }
    
    pila.meter(17);
    pila.meter(30);
    if (pila.vacia() || pila.numElem() != 3/*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testMeter (tertPila) message=El operador meter() fallo" << std::endl;
    }
    pila.destruir();
}

void testSacar() {
    Pila<int> pila;
    pila.iniciar();
    int result = pila.sacar();
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSacar (tertPila) message= El operador sacar() no funciono correctamente" << std::endl;
    }
    
    pila.meter(30);
    result = pila.sacar();
    if (result != 30 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSacar (tertPila) message= El operador sacar() no funciono correctamente" << std::endl;
    }
    
    pila.meter(40);
    pila.meter(45);
    pila.meter(10);
    result = pila.sacar();
    if (result != 10 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSacar (tertPila) message= El operador sacar() no funciono correctamente" << std::endl;
    }
    
    result = pila.sacar();
    if (result != 45 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSacar (tertPila) message= El operador sacar() no funciono correctamente" << std::endl;
    }
    pila.destruir();
}

void testTope() {
    Pila<int> pila;
    pila.iniciar();
    int result = pila.tope();
    if (result != -1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testTope (tertPila) message=El operador tope() fallo en la ejecucion" << std::endl;
    }
    
    pila.meter(23);
    result = pila.tope();
    if (result != 23 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSacar (tertPila) message= El operador sacar() no funciono correctamente" << std::endl;
    }
    
    pila.meter(12);
    pila.meter(67);
    result = pila.tope();
    if (result != 67 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSacar (tertPila) message= El operador sacar() no funciono correctamente" << std::endl;
    }
    pila.destruir();
}

void testNumElem() {
    Pila<int> pila;
    pila.iniciar();
    int result = pila.numElem();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (tertPila) message=El operador numElem() fallo en la ejecucion" << std::endl;
    }
    
    pila.meter(12);
    result = pila.numElem();
    if (result != 1 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (tertPila) message=El operador numElem() fallo en la ejecucion" << std::endl;
    }
    
    pila.meter(43);
    pila.meter(53);
    result = pila.numElem();
    if (result != 3 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (tertPila) message=El operador numElem() fallo en la ejecucion" << std::endl;
    }
    
    result = pila.sacar();
    result = pila.numElem();
    if (result != 2 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (tertPila) message=El operador numElem() fallo en la ejecucion" << std::endl;
    }
    
    pila.vaciar();
    result = pila.numElem();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNumElem (tertPila) message=El operador numElem() fallo en la ejecucion" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% tertPila" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testIniciar (tertPila)" << std::endl;
    testIniciar();
    std::cout << "%TEST_FINISHED% time=0 testIniciar (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testDestruir (tertPila)" << std::endl;
    testDestruir();
    std::cout << "%TEST_FINISHED% time=0 testDestruir (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testVaciar (tertPila)" << std::endl;
    testVaciar();
    std::cout << "%TEST_FINISHED% time=0 testVaciar (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testVacia (tertPila)" << std::endl;
    testVacia();
    std::cout << "%TEST_FINISHED% time=0 testVacia (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testMeter (tertPila)" << std::endl;
    testMeter();
    std::cout << "%TEST_FINISHED% time=0 testMeter (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testSacar (tertPila)" << std::endl;
    testSacar();
    std::cout << "%TEST_FINISHED% time=0 testSacar (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testTope (tertPila)" << std::endl;
    testTope();
    std::cout << "%TEST_FINISHED% time=0 testTope (tertPila)" << std::endl;

    std::cout << "%TEST_STARTED% testNumElem (tertPila)" << std::endl;
    testNumElem();
    std::cout << "%TEST_FINISHED% time=0 testNumElem (tertPila)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

