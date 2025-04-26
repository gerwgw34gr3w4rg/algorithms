



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

#include "ascii_to_unit64.c"


typedef struct{
    const char *digits;
    uint64_t number;
    bool is_convertion_valid;
} TestCase;



int main(){
    TestCase test_cases[] = {
        {.digits = "", .number = 0, .is_convertion_valid = false},
        {.digits = "123", .number = 123, .is_convertion_valid = true},
    };
    ascii_to_uint64(NULL, NULL, NULL); //abort
    for (size_t i = 0; i < 2; i++){
        uint64_t number = 150;
        bool is_convertion_valid;
        ascii_to_uint64(test_cases[i].digits, &number, &is_convertion_valid);
        assert(number == test_cases[i].number);
        assert(is_convertion_valid == test_cases[i].is_convertion_valid);
    }
}
