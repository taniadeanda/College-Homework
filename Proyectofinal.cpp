/* <3 <3 PRESENTACION <3 <3
NOMBRE:Lizeth Gutierrez Torres y Tania Citlaly de Anda Lara
FECHA: 20 de Mayo del 2024
PROGRAMA: Proyectofinal.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Es un programa que ayuda a los alumnos a registrarse, a registrar sus materias, sus maestros,
calificaciones, carrera y calcula el promedio (reprobado, regular, bueno y excelente). Ademas, el alumno 
puede editar el dato que quiera.*/

#include <vector>
#include <iostream>
#include <string>//librerías 

using namespace std;

int main (){//inicio del programa
int opcion;//variable para elegir lo que se desea en el menú 
//VALIDACION DE DATOS?FUNCIONES?
do{
cout<<"Hola, hola, bienvenid@ a este programa para hacer una capturación de datos, Comencemos!!"<<endl;
cout<<"Primero debes elegir la acción por hacer;"<<endl;
cout<<"1-Ingresar un registro"<<endl;
cout<<"2-Imprimir tus datos"<<endl;
cout<<"2-Editar datos de un registro"<<endl;
cout<<"3-Salir"<<endl;
cin>>opcion;//lee opción del menú para el switch 
switch (opcion) {//inicio del switch

		case 1:{//Ingresar los datos 
        struct registro {//se abre la estructura 
            string nombre;//variable string para nombre del alumnos, así nos permite tener espacios y cualquier cantidad 
            string materia;//variable string para materias AGREGAR MAS MATERIAS?
            string maestro;//variable strting para nombre del maestro
            float calificacion;//calificación variable 
        };//AGREGAR alumno1, alumno2, alumno3, alumno4, ?? 
        struct registro registro_alumno; //creacion de una variable de tipo estructura
        cout<<"Empieza por ingresar el nombre del alumno:"<<endl;
        cin.ignore();
        getline(cin, registro_alumno.nombre);//función getline para que permita seguir ingresando en esa misma línea aunque se le de espacio. Guarda el nombre del alumno 
        cout<<"Materia de registro."<<endl;
        getline(cin, registro_alumno.materia);//función getline, guarda el nombre de materias 
        cout<<"Nombre del maestro a cargo de la materia:"<<endl;
        getline(cin, registro_alumno.maestro);//función getline, guarda el nombre del maestro 
        cout<<"Calificación obtenida de la materia:"<<endl;
        cin>>registro_alumno.calificacion;//función getline, guarda el número que se le da de calificación 
            break;
        }

        case 2: { //imprimir, 
        //preguntar al usuario que estructura quiere imprimir? BUSCAR POR NOMBRE DE ALUMNO
            cout<<"Ingresa el nombre del alumno que desees saber su ficha";
            cin>>nombre;
            //??? COMO BUSCA LA FICHA
            cout<<"Los datos ingresados son: "<<endl;//imprime los datos anteriormente ingresados 
            cout<<"Nombre del alumno: "<<registro_alumno.nombre<<endl;//imprime nombre del alumno
            cout<<"Materia: "<<registro_alumno.materia<<endl;//imprime nombre de materia 
            cout<<"Maestro: "<<registro_alumno.maestro<<endl;//imprime nombre del profesor 
            cout<<"Calificación: "<<registro_alumno.calificacion<<endl;//imprime el número de calificación
        }

        case 3://Edición de datos
            cout<<"Ingresa el nombre del alumno que desees saber su ficha";
            cin>>nombre;
            //??? COMO BUSCA LA FICHA
            do { //funciones??, COMO SABE DATOS DE QUE ALUMNO?
                cout<<"A continuacion escribe el elemento que te gustaria editar:\n 1.Nombre del alumno\n 2.Materia\n 3.Maestro\n 4.Calificacion\n";
                switch(option) {
                case 1:
                    cout<<"Escribe el nombre del alumno nuevamente.";
                    getline(cin, registro_alumno.nombre);//función getline para que permita seguir ingresando en esa misma línea aunque se le de espacio
                case 2:
                    cout<<"Escribe la materia de registro nuevamente."<<endl;
                    getline(cin, registro_alumno.materia);//función getline, guarda el nombre de materias 
                case 3:
                    cout<<"Escribe nombre del maestro a cargo de la materia nuevamente."<<endl;
                    getline(cin, registro_alumno.maestro);//función getline, guarda el nombre del maestro 
                case 4:    
                    cout<<"Escribe la calificación obtenida de la materia nuevamente."<<endl;
                    cin>>registro_alumno.calificacion;//función getline, guarda el número que se le da de calificación 
                }
            }while(option!=3);
            break;

        case 4:
        cout<<"Hasta luego!!"<<endl;
            break;

    }//fin switch 
        }while(opcion!=4);
}//fin programa 