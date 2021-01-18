//
//  painting_exchange.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/10.
//  acmicpc.net/problem/1029

#include <iostream>
#include <vector>
using namespace std;

int artist[15][15];
int visited[15][(1<<15)-1][10];
int N;


int dp(int current, int path, int price){
    int cnt=0;
    
    if(path==(1<<N)-1) return N;
    
    for(int i=0;i<N;i++){
        if(artist[current][i]>=price && ((1<<i)&path)==0)
            cnt++;
    }
    if(cnt==0){
        for(int i=0;i<N;i++){
            if((i&path)!=0)
                cnt++;
        }
        visited[current][path][price]=cnt;
        return cnt;
    }
    
    if(visited[current][path][price]!=0)
        return visited[current][path][price];
    
    int result=0;
    
    for(int i=0;i<N;i++){
        if(((1<<i)&path)!=0||artist[current][i]<price)
            continue;;
        result=max(result, dp(i, path|(1<<i), artist[current][i]));
    }
    visited[current][path][price]=result;
    return result;
}


int main(){
    cin>>N;
    char c;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>c;
            artist[i][j]=c-'0';
        }
    }
    
    cout<<dp(0,1,0);
    return 0;
}
