// AUTOR: Víctor Rodrígues Dorta
// FECHA: 9 marzo
// EMAIL: alu0101540153
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Google Style Guidelines"
//        google

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

//Sintaxis de la plantilla
template<class T> //Declaracion para el inicio de la plantilla parametrizada , toma un parametro como entrada

class matrix_t 
{
public: //metodos
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);
  
  // getters
  // Métodos para acceder a los atributos
  int get_m(void) const; // M filas
  int get_n(void) const; // N columnas
  
  // getters-setters
  T& at(const int, const int); //verifica que los índices estén dentro de los límites válidos
  T& operator()(const int, const int); //permite acceder a los elementos de la matriz por la notación de paréntesis
  
  // getters constantes
  const T& at(const int, const int) const; //Sobrecarga de ()
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  //Modificacion-----------------------------------------
  vector_t<T> SumaFilasPares() const;
  vector_t<T> SumaColumnas() const;

//Métodos para la lectura por teclado
  void write(ostream& = cout) const;
  void read(istream& = cin);

private: //atributos
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const; //Conocer la posicion (metodo privado)
};




//Este es el Constructor de la clase matrix
template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


//Este es el destrucctor de la clase matrix, por que tiene ~
template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0); //verifica que m y n son mayores que 0
  m_ = m; //actualiza los antiguos valores por los nuevos que le has pasado
  n_ = n;
  v_.resize(m_ * n_); //construye el nuevo vector interno
}



template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_; //devuelve el numero de filas
}



template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_; // devuelve el numero de columnas*
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m()); //Se comprueba que los elementos son validos, osea que esten dentro de la matriz
  assert(j > 0 && j <= get_n()); 
  return v_[pos(i, j)]; //Devuelve la posicion del vector en el que esta
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j); //permite modificar elementos de la matriz a través de paréntesis
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m()); //son validos?
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)]; //Devuelve el valor de la posicion i,j
}



template<class T> //sobrecarga de ()
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j); //devuelve una referencia constante a la posicion i,j
}



template<class T>
void
matrix_t<T>::write(ostream& os) const //Esto imprime por pantalla el vector 
{ 
  os << get_m() << "x" << get_n() << endl; //primero dice el tamaño (3 x 3)
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j) //luego instancia cada valor y forma una matriz
      os << at(i, j) << "\t";
    os << endl; //fin de la fila, hace endl
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is) //leer la matriz 
{
  is >> m_ >> n_; // primero pedimos los valores del tamaño m,n
  resize(m_, n_); //Seteamos el valor a nuestra matriz
  for (int i = 1; i <= get_m(); ++i) //pedimos todos los valores de las posiciones correspondientes
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const //las matrices se almacenan en un vector unidimencional v_
{
  assert(i > 0 && i <= get_m()); //compueva que esta dentro de la matriz
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1); // Devuelve la posicion de memoria donde se encuentra esa posicion i,j
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
    assert(A.get_n() == B.get_m()); // Verificar que se pueda realizar la multiplicación de matrices
    
    int m = A.get_m(); // Número de filas de la matriz resultante
    int n = B.get_n(); // Número de columnas de la matriz resultante
    int p = A.get_n(); // Número de columnas de A (número de filas de B)
    
    resize(m, n); // Redimensionar la matriz resultante
    
    for (int i = 1; i <= m; i++) { //recorer la fila
        for (int j = 1; j <= n; j++) { //recorrer la columna
            at(i, j) = 0; //fijamos el valor a 0
            for (int k = 1; k <= p; k++) {
                at(i, j) = at(i, j) + A.at(i, k) * B.at(k, j); //hcaemos las operaciones en multoplicaion de matrices
            }
        }
    }


    
  
 
}
//Modificacion  -------------------------------

//almacenar en un vector la suma del las columnas de una matriz

template<class T>
vector_t<T>
matrix_t<T>::SumaColumnas() const {
  vector_t<T> resultado; //almacenamos el resultado en un vector
  resultado.resize(get_n()); //el vector medira lo mismo que la cantidad de columnas de matriz
  int k = 0;
  for(int i =1; i<= get_n(); i++){ //nos movemos por n
    for (int j=1; j<= get_m(); j++){ //nos movemos por m
      resultado.at(k) =  resultado.at(k) + at(j,i); //guardamos en la posicion del resultado en la posicion K, que sera la suma de todas las posiciones de columna
      }
      k++; // Cambiamos la posicion donde nos encontrames en resultado
  }
  
  return resultado;
}