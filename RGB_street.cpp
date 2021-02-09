//
//  RGB_stree.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/09.
//  acmicpc.net/problem/1149

#include <iostream>
using namespace std;

int n;
int rgb[1000][3];
int memo[1000][3];
int dp(int num, int pre_color){
    if(num==n-1){
        int min_num=1001;
        for(int i=0;i<3;i++){
            if(i==pre_color) continue;
            else min_num=min(min_num, rgb[num][i]);
        }
        return min_num;
    }
    
    int min_num=1<<20;
    for(int i=0;i<3;i++){
        if(i==pre_color) continue;
        
        if(memo[num][i]) min_num=min(min_num, memo[num][i]);
        else{
            memo[num][i]=dp(num+1, i)+rgb[num][i];
            min_num=min(min_num, memo[num][i]);
        }
    }
    return min_num;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>rgb[i][j];
        }
    }
    
    cout<<dp(0,-1)<<"\n";
    
    return 0;
}
