/*
- PalindromeTest.c
- Checks if a string is a palindrome
- Patrick Wain, B00830627
- Sept 11, 2022
*/

#include "Palindromes.h"

char new_str[MAX_REC_LEN];

void check_palindrome(char* inrec) 
{
	/* variables */
	int i = 0;
	int sen_tot = 0;
	int follow_spot = 0;

	char ch = inrec[follow_spot];

	while (ch != NUL) 
	{
		/* is a valid character */
		if (ch >= 'A' && ch <= 'Z') 
		{
			new_str[i] = tolower(ch);

			i++;
		}
		else if (ch >= 'a' && ch <= 'z') 
		{
			new_str[i] = ch;

			i++;
		}
		/* sentence has been found */
		else if (ch == '!' || ch == '?' || ch == '.') 
		{
			new_str[i] = '\0';
			
			/* redefine i for checking */
			i = strlen(new_str);

			/* counter from bottom of string */
			int j = 0;

			/* odd length */
			if (i % 2) 
			{
				while (j < i) 
				{
					if (new_str[j] != new_str[i]) 
					{
						printf("\nNO ");
						while ((ch = *inrec++)) 
						{
							printf("%c", ch);
							if (ch == '!' || ch == '?' || ch == '.') 
							{
								break;
							}
						}
						break;
					}

					if (i == j) 
					{
						printf("\nYES ");
						while ((ch = *inrec++)) 
						{
							printf("%c", ch);
							if (ch == '!' || ch == '?' || ch == '.') 
							{
								break;
							}
						}
						break;
					}
					i--;
					j++;
				}
			}
			/* even length */
			while (j < i)
			{
				if (new_str[j] != new_str[i])
				{
					printf("\nNO ");
					while ((ch = *inrec++))
					{
						printf("%c", ch);
						if (ch == '!' || ch == '?' || ch == '.')
						{
							break;
						}
					}
					break;
				}

				if (i == (j+1))
				{
					printf("\nYES ");
					while ((ch = *inrec++))
					{
						printf("%c", ch);
						if (ch == '!' || ch == '?' || ch == '.')
						{
							break;
						}
					}
					break;
				}
				i--;
				j++;
			}
		}

		follow_spot++;
		ch = inrec[follow_spot];
	}

	printf("\nit works?");
	return;
}