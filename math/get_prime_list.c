#include <stdlib.h>
#include <stdbool.h>

//find the prime number between 2 ~ n, and put the number of primes in 'len'
int* get_prime_list(int n, int* len) {
    bool *nums = (bool*)calloc(n + 1, sizeof(bool));
    *nums = *(nums + 1) = true;
    
    int cnt = n - 1;
    for (int i = 2; i * i <= n; i++)
        if (*(nums + i) == false)
            for (int j = i * i; j <= n; j += i)
                if (*(nums + j) == false){
                    *(nums + j) = true;
                    cnt--;
                }
    
    int *prime_list = (int*)calloc(cnt, sizeof(int));
    for (int i = 2; i <= n; i++)
        if (*(nums + i) == false)
            *(prime_list + (*len)++) = i;
    
    free(nums);
    return prime_list;
}