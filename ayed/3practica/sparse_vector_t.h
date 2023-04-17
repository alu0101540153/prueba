// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

// pauta de estilo google: comentarios multilínea usando solo "/**/"
#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6 //se define el rango para epsilon 

typedef pair_t<double> pair_double_t; //hacemos unos pares dobles
typedef vector_t<pair_double_t> pair_vector_t; //hacemos un vector de pares dobles

//Esta es la clase para los vectores dispersos
//los vectores dispersos son mas pijitos y no les gusta guardar 0, por lo que guardan una 
// un número y lo relacionan con una posicion que sería aquivalente a la posicion que tendria en un denso

class sparse_vector_t { //es clase hija de  vector
 public: //metodos
  // constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&,
		  const double = EPS); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  // operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);

  //Modificacioón -----------------


  double QueValorEs(const int n) const;




  sparse_vector_t par_impar();
  sparse_vector_t ElementosPares();
  double SumaCoeficientes() const ;
  void MonomiosConsecutivos ( const sparse_vector_t& spol);
  sparse_vector_t MayorMenor();
  int SumaInx() const ;
  // destructor
  ~sparse_vector_t();
  
  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  
  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // E/S
  void write(std::ostream& = std::cout) const;

 private: //atributos
  pair_vector_t pv_;  // valores + índices , los guada juntitos por que es un pair
  int nz_;            // nº de valores distintos de cero = tamaño del vector ( numbers not zero) luego de quitar los valores 0
  int n_;             // tamaño del vector original (numbers)

  // bool IsNotZero(const double, const double = EPS) const;
};

//funcion que comprueba si el valor no es 0, con una precision definida como epsilon
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps; // si esto ocurre debuelve true, osea que es mayor q 0
}

//Este es el constructor para la clase sparse, pero no me crea el polinomio
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II

//este es el constructor que me va a hacer el polinomio disperso correctamente con los pares
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps)
    : pv_(), nz_(0), n_(0) {
  // poner el código aquí
  n_ = v.get_size(); //n va a ser el tamaño de nuestro vector                                                                                   
  for (int i = 0; i < n_; i++){ //recorremos el vector                                                                      
    if (IsNotZero(v[i], eps)){  //si resulta que no son 0, va a aumentar el NotZeros                                                                          
      nz_++;
    }
  }
  pv_.resize(nz_); //el nuevo vector discperso tiene que medir los mismo que sin zeros
  for (int i = 0, j = 0; i < n_; i++){  //recorremos el vector original
    if (IsNotZero(v[i], eps)){ //si resulta que no es 0
      pair_t<double> temp(v.at(i),i); //Declaramos temp de clase pair que haga pares con el valor y la posicion que ocupa en realidad
      pv_.set_val(j,temp); //lo guardamos en el vector de tamaño nz_ en todas las posiciones
      j++; //siguiente posicion
    }
  }
}


// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación (sobrecarga de =)
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz(); //simplemente igualamos cada uno de los atributos con su correspondiente
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this; //deuelve una referencia al comparado
}

//destructor
sparse_vector_t::~sparse_vector_t() {}

//getters
inline int sparse_vector_t::get_nz() const {
  return nz_;
}

inline int sparse_vector_t::get_n() const {
  return n_;
}

//esto sirve para colocarse en la posicion que quieras del vector
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz()); // comprueba que esta dentro de nuestro vector
  return pv_[i];  //devuelve su posicion
}

//sobrecarga del operador [] para que el at. sea mas comodo
pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

//honestamente no sse por que lo hace again pero creo que es para hacerlo constante
const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

//tambien hace constante la sobrecarga, ya que no va a cambiar la posicion y es constante
const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

// E/S
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

//con la sobrecarga de << es mas facil hacer un write
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}



////////////////////////////////////////////////
//               MODFICACION_                //
////////////////////////////////////////////////  y posibles modificaciones

//Mostrar pon pantalla el valor del indice indicado
double sparse_vector_t::QueValorEs(const int x) const {

  for (int i = 0; i<get_nz() ; i++){ //recorremos el vector
    if (at(i).get_inx() == x){ // si el indice es igual al dado
      return at(i).get_val(); //debuelve su valor (val)
    }
  }
  return 0; //si no es ninguno, es 0 entonces
}






//---------------------------------------
//suma los valores de las posiciones de indices pares del vectorsparse, y lo pone en un vector, y las impares en otra posicion

sparse_vector_t sparse_vector_t::par_impar(){
  vector_t<double> sp_v(2); // crea un sparse vector de dos elementos a 0 
  for (int i = 0; i < get_nz(); ++i){ //recorremos el vector
    if (at(i).get_inx() % 2 == 0){ //si resulta que el indice de la posicion es PAR
      sp_v.at(0) += at(i).get_val();  //sumamos a el primer elemento su valor
    } else {              //si no, quiere decir que es impar
      sp_v.at(1) += at(i).get_val();  //sumamos a el segundo elemento el valor
    }
  }
  sparse_vector_t vec_fin(sp_v); //lo guardamos en un sparse vector
  return vec_fin; //y lo retornamos
}

//sacar los valores de los elementos con grado par
sparse_vector_t sparse_vector_t::ElementosPares(){
  vector_t<double> sp_v(get_nz() / 2);
  int j = 0;
  for (int i = 0; i < get_nz(); ++i){
    if (at(i).get_inx() % 2 == 0){
      sp_v.at(j) += at(i).get_val(); 
      j++;
    } 
  }
  sparse_vector_t vec_fin(sp_v);
  return vec_fin;
}

//sumar los coeficioentes de un sparse polinomial

double sparse_vector_t::SumaCoeficientes() const {
  double suma{0.0}; // inicializamos la variable suma en cero
  for (int i = 0; i < get_nz(); ++i){ // recorremos el vector sparse
    suma += at(i).get_val(); // sumamos el valor de cada elemento a la variable suma
  }
  return suma; // retornamos el valor de la suma
}

//imprimir el monomio de mayor y menor grado de un sparse polinomial
sparse_vector_t sparse_vector_t::MayorMenor(){
  vector_t<double> sp_v(2); // crea un sparse vector de dos elementos a 0 
  int j = 0;
  for (int i = 0; i < get_nz(); i+= get_nz()- 1){ //recorremos el vector
      sp_v.at(j) += at(i).get_val();  // guardamos en la posicion 0, el primero y en 1 el ultimo
      j++;
  }
  sparse_vector_t vec_fin(sp_v); //lo guardamos en un sparse vector
  return vec_fin; //y lo retornamos
}

//Sumar el valor de los exponentes de un sparse polinomial

int sparse_vector_t::SumaInx() const {
  int suma{0}; // inicializamos la variable suma en cero 
  for (int i = 0; i < get_nz(); ++i){ // recorremos el vector sparse
    suma += at(i).get_inx(); // sumamos el valor de cada indices del elemento
  }
  return suma; // retornamos el valor de la suma
}

//imprimir solo los monomios de indices consecutivos

void MonomiosConsecutivos ( const sparse_vector_t& spol) { //se le pasa por parametro el polinomio a analizar
  for (int i = 0; i < spol.get_nz() -1; i++ ) { //recorremos el polinomio
    if( (spol.at(i+1).get_inx() - spol.at(i).get_inx()) == 1){  //si el indice de la funcion sigiente menos el anterior es 1 ( osea es consecutivo )
    // diremos el par de polinomios con indice consecutivo con el cour
      std::cout << spol.at(i).get_val() << "x^" << spol.at(i).get_inx() << " y " << spol.at(i +1).get_val() << "x^" << spol.at(i+1).get_inx() << std::endl; 
    }
  }

}

#endif  // SPARSE_VECTORT_H_