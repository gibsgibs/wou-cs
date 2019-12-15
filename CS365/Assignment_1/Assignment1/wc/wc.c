#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
    I did NOT write this function. It was written by sehe on Stack overflow.
    I tried my best to get it to work, but despite my best efforts, it would not turn out.
    Source: https://stackoverflow.com/questions/12698836/counting-words-in-a-string-c-programming
*/
int words(const char sentence[ ])
{
    int counted = 0; // result

    // state:
    const char* it = sentence;
    int inword = 0;

    do switch(*it) {
        case '\0': 
        case ' ': 
        case '\t': 
        case '\n': 
        case '\r': // TODO others?
            if (inword) { inword = 0; counted++; }
            break;
        default: inword = 1;
    } while(*it++);

    return counted;
}

/*
    Function to check if the given array of the given 
    size contains the given element. 
    The element's location is returned.
*/
int contains(char** array, int size, char* element)
{
    for(int i = 1; i < size; i++)
    {
        if(strcmp(array[i], element) == 0)
        {
            return i; 
        }
    }
    return 0; 
}
/*
    Function to find the file in the array of arguments
    if it exists.
*/
FILE* findFile(char** array, int size)
{
    FILE* filePointer;

    for(int i = 1; i < size; i++)
    {
        filePointer = fopen(array[i], "r");

        if(filePointer != NULL)
        {
            return filePointer;
        }
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    int lineArgLoc = contains(argv, argc, "-l");

    int wordArgLoc = contains(argv, argc, "-w");
    
    int charArgLoc = contains(argv, argc, "-c");

    char* buffer= malloc(4096);
    
    FILE* filePointer = findFile(argv, argc);

    if(filePointer == NULL) //No file from user
    {
        printf("No file detected. Please enter text (ctrl + d to deliminate):\n");

        scanf("%[^D]s", buffer);
    }
    else //file from user
    {
        printf("File detected.\n");

        char current = fgetc(filePointer);

        int index = 0;

        while(current != EOF)
        {
            buffer[index] = current;

            current = fgetc(filePointer);

            index++;
        }
    }
    int numOfLines = 0;

    int numOfWords = words(buffer);

    int numOfChars = strlen(buffer);

    for(int i = 1; i < strlen(buffer); i++)
    {
        if(buffer[i] == '\n')
        {
            numOfLines++;
        }
        // if(buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
        // {
        //     numOfWords++;
        // }
    }

    if(lineArgLoc == 0 && wordArgLoc == 0 && charArgLoc == 0)
    {
        printf("There are %d new lines.\n", numOfLines);

        printf("There are %d words.\n", numOfWords);

        printf("There are %d characters.\n", numOfChars);
    }
    else
    {
        if(lineArgLoc != 0)
        {
            printf("There are %d new lines.\n", numOfLines);
        }
        if(wordArgLoc != 0)
        {
            printf("There are %d words.\n", numOfWords);
        }
        if(charArgLoc !=0)
        {
            printf("There are %d characters.\n", numOfChars);
        }
    }
    return 0;
}