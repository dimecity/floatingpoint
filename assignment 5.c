#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void CheckFloating() {	//Function to check if input number is a floating number
	char number[20];	//Char variable to hold input
	int state = 0;		//State of program
	int i = 0;
	
	printf("Enter a number: ");
	scanf("%s", number);		//Take input
	
	for (i = 0; i < strlen(number); i++) {		//Loop through every character of input
		if (number[i] == '.' || number[i] == 'e' || number[i] == 'E') {	//If input has '.' or 'e, E' then state = 1 and break
			state = 1; 			
			break;
		}
		if (number[i] == '-' || number[i] == '+') {	//Skip when number starts with '-,+' so that isdigit function won't mistakenly mark it false 
			continue;
		}
		if (isdigit(number[i]) == 0) {	//If any character except '-, +, E, e' in the input then state = 2 
			state = 2;
			break;
		}		
	}
	
	for (i = i + 1; i < strlen(number); i++) {			//Check the part after the break if there is any character beside number is entered
		if (number[i] == 'e' || number[i] == 'E' || number[i] == '-' || number[i] == '+') 
			continue;		
		if (isdigit(number[i]) == 0) {		
			state = 2;
			break;
		}
	}
	
	if (state == 2) 				//Print result
		printf("The input is not a valid number,\n\n");		
	else if (state == 1) 
		printf("The input is a floating point number.\n\n");
	else 
		printf("The input is an integer number.\n\n");
}


int main(int argc, char **argv) {
	while(1) {	//Infinite loop to enter input 
		CheckFloating();	
	}
	return 0;
}
