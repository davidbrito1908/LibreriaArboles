#ifndef NODO_H_
#define NODO_H_


template <typename Tipo>

class Nodo{
    protected:
        Tipo info;
        Nodo<Tipo> *hijoIzq, *herDer;
    public:
        void crear(Tipo elemento, Nodo<Tipo> * hijoIzq, Nodo<Tipo>*HerDer);
        Tipo getInfo();
        Nodo<Tipo> * getHijoIzq();
        Nodo<Tipo> * getHerDer();
        void setInfo(Tipo elemento);
        void setHijoIzq(Nodo<Tipo> * apuntador);
        void setHerDer(Nodo<Tipo> * apuntador);

};
template <typename Tipo>
void Nodo<Tipo>::crear(Tipo elemento, Nodo<Tipo> * hijoIzq, Nodo<Tipo>*HerDer){
    this->setInfo(elemento);
    this->setHijoIzq(hijoIzq);
    this->setHerDer(HerDer);
}


template <typename Tipo>
Tipo Nodo<Tipo>::getInfo(){
    return this->info; 
}

template <typename Tipo>
Nodo<Tipo> * Nodo<Tipo>::getHijoIzq(){
    return this->hijoIzq;
}
template <typename Tipo>
Nodo<Tipo> * Nodo<Tipo>::getHerDer(){
    return this->herDer;
}

template <typename Tipo>
void Nodo<Tipo>::setInfo(Tipo elemento){
    this->info = elemento;
}

template <typename Tipo>
void Nodo<Tipo>::setHijoIzq(Nodo<Tipo> * apuntador){
    this->hijoIzq = apuntador;
}
template <typename Tipo>
void Nodo<Tipo>::setHerDer(Nodo<Tipo> * apuntador){
    this->herDer = apuntador;
}

#endif