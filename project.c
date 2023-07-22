#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void morseToText(char *morse)
{
    char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                           "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                           "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
                           "---..", "----."};//morse codes of all alphabets and numbers(0-9)
    char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int len = strlen(morse);
    char buffer[100]; // buffer array to store the morse values
    int Index = 0;    // Indexing value for buffer (currently starts with 0)
    int i, j;
    for (i = 0; i < len; i++)
    {
        if (morse[i] == ' ' || morse[i] == '\t')//spacing between words are determined
        {
            buffer[Index] = '\0'; // Null-terminate the buffer to form a valid string
            Index = 0;        
            for (j = 0; j < 36; j++) // comparing to find the right match
            {
                if (strcmp(buffer, morseCode[j]) == 0)
                {
                    printf("%c", characters[j]); // print characters one after the other
                    break;
                }
            }
        }
        else
        {
            buffer[Index++] = morse[i];//incrementing of buffer index after storing the morse value 
        }
    }
    printf("\n");
}

// Function to convert plain text into Morse code
void textToMorse(char *text)
{
    char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                           "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                           "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
                           "---..", "----."};
    int len = strlen(text);
    int i, j;
    for (i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            printf(" "); // Print space for word separation
        }
        else if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= '0' && text[i] <= '9') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            j = ((text[i] >= 'A' && text[i] <= 'Z')) ? text[i] - 'A' : ((text[i] >= 'a' && text[i] <= 'z') ? text[i] - 'a' : text[i] - '0' + 26);//using of ternary operator to determine alphabet types and numeric value
            printf("%s ", morseCode[j]);
        }
    }
    printf("\n");
}

// Main programme with menu and fuction calls
void main()
{
    int choice;
    char text[100];
    printf("%c[4;3;35m\t\t\t\t\tWelcome to Morse Code Converter\n%c[0m",27,27);   
    do
    {
        printf("\n\t%c[4mMenu\n%c[0m\n",27,27);
        printf("1. Text to Morse code\n");
        printf("2. Morse code to Text\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer
        if (choice == 1)
        {
            printf("Enter the text: ");
            fgets(text, sizeof(text), stdin);
            printf("Morse Code: ");
            textToMorse(text);
        }
        else if (choice == 2)
        {
            printf("Enter Morse code (separate characters with spaces): ");
            fgets(text, sizeof(text), stdin);
            printf("Decoded Text: ");
            morseToText(text);
        }
        else if (choice == 3)
        {
            printf("%c[4;3;35m\t\t\tThank you for using our code, Hope to see you again soon :)\n%c[0m",27,27);   
            exit(0);
        }
        else
        {
            printf("Invalid choice :( \n");
        }
    } while (choice != 3); //continuation of loop until user decides to exit
}
