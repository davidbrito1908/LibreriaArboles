#ifndef NODOBIN_H_
#define NODOBIN_H_


template <typename Tipo>

class NodoBin{
    protected:
        Tipo info;
        NodoBin<Tipo> *hijoIzq, *hijoDer;
    public:
        void crear(Tipo elemento, NodoBin<Tipo> * hijoIzq, NodoBin<Tipo>*hijoDer);
        Tipo getInfo();
        NodoBin<Tipo> * getHijoIzq();
        NodoBin<Tipo> * getHijoDer();
        void setInfo(Tipo elemento);
        void setHijoIzq(NodoBin<Tipo> * apuntador);
        void setHijoDer(NodoBin<Tipo> * apuntador);

};
template <typename Tipo>
void NodoBin<Tipo>::crear(Tipo elemento, NodoBin<Tipo> * hijoIzq, NodoBin<Tipo>*hijoDer){
    this->setInfo(elemento);
    this->setHijoIzq(hijoIzq);
    this->setHijoDer(hijoDer);
}


template <typename Tipo>
Tipo NodoBin<Tipo>::getInfo(){
    return this->info; 
}

template <typename Tipo>
NodoBin<Tipo> * NodoBin<Tipo>::getHijoIzq(){
    return this->hijoIzq;
}
template <typename Tipo>
NodoBin<Tipo> * NodoBin<Tipo>::getHijoDer(){
    return this->hijoDer;
}

template <typename Tipo>
void NodoBin<Tipo>::setInfo(Tipo elemento){
    this->info = elemento;
}

template <typename Tipo>
void NodoBin<Tipo>::setHijoIzq(NodoBin<Tipo> * apuntador){
    this->hijoIzq = apuntador;
}
template <typename Tipo>
void NodoBin<Tipo>::setHijoDer(NodoBin<Tipo> * apuntador){
    this->hijoDer = apuntador;
}

#endif