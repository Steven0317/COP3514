/*****************************************************************/
/*Author Steven Faulkner
 * This program adds, subtracts, or multiplies complex numbers.  */
/* Project 4, Program Design					 */
/*****************************************************************/ 
#include <stdio.h>
void read_numbers(double *r1, double *i1, double *r2, double *i2);
void add(double r1, double i1, double r2, double i2, double *r3, double *i3);
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3);
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3);
void print_complex(double r3, double i3); 

int main(void)
{	//variable declarations
	double r1, r2, r3, i1, i2, i3;
	int option;
	
	printf("Complex Number Arithmetic Program: \n\n");
	for(;;)
	{
		printf("1. Add two complex numbers\n");
		printf("2. Subtract two complex numbers\n");
		printf("3. Multiply two complex numbers\n");
		printf("4. Quit\n\n");

		printf("Choose an option (1 - 4): ");
		scanf("%d", &option);
		switch(option){						// switch to chose arithmetic operation
			case 1:
				read_numbers(&r1, &i1, &r2, &i2);
				add(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 2:
				read_numbers(&r1, &i1, &r2, &i2);
				subtract(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 3:
				read_numbers(&r1, &i1, &r2, &i2);
				multiply(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 4:
				return 0;				//program termination
			default:
				printf("Invalid option. Choose an option (1-4):\n"); // checks for valid input 

		}
	}

	return 0;
}
	
/*Read_Numbers accepts input from user to store as
 *variables for real and complex numbers
 */
void read_numbers(double *r1, double *i1, double *r2, double *i2)
{

	printf("\nEnter the real component of the first number ");
	scanf("%lf", &*r1);
	printf("\nEnter the imaginary component of the first number ");
	scanf("%lf", &*i1);
	printf("\nEnter the real componenet of the second number ");
	scanf("%lf", &*r2);
	printf("\nEnter the imaginary componenet of the second number ");
	scanf("%lf", &*i2);
	

}
/* Add Function-adds the real components and the imaginary components 
 * storing the value in a seperate variable to be called 
 */
void add(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
	*r3 = r1+r2;
	*i3 = i1 +i2;
	

}
/* Subtract Function-subtracts the real and imaginary components respectively
 * storing the value in a seperate variable
 */
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
	*r3 = r1 - r2;
	*i3 = i1 - i2;

}
/* Muliply Function-takes the quotient of F and L from FOIL technique and stores the value in R3
 * and then the quotient from O and I and stores the value in i3
 */
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
	
	*r3 = (r1 * r2) - (i1 * i2);
	*i3 = (r1 * i2) + (i1 * r2);
}
/*Print_Complex-prints the results of the preceding arithmetic functions
 *
 */
void print_complex(double r3, double i3)
{
	if(i3 >= 0)
		printf("\nThe operation yields %.3lf + %.3lfi\n\n", r3, i3);
	else
		
		printf("\nThe operation yields %.3lf  %.3lfi\n\n", r3, i3);
}


