#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


static char *get_starting_point(const char *digits, bool *is_format_valid);


void ascii_to_uint64(const char *digits, uint64_t *number, bool *is_convertion_valid){
    /*
    @brief Converts a string containing ASCII digits to an unsigned 64-bit integer.*
        This function scans the input string digits for a single valid subsequence of digits,
        optionally preceded by a '+' sign, and converts it to a uint64_t value.*
    @param digits
        A null-terminated ASCII string to be parsed.
        May contain leading and trailing whitespace characters (' ', '\t', '\n').
        Must contain exactly one valid subsequence of the form "(+)dd...d", where:
        The '+' is optional.
        The sequence must contain at least one digit.
        The total string length must not exceed 1000 characters.
        The digit sequence must represent a value that fits in a uint64_t.
    @param number
        A pointer to a uint64_t where the result of the conversion will be stored.
        If the conversion is successful, the parsed number is written to this location.
        On failure, 0 is written to this location.
        
    @param is_convertion_valid
        A pointer to a bool flag indicating success or failure of the conversion.
        Set to true if conversion succeeds.
        Set to false if:
        No valid digit sequence is found.
        More than one valid sequence is found.
        The digit sequence causes an overflow.
        The input exceeds 1000 characters.
        
    @note
        There is no return value. Results are communicated via the number and
        is_convertion_valid output parameters.
        
    @Examples:
        uint64_t number;
        bool is_convertion_valid;
        ascii_to_uint64("6709\n", &number, &is_convertion_valid);
        assert(is_convertion_valid == true);
        assert(number == 6709);
        
        ascii_to_uint64("1 2 3", &number, &is_convertion_valid);
        assert(is_convertion_valid == false);
        assert(number == 0);
    */
    if (NULL == digits){
        fprintf(stderr, "NULL pointer error: %s: %s(): Line:%d\n", __FILE__, __FUNCTION__, __LINE__ -1);
        abort();
    }
    if (NULL == number){
        fprintf(stderr, "NULL pointer error: %s: %s(): Line:%d\n", __FILE__, __FUNCTION__, __LINE__ -1);
        abort();
    }
    if (NULL == is_convertion_valid){
        fprintf(stderr, "NULL pointer error: %s: %s(): Line:%d\n", __FILE__, __FUNCTION__, __LINE__ -1);
        abort();
    }
}


static char *get_starting_point(const char *digits, bool *is_format_valid){
    /*
    @param digits
        A null-terminated ASCII string to be parsed.
        May contain leading and trailing whitespace characters (' ', '\t', '\n').
        Must contain exactly one valid subsequence of the form "(+)dd...d", where:
        The '+' is optional.
        The sequence must contain at least one digit.
        The total string length must not exceed 1000 characters.

    @param is_format_valid
        A pointer to a bool flag indicating success or failure of the conversion.
        Set to true if conversion succeeds.
        Set to false if:
        No valid digit sequence is found.
        More than one valid sequence is found.
        The digit sequence causes an overflow.
        The input exceeds 1000 characters.
    
    @Examples
        bool is_format_valid;
        char *digits_begin = get_starting_point("517\n", &is_format_valid);
        assert(true == is_format_valid);

        bool is_format_valid;
        char *digits_begin = get_starting_point("aswiusiuhiuh", &is_format_valid);
        assert(false == is_format_valid);
    */

    return NULL;
}