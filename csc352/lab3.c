#include <stdio.h>
#include <stdlib.h>

struct Node {
       int grade;
       struct Node* next;
};

int main(){
	int n;
	int avg = 0;
	int allG = 0;
	int count = 0;
	struct Node* head = NULL;
	struct Node* temp = NULL;
	struct Node* next = NULL;
	while(n != -1){
		scanf("%d", &n);
		if(n == -1){
			break;
		}
		if(head == NULL){
			head = (struct Node*)malloc(sizeof(struct Node));
			head -> grade = n;
			head -> next = NULL;
		}
		else{
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp -> grade = n;
			temp -> next = head;
			head = temp;
		}
	}
	while(head != NULL){
		count += 1;
		allG += head-> grade;
		next = head ->next;
		free(head);
		head = next;
	}
	avg = allG / count;
	printf("%d \n", avg);

	return 0;
}


