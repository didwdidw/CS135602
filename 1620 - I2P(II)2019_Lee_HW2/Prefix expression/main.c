#include <stdio.h>
#include <stdlib.h>

int cal (){
    char c = getchar();
    if (c == ' ')
        c = getchar();
    if (c == '+')
        return cal() + cal();
    else if (c == '-')
        return cal() - cal();
    else {
        ungetc(c, stdin);
        int ans;
        scanf ("%d", &ans);
        return ans;
    }
}

int main()
{
    printf ("%d", cal());
    return 0;
}
