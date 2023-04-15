#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000000];
    int len_s;
    int answer;
    int cnt_toggle = 0;
    int cnt_0_to_1 = 0;
    int cnt_1_to_0 = 0;
    int i;

    scanf("%s" , s);
    len_s = strlen(s);

    for (i = 1; i < len_s; i++)
    {
        if(i == 1 && s[0] == '1'){
            cnt_1_to_0++;
        }
        else if (s[i - 1] == '0' && s[i] == '1')
        {
            cnt_1_to_0++;
        }    
        if (i == 1 && s[0] =='0')
        {
            cnt_0_to_1++;
        }
        else if (s[i - 1] == '1' && s[i] == '0')
        {
            cnt_0_to_1++;
        }    
    }
    answer = cnt_0_to_1 > cnt_1_to_0 ? cnt_1_to_0 : cnt_0_to_1;
    printf("%d\n ", answer);
    return 0;
}