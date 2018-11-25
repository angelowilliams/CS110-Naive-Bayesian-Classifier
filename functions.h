// Author: Angelo Williams, Oliver Hamburger, Tom Kang

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

/* getDataFromFile()
* Parameters:
	FILE *infile: a pointer to the file containing the data set
	float setosaData[][4]: a multidimensional array that will contain the Setosa data
	float versicolorData[][4]: a multidimensional array that will contain the Versicolor data
	float virginicaData[][4]: a multidimensional array that will contain the Virginica data
* Return: void
*/
void getDataFromFile(FILE *infile, float setosaData[][4], float versicolorData[][4], float virginicaData[][4]);

/*
* Parameters:
	float data[]: the array of floats to find the standard deviation of
	int num: the amount of floats in data[]
* Return: float, the standard deviation of data[]
*/
float calculateSD(float data[], int num);

/*
* Parameters:
	float data[]: the array of floats to find the mean of
	int num: the amount of floats in data[]
* Return: float, the mean of data[]
*/
float mean(float data[], int num);

/*
* Parameters:
	float data[][4]: a multidimensional array containing the data for a class
	int sizeData: the amount of samples for the class being used
	int indexOfDataP: the index of the data point being tested
	int attributeIndex: the current attribute being tested
* Return: float, PtoX
*/
float PtoX(float data[][4], int sizeData, int indexOfDataP, int attributeIndex);

#endif