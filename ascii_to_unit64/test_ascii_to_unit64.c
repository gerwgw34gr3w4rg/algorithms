



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

#include "ascii_to_unit64.c"


#define STRING_OF_1000_LETTERS "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678900"

typedef struct{
    const char *digits;
    uint64_t number;
    bool is_convertion_valid;
} TestCase;



int main(){
    TestCase test_cases[] = {
        //Invalid cases
        {.digits = "", .number = 0, .is_convertion_valid = false},
        {.digits = " ", .number = 0, .is_convertion_valid = false},
        {.digits = "145 51451 15", .number = 0, .is_convertion_valid = false},
        {.digits = "+", .number = 0, .is_convertion_valid = false},
        {.digits = "\n\n-1234\n", .number = 0, .is_convertion_valid = false},
        {.digits = "wef3ifn4 !whsiio? wihjnbk346543562", .number = 0, .is_convertion_valid = false},
        {.digits = "78234213137829837899011345", .number = 0, .is_convertion_valid = false},
        {.digits = "+9", .number = 0, .is_convertion_valid = false},
        {.digits = "", .number = 0, .is_convertion_valid = false},
        //Valid cases
        {.digits = "0", .number = (uint64_t)0, .is_convertion_valid = true},
        {.digits = "+0", .number = (uint64_t)0, .is_convertion_valid = true},
        {.digits = "123", .number = (uint64_t)123, .is_convertion_valid = true},
        {.digits = "12123123123", .number = (uint64_t)12123123123, .is_convertion_valid = true},
        {.digits = "+12123123123", .number = (uint64_t)12123123123, .is_convertion_valid = true},
        {.digits = "   \t   \n  0 \t  \t   \n", .number = (uint64_t)0, .is_convertion_valid = true},
        {.digits = "0", .number = (uint64_t)0, .is_convertion_valid = true},
        {.digits = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 +17                                                                                                                                                                                                                                                                                                                                                 \n", .number = (uint64_t)17, .is_convertion_valid = true},
        {.digits = "0000015", .number = (uint64_t)15, .is_convertion_valid = true},
    };
    size_t test_cases_size = sizeof(test_cases) / sizeof(test_cases[0]);


    for (size_t i = 0; i < test_cases_size; i++){
        uint64_t number = 150;
        bool is_convertion_valid;
        ascii_to_uint64(test_cases[i].digits, &number, &is_convertion_valid);
        assert(number == test_cases[i].number);
        assert(is_convertion_valid == test_cases[i].is_convertion_valid);
    }

    uint64_t n;
    bool flag;
    //ascii_to_uint64(NULL, NULL, NULL); //abort
    // ascii_to_uint64("", NULL, NULL); //abort
    // ascii_to_uint64("", &n, NULL); //abort
    // ascii_to_uint64("", NULL, &flag); //abort
    // ascii_to_uint64(NULL, &n, NULL); //abort
    // ascii_to_uint64(NULL, &n, &flag); //abort
    // ascii_to_uint64(NULL, NULL, &flag); //abort
}
