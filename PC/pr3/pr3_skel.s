#Author: Víctor Rodríguez Dorta
#Correo: alu0101540153@ull.edu.es

# Esqueleto PR3

#--------------------------CODE C++---------------------------
# ESTE PROGRAMA AUN NO CUMPLE CON LO QUE VA A PEDIR EL TESTER ( LUEGO LO MODIFICO )

# int main(void) {

#   int mat[] = { //Recuerda que es un vector
#     100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
#     120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
#     140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
#     160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
#     180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
#     200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
#     220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
#     240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259,
#     260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
#     280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299,
#     300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
#     320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339,
#     340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359,
#     360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
#     380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
#     400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
#     420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439,
#     440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459,
#     460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479,
#     480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499,
#   };

#   const int maximoElementos = 400; // Esto es constante
#   int nfil = 20;
#   int ncol = 10;

#   // se imprimie el título
#   std::cout << "\nPráctica PR3 de Principios de Computadores. Matrices.\n";

#   std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
#   for (int f = 0; f < nfil; f++)
#   {
#       for (int c = 0; c < ncol; c++)
#       {
#           std::cout << mat[f * ncol + c] << "  "; // equivalente a acceso `mat[f][c]`
#       }
#       std::cout << "\n"; // cuando acaba la fila hace un endl
#   }
#   std::cout << "\n";

#   // MENU DE INICIO
#   for (;;)
#   { // bucle infinito hasta que break
#       cout << " Elige una de las opciones disponibles: \n " << endl;
#       cout << " (1) Cambiar dimensiones" << endl;
#       cout << " (2) Intercambiar dos elementos" << endl;
#       cout << " (3) Suma elementos del perímetro" << endl;
#       cout << " (4) Calcula máximo y mínimo de la diagonal principal" << endl;
#       cout << " (0) Salir \n"
#            << endl;
#       cout << " ---> ";

#       int opcion = 0;
#       cin >> opcion;

#       if (opcion == 0)
#           break;
#       if (opcion == 1)
#       {
#           // Cambiar las dimenciones que quiera
#           const int maximoElementos = 400; // Esto es constante
#           std::cout << "Introduzca la dimencion de la matriz que desea: ";

#           std::cin >> nfil;
#        if (nfil <= 0) {

#          std::cout << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
#          break;
#        }
#        std::cout << "Introduzca número de columnas: ";
#        std::cin >> ncol;

#        if (ncol <= 0) {
#          std::cout << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
#         break;
#        }
        
#        if ( ncol * nfil > 400) {
#          std::cout << "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
#           break;
#        }

#           std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
#           for (int f = 0; f < nfil; f++)
#           {
#               for (int c = 0; c < ncol; c++)
#               {
#                   std::cout << mat[f * ncol + c] << "  "; // equivalente a acceso `mat[f][c]`
#               }
#               std::cout << "\n"; // cuando acaba la fila hace un endl
#           }
#       }

#       if (opcion == 2)
#       {
#           // cambiar las posiciones indicadas (Tenemos en cuenta que  elegiremos una posicion dentro de la matriz elegida)
#           cout << "introduce la posicion del elemento que desa mover:";
#           int afil; // filas
#           std::cin >> afil;
#           int acol; // columnas
#           std::cin >> acol;

#           cout << "introduce la posicion a donde deseas moverlo:";
#           int bfil; // filas
#           std::cin >> bfil;
#           int bcol; // columnas
#           std::cin >> bcol;

#           int aux = mat[afil * ncol + acol];
#           mat[afil * ncol + acol] = mat[bfil * ncol + bcol];
#           mat[bfil * ncol + bcol] = aux;

#           std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
#           for (int f = 0; f < nfil; f++)
#           {
#               for (int c = 0; c < ncol; c++)
#               {
#                   std::cout << mat[f * ncol + c] << "  "; // equivalente a acceso `mat[f][c]`
#               }
#               std::cout << "\n"; // cuando acaba la fila hace un endl
#           }
#       }

#       if (opcion == 3)
#       {
#           // sumar los elementos del perimetro
#           cout << "Esta es la suma de sus horizontales: ";
#           int sumatotal = 0;
#           int sumahorizontales = 0;
#           int sumalaterales = 0;

#           int f = 0; // fila primera
#           for (int c = 0; c < ncol; c++)
#           {
#               // cout << mat[f*ncol+c] << endl;
#               sumahorizontales += mat[f * ncol + c];
#           }
#           f = nfil - 1; // fila ultima
#           for (int c = 0; c < ncol; c++)
#           {
#               // cout << mat[f*ncol+c] << endl;
#               sumahorizontales += mat[f * ncol + c];
#           }

#           cout << sumahorizontales << endl;

#           // ya tenemos sumadas las horizontales
#           // suma de los lados sin tener en cuenta las esquinas
#           int c = 0; // columna primera
#           for (int f = 1; f < nfil - 1; f++)
#           {
#               // cout << mat[f*ncol+c] << endl;
#               sumalaterales += mat[f * ncol + c];
#           }

#           c = ncol; // columna ultima
#           for (int f = 1; f < ncol - 1; f++)
#           {
#               // cout << mat[f*ncol+c] << endl;
#               sumalaterales += mat[f * ncol + c];
#           }

#           cout << "Este es la suma de los laterales sin las esquinas:  " << sumalaterales << endl;
#           cout << "La suma total del perimetro es: " << sumalaterales + sumahorizontales << endl;
#           std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
#           for (int f = 0; f < nfil; f++)
#           {
#               for (int c = 0; c < ncol; c++)
#               {
#                   std::cout << mat[f * ncol + c] << "  "; // equivalente a acceso `mat[f][c]`
#               }
#               std::cout << "\n"; // cuando acaba la fila hace un endl
#           }
#       }

#       if (opcion == 4)
#       {
#           int maximo = mat[0];
#           int minimo = mat[0];
#           for (int f = 1; f < nfil; ++f)
#           {
#               if (maximo < mat[f * ncol + f])
#               {
#                   maximo = mat[f * ncol + f];
#               }
#               if (minimo > mat[f * ncol + f])
#               {
#                   minimo = mat[f * ncol + f];
#               }
#           }
#           std::cout << "\nEl máximo de la diagonal principal es " << maximo << " y el mínimo " << minimo;
#       }
#   }
#   return 0;
# }


# ----------------------------------ENSAMBLADOR---------------------------------

maximoElementos=400 # numero de enteros maximo reservado para la matriz 1600 bytes
size=4 # bytes que ocupa un entero
    .data
mat:   .word   100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119
       .word   120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139
       .word   140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159
       .word   160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179
       .word   180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199
       .word   200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219
       .word   220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239
       .word   240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259
       .word   260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279
       .word   280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299
       .word   300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319
       .word   320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339
       .word   340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359
       .word   360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379
       .word   380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399
       .word   400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419
       .word   420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439
       .word   440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459
       .word   460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479
       .word   480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499
       

nfil:   .word   20 # nuemro de filas de la matriz
ncol:   .word   10 # numero de columnas de la matriz

titulo:     .asciiz "\nPráctica PR3 de Principios de Computadores. Manejo de Matrices.\n"
msg_matriz: .asciiz "\nLa matriz es "
msg_x:      .asciiz "x"
separador:  .asciiz "  " # separador entre numeros
newline:    .asciiz "\n"
menu:       .ascii  "\n(1) Cambiar dimensiones\n(2) Intercambiar dos elemento\n"
            .ascii  "(3) Suma elementos del perimetro\n(4) Calcula max y min de la diagonal\n"
            .asciiz "(0) Salir\n\nElija opcion: "

error_op:   .asciiz "\nError: opcion incorrecta.\n"
msg_nfilas: .asciiz "Introduzca numero de filas: "
msg_ncols:  .asciiz "Introduzca numero de columnas: "
error_nfilas:   .asciiz "\nError: dimension incorrecta. Numero de fila incorrecto.\n"
error_ncols:    .asciiz "\nError: dimension incorrecta. Numero de columna incorrecto.\n"
error_dime:     .asciiz "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n"
msg_i:      .asciiz "Introduzca fila del primer elemento a cambiar: "
msg_j:      .asciiz "Introduzca columna del primer elemento a cambiar: "
msg_r:      .asciiz "Introduzca fila del segundo elemento a cambiar: "
msg_s:      .asciiz "Introduzca columna del segundo elemento a cambiar: "
msg_suma:   .asciiz "\n\nSuma de los elementos del perímetro: "
msg_max:    .asciiz "\nEl máximo de la diagonal principal es "
msg_min:    .asciiz " y el mínimo "
msg_fin:    .asciiz "\nFin del programa.\n"


    .text

#--------------------------------------- #
# Tabla Variables usadas en registros:   #
#--------------------------------------- #
# nfil:          $s0                     #
# ncol:          $s1                     #
# f:             $s2                     #
# c:             $s3                     #
# opcion:        $s4                     #
# mat ( matriz): $s5                     #
# afil:          $t2                     #
# acol:          $t3                     #
# bfil:          $t4                     #
# bcol:          $t5                     #
# suma_perimetro:$t7                     #
# sumalaterales: $t8                     #
#--------------------------------------- #
# (otros registros no son necesarios comentarlos Ej. auxiliares)


main:
#  std::cout << "\nPráctica PR3 de Principios de Computadores. Manejo de Matrices.\n";
	li $v0, 4
	la $a0, titulo
	syscall
#  int mat[...] = {
	# Cargamos la dirección de inicio de la matriz
	la $s5, mat

#  int nfil = 20;
	li $s0, 20
#  int ncol = 10;
	li $s1, 10

opciones:

#FUNCION IMPRIME MATRIZ --------
#    std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
	li $v0, 4
	la $a0, msg_matriz
	syscall
	li $v0, 1
	move $a0, $s0 # nfil
	syscall
	li $v0, 4
	la $a0, msg_x
	syscall
	li $v0, 1
	move $a0, $s1 # ncol
	syscall
	li $v0, 4
	la $a0, newline #\n
	syscall

#   for (int f = 0; f < nfil; f++) {
	li $s2, 0 #int f
WRITE_forF:
	bge $s2, $s0, MENU
#       for (int c = 0; c < ncol; c++){
	li $s3, 0 #int c
WRITE_forC:
	bge $s3, $s1, WRITE_fin_forC
#           std::cout << mat[f * ncol + c] << "  "; // equivalente a acceso `mat[f][c]`
	mul $t0, $s2, $s1  #f * ncol
	add $t0, $s3, $t0  #f * ncol + c
	mul $t0, $t0, size #SiZE = 4 (bits por entero)
	add $t0, $t0, $s5  #mat[f * ncol + c]
	lw $t0, 0($t0)     #Se carga el valor del elemento de la matriz en la dirección almacenada

	li $v0, 1  # cout
	move $a0, $t0
	syscall

	li $v0, 4  # espacio
	la $a0, separador
	syscall

	addi $s3, 1 #c++

	b WRITE_forC
WRITE_fin_forC:
#      std::cout << "\n";
	li $v0, 4
	la $a0, newline
	syscall

	addi $s2, 1	#f++

	b   WRITE_forF

MENU:
#    int opcion{0};
	li $s4, 0
#    std::cout << "\n(1) Cambiar dimensiones\n(2) Intercambiar dos elemento\n" <<
#    "(3) Suma elementos del perimetro\n(4) Calcula max y min de la diagonal\n" <<
#    "(0) Salir\n\nElija opcion: ";
	li $v0, 4
	la $a0, menu
	syscall

#    std::cin >> opcion;
	li $v0, 5
	syscall
	move $s4, $v0






#OPCION 1 ------------------------------------------------------

#    if (opcion == 1) {
opcion1:
	li $t0, 1 #cargamos en t0 1
	bne $s4, $t0, opcion2
#           // Cambiar las dimenciones que quiera

#        std::cout << "Introduzca número de filas: ";
	li $v0, 4
	la $a0, msg_nfilas
	syscall
#        std::cin >> nfil;
	li $v0, 5
	syscall
	move $s0, $v0
#        if (nfil <= 0) {

	bgt $s0, $zero, fila_correcta
#          std::cout << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
	li $v0, 4
	la $a0, error_nfilas
	syscall
#          break;
	b fin;

fila_correcta:
#        std::cout << "Introduzca número de columnas: ";
	li $v0, 4
	la $a0, msg_ncols
	syscall
#        std::cin >> ncol;
	li $v0, 5
	syscall
	move $s1, $v0
#        if (ncol <= 0) {

	bgt $s1, $zero, columna_correcta
#          std::cout << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
	li $v0, 4
	la $a0, error_ncols
	syscall
#         break;
	b	fin;
columna_correcta:
#        if ( ncol * nfil > 400) {
	mul $t2, $s0, $s1
	ble $t2, maximoElementos, opciones

#          std::cout << "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
	li $v0, 4
	la $a0, error_dime
	syscall






#OPCION 2  ---------------------------------------------------
opcion2: 
# if (opcion == 2) {
	li $t0, 2
	bne $s4, $t0, opcion3
#           // cambiar las posiciones indicadas (Tenemos en cuenta que  elegiremos una posicion dentro de la matriz elegida)
#      std::cout << "Introduzca fila del primer elemento a cambiar: ";
	li $v0, 4
	la $a0, msg_i
	syscall
#           int afil; // filas
#           std::cin >> afil;
	li $v0, 5
	syscall
	move $t2, $v0

#	Es correcta?
	blt $t2, $zero, error_afil
	bgt $t2, $s0, error_afil
	b afil_correcta

error_afil:
#            std::cout << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
	li $v0, 4
	la $a0, error_nfilas
	syscall
#            break;
	b fin

afil_correcta:
#      std::cout << "Introduzca columna del primer elemento a cambiar: ";
	li $v0, 4
	la $a0, msg_j
	syscall
#      std::cin >> columna_cambio1;
	li $v0, 5
	syscall
	move $t3, $v0
#	Escorrecta?
	blt $t3, $zero, error_acol
	bgt $t3, $s1, error_acol
	b acol_correcta

error_acol:
#            std::cout << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
	li $v0, 4
	la $a0, error_ncols
	syscall
#            break;
	b fin

acol_correcta:
#      std::cout << "Introduzca fila del segundo elemento a cambiar: "; 
	li $v0, 4
	la $a0, msg_r
	syscall
#      std::cin >> fila_cambio2;
	li $v0, 5
	syscall
	move $t4, $v0
#          if (fila_cambio2 <= 0 || fila_cambio2 > nfil) {
	blt $t4, $zero, error_bfil
	bgt $t4, $s0, error_bfil
	b bfil_correcta

error_bfil:
	#            std::cout << "\nError: dimension incorrecta. Numero de fila incorrecto.\n";
	li $v0, 4
	la $a0, error_nfilas
	syscall
#            break;
	b fin
bfil_correcta:
#      std::cout << "Introduzca columna del segundo elemento a cambiar: ";
	li $v0, 4
	la $a0, msg_s
	syscall
#      std::cin >> columna_cambio2;
	li $v0, 5
	syscall
	move $t5, $v0
#          if (columna_cambio2 <= 0 || columna_cambio2 > ncol) {
	blt $t5, $zero, error_bcol
	bgt $t5, $s1, error_bcol
	b bcol_correcto

error_bcol:
	#            std::cout << "\nError: dimension incorrecta. Numero de columna incorrecto.\n";
	li $v0, 4
	la $a0, error_ncols
	syscall
#            break;
	b fin

bcol_correcto:
#           int aux = mat[afil * ncol + acol];
	mul $t0, $t2, $s1
	add $t0, $t0, $t3
	mul $t0, $t0, size
	add $t0, $t0, $s5
	lw $s6, 0($t0)
#           mat[afil * ncol + acol] = mat[bfil * ncol + bcol];
	mul $t1, $t4, $s1
	add $t1, $t1, $t5
	mul $t1, $t1, size
	add $t1, $t1, $s5
	lw $t8, 0($t1)
	sw $t8, 0($t0)
#           mat[bfil * ncol + bcol] = aux;
	sw $s6, 0($t1)

b opciones








#OPCION 3  --------------------------------------------
opcion3:  #bugs con las sumas
#           // sumar los elementos del perimetro
#    if (opcion == 3) {
	li $t0, 3
	bne $s4, $t0, opcion4
#      int sumatotal = 0;
	li $t6, 0


#           int sumahorizontales = 0;
	li $t7, 0 
#           int sumalaterales = 0;
	li $t8, 0

	li $s2, 0 #int f
#      for (int f = 0; f < nfil; f++) {
for_horizontales:
#           int f = 0; // fila primera
	bge $s2, $s0, for_laterales
#           for (int c = 0; c < ncol; c++)
	li $s3, 0 #int c
for_recorrer_linea_sup:
	bge $s3, $s0, for_recorrer_linea_sup_fin
#               sumahorizontales += mat[f * ncol + c];
	mul $t0, $s2, $s1
	add $t0, $t0, $s3
	mul $t0, $t0, size
	add $t0, $t0, $s5
	lw $t0, 0($t0)
	add $t7, $t7, $t0
	addi $s3, 1
	b	for_recorrer_linea_sup
#           f = nfil - 1; // fila ultima
for_recorrer_linea_sup_fin:
	move $t0, $s0
	sub $t0, $t0, 1 #resta 1 a t0
	move $s2, $t0

#           for (int c = 0; c < ncol; c++)
for_recorrer_linea_inf:
	bge $s3, $s0, for_recorrer_linea_inf_fin
#               sumahorizontales += mat[f * ncol + c];
	mul $t0, $s2, $s1
	add $t0, $t0, $s3
	mul $t0, $t0, size
	add $t0, $t0, $s5
	lw $t0, 0($t0)
	add $t7, $t7, $t0
	addi $s3, 1
	b	for_recorrer_linea_inf

for_recorrer_linea_inf_fin:
	li $s3, 0 #c
	li $s2, 1 #f
for_laterales:
#           // ya tenemos sumadas las horizontales
#           // suma de los lados sin tener en cuenta las esquinas
#           int c = 0; // columna primera

#           for (int f = 1; f < nfil - 1; f++)
for_recorrer_columna1:
	sub $t0, $s0, 1
	bge $s2, $t0, for_recorrer_columna1_fin
#               sumahorizontales += mat[f * ncol + c];
	mul $t0, $s2, $s1
	add $t0, $t0, $s3
	mul $t0, $t0, size
	add $t0, $t0, $s5
	lw $t0, 0($t0)
	add $t7, $t7, $t0
	addi $s2, 1
	b	for_recorrer_columna1

for_recorrer_columna1_fin:

#           c = ncol; // columna ultima
	move $s3, $s1
	sub $t0, $s0, 1
#           for (int f = 1; f < ncol - 1; f++)
for_recorrer_columna2:

	bge $s2, $t0, for_recorrer_columna2_fin
#               sumahorizontales += mat[f * ncol + c];
	mul $t0, $s2, $s1
	add $t0, $t0, $s3
	mul $t0, $t0, size
	add $t0, $t0, $s5
	lw $t0, 0($t0)
	add $t7, $t7, $t0
	addi $s2, 1
	b	for_recorrer_columna2

for_recorrer_columna2_fin:
	#      std::cout << "\n\nSuma de los elementos del perímetro: " << suma_horizontales;
	li $v0, 4
	la $a0, msg_suma
	syscall
	li $v0, 1
	move $a0, $t7
	syscall
	b	opciones







#OPCION 4  ----------------------------------------------
opcion4:

	li $t0, 4
	bne $s4, $t0, opcion0 #salta pq no es esta opcion
#      int maximo = matriz[0];
	add $t0, $zero, $s5
	lw $t8, 0($t0)
#      int minimo = matriz[0];
	lw $t9, 0($t0)
#      numero_auxiliar = nfil; 
#		esto es para hacer un swap
	move $s7, $s0
#      if (nfil > ncol) { 
mayor:
	ble $s0, $s1, fin_mayor
#	 numero_auxiliar = ncol;
	move $s7, $s1 #swap
fin_mayor:
#      for (int f = 1; f < numero_auxiliar; ++f) {
	li $s2, 1
diagonal:
	bge $s2, $s7, fin_diagonal
#        if (maximo < matriz[f*ncol + f]) {
es_maximo:
	mul $t0, $s1, $s2
	add $t0, $t0, $s2
	mul $t0, $t0, size
	add $t0, $t0, $s5
	lw $t1, 0($t0)
	bge $t8, $t1, es_minimo
#          maximo = matriz[f*ncol + f];
	move $t8, $t1

#        if (minimo > matriz[f*ncol + f]) {
es_minimo:
	ble $t9, $t1, fin_es_minimo
#          minimo = matriz[f*ncol + f];
	move $t9, $t1

fin_es_minimo:
	addi $s2, 1
	b diagonal
fin_diagonal:
#      std::cout << "\nEl máximo de la diagonal principal es " << maximo <<
#      " y el mínimo " << minimo;
	li $v0, 4
	la $a0, msg_max
	syscall
	li $v0, 1
	move $a0, $t8 #maximo
	syscall
	li $v0, 4
	la $a0, msg_min
	syscall
	li $v0, 1
	move $a0, $t9 #minimo
	syscall
	b	opciones





#OPCION 0 -------------------------------------------------
#    if (opcion == 0) {
opcion0:
	bne $s4, $zero, opcion_erronea #si no es 0, salta a opcion erronea y comprueba
#      break;
	b fin

#    if (opcion < 0 || opcion > 4) {
opcion_erronea: #tiene  que estar dentro del rango
	blt $s4, $zero, error
	li $t0, 4 #cargo en $t0 el 4 para comparar
	bgt $s4, $t0, error
	b MENU #si esta dentro del rango (esto nunca deberia ocurrir)
#      std::cout << "\nError: opcion incorrecta.\n";
error:
	li $v0, 4
	la $a0, error_op
	syscall
#    }
	b MENU


fin: #se acabo las opciones por un break -------------------------------------
#  std::cout << "\nFin del programa.\n";
	li $v0, 4
	la $a0, msg_fin
	syscall
#}
fin_main:
	li $v0, 10
	syscall
	