#include <stdio.h>
#include <stdlib.h>

FILE *file;

void selectionSort(){

    file = fopen("C:\\Users\\Caio victor\\Desktop\\arquivoteste.txt", "r");

    int A[1000];

    for(int l = 0; l < 999; l++){
        fscanf(file, "%i ", &A[l]); 
    }
    fclose(file);

    int i_min, temp;
    for(int i = 0; i < 999 ; i++){
        i_min = i;
        for(int j = i + 1; j < 999 ; j++){
            if(A[j] < A[i_min]){
                i_min = j;
            }
        }
        if(i != i_min){
            temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        }
    }

    file = fopen("C:\\Users\\Caio victor\\Desktop\\arquivoteste.txt", "w");

    printf("[");
    for (int k = 0; k < 999; k++){
        printf("%i", A[k]);
        if(k != 998){
                printf(", ");
            }
        fprintf(file, "%d ", A[k]);
    }
    printf("]");
    fclose(file);
}

int main(int argc, char *argv[]){

    file = fopen("C:\\Users\\Caio victor\\Desktop\\arquivoteste.txt", "w");

    for (int i = 0; i < 999; i++){
        fprintf(file, "%i ",rand());
    }
    fclose(file);

    selectionSort();

    return 0;
}