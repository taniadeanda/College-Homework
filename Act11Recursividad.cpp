/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 23 de Abril del 2024
PROGRAMA: Act10(ordybus).cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Este programa usara una funcion recursiva para imprimir los elementos de la lista en vez de un for o while */
#include <iostream>
#include <vector>
using namespace std;

//Fuction definition here
//void print(const vector<int>& list, int position); //SOLO PARA VECTORES DINAMICOS
void print(int* new_lista, int position); //funcion que toma como parametro un arreglo
void adding_num(int* new_lista, int position);

/*int main() { 
    vector<int> list = {1,9,0,5,2,0,0,2};
    print(list, 0); //aplicar la funcion print con argumentos del vector print e inicializandose en 0    
}*/

int main() {
int new_list[5];//lista de 5 elementos
    adding_num(new_list, 0); //se aplica funcion de agregar numero a la lista de 5 elementos iniciando en 0
    print(new_list, 0); //se aplica funcion a la lista new_list iniciando su posicion en 0
}

void print(int* new_lista, int position) { //toma como argumento el vector y la posicion
    if (position == 5) { //caso base, cuando la posicion alcance el tamano de la lista, o sea el ultimo elemento se detiene
        return; 
    } else { //si todavia no llega al ultimo elemento entonces..
        cout << new_lista[position] << ","; //se imprime el elemento que esta en esa posicion que recorre
        print(new_lista, position + 1); //se vuelve a llamar la funcion print pero agregandole 1 la posicion, se recorre a la siguiente posicion
    }
}

void adding_num(int* new_lista, int position) {
    if (position == 5) { //caso base, cuando llegue a 5 (que es el total de elementos) se detiene
        cout << "Your list is full";
        return; //para
    } else {
        cout << "Type the value you want to add to your list. Remember you have 5 spaces" << endl;
        cin >> new_lista[position]; //lee el valor del usuario
        adding_num(new_lista, position +1); //se usa funcion y se agrega uno a posicion
    }
}