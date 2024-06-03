#include <stdbool.h>
#include <string.h>

bool isAnagram(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return false;
    int count[256] = {0};
    for (int i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}
void main()
{
    char ex1[] = "irak";
    char ex2[] = "arik";

    char ex3[] = "baba";
    char ex4[] = "kale";


    if(isAnagram(ex1, ex2))
    {
        printf("irak-arik = true %d\n", 1);
    }
    else
    {
        printf("irak-arik = false %d\n", 0);
    }

    if(isAnagram(ex3, ex4))
    {
        printf("baba-kale = true %d\n", 1);
    }
    else
    {
        printf("baba-kale = false %d\n", 0);
    }
}