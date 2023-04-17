// AUTOR: Víctor Rodríguez Dorta
// FECHA: 16-02-23
// EMAIL: alu0101540153@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html


// pauta de estilo: comentarios multilínea usando solo "/* */"


#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6 //Es decir , solo admitimos fallos despues de 6 digitos pasado coma

using namespace std;


//iniciador de la clase
class rational_t
{
 // pautas de estilos: primero "public" y después "private"
public: //métodos
 rational_t(const int = 0, const int = 1); //constructor
 ~rational_t() {} //Destructor
  // pauta de estilo: indentación a 2 espacios
 // getters
 //Metodos para acceder a los atributos
 int get_num() const;
 int get_den() const;
  // setters
 //Metodos para lectora y escritura por pantalla.
 void set_num(const int);
 void set_den(const int);


 double value(void) const;
//

 // FASE II
bool is_equal(const rational_t&, const double precision = EPSILON) const;
bool is_greater(const rational_t&, const double precision = EPSILON) const;
bool is_less(const rational_t&, const double precision = EPSILON) const;
bool is_one(const double precision = EPSILON) const;


  // FASE III
rational_t add(const rational_t&);
rational_t substract(const rational_t&);
rational_t multiply(const rational_t&);
rational_t divide(const rational_t&);



void write(ostream& = cout) const;
void read(istream& = cin);
private: //atributos

// pauta de estilo: nombre de los atributos seguido de "_"
 int num_, den_;
};
