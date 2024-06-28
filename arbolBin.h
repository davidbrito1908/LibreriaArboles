#ifndef ARBOLBIN_H_
#define ARBOLBIN_H_
#include "nodobin.h"
#include <List>

template <typename Tipo>

class ArbolBin{
    protected:
        int peso;
        NodoBin<Tipo> *raiz;
    public:
        void construir();
        void construir(Tipo raiz, ArbolBin hijoIzq, ArbolBin hijoDer);
        void construir(ArbolBin *a);
        bool esNulo();

        Tipo raiz();
        void insertarNodo(Tipo padre, Tipo hijo);

        void crear(int peso, NodoBin<Tipo> * raiz);
        int getPeso();
        NodoBin<Tipo> * getRaiz();
        void setPeso(int peso);
        void setRaiz(NodoBin<Tipo> * apuntador);

};
template <typename Tipo>
void ArbolBin<Tipo>::crear(int peso, NodoBin<Tipo> * raiz){
    this->setPeso(peso);
    this->setRaiz(raiz);
}


template <typename Tipo>
Tipo NodoBin<Tipo>::getInfo(){
    return this->info; 
}

template <typename Tipo>
NodoBin<Tipo> * ArbolBin<Tipo>::getRaiz(){
    return this->raiz;
}


template <typename Tipo>
void ArbolBin<Tipo>::setPeso(int peso){
    this->peso = peso;
}

template <typename Tipo>
void ArbolBin<Tipo>::setRaiz(NodoBin<Tipo> * apuntador){
    this->raiz = apuntador;
}


template <typename Tipo>
void imprimirPreOrden(NodoBin<Tipo> *raiz){
    if (raiz==nullptr){
        return;
    }else{
        cout << raiz->getInfo << " ";
        imprimirPreOrden(raiz->getHijoIzq);
        imprimirPreOrden(raiz->getHijoDer);
    }
}
template <typename Tipo>
void imprimirPostOrden(NodoBin<Tipo> *raiz){
    if (raiz==nullptr){
        return;
    }else{
        imprimirPreOrden(raiz->getHijoIzq);
        imprimirPreOrden(raiz->getHijoDer);
        cout << raiz->getInfo << " ";
    }
}

template <typename Tipo>
void leerArbol(List<Tipo> preorden, List<Tipo> inorden){
    return;
}

#endif