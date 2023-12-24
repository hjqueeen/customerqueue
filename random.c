#include "random.h"
#include <stdlib.h>
#include <ctype.h>

void generateRandomName(char *name, int length) {
    // Define vowels and consonants
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            // Choose a consonant for even indices
            name[i] = consonants[rand() % (sizeof(consonants) - 1)];
        } else {
            // Choose a vowel for odd indices
            name[i] = vowels[rand() % (sizeof(vowels) - 1)];
        }
    }

    name[0] = toupper(name[0]); // Convert the first character to uppercase
    name[length] = '\0'; // Add null character at the end of the string
}