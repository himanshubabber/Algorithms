// the only difference in it with articulation point is equality sign is not in bridge
// because i---j---k
//             |  /
//             m/
// j-k bridge nhi hn but disc of j is equal to low of k
// i-j bridge hn then esme low[j]> disc[i]
// main reason j se agar kisi neighbour pe backedge hogi toh uske neighbour ka low uske disc ke equal ho jaega 
// aur hmne yaha backedge wala case nhi dekhna kuki usme edge remove pe bhi disconnect nhi hoga.
                 
class Solution {
  public:
  bool fg=false;
  int cc;
  int dd;
  void dfs(int i,unordered_map<int,vector<int>>&adj,vector<int>&ans,vector<int>&disc
  ,vector<int>&low,int &par,vector<int>&vis,int &timer){
      vis[i]=1;
      low[i]=disc[i]=timer++;
      int child=0;
      
      for(auto j:adj[i]){
          if(par==j)continue;
          if(!vis[j]){
              dfs(j,adj,ans,disc,low,i,vis,timer);
              low[i]=min(low[i],low[j]);
              if(low[j]>disc[i]){
                  if(i==cc && j==dd || i==dd && j==cc)
                 fg=true;
              }
          }
          else{
              //backedge
              low[i]=min(low[i],disc[j]);
          }
      }
  }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        unordered_map<int,vector<int>>adj;
         cc=c;
         dd=d;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>ans(V,0);
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        int par=-1;
        vector<int>vis(V,0);
        disc[0]=low[0]=0;
        int timer=0;
        for(int i=0;i<V;i++){
            if(!vis[i])dfs(i,adj,ans,disc,low,par,vis,timer);
        }
       return fg;
        
    }
};
