/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Isaac
 *
 * Created on 8 de mayo de 2018, 12:20 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Pila.h"
#include "ListaIndArr.h"
#include "ListaIndEn.h"
//#include "ListaIndArr.h"
//#include "ListaOrdArr.h"
//#include "ListaOrdEn.h"
//#include "ListaPosArr.h"
//#include "ListaPosDoEn.h"
//#include "ListaPosSimEn.h"
using namespace std;

typedef ListaIndEn<int> Lista;
//typedef ListaIndArr<int> Lista;
/*
 * 
 */
int main(int argc, char** argv) {
    
    /*Pila<int> pila;
    pila.iniciar();
    pila.meter(4);
    pila->meter(34);
    pila->meter(23);
    int e = pila->sacar();
    int i = pila->numElem();
    cout << i << endl;
    cout << e << endl;
    pila->destruir();*/
    
    Lista lista;
    lista.iniciar();
    for(int i = 0; i < 4; i++)
        lista.insertar(i*2, i);
    Lista lista2;
    lista2.iniciar();
    lista2.insertar(45,0);
    lista2 = lista;
    bool reset = true;
    string poliedro = "";
    while (reset) {
        for(int i = 0; i < 4; i++)
            cout << lista2.recuperar(i) << endl;
            do {
                cout << "Desea Volver a Jugar. Si o No" << endl;
                cin >> poliedro;
            } while (poliedro != "Si" && poliedro != "No");
            if (poliedro == "Si")
                reset = true;
            else
                reset = false;
    }
    lista.destruir();
    lista2.destruir();
    return 0;
}

