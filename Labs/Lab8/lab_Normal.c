/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : 08
 * Program : KMP
 * ********************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void replaceWordInText(const char *text, const char *oldWord, const char *newWord)
{
    int i = 0, cnt = 0;
    int len1 = strlen(newWord);
    int len2 = strlen(oldWord);
    char *newString = (char *)malloc(i + cnt * (len1 - len2) + 1);
    i = 0;
    while (*text)
    {
        if (strstr(text, oldWord) == text)
        {
            strcpy(&newString[i], newWord);
            i += len1;
            text += len2;
        }
        else
            newString[i++] = *text++;
    }
    printf("Resulting String: %s\n\n", newString);
}

int main()
{
    printf("\n*************************\n*  Name : Rajkumar B L  *\n*  Reg  : 2047120       *\n*  Lab  : 08            *\n*  Prg  : KMP           *\n*************************\n\n");

    char *result;
    char string[100], matchcase[20], replace[50], c;
    int i = 0, j = 0, index;

    /*Scanning string*/
    printf("Enter the sentence: ");
    do
    {
        fflush(stdin);
        c = getchar();
        string[i++] = tolower(c);

    } while (c != '\n');
    string[i - 1] = '\0';


    /*Scanning substring*/
    printf("Enter substring to be searched: ");
    i = 0;
    do
    {
        fflush(stdin);
        c = getchar();
        matchcase[i++] = tolower(c);
    } while (c != '\n');
    matchcase[i - 1] = '\0';

    printf("Enter the replacement substring: ");
    i = 0;
    do
    {
        fflush(stdin);
        c = getchar();
        replace[i++] = tolower(c);
    } while (c != '\n');
    replace[i - 1] = '\0';


    for (i = 0; i < strlen(string) - strlen(matchcase) + 1; i++)
    {
        index = i;
        if (string[i] == matchcase[j])
        {
            do
            {
                i++;
                j++;
            } while (j != strlen(matchcase) && string[i] == matchcase[j]);

            if (j == strlen(matchcase))
            {
                printf("Match found from position %d to %d.\n", index + 1, i);
                replaceWordInText(string, matchcase, replace);
                return 0;
            }
            else
            {
                i = index + 1;
                j = 0;
            }
        }
    }
    printf("No substring match found in the string.\n");

    return 0;
}