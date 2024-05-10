/* <3 <3 PRESENTACION <3 <3
NOMBRE: Lizeth Gutierrez Torres, Tania Citlaly de Anda Lara y Victor Hugo Gutierrez Alvarado
FECHA: 16 de Mayo del 2024
PROGRAMA: Proyectofinal.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Es un programa que ayuda a los alumnos a registrarse, a registrar sus materias, sus maestros,
calificaciones, carrera y calcula el promedio (reprobado, regular, bueno y excelente). Ademas, el alumno 
puede editar el dato que quiera.*/

#include <vector>
#include <iostream>
#include <fstream> // Para trabajar con archivosd
#include <string>//librerías
#include <cctype> //para funcion isdigit() validacion
#include <limits> //para funcion de validacion y limpieza de buffer
using namespace std;

struct Materia{//declaramos la estructura de materias
    string nombre;
    string maestro;
    float calificacion;//sus variables 
};

struct Alumno{//estructura de alumno
    string nombre;//variable 
    vector<Materia> materias;//vector 
};

void validacion() { //funcion para validacion de datos y limpieza de buffer
    if(cin.fail()) { //verifica la entrada de datos, si falla devuelve true y se ejecuta lo siguiente
        cin.clear(); //restablece el estado del flujo de entrada para que pueda recibir mas datos
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignora los carateres no deseados y limpia el buffer
    }
}

void validar_string(string& frase) { //funcion para validar string por si el usuario ingresa numeros
    for (char caracter:frase) { //recorre caracter por caracter del string
        if (isdigit(caracter)) { //funcion is digit para verificar si el caracter es un digito
            cin.clear(); //restablece el estado del flujo de entrada para que pueda recibir mas datos
            cout << "Dato incorrecto. Vuelve a escribir el dato sin numeros" << endl;
            getline(cin, frase);
        }
    }
}

void agregar_calificacion(Materia& nueva_materia){
    while (true) {
        cout << "Ingresa la calificacion (0 - 10): ";
        cin >> nueva_materia.calificacion;
        if (cin.fail() || nueva_materia.calificacion < 0 || nueva_materia.calificacion > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Calificacion incorrecta. Vuelve a ingresar la calificacion en un rango de 0 - 10" << endl;
            //cin >> nueva_materia.calificacion;
        }
        else {
            break;
        }
    }
}

void guardarEnArchivo(const vector<Alumno>& alumnos){
    ofstream archivo("ficha_alumno.txt"); //se declara archivo con su nombre
    if (archivo.is_open()) { //se abre el archivo para poder escribir los datos
        for (const Alumno& alumno : alumnos) { //se usa un bucle para recorrer los elementos del vector alumno y transcribirlos
            archivo << "Nombre del alumno: " << alumno.nombre << endl; //escribe estos datos en el archivo
            for (const Materia& materia : alumno.materias) {
                archivo << "Materia: " << materia.nombre << ", Maestro: " << materia.maestro << ", Calificación: " << materia.calificacion << endl;
            }
            archivo << endl; // Separador entre alumnos
        }
        archivo.close(); //se cierra el archivo y se guardan los datos
        cout << "Datos guardados en el archivo correctamente.\n";
        } else {
        cout << "No se pudo abrir el archivo para guardar los datos.\n";
    }
} //guarda el archivo en la misma carpeta que se ejecuta el programa output

int main (){//inicio del programa
int opcion;//variable 
string nombre;
vector<Alumno> alumnos;//declaramos el vector de alumno
Alumno nuevo_alumno;
    //VALIDACION DE DATOS?FUNCIONES?

    cout<<"Hola, hola, bienvenid@ a este programa para hacer una capturación de datos, Comencemos!!"<<endl;
    cout<<"Primero debes elegir la acción por hacer;"<<endl;//introducción al programa 
    do{//inicio del do para regresar al menú al final de cada caso
        cout<<"1-Ingresar un registro"<<endl;
        cout<<"2-Imprimir tus datos"<<endl;
        cout<<"3-Sacar el promedio de las materias del alumno"<<endl;
        cout<<"4-Editar datos de un registro"<<endl;
        cout<<"5-Salir y guardar archivo"<<endl;//opciones del menú

        cin>>opcion;//lee opción del menú para el switch
        validacion();

        switch (opcion) {//inicio del switch
		    case 1://caso 1 Ingresar los datos 
                cout<<"Empieza por ingresar el nombre del alumno: "<<endl;//pedimos el nombre del alumno
                cin.ignore();
                getline(cin, nuevo_alumno.nombre); //función getline para que permita seguir ingresando en esa misma línea aunque se le de espacio. Guarda el nombre del alumno
                validar_string(nuevo_alumno.nombre); //funcion para validar que no haya ingresado solo numeros

                for (int i=0; i<5; i++) {//ciclo for para llenar las 5 materias 
                    Materia nueva_materia;//vector materia 
                    cout<<"Materia de registro "<<i + 1<<":"<<endl;//pedimos materias y va pidiendo hasta  el 5
                    cin.ignore();
                    getline(cin, nueva_materia.nombre);//función getline, guarda el nombre de materias
                    validar_string(nueva_materia.nombre); //funcion para validar la materia
                    cout<<"Nombre del maestro a cargo de la materia: "<<nueva_materia.nombre<<endl; //pide el nombre del maestro, e imprime el nomnbre de la materia a lado 
                    getline(cin, nueva_materia.maestro);//función getline, guarda el nombre del maestro 
                    validar_string(nueva_materia.maestro);
                    agregar_calificacion(nueva_materia); //permite agregar y validar la calificacion
                    nuevo_alumno.materias.push_back(nueva_materia);
                }
                alumnos.push_back(nuevo_alumno);
                break;//fin caso 1 

            case 2: //caso 2 imprimir 
                //int nombre;
                //cout<<"Ingresa el nombre del alumno para imprimir su ficha"<<endl;
                //cin>>nombre;
                for(const Alumno& alumno : alumnos){

                //preguntar al usuario que estructura quiere imprimir? BUSCAR POR NOMBRE DE ALUMNO

                    cout<<"Los datos de este registro son: "<<endl;//imprime los datos anteriormente ingresados 
                    cout<<"Nombre del alumno: "<<alumno.nombre<<endl;//imprime nombre del alumno
                    for (const Materia& materia : alumno.materias) {//llamamos el vector para que lea los elementos
                        cout<<"Materia: "<<materia.nombre<<endl;//imprime nombre de materia 
                        cout<<"Maestro: "<<materia.maestro<<endl;//imprime nombre del profesor 
                        cout<<"Calificación: "<<materia.calificacion<<endl;//imprime el número de calificación
                    }
                }
                break;//fin caso 2 
            
            case 3://sacar promedio
            { //llaves para evitar problema jump in case y declarar variables dentro de case
                float suma=0;//variable del promedio
                float promediofinal;
                for (const Alumno& alumno : alumnos) {
                    for (const Materia& materia : alumno.materias) {
                        suma += materia.calificacion; // Sumar las calificaciones de todas las materias del alumno
                    }
                }
                promediofinal=suma/5; // Calcular el promedio del alumno
                if (promediofinal<=59){//condición 1 de 59 para abajo
                    cout<<"REPROBADO"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promediofinal<<endl; //imprime el promedio que obtuvo el alumno
                }
                if(promediofinal>=60 && promediofinal<=79){//condición 2 de entre 60 y 79 
                    cout<<"REGULAR"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promediofinal<<endl; //imprime el promedio que obtuvo el alumno
                }
                if(promediofinal>=80 && promediofinal<=89){//condición 3 entre 80 y 89 
                    cout<<"MUY BIEN"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promediofinal<<endl; //imprime el promedio que obtuvo el alumno
                }
                else if (promediofinal>=90 && promediofinal<=100){//condición 4 entre 90 y 100
                    cout<<"EXCELENTE"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promediofinal<<endl; //imprime el promedio que obtuvo el alumno
                }
                break;//fin del caso 3 
            } //cierra llave case

            case 4://Edición de datos
                cout<<"Ingresa el nombre del alumno que desees editar su ficha"<<endl;
                /*
                cin>>nombre;
                //??? COMO BUSCA LA FICHA
                do { //funciones??, COMO SABE DATOS DE QUE ALUMNO?
                    cout<<"A continuacion escribe el elemento que te gustaria editar:\n 1.Nombre del alumno\n 2.Materia\n 3.Maestro\n 4.Calificacion\n";
                    cin>>option;
                    switch(option) {
                        case 1: {
                            cout<<"Escribe el nombre del alumno nuevamente.";
                            getline(cin, materia.nombre);//función getline para que permita seguir ingresando en esa misma línea aunque se le de espacio
                            break;
                        }
                        case 2: {
                            cout<<"Escribe la materia de registro nuevamente."<<endl;
                            getline(cin, materia.materia);//función getline, guarda el nombre de materias 
                        break;
                        }
                        case 3: {
                            cout<<"Escribe nombre del maestro a cargo de la materia nuevamente."<<endl;
                            getline(cin, materia.maestro);//función getline, guarda el nombre del maestro 
                        break;
                        }
                        case 4: {  
                            cout<<"Escribe la calificación obtenida de la materia nuevamente."<<endl;
                            cin>>materia.calificacion;//función getline, guarda el número que se le da de calificación 
                        break;
                        }
                    }
                }while(option!=3);*/
            break;

            case 5: //guardar datos en un archivo
                /* if (alumnos.empty()) {
                    cout << "Ingresa datos en tu ficha para poder guardar el archivo"<<endl;
                } else {}
                */
                guardarEnArchivo(alumnos);  //funcion para guardar archivo
                cout<<"Hasta luego!!"<<endl;
                break;

            default: 
                cout<<"Opción incorrecta de menú. Vuelve a ingresar una opción válida"<<endl;
        }//fin switch 
   }while(opcion!=5);
}//fin programa 

/*{
                    cout << "Datos almacenados de un alumno:\n";
                    cout << "Ingrese el índice del alumno que desea imprimir (de 0 a " << alumnos.size()-1 << "): ";
                    int indice_alumno;
                    cin >> indice_alumno;

                    if (indice_alumno >= 0 && indice_alumno < alumnos.size()) {
                        cout << "Nombre del alumno: " << alumnos[indice_alumno].nombre << endl;
                        cout << "Materias:\n";
                        for (const Materia& materia : alumnos[indice_alumno].materias) {
                            cout << "  Nombre: " << materia.nombre << ", Maestro: " << materia.maestro << ", Calificación: " << materia.calificacion << endl;
                        }
                    } else {
                        cout << "Índice de alumno fuera de rango.\n";
                    }
                    break;
                }*/