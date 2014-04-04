#ifndef __HELPEROPERATIONS_H__
#define __HELPEROPERATIONS_H__

//
//Fun��o crossProduct
//Objetivo: calcula o produto vetorial
//
void crossProduct(float &x1, float &y1, float &z1, float x2, float y2, float z2);

//
//Fun��o sizeVector
//Objetivo: calcula o tamanho (magnitude) do vetor
//
float sizeVector(float x, float y, float z);

//
//Fun��o normalizeVector
//Objetivo: torna o vetor unit�rio
//
void normalizeVector(float &x, float &y, float &z);


#endif