#include "HelperOperations.h"
#include <math.h>

//
//Função crossProduct
//Objetivo: calcula o produto vetorial
//
void crossProduct(float &x1, float &y1, float &z1, float x2, float y2, float z2)
{
	float x = x1, y = y1, z = z1;

	x1 = ((y * z2) - (z * y2));
	y1 = ((z * x2) - (x * z2));
	z1 = ((x * y2) - (y * x2));
}

//
//Função sizeVector
//Objetivo: calcula o tamanho (magnitude) do vetor
//
float sizeVector(float x, float y, float z)
{
	return (float)sqrt((x * x) + (y * y) + (z * z));
}

//
//Função normalizeVector
//Objetivo: torna o vetor unitário
//
void normalizeVector(float &x, float &y, float &z)
{
	//Calcula tamanho do vetor
	float size = sizeVector(x, y, z);

	//Normaliza vetor
	x /= size;
	y /= size;
	z /= size;
}
