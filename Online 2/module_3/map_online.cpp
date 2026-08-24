#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    int a,b;
    if(s.size()==2){
        a = s[0]-'0';
        b = s[1]-'0';
    }
    else{
        a = s[0]-'0';
        b = s[0]-'0';
    }
    
    map<int,string> mp;
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";

    for(int i=a; i<b; i++){
        string first = mp[i];
        for(int j=a+1; j<=b; j++){
            string second = mp[j];
            for(auto x : first){
                for(auto y : second){
                    cout << x << y << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}