#include <iostream>
#include <cmath>
using namespace std;


int baseconversion(int b1, int b2, int n){
    int out = 0;
    int conv = 0;
    for(int i = 0; n > 0; i++){
        conv += (n%10)*pow(b1,i);
        n=n/10;
    }
    for(int i = 0; conv > 0; i++){
        out += conv%b2 * pow(10,i);
        conv=conv/b2;
    }
    return out;
}

int main(){
    int base1, base2, num;
    do {
        cin >> base1;
        cin >> base2;
        cin >> num;
        num = abs(num);
    } while (base1 < 2 || base1 > 32 && base2 < 2 || base2 > 32); 
    cout << baseconversion(base1,base2,num);
    return 0;
}