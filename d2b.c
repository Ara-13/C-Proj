#include <stdio.h>

// آرش دوالی

int main() {
    int n;
    scanf("%d", &n);
    if(n==1 || n==0){
        printf("%d", n);
    }else{
        int i=1, result = 0;
        while( n >= 1){
            result += (n%2)*i;
            i = i*10;
            n = (int)(n/2);
        }
        printf("%d", result);
    }
    return 0;
}
