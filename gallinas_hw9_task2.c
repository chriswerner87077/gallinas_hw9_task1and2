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

/* Function Prototypes */
void ReadFile( char *fName, int data[]);
void OrganizeData( int data[], int xval[], int yval[]);
/* Main Program */
int main(int argc, char *argv[])
{
	int totaldata[8];
	int x[4]; // altitude
	int y[4]; // ozone mix ratio
	ReadFile("zone1.txt", totaldata);
	OrganizeData(totaldata, x, y);


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
	for( i = 0; i < 4; i++)
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


