#include <stdio.h>
#include <stdlib.h>

int main(void){
    int row, col;
    printf("row, column 값 입력 > ");
    scanf("%d %d", &row, &col);

    int** arr = (int**)malloc(sizeof(int*)*col);
    for(int i=0; i<col; i++){
        arr[i] = (int*)malloc(sizeof(int)*row);
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j] = i+j;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}