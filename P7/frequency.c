/*Author Steven Faulkner
 *reads in a line of text and 
 *calculates frequency of words
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SLEN 1000
#define WLEN 50

int read_line(char *str, int n);
int isPresent(char *word, char wards[][WLEN +1], int count);


int main(){

char input_words[SLEN +1];
char words[SLEN +1][WLEN +1];
char *pch;

int freq[1000] = {0};
int count = 0;
int i, num_chars, pos;

printf("Enter a sentence\n");
num_chars = read_line(input_words, SLEN +1);

pch  = strtok(input_words, " ,.!-");

while(pch != NULL){
// checks if word is already accounted for
pos = isPresent(pch, words, count);
	//copies word if not already found
	if (pos == -1){

	  strcpy(words[count],pch);
	  freq[count] = 1;
	  count++;
	}
	else{
	// inceases count if found
	 freq[pos]++;
	}

	pch = strtok(NULL, " ,.!");

	}

	printf("The frequency is: \n");

	for(i = 0; i < count; i++){
	  printf("%s\t%d\n", words[i], freq[i]);
	}



return 0;
}

int isPresent(char word[], char words[][WLEN +1], int count){
//checks to see if word is already present 
int i;

	for( i = 0; i < count; i++){

	  if (strcmp(word, words[i]) == 0){

		return i;
	  }
	}


	return -1;
}

int read_line(char *str, int n){
// skips white space before beginning to store array
int ch, i = 0;

while((ch = getchar()) != '\n'){

	if (i<n){
	 *str++ = ch;
	 i++;
	}
 }
  *str = '\0';
  return i;
}
