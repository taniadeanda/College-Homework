/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 29 de Enero del 2024
PROGRAMA: act3.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Este programa le pide un numero al usuario y si el numero es mayor a 0
y menor a 500 sube de 5 en 5 100 veces; si el numero es mayor a 500 y menos a 1000 se
sube el numero de 10 en 10 50 veces; si el numero es mayor a 1000 se imprime no se puede 
calcular el valor. Este programa tiene una opcion donde se pueda salir del programa 
hace un conteo de las veces que se realizo la operacion */

#include <iostream> //declaracion de librerias
using namespace std; 
int user_number, number, times = 0; //declaracion de variables como enteros
int main() { //inicio del programa
    do {
    cout<<"Bienvenido. Escribe a continuacion un numero. Si deseas salir del programa escribe \"2\" "<<endl; //pedir al usuario un numero
    cin>>user_number;//escanear el dato ingresado por el usuario y guardarlo en variable
    if (user_number >= 0 and user_number <= 500) //si user_number es mayor a 0 y menor a 500 entonces hacer
    {
        for (int number=0; number<=100; number++) //para numero iniciando en 0 hasta 100, incrementar 1
        {
            cout<<(number*5)<<endl; // imprimir el numero multiplicado por 5
        }
    }
        else if (user_number > 500 and user_number <= 1000) //si user_number va de 500 a 1000
        {
            for (int number=0; number<=50; number++) //para numero iniciando en 0 hasta 50 con incremento de 1
            {
                cout<<(number*10)<<endl; //mostrar numero multiplicado por 10
            }
        }
        else if (user_number > 1001) //si el numero es mayor a 1000 entonces
        {
         cout<<"No se puede calcular el valor"<<endl; //se imprime que no se puede calcular el valor
        }
        else { //si no
            cout<<"El numero no es valido"<<endl; //imprimir el numero no es valido
            fflush(stdin); // limpieza de buffer
        }
        
        times++; //contador times que es igual a times + 1
        cout<<"La cantidad de veces que utilizaste el programa fueron: "<<times<<endl; //imprimir la cantidad de veces que se uso el programa
        cout<<"Para continuar oprime 1, para terminar el programa oprime 2"<<endl; //Imprimir si se quiere continuar 1 si se quiere terminar 2
        cin>>user_number; //ingresar opcion del usuario
    }
    while(user_number != 2); //mientras user_number que ingrese el usuario sea diferente de 1 hacer y repetir lo anterior
} //fin del programa