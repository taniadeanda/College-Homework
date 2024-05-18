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
#include <algorithm>
using namespace std;

struct Materia{//declaramos la estructura de materias
    string nombre;
    string maestro;
    float calificacion;//sus variables 
};

struct Alumno{//estructura de alumno
    string nombre;//variable 
    string carrera;
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
        cout << "Ingresa la calificacion (0 - 100): ";
        cin >> nueva_materia.calificacion;
        if (cin.fail() || nueva_materia.calificacion < 0 || nueva_materia.calificacion > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Calificacion incorrecta. Vuelve a ingresar la calificacion en un rango de 0 - 100" << endl;
            //cin >> nueva_materia.calificacion;
        }
        else {
            break;
        }
    }
}

void guardarEnArchivo(const vector<Alumno>& alumnos){
    ofstream archivo("ficha_alumno.txt"); // Abrir el archivo en modo append
    if (archivo.is_open()) { // Verificar si el archivo se abrió correctamente
        for (const Alumno& alumno : alumnos) { // Recorrer el vector de alumnos
            archivo << "Nombre del alumno: " << alumno.nombre << endl; // Escribir el nombre del alumno en el archivo
            for (const Materia& materia : alumno.materias) { // Recorrer las materias del alumno
                archivo << "Materia: " << materia.nombre << ", Maestro: " << materia.maestro << ", Calificación: " << materia.calificacion << endl; // Escribir los detalles de la materia en el archivo
            }
            archivo << endl; // Agregar una línea en blanco como separador entre alumnos
        }
        archivo.close(); // Cerrar el archivo después de escribir
        cout << "Datos guardados en el archivo correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
    }
} //guarda el archivo en la misma carpeta que se ejecuta el programa, output
void leerDesdeArchivo(vector<Alumno>& alumnos) {
    ifstream archivo("ficha_alumno.txt"); // Abre el archivo en modo lectura
    if (archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        string linea;
        while (getline(archivo, linea)) { // Lee línea por línea del archivo
            if (linea.rfind("Nombre del alumno: ", 0) == 0) { // Verifica si la línea comienza con "Nombre del alumno: "
                Alumno alumno;
                alumno.nombre = linea.substr(19); // Extrae el nombre del alumno
                getline(archivo, linea); // Lee la siguiente línea para la carrera
                if (linea.rfind("Carrera: ", 0) == 0) { // Verifica si la línea comienza con "Carrera: "
                    alumno.carrera = linea.substr(9); // Extrae la carrera del alumno
                }

                while (getline(archivo, linea) && !linea.empty()) { // Lee las materias hasta que encuentre una línea en blanco
                    if (linea.rfind("Materia: ", 0) == 0) { // Verifica si la línea comienza con "Materia: "
                        Materia materia;
                        size_t pos1 = linea.find(": ") + 2;
                        size_t pos2 = linea.find(", Maestro: ");
                        materia.nombre = linea.substr(pos1, pos2 - pos1);

                        pos1 = linea.find("Maestro: ") + 9;
                        pos2 = linea.find(", Calificación: ");
                        materia.maestro = linea.substr(pos1, pos2 - pos1);

                        pos1 = linea.find("Calificación: ") + 14;
                        materia.calificacion = stof(linea.substr(pos1));

                        alumno.materias.push_back(materia); // Añade la materia al vector de materias del alumno
                    }
                }
                alumnos.push_back(alumno); // Añade el alumno al vector de alumnos
            }
        }
        archivo.close(); // Cierra el archivo después de leer
        cout << "Datos cargados desde el archivo correctamente.\n";
    } else {
        cout << "No se pudo abrir el archivo para cargar los datos.\n";
    }
}
bool compararPorNombre(const Alumno& a, const Alumno& b) {
    return a.nombre < b.nombre;
}
// Función para buscar un alumno por nombre usando búsqueda binaria
int buscarAlumnoPorNombre(const vector<Alumno>& alumnos, const string& nombre) {
    // Ordenar el vector de alumnos por nombre
    vector<Alumno> alumnosOrdenados = alumnos; // Copiar el vector original
    sort(alumnosOrdenados.begin(), alumnosOrdenados.end(), compararPorNombre);

    // Búsqueda binaria en el vector ordenado
    int inicio = 0;
    int fin = alumnosOrdenados.size() - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (alumnosOrdenados[medio].nombre == nombre) {
            // Encontrado el alumno en el vector original
            // Buscar el índice del alumno en el vector original
            for (size_t i = 0; i < alumnos.size(); ++i) {
                if (alumnos[i].nombre == nombre) {
                    return i;
                }
            }
        } else if (alumnosOrdenados[medio].nombre < nombre) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1; // Alumno no encontrado
}
float calcularPromedio(const Alumno& alumno) {
    float suma = 0;
    for (const Materia& materia : alumno.materias) {
        suma += materia.calificacion;
    }
    return suma / alumno.materias.size();
}

int main (){//inicio del programa
    int opcion;//variable 
    string nombre;
    vector<Alumno> alumnos;//declaramos el vector de alumno
    Alumno nuevo_alumno;
    cout<<"Hola, hola, bienvenid@ a este programa para hacer una capturación de datos, Comencemos!!"<<endl;
    cout<<"Primero debes elegir la acción por hacer;"<<endl;//introducción al programa 
    do{//inicio del do para regresar al menú al final de cada caso
        cout<<"1-Ingresar un registro"<<endl;
        cout<<"2-Imprimir todos los datos"<<endl;
        cout<<"3-Busqueda de alumno"<<endl;
        cout<<"4-Sacar el promedio de las materias del alumno"<<endl;
        cout<<"5-Editar datos de un registro"<<endl;
        cout<<"6-Abrir archivo"<<endl;
        cout<<"7-Salir y guardar archivo"<<endl;//opciones del menú

        cin>>opcion;//lee opción del menú para el switch
        validacion();

        switch (opcion) {//inicio del switch
		    case 1://caso 1 Ingresar los datos 
            {
                Alumno nuevo_alumno;
                cout<<"Empieza por ingresar el nombre del alumno: "<<endl;//pedimos el nombre del alumno
                cin.ignore();
                getline(cin, nuevo_alumno.nombre); //función getline para que permita seguir ingresando en esa misma línea aunque se le de espacio. Guarda el nombre del alumno
                validar_string(nuevo_alumno.nombre); //funcion para validar que no haya ingresado solo numeros
                cout<<"Ingresa la carrera que cursa"<<endl;
                getline(cin, nuevo_alumno.carrera);
                validar_string(nuevo_alumno.carrera);

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
        }
            case 2: //caso 2 imprime todas las fichas
            cout<<" "<<endl;
            cout<<"Los datos de este registro son: "<<endl;//imprime los datos anteriormente ingresados 
                for(const Alumno& alumno : alumnos){ 
                    cout<<"Nombre del alumno: "<<alumno.nombre<<endl;//imprime nombre del alumno
                    cout<<"Carrera: "<<alumno.carrera<<endl;
                    for (const Materia& materia : alumno.materias) {//llamamos el vector para que lea los elementos
                        cout<<"Materia: "<<materia.nombre<<endl;//imprime nombre de materia 
                        cout<<"Maestro: "<<materia.maestro<<endl;//imprime nombre del profesor 
                        cout<<"Calificación: "<<materia.calificacion<<endl;//imprime el número de calificación
                        cout<<" "<<endl;
                    }
                }
                break;
            case 3: //imprime solo la ficha del alumno
            {
                cout<<"Ingresa el nombre tal cual como en el registro"<<endl;
                cout<<"Estos son los alumnos registrados"<<endl;
                cout<<"Nombres de los alumnos: "<<endl;
                for(const Alumno& alumno : alumnos){
    
                    cout<<"["<<alumno.nombre<<"]"<<endl;//imprime nombre del alumno
                }
                string nombreBusqueda;
                cout << "Ingresa el nombre del alumno: ";
                cin.ignore();
                getline(cin, nombreBusqueda);

                // Buscar el alumno por nombre
                int indiceAlumno = buscarAlumnoPorNombre(alumnos, nombreBusqueda);

                if (indiceAlumno != -1) {
                    const Alumno& alumnoEncontrado = alumnos[indiceAlumno];
                    cout << "Los datos de este registro son: "<< endl;
                    cout << "Nombre del alumno: " << alumnoEncontrado.nombre << endl;
                    cout <<"Carrera: " <<alumnoEncontrado.carrera<<endl;
                    cout<<"===================================================="<<endl;
                    for (const Materia& materia: alumnoEncontrado.materias) {
                        cout << "Materia: " << materia.nombre << endl;
                        cout << "Maestro: " << materia.maestro << endl;
                        cout << "Calificación: " << materia.calificacion << endl;
                        cout<<"=================================================="<<endl;
                    }
                } else {
                cout << "Alumno no encontrado." << endl;
                }
            break;
            }
            case 4://sacar promedio
            { //llaves para evitar problema jump in case y declarar variables dentro de case
            cout<<"Ingresa el nombre tal cual como en el registro"<<endl;
            cout<<"Nombres de los alumnos: "<<endl;
                for(const Alumno& alumno : alumnos){
    
                    cout<<"["<<alumno.nombre<<"]"<<endl;//imprime nombre del alumno
                }
                cout << "Ingresa el nombre del alumno para calcular su promedio: ";
                string nombreBusqueda;
                cin.ignore();
                getline(cin, nombreBusqueda);

                int indiceAlumno = buscarAlumnoPorNombre(alumnos, nombreBusqueda);

                if (indiceAlumno != -1) {
                    const Alumno& alumno = alumnos[indiceAlumno];
                    float promedio = calcularPromedio(alumno);

                    cout << "El promedio de " << alumno.nombre << " es: " << promedio << endl;
                   if (promedio<=59){//condición 1 de 59 para abajo
                    cout<<"Reprobado"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promedio<<endl; //imprime el promedio que obtuvo el alumno
                }
                if(promedio>=60 && promedio<=79){//condición 2 de entre 60 y 79 
                    cout<<"Regular"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promedio<<endl; //imprime el promedio que obtuvo el alumno
                }
                if(promedio>=80 && promedio<=89){//condición 3 entre 80 y 89 
                    cout<<"Bueno"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promedio<<endl; //imprime el promedio que obtuvo el alumno
                }
                else if (promedio>=90 && promedio<=100){//condición 4 entre 90 y 100
                    cout<<"Excelente"<<endl;//imprime el mensaje de calificación que se solicitó
                    cout<<"El promedio total del alumno en sus 5 materias fue de: "<<promedio<<endl; //imprime el promedio que obtuvo el alumno
                }
                }
                break;//fin del caso 3 
            } //cierra llave case

           case 5: // Edición de datos
{       cout<<"Nombres de los alumnos: "<<endl;
                for(const Alumno& alumno : alumnos){
    
                    cout<<"["<<alumno.nombre<<"]"<<endl;//imprime nombre del alumno
                }
    cout << "Ingresa el nombre del alumno que desees editar su ficha" << endl;
    string nombreAlumnoEditar;
    cin.ignore();
    getline(cin, nombreAlumnoEditar);

    // Buscar el alumno por nombre
    int indiceAlumnoEditar = buscarAlumnoPorNombre(alumnos, nombreAlumnoEditar);

    if (indiceAlumnoEditar != -1) {
        Alumno& alumnoEditar = alumnos[indiceAlumnoEditar];
        cout << "Elige el número de la materia que deseas editar:" << endl;

        // Mostrar las materias del alumno
        for (size_t i = 0; i < alumnoEditar.materias.size(); ++i) {
            cout << i + 1 << ". " << alumnoEditar.materias[i].nombre << endl;
        }

        int numeroMateriaEditar;
        cin >> numeroMateriaEditar;
        validacion();

        if (numeroMateriaEditar >= 1 && numeroMateriaEditar <= alumnoEditar.materias.size()) {
            Materia& materiaEditar = alumnoEditar.materias[numeroMateriaEditar - 1];
            cout << "Seleccionaste la materia: " << materiaEditar.nombre << endl;
            cout << "¿Qué deseas editar?" << endl;
            cout << "1. Nombre de la materia" << endl;
            cout << "2. Nombre del maestro" << endl;
            cout << "3. Calificación" << endl;

            int opcionEditar;
            cin >> opcionEditar;
            validacion();

            switch (opcionEditar) {
                case 1:
                    cout << "Escribe el nuevo nombre de la materia: ";
                    cin.ignore();
                    getline(cin, materiaEditar.nombre);
                    validar_string(materiaEditar.nombre);
                    break;
                case 2:
                    cout << "Escribe el nuevo nombre del maestro: ";
                    cin.ignore();
                    getline(cin, materiaEditar.maestro);
                    validar_string(materiaEditar.maestro);
                    break;
                case 3:
                    agregar_calificacion(materiaEditar); // Utiliza la función existente para editar la calificación
                    break;
                default:
                    cout << "Opción incorrecta. No se realizó ninguna edición." << endl;
                    break;
            }
        } else {
            cout << "Número de materia inválido. No se realizó ninguna edición." << endl;
        }
    } else {
        cout << "Alumno no encontrado." << endl;
    }
    break;
} 
        case 6: 
        leerDesdeArchivo(alumnos);
        break;
            case 7: //guardar datos en un archivo
                guardarEnArchivo(alumnos);  //funcion para guardar archivo
                cout<<"Hasta luego!!"<<endl;
                break;

            default: 
                cout<<"Opción incorrecta de menú. Vuelve a ingresar una opción válida"<<endl;
        }//fin switch 
   }while(opcion!=7);
}//fin programa