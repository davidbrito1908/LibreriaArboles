#ifndef ARBOLBIN_H_
#define ARBOLBIN_H_
#include "nodobin.h"
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename Tipo>

class ArbolBin{
    protected:
        int peso;
        NodoBin<Tipo> *raiz;
    private:
        NodoBin<Tipo> * copiarNodos(NodoBin<Tipo> *p);

    public:
        //CONSTRUCTORES ==============================================
        void construir();
        void construir(Tipo raiz, ArbolBin hijoIzq = nullptr, ArbolBin hijoDer = nullptr); //
        void construir(ArbolBin *a); //
        void crear(int peso, NodoBin<Tipo> * raiz);
        
        void copiar(ArbolBin<Tipo> *a); //
        
        //GETTERS ==============================================
        int getPeso();
        NodoBin<Tipo> * getRaiz(); //
        Tipo infoRaiz(); //
        ArbolBin<Tipo> hijoIzq();//
        ArbolBin<Tipo> hijoDer();//
        
        //SETTERS ==============================================
        void setPeso(int peso);
        void setRaiz(NodoBin<Tipo> * apuntador);//

        //INSERTAR Y ELIMINAR ==============================================
        void insertarNodo(Tipo padre, Tipo hijo, NodoBin<Tipo> *raiz);//
        void insertarSubarbol(ArbolBin<Tipo> subarbol);//
        void eliminarSubarbol(int pos); //NO LOS ELIMINA COMO TAL
        //void destruirNodos(NodoBin<Tipo> *p); //HACER
        void destruir();
        

        //RECORRIDOS ==============================================
        void imprimirPreOrden(); //
        void imprimirPostOrden(); //
        void imprimirInOrden(); //
        void imprimirPorNiveles(); //
        void imprimirPreOrden(NodoBin<Tipo> *raiz); //
        void imprimirPostOrden(NodoBin<Tipo> *raiz); //
        void imprimirInOrden(NodoBin<Tipo> *raiz); //
        void imprimirPorNiveles(queue<NodoBin<Tipo>*> actual); //

        //LECTURAS ==============================================
        NodoBin<Tipo> *  leerArbol(list<Tipo> preorden, list<Tipo> inorden); //
        NodoBin<Tipo> *  leerArbolPostOrden(list<Tipo> postorden, list<Tipo> inorden); //

        //Metodos divertidos - VARIOS ==============================================
        bool esNulo();//
        list<Tipo> getPrimos(Tipo elemento, queue<NodoBin<Tipo>*> actual);
        void LCA(NodoBin<Tipo> *r, Tipo e1, Tipo e2, bool *encontrado1, bool *encontrado2, bool *LCAEncontrado, Tipo *ancestro);//
        Tipo LCA(Tipo e1, Tipo e2);//
};



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





//CONSTRUCTORES =============================================================================

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
void ArbolBin<Tipo>::construir(Tipo e, ArbolBin<Tipo> a1, ArbolBin<Tipo> a2){
    ArbolBin<Tipo> arbolAux;

    this->raiz = new(NodoBin<Tipo>);
    this->getRaiz()->setInfo(e);
    this->getRaiz()->setHijoIzq(copiarNodos(a1.getRaiz()));
    this->getRaiz()->setHijoDer(copiarNodos(a2.getRaiz()));
}
template <typename Tipo>
void ArbolBin<Tipo>::construir(ArbolBin<Tipo> *a){
    this->raiz = copiarNodos(a->getRaiz());
}

template <typename Tipo>
void ArbolBin<Tipo>::copiar(ArbolBin<Tipo> *a){
    this->raiz = copiarNodos(a->getRaiz());
}





//GETTERS  =============================================================================

template <typename Tipo>
NodoBin<Tipo> * ArbolBin<Tipo>::getRaiz(){
    return this->raiz;
}

template <typename Tipo>
ArbolBin<Tipo> ArbolBin<Tipo>::hijoIzq(){
    ArbolBin<Tipo> hijo;
    if (this->raiz != nullptr){
        hijo.raiz = copiarNodos(this->getRaiz()->getHijoIzq());
    }else{
        hijo.raiz = nullptr;
    }
    return (hijo);
}

template <typename Tipo>
ArbolBin<Tipo> ArbolBin<Tipo>::hijoDer(){
    ArbolBin<Tipo> hijo;
    if (this->raiz != nullptr){
        hijo.raiz = copiarNodos(this->getRaiz()->getHijoDer());
    }else{
        hijo.raiz = nullptr;
    }
    return (hijo);
}

template <typename Tipo>
Tipo ArbolBin<Tipo>::infoRaiz(){
    return (this->getRaiz()->getInfo());
}




//SETTERS =============================================================================

template <typename Tipo>
void ArbolBin<Tipo>::setPeso(int peso){
    this->peso = peso;
}

template <typename Tipo>
void ArbolBin<Tipo>::setRaiz(NodoBin<Tipo> * apuntador){
    this->raiz = apuntador;
}





// INSERTAR ===========================================================================

template <typename Tipo>
void ArbolBin<Tipo>::insertarNodo(Tipo padre, Tipo hijo, NodoBin<Tipo> *raiz){
    NodoBin<Tipo> *nuevo, *aux;

    if(raiz != nullptr){
        nuevo = new(NodoBin<Tipo>);
        nuevo->setInfo(hijo);
        nuevo->setHijoIzq(nullptr);
        nuevo->setHijoDer(nullptr);

        if(raiz->getInfo() == padre){
                if (raiz->getHijoIzq() == nullptr){
                    raiz->setHijoIzq(nuevo);
                    return;
                }
                if (raiz->getHijoDer() == nullptr){
                    raiz->setHijoDer(nuevo);
                    return;
                }
        }else{
            insertarNodo(padre,hijo,raiz->getHijoIzq());
            insertarNodo(padre,hijo,raiz->getHijoDer());
        }
    }
}

template <typename Tipo>
void ArbolBin<Tipo>::insertarSubarbol(ArbolBin<Tipo> subarbol){
    if (this->getRaiz()->getHijoIzq() == nullptr){
        this->getRaiz()->setHijoIzq(copiarNodos(subarbol.getRaiz()));
    }else{
        if (this->getRaiz()->getHijoDer() == nullptr){
            this->getRaiz()->setHijoDer(copiarNodos(subarbol.getRaiz()));
        }
    }
}

template <typename Tipo>
void ArbolBin<Tipo>::eliminarSubarbol(int pos) {
    NodoBin<Tipo> *aux;
    int i;

    if (pos==1){
        aux = this->getRaiz()->getHijoIzq();
        this->getRaiz()->setHijoIzq(this->getRaiz()->getHijoDer());
        this->getRaiz()->setHijoDer(nullptr);
    }
    else{
        aux = this->getRaiz()->getHijoDer();
        this->getRaiz()->setHijoDer(nullptr);
    }

}





//RECORRIDOS =============================================================================

template <typename Tipo>
void ArbolBin<Tipo>::imprimirPreOrden(){
    NodoBin<Tipo> *raiz = this->getRaiz();
    this->imprimirPreOrden(raiz);
}
template <typename Tipo>
void ArbolBin<Tipo>::imprimirPostOrden(){
    NodoBin<Tipo> *raiz = this->getRaiz();
    this->imprimirPostOrden(raiz);
}
template <typename Tipo>
void ArbolBin<Tipo>::imprimirInOrden(){
    NodoBin<Tipo> *raiz = this->getRaiz();
    this->imprimirInOrden(raiz);
}
template <typename Tipo>
void ArbolBin<Tipo>::imprimirPorNiveles(){
    queue<NodoBin<Tipo>*> c;
    c.push(this->getRaiz());
    this->imprimirPorNiveles(c);
}
template <typename Tipo>
void ArbolBin<Tipo>::imprimirPreOrden(NodoBin<Tipo> *raiz){
    if (raiz==nullptr){
        return;
    }else{
        cout << raiz->getInfo() << " ";
        imprimirPreOrden(raiz->getHijoIzq());
        imprimirPreOrden(raiz->getHijoDer());
    }
}
template <typename Tipo>
void ArbolBin<Tipo>::imprimirPostOrden(NodoBin<Tipo> *raiz){
    if (raiz==nullptr){
        return;
    }else{
        imprimirPostOrden(raiz->getHijoIzq());
        imprimirPostOrden(raiz->getHijoDer());
        cout << raiz->getInfo() << " ";
    }
}
template <typename Tipo>
void ArbolBin<Tipo>::imprimirInOrden(NodoBin<Tipo> *raiz){
    if (raiz==nullptr){
        return;
    }else{
        imprimirInOrden(raiz->getHijoIzq());
        cout << raiz->getInfo() << " ";
        imprimirInOrden(raiz->getHijoDer());
    }
}

template <typename Tipo>
void ArbolBin<Tipo>::imprimirPorNiveles(queue<NodoBin<Tipo>*> actual){
    queue<NodoBin<Tipo>*> sigNivel;
    int hijos = 0;

    cout<<endl;
    while (!actual.empty()) {
        hijos=0;
        if (actual.front()->getHijoIzq() != nullptr){
            sigNivel.push(actual.front()->getHijoIzq());
            hijos++;
        }
        if (actual.front()->getHijoDer() != nullptr){
            sigNivel.push(actual.front()->getHijoDer());
            hijos++;
        }
        
        cout << actual.front()->getInfo() << " (" << hijos << ") "<< "  ";
        actual.pop();
    }
    if(!sigNivel.empty()){
        imprimirPorNiveles(sigNivel);
    }
}





//LECTURAS =============================================================================

template <typename Tipo>
NodoBin<Tipo> * ArbolBin<Tipo>::leerArbol(list<Tipo> preorden, list<Tipo> inorden){
    
    NodoBin<Tipo> *r;
    list<Tipo> preIzq, preDer, inIzq, inDer;

    if(!preorden.empty()){
        r = new (NodoBin<Tipo>);
        r->setInfo(preorden.front());
        preorden.pop_front();


        //LLENAR LISTAS DE LA PARTE IZQUIERDA DEL ARBOL (MIENTRAS NO SE ENCUENTRE LA RAIZ EN EL INORDEN)
        while(inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            preIzq.push_back(preorden.front());

            inorden.pop_front();
            preorden.pop_front();
        }
        inorden.pop_front(); //eliminar raiz en inorden

        //LLENAR LISTAS DE LA PARTE DERECHA DEL ARBOL (MIENTRAS LAS LISTAS NO ESTÉN VACÍAS)
        while(!inorden.empty()){
            preDer.push_back(preorden.front());
            inDer.push_back(inorden.front());

            preorden.pop_front();
            inorden.pop_front();
        }

        r->setHijoIzq(leerArbol(preIzq, inIzq));
        r->setHijoDer(leerArbol(preDer, inDer));

        return r;

    }else{
        return nullptr;
    }

}


template <typename Tipo>
NodoBin<Tipo> * ArbolBin<Tipo>::leerArbolPostOrden(list<Tipo> postorden, list<Tipo> inorden){
    
    NodoBin<Tipo> *r;
    list<Tipo> postIzq, postDer, inIzq, inDer;

    if(!postorden.empty()){
        r = new (NodoBin<Tipo>);
        r->setInfo(postorden.back());
        postorden.pop_back();


        //LLENAR LISTAS DE LA PARTE DERECHA DEL ARBOL (MIENTRAS NO SE ENCUENTRE LA RAIZ EN EL INORDEN)
        while(inorden.back() != r->getInfo()){
            inDer.push_front(inorden.back());
            postDer.push_front(postorden.back());

            inorden.pop_back();
            postorden.pop_back();
        }
        inorden.pop_back(); //eliminar raiz en inorden

        //LLENAR LISTAS DE LA PARTE IZQUIERDA DEL ARBOL (MIENTRAS LAS LISTAS NO ESTÉN VACÍAS)
        while(!inorden.empty()){
            postIzq.push_front(postorden.back());
            inIzq.push_front(inorden.back());

            postorden.pop_back();
            inorden.pop_back();
        }

        r->setHijoIzq(leerArbol(postIzq, inIzq));
        r->setHijoDer(leerArbol(postDer, inDer));

        return r;

    }else{
        return nullptr;
    }

}


//VARIOS =============================================================================


template <typename Tipo>
bool ArbolBin<Tipo>::esNulo(){
    return (this->raiz == nullptr);
}


template <typename Tipo>
void ArbolBin<Tipo>::LCA(NodoBin<Tipo> *r, Tipo e1, Tipo e2, bool *encontrado1, bool *encontrado2, bool *LCAEncontrado, Tipo *ancestro){
    bool encontradoe1hi, encontradoe2hi, encontradoe1hd, encontradoe2hd;
    
    
    if (!*LCAEncontrado){
        if (r!=nullptr){
            if ((r->getHijoIzq() == nullptr) && (r->getHijoDer() == nullptr)){
                *encontrado1 = r->getInfo() == e1;
                *encontrado2 = r->getInfo() == e2;
            }else{
                encontradoe1hi=false;
                encontradoe1hd=false;
                encontradoe2hd=false;
                encontradoe2hi=false;

                this->LCA(r->getHijoIzq(), e1, e2, &encontradoe1hi, &encontradoe2hi, LCAEncontrado, ancestro);
                this->LCA(r->getHijoDer(), e1, e2, &encontradoe1hd, &encontradoe2hd, LCAEncontrado, ancestro);

                if(!*LCAEncontrado){
                    *encontrado1 = encontradoe1hi || encontradoe1hd || r->getInfo() == e1;
                    *encontrado2 = encontradoe2hi || encontradoe2hd || r->getInfo() == e2;

                    *LCAEncontrado = *encontrado1 && *encontrado2;

                    if (*LCAEncontrado) {
                        *ancestro = r->getInfo();
                    }
                }
            }
        }
    }
}

template <typename Tipo>
Tipo ArbolBin<Tipo>::LCA(Tipo e1, Tipo e2){
    bool encontrado1, encontrado2, LCAEncontrado;
    Tipo Ancestro;

    encontrado1 = false;
    encontrado2 = false;
    LCAEncontrado =false;
    this->LCA(this->getRaiz(), e1, e2, &encontrado1, &encontrado2, &LCAEncontrado, &Ancestro);
    return Ancestro;
}

template <typename Tipo>
list<Tipo> ArbolBin<Tipo>::getPrimos(Tipo elemento, queue<NodoBin<Tipo>*> actual){
    queue<NodoBin<Tipo>*> sigNivel;
    bool padre = false, fin =false;;
    list<Tipo> primos;

    while (!actual.empty()) {
        padre=false;
        if (actual.front()->getHijoIzq() != nullptr){
            //Si el actual es el padre no pongas sus hijos en el siguiente nivel
            padre = (actual.front()->getHijoIzq()->getInfo() == elemento);
            if (actual.front()->getHijoDer() != nullptr){
                padre = padre || (actual.front()->getHijoDer()->getInfo() == elemento);
            }
            if(!padre){
                sigNivel.push(actual.front()->getHijoIzq());
            }else{
                fin=true;
            }
        }
        if (actual.front()->getHijoDer() != nullptr){

            //Si el actual es el padre no pongas sus hijos en el siguiente nivel
            padre = (actual.front()->getHijoDer()->getInfo() == elemento);
            if (actual.front()->getHijoIzq() != nullptr){
                padre = padre || (actual.front()->getHijoIzq()->getInfo() == elemento);
            }
            if(!padre){
                sigNivel.push(actual.front()->getHijoDer());
            }else{
                fin=true;
            }
        }
        actual.pop();
    }
    if (fin){
        //PASAR DE LA COLA A LA LISTA PRIMOS
        while(!sigNivel.empty()){
            primos.push_back(sigNivel.front()->getInfo());
            sigNivel.pop();
        }
        return primos;

    }else{
        if(!sigNivel.empty()){
            primos = getPrimos(elemento, sigNivel);
        }
    }
    return primos;
}
#endif