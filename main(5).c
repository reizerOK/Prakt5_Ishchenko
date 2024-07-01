#include <stdio.h>

int main() {
    int n;

    printf("Введіть довжину послідовності n (1 < n < 10000): ");
    scanf("%d", &n);

    const int MOD = 12345;

    long long ending_with_0[n+1];
    long long ending_with_1[n+1];

    ending_with_0[1] = 1; 
    ending_with_1[1] = 1; 

    for (int i = 2; i <= n; i++) {
        ending_with_0[i] = (ending_with_0[i-1] + ending_with_1[i-1]) % MOD;
        ending_with_1[i] = ending_with_0[i-1];
    }

    long long result = (ending_with_0[n] + ending_with_1[n]) % MOD;

    printf("Кількість шуканих послідовностей за модулем %d: %lld\n", MOD, result);
    
    return 0;
}