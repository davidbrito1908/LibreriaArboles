#ifndef ARBOLNARIO_H_
#define ARBOLNARIO_H_
#include "nodo.h"
#include <list>
#include <stack>
#include <queue>
using namespace std;

template <typename Tipo>

class ArbolN{
    protected:
        int peso;
        Nodo<Tipo> *raiz;
    private:
        Nodo<Tipo>* copiarNodos(Nodo<Tipo>* p);
        void destruirNodos(Nodo<Tipo>* p);

    public:
    //CONSTRUCTORES ==============================================
        void construir();
        void construir(Tipo raiz, list<ArbolN> L);
        void construir(ArbolN<Tipo> *a);
        void crear(int peso, Nodo<Tipo> * raiz);

        void copiar(ArbolN<Tipo> *A);
        void destruir();

    //GETTERS ==============================================
        int getPeso();
        int getPeso(Nodo<Tipo> *raiz);
        Nodo<Tipo> * getRaiz();
        list<ArbolN> hijos();
        Tipo infoRaiz();
    //SETTERS ==============================================
        void setInfoRaiz(Tipo valor);
        void setPeso(int peso);
        void setRaiz(Nodo<Tipo> * r);
    //INSERTAR ==============================================
        void insertarNodo(Tipo padre, Tipo hijo, Nodo<Tipo> *raiz);
        void insertarNodo(Tipo padre, Tipo hijo);
        void insertarSubarbol(ArbolN<Tipo> arbol);
        void eliminarSubarbol (int pos);
        
    //RECORRIDOS ==============================================
        void imprimirPreOrden(); //
        void imprimirPostOrden(); //
        void imprimirInOrden(); //
        void imprimirPorNiveles(); //

        void imprimirPreOrden(Nodo<Tipo> *raiz);
        void imprimirPostOrden(Nodo<Tipo> *raiz);
        void imprimirInOrden(Nodo<Tipo> *raiz);
        void imprimirPorNiveles(queue<Nodo<Tipo>*> actual);

        void preOrden(Nodo<Tipo> *raiz, list<Tipo> *L);
        list<Tipo> preOrden();
        void postOrden(Nodo<Tipo> *raiz, list<Tipo> *L);
        list<Tipo> postOrden();
        void inOrden(Nodo<Tipo> *raiz, list<Tipo> *L);
        list<Tipo> inOrden();

    //VARIOS ==============================================

        bool esNulo();
};

template <typename Tipo>
int ArbolN<Tipo>::getPeso(){
    return this->peso;
}
template <typename Tipo>
int ArbolN<Tipo>::getPeso(Nodo<Tipo> *raiz){
    list<int> L;
    preOrden(raiz, &L);
    return  L.size();
}

template <typename Tipo>
void ArbolN<Tipo>::setPeso(int peso){
    this->peso = peso;
}
template <typename Tipo>
Nodo<Tipo>* ArbolN<Tipo>::getRaiz(){
    return this->raiz;
}
template <typename Tipo>
void ArbolN<Tipo>::setRaiz(Nodo<Tipo> *r){
    this->raiz = r;
}
template <typename Tipo>
void ArbolN<Tipo>::setInfoRaiz(Tipo valor){
    if (this->raiz == nullptr){
        this->raiz = new Nodo<Tipo>;
        this->raiz->crear(valor);
        this->peso = 1;
    }else{
        this->raiz->setInfo(valor);
    }
}


template <typename Tipo>
void ArbolN<Tipo>::construir(){
    this->raiz =nullptr;
    this->peso = 0;
}
template <typename Tipo>
Nodo<Tipo>* ArbolN<Tipo>::copiarNodos(Nodo<Tipo>* p){
    Nodo<Tipo> *nuevo;

    if (p ==nullptr){
        return nullptr;
    }
    else{
        this->peso = this->peso + 1;
        nuevo = new(Nodo<Tipo>);
        nuevo->crear(p->getInfo(), copiarNodos(p->getHijoIzq()), copiarNodos(p->getHerDer()));
        return (nuevo);
    }
}
template <typename Tipo>
void ArbolN<Tipo>::construir(ArbolN<Tipo> *a){
    this->raiz = copiarNodos(a->getRaiz());
    this->peso = a->getPeso();
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
void ArbolN<Tipo>::copiar(ArbolN<Tipo> *a){
    this->setRaiz(copiarNodos(a->getRaiz()));
    this->setPeso(a->getPeso());
}


template <typename Tipo>
bool ArbolN<Tipo>::esNulo(){
    return (this->getRaiz() == nullptr);
}


template <typename Tipo>
Tipo ArbolN<Tipo>::infoRaiz(){
    return this->getRaiz()->getInfo();
}


template <typename Tipo>
list<ArbolN<Tipo>> ArbolN<Tipo>::hijos(){
    Nodo<Tipo> *aux;
    ArbolN<Tipo> arbolAux;
    list<ArbolN<Tipo>> L;

    aux=this->getRaiz()->getHijoIzq();
    while (aux != nullptr){
        arbolAux.setRaiz(aux);
        L.push_back(arbolAux);
        aux=aux->getHerDer();
    }
    return L;
}

template <typename Tipo>
void ArbolN<Tipo>::insertarSubarbol(ArbolN<Tipo> subarbol){
    Nodo<Tipo> *aux;

    if (this->getRaiz()->getHijoIzq() == nullptr){
        this->getRaiz()->setHijoIzq(copiarNodos(subarbol.getRaiz()));
    }else{
        aux = this->getRaiz()->getHijoIzq();
        while(aux->getHerDer() != nullptr){
            aux= aux->getHerDer();
        }
        aux->setHerDer(copiarNodos(subarbol.getRaiz()));
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
        this->peso = this->peso -1;
        delete(p);
        p=nullptr;
    }
}
template <typename Tipo>
void ArbolN<Tipo>::eliminarSubarbol(int pos) {
    Nodo<Tipo> *aux, *elim;
    int i;

    if (pos==1){
        elim = this->getRaiz()->getHijoIzq();
        this->getRaiz()->setHijoIzq(this->getRaiz()->getHijoIzq()->getHerDer());
        elim->setHerDer(nullptr);
        this->peso = this->peso - getPeso(elim);
    }
    else{
        aux = this->getRaiz()->getHijoIzq();
        for(i=2; i<pos;i++){
            aux = aux->getHerDer();
        }
        elim = aux->getHerDer();
        aux->setHerDer(aux->getHerDer()->getHerDer());
        elim->setHerDer(nullptr);
        this->peso = this->peso - getPeso(elim);
    }

}


/*template <typename Tipo>
// Versión RECURSIVA
void ArbolN<Tipo>::destruir(){
    destruirNodos(this->getRaiz());
}*/


template <typename Tipo>
// Versión Iterativa (con una Pila)
void ArbolN<Tipo>::destruir(){
    stack<Nodo<Tipo> *> p;
    Nodo<Tipo> *aux;

    if(this->raiz != nullptr) {
        p.push(this->raiz);
        while(!p.empty()){
            aux = p.top();
            p.pop();
            if(aux->getHijoIzq() != nullptr) {
                p.push(aux->getHijoIzq());
            }
            if(aux->getHerDer() != nullptr) {
                p.push(aux->getHerDer());
            }
                //aux->destruir();
        }
        this->raiz = nullptr;
    }
}



template <typename Tipo>
void ArbolN<Tipo>::insertarNodo(Tipo padre, Tipo hijo, Nodo<Tipo> *raiz){
    Nodo<Tipo> *nuevo, *aux;

    if(raiz != nullptr){
        nuevo = new(Nodo<Tipo>);
        nuevo->setInfo(hijo);
        nuevo->setHijoIzq(nullptr);
        nuevo->setHerDer(nullptr);

        if(raiz->getInfo() == padre){
            if (raiz->getHijoIzq() == nullptr){
                raiz->setHijoIzq(nuevo);
                this->peso = this->peso + 1;
                return;
            }
            else{
                aux = raiz->getHijoIzq();
                while(aux->getHerDer() != nullptr){
                    aux = aux->getHerDer();
                }
                aux->setHerDer(nuevo);
                this->peso = this->peso + 1;
                return;
            }
        }
        else{
            this->insertarNodo(padre,hijo,raiz->getHijoIzq());
            this->insertarNodo(padre,hijo,raiz->getHerDer());
        }
    }
    
}
template <typename Tipo>
void ArbolN<Tipo>::insertarNodo(Tipo padre, Tipo hijo){
    this->insertarNodo(padre,hijo, this->raiz);
}



template <typename Tipo>
void ArbolN<Tipo>::imprimirPreOrden(Nodo<Tipo> *raiz){
    if (raiz==nullptr){
        return;
    }else{
        cout << raiz->getInfo() << " ";
        this->imprimirPreOrden(raiz->getHijoIzq());
        this->imprimirPreOrden(raiz->getHerDer());
    }
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirPreOrden(){
    this->imprimirPreOrden(this->raiz);
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirPostOrden(Nodo<Tipo> *raiz){
    Nodo<Tipo> *aux;
    if (raiz==nullptr){
        return;
    }else{
        aux = raiz->getHijoIzq();
        while(aux != nullptr){
            this->imprimirPostOrden(aux);
            aux=aux->getHerDer();
        }
        cout << raiz->getInfo() << " ";
    }
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirPostOrden(){
    this->imprimirPostOrden(this->raiz);
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirInOrden(Nodo<Tipo> *raiz){
    Nodo<Tipo> *aux;

    if (raiz==nullptr){
        return;
    }else{
        this->imprimirInOrden(raiz->getHijoIzq());
        cout << raiz->getInfo() << " ";
        if(raiz->getHijoIzq() != nullptr){
            aux = raiz->getHijoIzq()->getHerDer();
            while(aux != nullptr){
                this->imprimirInOrden(aux);
                aux = aux->getHerDer();
            }
        }
    }
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirInOrden(){
    this->imprimirInOrden(this->raiz);
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirPorNiveles(queue<Nodo<Tipo>*> actual){
    queue<Nodo<Tipo>*> sigNivel;
    Nodo<Tipo> *aux; 
    int hijos = 0;

    cout<<endl;
    while (!actual.empty()) {
        hijos=0;
        if (actual.front()->getHijoIzq() != nullptr){
            sigNivel.push(actual.front()->getHijoIzq());
            hijos++;
            
            aux = actual.front()->getHijoIzq()->getHerDer();
            while( aux != nullptr){
                sigNivel.push(aux);
                hijos++;
                aux = aux->getHerDer();
            }
            
        }
        cout << actual.front()->getInfo() << " (" << hijos << ") "<< "  ";
        actual.pop();
    }
    if(!sigNivel.empty()){
        this->imprimirPorNiveles(sigNivel);
    }
}
template <typename Tipo>
void ArbolN<Tipo>::imprimirPorNiveles(){
    queue<Nodo<Tipo>*> actual;
    actual.push(this->raiz);
    this->imprimirPorNiveles(actual);
}


template <typename Tipo>
void ArbolN<Tipo>::preOrden(Nodo<Tipo> *raiz, list<Tipo> *L){
    if (raiz!=nullptr){
        L->push_back(raiz->getInfo());
        this->preOrden(raiz->getHijoIzq(), L);
        this->preOrden(raiz->getHerDer(), L);
    }
}
template <typename Tipo>
list<Tipo> ArbolN<Tipo>::preOrden(){
    list<Tipo> L;
    this->preOrden(this->raiz, &L);
    return L;
}

template <typename Tipo>
void ArbolN<Tipo>::postOrden(Nodo<Tipo> *raiz, list<Tipo> *L){
    Nodo<Tipo> *aux;
    if (raiz!=nullptr){
        aux = raiz->getHijoIzq();
        while(aux != nullptr){
            this->postOrden(aux, L);
            aux=aux->getHerDer();
        }
        //this->postOrden(raiz->getHerDer(), L);
        L->push_back(raiz->getInfo());
    }
}
template <typename Tipo>
list<Tipo> ArbolN<Tipo>::postOrden(){
    list<Tipo> L;
    this->postOrden(this->raiz, &L);
    return L;
}
template <typename Tipo>
void ArbolN<Tipo>::inOrden(Nodo<Tipo> *raiz, list<Tipo> *L){
    Nodo<Tipo> *aux;
    if (raiz!=nullptr){
        this->inOrden(raiz->getHijoIzq(), L);
        L->push_back(raiz->getInfo());
        if(raiz->getHijoIzq() != nullptr){
            aux = raiz->getHijoIzq()->getHerDer();
            while(aux != nullptr){
                this->inOrden(aux, L);
                aux = aux->getHerDer();
            }
        }
    }
}
template <typename Tipo>
list<Tipo> ArbolN<Tipo>::inOrden(){
    list<Tipo> L;
    this->inOrden(this->raiz, &L);
    return L;
}

#endif
