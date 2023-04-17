// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 
// pauta de estilo google: comentarios multilínea usando solo "/**/"

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
//los vectores densos son los que almacenan brutamente el vector , les da igual si almacenan 0
class Polynomial : public vector_t<double> { //es una clase hijo de vector
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ "; //abrimos
  bool first{true}; 
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) { //si la posicion no es 0 (pq no vamos a imprimir los que son 0)
      os << (!first ? " + " : "") << at(i) //porque al principio no tendria sentido poner un +
	 << (i > 1 ? " x^" : (i == 1) ? " x" : ""); //si el exp es 0 no imprime nada
      if (i > 1)
	os << i;
      first = false; //ya no hay mas primero
    }
  os << " ]" << std::endl; //cerramos 
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  for (int i = 0; i < get_size(); i++){ //recorremos el vector
    result += at(i) * pow(x,i); // y lo multiplicamos por X elevado a su respectivo numero
  }
  return result; // devuelve un numero doble con el resultado de la operaciuon
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false; //se crea una variablebool que nos dice si es , o no es igual
  // poner el código aquí
 for (int i = 0; i < get_size()-1; i++){  // El termino independiente no es necesario compararlo, pero en verdad podria hacerlo si quiero
    if (pol.at(i) - at(i) >= eps){ //si la resta es mayor que la presicion declarada
      differents = true; //son diferentes
    }
  }
  return !differents; //si son diferentes, no son iguales y viceversa
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=, para copiar todo el sparse
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const { //imprime por patalla
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true}; 
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

//sobrecarga del cout
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0}; //fijamos resultado
  // poner el código aquí
  for (int i = 0; i < get_nz(); i++){ //recorremos vector
    pair_t<double> sp_v = at(i); //optenemos la posicion i no nula (Contiene el getval y el getinx)
    result += sp_v.get_val() * pow(x,sp_v.get_inx()); // //sumamos al resultado la multiplicacion del Val por x elevado a indice
  }
  return result; //devuelve result
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false; //como antes declaramos diferent
  // poner el código aquí
  for (int i = 0; i < get_nz()-1; i++){ //recorremos el vector sin la ultima posicion, pero que da igual en verdad
    pair_t<double> sp_v = at(i), sp_v2 = spol.at(i); //v es this, v2 es el segundo es decir v.IsEqual(v2) En cada posicion
    if (sp_v.get_val() - sp_v2.get_val() > eps){ //si la resta de los valores es mayor que epsilon
      differents = true; //son diferentes
    } 
  }
  return !differents; //si son diferentes, no son iguales y viceversa
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  for (int i = 0, j = 0; i < get_nz()-1; i++, j++){ //recorremos los dos vectores
    pair_t<double> sp_v = at(i); //cojemos la posicion de i sparse (recuerda que tiene un val y un inx)
    while (pol.at(j) == 0) { //si la posicion en el polinomio normal (denso) es 0, saltamos la posicion pq esa no se tendria en cuanta
      j++; // se salta
    }
    if (sp_v.get_val() - pol.at(j) > eps){ //ahora se comparan como antes con 0, y si resulta que es mayor que epsilon ,
      differents = true; //son diferentes
    }
  }
  return !differents; //si son diferentes, no son iguales y viceversa
}




#endif  // POLYNOMIAL_H_