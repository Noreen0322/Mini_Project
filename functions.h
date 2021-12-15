#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "add_item.h"

int push_item(int item_id, char item_description[20], int item_quantity, char item_date[10], double item_price) {
	int retVal = 0;
	FILE * fpointer = fopen("inventory.csv", "a");
	retVal = fprintf(fpointer, "%d, %s, %d, %s, %lf\n", item_id, item_description, item_quantity, item_date, item_price);
	fclose(fpointer);
	
	return retVal;
}

int id_check(int item_id) {
	char fItem[255];
	int retVal = 0;
	FILE * fpointer = fopen("inventory.csv", "r");
	
	while (fgets(fItem, 255, fpointer)) {
		char* token = strtok(fItem, ",");
		if (token) {
			int n = atoi(token);
			if (n == item_id) {
				retVal = 1;
				break;
			}
		}
	}
	fclose(fpointer);
	return retVal;
}

int date_check(char item_date[11]) {
	int returnVal = 0;
	for (int i = 0; i < strlen(item_date); i++) {
		if (i != 4 && i != 7) {
			if (isdigit(item_date[i]) == 0) {
				returnVal = 1;
				break;
			}
		} else {			
			if (item_date[i] != '-') {
					returnVal = 1;
					break;
			}
		}
	}
	return returnVal;
}