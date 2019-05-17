#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int m, n, p, map[35][35], i, cur = 1, dir = 1, x = 1, y = 1;
    scanf ("%d%d%d", &m, &n, &p);
    memset (map, 0, sizeof(map));
    for (i = 0; i < m+2; i++){
        map[i][0] = 1;
        map[i][n+1] = 1;
    }
    for (i = 0; i < n+2; i++){
        map[0][i] = 1;
        map[m+1][i] = 1;
    }
    while (cur != p){
        map[y][x] = 1;
        if (dir == 1){
            if (map[y][x+1] != 1)
                x++;
            else {
                dir = 2;
                y++;
            }
        }
        else if (dir == 2){
            if (map[y+1][x] != 1)
                y++;
            else {
                dir = 3;
                x--;
            }
        }
        else if (dir == 3){
            if (map[y][x-1] != 1)
                x--;
            else {
                dir = 4;
                y--;
            }
        }
        else {
            if (map[y-1][x] != 1)
                y--;
            else {
                dir = 1;
                x++;
            }
        }
        cur ++;
    }
    printf ("%d %d\n", y, x);
    return 0;
}
