/* Author: Steven Faulkner
 * A simple program that makes a linked list from user input
 * then provides user functionality to search and print through the list
 */
#include "readline.h"
#include "dogs.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>




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

