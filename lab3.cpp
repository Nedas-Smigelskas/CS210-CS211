#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;


bool is_prime(int x){
    if(x <= 1){
        return false;
    }
    for(int i = 2; i <= sqrt(x); i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num1, num2;
    int count = 0;
    cout << "Enter a number as start of range : " << endl;
    cin >> num1;
    cout << "Enter a number as end of range : " << endl;
    cin >> num2;
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i = num1; i <= num2; i++){
        if(is_prime(i)){
            count++;
        }
    }
    cout << count << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    return 0;
}