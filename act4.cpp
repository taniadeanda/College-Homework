/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 8 de Febrero del 2024
PROGRAMA: act4.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Se solicita al usuario un valor y la serie fibonacci debe llegar a un valor
igual o menor al ingresado. El usuario elige con que ciclo desea trabajar for, while o do while. 
Este programa tiene una opcion donde se pueda salir del programa*/

#include <iostream> //librerias
using namespace std;
int user_option, user_number, user_number1=0, user_number2=1, fibonacci_start=0, fibonacci_number; //declaracion de variables como enteros
int main() { //inicio del programa
    do {
    cout<<"Bienvenido. A continuacion podras introducir un numero entero para crear su serie fibonacci. De igual manera podras elegir el ciclo con el que desees trabajar."<<endl;
    cout<<"Escribe la opcion del ciclo con el que desees trabajar: 1.For, 2.While, 3.Do while y 4.Salir del programa"<<endl; //opciones al usuario
    cin>>user_option; //solicitar al usuario una opcion
    switch(user_option){ //switch segun sea la opcion
        case 1: //caso 1
            cout<<"Ciclo do. Ingresa el numero del que desees hacer tu serie fibonacci"; //pedir al usuario el numero
            cin>>user_number; //leer dato
             for (int fibonacci_start=0; fibonacci_start<=user_number;) { //para fibonacci inicio hasta numero menor o igual al ingresado por el usuario
               fibonacci_start=user_number1+user_number2; //fibonacci_start es igual a la suma del numero1 mas numero 2
               user_number1=user_number2; //numero uno es igual a numero dos, se reasigna la variable
               user_number2=fibonacci_start; //ahora el numero 2 es igual al inicio del numero de la serie fibonacci, asi las variables se intercambian
               cout<<"Tus numeros de la serie fibonacci son: "<<user_number1<<endl; //imprimir numero1 y mostrara la serie fibonacci
           }
            break; //finalizar
            
        case 2:
                cout<<"Ciclo while. Ingresa el numero del que desees hacer tu serie fibonacci"; //pedir al usuario el numero
            cin>>user_number; //leer dato
    while (fibonacci_start<=user_number) { //mientras el inicio=0 sea menor al numero ingresado por el usuario hacer
        fibonacci_start = user_number1 + user_number2; //inicio numero de fibonacci es igual a 0+1
               user_number1 = user_number2; //numero 1 ahora es asignado a numero 2
               user_number2 = fibonacci_start; //numero 2 es asignado a fibonacci_start y d
               cout<<"Tus numeros de la serie fibonacci son: "<<user_number1<<endl; //mostrar numeros de la serie
            }
            break; //finalizar
        
        case 3:
                cout<<"Ciclo do while. Ingresa el numero del que desees hacer tu serie fibonacci"<<endl; //pedir numero
    cin>>user_number; //leer numero
    do { //hacer
        fibonacci_start = user_number1 + user_number2; //inicio de fibonacci es igual a 
               user_number1 = user_number2;
               user_number2 = fibonacci_start;
                cout<<"Los numeros de tu serie fibonacci son: "<<user_number1<<endl; //mostrar
    }
        while(fibonacci_start<=user_number); //mientras fibonacci_start sea menor al numero ingresado hacer lo anterior
            break; //salir del loop
        }
    }
    while(user_option!=4);//mientras la opcion ingresada por el usuario sea diferente de 4 seguir haciendo lo anterior
    cout<<"Has salido del programa"<<endl; //mostrar salir del programa y terminar
    return 0;
} 