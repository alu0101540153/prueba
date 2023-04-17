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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo google: 3 líneas de separación entre métodos

// pauta de estilo google: tipo retornado en línea anterior al método
inline
int
rational_t::get_num() const
{
  return num_;
}



inline
int
rational_t::get_den() const //para el denominador
{
  return den_;
}


  
void
rational_t::set_num(const int n) //numerador
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



inline
double
rational_t::value() const //calcula el valor real
{ 
  return double(get_num()) / get_den();
}



rational_t 
rational_t::opposite() const
{ 
  return rational_t((-1)*get_num(), get_den());
}



rational_t
rational_t::reciprocal() const
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return (value() - r.value()) > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.is_greater(*this, precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r) const
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}



rational_t
rational_t::substract(const rational_t& r) const
{
  return add(r.opposite());
}



rational_t
rational_t::multiply(const rational_t& r) const
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}



rational_t
rational_t::divide(const rational_t& r) const
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
//SOBRECARGA

rational_t
operator+(const rational_t& a, const rational_t& b)
{
    int num = a.get_num() * b.get_den() + b.get_num() * a.get_den();
    int den = a.get_den() * b.get_den();
    return rational_t(num, den);
}



rational_t
operator-(const rational_t& a, const rational_t& b)
{
    int num = a.get_num() * b.get_den() - b.get_num() * a.get_den();
    int den = a.get_den() * b.get_den();
    return rational_t(num, den);
}



rational_t
operator*(const rational_t& a, const rational_t& b)
{
    int num = a.get_num() * b.get_num();
    int den = a.get_den() * b.get_den();
    return rational_t(num, den);
}



rational_t
operator/(const rational_t& a, const rational_t& b)
{
  assert(b.get_num() != 0); //No puede ser 0
  int num = a.get_num() * b.get_den();
  int den = a.get_den() * b.get_num();
  return rational_t(num, den);
}



// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}


//Esta es la sobrecarga del operador de entrada
ostream& 
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);  
  return os;
}

//Esta es la sobrecfarga del operador de salida
istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}