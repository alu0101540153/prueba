// AUTOR: Víctor Rodrígues Dorta
// FECHA: 9 marzo
// EMAIL: alu0101540153
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Google Style Guidelines"
//        google

// pauta de estilo google: comentarios multilínea usando solo "/**/"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilo google: primero "public" y después "private"
public: //metodos
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // pauta de estilo google: indentación a 2 espacios
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  //REferencias sobrecargas
  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  //comparaciones
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

 //operadores
  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;

  //entrada -salida
  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private: //atributyos
  // pauta de estilo google: nombre de los atributos seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

