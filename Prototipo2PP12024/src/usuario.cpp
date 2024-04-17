//uso de librerias
#include "usuario.h"
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iostream>
//constantes
//#include "bitacora.h"
#define USER "admin"
#define PASS "1"

using namespace std;


usuarios::usuarios()
{
    //ctor
}

usuarios::~usuarios()
{
    //dtor
}

bool usuario::LoginUsuario()
{
    string usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"---------------------------"<<endl;
        cout<<" AUTENTICACION DE USUARIOS "<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Codigo Usuario: ";
        getline(cin, usuario);
        cout<<"\nContrasena: ";
        //getline(cin, contra);
        char caracter;
        caracter = getch();
        contra="";
               while (caracter != 13) //ASCII TECLA ENTER
        {
            if (caracter != 8) //ASCII TECLA RETROCESO
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b"; //Efecto caracter borrado en pantalla
                    contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        // Obtener datos del archivo SECUENCIAL
        //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña

        if (buscar(usuario, contra)){
            ingresa=true;
            //bitacora.setRegistro(usuario, "Login correcto");
        } else {
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;
            //bitacora.setRegistro(usuario, "Login incorrecto");
        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, sus contrasenas son invalidas o agoto intentos"<<endl;
        bitacora auditoria;
        auditoria.insertar("usuario", "100", "LOGF");
        cin.get();
    } else {
        cout<<"\n=== Bienvenido al Sistema ==="<<endl;
        bitacora auditoria;
        auditoria.insertar("usuario", "100", "LOGS");
        name=usuario;
        cin.get();
    }
    return ingresa;
}

void usuarios::menuUsuarios(){
int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Usuarios"<<endl;
	cout<<"\t\t\t 2. Consulta Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificacion Usuarios"<<endl;
	cout<<"\t\t\t 4. Eliminacion Usuarios"<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	/*do
    	{
    		catalogos();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;
	case 2:
		//display();
		break;
	case 3:
		//modify();
		break;
	case 4:
		//search();
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	cin.get();
	//getch();
    }while(choice!= 5);
}


bool usuarios::buscar(string user, string passw)//metodo para buscar us
{
    system("cls");//funcion para limpar pantalla
    fstream file;//variable objeto tipo fstream llamada "file"
    int found = 0;//variable "found" que significa encontro, inicializada en 0
    file.open("Usuarios.txt", ios::in);//variable file usando la funcion .open, ingresando nombre del archivo y su parametro "ios::in" para abrir en modo lectura
    if (!file)//condicion si el archivo no se encuentra
    {
        cout << "\n-------------------------Datos de la Persona buscada------------------------" << endl;//saca en pantalla
        cout << "\n\t\t\tNo hay informacion...";//saca a pantalla con tabulacion
    }
    else//de lo contrario si existe un archivo con datos hace esto:
    {
        while (file >> id >> name >> pass)//mientras el archivo tenga estos 3 datos hacer:
        {
            if (user == id && passw == pass)//si user y passw son iguales hacer:
            {
                found++;//busqueda sera contada como 1 y sumara mas despues
                break; // No es necesario continuar buscando una vez que se ha encontrado la coincidencia
            }
        }
        file.close(); //cierre del archivo
    }

    return found > 0; // Devuelve true si se encontró al menos una coincidencia
}




string usuarios::getNombre()
{
    return name;
}
string usuarios::setNombre(string nombre)
{
    name=nombre;
}
