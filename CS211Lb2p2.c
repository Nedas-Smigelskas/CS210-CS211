#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool attendance(char str[],int strlen, int index, int absents, int lates){
    if(str[index] == 'L'){
        lates++;
    } else {
        lates = 0;
    }
    if(str[index] == 'A'){
        absents++;
    }
    if(absents == 2){
        return false;
    }
    if(lates == 3){
        return false;
    }
    if(index > strlen){
        return true;
    }
    return attendance(str, strlen, index+=1, absents, lates);
}


int main(){
    int len;
    printf("String length :");
    scanf("%d", &len);
    char str[len];
    scanf("%s", str);
    if(!attendance(str,len,0,0,0)){
        printf("FAIL");
    } else {
        printf("PASS");
    }
    return 0;
}
