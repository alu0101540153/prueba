// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

// pauta de estilo google: comentarios multilínea usando solo "/**/"

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public: //metodos
  // constructores
  pair_t(void); 
  pair_t(T, int);

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const;
  int get_inx(void) const;
  void set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 private: //atributos
  T val_; //valor en esa posicion
  int inx_; //indice que va relacionado con X
};

//constructor por defecto
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}
//constructor normal
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}
//destructor
template<class T> pair_t<T>::~pair_t() {}

//setter que actualiza los valores anteriores por unos nuevos
template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

//pide el tamaño del vector
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

//pide el valor de esa posicion
template<class T> T pair_t<T>::get_val() const {
  return val_;
}

// lee las variables
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

// escribe por pantalla las variables
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")"; //primero dice el inidce luego valor
}

//se puede hacer sobrecarga del operador de salida  << para que sea mas comodo
template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_