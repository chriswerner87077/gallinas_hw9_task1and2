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
void ReadFile( char *fName, float table[][]);

/* Main Program */
int main(int argc, char *argv[])
{
	FILE *inFile; // file pointer
	int alt[4]; // altitude (X COL)
	int ozone[5]; // oz mix ratio (Y COL)
	//int data[4][2]; // 2D Array in file.tct

	inFile = fopen("zone1.txt", "r"); // read

	if(inFile == NULL)
	{
		printf("The file was not successfully opened.\n");
		printf("Please include the zone1.txt in your current folder.\n");

		exit(1); // replase this with usage
	}
	printf("The file was successfully opened.\n");
	
	return 0;
}


/* Function Defenitions */
void ReadFile( char *fName, float table[][])
{

	return;
}


