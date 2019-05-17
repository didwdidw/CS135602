#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dim;
    int value;
}Data;

int main()
{
    Data* l1 = (Data*)malloc(sizeof(Data)*100000);
    Data* l2 = (Data*)malloc(sizeof(Data)*100000);
    long long sum = 0;
    int i = 0, j = 0, length1 = 1, length2 = 1, v1, v2;
    scanf ("%d:%d", &v1, &v2);
    while (v1 && v2){
        length1 ++;
        l1[i].dim = v1;
        l1[i].value = v2;
        scanf ("%d:%d", &v1, &v2);
        i++;
    }
    i = 0;
    scanf ("%d:%d", &v1, &v2);
    while (v1 && v2){
        length2 ++;
        l2[i].dim = v1;
        l2[i].value = v2;
        scanf ("%d:%d", &v1, &v2);
        i++;
    }
    for (i = 0; i < length1; i++){
        for (j = 0; j < length2; j++){
            if (l1[i].dim == l2[j].dim){
                sum += l1[i].value * l2[j].value;
                break;
            }
        }
    }
    printf ("%lld\n", sum);
    return 0;
}
