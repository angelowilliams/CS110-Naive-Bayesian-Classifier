#include "functions.h"

// Author: Tom Kang
float mean(float data[], int num) {
	float sumData, mean;

	for (int i = 0; i<num; ++i) {
		sumData += data[i];
	}

	mean = sumData / num;

	return mean;
}


// Author: Tom Kang, Oliver Hamburger
float calculateSD(float data[], int num) {
	float meanData, standardDeviation = 0.0;
	int i;

	meanData = mean(data, num);

	for (i = 0; i<num; ++i) {
		standardDeviation += pow(data[i] - meanData, 2);
	}

	return sqrt(standardDeviation / num);
}


// Author: Oliver Hamburger
float PtoX(float data[][4], int sizeData, int indexOfdataP, int attributeIndex) {
	// Create temp array to hold all values for a certain dataset and 
	//	 certain attribute except the value currently being tested
	int sizeTemp = sizeData - 1;
	float temp[sizeTemp];

	// Populate temp array
	int tempCounter = 0;
	for (int i = 0; i < sizeData; i++) {
		if (i != indexOfDataP) {
			temp[tempCounter] = data[i][attributeIndex];
			++tempCounter;
		}
	}

	float end, first, second;

	// Calculate mean and SD
	float dataMean = mean(temp, sizeTemp);
	float SD = calculateSD(temp, sizeTemp);

	// Calculate PofX
	float SDsquared = ldexp(SD, 2);
	float top = ldexp((data[indexOfDataP][attributeIndex] - dataMean), 2);

	first = 1 / (sqrt(2 * M_PI*(SDsquared)));
	second = exp(-top / (2 * SDsquared));
	end = first * second;

	return end;
}


// Author: Angelo Williams
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