#include<bits/stdc++.h>
using namespace std;
#define um unordered_map
#define us unordered_set
#define pr priority_queue
  #define ll long long 
#define vl vector<long long>
#define vc vector<char>
#define loop(n) for(ll i=0;i<n;i++)
#define fr(i,x,n) for(ll i=x;i<n;i++)	
#define all(v) v.begin(),v.end() 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const long long M=1e9+7;
int find(int u,vector<int>&par){
    if(par[u]==u)return u;
    return par[u]=find(par[u],par);
}
void uniondsu(int u,int v,vector<int>&par,vector<int>&rank){
    int u_par=find(u,par);
    int v_par=find(v,par);
    if(u_par==v_par)return;
    if(rank[u_par]<rank[v_par]){
        par[u_par]=v_par;
    }
    else if(rank[u_par]>rank[v_par]){
        par[v_par]=u_par;
    }
    else{
        par[u_par]=v_par;
        rank[v_par]++;
    }
}
int main(){ 
     //ॐ 
int n=7;
vector<int>par(n);
vector<int>rank(n);
for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=i;
}
uniondsu(1,2,par,rank);
uniondsu(2,3,par,rank);
uniondsu(4,5,par,rank);
int u,v;
cout<<"enter u and v"<<endl;
cin>>u>>v;
if(find(u,par)==find(v,par)){
    cout<<" lie in same component"<<endl;
}
else 
cout<<" not lie in same component  "<<endl;

 return 0;
}