#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int add_file() {
	int item_id = 0, item_quantity;
	char item_description[20], item_date[10], choice = 'Y';
	double item_price;
	
	while (choice == 'Y') {
		system("CLS");	
		printf("ADD INVENTORY ITEM: \n\n");	
		printf("Please input the Item ID: ");
		scanf(" %d", &item_id);	
		printf("Please input the Item Description: ");
		getchar();
		fgets(item_description, 20, stdin); //fix the newline bug later
		item_description[strcspn(item_description, "\n")] = 0; //remove fgets \n
		printf("Please input the Item Quantity: ");	
		scanf(" %d", &item_quantity);                                                                           	
		printf("Please input the Expiry Date (YYYY-MM-DD) (Place '-' if no expiry): ");
		getchar();
		fgets(item_date, 10, stdin);
		item_date[strcspn(item_date, "\n")] = 0; //remove fgets \n
		printf("Please input the Price of the Item (PHP, in two decimal places): ");
		scanf(" %lf", &item_price);
	
		int item_check = id_check(item_id);
		
		if (item_check == 1) {
			printf("\nFailed to add item!\nItem with the same Item ID found!");
		} else {
			int toFile = push_item(item_id, item_description, item_quantity, item_date, item_price);
			if (toFile > 0) {
				printf("\nItem successfully added!");
			} else {
				printf("\nFailed to add item!\nAn error occured while trying to add the item.");
			}
		}
		printf("\n\nDo you want to add another item? Y/N: ");
		scanf(" %c", &choice);
	}  
	printf("\n\n");                                                                                                          
}

void main() {
	char choice;	
	
	while (choice != 'X') {
		system("CLS");
		printf("MAIN MENU:\n");
		printf("[A] Add Inventory Item\n");
		printf("[B] Update Inventory Item\n");
		printf("[C] View Inventory List\n");
		printf("[D] Search for an Inventory Item\n");
		printf("[X] Exit Program\n\n");
		printf("Please input choice: ");
		scanf(" %c", &choice);
		        
		switch(choice) {
			case 'A':
				add_file();
				break;
			case 'B':
				//update inventory item
				break;
			case 'C':
				//view inventory list
				break;
			case 'D':
				//search for an inventory item
				break;
			case 'X':
				printf("\nThank you for using the program!\nProgram now closing.");
				break;
			default:
				printf("Invalid input! Please enter a valid input!\n\n");
				break;                                                   
		}
	} 
}