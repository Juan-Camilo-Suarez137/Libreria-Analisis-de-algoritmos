#include <jni.h>
#include <stdlib.h>
#include "libcalculadora_CalculadoraAnalisis.h"
/*
 * Class:     libcalculadora_CalculadoraAnalisis
 * Method:    interpolacion
 * Signature: ([[DD)D
 */
double productoria(double** puntos, int cantPuntos, double x, int index);

JNIEXPORT jdouble JNICALL Java_libcalculadora_CalculadoraAnalisis_interpolacion
  (JNIEnv * env, jobject obj, jobjectArray puntos, jdouble x){
    int cantPuntos = (*env)->GetArrayLength(env, puntos);
    double** cpuntos = malloc(cantPuntos * sizeof(double*));
    for(int i = 0; i < cantPuntos; i++){
        jdoubleArray darr = (jdoubleArray)(*env)->GetObjectArrayElement(env, puntos, i);
        cpuntos[i] = (*env)->GetDoubleArrayElements(env, darr, 0);
    }
    double resultado = 0;
    for(int i = 0; i < cantPuntos; i++){
       resultado += productoria(cpuntos, cantPuntos, x, i) * cpuntos[i][1];
    }
    return resultado;
}

double productoria(double** puntos, int cantPuntos, double x, int index){
   double resultado = 1;
   for (int i = 0; i < cantPuntos; i++) {
      if(i != index)
         resultado *= (x - puntos[i][0])/(puntos[index][0] - puntos[i][0]);
   }
   return resultado;
}
