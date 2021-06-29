#include "mymalloc.h"
/*
Assignment: project 3
Course: csc 352
Auhtor: Chris Lin
Purpose: Create a custom malloc

*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
       int size;
       char free;
       struct Node* next;
       struct Node* prev;
};


struct Node* head = NULL;
struct Node* end = NULL;


void *my_lastfit_malloc(int size)
{
	struct Node* temp;
	struct Node* new;
	if(head == NULL){
		head = sbrk(size + sizeof(struct Node));
		head -> size = size;
		head -> free = 0;
		head -> next = NULL;
		head -> prev = NULL;
		end = head;
		return head;
	}
	else{
		temp = end;
		while(temp != NULL){
			if(temp -> size > (size + sizeof(struct Node)) && 
				temp -> free){
				new -> size = size;
				new -> free = 0;
				new -> next  = temp; 
				new -> prev = temp -> prev;
				temp -> prev -> next = new;
				temp -> prev = new;
				temp -> size = temp -> size - new -> size - sizeof(struct Node);
				return new;
			}
			temp = temp -> prev;
		}
		if(temp == NULL){
			new = sbrk(size + sizeof(struct Node));
			new -> size = size;
			new -> free = 0;
			new -> prev = end;
			new -> next = NULL;
			end -> next = new;
			end = new;
			return new;
		}

	}

};
void my_free(void *ptr)
{
	struct Node* temp;
	
	if(end == ptr){
		sbrk(- (end->size + sizeof(struct Node)));
		temp = end -> prev;
		temp -> next = NULL;
		end = temp;
		return;
	}

	while(head != NULL){
		if(head == ptr ){
			temp = head;
			temp -> free = 1;
			if(temp -> prev != NULL && 
				temp -> prev -> free){
				temp -> size = temp -> size + temp-> prev -> size;
				temp -> prev = temp -> prev -> prev;
				temp -> prev -> next = temp;
			}
			if ( temp -> next -> free){
				temp -> size = temp -> size + temp-> next -> size;
				temp -> next = temp -> next -> next;
				temp -> next -> prev = temp;
			}
			return;
		}
		head = head-> next;

	}
};



