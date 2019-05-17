#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf ("%d", &n);
    int map[n][n], i, j, temp = 0, ans[n-2][n-2];
    for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
            scanf ("%d", &map[i][j]);
        }
    }
    for (i = 0; i < n-2; i++){
        for (j = 0; j < n-2; j++){
            if (temp < map[i][j]) temp = map[i][j];
            if (temp < map[i][j+1]) temp = map[i][j+1];
            if (temp < map[i][j+2]) temp = map[i][j+2];
            if (temp < map[i+1][j]) temp = map[i+1][j];
            if (temp < map[i+1][j+1]) temp = map[i+1][j+1];
            if (temp < map[i+1][j+2]) temp = map[i+1][j+2];
            if (temp < map[i+2][j]) temp = map[i+2][j];
            if (temp < map[i+2][j+1]) temp = map[i+2][j+1];
            if (temp < map[i+2][j+2]) temp = map[i+2][j+2];
            ans[i][j] = temp;
            temp = 0;
        }
    }
    for (i = 0; i < n-2; i++){
        printf ("%d", ans[i][0]);
        for (j = 1; j < n-2; j++){
            printf (" %d", ans[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
