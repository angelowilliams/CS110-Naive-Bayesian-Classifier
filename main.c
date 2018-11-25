#include "functions.h"

const _Bool DEBUG_MODE = 1;

// Author: Oliver Hamburger, Tom Kang, Angelo Williams
int main(){
	FILE *infile;
	infile = fopen("Data.txt", "r");
	
	int setosaCount = 0;
	int versicolorCount = 0;
	int virginicaCount = 0;
	int totalCount = 0;
	
	float temp;
	char name[50];
	while (!feof(infile)) {
		fscanf(infile, "%f", &temp);
		fscanf(infile, "%f", &temp);
		fscanf(infile, "%f", &temp);
		fscanf(infile, "%f", &temp);
		fscanf(infile, "%s", name);

		if (strcmp(name, "Irissetosa") == 0) {
			++setosaCount;
		}
		else if (strcmp(name, "Irisversicolor") == 0) {
			++versicolorCount;
		}
		else if (strcmp(name, "Irisvirginica") == 0) {
			++virginicaCount;
		}
		else {
			printf("Unknown category found: %s\nTerminating...", name);
			exit(0);
		}

		++totalCount;
	}
	
	float setosaData[setosaCount][4];
	float versicolorData[versicolorCount][4];
	float virginicaData[virginicaCount][4];
	
	getDataFromFile(infile, setosaData, versicolorData, virginicaData);

	if (DEBUG_MODE) {
		for (int i = 0; i < 50; ++i) {
			printf("%f %f %f %f %s\n", setosaData[i][0], setosaData[i][1], setosaData[i][2], setosaData[i][3], "Irissesota");
		}
		for (int i = 0; i < 50; ++i) {
			printf("%f %f %f %f %s\n", versicolorData[i][0], versicolorData[i][1], versicolorData[i][2], versicolorData[i][3], "Irisversicolor");
		}
		for (int i = 0; i < 50; ++i) {
			printf("%f %f %f %f %s\n", virginicaData[i][0], virginicaData[i][1], virginicaData[i][2], virginicaData[i][3], "Irisvirginica");
		}

		int index = 0;
		//for all the ptox values, loop through index 0-49
		printf("%f\n", PtoX(setosaData, setosaCount, index, 0));
		printf("%f\n", PtoX(setosaData, setosaCount, index, 1));
		printf("%f\n", PtoX(setosaData, setosaCount, index, 2));
		printf("%f\n", PtoX(setosaData, setosaCount, index, 3));
	}

	/*
	use p(xi|y) equation for the following
	
		x1Setosa[50];  p(x1|a)
		x2Setosa[50];  p(x2|a)
		x3Setosa[50];  p(x3|a)
		x4Setosa[50];  p(x4|a)
	
		x1Versicolor[50];  p(x1|b)
		x2Versicolor[50];  p(x2|b)
		x3Versicolor[50];  p(x3|b)
		x4Versicolor[50];  p(x3|b)
	
		x1Virginica[50];  p(x1|c)
		x2Virginica[50];  p(x2|c)
		x3Virginica[50];  p(x3|c)
		x4Virginica[50];  p(x4|c)
	*/
	
	/*
	p(x|a) = p(x1|a)p(x2|a)p(x3|a)p(x4|a)
	p(x|b) = p(x1|b)p(x2|b)p(x3|b)p(x4|b)
	p(x|c) = p(x1|c)p(x2|c)p(x3|c)p(x4|c) 
	*/
	
	return 0;
}
	
