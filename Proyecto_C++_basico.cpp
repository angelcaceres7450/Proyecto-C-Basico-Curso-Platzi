#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> empleados;
string documento;

bool verficar_DNI(string dni) {
    if(!dni.find_first_not_of("0123456789")) return true;
    if (dni.length() != 8) return true;

    if (dni == documento) {
        documento.resize(0);
        return false;
    }

    for (auto empleado : empleados) {
        if (empleado[2] == dni) 
            return true; 
    }
    return false;
}

bool verificar_Edad(string edad) {
    if(!edad.find_first_not_of("0123456789")) return true;
    if(stoi(edad) < 18 || stoi(edad) > 59) return true;
    return false;
}

bool verificar_Rango(string rango) {
    if (rango == "Junior" || rango == "Semi-Senior" || rango == "Senior")
        return false;
    return true;
}

vector<string> Datos() {
    /* Empleado ---> Nombre, Apellido, DNI, Edad, Rango*/
    vector<string> empleado(5,"Empleado");
    cout << "Nombres: "; cin >> empleado[0];
    cout << "Apellidos: "; cin >> empleado[1];
    do { cout << "DNI: "; cin >> empleado[2]; } while(verficar_DNI(empleado[2]));
    do { cout << "Edad: "; cin >> empleado[3]; } while(verificar_Edad(empleado[3]));
    do { cout << "Rango: "; cin >> empleado[4]; } while(verificar_Rango(empleado[4]));
    return empleado;
}

void ingresarEmpleados() {
    cout << "Registro de Empleado Nuevo" << endl;
    empleados.push_back(Datos());
}

void mostrar(vector<string> empleado) {
    cout << "Nombre: " << empleado[0] << endl;
    cout << "Apellido: " << empleado[1] << endl;
    cout << "DNI: " << empleado[2] << endl;
    cout << "Edad: " << empleado[3] << endl;
    cout << "Rango: " << empleado[4] << endl;
}

void modificar_eliminar(int numero) {
    string dni;
    do { cout << "Ingrese el DNI del empleado: "; cin >> dni; }
        while(!dni.find_first_not_of("0123456789") || dni.length() != 8);

    for (auto & empleado : empleados) {
        if (empleado[2] == dni) {
            cout << endl; mostrar(empleado);
            cout << endl; documento = empleado[2];

            if (numero == 3) empleado = Datos();
            else {
                auto iterador = std::find(empleados.begin(), empleados.end(), empleado);
                empleados.erase(iterador);
            }
        }
    }
}

void mostrarEmpleados() {
    int contador = 0;
    cout << "Lista de Empleados" << endl;
    for (auto empleado : empleados) {
        cout << endl; contador++;
        cout << "Empleado " << contador << endl;
        mostrar(empleado);
    }
    cout << endl << "Fin de la lista de empleados" << endl;
}

int main() {
    bool menu = true; string eleccion;
    cout << endl << "Bienvenidos a Programacion Inc." << endl;
    while (menu) {
        cout << endl << "Menu" << endl;
        cout << "1. Mostrar empleados" << endl;
        cout << "2. Ingresar empleados" << endl;
        cout << "3. Modificar datos de empleados" << endl;
        cout << "4. Despedir empleados" << endl;
        cout << "5. Salir" << endl << endl;
        do { cout << "Eleccion: "; cin >> eleccion; }
            while(!eleccion.find_first_not_of("12345") || eleccion.length() != 1);
        
        switch (stoi(eleccion)) {
            case 1: cout << endl; mostrarEmpleados(); break;
            case 2: cout << endl; ingresarEmpleados(); break;
            case 3: cout << endl; modificar_eliminar(stoi(eleccion)); break;
            case 4: cout << endl; modificar_eliminar(stoi(eleccion)); break;
            default: menu = false;
        }
    }
    return 0;
}
