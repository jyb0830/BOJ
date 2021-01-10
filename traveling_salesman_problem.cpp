//
//  traveling_salesman_problem.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/10.
//  acmicpc.net/problem/2098

#include <iostream>

using namespace std;
int map[16][16];
int cost[16][1<<16];
int N,min_cost=16000001;
int min(int a, int b){
    return a>b?b:a;
}

int dfs(int start,int path){
    if(path==(1<<N)-1){
        if(map[start][0]!=0)
            min_cost = min(min_cost, cost[start][path] + map[start][0]);
    }
    for(int i=0;i<N;i++){
        if(((1<<i)&path)==0){       //지나치지 않은 도시일 때
            if(cost[i][path+(1<<i)]==0) //
                cost[i][path+(1<<i)]=cost[start][path]+map[start][i];
            else
                cost[i][path+(1<<i)] = min(cost[i][path+(1<<i)], cost[start][path]+map[start][i]);
            
            dfs(i,path+(1<<i));
        }
    }
    return min_cost;
}

int main(){
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    cout<<dfs(0,1);
}
