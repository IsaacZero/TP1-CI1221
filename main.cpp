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
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Pila<int> pila;
    pila.iniciar();
    pila.meter(4);
    pila.meter(34);
    pila.meter(23);
    int e = pila.sacar();
    int i = pila.numElem();
    cout << i << endl;
    cout << e << endl;    
    return 0;
}

