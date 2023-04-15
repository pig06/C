#include <stdio.h>
#include <string.h> 

int main()
{
    char str[100 -1];
    int str_len;
    int i;
    int cnt_croatia = 0;

    scanf("%s", str);
    str_len = strlen(str);

    for (i = 0; i < str_len; i++)
    {   
        if (str[i] ==  'c')
        {
            if (str[i + 1] == '=')
            {
                cnt_croatia++;
                i++;
            }
            else if (str[i + 1] == '-')
            {
                cnt_croatia++;
                i++;
            }
            else cnt_croatia++;
        }

        else if (str[i] == 'd')
        {
            if (str[i + 1] == 'z')
            {
                if (str[i + 2] == '=')
                {
                    cnt_croatia++;
                    i += 2;
                }
                else
                {
                    cnt_croatia += 2;
                    i++;
                }
            }
            else if (str[i + 1] == '-')
            {
                cnt_croatia++;
                i++;
            }
            else cnt_croatia++;
        }

        else if (str[i] == 'l')
        {
            if (str[i + 1] == 'j')
            {
                cnt_croatia++;
                i++;
            }
            else cnt_croatia++;
        }

        else if (str[i] == 'n')
        {
            if (str[i + 1] == 'j')
            {
                cnt_croatia++;
                i++;
            }
            else cnt_croatia++;
        }

        else if (str[i] == 's')
        {
            if (str[i + 1] == '=')
            {
                cnt_croatia++;
                i++;
            }
            else cnt_croatia++;
        }
        
        else if (str[i] == 'z')
        {
            if (str[i + 1] == '=')
            {
                cnt_croatia++;
                i++;
            }
            else cnt_croatia++;
        }

        else cnt_croatia++;

    }
    printf("%d\n" , cnt_croatia);
    return 0;
}