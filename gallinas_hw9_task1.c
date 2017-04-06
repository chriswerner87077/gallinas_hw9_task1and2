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

/* Main Program */
int main(int argc, char *argv[])
{
	// Declare variables
	float numbers[NUMELS];
	FILE *outfile;
	// Call usage function if there are not two strings or if --helpis
	// first string
	if (argc != 3 || (strcmp(*(argv+1),"--help") == 0))
	{
		Usage(argv);
	}
	// Call ReadFile funciton , passing the input file name and an array
	// to stor info
	ReadFile(*(argv+1),numbers);
	outfile = OpenCheckFile(*(argv+2));
	if (outfile != NULL)
	{
		printf("success");
	}

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
	FILE *infile;
	int i=0;
	// Open file stream (filename corresponds to argv[1])
	infile = fopen(fName,"r");
	if (infile == NULL)
	{
		printf("The file, %s, could not be succesffully opened\n", fName);
		printf("Please check spelling or if the file exists\n");
		exit(1);
	}
	printf("The file has been successfully opened for reading\n");
	while ((fscanf(infile,"%f",&num[i++])) != EOF)
		;
	return;
}
FILE *OpenCheckFile(char *fName)
{
	// Declare variables
	FILE *outfile1;
	char ans;
	// open file stream (filename will be argv[2]) 
	if ((outfile1 = fopen(fName,"r"))== NULL)
	{
		printf("The file, %s, does not yet exist.\n", fName);
	}
	else
	{
		printf("The file, %s, already exists.\n", fName);
		printf("Do you want to overwrite it (y/n)?");
		scanf("%c", &ans);
		if (ans == 'n')
		{
			exit(1);
		}
	}
	outfile1 = fopen(fName,"w");

	return outfile1;
}


