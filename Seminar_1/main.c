#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* ptr;
    char str[50];
    int number,sum = 0,power,val;
    int lenght;
    ptr = fopen("new.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    while (fgets(str, 50, ptr) != NULL) {

    if(str[strlen(str) - 1] == '\n')
        lenght = strlen(str) - 2;
    else
        lenght = strlen(str) - 1;

    number = 0;
    power = 1;
    for(int i = lenght ; i >= 0 ; i--)
    {
        val = str[i] - '0';
        number = number + power * val;
        power = power * 10;

    }

    sum = sum + number;

    }

    printf("%d",sum);

    fclose(ptr);
    return 0;
}
