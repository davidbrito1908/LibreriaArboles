#include <iostream>
#include "arbolBin.h"
#include <queue>
#include <list>
#include "arboln.h"
using namespace std;
int main(){
    ArbolBin<int> A,B, C,D;
    NodoBin<int> r, hi,hd;
    

    hi.crear(2,nullptr,nullptr);
    hd.crear(3,nullptr,nullptr);
    //r.crear(1,&hi,&hd);
    r.crear(1, nullptr, &hd);
    NodoBin<int> r2, hi2,hd2;
    hi2.crear(5,nullptr,nullptr);
    hd2.crear(6,nullptr,nullptr);
    r2.crear(4,&hi2,&hd2);

    //B.setRaiz(&r2);

    A.construir();
    A.setRaiz(&r);
    A.insertarNodo(1,7,A.getRaiz());
    A.imprimirPreOrden(A.getRaiz());

    //B = A.hijoIzq();
    //B.imprimirPreOrden(B.getRaiz());
    //C= A.hijoDer();
    //D.construir(A.infoRaiz(), B, C);
    //D.imprimirPreOrden(D.getRaiz());
    //D.construir();
    /*   list<int> preorden, inorden;

    preorden.push_back(1);
    preorden.push_back(2);
    preorden.push_back(3);
    preorden.push_back(4);
    preorden.push_back(5);
    preorden.push_back(6);
    preorden.push_back(7);

    inorden.push_back(3);
    inorden.push_back(2);
    inorden.push_back(4);
    inorden.push_back(1);
    inorden.push_back(6);
    inorden.push_back(5);
    inorden.push_back(7);

    A.setRaiz(A.leerArbol(preorden, inorden));
    //A.imprimirPreOrden(A.getRaiz());
    //A.imprimirPostOrden(A.getRaiz());
    //A.imprimirInOrden(A.getRaiz());

    queue<NodoBin<int>*> c;
    c.push(A.getRaiz());
    A.imprimirPorNiveles(c);*/
    return 0;
}