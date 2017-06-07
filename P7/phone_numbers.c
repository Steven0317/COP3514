/*Author Steven Faulkner
 * a simple prgrram to read from a file containing
 * strings of 7 letters and transforms them into
 * phone numbers and then writes them into a new file
 * withing the same directory
 */
#include<stdio.h>
#include<ctype.h>

#define N 100


void translate(char *word, char *phone_number);

//reference array, faster than using switch statement
const char map[] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','\0','7','7','8','8','8','9','9','9','\0'};

int main(){

FILE *fin, *fout;

char filename[N];
char word[8];
char pNumber[8];




	printf("\nEnter input file name: ");
	scanf("%s", filename);

fin = fopen(filename,"r");
	if (fin == NULL){

	  printf("Error opening file\n");
	  return 1;
	}
fout = fopen("phone_list.txt.cvt","w");



//reads from 1st file, passes control to user function then writes to 2nd file
while(!feof(fin)){

	fscanf(fin, "%s", word);

	 translate(word,pNumber);

	  fprintf(fout," %s\n", pNumber);

}



//closes all files
printf("Output file name: %s.cvt \n ", filename);
 fclose(fin);
 fclose(fout);

return 0;
}

void translate(char *word, char *phone_number){

/*takes the first char array
 *then using their ascii #
 *translates the letter into
 * the appropriate #
 */



int i = 0;


	while ( i < 7){
	 int  j = word[i] - 65;
	 phone_number[i] = map[j];
	 i++;
	}

}
