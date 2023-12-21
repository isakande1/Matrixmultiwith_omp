#include<stdlib.h>
#include<omp.h>
#include<time.h>
#include<stdio.h>
int main(void) {
    int i = 0, j =0 ;

    int fmatrix [][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int **array = malloc(sizeof(int *) * 3);
    int **array2 = malloc(sizeof(int *) * 3);
    int *arr = malloc(sizeof(int) * 3);
    int *ar = malloc(sizeof(int) * 3);
    srand(time(0));
    for( j =0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            arr[i] = (rand() % 10) + 1;
            ar[i] = (rand() % 5) + 1;
        }
        array[j] = arr;
        array2[j] = ar;

    }
#pragma omp parallel
    {
        int x=0, y=0;
    int multi = 0;
    int inner = omp_get_thread_num();
    int outter = 0;
    int numt = omp_get_num_threads();
    for (outter = 0; outter < 3; outter++) {
        for (x = inner; x < 3; x += numt) {
            for (y = 0; y < 3; y++) {
                multi += array[y][x] * array2[outter][x];
            }
#pragma omp critical
            {
                fmatrix[outter][x] = multi;
            }
        }
    }
}
    for( j =0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            printf("%d  ", fmatrix[j][i]);
        }

    }
    printf("\n");
   /* for( j =0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            printf("%d  ", array2[j][i]);
        }
    }*/
return 0;
}
