#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

void add_file() {
	int item_id = 0, item_quantity = 0, item_check;
	char item_description[20], item_date[11], choice = 'Y';
	float item_price = 0;
	
	while (choice == 'Y') {
		system("CLS");	
		printf("ADD INVENTORY ITEM: \n\n");	
		while ((item_id <= 9999 || item_id > 99999)) {	
			printf("Please input the Item ID: ");
			scanf(" %d", &item_id);		
			if (item_id <= 9999 || item_id > 99999) {
				printf("\nInvalid Item ID! Item ID should be 5 digit number.\n\n");
			}							
			fflush(stdin); //clear input buffer
		}		
		printf("Please input the Item Description: ");		
		fgets(item_description, 20, stdin); //fix the newline bug later
		item_description[strcspn(item_description, "\n")] = 0; //remove fgets \n
		item_check = 1;
		while (item_check == 1) {
			item_check = 0;			
			printf("Please input the Item Quantity: ");	
			scanf(" %d", &item_quantity);
			if (item_quantity <= 0) {
				printf("\nInvalid Quantity! Make sure that the quantity is a number and is non-zero and non-negative.\n\n");
				item_check = 1;
				getchar();
			}   
			fflush(stdin); //clear input buffer  
		}
		int dateCheck = 1;
		while (dateCheck == 1) {
			printf("Please input the Expiry Date (YYYY-MM-DD) (Place '-' if no expiry): ");		
			fgets(item_date, 11, stdin);			
			item_date[strcspn(item_date, "\n")] = 0; //remove fgets \n
			if (strcmp(item_date, "-") == 0) {
				dateCheck = 0;
			} else {
				if (strlen(item_date) < 10) {
					dateCheck = 1;
				} else {					
					dateCheck = date_check(item_date);
				}				
			}					
			if (dateCheck == 1) {
				printf("\nInvalid Date! Please make sure that the date follows the YYYY-MM-DD format and does not contain any invalid characters.\n\n");
			}	
		}
		while(item_price == 0) {			                                	
			printf("Please input the Price of the Item (PHP, in two decimal places): ");	
			scanf(" %f", &item_price);
			if (item_price <= 0) {
				printf("\nInvalid Price! Make sure that the price is a number and is non-zero and non-negative!\n");
				item_price = 0;
			}
			fflush(stdin);
		}  		                           
	
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