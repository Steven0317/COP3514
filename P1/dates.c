#include<stdio.h>

int main()
{
	int month1, month2, day1, day2, year1, year2;
	int first_earlier = 0;

	printf("Enter first date(mm/dd/yy): ");
	scanf("%d/%d/%d", &month1, &day1, &year1);

	printf("Enter the second date(mm/dd/yy): ");
	scanf("%d/%d/%d", &month2, &day2, & year2);

	 if(year1 == year2)
	  
		if(month1 == month2)	
			if(day1 < day2)	
				first_earlier = 1;
			else 
				first_earlier = 0;
		
		else
		    if(month1 < month2)  
			   first_earlier = 1;
		    else 
		   	first_earlier = 0;
	 else
		    if ( year1 < year2)
 	 		   first_earlier = 1;
		    else
			   first_earlier = 0;
	 
	

	if((first_earlier = 1))
		printf("%d/%d/%d is earlier\n", month1, day1, year1);

	else
		printf("%d/%d/%d is earlier\n", month2,day2,year2);
	
	return 0;
}
