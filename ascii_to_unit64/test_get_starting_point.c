



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "ascii_to_uint64.c"


#define STRING_OF_1000_LETTERS "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678900"


typedef struct{
    const char *digits;
    const char *digits_start;
    bool is_format_valid;
} TestCase;



int main(){
    TestCase test_cases[] = {
        //Invalid cases
        {.digits = "", .digits_start = 0, .is_format_valid = false},
        {.digits = " ", .digits_start = 0, .is_format_valid = false},
        {.digits = "145 51451 15", .digits_start = 0, .is_format_valid = false},
        {.digits = "+", .digits_start = 0, .is_format_valid = false},
        {.digits = "\n\n-1234\n", .digits_start = 0, .is_format_valid = false},
        {.digits = "wef3ifn4 !whsiio? wihjnbk346543562", .digits_start = 0, .is_format_valid = false},
        {.digits = "+9", .digits_start = 0, .is_format_valid = false},
        //Valid cases
        {.digits = "78234213137829837899011345",
   .digits_start = "78234213137829837899011345" + 0, .is_format_valid = true},
   
        {.digits = "0",
   .digits_start = "0" + 0, .is_format_valid = true},

        {.digits = "+0",
   .digits_start = "+0" + 1, .is_format_valid = true},

        {.digits = "123",
   .digits_start = "123" + 0, .is_format_valid = true},

        {.digits = "12123123123",
   .digits_start = "12123123123" + 0, .is_format_valid = true},

        {.digits = "   \t   \n  0 \t  \t   \n",
   .digits_start = "   \t   \n  0 \t  \t   \n" + 30, .is_format_valid = true},

        {.digits = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          +17                                                                                                                                                                                                                                                                                                                                                 \n",
   .digits_start = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          +17                                                                                                                                                                                                                                                                                                                                                 \n" + 474, .is_format_valid = true},
        
        {.digits = "0000015",
   .digits_start = "0000015" + 0, .is_format_valid = true},
        
    };
    size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);                                                                                       

     for (size_t i = 0; i < test_cases_size; i++){
          bool is_format_valid;
          const char *digits_start = get_starting_point(test_cases[i].digits, &is_format_valid);
          if (digits_start != test_cases[i].digits_start
                    or is_format_valid != test_cases[i].is_format_valid){
               fprintf(stderr, "test case № %d failed\n", (int)i);
               fprintf(stderr, "digits:|%s|\n", test_cases[i].digits);
               fprintf(stderr, "Expected output: |%s|\n", digits_start);
               fprintf(stderr, "is_format_valid = %d\n", is_format_valid);
          }
          assert(digits_start == test_cases[i].digits_start);
          assert(is_format_valid == test_cases[i].is_format_valid);
          
     }
//     bool is_format_valid;
//     get_starting_point(NULL, &is_format_valid); //abort+
//     get_starting_point("328698451", NULL); //abort+
     printf("\n%s done!\n", __FILE__);
}
