#include <stdio.h>
#include <unistd.h>
int main()
{  
    int i;
    int j;

    i = 1;
    j = 1;
    while (++i)
    {
        while (j)
        {
            j++;
            if (j == 10)
            {
                write(1, "@#-", 3);
                break;
            }
        }
    }
    return (0);
}
