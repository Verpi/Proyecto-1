
//Integrantes del grupo
//Dennys Stuar Hernandez Moran 7691-21-12246 
//Gerson Aníbal Caal Icó 7691-21-7797
//Jonathan Gabriel Chiguichon de Paz 7691-21-13554

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Definimos las variables que vamos a utilizar
string nombre, correo, semestre,estado, promedio, auxestado, auxpromedio;
int clave=0, auxclave=0;
char grupo[10];
char opca;
bool encontrado = false;


void agregar()
{
    ///Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ifstream consulta;

    do{
    escritura.open("alumnos.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
    consulta.open("alumnos.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico alumnos.txt

    if (escritura.is_open() && consulta.is_open()){
            bool repetido=false;
            cout<<"\n";
            cout<<"NOTA: Recuerde separar los datos ingresados con '_' de lo contrario se tomaran como datos separados\n"<<endl;
            cout<<"\tIngresa la clave del alumno:   ";
            cin>>auxclave;
            
            ///A continuación se aplica el tipo de lectura de archivos secuencial
            consulta>>clave;
            while (!consulta.eof()){
                consulta>>nombre>>correo>>semestre>>grupo>>estado>>promedio;
                if (auxclave==clave){
                    cout<<"\t\tYa existe la clave del alumno...\n";
                    repetido=true;
                    break;
                }
                consulta>>clave;
            }
            if (repetido==false){
            	cout<<"\tIngresa el nombre del alumno:	";
            	cin>>nombre;
                cout<<"\tIngresa el correo del alumno:   ";
                cin>>correo;
                cout<<"\tIngresa el semestre del alumno: ";
                cin>>semestre;
                cout<<"\tIngresa la seccion del alumno:    ";
                cin>>grupo;
                cout<<"\tIngresa El estado del alumno:     ";
                cin>>estado;
                cout<<"\tIngresa El promedio del alumno:     ";
                cin>>promedio;
                //ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
                escritura<<auxclave<<" "<<nombre<<" "<<correo<<" "<<semestre<<" "<<grupo<<" "<<estado<<" "<<promedio<<endl;
                cout<<"\n\tRegistro agregado...\n";
            }

            cout<<"\n\tDeseas ingresar otro alumno? (S/N): ";
            cin>>opca;

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    escritura.close();
    consulta.close();

    }while (opca=='S' or opca=='s');

}

void eliminar()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas eliminar: ";
        cin>>auxclave;
            ///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
            ///hasta llegar al final del archivo gracias a la función .eof()
            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>correo>>semestre>>grupo>>estado>>promedio;
                if (auxclave==clave){
                        encontrado=true;
                        cout<<"\n";
                        cout<<"\tClave:    "<<clave<<endl;
                        cout<<"\tNombre:   "<<nombre<<endl;
                        cout<<"\tCorreo:   "<<correo<<endl;
                        cout<<"\tSemestre: "<<semestre<<endl;
                        cout<<"\tSeccion:    "<<grupo<<endl;
                        cout<<"\tEstado:   "<<estado<<endl;
                        cout<<"\tPromedio:   "<<promedio<<endl;
                        cout<<"\t____________\n\n";
                        cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                        cin>>opca;

                        if (opca=='S' or opca=='s'){
                            cout<<"\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
                        }else{
                            aux<<clave<<" "<<nombre<<" "<<correo<<" "<<semestre<<" "<<grupo<<" "<<estado<<" "<<promedio<<endl;
                        }

                    }else{
                        aux<<clave<<" "<<nombre<<" "<<correo<<" "<<semestre<<" "<<grupo<<" "<<estado<<" "<<promedio<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }
    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}


void consultas()
{
    //Lectura de archivos

    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>clave;
       while (!lectura.eof()){
            lectura>>nombre>>correo>>semestre>>grupo>>estado>>promedio;
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tSemestre: "<<semestre<<endl;
            cout<<"\tSeccion:    "<<grupo<<endl;
            cout<<"\tEstado:   "<<estado<<endl;
			cout<<"\tPromedio:   "<<promedio<<endl;
            lectura>>clave;
            cout<<"\t____________\n";
       }
    }else{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
}

void buscar()
{
    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);

    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tIngresa la clave del alumno que deseas buscar: ";
        cin>>auxclave;
        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>correo>>semestre>>grupo>>estado>>promedio;
        //comparar cada registro para ver si es encontrado

        if(auxclave==clave){
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tCorreo:   "<<correo<<endl;
            cout<<"\tSemestre: "<<semestre<<endl;
            cout<<"\tSeccion:    "<<grupo<<endl;
            cout<<"\tEstado:   "<<estado<<endl;
			cout<<"\tPromedio:   "<<promedio<<endl;
            cout<<"\t____________\n";
            encontrado=true;
            break;
        }//fin del if mostrar encontrado

        //lectura adelantada
        lectura>>clave;
        }//fin del while
        if (encontrado==false){
            cout<<"\n\n\tNo hay registros con la clave: "<<auxclave<<"\n\n\t\t\t";
        }
    }else{
        cout<<"\n\tAun no se pudo abrir el archivo...";
    }

    lectura.close();
}

void modificar()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){
        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas modificar: ";
        cin>>auxclave;
            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>correo>>semestre>>grupo>>estado>>promedio;
                if (auxclave==clave){
                    encontrado=true;
                    cout<<"\n";
                    cout<<"\tClave:    "<<clave<<endl;
                    cout<<"\tNombre:   "<<nombre<<endl;
                    cout<<"\tCorreo:   "<<correo<<endl;
                    cout<<"\tSemestre: "<<semestre<<endl;
                    cout<<"\tGrupo:    "<<grupo<<endl;
            		cout<<"\tEstado:   "<<estado<<endl;
					cout<<"\tPromedio:   "<<promedio<<endl;
                    cout<<"\t____________\n\n";
                    cout<<"\tIngresa el nuevo estado del alumno con la clave: "<<auxclave<<"\n\n\t---> ";
                    cin>>auxestado;
                    cout<<"\tIngresa el nuevo promedio del alumno con la clave: "<<auxclave<<"\n\n\t---> ";
                    cin>>auxpromedio;                   
                    aux<<clave<<" "<<nombre<<" "<<correo<<" "<<semestre<<" "<<grupo<<" "<<auxestado<<" "<<auxpromedio<<endl;
                    cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
                    }else{
                    aux<<clave<<" "<<nombre<<" "<<correo<<" "<<semestre<<" "<<grupo<<" "<<estado<<" "<<promedio<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}

int main()
{
    int opc;

    do{
    system("cls");

    cout<<"\n\tManejo de archivos en c++\n\n";
    cout<<"\n\t1.-Agregar un alumno";
    cout<<"\n\t2.-Eliminar un alumno";
    cout<<"\n\t3.-Consultas";
    cout<<"\n\t4.-Buscar un Alumno";
    cout<<"\n\t5.-Modificar Datos de un Alumno";
    cout<<"\n\t6.-Salir";
    cout<<"\n\n\tElige una opcion:  ";
    cin>>opc;
    switch (opc)
    {
		case 1:{
		    system("cls");
		    agregar();
		    cout<<"\n\t\t";
		    system ("pause");
		    break;
		}
		case 2:{
		    system("cls");
		    eliminar();
		    cout<<"\n\t\t";
		    system ("pause");
		    break;
		}
		
		case 3:{
		    system("cls");
		    consultas();
		    cout<<"\n\t\t";
		    system ("pause");
		    break;
		}
		case 4:{
		    system("cls");
		    buscar();
		    cout<<"\n\t\t";
		    system ("pause");
		    break;
		}
		case 5:{
		    system("cls");
		    modificar();
		    cout<<"\n\t\t";
		    system ("pause");
		    break;
		}
		case 6:{
		    cout<<"\n\n\tHa elegido salir...\n\n\t\t"; system ("pause");
		    break;
		}
		default:{
		    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t"; 
			system ("pause");
		    break;
		}
    }//fin switch

    }while (opc!=6);
    system("cls");
    return 0;
}
