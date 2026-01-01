#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n) {
    int index = 0;
    while(index != n){
        for(int i=index; i<n; i++){
            if(arr[i] < arr[index]){
                int temp = arr[index];
                arr[index] = arr[i];
                arr[i] = temp;
            }
        }
        index ++;
    }
}

int main() {
    FILE *fin = fopen("input.txt","r");
    if(!fin) return 1;

    int **lines = NULL;
    int lineCount = 0, cap = 2;
    lines = (int**)malloc(sizeof(int*) * cap);

    int n;
    while(fscanf(fin,"%d ->",&n) == 1) {
        if(lineCount >= cap) {
            cap *= 2;
            lines = (int**)realloc(lines,sizeof(int*)*cap);
        }

        int *arr = (int*)malloc(sizeof(int)*(n+2));
        arr[0] = n;
        int sum = 0;
        for(int i=1; i<=n ; i++) {
            fscanf(fin,"%d",&arr[i]);
            sum += arr[i];
        }
        arr[n+1] = sum;
        selectionSort(&arr[1],n);
        lines[lineCount++] = arr;
    }
    fclose(fin);

    for(int i=0; i< lineCount-1 ; i++) {
        for(int j=i+1;j<lineCount;j++) {
            int sum_i = lines[i][lines[i][0]+1];
            int sum_j = lines[j][lines[j][0]+1];
            if(sum_i > sum_j) {
                int *temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    FILE *fout = fopen("output.txt","w");
    if(!fout) return 1;

    for(int i=0; i< lineCount; i++) {
        int len = lines[i][0];
        for(int j=1;j<=len;j++) {
            fprintf(fout,"%d",lines[i][j]);
            if(j<len) fprintf(fout," ");
        }
        fprintf(fout,"\n");
        free(lines[i]);
    }
    free(lines);
    fclose(fout);
    return 0;
}
