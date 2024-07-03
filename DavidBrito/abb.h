#ifndef ABB_H_
#define ABB_H_
#include "arbolBin.h"

template<typename Tipo>
class ABB: public ArbolBin<Tipo>{
    private:
        /* data */
        NodoBin<Tipo>* buscarNodo(Tipo e);
        void insertarNodo(NodoBin<Tipo> *r, Tipo e);
    public:
        bool buscar(Tipo e);
        void insertar(Tipo e);
        NodoBin<Tipo>* encontrar(Tipo e);
        void eliminar(Tipo e);
};
    
template<typename Tipo>
NodoBin<Tipo>* ABB<Tipo>::buscarNodo(Tipo e){
    NodoBin<Tipo> *act;

    act = this->getRaiz();
    while(act != nullptr && act->getInfo() != e){
        if (e < act->getInfo()){
            act = act->getHijoIzq();
        }else{
            act = act->getHijoDer();
        }
    }
    return act;
}

template<typename Tipo>
bool ABB<Tipo>::buscar(Tipo e){
    NodoBin<Tipo> *p;
    p = this->buscarNodo(e);
    return (p!=nullptr);
}
template<typename Tipo>
NodoBin<Tipo>* ABB<Tipo>::encontrar(Tipo e){
    NodoBin<Tipo> *p;
    p = this->buscarNodo(e);
    return (p);
}
template <typename Tipo>
void ABB<Tipo>::eliminar(Tipo e){
    NodoBin<Tipo> *elim;
    int dir=0;
    NodoBin<Tipo> *act;

    act = this->getPadre(e);
    if (act->getHijoIzq() != nullptr){
        if (act->getHijoIzq()->getInfo() == e){
            elim = act->getHijoIzq();
            dir=0;
        }
    }
    if (act->getHijoDer() != nullptr){
        if (act->getHijoDer()->getInfo() == e){
            elim = act->getHijoDer();
            dir=1;
        }
    }


    if((elim->getHijoIzq() == nullptr) && (elim->getHijoDer() == nullptr)){
        if(dir){
            act->setHijoDer(nullptr);
        }else{
            act->setHijoIzq(nullptr);
        }
        delete(elim);
        return;
    }else{
        if((elim->getHijoIzq() == nullptr) || (elim->getHijoDer() == nullptr)){
            if((elim->getHijoIzq() == nullptr)){
                if (dir){
                    act->setHijoDer(elim->getHijoDer());
                }else{
                    act->setHijoIzq(elim->getHijoDer());
                }
            }else{

                if (dir){
                    act->setHijoDer(elim->getHijoIzq());
                }else{
                    act->setHijoIzq(elim->getHijoIzq());
                }

            }
            elim->setHijoIzq(nullptr);
            elim->setHijoDer(nullptr);
            delete(elim);
        }else{
            NodoBin<Tipo> *aux, *nuevo, *padrenuevoAnterior;
            aux = elim->getHijoDer();
            padrenuevoAnterior = aux->getHijoIzq();
            nuevo = padrenuevoAnterior->getHijoIzq();
            if(padrenuevoAnterior != nullptr){
                while(nuevo != nullptr){
                    aux=padrenuevoAnterior;
                    padrenuevoAnterior = nuevo;
                    nuevo=nuevo->getHijoIzq();
                }

                aux->setHijoIzq(padrenuevoAnterior->getHijoDer());
                padrenuevoAnterior->setHijoIzq(elim->getHijoIzq());
                padrenuevoAnterior->setHijoDer(elim->getHijoDer());

                if (dir){
                    act->setHijoDer(padrenuevoAnterior);
                }else{
                    act->setHijoIzq(padrenuevoAnterior);
                }

                elim->setHijoIzq(nullptr);
                elim->setHijoDer(nullptr);
                delete(elim);
            }else{
                aux->setHijoIzq(elim->getHijoIzq());
                if (dir){
                    act->setHijoDer(aux);
                }else{
                    act->setHijoIzq(aux);
                }
            }
            
        }
    }



}

// Procedimiento Privado
template<typename Tipo>
void ABB<Tipo>::insertarNodo(NodoBin<Tipo> *r, Tipo e){
    NodoBin<Tipo> *nodo;

    if(r == nullptr){
        r = new(NodoBin<Tipo>);
        r->crear(e);
        return;

    }else{
        if (e< (r->getInfo())){
            if (r->getHijoIzq() == nullptr){
                nodo = new(NodoBin<Tipo>);
                nodo->crear(e);
                r->setHijoIzq(nodo);
                return;
            }else{
                this->insertarNodo(r->getHijoIzq(), e);
            }
        }
        else{
            if(r->getHijoDer() == nullptr){
                nodo = new(NodoBin<Tipo>);
                nodo->crear(e);
                r->setHijoDer(nodo);
                return;
            }else{
                this->insertarNodo(r->getHijoDer(), e);
            }
        }
    }
}

template<typename Tipo>
void ABB<Tipo>::insertar(Tipo e){
    //if(!buscar(e))
    if(this->raiz == nullptr){
        this->raiz = new NodoBin<Tipo>;
        this->raiz->crear(e);
        return;
    }
    this->insertarNodo(this->raiz, e);
}
#endif