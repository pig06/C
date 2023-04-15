#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main()
{
    int n;
    int i;
    int cnt = 0;
    char name[MAX+1];
    memset(name, '\0' , sizeof(name));
    scanf("%d" , &n);
    scanf("%s" , name);
    if(n >= 4)
    {
        for (i = 0; i < n - 3; i++)
        {
            if (name[i] == 'p' && name[i+1] == 'P' && name[i+2] == 'A' && name[i+3] == 'p')
            {
               cnt++;
               i += 3;
            }
        }
        
    }
  
    printf("%d" , cnt);

    return 0;
}