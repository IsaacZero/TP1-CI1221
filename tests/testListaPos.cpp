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
#include "ListaPosSimEn.h"
//#include "ListaPosArr.h"
 
/*
 * Simple C++ Test Suite
 */

//typedef ListaPosDoEn<int> Lista;
//typedef ListaPosDoEn<int>::Pos Position;

typedef ListaPosSimEn<int> Lista;
typedef ListaPosSimEn<int>::Pos Position;

//typedef ListaPosArr<int> Lista;
//typedef ListaPosArr<int>::Pos Position;


void testIniciar() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    if (listaPosDoEn.vacia() == false) {
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
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    for(int i = 0; i < 4; i++){
        listaPosDoEn.agregarAlFinal(i);
    }
    listaPosDoEn.vaciar();
    if (listaPosDoEn.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testVaciar (testListaPos) No vació la lista" << std::endl;
    }
}

void testVacia() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    bool result = listaPosDoEn.vacia();
    if (result == false ) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaPos) No reconoce si la lista está vacía" << std::endl;
    }
    for(int i = 0; i < 4; i++){
        listaPosDoEn.agregarAlFinal(i);
    }
    result = listaPosDoEn.vacia();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVacia (testListaPos) si la lista tiene elementos" << std::endl;
    }
    
}

void testInsertar() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    listaPosDoEn.agregarAlFinal(0);
    Position inicio = listaPosDoEn.primera();
    int result = listaPosDoEn.recuperar(inicio);
    if (result != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaPos) No inserta al inicio" << std::endl;
    }
    
    listaPosDoEn.insertar(1, inicio);
    inicio = listaPosDoEn.primera();
    result = listaPosDoEn.recuperar(inicio);
    if (result != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaPos) No inserta en el medio" << std::endl;
    }
    
    Position sig = listaPosDoEn.siguiente(inicio);
    result = listaPosDoEn.recuperar(sig);
    if (result != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertar (testListaPos) No inserta al inicio" << std::endl;
    }
}

void testAgregarAlFinal() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    listaPosDoEn.agregarAlFinal(0);
    listaPosDoEn.agregarAlFinal(1);
    Position inicio = listaPosDoEn.primera();
    Position siguiente = listaPosDoEn.siguiente(inicio);
    int result = listaPosDoEn.recuperar(inicio);
    if (result != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregarAlFinal (testListaPos) No agrega al final" << std::endl;
    }
    
    result = listaPosDoEn.recuperar(siguiente);
    if (result != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgregarAlFinal (testListaPos) No agrega al final" << std::endl;
    }
}

void testBorrar() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    listaPosDoEn.agregarAlFinal(0);
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(1, inicio);
    inicio = listaPosDoEn.primera();
    Position segundo = listaPosDoEn.siguiente(inicio);
    listaPosDoEn.insertar(2, segundo);
    listaPosDoEn.borrar(segundo);
    listaPosDoEn.agregarAlFinal(23);
    segundo = listaPosDoEn.siguiente(inicio);
    Position tercero = listaPosDoEn.siguiente(segundo);
    if (listaPosDoEn.recuperar(tercero) != 23) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaPos) No elimina en el medio" << std::endl;
    }
    listaPosDoEn.borrar(tercero);
    Position ultimo = listaPosDoEn.ultima();
    if (listaPosDoEn.recuperar(ultimo) != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaPos) No elimina al final" << std::endl;
    }
    
    listaPosDoEn.borrar(segundo);
    listaPosDoEn.borrar(inicio);
    if (listaPosDoEn.vacia() == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testBorrar (testListaPos) No elimina el primero" << std::endl;
    }
}

void testRecuperar() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    Position segundo = listaPosDoEn.siguiente(inicio);
    listaPosDoEn.insertar(1, segundo);
    Position tercero = listaPosDoEn.siguiente(segundo);
    listaPosDoEn.insertar(2, tercero);
    int i = listaPosDoEn.recuperar(inicio);
    if (i != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaPos) No recuperó el primero" << std::endl;
    }
    i = listaPosDoEn.recuperar(segundo);
    if (i != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaPos) No recuperó el segundo" << std::endl;
    }
    i = listaPosDoEn.recuperar(tercero);
    if (i != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testRecuperar (testListaPos) No recuperó el tercero" << std::endl;
    }
}

void testModificarElemento() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    Position segundo = listaPosDoEn.siguiente(inicio);
    listaPosDoEn.insertar(1, segundo);
    Position tercero = listaPosDoEn.siguiente(segundo);
    listaPosDoEn.insertar(2, tercero);    
    listaPosDoEn.modificarElemento(3, inicio);
    int i = listaPosDoEn.recuperar(inicio);
    if (i != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaPos) No modificó el primero" << std::endl;
    }
    listaPosDoEn.modificarElemento(4, segundo);
    i = listaPosDoEn.recuperar(segundo);
    if (i != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaPos) No modificó el segundo" << std::endl;
    }
    listaPosDoEn.modificarElemento(5,tercero);
    i = listaPosDoEn.recuperar(tercero);
    if (i != 5) {
        std::cout << "%TEST_FAILED% time=0 testname=testModificarElemento (testListaPos) No modificó el tercero" << std::endl;
    }
}

void testIntercambiar() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    Position segundo = listaPosDoEn.siguiente(inicio);
    listaPosDoEn.insertar(1, segundo);
    listaPosDoEn.intercambiar(inicio, segundo);
    int i = listaPosDoEn.recuperar(inicio);
    int j = listaPosDoEn.recuperar(segundo);
    if ( i != 1 ) {
        std::cout << "%TEST_FAILED% time=0 testname=testIntercambiar (testListaPos) No intercambió bien el primero" << std::endl;
    }
    if (j != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testIntercambiar (testListaPos) No intercambió bien el segundo" << std::endl;
    }
}

void testPrimera() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    int i = listaPosDoEn.recuperar(inicio);
    if (i != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testPrimera (testListaPos) No devuelve el puntero al primero" << std::endl;
    }
}

void testUltima() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    listaPosDoEn.agregarAlFinal(1);
    Position result = listaPosDoEn.ultima();
    int j = listaPosDoEn.recuperar(result);
    if (j != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testUltima (testListaPos) No devuelve el puntero al último" << std::endl;
    }
}

void testSiguiente() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    Position segundo = listaPosDoEn.siguiente(inicio);
    listaPosDoEn.insertar(1, segundo);
    int j = listaPosDoEn.recuperar(inicio);
    if (j != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testSiguiente (testListaPos) No devuelve el puntero al siguiente" << std::endl;
    }
}

void testAnterior() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position inicio = listaPosDoEn.primera();
    listaPosDoEn.insertar(0, inicio);
    Position segundo = listaPosDoEn.siguiente(inicio);
    listaPosDoEn.insertar(1, segundo);
    Position result = listaPosDoEn.anterior(segundo);
    int j = listaPosDoEn.recuperar(result);
    if (j != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testAnterior (testListaPos) No devuelve el puntero al anterior" << std::endl;
    }
}

void testNumElem() {
    Lista listaPosDoEn;
    listaPosDoEn.iniciar();
    Position siguiente = listaPosDoEn.primera();
    for(int i = 0; i<4; i++){
        listaPosDoEn.insertar(i, siguiente);
        siguiente = listaPosDoEn.siguiente(siguiente); 
        int result = listaPosDoEn.numElem();
        if (result != i+1) {
            std::cout << "%TEST_FAILED% time=0 testname=testNumElem (testListaPos) No reconoce que hay "<< i << " elementos"<< std::endl;
        }
    }
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

