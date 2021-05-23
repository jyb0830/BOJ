//
//  jewerly_thief.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/23.
//  acmicpc.net/problem/1202

#include <iostream>
#include <queue>
#include <set>


using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int,int> b){
        return a.second<b.second;
    }
};

int main(){
    int N, K;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> j_q;
    cin>>N>>K;
    
    int64_t cost=0;
    multiset<int> bag;
    
    multiset<int>::iterator Iter;
    
    for(int i=0;i<N;i++){
        int M, V;
        cin>>M>>V;
        j_q.push(make_pair(M, V));
    }
    
    for(int i=0;i<K;i++){
        int C;
        cin>>C;
        bag.insert(C);
    }
    
    while(!j_q.empty() && !bag.empty()){
        Iter = bag.lower_bound(j_q.top().first);
        if(Iter == bag.end()) {
            j_q.pop();
            continue;
        }
        else{
            cost+=j_q.top().second;
            j_q.pop();
            bag.erase(Iter);
        }
    }
    
    cout<<cost<<"\n";
    
    return 0;
}
