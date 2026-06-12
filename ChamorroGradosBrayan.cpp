#include <iostream>
using namespace std;

int main() {
    string nombres[100];
    string carreras[100];
    int edades[100];
    int semestres[100]; 
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n=== REGISTRO DE ESTUDIANTES ===\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Nombre: ";
                cin >> nombres[cantidad];

                cout << "Edad: ";
                cin >> edades[cantidad];

                cout << "Carrera: ";
                cin >> carreras[cantidad];

                cout << "Semestre (1-10): ";   // NUEVO
                cin >> semestres[cantidad]; 

                cantidad++;
                cout << "Estudiante registrado.\n";
                break;

            case 2:
                cout << "\n--- LISTA DE ESTUDIANTES ---\n";
                for(int i = 0; i < cantidad; i++) {
                    cout << "\nEstudiante " << i + 1 << endl;
                    cout << "Nombre: " << nombres[i] << endl;
                    cout << "Edad: " << edades[i] << endl;
                    cout << "Carrera: " << carreras[i] << endl;
                    cout << "Semestre: "  << semestres[i]  << endl;
                }
                break;

            case 3:
                cout << "Fin del programa.\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while(opcion != 3);

    return 0;
}
