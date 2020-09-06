/*
	A console application that takes a number and 
	checks whether it belongs to the Fibonacci sequence.
	If yes, the app outputs its index.
	If no, the app prints a message.
*/

#include <stdio.h>
#include <math.h>

typedef enum {
	true,
	false
} FLAG;

FLAG fib_bool = false;

unsigned int validate_input(void);
unsigned int calc_fib_index(unsigned int user_int);

int main(void)
{
	unsigned int user_int = validate_input();

	unsigned int fib_index = calc_fib_index(user_int);

	if (fib_bool == true) {
		printf("%s%u\n", "This is a Fibonacci number. Its index is: ", fib_index);
	} else {
		printf("%s\n", "This is not a Fibonacci number.");
	}
}

unsigned int calc_fib_index(unsigned int user_int)
{
	unsigned int previous_fib_number = 0;
	unsigned int current_fib_number = 1;
	unsigned int fib_result = 1;
	unsigned int index = 0;

	if (0 == user_int) {
		fib_bool = true;
		return index;
	}

	for (index = 1; index > 0; index++) {

		if (fib_result == user_int) {
			fib_bool = true;
			return index;
			break;
		} else if (fib_result > user_int) {
			break;
		}

		fib_result = current_fib_number + previous_fib_number;
		previous_fib_number = current_fib_number;
		current_fib_number = fib_result;
	}
}

unsigned int validate_input(void)
// ensures the input is 0 or a natural number
{
	int input;
	do {
        printf("%s", "Provide a natural number: ");
        scanf("%d", &input);
    } while (input < 0);
}
