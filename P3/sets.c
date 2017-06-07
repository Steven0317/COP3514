/*Author Steven Faulkner
 *Finds the union and intersection of two user given arrays
 *
 */

#include<stdio.h>
int main()
{
	#define N 10//array constant
	const int arr[N] ={0,1,2,3,4,5,6,7,8,9};// placeholder arrays
	int numA, numB, setA[N]={0}, setB[N]={0};// initializes arrays
	
	//sets magnitude of 1st array
	printf("Enter the number of elements in set A: ");
	scanf("%d", &numA);
	
 	//prompts for elements
	printf("Enter %d numbers for set A: ", numA);

	int i=0,k, value;
	/*loop takes input then checks 
 	*to see where the input belongs
	* in the array
 	*/ 
	do
	{
	scanf("%d", &value);
		for(k = 0;k < N;k++)
		{	if(arr[k] == value)
			setA[k] = 1;
				
		}
	i++;
	}while(i < numA);
	
	printf("Enter the number of elements in set B:");
	scanf("%d", &numB);
	
	printf("Enter %d numbers for set B: ", numB);
	
	
	

	//Same as above but for set B
	i=0; 
	do
	{
	scanf("%d", &value);
		for(k = 0; k< N;k++)
		{	if(arr[k] == value)
			setB[k] = 1;
			
		}
	i++;
	}while(i < numB);
	
	//test loop for accurate assignment
	//int j;
	//for(j = 0;j< N;j++)
	//printf("%d", setB[j]);


	/*compares elements of both arrays to the
	 *place holder array to check for union set
	 */ 
	
	printf("Union of set's A & B: ");
	
	for(i = 0; i < N; i++)
	{ 
		
		if(setA[i] ==1 || setB[i] == 1)
			printf("%d ", arr[i]);
		
		
		else
			continue;
				
		
	}

	printf("\n");
	

	/*compares elements of each array against
	 *the placeholder array to find intersection set
	 */ 
	printf("Intersection of set's A & B: ");
	
	for(i = 0; i < N; i++)
	{
		
		if((setA[i] == 1 && setB[i] != 0) || (setA[i] != 0 && setB[i] ==1))
			printf("%d ", arr[i]);
		
		else
			continue;
	
	}
	printf("\n");
	

	return 0;
}
