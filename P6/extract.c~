/*Author Steven Faulkner
 *takes a website url, shortens it and checks to see
 *if it meets the qualifying parameters
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STR_LEN 1000

void extract(char *s1, char *s2);
void read_line(char *str, int n);
void pass_check(char *str);

int main(void)
{	
	char istr[STR_LEN+1];
	char ostr[STR_LEN+1];

	printf("Input: ");
	
	read_line(istr,STR_LEN);

	extract(istr,ostr);
	
	pass_check(ostr);
	
 return 0;
}



void extract(char *s1, char *s2)
{
	/*takes the user input url,
   	 *removes the protocol marker
	 *and terminates at first url
	 *directory
	 */ 	

 char *p, *q;
q = s2;

//starting after the http:// assigns character by character from input string to ouput string
for(p=s1+7; *p != 0;p++)
{
	  if(*p == '/')	
  		break;
	  else
 	  {	*q=*p;	
		q++;
   	  }
}
//sets last elements to null terminator
*q = '\0';
*p = '\0';

}


void read_line(char *str, int n)
{
	/*user defined function to read in
	 *character strings and store them into
	 * istr
	 */
int ch;
int i=0;
	//ch stores characters until new line is reached
	while((ch=getchar()) != '\n')
	{
		if (i<n)
		{*str ++=ch;
		 i++;

		}
	}
	//sets last element to null character
	*str = '\0';
}


void pass_check(char *str)
{
	/*takes the passed string and compares 
	 *to reference strings to ensure
	 *that the url is of desired output
	 *with proper placement
	 */

	//reference strings that hold desired outcomes		
	const char *fref = "www";
	const char *lref = "edu";

	int len = strlen(str);
	//printf("%d", len);
	
	
	//copies last three characters from string
	char *l = &str[len-3];

	//copies first three characters from string
	char f[STR_LEN+1];
	strncpy(f, str, 3);


//if statement that compares the snippets for accuracy
if((strcmp(f, fref) == 0) && strcmp(l,lref) == 0)
{	printf("Output: ");
	puts(str);	
	printf("\n");
}
else
	printf("Whoops, you entered an incorrect url\n");

}

