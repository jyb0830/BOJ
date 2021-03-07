//
//  palindrome.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/07.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n;
int memo[500][500];
int dp(int floor, int idx){
    if(floor==n-1) return v[floor][idx];
    
    else if(memo[floor][idx]!=0) return memo[floor][idx];
    
    else{
        int left_v=0, right_v=0;
        left_v=v[floor][idx]+dp(floor+1, idx);
        right_v=v[floor][idx]+dp(floor+1, idx+1);
        memo[floor][idx]=max(left_v, right_v);
        return memo[floor][idx];
    }
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++) v.push_back(vector<int>());
    
    for(int i=0;i<n;i++) {
        int num;
        for(int j=0;j<=i;j++){
            cin>>num;
            v[i].push_back(num);
        }
    }
    
    cout<<dp(0, 0)<<"\n";
    
    
    
    return 0;
}
