/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 24 de Abril del 2024
PROGRAMA: Act10(ordybus).cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Este programa pedira al usuario numeros para sumar, el usuario puede editar o eliminar
elementos, borrar todos o mostrar la lista de numeros. Se optimizo con funciones, se implementaron 2 algoritmos
de ordenamiento (burbuja y quicksort), y se implementa el algoritmo de busqueda binaria. El vector tiene 50 elementos
1 funciones de autollenado, fuction to verify data type isn't a character or string, edit a number, delete a number, sum, */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <limits>
using namespace std;
int user_option, option, fill_opt, org_option, position, new_number, recorrido = 0, num; // Inicializar la opción del usuario
vector <int> vector_list;

//Definicion de funciones
void limpieza_buffer() { // add if(cin.fail()){ } before using this
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void delete_all() {
    vector_list.clear(); //EDIT THIS
    cout << "All numbers have been deleted." << endl;  
}

void print() {
    int size = vector_list.size();
    for (int recorrido = 0; recorrido < size; ++recorrido) {
     cout << vector_list[recorrido] << endl;
   }
}
    
void delete_num() {
    int position;
    cout << "Enter the position of the number you want to delete: ";
    cin >> position;
    if (position >= 0 and position < 50) {
        vector_list.erase(vector_list.begin() + position);
    } else {
        cout << "Invalid position!" << endl;
        limpieza_buffer();
    }
}
    
void edit_num() {
    int tamano = vector_list.size();
    cout << "Enter the position of the number you want to edit: ";
    cin >> position;
    if (position >= 0 && position < tamano) { //fix this
        cout << "Enter the new number: ";
        cin >> new_number;
        vector_list[position] = new_number;
    } else {
        cout << "Invalid position!" << endl;
    }   
}
    
void sum() {
    int sum = 0;
    for (int num : vector_list) {
        sum += num;
    }
    cout << "The sum of all numbers is: " << sum << endl;  
}

void random_filling() {
    for (recorrido=0; recorrido<50; ++recorrido) {
        vector_list[recorrido] = (1 + rand()) % 200;
        cout << vector_list[recorrido] << endl; //prints the ramdon filling
    } //cierra for
    cout << "Your list has been filled out randomly" << endl;
}   

void bubbleSort(vector<int> &vector_list) { //declarar asi para que tome como argumento este vector dinamico
    int tamano = vector_list.size(); //declaramos un valor entero como el tamano de la lista para que al usuarlo en el siguiente for no haya problemas de compatibilidad de tipos de datos
    for (int recorrido = 0; recorrido < tamano - 1; recorrido++) { // recorre el vector
        for (int recorrido2 = 0; recorrido2 < tamano - recorrido - 1; ++recorrido2) { // recorre los elementos no ordenados
            if (vector_list[recorrido2] > vector_list[recorrido2 + 1]) { // Compara elementos y los intercambia para ordenarlos
                int temporal = vector_list[recorrido2]; 
                vector_list[recorrido2] = vector_list[recorrido2 + 1];
                vector_list[recorrido2 + 1] = temporal; //intercambia los elementos hasta ordenarlos
            }
        }
    }   
}

/*void quickSort(vector<int>& vector_list, int pequeno, int grande) {  
    if (pequeno < grande) {
    int pivot = vector_list[grande]; // elegimos el pivote que queramos, aqui el ultimo elemento
    int recorrido = pequeno - 1; // Index of the smaller element
    for (int recorrido2 = pequeno; recorrido2 < grande; recorrido2++) {
        if (vector_list[recorrido2] < pivot) {
            ++recorrido;
            swap(vector_list[recorrido], vector_list[recorrido2]); //intercambiamos elementos con swap
        }
    }
    swap(vector_list[recorrido + 1], vector_list[grande]); // Move pivot to its correct position
    int pi = recorrido + 1; // Index of the pivot
    quickSort(vector_list, pequeno, pi - 1); // Recursively sort the subvectors
    quickSort(vector_list, pi + 1, grande);
    }
}*/

void finding_position() {
    cout << "Type the number you want to check in the list" << endl; 
    int searching_num, tamano = vector_list.size();
    cin >> searching_num;
    if (vector_list.empty()) {
        cout << "Empty vector. Add elements" << endl;
    }
    sort(vector_list.begin(), vector_list.end()); //organiza el vector con el metodo sort
    if (binary_search(vector_list.begin(), vector_list.end(), searching_num)) { //???? hace busqueda binaria con el metodo binary search desde el inicio hasta el final buscando el dato ingresado por el usuario
        for (int recorrido = 0; recorrido < tamano; recorrido++) { //recorre el vector con un for
            if (vector_list[recorrido] == searching_num) { //si cuando hace el recorrido ese elemento es igual al buscado
                cout << "The element " << searching_num << " is in the list" << ". In the position " << recorrido << endl; //se imprime
                return; //sale de la funcion, la termina
            }
        }       
    }
    cout << "The number is not in the list" << endl;
}

void intercambiar(int* a, int* b) //para ordenamiento y particion de quicksort
{
    int temporal = *a; // Almacena el valor de a en una variable temporal
    *a = *b;       // Asigna el valor de b a la posición de a
    *b = temporal;     // Asigna el valor almacenado en la variable temporal a la posición de b
}

int particion(vector<int>& vector_list, int menor, int mayor) 
{
    int pivote = vector_list[menor]; //el primer elemento sera el privote
    int izquierda = menor + 1; //recorrido desde el elemento siguiente al pivote
    int derecha = mayor; //recorrido desde el final del arreglo
    while (1) {
        while (izquierda <= derecha && vector_list[izquierda] < pivote) { // Buscar un elemento mayor o igual al pivote desde la izquierda
            izquierda++;
        }
        while (derecha >= izquierda && vector_list[derecha] > pivote) { // Buscar un elemento menor o igual al pivote desde la derecha
            derecha--;
        }
        if (izquierda >= derecha) { //cuando ambos esten en posiciones juntas se termina la particion
            break;
        }
        intercambiar(&vector_list[izquierda], &vector_list[derecha]); //se intercambian estos elementos que se encontraron
    }
    intercambiar(&vector_list[menor], &vector_list[derecha]); // Colocar el pivote en su posición correcta intercambiándolo con el último elemento menor o igual al pivote
    return derecha; // Devolver la posición del pivote
}

void quick_sort(vector<int>& vector_list, int menor, int mayor) 
{
    if (menor < mayor) {
        int Pivote = particion(vector_list, menor, mayor); //se usa la funcion para encontrar el pivote
        quick_sort(vector_list, menor, mayor - 1); // Ordenamos la mitad izquierda
        quick_sort(vector_list, Pivote + 1, mayor); // Ordenamos la mitad derecha
    }
}

int main() {
    while (user_option != 9) { // Menú principal del programa
        cout << "Welcome to the program! Choose an option:" << endl;
        cout << "1. Add a number" << endl;
        cout << "2. Show numbers" << endl; //add options to show with quicksort or bubble 
        cout << "3. Organize list" <<endl;
        cout << "4. Find a position's number" <<endl;        
        cout << "5. Edit a number" << endl;
        cout << "6. Sum numbers" << endl;
        cout << "7. Delete a number" << endl;
        cout << "8. Delete all numbers" << endl;
        cout << "9. End program" << endl;
        cin >> user_option; //missing int validation
        switch (user_option) {
            case 1: {
                cout << "Press 1 to add a number manually. Press 2 to add numbers randomly" << endl;
                cin >> fill_opt;
                    switch (fill_opt) { 
                        case 1: {
                            do { //fuction to add numbers
                                cout << "Type the number you want to add ";
                                cin >> num;
                                if (cin.fail()) {   // validar el numero
                                    cout << "Invalid number." << endl;
                                    limpieza_buffer();
                                }else if (recorrido < 50) {
                                    vector_list.push_back(num); //change this
                                    //recorrido++;
                                }else {
                                    cout<<"Your list has already reached 50 elements. Try modifing one.\n"; 
                                    break;
                                }
                                cout << "Type 1 to add another number and 2 for stopping adding numbers";   
                                cin >> option;
                                if (cin.fail()) {
                                    cout << "Invalid number. Type 1 or 2 \n";
                                    limpieza_buffer();
                                    }
                            } while (option == 1);
                        break;
                        } // cierra case 1
                        case 2: {
                            random_filling();
                            break;
                        } //cierra case 2
                        default:
                            while (fill_opt>2 or fill_opt<1 or cin.fail()) {
                                limpieza_buffer();
                                cout<<"Incorrect option. Type again an option 1-2 ";
                                cin>>fill_opt;
                            } //cierra while
                    } //cierra switch
                    break;
                //} //cierra if
            } //cierra case 1
            case 2: { // Mostrar los números
                if (vector_list.empty()) {
                cout << "Your vector is empty" << endl;
                }
                else {
                    print();
                }
                break;
            }
            case 3: { //organize list
                cout << "Select the method to organize your list. Type 1 for bubble and 2 for quick sort" << endl;
                cin >> org_option;
                switch (org_option) {
                    case 1: { //bubble
                        bubbleSort(vector_list);
                        cout << "Your ordered list with bubble is " <<endl;
                        print();
                        break;
                    }   //cierra case 1
                    case 2: { //quicksort
                        //quickSort(vector_list, 0, vector_list.size() - 1)
                        quick_sort(vector_list, 0, vector_list.size() - 1);
                        print(); //print here
                        break;
                    } //cierra case 2
                    default:
                        while (true) {
                            limpieza_buffer();
                            cout << "Incorrect option. Type 1 or 2" << endl;
                            cin >> org_option;
                        } //cierra while
                    } //cierra switch                    
                } //cierra case 3
                break;
            case 4: { 
                //ordenar fuction first and then use finding_position ???
                finding_position();
                break;   
            }
            case 5: { // Editar un número
                edit_num();
                break;
            }
            case 6: { // Sumar los números SUM FUCTION HERE
                sum();
                break;
            }
            case 7: { // Eliminar un número
                print();
                delete_num();
                break;
            } //closes case 7
            case 8: { // Eliminar todos los números
                delete_all(); //funcion para vaciar
                break;
            }
            case 9: { // Finalizar el programa
                cout << "Exiting the program." << endl;
                break;
            }
            default: // Opción inválida
                cout << "Invalid option! Please choose a valid option." << endl;
                break;
        } //closes switch
    } //closes while
} //closes main