#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "linkedlist.h"

#define DATA_SIZE 15
#define FLAG_SIZE 8

extern int errno;

void stuff_data(linkedlist);
void frame_data(linkedlist);

int main(void) {

	int tmp[DATA_SIZE] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};

	linkedlist data = tolist(tmp, DATA_SIZE);
	if(data == NULL) goto CLEAN;

	printf("Before Stuffing: ");
	print_list(data);
	printf("-- %d characters\n", size(data));

	stuff_data(data);
	if(errno != EXIT_SUCCESS) goto CLEAN;
	
	printf("After Stuffing: ");
	print_list(data);
	printf("-- %d characters\n", size(data));

	frame_data(data);
	if(errno != EXIT_SUCCESS) goto CLEAN;

	printf("After framing: ");
	print_list(data);
	printf("-- %d characters\n", size(data));

	CLEAN:
	clear(data);
	perror("Status");

	return errno;
}

void stuff_data(linkedlist head) {

	linkedlist indirect = head;
	int counter = 0;
	int i = 0;

 	for(i = 0; *indirect != NULL; i++) {
		if((*indirect)->value == 1) {
			counter++;
		}else {
			counter = 0;
		}	
		if(counter == 5){
			add_index(head, i, 0); 

			if(errno != EXIT_SUCCESS) 
				return;
			
			counter = 0;
		}
		(indirect) = &((*indirect)->next);
	}

}

void frame_data(linkedlist head) {

	int flag[FLAG_SIZE] = {0, 1, 1, 1, 1, 1, 1, 0};

	add_first_all(head, flag, FLAG_SIZE);
		
	if(errno != EXIT_SUCCESS) {
		return;
	}

	add_all_index(head, size(head), flag, FLAG_SIZE); 

}
