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

using namespace std;

template<class T> //T se usa para poder sustituirlo por int, double, flotat... dependiendo de lo que quieras el vector
class vector_t
{
public:
  vector_t(const int = 0);
  ~vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

  //Modificacion-----------------------------------------------
  //Sumar los elementos de un vector 2 a 2
  void sumar_los_elementos_de_un_vector_2_a_2(const vector_t<double>& v);
  void PocicionesPares(const vector_t<double>& v);
  T Sumtres() const;

private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


//Constructor (llama a build)
template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}


//Destructor (llama a destroy)
template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}


//Para el constructor
template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL); //si no puede, error
  }
}


//pa el destructor
template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) { //si el valor no es nulo, lo borra todo
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;  //Crea el vector con el tamaño n que necesites
  build();
}



template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size()); //cpmprueba que esta dentro del vector
  return v_[i]; //dice el valor de esa posicion del vector
}



template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_; //Devuelve el tamaño del vector
}



template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size()); //comprueba que existe la pisicion i
  v_[i] = d; //cambiamos el valor de esa posicion por D
}


//Esto se usa para sobrecargar [] y poder decir v.at(i), en vez de v[i]
template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size()); //Está dentro del rango?
  return v_[i]; 
}



template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i); //devuelve la referencia al elemento en la posicion i
}



template<class T>
const T&
vector_t<T>::at(const int i) const   //de esta forma podemos hacer un A.at(1,2)
{
  assert(i >= 0 && i < get_size());
  return v_[i]; //Es una forma mas segura de sacar el valor i
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const   //de esta forma es mas comodo y podemso hacer un A[1,2], mas intuitivo
{
  return at(i); //devuelve una referencia constante al elemento i
}



template<class T>
void
vector_t<T>::write(ostream& os) const //Escribe por pantalla el vector por ejemplo 1,2,3 escribe "3: 1 2 3".
{ 
  os << get_size() << ":\t"; //   \t se usa para un tabulador
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_; // pedimos tamaño del vector
  resize(sz_);
  for (int i = 0; i < sz_; ++i) //luego pedimos los valores del interior del vector
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
    assert(v.get_size() == w.get_size()); //el tamaño tiene que ser igual siempre, si no error
    T result = 0; //creamos un result que sera Template
    for (size_t i = 0; i < v.get_size(); i++) { //Multiplicamos cada posicion i y se suman porque (3,2) x (4,6) = (3x4 * 2x6)
        result = result + v[i] * w[i];
    }
    return result;
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  assert(v.get_size() == w.get_size()); // Verificar que los vectores tengan el mismo tamaño
  double result = 0.0;
  for (int i = 0; i < v.get_size(); ++i) {
    result =  result + v[i].value() * w[i].value();
  }
  return result;
}


//Modificacion------------------------------------
//Sumar los elementos de un vector 2 a 2

void sumar_los_elementos_de_un_vector_2_a_2(const vector_t<int>& v) {
  assert (v.get_size() % 2 == 0); //comprobamos que el vector es par
  std::cout << "(";
  for (int i = 0; i < (v.get_size()-1); i++){ //recorremos el vector
    int resultado3 = v[i] + v[i+1]; //sumamos con la posicion siguiente
    std::cout << resultado3 << ", ";  //imprime el resultado de cada suma
  }
  std::cout << ")" << std::endl;
  //En verdad retorna el mismo vector sin modificacion
}

//Mostrar las posiciones pares de un vector

void PocicionesPares(const vector_t<int>& v) {
  std::cout << "(";
  for (int i = 0; i < (v.get_size()); i++){ //recorremos el vector
    if(i % 2 == 0){
  int resultado3 = v[i]; //sumamos con la posicion siguiente
    std::cout << resultado3 << ", ";  //imprime el resultado de cada suma
    }
  }
  std::cout << ")" << std::endl; //En verdad retorna el mismo vector sin modificacion
}

//SUma los elementos en posicicones divisibles entre 3
template<class T>
T vector_t<T>::Sumtres() const {
  T resultado = 0;
  for (int i = 0; i < (this->get_size()); i++){ //recorremos el vector
    if(i % 3 == 0){
      resultado = resultado + this->at(i);
    }
  }
  return resultado;
}

