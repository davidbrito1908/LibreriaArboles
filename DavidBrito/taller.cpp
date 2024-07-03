#include "arbolBin.h"
#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
#include <stack>
#include<queue>
using namespace std;


list<list<string>> Ramas(ArbolBin<string> A, int k){
    int l1,l2;
    list<string> hojas;
    list<list<string>> result;
    if(!A.esNulo()){
        hojas = A.getHojas();
        while(!hojas.empty()){

            list<string> L = A.camino(A.infoRaiz(), hojas.front());

            if (L.size() == k + 1){
                result.push_back(L);
            }
            hojas.pop_front();     
        }   
    }
    return result; 

}


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
                d.erase(remove_if(d.begin(), d.end(), ::isspace),d.end());
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
                    d.erase(remove_if(d.begin(), d.end(), ::isspace),d.end());
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
                    d.erase(remove_if(d.begin(), d.end(), ::isspace),d.end());
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

    list<string> preorden, postorden, inorden;
    bool pre, post;
    string line;
    cin>>c;
    int i;
    for(i=0 ; i<c;i++){
        cin>>k;
        ArbolBin<string> A;    
        A=leer();   
        //A.imprimirPorNiveles(); 
        list<list<string>> ramasKLongitud= Ramas(A, k);
        if(ramasKLongitud.empty()){
            cout<<"None";
        }
        while(!ramasKLongitud.empty()){

            list<string> actual = ramasKLongitud.front();
            cout<<"[";
            while(!actual.empty()){
                if(actual.size()==1){
                    cout<< actual.front();
                }else{
                    cout<< actual.front() << ", ";
                }
                actual.pop_front();
            }
            cout<<"]"<<endl;
            ramasKLongitud.pop_front();
        }
        cout<<endl;
    }

    return 0;
}

