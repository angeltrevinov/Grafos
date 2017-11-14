//
//  main.cpp
//  Grafos
//
//  Created by Angel Trevino on 11/10/17.
//  Copyright © 2017 Angel Odiel Treviño Villanueva. All rights reserved.
//

#include <iostream>
#include <string>
#include "Grafo.h"

using namespace std;

//Grafos

int main() {
    string Archivo;
    int instruccion; //nombre del archivo
    
    cout << "Cual es el nombre de tu archivo? "<< endl;
    cin >> Archivo;
    Grafo Grafo(Archivo);
    
    do{
        cout << "Que quieres hacer? \nBreadth First(1) \nDepth First(2) \nEncontrar camninosos(3) \nsalir(4)" << endl;
        cin >> instruccion;
        
        switch(instruccion){
            case 1:
                Grafo.BreadthFirst();
            break;
            case 2:
                Grafo.DepthFirst();
            break;
            case 3:
                int x, y;
                cout << "Cual es tu origen?" << endl;
                cin >> x;
                cout << "Cual es tu destino?" << endl;
                cin >> y;
                if(Grafo.Buscar(x,y))
                    cout <<"Existe camino" << endl;
                else
                    cout << "No existe camino" << endl;
                    
            break;
                
        }
        cout<< endl;
        
    }while(instruccion != 4 );
    
    return 0;
}
