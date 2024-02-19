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
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vector_list; // Vector para almacenar los números
    int user_option = 0; // Inicializar la opción del usuario

    while (user_option != 7) { // Menú principal del programa
        cout << "Welcome to the program! Choose an option:" << endl;
        cout << "1. Add a number" << endl;
        cout << "2. Show numbers" << endl;
        cout << "3. Edit a number" << endl;
        cout << "4. Sum numbers" << endl;
        cout << "5. Delete a number" << endl;
        cout << "6. Delete all numbers" << endl;
        cout << "7. End program" << endl;
        cin >> user_option;

        switch (user_option) {
            case 1: { // Agregar un número
                int new_number;
                cout << "Enter the number you want to add: ";
                cin >> new_number;
                vector_list.push_back(new_number);
                break;
            }
            case 2: { // Mostrar los números
                cout << "Your list:";
                for (int num : vector_list) {
                    cout << " " << num;
                }
                cout << endl;
                break;
            }
            case 3: { // Editar un número
                int position, new_number;
                cout << "Enter the position of the number you want to edit: ";
                cin >> position;
                if (position >= 0 position < vector_list.size()) {
                    cout << "Enter the new number: ";
                    cin >> new_number;
                    vector_list[position] = new_number;
                } else {
                    cout << "Invalid position!" << endl;
                }
                break;
            }
            case 4: { // Sumar los números
                int sum = 0;
                for (int num : vector_list) {
                    sum += num;
                }
                cout << "The sum of all numbers is: " << sum << endl;
                break;
            }
            case 5: { // Eliminar un número
                int position;
                cout << "Enter the position of the number you want to delete: ";
                cin >> position;
                if (position >= 0 && position < vector_list.size()) {
                    vector_list.erase(vector_list.begin() + position);
                } else {
                    cout << "Invalid position!" << endl;
                }
                break;
            }
            case 6: { // Eliminar todos los números
                vector_list.clear();
                cout << "All numbers have been deleted." << endl;
                break;
            }
            case 7: // Finalizar el programa
                cout << "Exiting the program." << endl;
                break;
            default: // Opción inválida
                cout << "Invalid option! Please choose a valid option." << endl;
                break;
        }
    }

    return 0;
}