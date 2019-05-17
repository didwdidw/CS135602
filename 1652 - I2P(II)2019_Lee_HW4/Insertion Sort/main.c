#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, t, swap = 0, i, j;
    scanf ("%d", &t);
    while (t--){
        scanf ("%d", &n);
        int seq[n];
        for (i = 0; i < n; i++){
            scanf ("%d", &seq[i]);
            for (j = i; j > 0; j--){
                if (seq[j] < seq[j-1]){
                    int temp = seq[j];
                    seq[j] = seq[j-1];
                    seq[j-1] = temp;
                    swap++;
                }
                else
                    break;
            }
        }
    }
    printf ("%d\n", swap);

    return 0;
}
