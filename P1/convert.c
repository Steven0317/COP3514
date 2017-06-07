#include<stdio.h>

int main()
{

	int input;
	double conversion, output;
	#define M2K 1.6093
	#define K2M .6214
	#define I2C 2.54
	#define C2I .3937


	//prompts use to determine coneversion
	printf("Choose a conversion from the table below]\n");
	printf("1-Miles to Kilometers\n");
	printf("2-Kilometers to miles\n");
	printf("3-Inches to Centimeters\n");
	printf("4-Centimeters to Inches\n");
	scanf("%d", &input);

	//if statement to ensure valid input
	if(input >= 1 && input <= 4)
	{
		switch(input)
		{
			case 1:
				printf("Enter the amount of miles to be converted\n");
				scanf("%lf", &conversion);
				output = (conversion * M2K);
				printf("%.2lf Kilometers\n", output);
				break;
			case 2:
				printf("Enter the amount of kilometers to be converted\n");				 
			        scanf("%lf", &conversion);
				output = (conversion * K2M);
				printf("%.2lf Miles\n", output);
				break;
			case 3:
				printf("Enter the amount of inches to be converted\n");
				scanf("%lf", &conversion);
				output = (conversion * I2C);
				printf("%.2lf centimeters\n", output);
				break;
			case 4:
				printf("enter the amount of centimeters to be converted\n");				
			        scanf("%lf", &conversion);
				output = (conversion * C2I);
				printf("%.2lf Inches\n", output);
				break;
		}
	}
	
	else
	{
	printf("Uexpected Values");
	return 0;
	}
	
 return 0;
			
}
