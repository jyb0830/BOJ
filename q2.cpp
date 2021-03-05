#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int p,n,h;

//int answer(int idx, int sum){
//    if(sum +arr[idx]==h) return sum + arr[idx];
//
//    else if(sum + arr[idx]>h) return sum;
//
//    else{
//        sum+=arr[idx];
//        if(idx+1<4){
//            vector<int> temp;
//            for(int i=idx+1;i<4;i++){
//                temp.push_back(answer(i,sum));
//            }
//            sort(temp.begin(), temp.end());
//            sum=temp[temp.size()-1];
//        }
//    }
//    return sum;
//}

int answer(int pc, int p, int hour){
    if(hour + v[pc][p]==h) return hour + v[pc][p];
    
    else if(hour + v[pc][p]>h) return hour;
    
    else{
        hour += v[pc][p];
        if(p+1<v[pc].size()){
            vector<int> temp;
            for(int i=p+1;i<v[pc].size();i++){
                temp.push_back(answer(pc, i, hour));
            }
            sort(temp.begin(), temp.end());
            hour = temp[temp.size()-1];
        }
    }
    return hour;
}


int main(){
    cin>>p>>n>>h;
    int ans[p];
    for(int i=0;i<p;i++) {
        v.push_back(vector<int>());
        ans[i]=0;
    }
    
    for(int i=0;i<n;i++){
        int pc, hour;
        cin>>pc>>hour;
        if(hour==h) ans[pc-1]=hour;
        v[pc-1].push_back(hour);
    }
    
    for(int i=0;i<p;i++){
        sort(v[i].begin(), v[i].end());
        if(ans[i]==0){
            for(int j=0;j<v[i].size();j++){
                ans[i]=max(ans[i], answer(i,j,0));
            }
        }
    }
    
    for(int i=0;i<p;i++){
        cout<<i+1<<" "<<ans[i]*1000<<"\n";
    }
    
    
    return 0;
}
