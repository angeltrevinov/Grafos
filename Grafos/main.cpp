//
//  main.cpp
//  Grafos
//
//  Created by Angel Trevino on 11/10/17.
//  Copyright © 2017 Angel Odiel Treviño Villanueva. All rights reserved.
//

#include <iostream>
#include "Grafo.h"

using namespace std;

//Grafos

int main() {
    string Archivo; //nombre del archivo
    
    cout << "Cual es el nombre de tu archivo? "<< endl;
    cin >> Archivo;
    
    Grafo Grafo(Archivo);
    Grafo.BreathFirst();
    
    return 0;
}
