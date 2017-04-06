/*
 * =====================================================================================
 *
 *       Filename:  gallinas_hw9_task1.c
 *       	Usage:  ./gallinas_hw9_task1.c
 *    Description:  Homework 9 Task 1. 
 *
 *        Version:  1.0
 *        Created:  04/06/2017 02:53:56 AM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Chris Werner (), christopherwerner@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* For Standard Library*/
#include <string.h>		/* For String Library */

#define NUMELS 12
/* Function Prototypes */
void Usage(char** info);
void ReadFile(char *fName, float num[]);
FILE *OpenCheckFile(char *fName);
void WriteFile(FILE *sFile, float num[]);

/* Main Program */
int main(int argc, char *argv[])
{
	// Declare variables
	float numbers[NUMELS];
	FILE *outFile;
	// Call usage function if there are not two strings or if --helpis
	// first string
	if (argc != 3 || (strcmp(*(argv+1),"--help") == 0))
	{
		Usage(argv);
	}
	// Call ReadFile funciton , passing the input file name and an array
	// to stor info
	ReadFile(*(argv+1),numbers);
	outFile = OpenCheckFile(*(argv+2));
	WriteFile(outFile, numbers);

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	// display how to use program
	printf("Usage");
	printf("%s <dataFile> <outFileName>\n", *info);
	exit(1);
	return;
}
void ReadFile(char *fName, float num[])
{
	// Declare variables
	FILE *inFile;
	int i=0;
	// Open file stream (filename corresponds to argv[1])
	inFile = fopen(fName,"r");
	if (inFile == NULL)
	{
		printf("The file, %s, could not be succesffully opened\n", fName);
		printf("Please check spelling or if the file exists\n");
		exit(1);
	}
	printf("The file has been successfully opened for reading\n");
	while ((fscanf(inFile,"%f",&num[i++])) != EOF)
		;
	return;
}
FILE *OpenCheckFile(char *fName)
{
	// Declare variables
	FILE *outFile1;
	char ans;
	// open file stream (filename will be argv[2]) 
	if ((outFile1 = fopen(fName,"r")) != NULL)
	{
		printf("The file, %s, already exists.\n", fName);
		printf("Do you want to overwrite it (y/n)?");
		scanf("%c", &ans);
		if (ans == 'n')
		{
			exit(1);
		}
	}
	outFile1 = fopen(fName,"w");
	if (outFile1 == NULL)
	{
		printf("Failed to open file %s\n", fName);
	}
	else
	{
		printf("The file %s has successfully been written.\n", fName);
	}
	return outFile1;
}
void WriteFile(FILE *sFile, float num[])
{
	// Declare/Initialize variables
	float sumnum = 0, avenum =0;
	// print each member of the array into the outFile
	for (int i = 0; i < NUMELS; i++)
	{
		fprintf(sFile,"%6.4f\n", num[i]);
		// Calculate the sum of all values
		sumnum += num[i];
	}
	// Calculate the average of the values
	avenum = sumnum/NUMELS;
	fprintf(sFile, "---------\n");
	fprintf(sFile, "Total: %6.4f\n", sumnum);
	fprintf(sFile, "Avg: %6.4f\n", avenum);

	return;
}


