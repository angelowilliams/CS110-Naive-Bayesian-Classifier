#include "functions.h"

void getDataFromFile(FILE *infile, float setosaData[][4], float versicolorData[][4], float virginicaData[][4]) {
	rewind(infile);
	
	float x1;
	float x2;
	float x3;
	float x4;
	char name[50];

	int setosaCount = 0;
	int versicolorCount = 0;
	int virginicaCount = 0;

	int i = 0;
	while (!feof(infile)) {
		fscanf(infile, "%f", &x1);
		fscanf(infile, "%f", &x2);
		fscanf(infile, "%f", &x3);
		fscanf(infile, "%f", &x4);
		fscanf(infile, "%s", name);

		if (strcmp(name, "Irissetosa") == 0) {
			setosaData[setosaCount][0] = x1;
			setosaData[setosaCount][1] = x2;
			setosaData[setosaCount][2] = x3;
			setosaData[setosaCount][3] = x4;
			++setosaCount;
		}
		else if (strcmp(name, "Irisversicolor") == 0) {
			versicolorData[versicolorCount][0] = x1;
			versicolorData[versicolorCount][1] = x2;
			versicolorData[versicolorCount][2] = x3;
			versicolorData[versicolorCount][3] = x4;
			++versicolorCount;
		}
		else if (strcmp(name, "Irisvirginica") == 0) {
			virginicaData[virginicaCount][0] = x1;
			virginicaData[virginicaCount][1] = x2;
			virginicaData[virginicaCount][2] = x3;
			virginicaData[virginicaCount][3] = x4;
			++virginicaCount;
		}
		else {
			printf("Unknown category found: %s\nTerminating...", name);
			exit(0);
		}
		i++;
	}
}

float calculateSD(float data[], int num) {
	float sum = 0.0;
	float mean;
	float standardDeviation = 0.0;

	for (int i = 0; i < num; ++i) {
		sum += data[i];
	}

	mean = sum / num;

	for (int i = 0; i < num; ++i) {
		standardDeviation += pow(data[i] - mean, 2);
	}

	return sqrt(standardDeviation / num);
}

float mean(float data[], int num) {
	int i; 
	int sum;
	float mean;

	for (i = 0; i < num; ++i) {
		sum += data[i];
	}

	mean = sum / num;
	return mean;
}
