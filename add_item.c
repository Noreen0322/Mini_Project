#include <stdio.h>
#include <stdlib.h>
#include <main.c>

int check_id(int item_id) {
	//check item_id from item list
}

int push_item(int item_id, char item_description[20], int item_quantity, char item_date[20]) {
	
	/*(FILE * fpointer = fopen("inventory.csv", "a");
	fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accounting\n");
	fclose(fpointer);*/
}

/*int add_file() {
	int item_id, item_quantity;
	char item_description[20], item_date[10];
	double item_price;
		
	printf("ADD INVENTORY ITEM: \n\n");	
	printf("Please input the Item ID: ");
	scanf(" %d", &item_id);
	printf("\nPlease input the Item Description: ");
	fgets(item_description, 20, stdin); //fix the newline bug later
	printf("\nPlease input the Item Quantity: ");
	scanf(" %d", &item_quantity);
	printf("\nPlease input the Expiry Date (YYYY-MM-DD) (Place '-' if no expiry): ");
	scanf(" %c", &item_date);
	printf("\nPlease input the Price of the Item (PHP, in two decimal places): ");
	scanf(" %d", &item_price);
	
	//call to function to check for validity
	
	push_item(item_id, item_description, item_quantity, item_date, item_price);
}*/