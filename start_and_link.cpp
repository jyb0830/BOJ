//
//  start_and_link.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/09.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,min=100;
    vector<int> t1,t2;
    cin>>N;
    int stat[N][N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>stat[i][j];
        }
    }
    
    for(int i=0;i<(1<<N);i++){
        t1.clear();
        t2.clear();
        
        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) == 0) {
                t1.push_back(j);
            }
            else {
                t2.push_back(j);
            }
        }
        if(t1.size()!=N/2) continue;
        int t1sum = 0;
        int t2sum = 0;
        for (int j = 0; j < N / 2; j++) {
            for (int k = 0; k < N / 2; k++) {
                if (j == k) continue;
                t1sum += stat[t1[j]][t1[k]];
                t2sum += stat[t2[j]][t2[k]];
            }
        }
        int diff=(t1sum>t2sum?t1sum-t2sum:t2sum-t1sum);
        if(diff<min)
            min=diff;
    }
    cout<<min;
    
    return 0;
}
