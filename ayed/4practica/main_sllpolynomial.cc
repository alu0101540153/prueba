// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_sllpolynomial.cc -o main_sllpolynomial
// EJECUCIÓN: ./main_sllpolynomial < data_sllpolynomial.txt

#include <iostream>

#include "sllpolynomial.h"

using namespace std;

int main() {
  vector_t<double> v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  cout << "v1= " << v1;
  cout << "v2= " << v2;
  cout << "v3= " << v3;
  cout << endl;
 
  // Fase II
  SllPolynomial sllp1(v1), sllp2(v2), sllp3(v3);
  cout << "sllp1= " << sllp1;
  cout << "sllp2= " << sllp2;
  cout << "sllp3= " << sllp3;
  cout << endl;

  // Fase III
  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  cout << "sllp1(" << x1 << ")= " << sllp1.Eval(x1) << endl;
  cout << "sllp1(" << x2 << ")= " << sllp1.Eval(x2) << endl;
  cout << "sllp1(" << x3 << ")= " << sllp1.Eval(x3) << endl;
  cout << "sllp2(" << x1 << ")= " << sllp2.Eval(x1) << endl;
  cout << "sllp2(" << x2 << ")= " << sllp2.Eval(x2) << endl;
  cout << "sllp2(" << x3 << ")= " << sllp2.Eval(x3) << endl;
  cout << "sllp3(" << x1 << ")= " << sllp3.Eval(x1) << endl;
  cout << "sllp3(" << x2 << ")= " << sllp3.Eval(x2) << endl;
  cout << "sllp3(" << x3 << ")= " << sllp3.Eval(x3) << endl;
  cout << endl;

  cout << "sllp1 == sllp1? " << (sllp1.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp2? " << (sllp2.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp3? " << (sllp3.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp1 == sllp2? " << (sllp1.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp1? " << (sllp2.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp1 == sllp3? " << (sllp1.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp1? " << (sllp3.IsEqual(sllp1) ? "true" : "false")
       << endl;
  cout << "sllp2 == sllp3? " << (sllp2.IsEqual(sllp3) ? "true" : "false")
       << endl;
  cout << "sllp3 == sllp2? " << (sllp3.IsEqual(sllp2) ? "true" : "false")
       << endl;
  cout << endl;

  // Fase IV
  SllPolynomial sllpsum12, sllpsum23;
  sllp1.Sum(sllp2, sllpsum12);
  cout << "sllp1 + sllp2= " << sllpsum12;
  sllp2.Sum(sllp3, sllpsum23);
  cout << "sllp2 + sllp3= " << sllpsum23;

  //MODIFICIACION
  cout << endl;
  cout << "------------Posibles Modificaciones-------------" << endl;
  cout << " producto escalar : ";
  SllPolynomial sllpscalar; // creamos el polinomio que se va a modificar
  double scalar = 5; // el escalar por el que se va a multiplicar
  sllp1.Scalar(sllpscalar, scalar); // esta funcion , aunq es viod modifica directamente a sllpscalar
  cout << "Scalar(5) * P1(x) = " << sllpscalar;

  cout << " Eliminar primero y el ultimo : ";

    // Obtenemos el polinomio sin el primer y último nodo
    SllPolynomial mod = removeFirstAndLastNodes(sllp1);

    // Imprimimos el polinomio resultante
    std::cout << "Polinomio sin el primer y último nodo: ";
    mod.Write(std::cout);


     sllp1.SumarCoeficientesContinuos(sllp1);


     // eliminar los grados pares del polinomio
     sllp1.EliminarImpares();

      // imprimir el polinomio con los grados pares eliminados
     std::cout << " Polinomio sin grados pares: ";
     sllp1.Write(std::cout);

     SllPolynomial sllpmod; // creamos el polinomio que se va a modificar

    cout << "\n\n ---------------------Crear un polinomio solo con los pares : " << endl;

    // Obtenemos el polinomio sin el primer y último nodo
    SllPolynomial mod1 = EliminarlosImpares(sllp1);  // los hago con sllp1 y 3
     SllPolynomial mod2 = EliminarlosImpares(sllp3);
    // Imprimimos el polinomio resultante
    std::cout << "Polinomio Sllp1 solo con los pares es: ";
    mod1.Write(std::cout);
    std::cout << "Polinomio Sllp3 solo con los pares es: ";
    mod2.Write(std::cout);



  return 0;
}
