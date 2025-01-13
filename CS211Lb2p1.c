#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int payment(double total, double interest, double install)
{
    double monthlyinterest = (interest/12)/100;
    double topay = (total * (1 + monthlyinterest)) - install;
    if(topay <= 0){
        return 1;
    }
    return 1 + payment(topay,interest,install);
}

int main()
{
    int out = payment(250000, 3, 1600);
    printf("Time to pay off loan will be %d months", out);
    return 0;
}
