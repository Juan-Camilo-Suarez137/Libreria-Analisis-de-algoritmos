#include <jni.h>
#include "libcalculadora_CalculadoraAnalisis.h"
/*
 * Class:     libcalculadora_CalculadoraAnalisis
 * Method:    interpolacion
 * Signature: ([[DD)D
 */
JNIEXPORT jdouble JNICALL Java_libcalculadora_CalculadoraAnalisis_interpolacion
  (JNIEnv * env, jobject obj, jobjectArray puntos, jdouble x);

