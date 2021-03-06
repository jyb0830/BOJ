//
//  q5.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/06.
//

#include <iostream>
#include <vector>
using namespace std;

struct mole{
    int score;
    vector<int> up_time;
};

int main(){
    int n, max_time=0, max_score=0;;
    cin>>n;
    vector<mole> v;
    for(int i=0;i<n*n;i++){
        mole m;
        int num;
        cin>>m.score>>num;
        for(int j=0;j<num;j++){
            int t;
            cin>>t;
            m.up_time.push_back(t);
        }
        max_time=max(max_time, m.up_time[m.up_time.size()-1]);
        v.push_back(m);
    }
    bool visited[max_time];
    for(int i=0;i<max_time;i++) visited[i]=false;
    
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i].score<v[j].score){
                int temp=v[i].score;
                v[i].score=v[j].score;
                v[j].score=temp;
                v[i].up_time.swap(v[j].up_time);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].up_time.size();j++){
            if(!visited[v[i].up_time[j]]){
                max_score+=v[i].score;
                visited[v[i].up_time[j]]=true;
            }
        }
    }
    
    cout<<max_score;
    
    return 0;
}
