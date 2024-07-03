#include <iostream>
#include "arbolBin.h"
#include <queue>
#include <list>
#include "arboln.h"
#include "abb.h"
using namespace std;
int main(){
    /*ArbolN<int> A, B,C;
    A.construir();
    A.setInfoRaiz(1);
    A.insertarNodo(1,2,A.getRaiz());
    A.insertarNodo(1,3,A.getRaiz());
    A.insertarNodo(1,4,A.getRaiz());
    A.insertarNodo(2,8,A.getRaiz());
    A.insertarNodo(2,10,A.getRaiz());
    A.insertarNodo(3,9,A.getRaiz());
    A.imprimirPorNiveles();

    B.setInfoRaiz(16);
    B.insertarNodo(16,17);
    B.insertarNodo(16,-5);
    B.insertarNodo(-5,11);

    A.insertarSubarbol(B);
    A.eliminarSubarbol(4);
    A.imprimirPorNiveles();
    C.construir(&B);
    C.imprimirPorNiveles();*/


    ArbolBin<int> A;
    A.setInfoRaiz(1);
    A.insertarNodo(1,2);
    A.insertarNodo(2,3);
    A.insertarNodo(2,4);
    A.insertarNodo(1,5);
    A.insertarNodo(5,6);
    A.insertarNodo(5,7);
    A.imprimirPorNiveles();
    list<int> L = A.camino(6,7);
    while(!L.empty()){
        cout<<L.front() << " ";
        L.pop_front();
    }



    /*while(!L.empty()){
        cout<<L.front();
        L.pop_front();
    }*/
    return 0;
}

void pruebas(){
        ArbolBin<int> A,B, C,D;
    NodoBin<int> r, hi,hd;
    

    hi.crear(2);
    hd.crear(5);
    r.crear(1,&hi,&hd);
    //r.crear(1, nullptr, &hd);
    NodoBin<int> r2, hi2,hd2;
    hi2.crear(5);
    hd2.crear(6);
    r2.crear(4,&hi2,&hd2);

    B.setRaiz(&r2);

    A.construir();
    //A.setRaiz(&r);
    //A.insertarNodo(1,7,A.getRaiz());
    /*A.insertarNodo(2,3,A.getRaiz());
    A.insertarNodo(2,4,A.getRaiz());
    A.insertarNodo(5,6,A.getRaiz());
    A.insertarNodo(5,7,A.getRaiz());
    A.insertarNodo(7,9,A.getRaiz());
    A.insertarNodo(6,8,A.getRaiz());*/
    //A.imprimirPreOrden(A.getRaiz());

    //int ancestro = A.LCA(3,4);
    queue<NodoBin<int>*> c;
    c.push(A.getRaiz());
    //A.imprimirPorNiveles(c);
    /*list<int> primos = A.getPrimos(8, c);
    while (!primos.empty()){
        cout << primos.front()<<endl;
        primos.pop_front();
    }*/

    //int a = A.LCA(6,7);
    //cout << endl << a;
    //cout<<endl<<ancestro;
    B=A.hijoDer();
    c.pop();
    c.push(B.getRaiz());
    //B.imprimirPorNiveles(c);


    /*C.construir();
    NodoBin<int> r3, r4;
    r3.crear(9, nullptr, nullptr);
    r4.crear(2, nullptr, nullptr);
    C.setRaiz(&r3);
    C.getRaiz()->setHijoIzq(&r4);
    C.insertarSubarbol(B);
    C.eliminarSubarbol(1);
    C.insertarSubarbol(A);
    C.imprimirPreOrden(C.getRaiz());*/
    //B = A.hijoIzq();
    //B.imprimirPreOrden(B.getRaiz());
    //C= A.hijoDer();
    //D.construir(A.infoRaiz(), B, C);
    //D.imprimirPreOrden(D.getRaiz());
    //D.construir();
       list<int> preorden, inorden;

    preorden.push_back(3);
    preorden.push_back(4);
    preorden.push_back(2);
    preorden.push_back(6);
    preorden.push_back(7);
    preorden.push_back(5);
    preorden.push_back(1);

    inorden.push_back(3);
    inorden.push_back(2);
    inorden.push_back(4);
    inorden.push_back(1);
    inorden.push_back(6);
    inorden.push_back(5);
    inorden.push_back(7);

    A.setRaiz(A.leerArbolPostOrden(preorden, inorden));
    //A.imprimirPreOrden(A.getRaiz());
    //A.imprimirPostOrden(A.getRaiz());
    //A.imprimirInOrden(A.getRaiz());

    //queue<NodoBin<int>*> c;
    c.push(A.getRaiz());
    //A.imprimirPreOrden();

    ABB<int> O;
    O.construir();
    O.insertar(15);
    O.insertar(5);
    O.insertar(3);
    O.insertar(12);
    O.insertar(16);
    O.insertar(10);
    O.insertar(13);
    O.insertar(20);
    O.insertar(23);
    O.insertar(18);
    O.insertar(6);
    O.insertar(7);
    O.eliminar(13);

    int padre = O.getPadre(10)->getInfo();
    cout<<endl<<padre<<endl;

    O.imprimirPorNiveles();
    /*list<int> P = O.inOrden();
    while(!P.empty()){
        cout<<P.front()<< " ";
        P.pop_front();
    }*/
    if (O.buscar(12)){
        cout<<"Si esta";
    }
    //NodoBin<int> *N = O.encontrar(1);
    //cout << N->getInfo();
    //A.imprimirPreOrden();

}