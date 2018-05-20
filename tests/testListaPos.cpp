/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testListaPos.cpp
 * Author: Javier
 *
 * Created on 13 de mayo de 2018, 06:25 PM
 */

#include <stdlib.h>
#include <iostream>

//#include "ListaPosDoEn.h"
//#include "ListaPosSimEn.h"
#include "ListaPosArr.h"
 
/*
 * Simple C++ Test Suite
 */

//typedef ListaPosDoEn<int> Lista;
//typedef ListaPosDoEn<int>::Pos Position;

//typedef ListaPosSimEn<int> Lista;
//typedef ListaPosSimEn<int>::Pos Position;

typedef ListaPosArr<int> Lista;
typedef ListaPosArr<int>::Pos Position;


void testIniciar() {
    Lista lista;
    lista.iniciar();
    if (lista.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testIniciar (testListaPos) No inició la lista vacía" << std::endl;
    }
}

void testDestruir() {
    if(true){
        Lista lista;
        lista.iniciar();
        for(int i = 0; i < 4; i++){
            lista.agregarAlFinal(i);
        }
        lista.destruir();
    }
    Lista lista;
    lista.iniciar();
    if (!lista.vacia()) {
        std::cout << "%TEST_FAILED% time=0 testname=testDestruir (testListaPos) message=error No destruyó la lista" << std::endl;
    }
}

void testVaciar() {
    Lista lista;
    lista.iniciar();
    for(int i = 0; i < 4; i++){
        lista.agregarAlFinal(i);
    }
    lista.vaciar();
    if (lista.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaPos) No vació la lista" << std::endl;
    }
}

void testVacia() {
    Lista lista;
    lista.iniciar();
    bool result = lista.vacia();
    if (result == false ) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaPos) No reconoce si la lista está vacía" << std::endl;
    }
    for(int i = 0; i < 4; i++){
        lista.agregarAlFinal(i);
    }
    result = lista.vacia();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaPos) si la lista tiene elementos" << std::endl;
    }
    
    lista.destruir();
}

void testInsertar() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    int result = lista.recuperar(inicio);
    if (result != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaPos) No inserta al inicio" << std::endl;
    }
    
    lista.insertar(1, inicio);
    inicio = lista.primera();
    result = lista.recuperar(inicio);
    if (result != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaPos) No inserta en el medio" << std::endl;
    }
    
    Position sig = lista.siguiente(inicio);
    result = lista.recuperar(sig);
    if (result != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaPos) No inserta al inicio" << std::endl;
    }
    
    lista.destruir();
}

void testAgregarAlFinal() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    lista.agregarAlFinal(1);
    Position inicio = lista.primera();
    Position siguiente = lista.siguiente(inicio);
    int result = lista.recuperar(inicio);
    if (result != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregarAlFinal (testListaPos) No agrega al final" << std::endl;
    }
    
    result = lista.recuperar(siguiente);
    if (result != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregarAlFinal (testListaPos) No agrega al final" << std::endl;
    }
    
    lista.destruir();
}

void testBorrar() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    lista.insertar(1, inicio);
    inicio = lista.primera();
    Position segundo = lista.siguiente(inicio);
    lista.insertar(2, segundo);
    lista.borrar(segundo);
    lista.agregarAlFinal(23);
    segundo = lista.siguiente(inicio);
    Position tercero = lista.siguiente(segundo);
    if (lista.recuperar(tercero) != 23) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaPos) No elimina en el medio" << std::endl;
    }
    lista.borrar(tercero);
    Position ultimo = lista.ultima();
    if (lista.recuperar(ultimo) != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaPos) No elimina al final" << std::endl;
    }
    
    lista.borrar(segundo);
    lista.borrar(inicio);
    if (lista.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaPos) No elimina el primero" << std::endl;
    }
    
    lista.destruir();
}

void testRecuperar() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    lista.insertar(1, inicio);
    inicio = lista.primera();
    Position segundo = lista.siguiente(inicio);
    lista.insertar(2, segundo);
    segundo = lista.siguiente(inicio);
    Position tercero = lista.siguiente(segundo);
    int i = lista.recuperar(inicio);
    if (i != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaPos) No recuperó el primero" << std::endl;
    }
    i = lista.recuperar(segundo);
    if (i != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaPos) No recuperó el segundo" << std::endl;
    }
    i = lista.recuperar(tercero);
    if (i != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaPos) No recuperó el tercero" << std::endl;
    }
    lista.destruir();
}

void testModificarElemento() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    lista.insertar(1, inicio);
    inicio = lista.primera();
    Position segundo = lista.siguiente(inicio);
    lista.insertar(2, segundo);
    segundo = lista.siguiente(inicio);
    Position tercero = lista.siguiente(segundo);  
    lista.modificarElemento(3, inicio);
    int i = lista.recuperar(inicio);
    if (i != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaPos) No modificó el primero" << std::endl;
    }
    lista.modificarElemento(4, segundo);
    i = lista.recuperar(segundo);
    if (i != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaPos) No modificó el segundo" << std::endl;
    }
    lista.modificarElemento(5,tercero);
    i = lista.recuperar(tercero);
    if (i != 5) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaPos) No modificó el tercero" << std::endl;
    }
    lista.destruir();
}

void testIntercambiar() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    lista.insertar(1, inicio);
    inicio = lista.primera();
    Position segundo = lista.siguiente(inicio);
    lista.intercambiar(inicio, segundo);
    int i = lista.recuperar(inicio);
    int j = lista.recuperar(segundo);
    if ( i != 0 ) {
        std::cout << "%TEST_FAILED% time=0 testname=testIntercambiar (testListaPos) No intercambió bien el primero" << std::endl;
    }
    if (j != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testIntercambiar (testListaPos) No intercambió bien el segundo" << std::endl;
    }
    lista.destruir();
}

void testPrimera() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    int i = lista.recuperar(inicio);
    if (i != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrimera (testListaPos) No devuelve el puntero al primero" << std::endl;
    }
    lista.destruir();
}

void testUltima() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(1);
    Position inicio = lista.primera();
    lista.insertar(0, inicio);
    Position result = lista.ultima();
    int j = lista.recuperar(result);
    if (j != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testUltima (testListaPos) No devuelve el puntero al último" << std::endl;
    }
    lista.destruir();
}

void testSiguiente() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    lista.insertar(1, inicio);
    inicio = lista.primera();
    inicio = lista.siguiente(inicio);
    int j = lista.recuperar(inicio);
    if (j != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testSiguiente (testListaPos) No devuelve el puntero al siguiente" << std::endl;
    }
    lista.destruir();
}

void testAnterior() {
    Lista lista;
    lista.iniciar();
    lista.agregarAlFinal(0);
    Position inicio = lista.primera();
    lista.insertar(1, inicio);
    inicio = lista.primera();
    Position segundo = lista.siguiente(inicio);
    lista.insertar(2, segundo);
    segundo = lista.siguiente(inicio);
    Position result = lista.anterior(segundo);
    int j = lista.recuperar(result);
    if (j != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testAnterior (testListaPos) No devuelve el puntero al anterior" << std::endl;
    }
    lista.destruir();
}

void testNumElem() {
    Lista lista;
    lista.iniciar();
    for(int i = 0; i<4; i++){
        lista.agregarAlFinal(i);
        int result = lista.numElem();
        if (result != i+1) {
            std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaPos) No reconoce que hay "<< i << " elementos"<< std::endl;
        }
    }
    lista.destruir();
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% testListaPos" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testIniciar (testListaPos)" << std::endl;
    testIniciar();
    std::cout << "%TEST_FINISHED% time=0 testIniciar (testListaPos)" << std::endl;   
    
    std::cout << "%TEST_STARTED% testDestruir (testListaPos)" << std::endl;
    testDestruir();
    std::cout << "%TEST_FINISHED% time=0 testDestruir (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testVaciar (testListaPos)" << std::endl;
    testVaciar();
    std::cout << "%TEST_FINISHED% time=0 testVaciar (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testVacia (testListaPos)" << std::endl;
    testVacia();
    std::cout << "%TEST_FINISHED% time=0 testVacia (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertar (testListaPos)" << std::endl;
    testInsertar();
    std::cout << "%TEST_FINISHED% time=0 testInsertar (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testAgregarAlFinal (testListaPos)" << std::endl;
    testAgregarAlFinal();
    std::cout << "%TEST_FINISHED% time=0 testAgregarAlFinal (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testBorrar (testListaPos)" << std::endl;
    testBorrar();
    std::cout << "%TEST_FINISHED% time=0 testBorrar (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testRecuperar (testListaPos)" << std::endl;
    testRecuperar();
    std::cout << "%TEST_FINISHED% time=0 testRecuperar (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testModificarElemento (testListaPos)" << std::endl;
    testModificarElemento();
    std::cout << "%TEST_FINISHED% time=0 testModificarElemento (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testIntercambiar (testListaPos)" << std::endl;
    testIntercambiar();
    std::cout << "%TEST_FINISHED% time=0 testIntercambiar (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testPrimera (testListaPos)" << std::endl;
    testPrimera();
    std::cout << "%TEST_FINISHED% time=0 testPrimera (testListaPos)" << std::endl;
    
    std::cout << "%TEST_STARTED% testUltima (testListaPos)" << std::endl;
    testUltima();
    std::cout << "%TEST_FINISHED% time=0 testUltima (testListaPos)" << std::endl; 

    std::cout << "%TEST_STARTED% testSiguiente (testListaPos)" << std::endl;
    testSiguiente();
    std::cout << "%TEST_FINISHED% time=0 testSiguiente (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testAnterior (testListaPos)" << std::endl;
    testAnterior();
    std::cout << "%TEST_FINISHED% time=0 testAnterior (testListaPos)" << std::endl;

    std::cout << "%TEST_STARTED% testNumElem (testListaPos)" << std::endl;
    testNumElem();
    std::cout << "%TEST_FINISHED% time=0 testNumElem (testListaPos)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

