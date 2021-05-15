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

void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0; 
    int j = 0; 
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
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

    KMPSearch(matchcase, string);
    replaceWordInText(string, matchcase, replace);
    return 0;
}