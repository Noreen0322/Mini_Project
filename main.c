#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int push_item(int item_id, char item_description[20], int item_quantity, char item_date[10], double item_price) {
	FILE * fpointer = fopen("inventory.csv", "a");
	fprintf(fpointer, "%d, %s, %d, %s, %lf\n", item_id, item_description, item_quantity, item_date, item_price);
	fclose(fpointer);
}

int id_check(int item_id) {
	FILE * fpointer = fopen("inventory.csv", "r");
}

int add_file() {
	int item_id, item_quantity;
	char item_description[20], item_date[10];
	double item_price;
		
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
		
	push_item(item_id, item_description, item_quantity, item_date, item_price);                                                                                                                            
}

void main() {
	char choice;
	printf("MAIN MENU:\n");
	printf("[A] Add Inventory Item\n");
	printf("[B] Update Inventory Item\n");
	printf("[C] View Inventory List\n");
	printf("[D] Search for an Inventory Item\n");
	printf("[X] Exit Program\n\n");
	
	while (choice != 'X') {
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