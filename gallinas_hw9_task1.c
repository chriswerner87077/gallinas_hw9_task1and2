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

/* Function Prototypes */

/* Main Program */
void Usage(char** info);
int main(int argc, char *argv[])
{
	// Call usage function if there are not two strings or if --helpis
	// first string
	if (argc != 3 || (strcmp(argv[1],"--help") == 0))
	{
		Usage(argv);
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


