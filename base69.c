#include <stdio.h>
#include <stdlib.h>
#include "base69.h"
#include <string.h>

// Base69 alphabet
const char *base69_alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/=@*-!#";

// Reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Base69 encoder
void encode_base69(int input, char *output) {
    int remainder;
    int index = 0;
    char tempBuffer[input]; // Assuming a maximum length for the encoded string

    // Add prefix "69*|"
    strcpy(output, "69*|");
    int prefixLength = strlen(output);

    while (input > 0) {
        remainder = input % 70;
        input /= 70;
        tempBuffer[index++] = base69_alphabet[remainder];
    }

    tempBuffer[index] = '\0'; // Null-terminate the temporary buffer
    reverseString(tempBuffer); // Reverse the encoded string

    strcat(output, tempBuffer); // Concatenate the reversed string to the output after the prefix
}

