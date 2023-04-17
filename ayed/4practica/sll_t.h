// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
// las listas enlazadas es lineal de nodos enlazados en secuencia
//cada nodo almacena un tipo T
template <class T> class sll_t {
 public: //metodos
  // constructor
  sll_t(void) : head_(NULL) {} //inicializa el primer nodo a NULL ( osea esta vacia )

  // destructor
  ~sll_t(void); 

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);


  sll_node_t<T>* search(const T&) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private: //atributos*/
  sll_node_t<T>* head_;
};


// destructor
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) { // esto se repite hasta que head sea null
    sll_node_t<T>* aux = head_; //creamos un puntero auxiliar con valor head_ (primer nodo)
    head_ = head_->get_next(); // hacemos que el primer nodo valga el siguiente
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL; // si head es null , nuestra lista esta vacia
}

// operaciones

template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) { // se le pasa como parametro el nodo que deseamos añadir
  assert(n != NULL); //primero comprobamos que no sea null por si acaso

  n->set_next(head_);  // hacemos que apunte a la primera posicion
  head_ = n; // y añadimos n en la primera posicion
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { //borra el primer nodo y devuelve su puntero
  assert(!empty()); // no vaya a ser que esté vacio
  sll_node_t<T>* aux = head_; // cogemos un aux que apunte a head
  head_ = head_->get_next(); // hacemos que apunte a el siguiente nodo
  aux->set_next(NULL); // establecemos el puntero en null por defecto

  return aux; // devolvemos el puntero
}

//inserta el nodo que quieras despues del que quieras
template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev,
					       sll_node_t<T>* n) {  //prev es el nodo anterior al que deseas insertar y n el que quieres meter
  assert(prev != NULL && n != NULL); // miramos que no sea nulo

  n->set_next(prev->get_next()); //hacemos que el next de prev sea n con punteros
  prev->set_next(n); // efectivamente lo colovamos
}

//borra el nodo siguiente
template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) {  // solicita prev
  assert(!empty()); // que no este vacio la lista
  assert(prev != NULL); // que prev no sea nulo y exista
  sll_node_t<T>* aux = prev->get_next(); //creamos un aux que apunte al nodo que perderemos
  
  assert(aux != NULL); // miramos que aux no sea null
  prev->set_next(aux->get_next()); // Hacemos que el puntero del siguiente de prev se salte aux ( osea se lo salta)
  aux->set_next(NULL); // ahora seteamos el next a prev en null ( osea eliminalo completamente)

  return aux; //retorna el puntero al nodo que hemos eliminado ( Esto es por si necesitas borrar ese espacio de memoria )
}

//Sirve para buscar un nodo específico y devuelve su puntero
template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const { // pide el nodo deseado
  sll_node_t<T>* aux = head_; //creamos un puntero aux que apunta a el primer nodo de todos
  while ((aux != NULL) && (aux->get_data() != d))  // si aux no es nulo y no coincide con el nodo deseado
    aux = aux->get_next(); // nodo ++
    
  return aux; // va a devolver el aux con el puntero correspondiente cuando el bucle se corte
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_; // creamos un aux que apunte al primer nodo

  while (aux != NULL) { // mientras exista
    aux->write(os); // se imprime
    aux = aux->get_next(); // y aux ++
  }
  return os;
}



#endif  // SLLT_H_
