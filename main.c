#include <stdio.h>
#include <stdlib.h>

double interpolacion(double puntos[4][2], int cantPuntos, double x);
double productoria(double puntos[4][2], int cantPuntos, double x, int index);

int main(int numArgs, char** args){
   double puntos[4][2] = {{0.0,5.0}, {5.0,33.0}, {8.0,42.0}, {9.0,97.0}};
   double x = 6.0;
   double resultado = interpolacion(puntos, 4, x);
   printf("El resultado es: %lf\n", resultado);
   return 0;
}

double interpolacion(double puntos[4][2], int cantPuntos, double x){
   double resultado = 0;
   for(int i = 0; i < cantPuntos; i++){
      resultado += productoria(puntos, cantPuntos, x, i) * puntos[i][1];
   }
   return resultado;
}

double productoria(double puntos[4][2], int cantPuntos, double x, int index){
   double resultado = 1;
   for (int i = 0; i < cantPuntos; i++) {
      if(i != index)
         resultado *= (x - puntos[i][0])/(puntos[index][0] - puntos[i][0]);
   }
   return resultado;
}
