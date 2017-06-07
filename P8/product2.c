/*Steven Faulkner
 *a simple program that that accepts cmd line arguments
 *and finds the listed data within a specified file
 */


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define LEN 100
#define MAX 1000


struct product
{
char name[LEN];
double unit_price;
double lbs_sold;
double sale_vol;
};


void find_product(struct product p[], int n, char *name);


int main(int argc, char * argv[]){

  FILE *fin;

  
									//checks for cmd line input validation
	if (argc < 2){

	  printf("Invalid argument entered please try again");

	  return 1;
	}


									// opens file then checks to make sure it was successful
  fin = fopen("sale.txt", "r");
  
    if (fin == NULL){

	printf("Error opening file");

	return 1;

	}

 
									// array of structs declaration
  struct product description[MAX];

  int i = 0;

									//reads from given file and stores the data in array of structs
    while (!feof(fin)){						

	fscanf(fin, "%s %lf %lf %lf", description[i].name, &description[i].unit_price, &description[i].lbs_sold, &description[i].sale_vol);

	description[i].sale_vol = description[i].unit_price * description[i].lbs_sold;

	i++; 

  }
									// calls user defined function
  find_product( description, i, *argv);

  fclose(fin);

return 0;
}



void find_product(struct product p[], int n, char *name){

	/* array of strcuts, argc and argv are passed 
	 * which function uses to step through a nested
	 * loop comparing the name to a struct member
	 * then printing any succesful results
	 */



  int i,j;
  int ref;

	
  for(j = 0; j < n;j++){	

   for( i = 0; i < n; i++){
	
	ref = strcmp(name,p[i].name);
	
	  if (ref == 0){

	    printf("Output:\n Name: %s\n Unit price: $%.2lf\n Number of pounds sold: %.2lf\n Sale Volume: $%.2lf\n", p[i].name, p[i].unit_price, p[i].lbs_sold, p[i].sale_vol);

        }  	
   }
	name++;
  }
} 
