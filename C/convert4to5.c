//Eric Kyle Salas and Jacob Wilks
//Program 1 - Convert message to 4B/5B and binary


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Table used to convert 4 bit values to 5 bit values
char *lookup_table[] = { "11110", "01001", "10100", "10101", "01010",
    "01011", "01110", "01111", "10010", "10011", "10110", "10111", "11010",
        "10011", "11100", "11101"};

//Takes the 4 bit value and returns a 5 bit value according to lookup_table
char *convert4Bto5B(char *a) {
    int temp;
    temp = (int) strtol(a, NULL, 2);
    return lookup_table[temp];
}

//Takes the users input and converts the message to binary
void convert_binary(char a, char *b, char *c) {
    int i;
    for (i=3; i>=0; i--) {
        b[3-i] = (char)(((a >> (i + 4)) & 1) + '0');
        c[3-i] = (char)(((a >> i) & 1) + '0');
    }
}
//Main function - Calls the convert functions from above
int main () {

    int msg_len;
    int i;
    char *userInput;
    char (*bArray)[5];
    size_t nbytes = 256;

    printf ("> Please enter a message you want encoded:\n");

    //error messages to terminate program if input is incorrect
    if ((msg_len = getline(&userInput, &nbytes, stdin)) < 0) {
        exit(EXIT_FAILURE);
    }
    if (!(bArray = malloc(2*msg_len*5))) {
        exit(EXIT_FAILURE);
    }

//Function call to convert to binary and display the binary numbers
    for (i = 0; i < msg_len; i++){
        convert_binary(userInput[i], bArray[i*2], bArray[(i*2)+1]);
      }

    printf("> your message %sin binary: ", userInput);
    for (i = 0; i < 2*(msg_len-1); i++) {
        printf("%s", bArray[i]);
      }

//Function call to take the array of binary numbers and convert to 4b/5b
    printf("\nyour message using 4B/5B: ");
    for (i = 0; i < 2*(msg_len-1); i++) {
        printf("%s", convert4Bto5B(bArray[i]));
      }
    printf("\n");
    return 0;
}
