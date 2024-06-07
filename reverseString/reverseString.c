#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    sSize = sSize - 1;
    for(int i = 0; i <= sSize/2; i++)
    {
        char temp = s[sSize - i];
        s[sSize - i] = s[i];
        s[i] = temp;
        
    }
}

void main()
{
    char exString[] = "pakito";

    reverseString(exString, strlen(exString));    

    printf("%s", exString);
}