//
//  maze_search.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/04.
//

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, M, cnt=0;
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    queue<pair<int, int>> q;
    
    
    
    cin>>N>>M;
    
    char maze[N][M];
    bool visited[N][M];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maze[i][j];
            visited[i][j]=false;
        }
    }
    
    visited[0][0]=true;
    q.push(make_pair(0, 0));
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(maze[nx][ny]&&!visited[nx][ny])
                q.push(make_pair(nx, ny));
        }
        
    }
    
    
    return 0;
}
