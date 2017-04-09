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

#define RANGE 5
#define DATA 8
/* Function Prototypes */
void ReadFile( char *fName, int data[]);
void OrganizeData( int data[], int xval[], int yval[]);
void RangeofX( int xval[]);
/* Main Program */
int main(int argc, char *argv[])
{
	int totaldata[DATA];
	int x[RANGE]; // altitude
	int y[RANGE]; // ozone mix ratio
	ReadFile("zone1.txt", totaldata);
	OrganizeData(totaldata, x, y);
	RangeofX(x); 

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
	printf("The file was successfully opened.\n");

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
	for( i = 0; i < RANGE - 1; i++)
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

	for(int i = 1; i < RANGE - 1; i++)
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
	printf("The range of altitude is: %d to %d\n", xmin, xmax);

	return;
}

