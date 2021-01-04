// Técnica para validação de leitura de inteiros
// Fonte: https://jackstromberg.com/2013/02/how-to-validate-numeric-integer-input-in-c/


#include<stdio.h>
int main(void){
	// input	user input -- hopefully a number
	// temp		used to collect garbage characters
	// status	did the user enter a number?
	int input, temp, status;

	printf("Please enter a number: ");
	status = scanf("%d", &input);

	while(status!=1){
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input... please enter a number: ");
		status = scanf("%d", &input);
	}

	printf("Your number is %d\n", input);
	
	
	return 0;
}
