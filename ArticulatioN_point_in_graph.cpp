//User function Template for C++

// Rule 1: The Root Node (par == -1)
// If the node where you started the DFS (the root) has more than one independent child in the DFS tree, it is an AP.

// Code logic: if(par==-1 && child>1) { ans[i]=1; }

// Why? If the root has two children, the only way those two children connect to each other is through the root. If you remove the root, they get disconnected.

// Rule 2: Non-Root Nodes (par != -1)
// For any non-root node i with a child j, if low[j] >= disc[i], then node i is an AP.

// Code logic: if(low[j] >= disc[i] && par != -1) { ans[i]=1; }

// Why? low[j] >= disc[i] means that the child j (and everything below it) cannot find a back-edge to an ancestor of i. The highest up they can reach is node i itself (or lower). Therefore, node j is trapped. If you remove i, j is cut off from the rest of the graph.


// main idea is that ki ek particular node i se jab dfs call j pe marke jab wapis aate hn tab agar i node ko chorke uske 
// kisi ancestor se low of j update hua hn toh wo hamesa kam hi hoga i ke disc se toh wo toh wo ap nhi hoga 
// agar wo i se update hua hn toh wo equal hoga us case me ap hoga.=> matlab j hm bas i ke through hi pahuch sakte hn baki
// aur kisi ke through nhii.


class Solution {
  public:
  void dfs(int i,vector<int>adj[],vector<int>&ans,vector<int>&disc
  ,vector<int>&low,int &par,vector<int>&vis,int &timer){
      vis[i]=1;
      low[i]=disc[i]=timer++;
      int child=0;
      for(auto j:adj[i]){
          if(par==j)continue;
          if(!vis[j]){
              dfs(j,adj,ans,disc,low,i,vis,timer);
              low[i]=min(low[i],low[j]);
              if(low[j]>=disc[i]&&par!=-1){
                  ans[i]=1;
              }
              child++;
          }
          else{
              //backedge
              low[i]=min(low[i],disc[j]);
          }
      }
      if(par==-1&&child>1){
          ans[i]=1;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
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
        vector<int>ap;
        for(int i=0;i<V;i++){
            if(ans[i]==1)ap.push_back(i);
        }
        if(ap.size()==0)return {-1};
        return ap;
    }
};
