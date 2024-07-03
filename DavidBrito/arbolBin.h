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
        void destruirNodos(NodoBin<Tipo> **ptrNodo);

    public:
        //CONSTRUCTORES ==============================================
        void construir();
        void construir(Tipo raiz, ArbolBin hijoIzq = nullptr, ArbolBin hijoDer = nullptr); //
        void construir(ArbolBin *a); //
        void crear(int peso, NodoBin<Tipo> * raiz);
        
        void copiar(ArbolBin<Tipo> *a); //
        
        //GETTERS ==============================================
        int getPeso();
        int getPeso(NodoBin<Tipo> *raiz);
        NodoBin<Tipo> * getRaiz(); //
        Tipo infoRaiz(); //
        ArbolBin<Tipo> hijoIzq();//
        ArbolBin<Tipo> hijoDer();//
        
        //SETTERS ==============================================
        void setPeso(int peso);
        void setRaiz(NodoBin<Tipo> * apuntador);//
        void setInfoRaiz(Tipo valor);

        //INSERTAR Y ELIMINAR ==============================================
        void insertarNodo(Tipo padre, Tipo hijo, NodoBin<Tipo> *raiz);//
        void insertarNodo(Tipo padre, Tipo hijo);//
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

        void preOrden(NodoBin<Tipo> *raiz, list<Tipo> *L);
        list<Tipo> preOrden();
        void postOrden(NodoBin<Tipo> *raiz, list<Tipo> *L);
        list<Tipo> postOrden();
        void inOrden(NodoBin<Tipo> *raiz, list<Tipo> *L);
        list<Tipo> inOrden();

        //LECTURAS ==============================================
        NodoBin<Tipo> *  leerArbol(list<Tipo> preorden, list<Tipo> inorden); //
        NodoBin<Tipo> *  leerArbolPostOrden(list<Tipo> postorden, list<Tipo> inorden); //

        //Metodos divertidos - VARIOS ==============================================
        bool esNulo();//
        list<Tipo> getPrimos(Tipo elemento, queue<NodoBin<Tipo>*> actual);
        void LCA(NodoBin<Tipo> *r, Tipo e1, Tipo e2, bool *encontrado1, bool *encontrado2, bool *LCAEncontrado, Tipo *ancestro);//
        void LCANodo(NodoBin<Tipo> *r, Tipo e1, Tipo e2, bool *encontrado1, bool *encontrado2, bool *LCAEncontrado, NodoBin<Tipo> **ancestro);
        Tipo LCA(Tipo e1, Tipo e2);//
        void getPadre(Tipo e, NodoBin<Tipo> *raiz, bool *band, NodoBin<Tipo> **padre);
        NodoBin<Tipo>* getPadre(Tipo e);
        list<Tipo> camino(Tipo e1,Tipo e2);
        void caminoNodos(NodoBin<Tipo>* ptr, Tipo e, bool *band, list<Tipo> *camino);
        queue<NodoBin<Tipo>*> hojas (queue<NodoBin<Tipo>*> actual);
};



template <typename Tipo>
NodoBin<Tipo>* ArbolBin<Tipo>::copiarNodos(NodoBin<Tipo> *p){
    NodoBin<Tipo> *nuevo;

    if (p==nullptr){
        return nullptr;
    }else{
        this->peso = this->peso + 1;
        nuevo = new(NodoBin<Tipo>);
        nuevo->crear(p->getInfo(), p->getHijoIzq(), p->getHijoDer());
        return(nuevo);
    }
}





//CONSTRUCTORES =============================================================================

template <typename Tipo>
void ArbolBin<Tipo>::construir(){
    this->setRaiz(nullptr);
    this->peso = 0;
}

template <typename Tipo>
void ArbolBin<Tipo>::crear(int peso, NodoBin<Tipo> * raiz){
    this->setPeso(peso);
    this->setRaiz(raiz);
}

template <typename Tipo>
void ArbolBin<Tipo>::construir(Tipo e, ArbolBin<Tipo> a1, ArbolBin<Tipo> a2){
    ArbolBin<Tipo> arbolAux;
    this->peso = 1;
    this->raiz = new(NodoBin<Tipo>);
    this->getRaiz()->setInfo(e);
    this->getRaiz()->setHijoIzq(copiarNodos(a1.getRaiz()));
    this->getRaiz()->setHijoDer(copiarNodos(a2.getRaiz()));
}
template <typename Tipo>
void ArbolBin<Tipo>::construir(ArbolBin<Tipo> *a){
    this->raiz = copiarNodos(a->getRaiz());
    this->peso = a->getPeso();
}

template <typename Tipo>
void ArbolBin<Tipo>::copiar(ArbolBin<Tipo> *a){
    this->raiz = copiarNodos(a->getRaiz());
    this->peso = a->getPeso();
}


template<class Tipo>
void ArbolBin<Tipo>::destruirNodos(NodoBin<Tipo> **ptrNodo){
    delete *ptrNodo;
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
template <typename Tipo>
int ArbolBin<Tipo>::getPeso(){
    return this->peso;
}
template <typename Tipo>
int ArbolBin<Tipo>::getPeso(NodoBin<Tipo> *raiz){
    list<int> L;
    preOrden(raiz, &L);
    return  L.size();
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
template <typename Tipo>
void ArbolBin<Tipo>::setInfoRaiz(Tipo valor){
    if (this->raiz == nullptr){
        this->raiz = new NodoBin<Tipo>;
        this->raiz->crear(valor);
        this->peso = 1;
    }else{
        this->raiz->setInfo(valor);
    }
}





// INSERTAR ===========================================================================

template <typename Tipo>
void ArbolBin<Tipo>::insertarNodo(Tipo padre, Tipo hijo){
    this->insertarNodo(padre,hijo, this->raiz);
}
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
                    this->peso = this->peso + 1;
                    return;
                }
                if (raiz->getHijoDer() == nullptr){
                    raiz->setHijoDer(nuevo);
                    this->peso = this->peso + 1;
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
        this->peso = this->peso - getPeso(aux);
    }
    else{
        aux = this->getRaiz()->getHijoDer();
        this->getRaiz()->setHijoDer(nullptr);
        this->peso = this->peso - getPeso(aux);
    }
    //this->destruirNodos(&aux);

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


template <typename Tipo>
void ArbolBin<Tipo>::preOrden(NodoBin<Tipo> *raiz, list<Tipo> *L){
    if (raiz!=nullptr){
        L->push_back(raiz->getInfo());
        preOrden(raiz->getHijoIzq(), L);
        preOrden(raiz->getHijoDer(), L);
    }
}
template <typename Tipo>
list<Tipo> ArbolBin<Tipo>::preOrden(){
    list<Tipo> L;
    preOrden(this->raiz, &L);
    return L;
}

template <typename Tipo>
void ArbolBin<Tipo>::postOrden(NodoBin<Tipo> *raiz, list<Tipo> *L){
    if (raiz!=nullptr){
        postOrden(raiz->getHijoIzq(), L);
        postOrden(raiz->getHijoDer(), L);
        L->push_back(raiz->getInfo());
    }
}
template <typename Tipo>
list<Tipo> ArbolBin<Tipo>::postOrden(){
    list<Tipo> L;
    postOrden(this->raiz, &L);
    return L;
}
template <typename Tipo>
void ArbolBin<Tipo>::inOrden(NodoBin<Tipo> *raiz, list<Tipo> *L){
    if (raiz!=nullptr){
        inOrden(raiz->getHijoIzq(), L);
        L->push_back(raiz->getInfo());
        inOrden(raiz->getHijoDer(), L);
    }
}
template <typename Tipo>
list<Tipo> ArbolBin<Tipo>::inOrden(){
    list<Tipo> L;
    inOrden(this->raiz, &L);
    return L;
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
        while((!inorden.empty() && !preorden.empty()) && inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            preIzq.push_back(preorden.front());

            inorden.pop_front();
            preorden.pop_front();
        }
        inorden.pop_front(); //eliminar raiz en inorden

        //LLENAR LISTAS DE LA PARTE DERECHA DEL ARBOL (MIENTRAS LAS LISTAS NO ESTÉN VACÍAS)
        while((!inorden.empty() && !preorden.empty())){
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

    if(!inorden.empty()){
        r = new (NodoBin<Tipo>);
        r->setInfo(postorden.back());
        postorden.pop_back();


        //LLENAR LISTAS DE LA PARTE DERECHA DEL ARBOL (MIENTRAS NO SE ENCUENTRE LA RAIZ EN EL INORDEN)
        while((!inorden.empty() && !postorden.empty()) && inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            postIzq.push_back(postorden.front());

            inorden.pop_front();
            postorden.pop_front();
        }
        inorden.pop_front(); //eliminar raiz en inorden

        //LLENAR LISTAS DE LA PARTE IZQUIERDA DEL ARBOL (MIENTRAS LAS LISTAS NO ESTÉN VACÍAS)
        while(!inorden.empty() && !postorden.empty()){
            postDer.push_back(postorden.front());
            inDer.push_back(inorden.front());

            postorden.pop_front();
            inorden.pop_front();
        }

        r->setHijoIzq(leerArbolPostOrden(postIzq, inIzq));
        r->setHijoDer(leerArbolPostOrden(postDer, inDer));

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
void ArbolBin<Tipo>::LCANodo(NodoBin<Tipo> *r, Tipo e1, Tipo e2, bool *encontrado1, bool *encontrado2, bool *LCAEncontrado, NodoBin<Tipo> **ancestro){
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

                this->LCANodo(r->getHijoIzq(), e1, e2, &encontradoe1hi, &encontradoe2hi, LCAEncontrado, ancestro);
                this->LCANodo(r->getHijoDer(), e1, e2, &encontradoe1hd, &encontradoe2hd, LCAEncontrado, ancestro);

                if(!*LCAEncontrado){
                    *encontrado1 = encontradoe1hi || encontradoe1hd || r->getInfo() == e1;
                    *encontrado2 = encontradoe2hi || encontradoe2hd || r->getInfo() == e2;

                    *LCAEncontrado = *encontrado1 && *encontrado2;

                    if (*LCAEncontrado) {
                        *ancestro = r;
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

template <typename Tipo>
void ArbolBin<Tipo>::getPadre(Tipo e, NodoBin<Tipo> *raiz, bool *band, NodoBin<Tipo> **padre){
    //NodoBin<Tipo> *aux;

    if(raiz != nullptr && !*band){
        if (raiz->getHijoIzq()!=nullptr){
            if(raiz->getHijoIzq()->getInfo() == e){
                *band = true;
                *padre = raiz;
                return;
            }else{
                this->getPadre(e, raiz->getHijoIzq(), band, padre);
                if (*band){
                    return;
                }
            }
        }
        if(raiz->getHijoDer() != nullptr){
            if(raiz->getHijoDer()->getInfo() == e){
                *band = true;
                *padre=raiz;
                return;
            }else{
                this->getPadre(e, raiz->getHijoDer(), band, padre);
                if (*band){
                    return;
                }
            }
        }
    }
}
template <typename Tipo>
NodoBin<Tipo>* ArbolBin<Tipo>::getPadre(Tipo e){
    NodoBin<Tipo> *padre;
    bool band=false;
    padre = nullptr;
    this->getPadre(e,this->raiz,&band, &padre);
    if (padre!=nullptr){
        return padre;
    }else{
        return this->raiz;
    }
}
template <typename Tipo>
list<Tipo> ArbolBin<Tipo>::camino(Tipo e1, Tipo e2){
        list<Tipo> path1,path2;
        NodoBin<Tipo>* ancestro= nullptr;
        bool found1= false,found2= false,lcafound= false,band=false;

        this->LCANodo(this->raiz,e1,e2, &found1, &found2, &lcafound, &ancestro);

        if (ancestro != nullptr){
            caminoNodos(ancestro,e1,&band,&path1);
            caminoNodos(ancestro->getHijoDer(),e2,&band,&path2);
            path1.reverse();
            //path2.reverse();
            path1.splice(path1.end(),path2);

        }
        return path1;

}
template<typename Tipo>
void ArbolBin<Tipo>::caminoNodos(NodoBin<Tipo>* ptr, Tipo e, bool *band, list<Tipo> *camino){
    bool bandI= false, bandD=false;
    if (ptr->getInfo()==e){
        *band= true;
        camino->push_front(ptr->getInfo());
    }
    else if (ptr->getHijoIzq() == nullptr && ptr->getHijoDer() == nullptr)
        *band= false;
    else{
        if (ptr->getHijoIzq()!=nullptr)
            this->caminoNodos(ptr->getHijoIzq(), e, &bandI, camino);
        if (ptr->getHijoDer()!=nullptr)
            this->caminoNodos(ptr->getHijoDer(), e, &bandD, camino);
        if((bandD)||(bandI)){
            *band=true;
            camino->push_front(ptr->getInfo());
        }
    }
}
template<typename Tipo>
queue<NodoBin<Tipo>*> ArbolBin<Tipo>::hojas (queue<NodoBin<Tipo>*> actual){
    queue<NodoBin<Tipo>*> sigNivel, h;
    int hijos = 0;

    //cout<<endl;
    while (!actual.empty()) {
        //hijos=0;
        if (actual.front()->getHijoIzq() != nullptr){
            sigNivel.push(actual.front()->getHijoIzq());
            //hijos++;
        }
        if (actual.front()->getHijoDer() != nullptr){
            sigNivel.push(actual.front()->getHijoDer());
            //hijos++;
        }
        
        //cout << actual.front()->getInfo() << " (" << hijos << ") "<< "  ";
        actual.pop();
    }
    if(!sigNivel.empty()){
        h = hojas(sigNivel);
        return h;
    }else{
        return actual;
    }
    
}

#endif