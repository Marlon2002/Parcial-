#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#define s 30 
using namespace std;

void co(int, int);
const char *nombe_archivo = "Empleado.dat";
const char *nom_temporal = "temporal.dat";

struct Empleado
{
    int codigo;
    char nombre[s];
    char apellido[s];
    char puesto[s];
    float sueldo;
    float bonificacion;
    float total;
};
void eliminar_dato();

void ingresar_dato();
void mostrar_dato();
void menu();
void modificar_dato();
void buscar_dato();

int main()
{
    menu();
}

void menu()
{
    int a, b, c;
    do
    {
        system("cls");
        cout << (" 1. Insertar  Datos")<<endl;
        cout << (" 2. Ver Datos")<<endl;
        cout << (" 3. Buscar Dato")<<endl;
        cout << (" 4. Modificar Dato")<<endl;
        cout << (" 5. Eliminar Dato")<<endl;
        cout << (" 6. Salir")<<endl;
        cout << ("Ingrese opcion: ")<<endl;
        cin >> a;
        switch (a)
        {
        case 1:
            system("cls");
            ingresar_dato();
            break;
        case 2:
            system("cls");
            mostrar_dato();
            break;
        case 3:
            system("cls");
            buscar_dato();
            break;
        case 4:
            system("cls");
            modificar_dato();
            break;

        case 5:
            system("cls");
            eliminar_dato();
            break;
        }
    } while (a != 6);
}

void ingresar_dato()
{
    char continuar;
    FILE *archivo = fopen(nombe_archivo, "ab"); // ab
    Empleado emp;
        string nombre,apellido, puesto;
    do
    {
        system("cls");
        fflush(stdin);
        emp.codigo = 0;
        emp.codigo = emp.codigo + 1;
        
        cout << "Ingrese nombre: "<<endl;
        getline(cin, nombre);
        strcpy(emp.nombre, nombre.c_str());

        
        cout << "Ingrese apellido: "<<endl;
        getline(cin, apellido);
        strcpy(emp.apellido, apellido.c_str());

        
        cout << "Ingrese puesto: "<<endl;
        getline(cin, puesto);
        strcpy(emp.puesto, puesto.c_str());

        cout << "Sueldo Base: "<<endl;
        cin >> emp.sueldo;
        cin.ignore();
        
        cout << "Bonificacion: "<<endl;
        cin >> emp.bonificacion;
        cin.ignore();
        emp.total = emp.sueldo + emp.bonificacion;

        fwrite(&emp, sizeof(Empleado), 1, archivo);

        
        cout << "Desea Agregar otro Palabra s/n : ";
        cin >> continuar;
    } while ((continuar == 's') || (continuar == 'S'));
    fclose(archivo);
    system("cls");
}

void modificar_dato()
{
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id;
    char respuesta[s];
    string nombre, apellido, puesto;
    Empleado emp;

    cout << "Ingrese el ID que desea Modificar: ";
    cin >> id;
    fseek(archivo, id * sizeof(Empleado), SEEK_SET);
    fread(&emp, sizeof(Empleado), 1, archivo);

    
    cout << ("------------   Datos Encontrados -------------")<<endl;
    
    cout << ("nombre:  [") << emp.nombre << ("]")<<endl;
    
    cout << ("apellido:  [") << emp.apellido << ("]")<<endl;
    
    cout << ("Puesto:  [") << emp.puesto << ("]")<<endl;

    cout << ("Sueldo Base:  [") << emp.sueldo << ("]")<<endl;
    
    cout << ("bonificacion [") << emp.bonificacion << ("]")<<endl;

    cout << ("---------------------------------------------")<<endl;

    cout << "<\n\n Nombre: " << emp.nombre << endl;
    cout << ("Desea modificar la palabra [s/n]: ");
    cin >> respuesta, s;

    if (strcmp(respuesta, "s") == 0)
    {

        fseek(archivo, id * sizeof(Empleado), SEEK_SET);
        cin.ignore();
        cout << ("Nuevo Nombre : ")<<endl;
        getline(cin, nombre);
        strcpy(emp.nombre, nombre.c_str());
        fwrite(&emp, sizeof(Empleado), 1, archivo);
    }

    cout << "\n\nApellido: " << emp.apellido << endl;
    cout << ("Desea modificar el apellido [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Empleado), SEEK_SET);
        cin.ignore();
        cout << "Ingrese nuevo Apellido: "<<endl;
        getline(cin, apellido);
        strcpy(emp.apellido, apellido.c_str());
        fwrite(&emp, sizeof(Empleado), 1, archivo);
    }

    
    cout << "\n\nPuesto: " << emp.puesto << endl;
    cout << ("Desea modificar el puesto [s/n]: ")<<endl;
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Empleado), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nuevo Puesto: "<<endl;
        getline(cin, puesto);
        strcpy(emp.puesto, puesto.c_str());
        fwrite(&emp, sizeof(Empleado), 1, archivo);
    }


    cout << "\n\nSueldo: " << emp.sueldo << endl;
    cout << ("Desea modificar el sueldo [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Empleado), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nueva Sueldo: "<<endl;
        cin >> emp.sueldo;
        fwrite(&emp, sizeof(Empleado), 1, archivo);
    }

    cout << "\n\nBonificion: " << emp.bonificacion << endl;
    cout << ("Desea modificar la boni [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0){
        fseek(archivo, id * sizeof(Empleado), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nueva Bonificacion: "<<endl;
        cin >> emp.bonificacion;
        fwrite(&emp, sizeof(Empleado), 1, archivo);
    }

    emp.total = emp.sueldo + emp.bonificacion;
    system("cls");
    cout << ("Los datos han sido actualizados.");
    fclose(archivo);
    getch();
    mostrar_dato();
}

void mostrar_dato()
{
    system("cls");
    FILE *archivo = fopen(nombe_archivo, "rb");
    if (!archivo)
    {
        archivo = fopen(nombe_archivo, "w+b");
    }

    Empleado emp;
    int registro = 0;
    fread(&emp, sizeof(Empleado), 1, archivo);
    cout << "___________________________________________________________________________________________________________________" << endl;
    cout << "id|"
         << "  Nombre\t|"
         << "\tApellido\t |"
         << "\tPuesto\t |"
         << "\tSueldo\t"
         << "\tBonificacion\t |"
         << "\tTotal\t |" << endl;

    do
    {

        cout << "_________________________________________________________________________________________________________________" << endl;
        cout << registro <<"\t"<<emp.nombre<< "|\t"<<"\t" << emp.apellido << "|\t"<<"\t" << emp.puesto << " \t|"<<"\t" << emp.sueldo << "\t|"<<"\t" << emp.bonificacion << "\t|" <<"\t" << emp.total << endl;

        fread(&emp, sizeof(Empleado), 1, archivo);
        registro += 1;

    } while (feof(archivo) == 0);

    cout << endl;

    fclose(archivo);
    getch();
}

void buscar_dato()
{

   FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Digite el codigo del registro a buscar: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado emp;
    
    fread(&emp, sizeof(Empleado), 1, archivo);

    cout << "Codigo: " <<pos<< endl;
    cout << "Nombre: " << emp.nombre << endl;
    cout << "Apellido: " << emp.apellido << endl;
    cout << "puesto: " << emp.puesto << endl;
    cout << "Sueldo Base: " << emp.sueldo << endl;
    cout << "Bonificacion: " << emp.bonificacion << endl;
    cout << "Total: " << emp.total << endl;
    cout << endl;

    fclose(archivo);
    system("PAUSE");
}

void eliminar_dato()
{
    Empleado emp;
    FILE *temporal = fopen(nom_temporal, "w+b");
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id;
    cout << "Ingrese el codigo que desea eliminar: ";
    cin >> id;
    fseek(archivo, id * sizeof(Empleado), SEEK_SET);
    emp.codigo = -1;
    fwrite(&emp, sizeof(Empleado), 1, archivo);
    fclose(archivo);

    archivo = fopen(nombe_archivo, "r+b");

    fread(&emp, sizeof(Empleado), 1, archivo);
    temporal = fopen(nom_temporal, "a+b");
    do
    {
        if (emp.codigo == -1)
        {
            cout << "Archivo eliminado";
        }
        if (emp.codigo >= 0)
        {
            fwrite(&emp, sizeof(Empleado), 1, temporal);
        }
        fread(&emp, sizeof(Empleado), 1, archivo);
    } while (feof(archivo) == 0);
    fclose(temporal);
    fclose(archivo);

    archivo = fopen(nombe_archivo, "w");
    fclose(archivo);

    temporal = fopen(nom_temporal, "r+b");

    fread(&emp, sizeof(Empleado), 1, temporal);
    archivo = fopen(nombe_archivo, "a+b");
    do
    {
        fwrite(&emp, sizeof(Empleado), 1, archivo);
        fread(&emp, sizeof(Empleado), 1, temporal);
    } while (feof(temporal) == 0);
    fclose(archivo);
    fclose(temporal);

    temporal = fopen(nom_temporal, "w");
    fclose(temporal);

    mostrar_dato();
}
