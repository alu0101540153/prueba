// AUTOR: Víctor Rodríguez Dorta
// FECHA: 16-02-23
// EMAIL: alu0101540153@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html


// pauta de estilo : comentarios multilínea usando preferiblemente "/*  */"


#include "rational_t.hpp"


//Este es el constructor para la clase rational_t
rational_t::rational_t(const int n, const int d)
{
 assert(d != 0);
 num_ = n, den_ = d;
}


// pauta de estilo : 1 linea de separación entre métodos


// pauta de estilo: tipo retornado en línea anterior al método
//Pedimos el valor para nuestro numerador
//metodo para acceder a los atributos (getter)
int
rational_t::get_num() const
{
 return num_;
}



//metodo para acceder a los atributos (getter)
int
rational_t::get_den() const
{
 return den_;
}



//Método para leer y escribir por pantalla (setter)
void
rational_t::set_num(const int n)
{
 num_ = n;
}



//Método para leer y escribir por pantalla (setter)
void
rational_t::set_den(const int d)
{
 assert(d != 0); // Esto es para prohibir que sea 0
 den_ = d;
}

//Esta funion calcula el valor real que resulta de dividir el numerador entre denominador en un número double
double
rational_t::value() const
{
 return double(get_num()) / get_den();
}

// comparaciones -----------------------------------------
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
    bool iguales;
    double resta{ fabs( this->value() /* x */- r.value() /* y */ )};
    if ( resta < precision ) {
        iguales = true;
    } else{
        iguales = false;
    }
 
    return iguales;
}

bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
    bool greater;
    double resta {r.value() /*x*/ - this->value() /*y*/ };
    if ( resta > precision ) {
        greater = true;
    } else{
        greater = false;
    }
    return greater;
}

bool
rational_t::is_less(const rational_t& r, const double precision) const
{
    bool less;
    double resta {r.value() /*x*/ - this->value() /*y*/  };
    if ( resta < precision * -1 ) {
        less = true;
    } else{
        less = false;
    }
    return less;
}


bool
rational_t::is_one(const double precision) const
{
    bool esmenor;
    double resta {this->value() /*x*/ - 1 }; //ES igual a is less pero la resta la ago con 1
    
    if ( resta >= precision ) {
        esmenor = true;
    } else{
        esmenor = false;
    }

    //Tenemos un problema cuando es 1, por culpa de la resta, asi que:
    if (this->get_den() == this->get_num()) {
        esmenor = true; //porque puede ser menor o IGUAL, este es el caso para igual.
    }
    return esmenor;
}


// operaciones -----------------------------------------
rational_t
rational_t::add(const rational_t& r)
{
    //Minimo común multiplo
    double mcm{ r.get_den() * this->get_den()};

    /*En una suma calculariamos el mcm y luego dividimos con el denominador de cada fraccion 
    Y luego lo multiplica por el numerador, finalmente hace la suma de resultados*/
    // No es necesario aquí por que solo son dos fracciones asi que basta con multiplicar y sumar
    double numtotal{ this->get_den() * r.get_num() + r.get_den() * this->get_num() };
    //construimos una clase compuesta por estos datos y la returnamos
    return rational_t(numtotal, mcm);

}

rational_t
rational_t::substract(const rational_t& r)
{
        //Minimo común multiplo
    double mcm{ r.get_den() * this->get_den()};

    /*En una suma calculariamos el mcm y luego dividimos con el denominador de cada fraccion 
    Y luego lo multiplica por el numerador, finalmente hace la suma de resultados*/
    // No es necesario aquí por que solo son dos fracciones asi que basta con multiplicar y restar
    double numtotal{ r.get_den() * this->get_num() - this->get_den() * r.get_num() };
    //construimos una clase compuesta por estos datos y la returnamos
    return rational_t(numtotal, mcm);
}

rational_t
rational_t::multiply(const rational_t& r)
{
    double numtotal{r.get_num() * this->get_num()}; //Simplemente multiplico cada cosa
    double dentotal{r.get_den() * this->get_den()};
    return rational_t(numtotal, dentotal);
}

rational_t
rational_t::divide(const rational_t& r)
{
    double numtotal_{r.get_num() * this->get_den()}; //En la division se hace en forma de cruz
    double dentotal_{r.get_den() * this->get_num()};
    return rational_t(numtotal_, dentotal_);
}




//Esta funcion representa por pantalla nuestro valor grafico a la division,
//Por ejemplo, muestra: 8/2=4
// E/S
void
rational_t::write(ostream& os) const
{
 os << get_num() << "/" << get_den() << "=" << value() << endl;
}




//En esta Funcion se le pide al usuario que inserte los valores.
void
rational_t::read(istream& is)
{
 cout << "Numerador? ";
 is >> num_; //se guarda en la variable numerador
 cout << "Denominador? ";
 is >> den_; //se guarda en la variable denominador
 assert(den_ != 0); //Confirmamos que no sea 0
}

//Is y Os son propias del iostream , es literalmente lo mismo q cin cout


