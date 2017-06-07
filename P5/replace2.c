/*Author Steven Faulkner
 * takes a positive integer, performs arithmetic and
 *display the results to the screen
 */


#include<stdio.h>

void replace(int *a, int *b, int n);
void swap(int *p, int *q);





int main(void)
{	int size;
	
	printf("Enter the number of digits of the number: ");   //asks & stores sizeof array
	scanf("%d", &size);
	int *p;
		
	int a[size], b[size];
	p = &a[0];
	
	printf("Enter a positive integer number: ");		//stores integer in array a 
	for( p = &a[0]; p < &a[size]; p++)
	   scanf("%1d", p);
	   
	replace(a, b, size);					// transfers control to replace, passing along arrays a b and sizeof
	
		
	
		
	swap(&b[0],&b[size-1]);				//tranfers control to swap, passing along addresses of first and last int in array b
	
	
	int *x;							//prints array b to the screen
	for(x = &b[0]; x < &b[size];x++)
	printf("%d", *x);

	printf("\n");	
	
	//for(x = &b[0]; x < &b[size];x++)
	//printf("%p \n", x);

	printf("\n");
	
return 0;
}
/*Replace reads in a pointer, performs
 *arithmetic and stores the value in a
 * second pointer
 */

void replace(int *a, int *b, int n)
{   int *p, *q;
    q = b;

	for(p = a; p < a+n; p++)
	{
		*q = ((*p + 6) % 10);	
		q++;
	}
		
}
/*Swap creates a placeholder variable and switches the values 
 *of the first and last element of array b
 */

void swap( int *p, int *q)
{ 	
  
   int temp = *p;
   *p = *q;
   *q = temp;	
   
}
