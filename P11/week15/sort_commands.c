#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare_word(const void *p, const void *q);


int main(int argc, char *argv[]){

int i;

	

	if (argc < 3){

	  printf("Error not enough commands to execute");
	  return 1;
	}

		
	qsort(argv, argc, sizeof(*argv), compare_word);

	
	printf("Sorted List: ");
	
	
	for(i = 1; i < argc; i++){

	  printf("%s ", argv[i]);
	}




	return 0;

}




int compare_word(const void *p, const void *q){


	return strcmp(*((char **)p), *((char **)q));

}
