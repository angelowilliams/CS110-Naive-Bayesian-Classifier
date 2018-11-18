#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void getDataFromFile(FILE *infile, float setosaData[][4], float versicolorData[][4], float virginicaData[][4]);
//Standard deviation function, num should be 149
float calculateSD(float data[], int num);

float mean(float data[], int num);

#endif