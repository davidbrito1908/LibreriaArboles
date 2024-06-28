#ifndef NODO_H_
#define NODO_H_


template <typename Tipo>

class NodoBin{
    protected:
        Tipo info;
        NodoBin<Tipo> *hijoIzq, *herDer;
    public:
        void crear(Tipo elemento, NodoBin<Tipo> * hijoIzq, NodoBin<Tipo>*HerDer);
        Tipo getInfo();
        NodoBin<Tipo> * getHijoIzq();
        NodoBin<Tipo> * getHerDer();
        void setInfo(Tipo elemento);
        void setHijoIzq(NodoBin<Tipo> * apuntador);
        void setHerDer(NodoBin<Tipo> * apuntador);

};
template <typename Tipo>
void NodoBin<Tipo>::crear(Tipo elemento, NodoBin<Tipo> * hijoIzq, NodoBin<Tipo>*HerDer){
    this->setInfo(elemento);
    this->setHijoIzq(hijoIzq);
    this->setHerDer(HerDer);
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
NodoBin<Tipo> * NodoBin<Tipo>::getHerDer(){
    return this->HerDer;
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
void NodoBin<Tipo>::setHerDer(NodoBin<Tipo> * apuntador){
    this->HerDer = apuntador;
}

#endif