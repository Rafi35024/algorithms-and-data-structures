//https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start, vector<int> &finish) {
    int n = *max_element(finish.begin(), finish.end()) + 1;
    vector<bool> marked(n);
    vector<tuple<int,int,int>> vec(start.size());
    for(int i=0; i<start.size(); i++){
        vec[i] = {finish[i],finish[i]-start[i], start[i]};
    }
    sort(vec.begin(),vec.end());
    int cnt = 0;
    for(auto [x,y,z] : vec){
        bool flag = true;
        for(int i=z; i<=x; i++){
            if(marked[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i=z; i<=x; i++){
                marked[i] = true;
            }
            cnt++;
        }
    }
    return cnt;
}

int main() {

    


    return 0;
}