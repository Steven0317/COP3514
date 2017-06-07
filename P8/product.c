/*Steven Faulkner
 *a simple program that reads in from a text file,
 *sorts the file in ascending order according to
 * sales volume then writes the data to a new file
 */


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


#define LEN 100
#define MAX 1000


struct product
{
char name[LEN];
double unit_price;
double lbs_sold;
double sale_vol;
};


void selection_sort(struct product p[], int n);

int main(){

FILE *fin;
FILE *fout;

								//opens file and checks for success

fin = fopen("sale.txt", "r");
  
  if (fin == NULL){

	printf("Error opening file");

	return 1;

	}
								// creates file to be written to
fout = fopen("sorted_products.txt", "w");

 

struct product description[MAX];

int i = 0;

									
fprintf(fout, "#Name\t Unit Price($)\t Units(pound) Sold\t   Sale Volume($)\n");
								
								//reads from 1st file and stores data in array of structs
								//while also computing sales volume 
while (!feof(fin)){

	fscanf(fin, "%s %lf %lf %lf", description[i].name, &description[i].unit_price, &description[i].lbs_sold, &description[i].sale_vol);

	description[i].sale_vol = description[i].unit_price * description[i].lbs_sold;

	i++;
	}
	

								//passses control to user defined function	
	selection_sort(description, i);




				
int j = 0;
								// writes the array of strcuts to the outbound file
while ( j< i){
	
	fprintf(fout, "%-10s %-.2lf\t\t    %-.2lf\t\t\t%-.2lf\n", description[j].name, description[j].unit_price, description[j].lbs_sold, description[j].sale_vol);

	j++;
}


fclose(fin);
fclose(fout);

return 0;
}


void selection_sort(struct product p[], int n){

	/* Selection Sort is passed the array of structs
	 * and the size of array, then systematically 
	 * sorts the array from smallest to largest 
	 */


  struct product temp;
  int largest = 0;;
  int i;

 if (n == 1){
	return;
 }

	for( i = 1; i < n; i++){
	  if ( p[i].sale_vol > p[largest].sale_vol){
	    
       	   largest = i;
	   
	  }
	}
	   if (largest < n-1){
		
		temp = p[n-1];
		p[n-1] = p[largest];
		p[largest] = temp;
	  }	

	selection_sort(p, n-1);        
 }
 
