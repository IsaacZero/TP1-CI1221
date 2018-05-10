/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaIndEn.h
 * Author: Isaac
 *
 * Created on 7 de mayo de 2018, 11:10 PM
 */

#ifndef LISTAINDEN_H
#define LISTAINDEN_H

template < typename V >
class ListaIndEn{
public:    
    
    ListaIndEn();
    virtual ~ListaIndEn();
    
    //EFE: Inicializa la Lista.
    //REQ:
    //MOD:
    void iniciar();
    
    //EFE: Destruye la Lista, la deja inutilizable.
    //REQ: L inicializado.
    //MOD: La Lista.
    void destruir();
    
    //EFE: Elimina todos los elementos de la Lista.
    //REQ: L inicializado.
    //MOD: La Lista.
    void vaciar();
    
    //EFE: Retorna true si esta vacia y false en caso contrario.
    //REQ: La Lista inicializada.
    //MOD:
    bool vacia();
    
    //EFE:
    //REQ:
    //MOD:
    void agregar(V elemento, int indice);
    
    //EFE:
    //REQ:
    //MOD:
    void borrar(int indice);
    
    //EFE:
    //REQ:
    //MOD:
    V recuperar(int indice);
    
    //EFE:
    //REQ:
    //MOD:
    void modificarElemento(V elemento, int indice);
    
    //EFE:
    //REQ:
    //MOD:
    void intercambiar(int i, int j);
    
    //EFE:
    //REQ:
    //MOD:
    int numElem();
};

#endif /* LISTAINDEN_H */

