/*
- Palindromes.c
- Check whether a string is a Palindrome
- Patrick Wain, B00830627
- Sept 11, 2022
*/

#include "Palindromes.h"

FILE* infile;

char inrec[MAX_REC_LEN];

int main(int argc, char* argv[]) 
{
	int i = 0;

	getchar();

	/* Check number of arguments */
	if (argc == 1) 
	{
		printf("Missing file name\n");
		getchar();
		return -1;
	}

	/* file is missing */
	if (fopen_s(&infile, argv[1], "r") != 0) 
	{
		printf("Error opening file >%s< - possibly missing\n", argv[1]);
		getchar();
		return -1;
	}
	
	while (1==1)
	{

		if (inrec[i] == '>')
		{
			break;
		}

		inrec[i] = fgetc(infile);
		printf("%c", inrec[i]);

		i++;
	}

	getchar();

	fclose(infile);

	getchar();
	return 0;
}