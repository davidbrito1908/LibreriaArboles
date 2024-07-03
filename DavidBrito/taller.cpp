#include "arbolBin.h"
#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
#include <stack>
#include<queue>
using namespace std;


void Ramas(ArbolBin<string> A, int k){
    int l1,l2;
    queue<NodoBin<string>*> c;
    if(A.getRaiz() != nullptr){
        c.push(A.getRaiz());
        A.hojas(c);
        while(!c.empty()){
            list<string> L = A.camino(A.infoRaiz(), c.front()->getInfo());
            if (L.size() == k){
                while(!L.empty()){
                    cout<<L.front()<<", ";
                    L.pop_front();
                }
                cout<<endl;
            }
            c.pop();
        }
    }
    
}


/*

ArbolBin<string> leer(){
    ArbolBin<string> A;
    A.construir();
    string tipo,datos, info,d, linea;
    int k,i;
    list<string> listaPre, listaPos, listaIn;
    list<string> preorden, postorden, inorden;
    bool pre=false;
    //cin>>tipo;

    preorden.clear();
    postorden.clear();
    inorden.clear();
    listaPre.clear();
    listaPos.clear();
    listaIn.clear();

    for(i=0;i<2;i++){
        //cout<<"aaaaaaa";
        cin>>tipo;
        cout<<tipo<<endl;
        if (tipo == "PREORDEN"){
            pre=true;
            getline(cin, datos);
            stringstream data(datos);
            data>>datos;
            getline(data, datos, '[');
            getline(data, datos, ']');
            //cout<<info<<endl;
            stringstream a(datos);
            

            while(getline(a, d, ',')){
                preorden.push_back(d);
                //cout<<preorden.back();
            }
            listaPre = preorden;

        }else{
            if (tipo == "POSTORDEN"){
                pre=false;
                getline(cin, datos);
                stringstream data(datos);
                data>>datos;
                getline(data, datos, '[');
                getline(data, datos, ']');
                //cout<<datos<<endl;
                stringstream a(datos);

                //list<string> postorden;

                while(getline(a, d, ',')){
                    postorden.push_back(d);
                    //cout<<postorden.back();
                }
                listaPos = postorden;

            }
            else{
                if(tipo == "INORDEN"){
                    //cout<<"inordennnnn";
                    getline(cin, datos);
                    stringstream data(datos);
                    data>>datos;
                    getline(data, datos, '[');
                    getline(data, datos, ']');
                    //cout<<datos<<endl;
                    stringstream a(datos);

                    list<string> inorden;
                    while(getline(a, d, ',')){
                        inorden.push_back(d);
                        //cout<<inorden.back();
                    }
                    listaIn = inorden;

                }
            }
        }
    }
    
    if(pre){
        /*while(!listaPre.empty()){
            cout<<listaPre.front();
            listaPre.pop_front();
        }
        while(!listaIn.empty()){
            cout<<listaIn.front();
            listaIn.pop_front();
        }*/
 /*       if( listaPre.size() == listaIn.size()){
            cout<<"xd";
        }
        NodoBin<string> *r = A.leerArbol(listaPre, listaIn);
        //A.setRaiz(r);
        //A.imprimirPreOrden();
    }else{
        //NodoBin<string> *r = A.leerArbolPostOrden(postorden, inorden);
    }
    preorden.clear();
    postorden.clear();
    inorden.clear();
    listaPre.clear();
    listaPos.clear();
    listaIn.clear(); 

    //A.imprimirPorNiveles();
    return(A);

}*/



ArbolBin<string> leer(){
    ArbolBin<string>(A);
    string tipo,datos, info,d;
    int k,i;
    list<string> preorden, inorden, postorden;
    bool pre=false;
    //cin>>k;
    for(i=0;i<2;i++){
        cin>>tipo;
        if (tipo == "PREORDEN"){
            pre=true;
            getline(cin, datos);
            stringstream data(datos);
            getline(data, info, '[');
            getline(data, info, ']');
            stringstream a(info);

            while(getline(a, d, ',')){
                preorden.push_back(d);
            }

        }else{
            if (tipo == "POSTORDEN"){
                getline(cin, datos);
                stringstream data(datos);
                getline(data, info, '[');
                getline(data, info, ']');
                stringstream a(info);

                while(getline(a, d, ',')){
                    postorden.push_back(d);
                }

            }
            else{
                getline(cin, datos);
                stringstream data(datos);
                getline(data, info, '[');
                getline(data, info, ']');
                stringstream a(info);

                while(getline(a, d, ',')){
                    inorden.push_back(d);
                }
            }
        }

    }
    
    if(pre){
        A.setRaiz(A.leerArbol(preorden, inorden));
    }else{
        A.setRaiz(A.leerArbolPostOrden(postorden, inorden));
    }
    preorden.clear();
    postorden.clear();
    inorden.clear();

    return(A);

}








int main(){

    string linea;
    int c, k;
    string nombre, datos, num;
    
    //queue<string> preorden1, postorden1, inorden1;
    list<string> preorden, postorden, inorden;
    bool pre, post;
    string line;
    cin>>c;
    int i;
    for(i=0 ; i<c;i++){
        cin>>k;
        ArbolBin<string> A;
        //A.construir();
        A=leer();
        A.imprimirPorNiveles();
        //Ramas(A, k);
    }

    return 0;
}

