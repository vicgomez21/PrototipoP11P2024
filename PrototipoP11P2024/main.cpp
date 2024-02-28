#include <stdio.h>      // Librería estándar de entrada y salida en C
#include <stdlib.h>     // Librería estándar de funciones de utilidad en C
#include <unistd.h>     // Librería estándar de funciones de sistema en POSIX (en este caso, getpid())
#include <string.h>     // Librería estándar de manipulación de cadenas en C
#include <iostream>     // Librería estándar de entrada y salida en C++
#include <iomanip>

 #include <iomanip> //sirve para formatos de salida
using namespace std;
#define EQUIPOS 5
#define COLUMAS 3
#define MAX_VOTOS 50


void imprimirMatriz(int matriz[EQUIPOS][COLUMAS+1]);

struct TablaGeneral{
string nombre;
int P2010;
int P2011;
int p2012;
int p2014;
int Puntos;

};
struct LigaAscenso{
string nombre;
int P2010;
int P2011;
int P2014;
int P2012;
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

    TablaGeneral T_general[EQUIPOS];
    LigaAscenso liga_asenso[EQUIPOS];
        bool repetir=true;
        char opcion;

do{
    for(int i =0;i<EQUIPOS;i++){
        cout<<"Equipo No " <<i+1 <<" de la tabla de Liga Nacional"<<endl;
        cout<<"Nombre: ";
        cin>>T_general[i].nombre;

        T_general[i].P2010=busquedaAleatorios( 1,MAX_VOTOS);

        T_general[i].P2011=busquedaAleatorios( 1,MAX_VOTOS);
        T_general[i].p2012=busquedaAleatorios( 1,MAX_VOTOS);
        T_general[i].p2014=busquedaAleatorios( 1,MAX_VOTOS);

        T_general[i].Puntos=(T_general[i].P2010+T_general[i].P2011+T_general[i].p2012+T_general[i].p2014);



}


        //-----------------------------------------------------------
for(int i =0;i<EQUIPOS;i++){
        cout<<"Equipo No " <<i+1 <<" de la tabla de Liga Asenso"<<endl;
        cout<<"Nombre: ";
        cin>>liga_asenso[i].nombre;

        liga_asenso[i].P2010=busquedaAleatorios( 1,MAX_VOTOS);

        liga_asenso[i].P2011=busquedaAleatorios( 1,MAX_VOTOS);
        liga_asenso[i].P2012=busquedaAleatorios( 1,MAX_VOTOS);
        liga_asenso[i].P2014=busquedaAleatorios( 1,MAX_VOTOS);

        liga_asenso[i].Puntos=(liga_asenso[i].P2010+liga_asenso[i].P2011+liga_asenso[i].P2012+liga_asenso[i].P2014);


        //-----------------------------------------------------------


    }
int Mpuntos=0;
int Mepuntos=100000000;
string Equipo_Menor;
string Equipo_Mayor;
int suma=0;
int Mpuntos1=0;
int Mepuntos1=100000000;
string Equipo_Menor1;
string Equipo_Mayor1;
int suma1=0;

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
//segundo for
//-------------------------------------------------------------------
for(int i=0;i< EQUIPOS;i++){
//acumulador de votos
suma1=suma1+liga_asenso[i].Puntos;

//mayor votos//
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
if(liga_asenso[i].Puntos>Mpuntos1){
Mpuntos1=liga_asenso[i].Puntos;
Equipo_Mayor1=liga_asenso[i].nombre;
}
//menor votos
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
if (liga_asenso[i].Puntos<Mepuntos1){
    Mepuntos1=liga_asenso[i].Puntos;
    Equipo_Menor1=liga_asenso[i].nombre;
}

}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
cout<<setw(10)<<"------Historial Liga Nacional-----"<<endl<<endl;
cout<<setw(9)<<"Nombre /"<<setw(9)<<" Torneo 2010/"<<setw(15)<<"Torneo 2011/"<< setw(9) << "Torneo 2012/" << setw(15) << "Torneo 2014/" << setw(15) << "PTS acumulados/" <<  endl<<endl;
  cout<<"------------------------------------------------------------------------------------------"<<endl;
    //for para imprimir los datos
    for(int i=0;i<EQUIPOS;i++){
     cout<<setw(9)<<T_general[i].nombre<<setw(9)<<T_general[i].P2010<<setw(15)<<T_general[i].P2011<< setw(9) << T_general[i].p2012 << setw(15) << T_general[i].p2014 << setw(15) <<T_general[i].Puntos <<  endl<<endl;
    }
    cout<<"EL EQUIPO "<<Equipo_Mayor <<" TIENE  "<< Mpuntos<<" PTS Y ES LA PUNTUACION MAS ALTA"<<endl<<endl;
    cout<<"EL EQUIPO "<<Equipo_Menor <<" TIENE "<<Mepuntos<<" PTS Y ES LA PUNTUACION MAS ALTA"<<endl<<endl;


//----------------------------------------------------------------------------------------------------------------
cout<<setw(10)<<"------Historial Liga Ascenso-----"<<endl<<endl;
cout<<setw(9)<<"Nombre /"<<setw(9)<<" Torneo 2010/"<<setw(15)<<"Torneo 2011/"<< setw(9) << "Torneo 2012/" << setw(15) << "Torneo 2014/" << setw(15) << "PTS acumulados/" <<  endl<<endl;
  cout<<"------------------------------------------------------------------------------------------"<<endl;
    //for para imprimir los datos
    for(int i=0;i<EQUIPOS;i++){
     cout<<setw(9)<<liga_asenso[i].nombre<<setw(9)<<liga_asenso[i].P2010<<setw(15)<<liga_asenso[i].P2011<< setw(9) << liga_asenso[i].P2012 << setw(15) << liga_asenso[i].P2014 << setw(15) <<liga_asenso[i].Puntos <<  endl<<endl;
    }
    cout<<"EL EQUIPO "<<Equipo_Mayor1 <<" TIENE  "<< Mpuntos1<<" PTS Y ES LA PUNTUACION MAS ALTA"<<endl<<endl;
    cout<<"EL EQUIPO "<<Equipo_Menor1 <<" TIENE "<<Mepuntos1<<" PTS Y ES LA PUNTUACION MAS ALTA"<<endl<<endl;



 cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        system("cls");
        if (opcion == 'n') {
            repetir = false;    // Si la opción es 'n', se termina el bucle
        }
    }while (repetir);



}



