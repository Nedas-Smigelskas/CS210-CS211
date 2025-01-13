#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

#define CACHE_SIZE 1000000
ull cache[CACHE_SIZE] = {0};

ull sequence(ull n, ull steps){
    if(n < CACHE_SIZE && cache[n] != 0)
        return cache[n] + steps;
    
    if(n == 1){
        return steps;
    }
    if(n%2==0){
        return sequence(n/2, steps+1);
    } else {
        return sequence((n*3)+1, steps+1);
    }
}

int main(){
    ull count = 0;
    ull high = 0;
    ull low = 0;
    ull highest = 0;
    for(ull i = 880000000; i <= 900000000; i++){
        ull seq_len = sequence(i,0);
        if(i < CACHE_SIZE)
            cache[i] = seq_len;
        
        if(seq_len == sequence(i+1,0)){
            count++;
        } else {
            count = 0;
        }
        if(count >= high){
            high = count;
            low = i-count;
            highest = i;
        }
    }
    ull i = low;
    for(i; i <= highest; i++){
        printf("%lld\n", i);
    }
    printf("TOTAL: %lld", highest-low);

}
