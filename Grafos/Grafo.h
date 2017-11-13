//
//  Grafo.h
//  Grafos
//
//  Created by Angel Trevino on 11/10/17.
//  Copyright © 2017 Angel Odiel Treviño Villanueva. All rights reserved.
//


#ifndef Grafo_h
#define Grafo_h

#include <fstream>
using namespace std;

class Grafo{
private:
    int Lugares;
    int Rutas[500][500];
    
public:
    Grafo(string archivo){
            
        ifstream Datos;
        Datos.open("/Users/angel/Desktop/ITC/Estructura de Datos/Programas/Grafos/"+archivo+".txt");
    
        Datos >> Lugares;
        for(int i = 0; i < Lugares; i++ ) //filas
            for(int j = 0; j < Lugares; j++)//columnas
                Datos >> Rutas[j][i];
    }
    
    //BreadthFirst
    void BreadthFirst(){
        int Queue[100] = {-1};
        int Origen = 0, Agregar = 0; //Origen como vas moviendote en el array y Agregar en como estas agregando los datos para Queue
        bool Repite = false;
        Queue[0] = Origen;
        cout << Queue[0] <<" ";
        while(Origen <= 4){ //recorres fila por fila y vas metiendo los que tienen camino y no se repiten
            for(int i = 0; i < Lugares; i++){
                for(int j = 0; j < Origen; j++){
                    if(Queue[j] == Rutas[Queue[Origen]][i]){
                        Repite = true;
                    }
                }
                if(Rutas[Queue[Origen]][i] != 0 && Repite == false){
                    Queue[Agregar] = i;
                    Agregar++;
                }
                Repite = false;
            }
            Origen++;
        }
        
        for(int i = 0; i < Lugares-1; i++){
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
    
    //Depth First
    void DepthFirst(){
        int Stack[20] = {-1};
        int Despliega[8] = {-1}; //este guardara los datos a despliegar
        int tope = 0; //este es el tope del stack
        int Cont = 0;//Este es para agregar en el despliega
        bool Repite = false; //para ver si se repite un valor en el despliega
        Stack[tope] = 0; //agrega la posicion 0 al stack
        Despliega[0] = Stack[tope];
        while(Cont < 4){
            for(int i = Lugares-1; i>= 0; i--){//para pasar por toas las filas de cada columna
                if(Rutas[Despliega[Cont]][i] != 0){//existe una ruta
                    for(int j = 0; j < Lugares; j++){
                        if(i == Despliega[j])
                            Repite = true;
                    }
                    if(Repite == false){
                        Stack[tope] = i;
                        tope++;
                    }
                    Repite = false;
                }
            }
            tope--;
            Cont++;
            Despliega[Cont] = Stack[tope];
        }
        
        for(int i = 0; i < Lugares; i++)
            cout<< Despliega[i] << " ";
        cout << endl;
    }
    
    //buscar datos
    int Buscar(int x, int y){
        return 3;
    }
    
};


#endif /* Grafo_h */
