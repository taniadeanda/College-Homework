/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 24 de Enero del 2024
PROGRAMA: datos_alumno.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: El programa pide datos del alumno como edad, nombre, lugar, carrera, semestre, ano y fecha para al final imprimirlas*/

#include <stdio.h>
int main() { //inicio del programa
    char name[80],place[20],date[20],career[20]; //declaracion de estas variables como caracteres y como maximo los caracteres que tome dentro del corchete
    int age,semester; //declaracion de estas variables como enteros
    printf("BIENVENIDO, te ayudaré a recopilar tus datos de estudiante para mostrarlos.\nEscribe a continuación tu nombre completo\n");//darle bienvenida al usuario y pedirle su nombre
    scanf(" %[^\n]", name); //escanear la linea de texto con espacios hasta que el usuario de enter y guardar el dato en la variable name
    
    printf("Escribe tu edad a continuación\n"); //imprimir esto para pedir la edad al usuario
    scanf("%d", &age); //escanear tipo de dato entero y guardarlo en la variable age
    
    printf("Escribe tu lugar de residencia a continuación\n"); //imprimir esto para pedir el lugar de residencia al usuario
    scanf(" %[^\n]", place); //escanear la linea de texto proporcionada y guardarlo en la variable place
    
    printf("Escribe tu fecha de nacimiento\n"); //pedir al usuario su fecha de nacimiento
    scanf(" %[^\n]", date); //guardar linea de texto en la variable date
    
    printf("Escribe tu carrera a continuación\n"); //imprimir esto para pedir al usuario la carrera
    scanf(" %[^\n]", career); //escanear la linea de texto y guardarlo en la variable career hasta que el usuario de enter
    
    printf("Escribe tu semestre que estas cursando (únicamente el número)\n"); //imprimir esto para pedir al usuario el semestre
    scanf("%d", &semester); //guardar el tipo de dato como numero y guardarlo en la variable semester
    
    printf("Tus datos de alumno son:\n-Nombre:%s\n-Edad:%d\n-Lugar:%s\n-Fecha:%s\n-Carrera:%s\n-Semestre:%d\n",name,age,place,date,career,semester); //imprimir los datos proporcionados por el alumno especificando variables y tipo de datos
} //fin del programa