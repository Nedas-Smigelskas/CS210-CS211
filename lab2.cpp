#include <iostream>
using namespace std;

bool cardVerifier(string& cc){
    int out = 0;
    int j = 0;
    for(int i = cc.length()-1; i >= 0; i--){
        int num = cc[i] - '0';
        if(j % 2 == 0){
            out += num;
        } else {
            if(num*2 > 9){
                out+= ((num*2)-9);
            } else {
                out += num*2;
            }
        }
        j++;    
    }
    return (out%10==0);
}


int main(){
    string cc;
    cout << "Enter your credit card details : ";
    cin >> cc;
    while(cc.length()<4 || cc.length()>30){
        cout << "Invalid constraints try again : ";
        cin >> cc;
    }
    if(cardVerifier(cc)){
        cout << "VALID";
    } else {
        cout << "INVALID";
    }
    return 0;
}
