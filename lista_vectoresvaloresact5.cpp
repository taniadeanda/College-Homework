/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 15 de Febrero del 2024
PROGRAMA: lista_vectorescvaloresact5.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Este programa pedira al usuario numeros para sumar, el usuario puede editar o eliminar
elementos, borrar todos o mostrar la lista de numeros*/

/* to add element and print the list ESCRIBIR ELEMENTOS EN LA LISTA
int num[10]  
for (int i=0; i<10; i++) {   recorre cada uno de los elementos de la lista, buscar un auxiiar para no usar tantos for cada vez que agrega un numero
cout<<"escribe un numero";
cin>>num[i]
cout<<"your number is "<<num[i]; it prints the list with the numbers you added
}

IMPRIMIR ELEMENTOS DE LA ISTA
for (int i=0; i<10; i++) {
cout<<num[i]<<endl;
cout<<"your number is "<<num[i]; it prints the list with the numbers you added
}
*/
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector> //declaracion de librerias
using namespace std;

vector <int> vector_list; //declaracion del vector con 10 elementos de tipo entero asi porque se usa la libreria vector
int main () { //do while or something to repeat it 
int user_option, recorrido_vector=0, position, new_number, sum=0; //declaracion de variables
    
    while (user_option!=7) { //mientras la opcion del usuario sea diferente de 6 hacer todo lo siguiente ya que si escribe 6 se saldra del programa
    cout<<"Welcome to the programm that will help you to sum numbers and edit their positions. Type the option (number) you want to do:"<<endl;
    cout<<"1.Add number"<<endl; //opcion para agregar un numero
    cout<<"2.Show numbers"<<endl; //opcion para mostrar lista
    cout<<"3.Edit a number"<<endl; //opcion para sumar los numeros
    cout<<"4.Sum numbers"<<endl; //eliminar un numero
    cout<<"5.Delete a number"<<endl; //editar un numero
    cout<<"6.Delete all numbers"<<endl; //eliminar todos los numeros
    cout<<"7.End program"<<endl; //finalizar programa
    cin>>user_option; //leer la opcion del usuario y segun lo que haya elegido en el menu hacer lo siguiente:
        
    switch (user_option) { //switch para el menu de opciones
        case 1: //casp 1 para agregar números
            cout<<"Type the number you want to add"<<endl; //add value to the start position
        cin>>new_number;
        vector_list.push_back(new_number); //add value to the start position 0
        break; 
        
        case 2: //caso 2 para imprimir la lista
        for (int recorrido_vector=0; recorrido_vector<10; ++recorrido_vector) { //que vaya recorriendo la lista iniciando en 0 hasta el elemento 9, de uno en uno elemento
            cout<<"Your list is "<<vector_list[recorrido_vector]<<endl; //imprimir lista
        } //cierra for
        break;
        
        case 3: //caso 3 para editar un numero
        cout<<"This is your list"<<vector_list<<endl; //print all the elements and show them
        cout<<"Type the position to edit that number"<<endl; //indicacion
        cin>>position; //leer posicion del numero
            if (position>=0 and position<vector_list.size()){
            cout<<"Type the new number ";
                cin>>new_number;
                vector_list[position]= new_number; //eliminar esa posicion
            }
            else {
                cout<<"Incorrect position"<<endl;
            }
        break;
        
        case 4: //sum num
        for (recorrido_vector, recorrido_vector<vector_list.size(); ++recorrido_vector) { //para recorrido del vector hasta menor a su tamano, incrementar 1 al recorrido
            cout<<"Your list is "<<vector_list[recorrido_vector]<<endl; //imprimir la lista
            sum+=vector_list[recorrido_vector]; //hacer la suma que es igual a los elementos entro del vector
        }
        cout<<"The total is "<<sum<<endl; //imprimir suma
        break;
        
        case 5: //del number
        cout<<"This is your list"<<vector_list[recorrido_vector]; //print the list
        cout<<"Type the number position to delete that number"<<endl; //indicacion
        cin>>position; //leer posicion del numero
            if (position>=0 and position<vector_list.size()){
            vector_list.erase(vector_list.begin()+position); //eliminar esa posicion
            }
        break;
        
        case 6: //caso 6 para limpiar el vector
        vector_list.clear(); //DOESNT WORK, METHODS
        cout<<"The content after cleaning is "<<vector_list.size()<<endl; //prints empty vector
        break;
    } //cierra switch
    } //corchete para while
    
    cout<<"You have left the program"<<endl; //end of the program
}