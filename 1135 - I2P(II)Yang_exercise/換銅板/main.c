#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int value[7], amount[7];
int n;
void show() {
    int i;
    printf("(%d", amount[0]);
    for (i = 1; i < n; i++) {
        printf(",%d", amount[i]);
    }
    printf(")\n");
}

void change (int sum, int cur){
    if (sum == 0)
        show ();
    else if (sum > 0 && cur < n){
        change (sum, cur+1);

        amount[cur]++;
        change (sum - value[cur], cur);
        amount[cur]--;
    }
}
int main()
{
    int i, sum;
    scanf ("%d", &n);
    for (i = 0; i < n; i++){
        scanf ("%d", &value[i]);
    }
    scanf ("%d", &sum);
    memset (amount, 0, sizeof(amount));
    change (sum, 0);
    return 0;
}
