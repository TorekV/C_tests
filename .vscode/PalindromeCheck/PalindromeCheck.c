#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* str)
{
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - i - 1])
            return false;
    }

    return true;
}

void main()
{
    char ex1[] = "kekik";
    char ex2[] = "tenet";
    char ex3[] = "kek";
    char ex4[] = "yapay";
    char ex5[] = "kamalamak";
    char ex6[] = "tarik";

    int res1 = isPalindrome(ex1);
    int res2 = isPalindrome(ex2);
    int res3 = isPalindrome(ex3);
    int res4 = isPalindrome(ex4);
    int res5 = isPalindrome(ex5);
    int res6 = isPalindrome(ex6);

    printf("kekik = %d\n", res1);
    printf("tenet = %d\n", res2);
    printf("kek = %d\n", res3);
    printf("yapay = %d\n", res4);
    printf("kamalamak = %d\n", res5);
    printf("tarik = %d\n", res6);
}