/*Author: Steven Faulkner
 * takes an 8 bit binary number 
 * and manipulates it */
 
#include<stdio.h>
#define N 8
//function declaration
void edge( int a1[], int a2[]);

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
    for(i = 0; i<N;i++)
    printf("%d", a2[i]);
   
	printf("\n");
  
	return 0;
}



void edge(int a1[],int a2[])
{  int i;
   //sets 1st element to zero
   a2[0] = 0; 
   
   // compares place holder(i)to previous element(i--) to determine outcome  	
   for(i = 1; i< N; i++)
   { 
	if(a1[i] != a1[i-1])	
		a2[i] = 1;
	else if(a1[i] == a1[i-1])
		a2[i] = 0;

   }
 	
}
