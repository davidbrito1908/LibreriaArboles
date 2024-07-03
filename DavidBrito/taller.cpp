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




ArbolBin<string> leer(){
    ArbolBin<string>(A);
    string tipo,datos, info,d;
    int k,i;
    list<string> preorden, inorden, postorden;
    bool pre=false;
    cin>>k;
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
                stringstream data(datos);
                getline(data, info, '[');
                getline(data, info, ']');
                stringstream a(info);

                while(getline(a, d, ',')){
                    postorden.push_back(d);
                }

            }
            else{
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
        while(!preorden.empty()){
            cout << preorden.front();
            cout<<inorden.front();
            inorden.pop_front();
            preorden.pop_front();
        }
        //A.setRaiz(A.leerArbol(preorden, inorden));
    }else{
        //A.setRaiz(A.leerArbolPostOrden(postorden, inorden));
    }

    //A.imprimirPorNiveles();
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
        cin>>num;
        stringstream a(num);
        a>>k;
        ArbolBin<string> A;
        A=leer();
        //Ramas(A, k);
    }

    return 0;
}

