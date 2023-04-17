 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2023
 */

#include "grafo.h"

//metodo destoy
// Este metodo destruye nuesta clase
void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++) // este for recorre todos los nodos del grafo
    {
		LS[i].clear(); //borra la lista de sucesores
	  
		if (dirigido == 1) // si es dirigido, entonces
        {
            LP[i].clear(); // borramos tmb su lista de presdecesores
        };
	}
	LS.clear();  // borramos todo
	LP.clear();



}

// este es el constructor de grafo
void GRAFO :: build (char nombrefichero[85], int &errorapertura) { // necesita saber el fuchero y si hay erroes
  ElementoLista  dummy; // Usado para construir lista de sucesores
  ifstream textfile; // abre el archivo especificado
  textfile.open(nombrefichero); // .open lo abre
    if (textfile.is_open()) {  // cuando esta abierto:
      errorapertura = 0;  // no hay erroes
      unsigned i, j, k;  
      //leemos el numero de nodos, arcos y el atributo dirigido
      textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido; // lee los atributos
      //ahota crea lo que necesitamso
      // creamos las n listas de sucesores
      LS.resize(n); 
      // leemos los m arcos
      for (k=0; k < m; ++k) {  // con k podemos recorrer cada arco
        textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c; //inicializamos j c que son los atributos del struct ElmentoLista
        if(Es_dirigido() == true) {  // si la funcion que detecta dirigido es true:
          LP.resize(n);               //Redimensionamos LP para meter los arcos
          dummy.j =  j - 1;    // se construye una lista de predecesotes con los objetos necesarios
          LS[i-1].push_back(dummy); //situamos en la posici�n del nodo i a dummy mediante push_back
          dummy.j =  i - 1; // colocamos i
          LP[j-1].push_back(dummy); // y push back
        }
        if(Es_dirigido() == false) { // si no es dirigido
          dummy.j = i-1; // se añade i-1 a j a LS
          LS[j-1].push_back(dummy);
          if(i!= j) { // si son difererntes
              dummy.j = j-1; // se ocnstruye dummy con j-1 y se añade a la lista de sucesotes de i-1
              LS[i-1].push_back(dummy);
            }
        }
      }
    } else {
    errorapertura = 1; //pendiente del valor a devolver en errorapertura     
    // si no pasa esto hay un error de apertura del fuchero       ...
    }		
}


//destructor
GRAFO::~GRAFO()
{
	destroy();
}

//constructor normal ( llama dirctamente a build)
GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

// actualiza la clase grafo existente para crearla con otro fichero
void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

// dice si es dirigido o no tomando el ultimo binario de la primera fila de .gr
unsigned GRAFO::Es_dirigido()
{
    return dirigido;  // evidentemente lo retonra
}

// esta funcion muestra todo lo que se sabe sobre el grafo
void GRAFO::Info_Grafo()
{
    cout << "Información del Grafo:" << endl;
    cout << " - Tipo de grafo: " << (dirigido == 1 ? "Dirigido" : "No dirigido") << endl;
    cout << " - Número de nodos: " << n << endl;
    dirigido == 1 ? cout << " - numero de arcos: " : cout << " - numero de aristas: ";
    cout << m << endl;
    
}

//
void Mostrar_Lista(vector<LA_nodo> L) { // recive un vector de nodos de una lista de adyacencia
//cada nodo tiene un j (nodo al que apunta) y c, (coste)
  for (unsigned int t{0}; t < L.size(); ++t) {  // recorre el vector de nodos
    std::cout << "[" << (t+1) << "] :"; // y los imprime por pantalla
    if (L[t].empty()) std::cout << " null"; // si no existe ese nodo , dice null
    for (unsigned int h{0}; h < L[t].size(); ++h) { //ahora quiere saber los costes
    // recorre la matriz y muestra el coste de cada necesario, osea todos los sucesotes o predecesores que tenga
      std::cout << " | " << (L[t][h].j + 1) << " (" << L[t][h].c << ")";
    }
    std::cout << std::endl; // pa separar wacho
  }
}




void GRAFO :: Mostrar_Listas (int l) {
 vector<LA_nodo> L; //caargamos un vector de nodos L
 if (l == 1 || l == 0) { // si resulta que es igual a uno o 0
   L = LS; // cargamos en L la lista de sucesores
   l == 1 ? std::cout << "Nodos de la lista de sucesores" << std::endl : std::cout << "Nodos de la lista de adyacencia" << std::endl;
 } else {
   L = LP; // si no pues cargamos lista de predecesores
   std::cout << "Nodos de la lista de predecesores" << std::endl;
 }
 std::cout << "(Nota: los costes están entre paréntesis. El otro número es el nodo)" << std::endl;
 Mostrar_Lista(L); // la mostramos 
}



void GRAFO::Mostrar_Matriz() {//Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
}




// Realiza un recorrido en profundidad recursivo en el grafo de adyacencia L
//dfs recorre en forma de arbol hasta lo mas lejos posible (no hacer)
void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) {//Recorrido en profundidad recursivo con recorridos enum y postnum

}


void GRAFO::RecorridoProfundidad() {

}


void GRAFO::bfs_num(unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) {//vector de distancias a nodo i+1
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola

    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);  
    visitado[i-1] = true;
 
    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i-1] = i; //su predecesor sera el inicial siempre
    d[i-1] = 0; //la distancia es 0 pues no nos hemso movido

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1
    bool ajuste_desfase = true;
    while (!cola.empty()) { //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
      unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
      cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
      if (ajuste_desfase == true) {
        ajuste_desfase = false; //el desfese lo rectifica
        k = k - 1;
      }
      for (unsigned h=0;h<L[k].size();h++) {
          //Recorremos todos los nodos u adyacentes al nodo k+1
          //Si el nodo u no est� visitado
        unsigned nodo = L[k][h].j;
        if(visitado[nodo] == false) {    //Si el nodo u no est� visitado
          visitado[nodo] = true;         //Lo visitamos
          cola.push(nodo);               //Lo metemos en la cola
          pred[nodo] = k+1;                //le asignamos el predecesor
          d[nodo] = d[k]+1;              //le calculamos su etiqueta distancia
      }
      };
        //Hemos terminado pues la cola est� vac�a
    };
}



void GRAFO::RecorridoAmplitud() { //Construye un recorrido en amplitud desde un nodo inicial
  unsigned int i;
  vector<LA_nodo> L(LS);
  vector<unsigned> pred;
  vector<unsigned> d;
  std::cout << "Vamos a construir un recorrido en amplitud" << std::endl;
  std::cout << "Elija nodo de partida [1 - " << n << "]: ";
  //pedimos al usuario el nodo inicial
  std::cin >> i;
  if (i <= 0) { // si es negativo error
    std::cerr << "Error: nodo ingresado no válido." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::cout << "Nodo inicial: " << i << std::endl << std::endl;
  bfs_num(i,L,pred,d); //ahora recurrimos ala funcion que nos calcula el recorrido de amplitud
  bool aux = true; // creamos una aux que es true
  
  
  for (unsigned int t{0}; t < d.size(); ++t) { // recorremos el grafo con d siendo la distancia
    aux = false; // aux sigue siendo falso
    for (unsigned int h{0}; h < d.size();++h) { // otra variable h que recorre tambien
    // t es la distancia y h las aristas
      if(d[h] == t && pred[h] != 0) {  // cuando suceda que la distancia es la misma y tiene algun predecesor
        //significa que tiene estos datos:
        if (aux == false) std::cout << "Distancia " << t << " aristas";
        aux = true; // ahora auz puede ser true al fun
        std::cout << " : " << (h+1);
      }
    }
    if (aux == false) break; // en tal caso de que sigua siendo falso, entonces se acaba
    std::cout << std::endl;
  }
  
  std::cout << std::endl;
  std::cout << "Ramas de conexión en el recorrido:" <<std::endl; 
  // vamos a decir las ramas

  for (unsigned int t{1}; t < pred.size(); ++t) { // volvemso a recorrerlo
    for (unsigned int h{0}; h < d.size(); ++h) {

      vector<unsigned int> v_temp; // creamos un temporal vector
      if (d[h] == t && pred[h] != 0) {  // cuando suceda que la distancia es la misma y tiene algun predecesor
        unsigned int temp = h+1; //temporal es h+1
        v_temp.push_back(temp); // metemos el temporal en el vector
        while (pred[(temp-1)] != i) { // mientes el predecesor no coincida con i, que es el nodo de partida
          temp = pred[temp-1]; // temporal pasara a ser el pred
          if (temp != i) v_temp.push_back(temp); //si resulta que el temporal es el inicial:
          //añade temporal al final del vector de temporales
        }
        std::cout << i; // imprimimos por pantalla el vector inicial del recorrido
        for (unsigned int x{v_temp.size()}; x > 0; --x ) { // y ahora recorremos el vector de temporales pero al reves
          std::cout << " - " << v_temp[x-1]; // y nombramos cada uno que van saliendo ( ese sera el orden de recorrido de amplitud)
        }
        std::cout << std::endl;
      }

    }
  }

  
}





