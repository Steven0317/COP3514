/* Author: Steven Faulkner
 *A simple program to calculate the voltage output
 *over a given interval of time.
 */

#include<stdio.h>
#include<math.h>

int main()
{

	double t = 0, volts = 0; //variables for time and voltage



	printf("Time(sec)\t Voltage\n");
	
	//calculates voltage for time less than 1s and prints to screen 
	while( t < 1.0)
	{
	
	volts = .5 * sin(2 * t);

	printf("%.2lf\t\t %.2lf\n", t, volts);

	t += .5;

	}
	//calculates voltage between 1s and 10s and prints to screen
	for(t = 1.0; t <= 10.0;)
	{
	
	volts = sin(t);
	
	printf("%.2lf\t\t %.2lf\n", t, volts);

	t += .5;

	}
	//calcualtes voltage between 1s and 12s and prints to screen
	for( t = 10.0; t <= 12.0;)
	{
	
	volts = sin(10.0);

	printf("%.2lf\t\t %.2lf\n", t, volts);

	t += .5;
	}

	return 0;
}
