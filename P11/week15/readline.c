/*Author Steven Faulkner
 * reads in user input  and stores in in appropriate sting
 *
 */

#include<ctype.h>
#include<stdio.h>




int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }
