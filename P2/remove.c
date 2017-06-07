/*Author: Steven Faulkner
 *Takes a user inputed phrase, removes any non alpha characters
 * capitalizes all lettters then prints the output to screen
 *
 */


#include<stdio.h>
#include<ctype.h>
int main()
{
	
	char ch;
	// prompts user for a phrase
	printf("Enter a phrase that contains no digits ");
	
	
	printf("\n");
	// do while loop to differentiate between alpha and non alpha
	do
	{	
		if( isalpha(ch)) 	//capitalizes all alpa characters
		{	ch = toupper(ch);
			putchar(ch);
			ch = getchar();
		}
		else			// differentiates between non alpha characters and white splace
			 if (ch == 32 )	
			{	putchar(ch);	
				ch = getchar();
			}
			else		// skips non white space characters
				ch = getchar();	
			

	}
	while(ch !='\n');

	printf("\n");	

	return 0;
}
