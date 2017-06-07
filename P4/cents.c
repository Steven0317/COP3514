/*Author Steven Faulkner
*cents.c, project  4
*Gives the least amount of coins need to make change
*/

#include <stdio.h>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

void coins(int cents, int *q, int *d, int *n, int *p);

int main(void)
{
	//initialize variables and read input
	int cents, pennies, quarters, dimes, nickels;
	pennies = quarters = dimes = nickels =0;
	int *q = &quarters;
	int *d = &dimes;
	int *n = &nickels;
	int *p = &pennies;


        printf("Enter the number of cents:\n");
	scanf("%d", &cents);

	//check the range of the input amount
	if(cents< 0 || cents > 10000)
	   printf("Invalid amount %d,\nAmount must be between 0 and 10000, inclusive\n", cents);
        else {
		coins(cents, &quarters, &dimes, &nickels, &pennies);

		printf("Quarters: %d\n", *q);
	        printf("Dimes: %d\n", *d);
        	printf("Nickels: %d\n", *n);
	        printf("Pennies: %d\n", *p);
	}
	return 0;
}
/*coins - calculates the least amount of each coin needed in order 
 *to reach the total amount. Parameters passed are value of cents and 
 *pointers for each denomination, which are modified as the function executes
 */
void coins(int cents, int *q, int *d, int *n, int *p){

	*q = cents / QUARTER;
	*d = cents % QUARTER / DIME;
	*n = cents % QUARTER % DIME / NICKEL; 
	*p = cents % QUARTER % DIME % NICKEL / PENNY;



}
