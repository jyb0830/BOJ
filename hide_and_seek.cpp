//
//  hide_and_seek.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/05.
//  acmicpc.net/problem/1697

#include <iostream>
#include <queue>

using namespace std;
int arr[100001];
void bfs(int N, int K){
    queue<int> q;
    q.push(N);
    
    while(!q.empty()){
        int temp=q.front();
        
        if(temp==K)
            break;
        
        q.pop();
        if(temp-1>=0 && !arr[temp-1]){
            q.push(temp-1);
            arr[temp-1]=arr[temp]+1;
        }
        if(temp+1<=100000 && !arr[temp+1]){
            q.push(temp+1);
            arr[temp+1]=arr[temp]+1;
        }
        if(temp*2<=100000 && !arr[temp*2]){
            q.push(temp*2);
            arr[temp*2]=arr[temp]+1;
        }
    }
    cout<<arr[K];
}

int main(){
    int N,K;
    
    cin>>N>>K;
    
    bfs(N, K);
    
    return 0;
}
