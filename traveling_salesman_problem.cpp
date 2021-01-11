//
//  traveling_salesman_problem.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/10.
//  acmicpc.net/problem/2098

#include <iostream>

using namespace std;

#define INF 987654321

int map[16][16];
int cost[16][1<<16];
int N;


int tsp(int curr,int path){
    int result = cost[curr][path];
    if(result!=0) return result; // 현재 도시를 포함한 경로에서, 모든 도시를 순회하고 첫 번째 도시로 가는 최단거리가 구해져 있으면 그 값을 그대로 반환한다
    
    if(path==((1<<N)-1)){     //모든 도시를 방문했을 때, 마지막 도시에서 처음 도시로 가는 비용을 반환
        if(map[curr][0]!=0)
            return map[curr][0];
        return INF;
    }
    result=INF;
    for(int i=0;i<N;i++){
        if(map[curr][i]==0||((1<<i)&path)!=0) continue;
        result = min(result, map[curr][i]+tsp(i,path|(1<<i)));
    }
    cost[curr][path]=result;
    
    return result;
}

int main(){
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    cout<<tsp(0,1);
}
