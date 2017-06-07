#include<stdio.h>

int main()

{       
	int input, digit;//input variables
	int inputs[3];//array declaration
	//asks for input
	printf("Enter a three-digit number");
	scanf("%d", &input);

		
		//checks for validity
		while(input < 100 || input >999 )
		{
			printf("Unacceptable Number");
			return 0;
		}

		// asigns elements to array
		for(digit = 2; digit >= 0; digit--)
		{
			inputs[digit] = (((input % 10)+6)%10);
			input /= 10;
			
		}
		//prints array 
		for(digit = 0; digit < 3; digit++)
			printf("%d", inputs[digit]);
	
		
	printf("\n");
	return 0;	
		
}	
