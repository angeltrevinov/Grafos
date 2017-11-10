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
    int Fila[1000] = {-1};
    int Despliega[1000] = {-1};
    
public:
    Grafo(string archivo){
            
        ifstream Datos;
        Datos.open("/Users/angel/Desktop/ITC/Estructura de Datos/Programas/Grafos/"+archivo+".txt");
            
        Datos >> Lugares;
            
        for(int i = 0; i < Lugares; i++ ){ //filas
            for(int j = 0; j < Lugares; j++){//columnas
                Datos >> Rutas[j][i];
            }
        }
    }
    
    
    void BreathFirst(){
        int Procesado; //para saber en que origen estamos
        int Index = 0; // Para la fila
        int j=0; //para el despliega
        bool Repite = false; //para ver que no se repite
        
        Fila[0] = 0;//pone el primer indicie
        while(Fila[0] != -1){ //mientras que no este vacia
            
            //para ver si se repite el numero que vas a insertar a despliega
            for(int i = 0; i <= Index; i++){
                if(Fila[0] != Fila[i]){
                    Repite = true;
                }
            }
            //si se repite, no lo agregas
            if(Repite != true){
                Despliega[j] = Fila[0];
                j++;
                
            }
            Repite = false;//regresa a false para hacerlo de nuevo
            Procesado = Despliega[j];
            
            for(int i = 0; i < Lugares; i++){ //va insertando a la fila
                if(Rutas[Procesado][i] != 0){
                    Index++;
                    Fila[Index] = i;
                }
            }
            
            for(int i = 0; i<Index; i++){ // mueve la fila para borrar el que se fue
                Fila[i] = Fila[i+1];
            }
            Index--;
            
        }
        
        for(int i = 0; i < j; i++){ //despliega 
            cout << Despliega[i]<< " ";
        }
        cout << endl;
    }
    
};


#endif /* Grafo_h */
