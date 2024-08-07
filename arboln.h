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


/*


template<class Elemento>
void ArbolN<Elemento>::LCA(NodoAN<Elemento> *actual, Elemento origen, Elemento destino, int &contadorEncontrado, int *contTemp, bool &LCAEncontrado, Elemento &ancestro){
    int encontrados = 0;
    int totalTmp = 0;
    NodoAN<Elemento> *auxN;
    if(actual == nullptr){
        return;
    }
    auxN = actual->getHijoIzq();
    while (auxN != nullptr)
    {
        encontrados = 0;
        this->LCA(auxN,origen,destino, contadorEncontrado,&encontrados,LCAEncontrado,ancestro);
        totalTmp = totalTmp + encontrados;
        *contTemp = encontrados;
        auxN = auxN->getHermanoDer();
    }
    if(totalTmp == 2 && !LCAEncontrado){
        ancestro = actual->getInfo();
        LCAEncontrado = true;
    }
    *contTemp = totalTmp;
    if(actual->getInfo() == origen || actual->getInfo() == destino){
        ++contadorEncontrado;
        ++(*contTemp);
    }
}

template<class Elemento>
Elemento ArbolN<Elemento>::LCA(Elemento origen, Elemento destino){
    bool LCAEncontrado;
    int total = 0, cont = 0;
    Elemento ancestro;

    LCAEncontrado = false;
    this->LCA(NodoRaiz,origen,destino,total,&cont,LCAEncontrado,ancestro);
    return ancestro;
}

template<class Elemento>
void ArbolN<Elemento>::camino(NodoAN<Elemento> *actual, Elemento origen, Elemento destino, int &contadorEncontrado, int *contTemp, bool &LCAEncontrado, list<Elemento> &salida, list<Elemento> &aux){
    int encontrados = 0;
    int totalTmp = 0;
    NodoAN<Elemento> *auxN;
    if(actual == nullptr){
        return;
    }

    auxN = actual->getHijoIzq();
    while (auxN != nullptr)
    {
        encontrados = 0;
        this->camino(auxN,origen,destino, contadorEncontrado,&encontrados,LCAEncontrado,salida,aux);
        totalTmp = totalTmp + encontrados;
        *contTemp = encontrados;
        auxN = auxN->getHermanoDer();
    }
    if(totalTmp == 1){
        if(contadorEncontrado == 2){
            aux.push_front(actual->getInfo());
        }else{
            salida.push_back(actual->getInfo());
        }
    }else if(totalTmp == 2 && !LCAEncontrado){
        salida.push_back(actual->getInfo());
        salida.splice(salida.end(),aux);
        for (auto v: salida)
        {
            cout << v << endl;
        }
        LCAEncontrado = true;
    }
    *contTemp = totalTmp;
    if(actual->getInfo() == origen || actual->getInfo() == destino){
        ++contadorEncontrado;
        ++(*contTemp);
        if(contadorEncontrado == 2){
            aux.push_front(actual->getInfo());
        }else{
            salida.push_back(actual->getInfo());
        }
    }
}

template<class Elemento>
list<Elemento> ArbolN<Elemento>::camino(Elemento origen, Elemento destino){
    bool LCAEncontrado;
    int total = 0, cont = 0;
    list<Elemento> camino,aux;
    LCAEncontrado = false;
    this->camino(NodoRaiz,origen,destino,total,&cont,LCAEncontrado,camino,aux);
    return camino;
}























template <class elemento>
elemento ArbolN<elemento>::encontrarPadreElemento(NodoArbolN<elemento>* p,elemento hijo) {
    NodoArbolN<elemento>  *actual;
	elemento padre;
	if (p != NULL){
		actual = p->getHijoIzquierdo();
		while (actual != NULL) {
			if(actual->getHermanoDerecho() != NULL){
				if(actual->getHermanoDerecho()->getInfo() == hijo){
					return (p->getInfo());
				}
			}
			if (actual->getInfo() == hijo) {
				return (p->getInfo());
			}else{
				padre = encontrarPadreElemento(actual, hijo);
				if(padre != -1){
					return (padre);
				}
			}
        	actual = actual->getHermanoDerecho();
    	}
	}
	return (-1);
}
template <class elemento>
elemento ArbolN<elemento>::encontrarPadreElemento(elemento valor){
    elemento padre;
	if(this->raiz != NULL){
		padre = this->encontrarPadreElemento(this->raiz,valor);
	}else{
		cout<<"Raiz esta vacia"<<endl;
	}
	return (padre);
}

template <class elemento>
int ArbolN<elemento>::altura(NodoArbolN<elemento>* p) {
   	int maxAltura = 0,cont = 0;
    NodoArbolN<elemento>* hijo;
    if (p != NULL){
		hijo = p->getHijoIzquierdo();
    	while (hijo != NULL) {
       		maxAltura = max(maxAltura, altura(hijo));
        	hijo = hijo->getHermanoDerecho();
    	}
		cont = 1;
	} 
    return (cont + maxAltura);
}

template <class elemento>
int ArbolN<elemento>::altura(){
	int result = 0;
	result = altura(this->raiz);
    return (result);
}

template <class elemento>
int ArbolN<elemento>::contarHojas(NodoArbolN<elemento>* p) {
	NodoArbolN<elemento>* hijo;
	int count = 0;
	if (p != NULL){
		if (p->getHijoIzquierdo() == NULL){
			return (1);
		} 
		 hijo = p->getHijoIzquierdo();
		while (hijo != NULL) {
			count += contarHojas(hijo);
			hijo = hijo->getHermanoDerecho();
		}
	} 
    return (count);
}

template <class elemento>
int ArbolN<elemento>::contarHojas() {
	int result = 0;
	result = this->contarHojas(this->raiz);
    return (result);
}

template <class elemento>
bool ArbolN<elemento>::sonIsomorfos(NodoArbolN<elemento>* nodo1, NodoArbolN<elemento>* nodo2) {
    NodoArbolN<elemento> *hijo1,*hijo2;
	if ((nodo1 == NULL) && (nodo2 == NULL)){
		return (true);
	} 
    if ((nodo1 == NULL) || (nodo2 == NULL)){
		return (false);
	} 
    hijo1 = nodo1->getHijoIzquierdo();
    hijo2 = nodo2->getHijoIzquierdo();
    while ((hijo1 != NULL) && (hijo2 != NULL)) {
        if (!sonIsomorfos(hijo1, hijo2)) {
            return (false);
        }
        hijo1 = hijo1->getHermanoDerecho();
        hijo2 = hijo2->getHermanoDerecho();
    }
    return (hijo1 == NULL && hijo2 == NULL);
}

template <class elemento>
bool ArbolN<elemento>::sonIsomorfos(ArbolN<elemento>& otro) {
	bool result = false;
	result = sonIsomorfos(this->raiz, otro.getRaiz());
    return (result);
}

template <class elemento>
list<elemento> ArbolN<elemento>::encontrarCamino(elemento elemento1, elemento elemento2) {
    vector<NodoArbolN<elemento>*> ruta1, ruta2;
	list<elemento> camino;
	int i = 0;
    if ((encontrarRuta(this->raiz, elemento1, ruta1)) || (encontrarRuta(this->raiz, elemento2, ruta2))) {
        while ((i < ruta1.size()) && (i < ruta2.size()) && (ruta1[i] == ruta2[i])) {
			i++;
		}

		for (int j = 0; j < i; j++) {
			camino.push_back(ruta1[j]->getInfo());
		}

		for (int j = i; j < ruta1.size(); j++) {
			camino.push_back(ruta1[j]->getInfo());
		}

		for (int j = ruta2.size() - 1; j >= i; j--) {
			camino.push_back(ruta2[j]->getInfo());
		}
    }
    return (camino);
}

template <class elemento>
bool ArbolN<elemento>::encontrarRuta(NodoArbolN<elemento>* nodo, elemento objetivo, vector<NodoArbolN<elemento>*> &ruta) {
    NodoArbolN<elemento> *hijo;
	if (nodo != NULL){
		ruta.push_back(nodo);
		if (nodo->getInfo() == objetivo){
			return (true);
		} 
		hijo = nodo->getHijoIzquierdo();
		while (hijo != NULL) {
			if (encontrarRuta(hijo, objetivo, ruta)) {
				return (true);
			}
			hijo = hijo->getHermanoDerecho();
		}
		ruta.pop_back();
	}
    return (false);
}

template <class elemento>
NodoArbolN<elemento>* ArbolN<elemento>::ancestroComunMasReciente(NodoArbolN<elemento>* nodo, elemento elemento1, elemento elemento2) {
    vector<NodoArbolN<elemento>*> ruta1, ruta2;
	int i = 0;
    if ((!encontrarRuta(nodo, elemento1, ruta1)) || (!encontrarRuta(nodo, elemento2, ruta2))) {
        return (NULL); 
    }
    while ((i < ruta1.size()) && (i < ruta2.size()) && (ruta1[i] == ruta2[i])) {
        i++;
    }
    return (ruta1[i - 1]);
}

template <class elemento>
elemento ArbolN<elemento>::ancestroComunMasReciente(elemento elemento1, elemento elemento2) {
    elemento result;
	NodoArbolN<elemento> *ancestro;
	ancestro = ancestroComunMasReciente(this->raiz, elemento1, elemento2);
	if(ancestro != NULL){
		result = ancestro->getInfo();
	}
	return (result);
}

template <class elemento>
void ArbolN<elemento>::diametro(NodoArbolN<elemento>* p, int& diametro,int &altura, vector<elemento>& camino) {
    int alturaMax2 = 0, alturaHijo;
	altura = 0;
	vector<elemento> caminoMax1, caminoMax2;
	NodoArbolN<elemento>* hijo;
	if (p != NULL){
		hijo = p->getHijoIzquierdo();
		while (hijo != NULL) {
			vector<elemento> caminoHijo;
			this->diametro(hijo, diametro,alturaHijo,caminoHijo);
			if (alturaHijo > altura) {
				alturaMax2 = altura;
				caminoMax2 = caminoMax1;
				altura = alturaHijo;
				caminoMax1 = caminoHijo;
			} else if (alturaHijo > alturaMax2) {
				alturaMax2 = alturaHijo;
				caminoMax2 = caminoHijo;
			}
			hijo = hijo->getHermanoDerecho();
		}

		if (altura + alturaMax2 > diametro) {
			diametro = altura + alturaMax2;
			camino = caminoMax1;
			camino.push_back(p->getInfo());
			camino.insert(camino.end(), caminoMax2.rbegin(), caminoMax2.rend());
		}

		caminoMax1.push_back(p->getInfo());
		altura++;
	}
}

template <class elemento>
vector<elemento> ArbolN<elemento>::diametro() {
    int diametro = 0,altura = 0;
    vector<elemento> camino;
    this->diametro(this->raiz, diametro, altura, camino);
    return (camino);
}

















*/

#endif
