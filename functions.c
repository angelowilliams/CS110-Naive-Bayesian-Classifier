#include "functions.h"

float PtoX(float data[], int length, int indexOfdataP) {
	float end, first, second;
	float dataMean = mean(data, length, indexOfdataP);
	float SD = calculateSD(data, length, indexOfdataP);
	float SDsquared = ldexp(SD, 2);
	float top = ldexp((data[indexOfdataP] - dataMean), 2);

	first = 1 / (sqrt(2 * M_PI*(SDsquared)));
	second = exp(-top / (2 * SDsquared));
	end = first * second;

	return end;
}

float calculateSD(float data[], int num, int dataPoint) {
	float sumData = 0.0, mean, standardDeviation = 0.0;

	int i;

	sumData = sum(data, num) - data[dataPoint];
	num -= 1;
	mean = sumData / num;

	for (i = 0; i<num; ++i) {
		standardDeviation += pow(data[i] - mean, 2);
	}

	return sqrt(standardDeviation / num);

}

float mean(float data[], int num, int dataPoint) {
	float sumData, mean;

	sumData = sum(data, num) - data[dataPoint];
	num -= 1;
	mean = sumData / num;

	return mean;
}

float sum(float data[], int num) {
	int i; int sum;
	for (i = 0; i<num; ++i)
	{
		sum += data[i];
	}


	return sum;
}

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