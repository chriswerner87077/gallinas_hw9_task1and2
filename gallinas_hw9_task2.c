/*
 * =====================================================================================
 *
 *       Filename:  gallinas_hw9_task2.c
 *       	Usage:  ./gallinas_hw9_task2.c
 *    Description:  ozone problem
 *
 *        Version:  1.0
 *        Created:  04/06/2017 11:03:04 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Orlando Salas (), orlandosalas@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>

#define N 5
#define DATA 8
/* Function Prototypes */
void ReadFile( char *fName, int data[]);
void OrganizeData( int data[], int xval[], int yval[]);
void RangeofX( int xval[]);
void MathSlope( int xval[], int yval[]);
void MathYInt( int xval[], int yval[]);

/* Main Program */
int main(int argc, char *argv[])
{
	int totaldata[DATA];
	int x[N-1]; // altitude
	int y[N-1]; // ozone mix ratio
	ReadFile("zone1.txt", totaldata);
	OrganizeData(totaldata, x, y);
	RangeofX(x);
	printf("Linear Model:\n");
	MathSlope(x,y);
	MathYInt(x,y);
	
	return 0;
}


/* Function Defenitions */
void ReadFile( char *fName, int data[])
{
	FILE *inFile; // file pointer
	inFile = fopen(fName, "r"); // read
	int i = 0;

	if(inFile == NULL)
	{
		printf("The file was not successfully opened.\n");
		printf("Please include the zone1.txt in your current folder.\n");

		exit(1); // replase this with usage
	}
	printf("\nThe file was successfully opened.\n\n");

	while( (fscanf(inFile, "%d", &data[i++]) ) != EOF)
		;
	//for(i = 0; i < 8; i++)
	//{
	//	printf("data[%d] = %d\n", i, data[i]);
	//}
	
	return;
}

void OrganizeData( int data[], int xval[], int yval[])
{

	int i;
	for( i = 0; i < N - 1; i++)
	{
	xval[i] = *data;
	data++;
	yval[i] = *data;
	data++;
	//printf("xval[%d] = %d\n", i, xval[i]);
	//printf("yval[%d] = %d\n", i, yval[i]);
	}
	return;
}

void RangeofX( int xval[])
{
	int xmin = xval[0];
	int xmax = xval[0];

	for(int i = 1; i < N - 1 ; i++)
	{
		if( xmin > xval[i])
			{
				xmin = xval[i];
			}
		if( xmax < xval[i])
		{
				xmax = xval[i];

		}
	}
	printf("The range of altitude [in km] is: %d to %d\n", xmin, xmax);

	return;
}

void MathSlope( int xval[], int yval[])
{
	int n = N - 1;
	int SumX = 0, SumY = 0, SumXY = 0, SumX2 = 0;
	float slopen = 0.00, sloped = 0.00, slope = 0.00;
	for(int i = 0; i < N - 1; i++)
	{
		SumX += xval[i];
		SumY += yval[i];
		SumX2 += (xval[i])*(xval[i]);
		SumXY += (xval[i])*(yval[i]);
	}
	//printf("SumX = %d\n",SumX);
	//printf("SumY = %d\n",SumY);
	
	slopen = (( SumX * SumY) - ( n * SumXY) );
	sloped = (( SumX*SumX ) - n*SumX2);
	slope = slopen/sloped;
	printf("Ozone-Mix Ratio = %.2f\n",slope);
	
	return;
}

void MathYInt( int xval[], int yval[])
{
	int n = N - 1;
	int SumX = 0, SumY = 0, SumXY = 0, SumX2 = 0;
	float yIntn = 0.00, yIntd = 0.00, yInt = 0.00;

	for(int i = 0; i < N - 1; i++)
	{
		SumX += xval[i];
		SumY += yval[i];
		SumX2 += (xval[i])*(xval[i]);
		SumXY += (xval[i])*(yval[i]);
	}
	
	yIntn = ( (SumX*SumXY) - (SumX2 * SumY) );
	yIntd = ( (SumX*SumX) - (n*SumX2) );
	yInt = yIntn/yIntd;
	printf("Altitude Int.: %.2f\n",yInt);

	
	return;
}
