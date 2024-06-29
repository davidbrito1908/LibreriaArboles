#ifndef ARBOLNARIO_H_
#define ARBOLNARIO_H_
#include "nodo.h"
#include <list>
#include <stack>
using namespace std;

template <typename Tipo>

class ArbolN{
    protected:
        int peso;
        Nodo<Tipo> *raiz;
    private:
        static Nodo<Tipo>* copiarNodos(Nodo<Tipo>* ptrNodo);
        static void destruirNodos(Nodo<Tipo>* p);

    public:
        void construir();
        void construir(Tipo raiz, list<ArbolN> L);
        void construir(Arbol *a);
        void copiar(ArbolN *A);
        bool esNulo();

        Tipo raiz();
        void insertarNodo(Tipo padre, Tipo hijo);

        void crear(int peso, Nodo<Tipo> * raiz);
        int getPeso();
        Nodo<Tipo> * getRaiz();
        void setPeso(int peso);
        void setRaiz(Nodo<Tipo> * apuntador);
        list<ArbolN> hijos();
        void insertarSubarbol(ArbolN<Tipo> arbol);
        void eliminarSubarbol (int pos);
        void destruir();

};
#endif

template <typename Tipo>
void ArbolN<Tipo>::construir(){
    this->raiz =nullptr;
    this->peso = 0;
}
template <typename Tipo>
static Nodo<Tipo>* copiarNodos(Nodo<Tipo>* p){
    Nodo<Tipo> *nuevo;

    if (p ==nullptr){
        return nullptr;
    }
    else{
        nuevo = new(Nodo<Tipo>);
        nuevo->construir(p->getInfo(), copiarNodos(p->getHijoIzq()), copiarNodos(p->getHerDer()));
        return (nuevo);
    }
}

template <typename Tipo>
void ArbolN<Tipo>::construir(Tipo raiz, list<ArbolN<Tipo>> L){
    Nodo<Tipo> *aux;

    this->raiz = new(Nodo<Tipo>);
    this->getRaiz()->crear(raiz,nullptr,nullptr);
    if (!L.empty()){
        this->getRaiz()->setHijoIzq(copiarNodos(L.front().getRaiz()));
        L.pop_front();
        aux= this->getRaiz()->getHijoIzq();
        while(!L.empty()){
            aux->setHerDer(copiarNodos(L.front().getRaiz()));
            L.pop_front();
            aux = aux->getHerDer();
        }
    }
}

template <typename Tipo>
void ArbolN<Tipo>::copiar(ArbolN *a){
    this->setRaiz(copiarNodos(a->getRaiz()));
}
template <typename Tipo>
bool ArbolN<Tipo>::esNulo(){
    return (this->getRaiz() == nullptr);
}
template <typename Tipo>
Tipo ArbolN<Tipo>::raiz(){
    return this->getRaiz()->getInfo();
}
template <typename Tipo>
list<ArbolN<Tipo>> ArbolN<Tipo>::hijos(){
    Nodo<Tipo> *aux;
    ArbolN<Tipo> arbolAux;
    list<ArbolN<Tipo>> L;

    aux=this->getRaiz()->getHijoIzq();
    while (aux != nullptr){
        arbolAux->setRaiz(aux);
        L.push_back(arbolAux);
        aux=aux->getHerDer();
    }
    return L;
}

template <typename Tipo>
void ArbolN<Tipo>::insertarSubarbol(ArbolN<Tipo> subarbol){
    Nodo<Tipo> *aux;

    if (this->getRaiz()->getHijoIzq() != nullptr){
        this->getRaiz()->setHijoIzq(copiarNodos(subarbol->getRaiz()));
    }else{
        aux = this->getRaiz()->getHijoIzq();
        while(aux->getHerDer() != nullptr){
            aux= aux->getHerDer();
        }
        aux->setHerDer(copiarNodos(subarbol->getRaiz()));
    }
}


template <typename Tipo>
void ArbolN<Tipo>::destruirNodos(Nodo<Tipo> *p) {
    if ( p != nullptr){
        if(p->getHerDer() != nullptr){
            destruirNodos(p->getHerDer());
        }
        if(this->getRaiz()->getHijoIzq() != nullptr){
            destruirNodos(p->getHijoIzq());
        }
        delete(p);
        p=nullptr;
    }
}
template <typename Tipo>
void ArbolN<Tipo>::eliminarSubarbol(int pos) {
    Nodo<Tipo> *aux, elim;
    int i;

    if (pos==1){
        elim = this->getRaiz()->getHijoIzq();
        this->getRaiz()->setHijoIzq(this->getRaiz()->getHijoIzq()->getHerDer());
    }
    else{
        aux = this->getRaiz()->getHijoIzq();
        for(i=2; i<pos;i++){
            aux = aux->getHerDer();
        }
        elim = aux->getHerDer();
        aux->setHerDer(aux->getHerDer()->getHerDer());
    }
}


template <typename Tipo>
// Versión RECURSIVA
void ArbolN<Tipo>::destruir(){
    destruirNodos(this->getRaiz());
}


template <typename Tipo>
// Versión Iterativa (con una Pila)
void ArbolN<Tipo>::destruir(){
    stack<Nodo<Tipo> *> p;
    Nodo<Tipo> *aux;

    if(this->raiz != nullptr) {
        p.apilar(this->raiz);
        while(!p.esVacia()){
            aux = p.tope();
            p.desapilar();
            if(*aux.getHijoIzquierdo() != nullptr) {
                p.apilar(*aux.getHijoIzquierdo());
            }
            if(*aux.getHermanoDerecho() != nullptr) {
                p.apilar(*aux.getHermanoDerecho());
            }
                aux.destruir();
        }
        this->raiz = nullptr;
    }
}