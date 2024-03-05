/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 5 de Marzo del 2024
PROGRAMA: Act5_matrices.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Calculadora que suma, resta y multiplica 2 matrices. El usuario puede elegir el tamano
de la matriz, el usuario puede indicar los valores y posiciones en las matrices, tiene opcion de ser llenada
con calores aleatorios entre -100 y 100, se puede borrar y editar elementos o vaciar las matrices*/
#include <iostream>
#include <cstdlib>
using namespace std;
int matriz1[10][10]; //definir matrices como maximo de tamano
int matriz2[10][10];
int option, llenado, filas1, filas, columnas, columnas1, filas2, columnas2, opt_matriz, suma=0, resta=0, multiplicacion=0, recorrido_filas, recorrido_columnas, value;
int main() {
    do {
        cout<<"Bienvenido a la calculadora de matrices. A continuacion escribe una opcion. Te recomendamos iniciar a llenar tus matrices ya que si seleccionas cualquier otra opcion del menu no tendra resultado"<<endl;
        cout<<"1.Llenar Matriz 1"<<endl;
        cout<<"2.Llenar Matriz 2"<<endl; //menu con opciones
        cout<<"3.Sumar matrices"<<endl;
        cout<<"4.Restar matrices"<<endl;
        cout<<"5.Multiplicar matrices"<<endl;
        cout<<"6.Editar matrices"<<endl;
        cout<<"7.Vaciar matrices"<<endl;
        cout<<"8.Mostrar matrices"<<endl;
        cout<<"9.Finalizar calculadora"<<endl;
        cin>>option; //ingresar opcion
        switch (option) {
            case 1:
                cout<<"Comenzaremos a llenar tu matriz 1. Recuerda que sus dimensiones deben ser de 2x2 a 10x10"<<endl;
                cout<<"Ingresa filas y columnas"<<endl;
                cin>>filas1>>columnas1; //pedir y leer filas y columas de la matriz 1
                while (filas1>10 or filas1<2 or columnas1<0 or columnas1>10) {
                    cout<<"Dimensiones invalidas. Recuerda que deben ser 2x2 a 10x10. Vuelve a ingresar dimensiones"<<endl;
                    cin>>filas1>>columnas1;
                } //valida las dimensiones de la matriz
                cout<<"Como te gustaria llenar tu matriz 1?"<<endl;
                cout<<"Ingresar valores"<<endl;
                cout<<"Valores aleatorios"<<endl; 
                cout<<"Terminar operaciones"<<endl;
                cin>>llenado; //ingresar opcion de llenado de matriz
                do {
                    switch (llenado) {
                        case 1:
                            cout<<"Ingresa los valores para tu matriz 1. Recuerda que se iran acomodando en orden"; //pedir al usuario valores de la matriz 1
                            for (recorrido_filas=0; recorrido_filas<filas1; recorrido_filas++) { //for que recorre filas
                                for (recorrido_columnas=0; recorrido_columnas<columnas1; recorrido_columnas++) { //for que recorre columnas
                                    cin>>matriz1[recorrido_filas][recorrido_columnas]; //el usuario escribe las filas y columnas que desee para matriz 1
                                    while (matriz1[recorrido_filas][recorrido_columnas]<-100 or matriz1[recorrido_filas][recorrido_columnas]>100) {
                                        cout<<"Rango invalido de numero. Vuelve a ingresar valores de -100 a 100"<<endl;
                                        cin>>matriz1[recorrido_filas][recorrido_columnas]; //valida que los numeros ingresados esten de -100 a 100
                                    }
                                }
                            }
                            for (recorrido_filas=0; recorrido_filas<filas1; recorrido_filas++) {
                                cout<<endl;
                                for (recorrido_columnas=0; recorrido_columnas<columnas1; recorrido_columnas++) {
                                    cout<<"I"<<matriz1[recorrido_filas][recorrido_columnas]<<"I"; //for anidados para imprimir la matriz 1 ingresada
                                }
                            }
                        break;
                        case 2:
                            cout<<"Valores aleatorios"<<endl;
                            for (recorrido_filas=0; recorrido_filas<filas1; ++recorrido_filas) {
                                for (recorrido_columnas=0; recorrido_columnas<columnas1; ++recorrido_columnas) {
                                    matriz1[recorrido_filas][recorrido_columnas] = -100 + rand() % 201;
                                    cout<<"I"<<matriz1[recorrido_filas][recorrido_columnas]<<"I"; //imprime matriz 1 llenada aleatoriamente
                                } //cierra for
                                cout<<endl;
                            }//cierra for 2
                            break;
                        default: 
                        cout<<"Opcion invalida porfavor vuelve a ingresar una opcion correcta del menu"<<endl; //validacion de opcion de menu
                    } //cierra switch 
                } //cierra do 
                while (llenado!=3);
                break;
            case 2:
                cout<<"Ahora llenaremos tu segunda matriz. Recuerda que sus dimensiones deben ser 2x2 a 10x10"<<endl; //llenar matriz 2
                cout<<"Escribe filas y columnas";
                cin>>filas2>>columnas2; //leer dimensiones de la matriz 2
                while (filas2>10 or filas2<2 or columnas2<0 or columnas2>10) {
                    cout<<"Dimensiones invalidas. Recuerda que deben ser 2x2 a 10x10. Vuelve a ingresar dimensiones"<<endl;
                    cin>>filas2>>columnas2;
                }
                cout<<"Como te gustaria llenar tu matriz 1?"<<endl; //mostrar menu
                cout<<"Ingresar valores"<<endl;
                cout<<"Valores aleatorios"<<endl; 
                cout<<"Terminar operaciones"<<endl;    
                cin>>llenado; //leer opcion de llenado
                do {
                    switch (llenado) {
                        case 1:
                            cout<<"Ingresa valores para tu segunda matriz"<<endl;
                            for (recorrido_filas=0; recorrido_filas<filas2; recorrido_filas++) { //for anidados que recorren filas y columnas y leen los datos ingresados por el usuario
                                for (recorrido_columnas=0; recorrido_columnas<columnas2; recorrido_columnas++) {
                                    cin>>matriz2[recorrido_filas][recorrido_columnas];
                                    while (matriz2[recorrido_filas][recorrido_columnas]<-100 or matriz2[recorrido_filas][recorrido_columnas]>100 or matriz2[recorrido_filas][recorrido_columnas]==100) {
                                        cout<<"Rango de numero invalido. Vuelve a ingresar numeros de -100 a 100"<<endl;
                                        cin>>matriz2[recorrido_filas][recorrido_columnas];
                                    }
                                }
                            }
                            for (recorrido_filas=0; recorrido_filas<filas2; recorrido_filas++) {
                                cout<<endl;
                                for (recorrido_columnas=0; recorrido_columnas<columnas2; recorrido_columnas++) { //imprimir matriz
                                    cout<<"I"<<matriz2[recorrido_filas][recorrido_columnas]<<"I";
                                }
                            }
                            break;
                        case 2:
                            cout<<"Llenar aleatoriamente"<<endl;
                            for (recorrido_filas=0; recorrido_filas<filas2; ++recorrido_filas) {
                                for (recorrido_columnas=0; recorrido_columnas<columnas2; ++recorrido_columnas) { //for anidados para recorrer filas y columnas
                                    matriz2[recorrido_filas][recorrido_columnas]=rand()%201-100;
                                    cout<<"I"<<matriz2[recorrido_filas][recorrido_columnas]<<"I"; //imprimir matriz llenada aleatoriamente
                                }
                                cout<<endl;
                            }
                        break;
                        default:
                        cout<<"Opcion invalida. Porfavor vuelve a ingresar una opcion correcta"<<endl; //validacion de opcion de menu
                    }
                } while (llenado!=3);
                break;
            case 3:
                cout<<"Suma"<<endl;
                for (recorrido_filas=0; recorrido_filas<filas1; recorrido_filas++) { //recorrer filas y columnas
                    for (recorrido_columnas=0; recorrido_columnas<columnas1; recorrido_columnas++) {
                        suma= matriz1[recorrido_filas][recorrido_columnas] + matriz2[recorrido_filas][recorrido_columnas]; //sumar filas y columnas de matriz 1 y 2
                        cout<<suma<<endl;
                    }
                    cout<<endl;
                }
                break;
            case 4:
                cout<<"Resta"<<endl;
                for (recorrido_filas=0; recorrido_filas<filas1; recorrido_filas++) {
                    for (recorrido_columnas=0; recorrido_columnas<columnas1; recorrido_columnas++) { //recorrer elementos de ambas matrices y restar sus contenidos
                        resta=matriz1[recorrido_filas][recorrido_columnas] - matriz2[recorrido_filas][recorrido_columnas];
                        cout<<resta<<endl;
                    }
                    cout<<endl;
                }
            break;
            case 5:
            cout<<"Multiplicacion"<<endl;
            cout<<"Ingresa la posicion de la matriz 1 que desees multiplicar (fila y columna)"<<endl;
            cin>>filas1>>columnas1; //leer posicion de la matriz 1
            cout<<"Ingresa la posicion de la matriz 2 que desees multiplicar (fila y columna)"<<endl;
            cin>>filas2>>columnas2; //leer posicioon de la matriz 2
            multiplicacion=matriz1[filas1][columnas1]*matriz2[filas2][columnas2]; //hacer multiplicacion de ambas casillas
            cout<<"Tu multiplicacion es "<<multiplicacion<<endl;
            break;
            case 6:
            cout<<"Editar"<<endl;
            cout<<"En que matriz quieres editar?"<<endl;
            cin>>opt_matriz; //leer opcion para editar matriz
            switch (opt_matriz) {
                case 1:
                cout<<"Ingresa fila y columna"<<endl;
                cin>>filas1>>columnas1;
                cout<<"Ingresa el numero";
                cin>>value;
                if (filas>=0 and filas<columnas1 and columnas1>=0 and columnas<filas1) {
                    matriz1[filas][columnas]=value; //recorrer matriz y agregar el valor en esa posicion
                }
                break;
                case 2:
                cout<<"Ingresa fila y columna"<<endl;
                cin>>filas2>>columnas2; //how do u valid this exists????
                cout<<"Ingresa el numero"<<endl;
                cin>>value;
                if (filas>=0 and filas<columnas2 and columnas>=0 and columnas<filas2) {//recorer matriz y agregar value en esa posicion
                    matriz2[filas][columnas]=value;
                }
                break;
            }
            break;
            case 7:
                cout<<"Que matriz deseas vaciar?"<<endl;
                cin>>opt_matriz;
                switch (opt_matriz) {
                    case 1:
                        for (recorrido_filas=0; recorrido_filas<filas1; recorrido_filas++) { //recorrido de elementos en matriz e igualar a 0
                            for (recorrido_columnas=0; recorrido_columnas<columnas1; recorrido_columnas++) {
                                matriz1[recorrido_filas][recorrido_columnas]=0;
                            }
                        }
                        break;
                    case 2:
                        for (recorrido_filas=0; recorrido_filas<filas2; recorrido_filas++) {
                            for (recorrido_columnas=0; recorrido_columnas<columnas2; recorrido_columnas++) {
                                matriz2[recorrido_filas][recorrido_columnas]=0; //igualar a 0 para vaciarse
                            }
                        }
                        break;
                    default:
                    cout<<"Opcion incorrecta"<<endl;
                }
                break;
            case 8:
            cout<<"Matriz 1"<<endl;
            for (recorrido_filas=0; recorrido_filas<filas1; recorrido_filas++) {
                cout<<endl;
                for (recorrido_columnas=0; recorrido_columnas<columnas1; recorrido_columnas++) { //imprimir matriz 1 con for anidados para que recorra elemento por elemento de fila y columna 
                    cout<<"I"<<matriz1[recorrido_filas][recorrido_columnas]<<"I";
                }
            }
            cout<<"Matriz 2"<<endl;
            for (recorrido_filas=0; recorrido_filas<filas2; recorrido_filas++) {
                cout<<endl;
                for (recorrido_columnas=0; recorrido_columnas<columnas2; recorrido_columnas++) {
                    cout<<"I"<<matriz2[recorrido_filas][recorrido_columnas]<<"I"; //imprimir matriz 2 con for anidados para que recorra filas y columnas 
                }
            }
            break;
            case 9:
                cout<<"Haz finalizado. Gracias por usar calculadora de operaciones"; //fin del programa
                break;
            default:
                cout<<"Opcion invalida. Porfavor vuelve a escribir una opcion correcta"<<endl; //validar opcion
        }
    } while (option!=9);
    return 0; //fin
}