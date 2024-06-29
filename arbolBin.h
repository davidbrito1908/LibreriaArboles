#ifndef ARBOLBIN_H_
#define ARBOLBIN_H_
#include "nodobin.h"
#include <list>

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

        NodoBin<Tipo> * copiarNodos(NodoBin<Tipo> *p);
        Tipo raiz();
        void insertarNodo(Tipo padre, Tipo hijo);
        void crear(int peso, NodoBin<Tipo> * raiz);
        int getPeso();
        NodoBin<Tipo> * getRaiz();
        ArbolBin<Tipo> hijoIzq();
        ArbolBin<Tipo> hijoDer();
        void setPeso(int peso);
        void setRaiz(NodoBin<Tipo> * apuntador);
        void copiar(ArbolBin<Tipo> *a);
        void destruir();
};

template <typename Tipo>
void ArbolBin<Tipo>::construir(){
    this->setRaiz(nullptr);
}

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
Tipo ArbolBin<Tipo>::raiz(){
    return this->raiz->getInfo();
}
template <typename Tipo>
NodoBin<Tipo>* ArbolBin<Tipo>::copiarNodos(NodoBin<Tipo> *p){
    NodoBin<Tipo> *nuevo;

    if (p==nullptr){
        return nullptr;
    }else{
        nuevo = new(NodoBin<Tipo>);
        nuevo->crear(p->getInfo(), p->getHijoIzq(), p->getHijoDer());
        return(nuevo);
    }
}

template <typename Tipo>
void ArbolBin<Tipo>::construir(Tipo raiz, ArbolBin<Tipo> a1, ArbolBin<Tipo> a2){
    ArbolBin<Tipo> arbolAux;

    this->raiz = new(NodoBin<Tipo>);
    this->getRaiz()->setInfo(e);
    this->getRaiz()->setHijoIzq(copiarNodos(a1->getRaiz()));
    this->getRaiz()->setHijoDer(copiarNodos(a2->getRaiz()));
}


template <typename Tipo>
void ArbolBin<Tipo>::copiar(ArbolBin<Tipo> *a){
    this->raiz = copiarNodos(a->getRaiz());
}

template <typename Tipo>
bool ArbolBin<Tipo>::esNulo(){
    return (this->raiz == nullptr);
}
template <typename Tipo>
Tipo ArbolBin<Tipo>::raiz(){
    return (this->getRaiz()->getInfo());
}
template <typename Tipo>
ArbolBin<Tipo> ArbolBin<Tipo>::hijoIzq(){
    ArbolBin<Tipo> hijo;
    if (this->raiz != nullptr){
        hijo->raiz = copiarNodos(this->getRaiz()->getHijoIzq());
    }else{
        hijo->raiz = nullptr;
    }
    return (hijo);
}
template <typename Tipo>
ArbolBin<Tipo> ArbolBin<Tipo>::hijoDer(){
    ArbolBin<Tipo> hijo;
    if (this->raiz != nullptr){
        hijo->raiz = copiarNodos(this->getRaiz()->getHijoDer());
    }else{
        hijo->raiz = nullptr;
    }
    return (hijo);
}
template <typename Tipo>
Tipo ArbolBin<Tipo>::raiz(){
    return (this->getRaiz()->getInfo());
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