#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int map[15][15];
int m, n, queenNum, castleNum, total = 0;

int queenvalid (int row, int col){
    int i, y = row, x = col;
    for (i = 0; i < row; i++){
        if (map[i][col] != 0)
            return 0;
    }
    while (y > 0 && x > 0){
        if (map[y-1][x-1] != 0)
            return 0;
        y--;
        x--;
    }
    y = row;
    x = col;
    while (y > 0 && x < m+n){
        if (map[y-1][x+1] != 0)
            return 0;
        y--;
        x++;
    }
    return 1;
}
int castlevalid (int row, int col){
    int i, y = row, x = col;
    for (i = 0; i < row; i++){
        if (map[i][col] != 0)
            return 0;
    }
    while (y > 0 && x > 0){
        if (map[y-1][x-1] == 1)
            return 0;
        y--;
        x--;
    }
    y = row;
    x = col;
    while (y > 0 && x < m+n){
        if (map[y-1][x+1] == 1)
            return 0;
        y--;
        x++;
    }
    return 1;
}

void set (int row){
    if (row == m+n) total ++;
    else {
    int i;
    for (i = 0; i < m+n; i++){
        if (queenvalid(row, i) && queenNum > 0){
            map[row][i] = 1;
            queenNum --;
            set (row + 1);
            queenNum ++;
            map[row][i] = 0;
        }
        if (castlevalid(row, i) && castleNum > 0){
            map[row][i] = 2;
            castleNum --;
            set (row + 1);
            castleNum ++;
            map[row][i] = 0;
        }
    }
    }
}

int main()
{
    scanf ("%d%d", &m, &n);
    queenNum = m;
    castleNum = n;
    memset (map, 0, sizeof(map));
    set (0);
    printf ("%d\n", total);
    return 0;
}
