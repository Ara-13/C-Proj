#include <stdio.h>

//آرش دوالی

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0 || n == 1) {
        printf("%d", n);
    }else{
    
    long long result = 0;
    long long i = 1;
    
    while (n > 0) {
        result += (n % 2) * place;
        i = i * 10;
        n = n / 2;
    }
    printf("%lld", result);
    }
    return 0;
}
