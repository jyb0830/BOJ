//
//  vector_matching.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/30.
//  acmicpc.net/problem/1007



#include <iostream>
#include <cmath>
using namespace std;
int N;
int X[21],Y[21];
int64_t sum_x=0,sum_y=0;

double matching(int S,int start, int64_t x, int64_t y){
    if(N/2-S>N-start) return INT64_MAX;
    
    if(S+1==N/2)
        return pow(sum_x-2*(x+X[start]),2)+pow(sum_y-2*(y+Y[start]),2);
    
    int64_t ans = INT64_MAX;
    for(int i=start;i<N;i++){
        double temp = matching(S+1,i+1,x+X[start],y+Y[start]);
        if(ans>temp){
            ans=temp;
        }
    }
    return ans;
}


int main(){
    int T;
    cin>>T;
    double ans[T];
    for(int i=0;i<T;i++){
        ans[i]=0;
        cin>>N;
        
        sum_x=0;
        sum_y=0;
        for(int j=0;j<N;j++){
            cin>>X[j]>>Y[j];
            sum_x+=X[j];
            sum_y+=Y[j];
        }
        if(N==2){
            ans[i]=sqrt((double)pow(X[1]-X[0],2)+pow(Y[1]-Y[0],2));
        }
        else
            ans[i]=sqrt((double)matching(0,0,0,0));
    }
    cout << fixed;
    cout.precision(7);
    for(int i=0; i<T;i++)
    cout<<ans[i]<<"\n";
    
    return 0;
}
