#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, e;//n : 땅콩개수, m : 먹으려는 갯수, e : 현재 위치
    cin>>n>>m>>e;
    int peanut[n];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>peanut[i];
        if(peanut[i]==e) m--;
    }
    
    for(int i=0;i<n;i++){
        int cnt=0;
        if(e-peanut[i]>0){
            for(int j=i;j<n;j++){
                if(peanut[j]>=peanut[i] && peanut[j]<e){
                    cnt++;
                }
            }
            v.push_back(make_pair(e-peanut[i], cnt));
        }
        else if(e-peanut[i]<0){
            for(int j=i;j>0;j--){
                if(peanut[j]<=peanut[i] && peanut[j]>e){
                    cnt++;
                }
            }
            v.push_back(make_pair(e-peanut[i], cnt));
        }
    }
    
    int min_num=2100000000;
    for(int i=0;i<v.size();i++){
        int ans=0;
        
        if(v[i].second>m) continue;
        
        else if(v[i].second==m) {
            ans=abs(v[i].first);
        }
        
        else{
            if(v[i].first>0){
                for(int j=i;j<v.size();j++){
                    if(v[j].first<0 && v[i].second+v[j].second==m) ans=abs(v[i].first-v[j].first);
                }
            }
            else if(v[i].first<0){
                for(int j=i;j>=0;j--){
                    if(v[j].first>0 && v[i].second+v[j].second==m) ans=abs(v[i].first-v[j].first);
                }
            }
        }
        min_num=min(min_num, ans);
    }
    
    cout<<min_num<<"\n";
    
    return 0;
}
