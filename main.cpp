#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cctype>
using namespace std;
bool isinit(char a,string b){
    for(int i=0; i < b.length(); i++){
        if(a == b[i]){
            return true;
        }
    }
    return false;
}
void upper(string &a){
    for(int i=0;i<a.length(); i++){
        if(a[i] > 96){
            a[i] = toupper(a[i]);
        }
    }
}
int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand((int)time(0));
    vector<string> words;

    ifstream fin("words.txt"); //get words vector from txt
    string c;
    while(fin>>c){
        words.push_back(c);
    }
    fin.close();

    int randint = (rand() % words.size());
    string ans = words[randint];
    upper(ans);
    string guess;
    int guesscnt=0;
    cout << "Take a Guess:" << endl;
    while(true){
        cin >> guess;
        guesscnt++;
        upper(guess);
        if(guess.length() != 5){
            cout<< "Please give 5-letter word."<<endl;
        }
        else{
            for(int i=0 ; i < 5 ; i++){
                if(guess[i] == ans[i]){
                    SetConsoleTextAttribute(h,10);
                    cout<<guess[i];
                    SetConsoleTextAttribute(h,7);
                }
                else if(isinit(guess[i],ans)){
                    SetConsoleTextAttribute(h,14);
                    cout<<guess[i];
                    SetConsoleTextAttribute(h,7);
                }
                else{
                    SetConsoleTextAttribute(h,4);
                    cout<<guess[i];
                    SetConsoleTextAttribute(h,7);
                }
            }
        }
        cout<<endl;
        if(guess == ans){
            cout << "Congrats!! You found the word in " << guesscnt << " tries."<<endl;
            break;
        }
    }

    return 0;
}
