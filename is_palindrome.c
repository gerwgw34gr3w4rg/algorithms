#include <stdbool.h>
#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>


size_t str_size(const char *str){
	/**
	* @brief Calculates the length of a null-terminated C string.
	*
	* This function returns the number of characters in the input string, 
	* excluding the null terminator (`'\0'`).
	*
	* If the input pointer is `NULL`, the function prints an error message 
	* to `stderr` indicating the file and line where the null pointer was detected,
	* and then terminates the program using `abort()`.
	*
	* @param str A pointer to a null-terminated C string.
	*
	* @return The number of characters in the string (not including the null terminator).
	*
	* @note This function is designed for ASCII or UTF-8 strings where characters are
	*       represented by single bytes. It does not support wide or multibyte characters.
	*
	* @warning Passing a NULL pointer will cause the program to terminate.
	*
	* @examples
	* str_size("Hello")         -> 5
	* str_size("")              -> 0
	* str_size("OpenAI GPT-4")  -> 12
	* str_size(NULL)            -> Program aborts with an error message
	*/
	if (NULL == str){
		fprintf(stderr, "Null pointer at %s: %d\n", __FILE__, __LINE__ - 1);
		abort();
	}
	size_t size = 0;
	for (size_t i = 0; str[i] != '\0'; i++){
		size++;
	}
	return size;
}


char to_lower(char ch){
	/**
	* @brief Converts an uppercase ASCII letter to its lowercase equivalent.
	*
	* This function takes a single character as input and returns its lowercase form
	* if the character is an uppercase English letter (i.e., 'A' to 'Z').
	* If the character is not an uppercase letter, it is returned unchanged.
	*
	* The conversion follows the ASCII standard, where uppercase letters 'A'-'Z' 
	* correspond to values 65–90 and lowercase letters 'a'-'z' correspond to 97–122.
	* The function converts by adding 32 ('a' - 'A') to the ASCII value of the uppercase letter.
	*
	* @param ch A character to convert.
	* 
	* @return The lowercase equivalent of the character if it is uppercase;
	*         otherwise, the original character.
	*
	* @examples
	* lower('A') -> 'a'
	* lower('Z') -> 'z'
	* lower('C') -> 'c'
	* lower('m') -> 'm'   // Already lowercase, returned unchanged
	* lower('9') -> '9'   // Not a letter, returned unchanged
	* lower('!') -> '!'   // Punctuation, returned unchanged
	*/
	if (ch >= 'A' and ch <= 'Z'){
		return ch + 'a' - 'A';
	}
	return ch;
}


bool is_alpha(char ch){
	/**
	* @brief Determines whether a character is an ASCII alphabetic letter.
	*
	* This function checks whether the given character is an English letter,
	* either uppercase ('A'–'Z') or lowercase ('a'–'z'), based on its ASCII value.
	*
	* The ASCII values checked are:
	*   - Uppercase letters: 65 ('A') to 90 ('Z')
	*   - Lowercase letters: 97 ('a') to 122 ('z')
	*
	* Any other character, including digits, punctuation, or special symbols, 
	* is considered non-alphabetic and will return false.
	*
	* @param ch The character to evaluate.
	*
	* @return true if the character is an ASCII alphabetic letter; false otherwise.
	*
	* @examples
	* is_alpha('A') -> true
	* is_alpha('z') -> true
	* is_alpha('M') -> true
	* is_alpha('5') -> false   // Digit
	* is_alpha('#') -> false   // Symbol
	* is_alpha(' ') -> false   // Whitespace
	*/
	if (ch >= 'A' and ch <= 'Z' or ch >= 'a' and ch <= 'z'){
		return true;
	}
	return false;
}


bool is_palindrome(const char *str){
	/*
	* @brief Determines whether a given input string is a palindrome.
	*
	* A palindrome is a sequence that reads the same forward and backward.
	* This function checks if the input string meets that criterion with the following considerations:
	*
	* - The comparison is case-insensitive; uppercase and lowercase letters are treated the same.
	* - Only alphabetic letters (A-Z, a-z) are considered in the comparison.
	* - Non-letter characters (e.g., digits, punctuation, whitespace) are ignored.
	* - An empty string is considered a not valid palindrome.
	*
	* Example cases:
	*   is_palindrome("A Santa at NASA")           -> true
	*   is_palindrome("Madam, I'm Adam!")          -> true
	*   is_palindrome("8975798")                   -> false
	*   is_palindrome("Madam Palindrome")          -> false
	*	is_palindrome("")                          -> false
	*
	* @param str A null-terminated C string (const char *) to be evaluated.
	*            The input is assumed to be no longer than 100 characters.
	*
	* @return true if the input string is a palindrome under the rules above,
	*         false otherwise.
	*/
	if (NULL == str){
		fprintf(stderr, "Null pointer at %s: %d\n", __FILE__, __LINE__ - 1);
		abort();
	}
	if ('\0' == str[0]){
		return false;
	}
	
    bool has_letter = false;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i])) {
            has_letter = true;
            break;
        }
    }
    
    if (not has_letter) {
        return false;
    }

    size_t left = (size_t)0;
    size_t right = str_size(str) - (size_t)1;
    while (left < right) {
        while (left < right and not is_alpha(str[left])) {
            left++;
        }
        while (left < right and not is_alpha(str[right])) {
            right--;
        }
        if (to_lower(str[left]) != to_lower(str[right])) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}
