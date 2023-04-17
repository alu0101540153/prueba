// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6 //precision

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
// Representa polinomios usando listas de pares ( el primer elemento del par es coeficiente, el segundo exponente)
class SllPolynomial : public sll_t<pair_double_t> { //heredera de sll_t y de pairs
 public: //metodos (no hay private pq lo hereda de sll_t)
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
   void Scalar(SllPolynomial&, const double scalar);
  SllPolynomial removeFirstAndLastNodes(const SllPolynomial& polynomial);
  SllPolynomial EliminarlosImpares(const SllPolynomial& polynomial);
  pair_double_t RemoveLast();
  void SumarCoeficientesContinuos(SllPolynomial& aux);
  void SumarCoeficientesIguales(SllPolynomial& aux);
  void EliminarImpares();
  void OrdenarPoly();
};

//funcion quecomprueva si es 0
bool IsNotZero(const double val, const double eps = EPS) { // necesita valor y necesita epsilon
  return fabs(val) > eps; // si el valor absoluto de val es mayor que epsilon NOES 0 y devuelve 1, si no , 0
} 

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for (int i = v.get_size()-1; i >= 0; i--){ //recorremos la lista ( como si fuera un vector)
    if (IsNotZero(v[i], eps)){ // si no es 0 entonces
      push_front(new SllPolyNode(pair_double_t(v.get_val(i), i))); // metemos en la lista ( con push front ) un nuevo nodo de par (coeficiente, exponente)
    }
  }
}


// E/S ( MEtodo prara el cout)
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ "; //abrimos corchete
  bool first{true}; // si es el primero
  SllPolyNode* aux{get_head()}; // creamos un aux que apunta a primero
  while (aux != NULL) { // mientras exista
    int inx{aux->get_data().get_inx()}; // cogemos su indice
    double val{aux->get_data().get_val()}; // cogemos el coeficiente
    if (val > 0) // si es positivo ponemos +, sino -
      os << (!first ? " + " : "") << val;  // si es el primero no pongas +, pon espacio
    else
      os << (!first ? " - " : "-") << fabs(val); //  ponemos un - y el valor absoluto
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");  // luego el x elevado ( que si es 1, no pongas nada wacho)
    if (inx > 1) // y si es mayor que 1 ( no mames, pasa siempre)
      os << inx; // pon el indice
    first = false;  // acabamos el primer bucle, osea, ya no hay first 
    aux = aux->get_next(); // hacemos que aux apunte al nodo siguiente
  }
  os << " ]" << std::endl; // cerramos corchete
}

// esto es la sobrecarga del operador << para el cout
std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const { // se le pase como parametro la x, y calcula el polinomio con x
  double result{0.0}; // creamos el resultado iniciado a 0
  SllPolyNode* aux{get_head()}; // creamos un puntero aux que apunte a el primer nodo

  while (aux != NULL) { //mientras exista
    result += aux->get_data().get_val() * pow(x, aux->get_data().get_inx()); // vamos a sumar a result el valor calculado con x elevado a exponente correspndiente del par
    aux = aux->get_next(); // hacemso que aux apunte a el siguiente nodo
  }
  return result;
}


// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const { // necesita otro polinomio y epsilon
  bool differents = false; // creamos un bool que nos diga si son diferentes
  SllPolyNode* aux{get_head()}; // creamos un aux que apunte al el primer nodo
  SllPolyNode* aux2{sllpol.get_head()}; // creamos un aux secundario que apunta a el primer ndoo del polinomio secundario
  while (aux != NULL || aux2 != NULL) { // mientras los dos existan
    if (aux == NULL && aux2 != NULL || aux != NULL && aux2 == NULL){ // si no existe pero el otro no :
      return false;  // Son diferentes
    }
    if (aux->get_data().get_val() - aux2->get_data().get_val() >= eps){ // si  el value de cada uno es igual
      differents = true;  // si son iguales
    } 
    aux = aux->get_next(); //avanzamos cada aux y hacesmos que apunte al siguiente nodo
    aux2 = aux2->get_next();
  }
  return !differents; // devuelve diferentes al reves ajajja
}


// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
// No se como coño funcion pero funciona
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum,
                        const double eps) {
  SllPolynomial auxSllPolSum;
  SllPolyNode* aux = get_head();
  SllPolyNode* aux2 = sllpol.get_head();
  pair_double_t pair;
  double sum = 0.0;

  // si tienen los mismos exponentes se suman
  while (aux != NULL || aux2 != NULL) { // si alguno existe
    if (aux != NULL && aux2 != NULL) { // mientras los dos aux existan osea que apunten bien
      if (aux->get_data().get_inx() == aux2->get_data().get_inx()) { // y si los indices son igualitos
        sum = aux->get_data().get_val() + aux2->get_data().get_val(); // metemos en la suma los dos valores
        if (IsNotZero(sum, eps)) {  // si la suma no es 0
          pair.set(sum, aux->get_data().get_inx());  // creamos el par que 
          auxSllPolSum.push_front(new SllPolyNode(pair)); // metemos en un polinomio ese nuevo nodo par
        }
        if (aux != NULL) aux = aux->get_next(); // que si aux no es nulo saltamos 
        if (aux2 != NULL) aux2 = aux2->get_next(); // si el otro no es nulo tmb slatamos 
      } else if (aux->get_data().get_inx() > aux2->get_data().get_inx()) { // y si resulta que es mayor
        sum = aux2->get_data().get_val(); // simplemente metemos al mayor
        if (IsNotZero(sum, eps)) { // si no es 0 la suma aun
          pair.set(sum, aux2->get_data().get_inx()); // entonces creamos un par para meterlo
          auxSllPolSum.push_front(new SllPolyNode(pair)); // y lo metemos con el vector resultado
        }
        if (aux2 != NULL) aux2 = aux2->get_next(); // no es nulo saltamos al siguiente
      } else {
        sum = aux->get_data().get_val(); 
        if (IsNotZero(sum, eps)) {
          pair.set(sum, aux->get_data().get_inx());
          auxSllPolSum.push_front(new SllPolyNode(pair));
        }

        if (aux != NULL) aux = aux->get_next();
      }

      // Si uno llego al final
    } else if (aux == NULL) {
      sum = aux2->get_data().get_val();
      if (IsNotZero(sum, eps)) {
        pair.set(sum, aux2->get_data().get_inx());
        auxSllPolSum.push_front(new SllPolyNode(pair));
      }
      if (aux2 != NULL) aux2 = aux2->get_next();

    } else if (aux2 == NULL) {
      sum = aux->get_data().get_val();
      if (IsNotZero(sum, eps)) {
        pair.set(sum, aux2->get_data().get_inx());
        auxSllPolSum.push_front(new SllPolyNode(pair));
      }

      if (aux != NULL) aux = aux->get_next();
    }
  }

  while (!auxSllPolSum.empty()) {
    sllpolsum.push_front(auxSllPolSum.pop_front());
}
}

// MODIFICACIONES -----------------

// Escalar un polinomio las vceces que necesite
void SllPolynomial::Scalar(SllPolynomial& sllpscalar, const double scalar){  // pide un poninomio enlazado y un scalar
  SllPolyNode* aux{get_head()};  // hacemos que el puntero apunte al primer nodo
  while (aux != NULL){  // mientras exista ese nodo
    //va a cambiarlo por el valor multiplicado por el scalar
    sllpscalar.push_front(new SllPolyNode(pair_double_t(aux->get_data().get_val() *  scalar, aux->get_data().get_inx())));
    aux = aux->get_next(); // cambiamos de nodo
  }
}

// Pedir un polinomio y devolver el polunomio sin el primer ni el ultimo elemento
SllPolynomial removeFirstAndLastNodes(const SllPolynomial& polynomial) {
    SllPolynomial result; // creamos un objeto SllPolynomial vacío para almacenar el resultado

    // obtenemos el segundo nodo (el primero es head_)
    sll_node_t<pair_double_t>* current = polynomial.get_head()->get_next();

    // recorremos la lista hasta el penúltimo nodo
    while (current->get_next() != NULL) { //mientras no sea el ultimo, (si detecta que es el ultimo para)
        result.push_front(new sll_node_t<pair_double_t>(current->get_data())); // añadimos el nodo actual a la nueva lista
        current = current->get_next(); // avanzamos al siguiente nodo
    }

    return result;
}

//sumar los coeficientos de los monomios con grados contiguos
void SllPolynomial::SumarCoeficientesContinuos(SllPolynomial& aux){
//recorremos el Polinomio
  SllPolyNode* aux1{aux.get_head()}; // puntero al primer nodo de sllp1
  SllPolyNode* aux2{aux1->get_next()}; // puntero al primer nodo de sllp2

  while (aux1 != NULL && aux2 != NULL){  // mientras exista ese nodo
  if (aux1->get_data().get_inx() +1 == aux2->get_data().get_inx()){ // si los indices continuos es igual al +1
  //entonces los sumamos y hacemos un cout
     double sum = aux1->get_data().get_val() + aux2->get_data().get_val();
     std::cout << " La suma de los indices continuos: "<< aux1->get_data().get_inx() << " y " << aux2->get_data().get_inx() <<" es = " << sum << std::endl;
  }
  aux1 = aux1->get_next(); // cambiamos de nodo
  aux2 = aux1->get_next();
  }
}

//sumas los coeficienes de los monomios con grados iguales
void SllPolynomial::SumarCoeficientesIguales(SllPolynomial& aux){
//recorremos el Polinomio
  SllPolyNode* aux1{aux.get_head()}; // puntero al primer nodo de sllp1
  SllPolyNode* aux2{aux1->get_next()}; // puntero al primer nodo de sllp2

  while (aux1 != NULL && aux2 != NULL){  // mientras exista ese nodo
  if (aux1->get_data().get_inx() +1 == aux2->get_data().get_inx()){ // si los indices continuos es igual al +1
  //entonces los sumamos y hacemos un cout
     double sum = aux1->get_data().get_val() + aux2->get_data().get_val();
     std::cout << " La suma de los indices continuos: "<< aux1->get_data().get_inx() << " y " << aux2->get_data().get_inx() <<" es = " << sum << std::endl;
  }
  aux1 = aux1->get_next(); // cambiamos de nodo
  aux2 = aux1->get_next();
  }
}

//retornar el polinomio pasado como pararmetro pero con los gradoss pares borrados
void SllPolynomial::EliminarImpares() {
  if (get_head()->get_data().get_inx() % 2 != 0){ // si la cabecera es impar
    pop_front(); // la borramos
  }
  SllPolyNode* aux{get_head()}; // creamos un puntero que apunte a el primero
  while (aux ->get_next() != NULL){  // mientras ese puntero acierte
    if( aux -> get_next() -> get_data().get_inx() % 2 != 0){ // y si el grado del siguiente que acierta es impar
      erase_after(aux); // borra el anterior al siguiente, osea , ese
    }
  if (aux->get_next() != NULL) { // esto creo que no pasaria nunca por que hay un null xd
    aux = aux->get_next(); //hacemos que apunte al siguiente de aux para recorrer el polinomio
  }
  }
}



// crear un nuevo polinomio que solo tenga los grados pares
SllPolynomial EliminarlosImpares(const SllPolynomial& polynomial) {
    SllPolynomial result; // creamos un objeto SllPolynomial vacío para almacenar el resultado

    // obtenemos el segundo nodo (el primero es head_)
    sll_node_t<pair_double_t>* aux = polynomial.get_head();

    // recorremos la lista hasta el penúltimo nodo
    while (aux != NULL) { //mientras no sea el ultimo, (si detecta que es el ultimo para)
        if( aux->get_data().get_inx() % 2 == 0){ // Es decir, que si no es 0, es PAR,
        // y si es par, entonces añadira ese nodo
        result.push_front(new sll_node_t<pair_double_t>(aux->get_data())); // añadimos el nodo actual a la nueva lista ( creamos un par que se añade)
        }
        if (aux != NULL) { // esto creo que no pasaria nunca por que hay un null xd
          aux = aux->get_next(); //hacemos que apunte al siguiente de aux para recorrer el polinomio
        }
    } 
    // asi susecivamente se va a generar un nuevo olinomio resultado que lo que haga sea

    return result; // retorna un polinomio pero solo de pares
}


#endif  // SLLPOLYNOMIAL_H_
