/* <3 <3 PRESENTACION <3 <3
NOMBRE: Tania Citlaly de Anda Lara
FECHA: 15 de Marzo del 2024
PROGRAMA: Act7_operacionesdeconjuntos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCION: Programa que realiza operaciones de 2 conjuntos: Union, interseccion, complemento, 
diferencia simetrica, borrado de elementos, editar elementos, vaciar conjuntos. Minimo 5 elementos en cada conjunto. 
El usuario puede agregar tipo de dato char para agregar numeros y letras. Se tiene que validar todo*/
#include <iostream> //entrada y salida de datos
#include <vector> //para funciones de .clear y vetores
#include <limits> 
#include <algorithm> 
#include <set> //para merge 2 vectors
using namespace std;
vector<char>conjunto1; //se inicializa vector dinamico sin limite
vector<char>conjunto2; //vector 2 dinamico sin limite
vector<char> union_c(conjunto1.size()+conjunto2.size()); //vector para almacenar la union
vector<char> interseccion(conjunto1.size()+conjunto2.size()); //vector para almacenar la union
vector<char>dif_simetrica(conjunto1.size()+conjunto2.size()); //almacena diferencia simetrica
vector<char>complemento_c1(conjunto1.size()+conjunto2.size());
vector<char>complemento_c2(conjunto1.size()+conjunto2.size());
vector<char>::iterator it; //hace recorrido de los elementos de ambos vectores y si alguno no existe en el otro lo agrega
int menu_option, option_c, position, size_conjunto1, size_conjunto2, complemento_option;
char new_num;
int main() {
    sort(conjunto1.begin(), conjunto1.end()); //ordenar los vectores para poder usar "set_union" y otras operaciones con conjuntos
    sort(conjunto2.begin(), conjunto2.end()); //same
    do {
        cout<<"Bienvenido a calculadora de operaciones de conjuntos. A continuacion ingresa la opcion que sea de tu agrado: \n1.Conjunto 1 \n2.Conjunto 2 \n3.Union \n4.Interseccion \n5.Complemento \n6.Diferencia simetrica \n7.Terminar operaciones"<<endl;
        cin>>menu_option;
            switch(menu_option){
                case 1: //conjuntO 1
                    cout<<"Bienvenido a tu conjunto 1. A continuacion ingresa la opcion de tu agrado: \n1.Tamano y elementos \n2.Editar/eliminar elementos \n3.Vaciar conjunto \n4.Imprimir elementos del conjunto \n5.Regresar a menu inicial"<<endl;
                    cin>>option_c;
                        switch(option_c){
                            case 1: 
                                cout<<"A continuacion ingresa el numero de elementos que deseas que contenga tu conjunto 1. Recuerda que debe contener mas de 5 elementos."<<endl;
                                cin>>size_conjunto1;
                                while(size_conjunto1<5 or cin.fail()) { //valida datos de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //limpia el buffer de entrada
                                    cout<<"Ingresa nuevamente un tamano valido. Recuerda que tu conjunto debe contener mas de 5 elementos."<<endl;
                                    cin>>size_conjunto1;
                                }
                                cout<<"Escribe los elementos que deseas agregar segun el tamano del conjunto que definiste anteriormente"<<endl;
                                for (position=0; position<size_conjunto1; position++) {
                                    cin>>new_num;
                                    conjunto1.push_back(new_num);
                                }//cierra for
                                break;
                            case 2://edit or delete number, METHOD .erase is not working
                                cout<<"Escribe la posicion que deseas editar o eliminar"<<endl;
                                cin>>position;
                                while (true) {
                                    if (cin.fail()) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //limpia el buffer de entrada
                                        cout<<"Ingresa una posicion valida en numeros."<<endl;
                                        cin>>position;
                                    }//cierra if
                                    if (position>=0 and position<conjunto1.size()){
                                        conjunto1.erase(conjunto1.begin()+position); //verifica que la opcion exista en la lista
                                    }
                                    else {
                                        cout<<"Posición incorrecta. Vuelve a escribir una posicion existente. Asegurate de que hayas llenado tus conjuntos correctamente"<<endl;
                                        cin>>position;
                                    }
                                }//cierra while
                            cout<<"Escribe el numero o valor que deseas agregar en su lugar"<<endl;
                            cin>>new_num;
                            conjunto1.insert(conjunto1.begin() + position,new_num); //insertar numero en ese lugar
                                break;
                            case 3:
                                conjunto1.clear();
                                cout<<"Tu conjunto se ha vaciado correctamente"<<endl; //mostrar conjunto para comprobar que se borro?
                                break;
                            case 4: //print vecto
                                if (size_conjunto1<5) {
                                    cout<<"Tu conjunto esta vacio. Ingresa elementos"<<endl;
                                }
                            else {cout<<"Tu conjunto 1 esta formado por los elementos: "<<endl; //IS ONLY PRINTING THE NUMERO OF ELEMENTS
                                for (int position = 0; position <size_conjunto1/*conjunto1.size()*/; position++) {
                                    cout << conjunto1[position] << endl;
                                } //cierra for
                            } //else
                                break;
                            case 5: //go back to the main menu
                                break;
                            default:
                                cout<<"Opcion incorrecta de menu. Vuelve a ingresar una opcion valida del 1-4";
                                cin>>option_c;
                        } //cierra switch
                    break;
                case 2: //conjunto 2 DO SAME AS THE FIRST ONE, SAME MENU OPTIONS
                    cout<<"Bienvenido a tu conjunto 2. A continuacion ingresa la opcion de tu agrado: \n1.Tamano y elementos \n2.Editar/eliminar elementos \n3.Vaciar conjunto \n4.Imprimir elementos del conjunto \n5.Regresar a menu inicial"<<endl;
                    cin>>option_c;
                        switch(option_c){
                            case 1:
                                cout<<"A continuacion ingresa el numero de elementos que deseas que contenga tu conjunto 2. Recuerda que debe contener mas de 5 elementos."<<endl;
                                cin>>size_conjunto2;
                                while (size_conjunto2<5 or cin.fail()) { //valida datos de entrada
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //limpia el buffer de entrada
                                    cout<<"Ingresa nuevamente un tamano valido. Recuerda que tu conjunto debe contener mas de 5 elementos."<<endl;
                                    cin>>size_conjunto2;
                                }//cierra whiie
                            cout<<"Escribe los elementos que deseas agregar segun el tamano del conjunto que definiste anteriormente"<<endl;
                            for (position=0; position<size_conjunto2; position++) {
                                cin>>new_num;
                                conjunto2.push_back(new_num);
                            }//cierra for
                                break;
                            case 2://edit or delete number, METHOD .erase is not working
                                cout<<"Escribe la posicion que deseas editar o eliminar"<<endl;
                                cin>>position;
                                while (true) {
                                    if (cin.fail()) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //limpia el buffer de entrada
                                        cout<<"Ingresa una posicion valida en numeros."<<endl;
                                        cin>>position;
                                    }//cierra if
                                    if (position>=0 and position<conjunto1.size()){
                                        conjunto2.erase(conjunto1.begin()+position); //verifica que la opcion exista en la lista
                                    }
                                    else {
                                        cout<<"Posición incorrecta. Vuelve a escribir una posicion existente. Asegurate de que hayas llenado tus conjuntos anteriormente"<<endl;
                                        cin>>position;
                                    } //else
                                }//cierra while
                            cout<<"Escribe el numero o valor que deseas agregar en su lugar"<<endl;
                            cin>>new_num;
                            conjunto1.insert(conjunto1.begin() + position,new_num); //insertar numero en ese lugar
                                break;
                            case 3:
                                conjunto2.clear();
                                cout<<"Tu conjunto se ha vaciado correctamente"<<endl; //mostrar conjunto para comprobar que se borro?
                                break;
                            case 4: //print vector
                            if (size_conjunto2<5) {
                                cout<<"Tu conjunto esta vacio. Ingresa elementos"<<endl;
                            }
                            else {
                                cout<<"Tu conjunto 1 esta formado por los elementos: "<<endl; //IS ONLY PRINTING THE NUMERO OF ELEMENTS
                                for (int position = 0; position <size_conjunto2/*conjunto1.size()*/; position++) {
                                    cout << conjunto2[position] << endl;
                                } //cierra for
                            } //else
                                break;
                            case 5: //goes back to the main menu
                                break;
                            default:
                                cout<<"Opcion incorrecta de menu. Vuelve a ingresar una opcion valida del 1-4";
                            cin>>option_c;
                        } //cierra switc
                    break;
                case 3: //union de conjuntos
                    if (conjunto1.empty()) {
                        cout<<"Union vacia. Agrega elementos a tus conjunto 1"<<endl;
                    }
                    if (conjunto2.empty()) {
                        cout<<"Union vacia. Agrega elementos a tu conjunto 2"<<endl;
                    }
                    else {
                        union_c.resize(conjunto1.size() + conjunto2.size()); //se redimensiona el tamano del vector
                        it = set_union(conjunto1.begin(), conjunto1.end(), conjunto2.begin(), conjunto2.end(), union_c.begin()); //unir vectores
                        union_c.resize(it-union_c.begin()); //redimensionar el vector segun los elementos dados anteriormente
                        cout<<"La union de tus conjuntos es ";
                        for (char const &position: union_c){
                            cout<<position<<",";
                        } //closes for
                        cout<<endl;
                    } // closes else
                    break;
                case 4: //interseccion set_intersection
                    if (conjunto1.empty()) {
                        cout<<"Interseccion vacia. Agrega elementos a tus conjunto 1"<<endl;
                    }
                    if (conjunto2.empty()) {
                        cout<<"Interseccion vacia. Agrega elementos a tu conjunto 2"<<endl;
                    }
                    else {
                        interseccion.resize(conjunto1.size() + conjunto2.size()); //se redimensiona el tamano del vector 
                        it = set_intersection(conjunto1.begin(), conjunto1.end(), conjunto2.begin(), conjunto2.end(), interseccion.begin()); //unir vectores
                        interseccion.resize(it-interseccion.begin()); //redimensionar el vector segun los elementos dados anteriormente
                        cout<<"La interseccion de tus conjuntos es ";
                        for (char const &position: interseccion){
                            cout<<position<<",";
                        } //closes for
                        cout<<endl;
                    } // closes else
                    break;
                case 5: //complemento
                    cout<<"A continuacion escribe el complemento del conjunto que desees saber: \n1.Conjunto 1 \n2.Conjunto 2 \n3.Terminar operaciones"<<endl;
                    cin>>complemento_option;
                        switch(complemento_option){
                            case 1://needs to take only exclusive elements del conjunto 2 que no esten en el conjunto 1
                                if (conjunto1.empty()) {
                                    cout<<"No se puede calcular el complemento. Agrega elementos a tus conjunto 1"<<endl;
                                }
                                if (conjunto2.empty()) {
                                    cout<<"No se puede calcular el complemento. Agrega elementos a tu conjunto 2"<<endl;
                                }
                                else {
                                    complemento_c1.resize(conjunto2.size());
                                    set_difference (conjunto2.begin(), conjunto2.end(), conjunto1.begin(), conjunto1.end(), back_inserter(complemento_c1));
                                    cout<<"El complemento de tu conjunto 1 es ";
                                    for (char const &position: complemento_c1){
                                        cout<<position<<",";
                                    } //closes for
                                    cout<<endl;
                                } // closes else
                                break;
                            case 2: //needs to take only exclusive elements del conjunto 1 que no esten en el conjunto 2 set_complement HERE
                                if (conjunto1.empty()) {
                                    cout<<"No se puede calcular el complemento. Agrega elementos a tus conjunto 1"<<endl;
                                }
                                if (conjunto2.empty()) {
                                    cout<<"No se puede calcular el complemento. Agrega elementos a tu conjunto 2"<<endl;
                                } 
                                else {
                                    complemento_c2.resize(conjunto1.size());
                                    set_difference (conjunto1.begin(), conjunto1.end(), conjunto2.begin(), conjunto2.end(), back_inserter(complemento_c2));
                                    cout<<"El complemento de tu conjunto 2 es ";
                                    for (char const &position: complemento_c2){
                                        cout<<position<<",";
                                    } //closes for
                                    cout<<endl;
                                } // closes else
                                break;
                            case 3:
                                cout<<"Haz terminado operaciones"<<endl;
                                break;
                            default:
                                while (true) {
                                    cout<<"Opcion incorrecta de menu. Vuelve a ingresar una opcion del 1-3";
                                    cin>>complemento_option;
                                } //cierra while
                        } //cierra switch
                    break;
                case 6: //diferencia simetrica set_symmetric_difference, means todo menos lo que tienen en comun, eliminar lo que tienen en comun los elementos y dejar lo demas
                    if (conjunto1.empty()) {
                        cout<<"Diferencia simetrica vacia. Agrega elementos a tus conjunto 1"<<endl;
                    }
                    if (conjunto2.empty()) {
                        cout<<"Diferencia simetrica vacia. Agrega elementos a tu conjunto 2"<<endl;
                    } 
                    else {
                        dif_simetrica.resize(conjunto1.size() + conjunto2.size()); //redimensionar el vector 
                        it = set_symmetric_difference(conjunto1.begin(), conjunto1.end(), conjunto2.begin(), conjunto2.end(), dif_simetrica.begin()); //unir vectores
                        dif_simetrica.resize(it-interseccion.begin()); //redimensionar el vector segun los elementos dados anteriormente
                        cout<<"La diferencia simetrica de tus conjuntos es ";
                        for (char const &position: dif_simetrica){
                            cout<<position<<",";
                        } //closes for
                        cout<<endl;
                    } // closes else
                    break;
                case 7: //program ends
                    cout<<"Has finalizado calculadora de operaciones de conjuntos. Gracias por usarme, hasta pronto"<<endl;
                    break;
                default:
                    while (menu_option!=7 or menu_option<=0 or cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"Opcion incorrecta de menu. Vuelve a ingresar una opcion valida del 1-7";
                        cin>>menu_option;
                    } //closes while
                break;
            } //cierra 1er switch
    } while (menu_option!=7 or menu_option<=0);
    cout<<"Opcion incorrecta de menu. Vuelve a ingresar una opcion valida del 1-7";
    return 0;
} //closes main