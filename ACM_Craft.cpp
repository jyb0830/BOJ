//
//  ACM_Craft.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/26.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    int Ans[T];
    for(int i=0;i<T;i++)
        Ans[i]=0;
    for(int a=0;a<T;a++){
        queue<int> q;
        vector<vector<int>> v;
        
        int N, M, X, Y, W;
        cin>>N>>M;
        int D[N+1],in[N+1],min_t[N+1];
        for(int i=0;i<N+1;i++) v.push_back(vector<int>());
        for(int i=0;i<N+1;i++){
            D[i]=0;
            in[i]=0;
            min_t[i]=0;
        }
        for(int i=1;i<N+1;i++) cin>>D[i];
        
        for(int i=0;i<M;i++){
            cin>>X>>Y;
            v[X].push_back(Y);
            in[Y]++;
        }
        cin>>W;
        for(int i=1;i<N+1;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int temp = q.front();
            if(temp==W){
                Ans[a]=min_t[temp]+D[temp];
                break;
            }
            q.pop();
            for(int i=0;i<v[temp].size();i++){
                if(--in[v[temp][i]]==0)
                    q.push(v[temp][i]);
                if(min_t[temp]+D[temp]>min_t[v[temp][i]])
                    min_t[v[temp][i]]=min_t[temp]+D[temp];
            }
        }
    }
    for(int i=0;i<T;i++)
        cout<<Ans[i]<<"\n";
    return 0;
}
