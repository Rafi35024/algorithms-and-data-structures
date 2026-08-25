//https://www.geeksforgeeks.org/problems/attend-all-meetings/1
#include <bits/stdc++.h>
using namespace std;

bool canAttend(vector<vector<int>> &arr) {
    vector<bool> marked;
    bool flag = true;
    for(int i=0; i<arr.size(); i++){
        if(marked.size()<=arr[i][1]) marked.resize(arr[i][1]+1);
        for(int j = arr[i][0]; j<arr[i][1]; j++){
            if(!marked[j]) marked[j] = true;
            else{
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {

    


    return 0;
}
