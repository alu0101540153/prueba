
 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <iostream>
#include <string.h>
#include "grafo.h"
using namespace std;

//esta funcion simplemente enseña las opciones que hay 
void menu (unsigned dirigido, char &opcion) {
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
  cout << "Optimiza!cion en Grafos, 2022- 2023 Víctor Rodríguez Dorta" << endl;
  cout << "c. [c]argar grafo desde fichero" << endl;
  if (dirigido == 0) { //Grafo no dirigido
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
    std::cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores." << std::endl;
	    //Aqu� se a�aden m�s opciones al men� del grafo no dirigido
  } else {
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
    cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
    std::cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores." << std::endl; 
	    //Aqu� se a�aden m�s opciones al men� del grafo dirigido
  };
  cout << "q. Finalizar el programa" << endl;
  cout << "Introduce la letra de la accion a ejecutar  > ";
  cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {
  int error_apertura; 
  char nombrefichero[85], opcion;  //creamos lo que necesitamos
  //clrscr();
  //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) { //resulta que si el argumento se le pasa de parametro al ejecutar
    cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]); // lo cargamso direcctamente
  } else { // sino, pues lo pedimos
    cout << "Introduce el nombre completo del fichero de datos" << endl;
    cin >> nombrefichero;
  };
  GRAFO G(nombrefichero, error_apertura); // creamos el grafo g que se va a formar por el fichero que se ha pasado
  if (error_apertura == 1) { // si el error de apertura es 1, mal vamos
    cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
    //pressanykey();
    //clrscr();
  } else { // si es 0, que siga el codigo
    cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
    //pressanykey();
    //clrscr();
    do {
      menu(G.Es_dirigido(), opcion); // cargamos el menu, personalizado dependiendo de si es dirigido o no
      switch (opcion) { // dependiendo de lo que elijas
        case 'c' :
        //clrscr();
          std::cout << std::endl << "......." << std::endl << std::endl;
          cout << "Introduce el nombre completo del fichero de datos" << endl;
          cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura); //actualizamos el fichero
          
          if (error_apertura == 1) {
            cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
          } else {
            cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
          };
          std::cout << std::endl << "......." << std::endl << std::endl;
          //pressanykey();
          //clrscr();
          break;

        case 'i' : 
          //clrscr();
          std::cout << std::endl << "......." << std::endl << std::endl;
          cout << "Grafo cargado desde " << nombrefichero << endl;
          G.Info_Grafo(); //generamos la funcion de informacion
          //pressanykey();
          //clrscr();
          std::cout << std::endl << "......." << std::endl << std::endl;
          break;

		    case 's': 
          std::cout << std::endl << "......." << std::endl << std::endl;
          G.Mostrar_Listas(1); //cargamos la funcion de mostrar listas
          std::cout << std::endl << "......." << std::endl << std::endl;
          break;

		    case 'p':
          std::cout << std::endl << "......." << std::endl << std::endl;
          G.Mostrar_Listas(-1); // llama a mostrar listas pero -1 para que muestre los predecesores ( asi no tener que hacer otra funcion pa eso)
          std::cout << std::endl << "......." << std::endl << std::endl;
          break;       
        
		    case 'm':
          std::cout << std::endl << "......." << std::endl << std::endl;
          G.RecorridoAmplitud();  // me da el recorrido de amplitud
          std::cout << std::endl << "......." << std::endl << std::endl;
          break;
        
		    case 'a':
          std::cout << std::endl << "......." << std::endl << std::endl;
          G.Mostrar_Listas(0); // me muestra la listas pero de adyacencia ( es decir le pongo 0 y asi reutilizo la funcion que pa algo esta )
          std::cout << std::endl << "......." << std::endl << std::endl;
          break;
        }
      } while (opcion != 'q'); // haremso todo esto mientras no le demos a q(sailir)
    }
    cout << "Fin del programa" << endl; // se ha acabao
	return(0);
};