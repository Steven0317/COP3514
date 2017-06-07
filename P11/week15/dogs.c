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
	
	struct dog *new_node, *cur;
	int number;

	printf("Please enter patient ID");
	scanf("%d", &number);
	
								//checks to see if dog is already in list
	for(cur = list; cur != NULL; cur = cur->next){

		if(cur->number == number){
		  printf("Dog already in system ");
		 return list;
		}
	}

	new_node = malloc(sizeof(struct dog));

	if (new_node == NULL){
		printf("ERROR in Append");
		return list;
	}


	/* reads in user input, passing control to read line function
	 * to store data in appropriate struct member
	 */

	new_node->number = number;

	printf("Enter dog name: ");
	read_line(new_node->dog_name, NAME_LEN);
	
	printf("Enter dog breed: ");
	read_line(new_node->breed,NAME_LEN);

	printf("Enter Owner name: ");
	read_line(new_node->owner_last_name, NAME_LEN);


	if( list == NULL){
	
		list = new_node;
		list->next = NULL;
		return new_node;
	}else if(strcmp(list->owner_last_name, new_node->owner_last_name) > 0){		//checks to see 'alphabetical order' of last name

		new_node->next = list;
		list = new_node;
	}else{

		for(cur = list; cur->next != NULL && (((strcmp(cur->next->owner_last_name, new_node->owner_last_name) <= 0)) && (strcmp(cur->next->dog_name, new_node->dog_name) < 0)); cur = cur->next); // uses dogs name to determine final position if last names are the same;

		if(cur->next == NULL){

			cur->next = new_node;
			new_node->next = NULL;	
		}else{

			new_node->next = cur->next;
			cur->next = new_node;
		}
	}

	return list;

}




void search (struct dog *list)
{
	/* Is passed a pointer to search through the linked list 
	 * in using string comparison to find a struct containing 
	 * the right information
	 */

 struct dog *p, *nombre;
 int flag = 0;
;
	printf("Enter a dogs name to search for ");
	scanf("%s", nombre->dog_name);


	printf("\nID Number\t Dog Name\t Breed\t\t Owner\n");

	for ( p = list; p != NULL; p = p->next){
	
									//uses strcmp int value to check for likeness		

		if ( strcmp(p->dog_name, nombre->dog_name) == 0){

			
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

struct dog *delete_from_list(struct dog *dogs){

int num;

	printf("Enter a dogs ID number to be deleted ");
	scanf("%d", &num);

struct dog *prev, *cur;

	/* passed along a pointer to a LL then searches for a dogs ID number
	 * in orer to de-link the struct/ relink the surrounding structs
	 * and then free the memory
	 */

	
	for(cur = dogs, prev = NULL; 
		cur !=NULL && cur->number != num; 
		prev = cur, cur = cur->next);
	
	 if (cur == NULL){

		printf("Dog not found");
		return dogs;
	}
	 if( prev == NULL){
		
			
		dogs = dogs->next;
		
			
	}
	 else{

		prev->next = cur->next;	

	}
	


	printf("dog %s deleted\n ", cur->dog_name);	
	free(cur);

	
	return dogs;
		
}
