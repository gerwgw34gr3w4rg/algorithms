



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "ascii_to_uint64.c"


#define STRING_MORE_THAN_1000_LETTERS "023456789012345678902234567890323456789042345678905234567890623456789072345678908234567890923456789002345678901234567890223456789032345678904234567890523456789062345678907234567890823456789092345678900234567890123456789022345678903234567890423456789052345678906234567890723456789082345678909234567890023456789012345678902234567890323456789042345678905234567890623456789072345678908234567890923456789002345678901234567890223456789032345678904234567890523456789062345678907234567890823456789092345678900234567890123456789022345678903234567890423456789052345678906234567890723456789082345678909234567890023456789012345678902234567890323456789042345678905234567890623456789072345678908234567890923456789002345678901234567890223456789032345678904234567890523456789062345678907234567890823456789092345678900234567890123456789022345678903234567890423456789052345678906234567890723456789082345678909234567890023456789012345678902234567890323456789042345678905234567890623456789072345678908234567890923456789002345678901234567890223456789032345678904234567890523456789062345678907234567890823456789092345678900234567890123456789022345678903234567890423456789052345678906234567890723456789082345678909234567890"
#define LONG_VALID_STRING "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    +17                 \n"


typedef struct {
	const char *digits;
	const char *digits_start; 
	bool is_format_valid;
} TestCase;


int main(){
	TestCase test_cases[] = {
		// Invalid cases
		{.digits = "",				.digits_start = NULL, .is_format_valid = false},
		{.digits = " ",				.digits_start = NULL, .is_format_valid = false},
		{.digits = "145 51451 15", 	.digits_start = NULL, .is_format_valid = false},
		{.digits = "+", 			.digits_start = NULL, .is_format_valid = false},
		{.digits = "\n\n-1234\n", 				.digits_start = NULL, .is_format_valid = false},
		{.digits = "abvvb !afgag? afgag\n", 	.digits_start = NULL, .is_format_valid = false},
		{.digits = "123abc", 		.digits_start = NULL, .is_format_valid = false},
		{.digits = "+++9",					.digits_start = NULL, .is_format_valid = false},
		{.digits = "____0",					.digits_start = NULL, .is_format_valid = false},
		{.digits = STRING_MORE_THAN_1000_LETTERS,	.digits_start = NULL, .is_format_valid = false},

		// Valid cases
		{.digits = "\n\n\n\n51874651987410875410175     ",
   .digits_start = "\n\n\n\n51874651987410875410175     " + 4, .is_format_valid = true},
   
		{.digits = "0", .digits_start = "0", .is_format_valid = true},
		{.digits = "0000015", .digits_start = "0000015", .is_format_valid = true},
		{.digits = "+0", .digits_start = "+0" + 1, .is_format_valid = true},
		{.digits = "123", .digits_start = "123", .is_format_valid = true},
		{.digits = "12123123123", .digits_start = "12123123123", .is_format_valid = true},
		{.digits = "+12123123123", .digits_start = "+12123123123" + 1, .is_format_valid = true},
		{.digits = "   \t\t  \n 0  \n\t ",
   .digits_start = "   \t\t  \n 0  \n\t " + 9, .is_format_valid = true},
   
		{.digits = LONG_VALID_STRING, .digits_start = LONG_VALID_STRING + 485, .is_format_valid = true},
	};


	size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < test_cases_size; i++){
		const char *digits_start = get_starting_point(test_cases[i].digits);
		if (digits_start != test_cases[i].digits_start){
			fprintf(stderr, "test case N %zu failed\n", i);
			fprintf(stderr, "digits:|%s|\n", test_cases[i].digits);
			fprintf(stderr, "Expected output:|%s|\n", digits_start);
		}
		assert(digits_start == test_cases[i].digits_start);
	}
	
	// get_starting_point(NULL);  // abort

	printf("\n%s done!\n", __FILE__);
}
