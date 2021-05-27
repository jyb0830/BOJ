//
//  greedy_panda.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/27.
//  acmicpc.net/problem/1937

#include <iostream>

using namespace std;

int n;

int forest[500][500];
int memo[500][500];
int r_move[4]={-1,0,1,0};
int c_move[4]={0,1,0,-1};


int dfs(int row, int col, int cnt){
    int possible=0;
    int max_cnt=cnt;
    for(int i=0;i<4;i++){
        if(row+r_move[i]>=0&&row+r_move[i]<n&&col+c_move[i]>=0 &&col+c_move[i]<n&&forest[row][col]<forest[row+r_move[i]][col+c_move[i]]){
            possible++;
            
            if(memo[row+r_move[i]][col+c_move[i]]!=0) max_cnt=max(max_cnt, cnt+memo[row+r_move[i]][col+c_move[i]]);
            
            else{
                max_cnt = max(max_cnt, cnt + dfs(row+r_move[i],col+c_move[i], 1));
            }
        }
    }
    if(possible==0) {
        memo[row][col]=1;
        return cnt;
    }
    
    else{
        memo[row][col]=max_cnt;
    }
    
    return max_cnt;
}

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>forest[i][j];
        }
    }
    
    int max_num=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            max_num = max(max_num, dfs(i,j,1));
        }
    }
    
    cout<<max_num<<"\n";
    
    return 0;
}
