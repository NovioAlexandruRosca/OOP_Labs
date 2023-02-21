#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[255],moving_word[255];
    char tower[150][255];
    char *tkn;
    int i = 0;

    scanf("%[^\n]s",str);

    tkn = strtok(str, " ");

    while(tkn != NULL) {

       i++;
       strcpy(tower[i],tkn);
       tkn = strtok(NULL, " ");
   }

    int n = i;

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = i + 1 ; j <= n ; j++)
        {
            if(strlen(tower[i]) < strlen(tower[j]))
            {
                strcpy(moving_word,tower[i]);
                strcpy(tower[i],tower[j]);
                strcpy(tower[j],moving_word);
            }
            else if(strlen(tower[i]) == strlen(tower[j]))
            {
                int OK = 0;
                for(int k = 0 ; k < strlen(tower[i]) && OK == 0 ; k++)
                {
                    if(tower[i][k] < tower[j][k])
                    {
                       strcpy(moving_word,tower[i]);
                       strcpy(tower[i],tower[j]);
                       strcpy(tower[j],moving_word);
                       OK = 1;
                    }

                }
            }
        }

    }
    for(int i = 1 ; i <= n ; i++)
    {
     printf("%s \n",tower[i]);
    }

}
