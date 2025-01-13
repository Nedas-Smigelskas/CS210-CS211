#include <iostream>
using namespace std;

int scrabblescore(string& word){
    int scrabblevalues[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int score = 0;
    for(char c : word){
        char letter = toupper(c);
        if(letter >= 'A' && letter <= 'Z'){
            score+=scrabblevalues[letter-'A'];
        }
    }
    return score;
}

bool compareWords(string &s1, string &s2){
    int score1 = scrabblescore(s1);
    int score2 = scrabblescore(s2);
    if(score1 == score2){
        return s1 < s2;
    }
    return score1 < score2;
}

int main(){
    int num;
    cin >> num;
    string scrabblearray[num];
    for(int i = 0; i < num; i++){
        cin >> scrabblearray[i];
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(!compareWords(scrabblearray[j], scrabblearray[j+1])){
                swap(scrabblearray[j],scrabblearray[j+1]);
            }
        }
    }
    for(int i = 0; i < num; i++){
        cout << scrabblearray[i] << endl;
    }

}