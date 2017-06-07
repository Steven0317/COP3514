/*Author Steven Faulkner
 *
 *adds a function that pops the third variable and rolls it to the front of the stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node* push(struct node* top, int i)
{
   struct node *new_node;
   new_node = malloc(sizeof(struct node));
   if(new_node == NULL)
   {
	printf("malloc failed");
        return top;
   }
   
   new_node->value = i;
   new_node->next = top;
   return new_node;

}

struct node *make_empty(struct node *top)
{
  struct node *p;
	

	while (top != NULL){
		
	  p = top;
	  top = top->next;

		if (p != NULL)
		 free(p);

	}

	top = NULL;

  return top;
}

struct node *pop(struct node *top, int *i)
{
  struct node *p;

	if (top != NULL){


		*i = top->value;
		 p = top->next;
		 free(top);
		 return p;
	} else{

		printf("Stack is empty");

	}

  return top;
}

struct node *roll(struct node *top){
 

   struct node *temp, *prev;


   temp = top->next;
   prev = temp->next;


   temp->next = prev->next;		//swaps temp and next slot

   prev->next = top;			//sets prev-next equal to top

   top = prev;				


  return top;
} 


void print_stack(struct node *top)
{
   struct node *p;
   if(top != NULL){
      for(p = top; p !=NULL; p=p->next)
	printf("%d\n", p->value);
      printf("\n");
   }
   else
      printf("stack is empty\n");
}
