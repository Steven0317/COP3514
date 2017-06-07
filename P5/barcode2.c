/*Author: Steven Faulkner
 * takes an 8 bit binary number 
 * and manipulates it */
 
#include<stdio.h>
#define N 8
//function declaration
void  edge( int *a1, int *a2 );

int main(void)
{ 
  int i, a1[N], a2[N]={0};
  //user input 
  printf("Enter an 8 bit binary number: ");
  //initializes 1st array
   for( i = 0; i < N; i++)
   scanf("%1d", &a1[i]);   

   //calls user defined function
   edge(a1, a2);
   
    //prints array after function executes
    printf("\nOutput: ");
    for(i = 0; i<N;i++)
    printf("%d", a2[i]);
   
	printf("\n");
  
	return 0;
}


/*Edge - compares elements of array to previous elements 
 *for equivalance, converting the element as necessary
 */

void  edge(int *a1,int *a2)
{  
   
   int *p;
   int *q;
   p = a2; 

   // compares pointer to previous pointers to determine outcome  	
   for(q = a1+1; q < a1+N; q++)
   {	p++;	
	
	if( *q != *(q-1))	
		*p = 1;
	else 
		*p = 0;
   }
 	
}
