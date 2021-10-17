// magic square 출력
#include <stdio.h>

int main(void){
    int size;
    int a, b;
    int number=1;
    int magicSquare[100][100]={0};

    printf("magic squar size(1보다 큰 홀수) : ");
    scanf("%d", &size);

    a = 0;
    b = size/2;
    while(number<=size*size){
        if(magicSquare[a][b]==0){
            magicSquare[a][b]=number;
            a--;
            b--;
        }else{
            a+=2;
            b++;
            magicSquare[a][b]=number;
            a--;
            b--;
        }
        if(a<0 && b<0){
            a+=2;
            b++;
        }
        if(a<0){
            a+=size;
        }
        if(b<0){
            b+=size;
        }
        number++;
    }
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%2d ", magicSquare[i][j]);
        }
        printf("\n");
    }

    return 0;
}