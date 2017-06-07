/* Author: Steven Faulkner
 * A simple program that makes a linked list from user input
 * then provides user functionality tos search and print through the list
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LEN 30
struct dog{
	int number;
	char dog_name[NAME_LEN+1];
	char owner_last_name[NAME_LEN+1];
	char breed[NAME_LEN+1];
	struct dog *next;
};


struct dog *append(struct dog *list);
void search(struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct dog *dog_list = NULL;  
  printf("Operation Code: a for appending to the list, s for finding a dog"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': dog_list = append(dog_list);
                break;
      case 's': search(dog_list);
                break;
      case 'p': print(dog_list);
                break;
      case 'q': clear(dog_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct dog *append(struct dog *list){

	/* is passed the pointer to the linked list
	 * prompts user for an id number, if the id number is already stored within the
	 * LL a message is displayed and function is exited, if not memory is allocated fo
	 * a struct and information is stored using the read_line function, if this is the
	 * first struct created, the return pointer points to the new struct
	 */
	
	struct dog *new_node, *cur, *temp;
	int number;

	printf("Please enter patient ID");
	scanf("%d", &number);
									//checks to see if dog is already in list
	for (temp = list; temp != NULL; temp = temp->next){

		if ( temp->number == number){
		  printf("Patient already exists in system");
		  return list;
		}
	}



	new_node = malloc(sizeof(struct dog));

	if (new_node == NULL){

	 printf("Memory allocation failed in append");
	 return list;
	
	}


	new_node->number = number;

	printf("Enter the patient's name");
	read_line(new_node->dog_name,NAME_LEN);

	printf("Enter the breed");
	read_line(new_node->breed,NAME_LEN);

	printf("Enter owners last name");
	read_line(new_node->owner_last_name,NAME_LEN);

	new_node->next = NULL;


							// if list is empty add insert node else add to end of list
	if (list ==  NULL){
		
		list = new_node;
		list->next = NULL;
		return list;
	}else{

		for (cur = list; cur->next!= NULL; cur = cur->next);

		cur->next = new_node;
		new_node->next = NULL;
		return list;		

	 }

  free(new_node);

}

void search (struct dog *list)
{
	/* Is passed a pointer to search through the linked list 
	 * in using string comparison to find a struct containing 
	 * the right information
	 */

 struct dog *p, *nombre;
 int ref = 0;
 int flag = 0;
;
	printf("Enter a dogs name to search for ");
	scanf("%s", nombre->dog_name);


	printf("\nID Number\t Dog Name\t Breed\t\t Owner\n");

	for ( p = list; p != NULL; p = p->next){
	
									//uses strcmp int value to check for likeness	
		ref = strcmp(p->dog_name, nombre->dog_name);	

		if ( ref == 0){

			
			printf("%d\t\t  %-10s\t  %-10s\t %-12s\n", p->number, p->dog_name, p->breed, p->owner_last_name);
		
			flag++;
		}
	}

	if (flag == 0)
	  
	  printf("Dog not found");
		


}
void print(struct dog *list){
 
	/* Prints all structs within the 
	 * linked list
	 */


	printf("\nID Number\t Dog Name\t Breed\t\t Owner\n");
	for( ; list != NULL; list = list->next){
		
		printf("%d\t\t  %-10s\t  %-10s\t %-12s\n", list->number, list->dog_name, list->breed, list->owner_last_name);
	
	}
}
void clear(struct dog *list){

	/* frees the memory to the stack 
	 * upon exiting the program and displays a success/fail message
	 */


	struct dog *p;

	while ( list != NULL){

		p = list;
		list = list->next;
	
		if (p != NULL)
		
		 free(p);
	}

	if (list == NULL)
	 
	 printf("List has been cleared!\n");

	else

	 printf("List not succesfully cleared!\n");

	
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }
