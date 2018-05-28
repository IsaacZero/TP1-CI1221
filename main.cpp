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
#include "AlgListaIndex.h"
#include "AlgListaOrd.h"
#include "AlgListaPos.h"


#include "ListaIndArr.h"
typedef ListaIndArr<int> listaInd;

//#include "ListaIndEn.h"
//typedef ListaIndEn<int> listaInd;


#include "ListaOrdArr.h"
typedef ListaOrdArr<int> listaOrd;

//#include "ListaOrdEn.h"
//typedef ListaOrdEn<int> listaOrd;


#include "ListaPosArr.h"
typedef ListaPosArr<int> listaPos;

//#include "ListaPosDoEn.h"
//typedef ListaPosDoEn<int> listaPos;

//#include "ListaPosSimEn.h"
//typedef ListaPosSimEn<int> listaPos;

using namespace std;

typedef AlgListaIndex algIndex;
typedef AlgListaOrd algOrd;
typedef AlgListaPos algPos;

typedef listaPos::Pos pos;

/*
 * 
 */
int main(int argc, char** argv) {

    int desicion;
    bool continuar = true;
    while (continuar) {
        cout << "MENU DE OPCIONES\n" << endl;
        cout << "¿Cuales algoritmos desea usar?\n (Ingrese un numero)" << endl;
        cout << "1. Algoritmos Lista Posicionada." << endl;
        cout << "2. Algoritmos Lista Indexada." << endl;
        cout << "3. Algoritmos Lista Ordenada." << endl;
        cout << "0. Salir" << endl;
        cin >> desicion;
        switch (desicion) {
            case 1:
            {
                int desicion2;
                bool continuar2 = true;
                listaPos L1;
                listaPos L2;
                listaPos L3;
                algPos algoritmos;
                ifstream archivo;
                while (continuar2) {
                    bool continuar3 = true;
                    cout << "CREACION DE LISTAS PREDEFINIDAS" << endl;
                    cout << "Escoger dos de las listas." << endl;
                    cout << "Puede escoger la misma 2 veces" << endl;
                    cout << "1. Lista Uno." << endl;
                    cout << "2. Lista Dos." << endl;
                    cout << "3. Lista Tres." << endl;
                    cout << "4. Lista Cuatro." << endl;
                    cout << "0. Salir." << endl;
                    cout << "Las Listas Predefinidas pueden ser cambiadas entrando al archivo en la carpeta del documento." << endl;
                    cin >> desicion2;
                    switch (desicion2) {
                        case 1:
                        {
                            archivo.open("ListaUno.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 2:
                        {
                            archivo.open("ListaDos.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 3:
                        {
                            archivo.open("ListaTres.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 4:
                        {
                            archivo.open("ListaCuatro.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 0:
                        {
                            continuar2 = false;
                            continuar3 = false;
                        }
                            break;
                        default:
                        {
                            cout << "Ingrese un numero valido." << endl;
                        }
                    }
                    cout << "1. Lista Uno." << endl;
                    cout << "2. Lista Dos." << endl;
                    cout << "3. Lista Tres." << endl;
                    cout << "4. Lista Cuatro." << endl;
                    cout << "0. Salir." << endl;
                    cin >> desicion2;
                    switch (desicion2) {
                        case 1:
                        {
                            archivo.open("ListaUno.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 2:
                        {
                            archivo.open("ListaDos.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 3:
                        {
                            archivo.open("ListaTres.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 4:
                        {
                            archivo.open("ListaCuatro.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 0:
                        {
                            continuar2 = false;
                            continuar3 = false;
                        }
                            break;
                        default:
                        {
                            cout << "Ingrese un numero valido." << endl;
                        }
                    }
                    while (continuar3) {
                        cout << "ALGORITMOS DISPONIBLES" << endl;
                        cout << "Escoja el algoritmo que desea aplicar" << endl;
                        cout << "1. Listar." << endl;
                        cout << "2. Simetrica." << endl;
                        cout << "3. Invertir." << endl;
                        cout << "4. Buscar." << endl;
                        cout << "5. Eliminar Elementos Repetidos de una Lista." << endl;
                        cout << "6. Sublista." << endl;
                        cout << "7. Iguales." << endl;
                        cout << "8. Burbuja Original." << endl;
                        cout << "9. Burbuja Bidireccional." << endl;
                        cout << "10. Seleccion Iterativa." << endl;
                        cout << "11. Seleccion Recursiva con pila del compilador." << endl;
                        cout << "12. Sleccion Recursiva con pila creada." << endl;
                        cout << "13. Insercion." << endl;
                        cout << "14. QuickSort Aho." << endl;
                        cout << "15. QuickSort sin Aho." << endl; //XD
                        cout << "16. MergeSort." << endl;
                        cout << "17. Union primer tipo." << endl;
                        cout << "18. Union segundo tipo." << endl;
                        cout << "19. Interseccion primer tipo." << endl;
                        cout << "20. Interseccion segundo tipo." << endl;
                        cout << "21. Eliminar primer tipo." << endl;
                        cout << "22. Eliminar segundo tipo." << endl;
                        cout << "0. Salir." << endl;
                        cin >> desicion;
                                                    
                        switch (desicion) {
                            
                            case 1:
                            {
                                string lista = "";
                                do {
                                    cout << "¿Cual lista desea listar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        lista = algoritmos.listar(L1);
                                    else if (desicion == 2)
                                        lista = algoritmos.listar(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << lista << endl;
                            }
                                break;
                            case 2:
                            {
                                bool sim;
                                do {
                                    cout << "¿Cual lista desea investigar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        sim = algoritmos.simetrica(L1);
                                    else if (desicion == 2)
                                        sim = algoritmos.simetrica(L2);
                                } while (desicion != 1 && desicion != 2);
                                if (sim)
                                    cout << "La Lista es simetrica." << endl;
                                else
                                    cout << "La Lista NO es simetrica." << endl;
                            }
                                break;
                            case 3:
                            {
                                do {
                                    cout << "¿Cual lista desea invertir? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.invertirLista(L1);
                                    else if (desicion == 2)
                                        algoritmos.invertirLista(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "La lista termino de invertirse." << endl;
                            }
                                break;
                            case 4:
                            {
                                bool found;
                                int des = 0;
                                do {
                                    cout << "¿En cual lista desea buscar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1) {
                                        cout << "Inserte el número que desea buscar. Recuerde insertar solo números enteros." << endl;
                                        cin >> des;
                                        found = algoritmos.buscar( L1,des);
                                    } else if (desicion == 2) {
                                        cout << "Inserte el número que desea buscar. Recuerde insertar solo números enteros." << endl;
                                        cin >> des;
                                        found = algoritmos.buscar(L2,des);
                                    }
                                } while (desicion != 1 && desicion != 2);
                                if (found)
                                    cout << "El elemento se encuentra en la lista." << endl;
                                else
                                    cout << "El elemento NO se encuentra en la lista." << endl;
                            }
                                break;
                            case 5:
                            {
                                do {
                                    cout << "¿Cual Lista desea eliminar los repetidos? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.eliminarRepetidos(L1);
                                    else if (desicion == 2)
                                        algoritmos.eliminarRepetidos(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Ya se eliminaron los repetidos." << endl;
                            }
                                break;
                            case 6:
                            {
                                bool esSublista;
                                do {
                                    cout << "¿Cual Lista desea averiguar si es sublista? \n Digite 1 para la primera en la segunda \n "
                                            "2 para la segunda en la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        esSublista = algoritmos.subLista(L1, L2);
                                    else if (desicion == 2)
                                        esSublista = algoritmos.subLista(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                if (esSublista)
                                    cout << "La lista esta contenida en la otra lista." << endl;
                                else
                                    cout << "La lista NO esta contenida en la otra lista." << endl;
                            }
                                break;
                            case 7:
                            {
                                bool igual = algoritmos.iguales(L1, L2);
                                if (igual)
                                    cout << "Las listas son iguales." << endl;
                                else {
                                    cout << "Las listas NO son iguales." << endl;
                                }
                            }
                                break;
                            case 8:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Burbuja? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.burbuja(L1);
                                    else if (desicion == 2)
                                        algoritmos.burbuja(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 9:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Burbuja Bidireccional? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.burbujaBidireccional(L1);
                                    else if (desicion == 2)
                                        algoritmos.burbujaBidireccional(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 10:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Seleccion Iterativa? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.selecccionIterativa(L1);
                                    else if (desicion == 2)
                                        algoritmos.selecccionIterativa(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 11:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Seleccion Recursiva por el compilador? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1){
                                        
                                        algoritmos.selecccionIterativaRecComp(L1);
                                    }else if (desicion == 2){
                                        algoritmos.selecccionIterativaRecComp(L2);
                                    }
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 12:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Seleccion Recursiva con pila creada? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.selecccionIterativaRecPila(L1);
                                    else if (desicion == 2)
                                        algoritmos.selecccionIterativaRecPila(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 13:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Insercion? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.insercion(L1);
                                    else if (desicion == 2)
                                        algoritmos.insercion(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                            case 14:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Quick Sort Aho? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.quickSortAho(L1);
                                    else if (desicion == 2)
                                        algoritmos.quickSortAho(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 15:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Quick Sort sin Aho? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1){
                                        int decision4;
                                        cout << "¿Cual desea que sea el mínimo para que use Quicksort? \n Digite el numero." << endl;
                                        cin >> decision4;
                                        
                                        algoritmos.quickSortN(L1,decision4);
                                    }else if (desicion == 2){
                                        int decision4;
                                        cout << "¿Cual desea que sea el mínimo para que use Quicksort? \n Digite el numero." << endl;
                                        cin >> decision4;
                                        algoritmos.quickSortN(L2,decision4);
                                    }
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 16:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Merge Sort? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.mergeSort(L1);
                                    else if (desicion == 2)
                                        algoritmos.mergeSort(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 17:
                            {
                                do {
                                    cout << "¿Cual Lista desea unir a la otra? \n Digite 1 para la primera a la segunda \n "
                                            "2 para la segunda a la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.unionConOrden(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.unionConOrden(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se finalizo el agregado de los elementos." << endl;
                            }
                                break;
                            case 18:
                            {
                                do {
                                    cout << "¿Cual Lista desea unir a la otra? \n Digite 1 para la primera a la segunda \n "
                                            "2 para la segunda a la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.unionSinOrden(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.unionSinOrden(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se finalizo el agregado de los elementos." << endl;
                            }
                                break;
                            case 19:
                            {
                                int des = 0;
                                L3.iniciar();
                                algoritmos.interseccionConOrden(L1, L2, L3);
                                cout << "La Lista L3 se ha llenado. ¿Desea listarla? \n Digite 1 para SI, 2 para No." << endl;
                                cin >> des;
                                string lista = "";
                                if (des == 1)
                                    lista = algoritmos.listar(L3);
                                cout << "La lista es:" << endl;
                                cout << lista << endl;
                            }
                                break;
                            case 20:
                            {
                                int des = 0;
                                L3.iniciar();
                                algoritmos.interseccionSinOrden(L1, L2,L3);
                                cout << "La Lista L3 se ha llenado. ¿Desea listarla? \n Digite 1 para SI, 2 para No." << endl;
                                cin >> des;
                                string lista = "";
                                if (des == 1)
                                    lista = algoritmos.listar(L3);
                                cout << "La lista es:" << endl;
                                cout << lista << endl;
                            }
                                break;
                            case 21:
                            {
                                algoritmos.eliminarElementosListaConOrden(L1, L2);
                                cout << "Se eliminaron los elementos iguales." << endl;
                            }
                                break;
                            case 22:
                            {
                                algoritmos.eliminarElementosListaSinOrden(L1, L2);
                                cout << "Se eliminaron los elementos iguales." << endl;
                            }
                                break;
                            case 0:
                            {
                                continuar3 = false;
                                L1.vaciar();
                                L2.vaciar();
                                L3.vaciar();
                            }
                                break;
                            default:
                            {
                                cout << "Ingrese un numero valido." << endl;
                            }
                        }
                    }
                }
                L1.destruir();
                L2.destruir();
                L3.destruir();
            }
                //archivo.open("dodecaedro.txt", ios::in);
                break;
            case 2:
            { //Lista INDEXADA
                int desicion2;
                bool continuar2 = true;
                listaInd L1;
                listaInd L2;
                listaInd L3;
                L1.iniciar();
                L2.iniciar();
                L3.iniciar();
                algIndex algoritmos;
                ifstream archivo;
                while (continuar2) {
                    bool continuar3 = true;
                    cout << "CREACION DE LISTAS PREDEFINIDAS" << endl;
                    cout << "Escoger dos de las listas." << endl;
                    cout << "Puede escoger la misma 2 veces" << endl;
                    cout << "1. Lista Uno." << endl;
                    cout << "2. Lista Dos." << endl;
                    cout << "3. Lista Tres." << endl;
                    cout << "4. Lista Cuatro." << endl;
                    cout << "0. Salir." << endl;
                    cout << "Las Listas Predefinidas pueden ser cambiadas entrando al archivo en la carpeta del documento." << endl;
                    cin >> desicion2;
                    switch (desicion2) {
                        case 1:
                        {
                            archivo.open("ListaUno.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 2:
                        {
                            archivo.open("ListaDos.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 3:
                        {
                            archivo.open("ListaTres.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 4:
                        {
                            archivo.open("ListaCuatro.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 0:
                        {
                            continuar2 = false;
                            continuar3 = false;
                        }
                            break;
                        default:
                        {
                            cout << "Ingrese un numero valido." << endl;
                        }
                    }
                    cout << "1. Lista Uno." << endl;
                    cout << "2. Lista Dos." << endl;
                    cout << "3. Lista Tres." << endl;
                    cout << "4. Lista Cuatro." << endl;
                    cout << "0. Salir." << endl;
                    cin >> desicion2;
                    switch (desicion2) {
                        case 1:
                        {
                            archivo.open("ListaUno.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 2:
                        {
                            archivo.open("ListaDos.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 3:
                        {
                            archivo.open("ListaTres.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 4:
                        {
                            archivo.open("ListaCuatro.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 0:
                        {
                            continuar2 = false;
                            continuar3 = false;
                        }
                            break;
                        default:
                        {
                            cout << "Ingrese un numero valido." << endl;
                        }
                    }
                    while (continuar3) {
                        cout << "ALGORITMOS DISPONIBLES" << endl;
                        cout << "Escoja el algoritmo que desea aplicar" << endl;
                        cout << "1. Listar." << endl;
                        cout << "2. Simetrica." << endl;
                        cout << "3. Invertir." << endl;
                        cout << "4. Buscar." << endl;
                        cout << "5. Eliminar Elementos Repetidos de una Lista." << endl;
                        cout << "6. Sublista." << endl;
                        cout << "7. Iguales." << endl;
                        cout << "8. Burbuja Original." << endl;
                        cout << "9. Burbuja Bidireccional." << endl;
                        cout << "10. Seleccion Iterativa." << endl;
                        cout << "11. Seleccion Recursiva con pila del compilador." << endl;
                        cout << "12. Sleccion Recursiva con pila creada." << endl;
                        cout << "13. Insercion." << endl;
                        cout << "14. QuickSort Aho." << endl;
                        cout << "15. QuickSort sin Aho." << endl; //XD
                        cout << "16. MergeSort." << endl;
                        cout << "17. Union primer tipo." << endl;
                        cout << "18. Union segundo tipo." << endl;
                        cout << "19. Interseccion primer tipo." << endl;
                        cout << "20. Interseccion segundo tipo." << endl;
                        cout << "21. Eliminar primer tipo." << endl;
                        cout << "22. Eliminar segundo tipo." << endl;
                        cout << "0. Salir." << endl;
                        cin >> desicion;
                        switch (desicion) {
                            case 1:
                            {
                                string lista = "";
                                do {
                                    cout << "¿Cual lista desea listar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        lista = algoritmos.listar(L1);
                                    else if (desicion == 2)
                                        lista = algoritmos.listar(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << lista << endl;
                            }
                                break;
                            case 2:
                            {
                                bool sim;
                                do {
                                    cout << "¿Cual lista desea investigar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        sim = algoritmos.simetrica(L1);
                                    else if (desicion == 2)
                                        sim = algoritmos.simetrica(L2);
                                } while (desicion != 1 && desicion != 2);
                                if (sim)
                                    cout << "La Lista es simetrica." << endl;
                                else
                                    cout << "La Lista NO es simetrica." << endl;
                            }
                                break;
                            case 3:
                            {
                                do {
                                    cout << "¿Cual lista desea invertir? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.invertir(L1);
                                    else if (desicion == 2)
                                        algoritmos.invertir(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "La lista termino de invertirse." << endl;
                            }
                                break;
                            case 4:
                            {
                                bool found;
                                int des = 0;
                                do {
                                    cout << "¿En cual lista desea buscar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1) {
                                        cout << "Inserte el número que desea buscar. Recuerde insertar solo números enteros." << endl;
                                        cin >> des;
                                        found = algoritmos.buscar(des, L1);
                                    } else if (desicion == 2) {
                                        cout << "Inserte el número que desea buscar. Recuerde insertar solo números enteros." << endl;
                                        cin >> des;
                                        found = algoritmos.buscar(des, L2);
                                    }
                                } while (desicion != 1 && desicion != 2);
                                if (found)
                                    cout << "El elemento se encuentra en la lista." << endl;
                                else
                                    cout << "El elemento NO se encuentra en la lista." << endl;
                            }
                                break;
                            case 5:
                            {
                                do {
                                    cout << "¿Cual Lista desea eliminar los repetidos? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.eliminarRep(L1);
                                    else if (desicion == 2)
                                        algoritmos.eliminarRep(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Ya se eliminaron los repetidos." << endl;
                            }
                                break;
                            case 6:
                            {
                                bool esSublista;
                                do {
                                    cout << "¿Cual Lista desea averiguar si es sublista? \n Digite 1 para la primera en la segunda \n "
                                            "2 para la segunda en la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        esSublista = algoritmos.sublista(L1, L2);
                                    else if (desicion == 2)
                                        esSublista = algoritmos.sublista(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                if (esSublista)
                                    cout << "La lista esta contenida en la otra lista." << endl;
                                else
                                    cout << "La lista NO esta contenida en la otra lista." << endl;
                            }
                                break;
                            case 7:
                            {
                                bool igual = algoritmos.iguales(L1, L2);
                                if (igual)
                                    cout << "Las listas son iguales." << endl;
                                else {
                                    cout << "Las listas NO son iguales." << endl;
                                }
                            }
                                break;
                            case 8:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Burbuja? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.burbujaOri(L1);
                                    else if (desicion == 2)
                                        algoritmos.burbujaOri(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 9:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Burbuja Bidireccional? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.burbujaBi(L1);
                                    else if (desicion == 2)
                                        algoritmos.burbujaBi(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 10:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Seleccion Iterativa? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.seleccionIter(L1);
                                    else if (desicion == 2)
                                        algoritmos.seleccionIter(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 11:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Seleccion Recursiva por el compilador? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.seleccionRecUno(L1, L1.recuperar(0), 0);
                                    else if (desicion == 2)
                                        algoritmos.seleccionRecUno(L2, L2.recuperar(0), 0);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 12:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Seleccion Recursiva con pila creada? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.seleccionRecDos(L1);
                                    else if (desicion == 2)
                                        algoritmos.seleccionRecDos(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 13:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Insercion? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.insercion(L1);
                                    else if (desicion == 2)
                                        algoritmos.insercion(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                            case 14:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Quick Sort Aho? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.quickSort(L1, 1);
                                    else if (desicion == 2)
                                        algoritmos.quickSort(L2, 1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 15:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Quick Sort sin Aho? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.quickSort(L1, 2);
                                    else if (desicion == 2)
                                        algoritmos.quickSort(L2, 2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 16:
                            {
                                do {
                                    cout << "¿Cual Lista desea aplicar Merge Sort? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.mergeSort(L1);
                                    else if (desicion == 2)
                                        algoritmos.mergeSort(L2);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de ordenar la lista." << endl;
                            }
                                break;
                            case 17:
                            {
                                do {
                                    cout << "¿Cual Lista desea unir a la otra? \n Digite 1 para la primera a la segunda \n "
                                            "2 para la segunda a la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.unionUno(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.unionUno(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se finalizo el agregado de los elementos." << endl;
                            }
                                break;
                            case 18:
                            {
                                do {
                                    cout << "¿Cual Lista desea unir a la otra? \n Digite 1 para la primera a la segunda \n "
                                            "2 para la segunda a la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.unionDos(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.unionDos(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se finalizo el agregado de los elementos." << endl;
                            }
                                break;
                            case 19:
                            {
                                int des = 0;
                                L3 = algoritmos.interseccionUno(L1, L2);
                                cout << "La Lista L3 se ha llenado. ¿Desea listarla? \n Digite 1 para SI, 2 para No." << endl;
                                cin >> des;
                                string lista = "";
                                if (des == 1)
                                    lista = algoritmos.listar(L3);
                                cout << "La lista es:" << endl;
                                cout << lista << endl;
                            }
                                break;
                            case 20:
                            {
                                int des = 0;
                                L3 = algoritmos.interseccionUno(L1, L2);
                                cout << "La Lista L3 se ha llenado. ¿Desea listarla? \n Digite 1 para SI, 2 para No." << endl;
                                cin >> des;
                                string lista = "";
                                if (des == 1)
                                    lista = algoritmos.listar(L3);
                                cout << "La lista es:" << endl;
                                cout << lista << endl;
                            }
                                break;
                            case 21:
                            {
                                algoritmos.eliminarUno(L1, L2);
                                cout << "Se eliminaron los elementos iguales." << endl;
                            }
                                break;
                            case 22:
                            {
                                algoritmos.eliminarDos(L1, L2);
                                cout << "Se eliminaron los elementos iguales." << endl;
                            }
                                break;
                            case 0:
                            {
                                continuar3 = false;
                                L1.vaciar();
                                L2.vaciar();
                                L3.vaciar();
                            }
                                break;
                            default:
                            {
                                cout << "Ingrese un numero valido." << endl;
                            }
                        }
                    }
                }
                L1.destruir();
                L2.destruir();
                L3.destruir();
            }
                //archivo.open("dodecaedro.txt", ios::in);
                break;
            case 3:
            { //LISTA ORDENADA
                int decision2;
                bool continuar2 = true;
                listaOrd L1;
                listaOrd L2;
                listaOrd L3;
                L1.iniciar();
                L2.iniciar();
                L3.iniciar();
                algOrd algoritmos;
                ifstream archivo;
                while (continuar2) {
                    bool continuar3 = true;
                    cout << "CREACION DE LISTAS PREDEFINIDAS" << endl;
                    cout << "Escoger dos de las listas." << endl;
                    cout << "Puede escoger la misma 2 veces" << endl;
                    cout << "1. Lista Uno." << endl;
                    cout << "2. Lista Dos." << endl;
                    cout << "3. Lista Tres." << endl;
                    cout << "4. Lista Cuatro." << endl;
                    cout << "0. Salir." << endl;
                    cout << "Las Listas Predefinidas pueden ser cambiadas entrando al archivo en la carpeta del documento." << endl;
                    cin >> decision2;
                    switch (decision2) {
                        case 1:
                        {
                            archivo.open("ListaUno.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 2:
                        {
                            archivo.open("ListaDos.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 3:
                        {
                            archivo.open("ListaTres.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 4:
                        {
                            archivo.open("ListaCuatro.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L1);
                        }
                            break;
                        case 0:
                        {
                            continuar2 = false;
                            continuar3 = false;
                        }
                            break;
                        default:
                        {
                            cout << "Ingrese un numero valido." << endl;
                        }
                    }
                    cout << "1. Lista Uno." << endl;
                    cout << "2. Lista Dos." << endl;
                    cout << "3. Lista Tres." << endl;
                    cout << "4. Lista Cuatro." << endl;
                    cin >> decision2;
                    switch (decision2) {
                        case 1:
                        {
                            archivo.open("ListaUno.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 2:
                        {
                            archivo.open("ListaDos.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 3:
                        {
                            archivo.open("ListaTres.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 4:
                        {
                            archivo.open("ListaCuatro.txt", ios::in);
                            if (!archivo) { // operador ! sobrecargado
                                cerr << "No se pudo abrir el archivo de entrada." << endl;
                                exit(1);
                            }
                            algoritmos.llenarLista(archivo, L2);
                        }
                            break;
                        case 0:
                        {
                            continuar2 = false;
                            continuar3 = false;
                        }
                            break;
                        default:
                        {
                            cout << "Ingrese un numero valido." << endl;
                        }
                    }
                    while (continuar3) {
                        cout << "ALGORITMOS DISPONIBLES" << endl;
                        cout << "Escoja el algoritmo que desea aplicar" << endl;
                        cout << "1. Iguales." << endl;
                        cout << "2. Copiar elementos." << endl;
                        cout << "3. Lista Contenida en otra." << endl;
                        cout << "4. Pertene un elemento." << endl;
                        cout << "5. Eliminar Elementos Repetidos de una Lista." << endl;
                        cout << "6. Primera Union." << endl;
                        cout << "7. Segunda Union." << endl;
                        cout << "8. Primera Interseccion." << endl;
                        cout << "9. Segunda Interseccion." << endl;
                        cout << "0. Salir." << endl;
                        cin >> desicion;
                        switch (desicion) {
                            case 1:
                            {
                                bool igualdad = algoritmos.iguales(L1, L2);
                                if (igualdad)
                                    cout << "Las Listas son iguales." << endl;
                                else
                                    cout << "Las Listas NO son iguales." << endl;
                            }
                                break;
                            case 2:
                            {
                                do {
                                    cout << "¿Cual lista desea copiar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.copiar(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.copiar(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Las Listas se copiaron." << endl;
                            }
                                break;
                            case 3:
                            {
                                bool content;
                                do {
                                    cout << "¿Cual lista desea saber si esta contenida? \n Digite 1 para la primera en la segunda.\n"
                                            " 2 para la segunda en la primera." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        content = algoritmos.contenida(L1, L2);
                                    else if (desicion == 2)
                                        content = algoritmos.contenida(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                if (content)
                                    cout << "La Lista esta contenida." << endl;
                                else
                                    cout << "La Lista NO esta contenida" << endl;
                            }
                                break;
                            case 4:
                            {
                                bool exist;
                                cout << "¿Cual Elemento desea buscar. \n Recuerde insertar solo numeros enteros." << endl;
                                cin >> decision2;
                                do {
                                    cout << "¿En cual Lista desea buscar? \n Digite 1 para la primera 2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        exist = algoritmos.pertene(decision2, L1);
                                    else if (desicion == 2)
                                        exist = algoritmos.pertene(decision2, L2);
                                } while (desicion != 1 && desicion != 2);
                                if (exist)
                                    cout << "El Elemento pertenece a la lista" << endl;
                                else
                                    cout << "El Elemento NO pertenece a la lista." << endl;
                            }
                                break;
                            case 5:
                            {
                                do {
                                    cout << "¿A cual lista desea eliminar los elementos de la otra? \n Digite 1 para la primera "
                                            "2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.eliminarElemRep(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.eliminarElemRep(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se eliminaron los elementos Repetidos" << endl;
                            }
                                break;
                            case 6:
                            {
                                do {
                                    cout << "¿A cual lista desea agregarle los elementos de la otra? \n Digite 1 para la primera "
                                            "2 para la segunda." << endl;
                                    cin >> desicion;
                                    if (desicion == 1)
                                        algoritmos.unionPrim(L1, L2);
                                    else if (desicion == 2)
                                        algoritmos.unionPrim(L2, L1);
                                } while (desicion != 1 && desicion != 2);
                                cout << "Se termino de agregar los elementos." << endl;
                            }
                                break;
                            case 7:
                            {
                                L3 = algoritmos.unionSeg(L1, L2);
                                cout << "Se termino de agregar los elementos." << endl;
                                do {
                                    cout << "¿Desea listar la lista? \n Digite 1 para SI 2 para NO." << endl;
                                    cin >> desicion;
                                    if (desicion == 1) {
                                        int elem = L3.primero();
                                        cout << "->";
                                        cout << elem;
                                        for (int i = 0; i < L3.numElem()-1; i++) {
                                            cout << "->";
                                            cout << L3.siguiente(elem);
                                        }
                                    }
                                } while (desicion != 1 && desicion != 2);
                            }
                                break;
                            case 8:
                            {
                                L3 = algoritmos.interseccionPrim(L1, L2);
                                cout << "Se termino de agregar los elementos." << endl;
                                do {
                                    cout << "¿Desea listar la lista? \n Digite 1 para SI 2 para NO." << endl;
                                    cin >> desicion;
                                    if (desicion == 1) {
                                        int elem = L3.primero();
                                        cout << "->";
                                        cout << elem;
                                        for (int i = 0; i < L3.numElem()-1; i++) {
                                            cout << "->";
                                            cout << L3.siguiente(elem);
                                        }
                                    }
                                } while (desicion != 1 && desicion != 2);
                            }
                                break;
                            case 9:
                            {
                                L3 = algoritmos.interseccionSeg(L1, L2);
                                cout << "Se termino de agregar los elementos." << endl;
                                do {
                                    cout << "¿Desea listar la lista? \n Digite 1 para SI 2 para NO." << endl;
                                    cin >> desicion;
                                    if (desicion == 1) {
                                        int elem = L3.primero();
                                        cout << "->";
                                        cout << elem;
                                        for (int i = 0; i < L3.numElem()-1; i++) {
                                            cout << "->";
                                            cout << L3.siguiente(elem);
                                        }
                                    }
                                } while (desicion != 1 && desicion != 2);
                            }
                                break;
                            case 0:
                            {
                                continuar3 = false;
                                L1.vaciar();
                                L2.vaciar();
                                L3.vaciar();
                            }
                                break;
                            default:
                            {
                                cout << "Ingrese un numero valido." << endl;
                            }
                        }
                    }
                }
                L1.destruir();
                L2.destruir();
                L3.destruir();
            }
                break;

            case 0:
            {
                continuar = false;
            }
                break;
            default:
            {
                cout << "Ingrese un numero valido." << endl;
            }
        }
    }
    cout << "\nFin de la prueba!" << endl;

    return 0;
}

