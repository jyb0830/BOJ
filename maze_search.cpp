//
//  maze_search.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/04.
//  acmicpc.net/problem/2178

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, M;
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    queue<pair<int, int>> q;
    
    
    
    cin>>N>>M;
    
    char maze[N][M];
    int visited[N][M];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maze[i][j];
            visited[i][j]=0;
        }
    }
    
    visited[0][0]=1;
    q.push(make_pair(0, 0));
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(maze[nx][ny]=='1'&&visited[nx][ny]==0){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny]=visited[x][y]+1;
                }
            }
        }
    }
    cout<<visited[N-1][M-1];
    
    return 0;
}
