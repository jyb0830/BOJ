//
//  painting_exchange.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/10.
//

#include <iostream>
#include <vector>
using namespace std;

int artist[15][15];
int visited[15][(1<<15)-1];
int N;


int dp(int current, int path, int price){
    int cnt=0;
    for(int i=0;i<N;i++){
        if(artist[current][i]>=price)
            cnt++;
    }
    if(cnt==0){
        for(int i=0;i<15;i++){
            if((i&path)!=0)
                cnt++;
        }
        visited[current][path]=cnt;
        return cnt;
    }
    
    if(visited[current][path]!=0)
        return visited[current][path];
    
    int result=0;
    
    for(int i=0;i<N;i++){
        if(((1<<i)&path)!=0||artist[current][i]<price)
            continue;;
        result=max(result, dp(current, path|(1<<i), artist[current][i]));
        
    }
    visited[current][path]=result;
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
