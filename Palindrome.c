#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
// A constant macro defining the maximum length of the input string
#define MAX_LEN 100

// Function prototypes

// Reads a line of input into str, removes the newline character, and
// returns the length of the string.
//
// Parameters:
//   str: a character array where the input string will be stored
//   n: the maximum length of the input string, including the null character
//
// Returns:
//   The length of the input string, not including the null character.
int read_line(char str[], int n);

// Returns true if the given message is a palindrome, false otherwise.
//
// A palindrome is a word that reads the same backwards and forwards,
// such as "racecar".
//
// Parameters:
//will update
//   message: a null-terminated string to be checked for palindromicity
//
// Returns:
//   true if the message is a palindrome, false otherwise
bool is_palindrome(const char *message);

int main(void) {
  // An array to store the input string
  char str[MAX_LEN];

  // The length of the input string
  int len;

  // Read a line of input from the user
  printf("Enter a message: ");
  len = read_line(str, MAX_LEN);

  // Check if the input string is a palindrome
  if (is_palindrome(str)) {
    printf("Palindrome\n");
  } else {
    printf("Not a palindrome\n");
  }

  return 0;
}

// Reads a line of input into str, removes the newline character, and
// returns the length of the string.
int read_line(char str[], int n) {
  // A variable to store each character as it is read
  int ch;

  // An index variable to keep track of the position in the array
  int i = 0;

  // Read characters until a newline character is encountered
  while ((ch = getchar()) != '\n') {
    // If the array is not full, store the character in the array
    if (i < n) {
      str[i++] = ch;
    }
  }

  // Add a null character to the end of the string to mark the end
  // of the string
  str[i] = '\0';

  // Return the length of the string, not including the null character
  return i;
}

// Returns true if the given message is a palindrome, false otherwise.
bool is_palindrome(const char *message) {
  // The length of the message string
  int len = strlen(message);

  // Iterate over the characters in the message
  for (int i = 0; i < len / 2; i++) {
    // If the characters at the corresponding positions from the beginning
    // and end of the message differ, the message is not a palindrome
    if (message[i] != message[len - 1 - i]) {
      return false;
