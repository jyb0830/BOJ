//
//  virus.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/07.
//  acmicpc.net/problem/2606

#include <iostream>
#include <queue>

using namespace std;
int n;
bool visited[101];
bool network[101][101];
void bfs(){
    int cnt=0;
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        visited[tmp]=true;
        for(int i=1;i<n+1;i++){
            if(network[tmp][i]==true&&visited[i]==false){
                q.push(i);
                visited[i]=true;
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}

int main(){
    int path;
    cin>>n;
    cin>>path;
    
    for(int i=0;i<path;i++){
        int x,y;
        cin>>x>>y;
        network[x][y]=true;
        network[y][x]=true;
    }
    bfs();
        
    return 0;
}
