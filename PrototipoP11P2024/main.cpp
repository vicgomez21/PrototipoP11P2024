#include <stdio.h>      // Librería estándar de entrada y salida en C
#include <stdlib.h>     // Librería estándar de funciones de utilidad en C
#include <unistd.h>     // Librería estándar de funciones de sistema en POSIX (en este caso, getpid())
#include <string.h>     // Librería estándar de manipulación de cadenas en C
#include <iostream>     // Librería estándar de entrada y salida en C++
#include <iomanip>

 #include <iomanip> //sirve para formatos de salida
using namespace std;
#define EQUIPOS 6
#define COLUMAS 2
#define MAX_VOTOS 10
#define PIDA_VUELTA 10

void imprimirMatriz(int matriz[EQUIPOS][COLUMAS+1]);

struct TablaGeneral{
string nombre;
int PJ;
int PG;
int Pe;
int Pp;
int Puntos;
};

//La sección abarca una variedad de estructuras de control en programación
//, comenzando con una introducción sobre su importancia. Se detallan las estructuras if, if...else y switch,

int main()
{
    int matriz[EQUIPOS][COLUMAS+1];
  imprimirMatriz(matriz);
    return 0;
}
int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
// explicando su uso para tomar decisiones en el programa. Luego, se exploran las estructuras de repetición,
//incluyendo while, do...while y for. Se analiza el anidamiento de estructuras de control para acciones más complejas, y se introduce la declaración de variables dentro de bucles. También se cubre la terminación anticipada de bucles y se presentan las estructuras de control break, continue.
void imprimirMatriz(int matriz[EQUIPOS][COLUMAS+1]){
    Tabla_ida_vuelta t_ida_vuelta[PIDA_VUELTA];
    TablaGeneral T_general[EQUIPOS];
        bool repetir=true;
        char opcion;

do{
    for(int i =0;i<EQUIPOS;i++){
        cout<<"Equipo No " <<i+1 <<" de la tabla general"<<endl;
        cout<<"Nombre: ";
        cin>>T_general[i].nombre;

        T_general[i].PJ=10;

        T_general[i].PG=busquedaAleatorios( 1,5);
        T_general[i].Pe=busquedaAleatorios( 1,5);
        T_general[i].Pp=10-(T_general[i].PG+T_general[i].Pe);

        T_general[i].Puntos=(T_general[i].PG*3)+T_general[i].Pe;


        //-----------------------------------------------------------


    }
int Mpuntos=0;
int Mepuntos=100000000;
string Equipo_Menor;
string Equipo_Mayor;
int suma=0;

for(int i=0;i< EQUIPOS;i++){
//acumulador de votos
suma=suma+T_general[i].Puntos;

//mayor votos//
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
if(T_general[i].Puntos>Mpuntos){
Mpuntos=T_general[i].Puntos;
Equipo_Mayor=T_general[i].nombre;
}
//menor votos
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
if (T_general[i].Puntos<Mepuntos){
    Mepuntos=T_general[i].Puntos;
    Equipo_Menor=T_general[i].nombre;
}

}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
cout<<setw(10)<<"------Tabla general 2024-----"<<endl<<endl;
cout<<setw(9)<<"Nombre /"<<setw(9)<<" JJ"<<setw(15)<<"JG "<< setw(9) << "JP" << setw(15) << "JE" << setw(15) << "Puntos" <<  endl<<endl;
  cout<<"------------------------------------------------------------------------------------------"<<endl;
    //for para imprimir los datos
    for(int i=0;i<EQUIPOS;i++){
     cout<<setw(9)<<T_general[i].nombre<<setw(9)<<T_general[i].PJ<<setw(15)<<T_general[i].PG<< setw(9) << T_general[i].Pp << setw(15) << T_general[i].Pe << setw(15) <<T_general[i].Puntos <<  endl<<endl;
    }
    cout<<"el equipo GANADOR ES "<<Equipo_Mayor <<" con "<< Mpuntos<<" PTS"<<endl<<endl;
    cout<<"el EQUIPO que DESCIENDE ES "<<Equipo_Menor <<" con "<<Mepuntos<<" PTS"<<endl<<endl;
 cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        system("cls");
        if (opcion == 'n') {
            repetir = false;    // Si la opción es 'n', se termina el bucle
        }
    } while (repetir);



}

