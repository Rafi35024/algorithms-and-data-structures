#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<tuple<int,int,string>> vec(n);
    tuple<string,int,int> t;
    for(int i=0; i<n; i++){
        cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
        vec[i] = {get<2>(t),get<1>(t),get<0>(t)};
    }
    sort(vec.begin(),vec.end());
    vector<tuple<int,int,string>> ans;
    int prev_end = 0;
    for(auto [end,start,course] : vec){
        if(start>=prev_end){
            ans.push_back({end,start,course});
            prev_end = end;
        }
    }
    for(auto [x,y,z] : ans) cout << z << endl;


    return 0;
}