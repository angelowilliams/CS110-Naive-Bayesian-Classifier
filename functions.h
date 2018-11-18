#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
	Function under construction
*/
float calculateSD(float data[], int num);

/*
Function under construction
*/
float mean(float data[], int num);

#endif