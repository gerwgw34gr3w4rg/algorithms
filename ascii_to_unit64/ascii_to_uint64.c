



#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>


static const char *get_starting_point(const char *digits, bool *is_format_valid);


void ascii_to_uint64(const char *digits, uint64_t *number, bool *is_convertion_valid){
	/*
	* @brief Converts a string containing ASCII digits to an unsigned 64-bit integer.
	*           
	* This function scans the input string `digits` for a single valid subsequence of digits,
	* optionally preceded by a '+' sign, and converts it to a `uint64_t` value.
	*
	* @param digits
	*      A null-terminated ASCII string to be parsed.
	*      - May contain leading and trailing whitespace characters (' ', '\t', '\n').
	*      - Must contain exactly one valid subsequence of the form "(+)dd...d", where:
	*          - The '+' is optional.
	*          - The sequence must contain at least one digit.
	*      - The total string length must not exceed 1000 characters.
	*      - The digit sequence must represent a value that fits in a uint64_t.
	*
	* @param number
	*      A pointer to a `uint64_t` where the result of the conversion will be stored.
	*      - If the conversion is successful, the parsed number is written to this location.
	*      - On failure, 0 is written to this location.
	*
	* @param is_convertion_valid
	*      A pointer to a `bool` flag indicating success or failure of the conversion.
	*      - Set to `true` if conversion succeeds.
	*      - Set to `false` if:
	*          - No valid digit sequence is found.
	*          - More than one valid sequence is found.
	*          - The digit sequence causes an overflow.
	*          - The input exceeds 1000 characters.
	*
	* @note
	*      There is no return value. Results are communicated via the `number` and
	*      `is_convertion_valid` output parameters.
	*
	* @Examples:
	*      uint64_t number;
	*      bool is_convertion_valid;
	*		ascii_to_uint64("6709\n", &number, &is_convertion_valid);
	*		assert(is_convertion_valid == true);
	*      assert(number == 6709);
	*
	*		ascii_to_uint64("1 2 3", &number, &is_convertion_valid);
	*		assert(is_convertion_valid == false);
	*      assert(number == 0);
	*/
	if (NULL == digits){
	 	fprintf(stderr, "NULL POINTER ERROR: %s: %s(): line: %d\n",
	 	        __FILE__, __FUNCTION__, __LINE__ - 2);
	 	abort();
	}
	if (NULL == number){
 	 	fprintf(stderr, "NULL POINTER ERROR: %s: %s(): line: %d\n",
 	 	        __FILE__, __FUNCTION__, __LINE__ - 2);
 	 	abort();
 	}
	if (NULL == is_convertion_valid){
		fprintf(stderr, "NULL POINTER ERROR: %s: %s(): line: %d\n",
 	 	        __FILE__, __FUNCTION__, __LINE__ - 2);
 	 	abort();
 	}	
}


static const char *get_starting_point(const char *digits, bool *is_format_valid){
	/*
	* @brief Locates the start of a valid unsigned integer sequence within a string.
	*
	* This function scans the input string `digits` to find the beginning of a valid
	* numeric sequence, optionally preceded by a '+' character. Leading or trailing whitespace 
	* characters (' ', '\t', '\n') are ignored.
	*
	* @param digits
	*      A null-terminated ASCII string to be parsed.
	*      - May contain leading and trailing whitespace characters (' ', '\t', '\n').
	*      - Must contain exactly one contiguous numeric sequence, optionally prefixed by a '+'.
	*      - The string must not exceed 1000 characters in total length.
	*
	* @param is_format_valid
	*      A pointer to a `bool` where the format validation result will be stored:
	*      - Set to `true` if a valid subsequence is found and correctly formatted.
	*      - Set to `false` if the string does not match the required format.
	*
	* @return
	*      - A pointer to the beginning of the valid digit sequence (after any optional '+').
	*      - NULL if the input does not contain a valid sequence.
	*
	* @note
	*      This function does not modify the input string.
	*      If no valid numeric sequence is found, `is_format_valid` will be set to `false`.
	*
	* @examples
	*      bool is_format_valid;
	*
	*      char *start = get_starting_point("  +517\n", &is_format_valid);
	*      assert(is_format_valid == true);
	*      // 'start' points to '5'
	*
	*      char *start = get_starting_point("abc123", &is_format_valid);
	*      assert(is_format_valid == false);
	*      assert(NULL == start);
	*/
	if (NULL == digits){
		fprintf(stderr, "NULL POINTER ERROR: %s: %s(): line: %d\n",
				__FILE__, __FUNCTION__, __LINE__ - 2);
		abort();
	}
	if (NULL == is_format_valid){
		fprintf(stderr, "NULL POINTER ERROR: %s: %s(): line: %d\n",
				__FILE__, __FUNCTION__, __LINE__ - 2);
		abort();
	}
	bool is_plus_exits = false;
	*is_format_valid = true;
	char *digits_start = NULL;
	size_t i = 0;
	while (digits[i] != '\0'){
		if('+' == digits[i]){
			if(is_plus_exits == true){
				*is_format_valid = false;
				return NULL;
			}
			if('\0' == digits[i + 1]){
				is_format_valid = false;
			}
			if(digits[i + 1] >= '0' and digits[i + 1] <= '9'){
				is_plus_exits = true;
			}
			else {
				*is_format_valid = false;
				return NULL;
			}
		}
		if(digits[i] >= '0' and digits[i] <= '9'){
			if (NULL == digits_start){
				digits_start = (char *)digits + i;
			}
			else {
				*is_format_valid = false;
				return NULL;
			}
			while (digits[i] >= '0' and digits[i] <= '9'){
				i++;
			}			
		}
		else if (' ' == digits[i] or '\t' == digits[i] or '\n' == digits[i]){
			i++;
		}
		else {
			*is_format_valid = false;
			return NULL;
		}
	}
	const size_t STRING_SIZE_LIMIT = (size_t)1000;
	if (i > STRING_SIZE_LIMIT){
		*is_format_valid = false;
		return NULL;
	}
	if (NULL == digits_start){
		*is_format_valid = false;
		return NULL;
	}
	return (const char *)digits_start;
}
