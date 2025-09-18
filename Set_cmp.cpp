class TaskManager {
public:
struct cmp{
     bool operator()(const pair<int,int>&a, const    pair<int,int>&b) const{
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
   }
 };

    unordered_map<int,int>mp;
    unordered_map<int,int>mp2;
     set<pair<int,int>,cmp>st;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks){
            mp[i[1]]=i[0];
            mp2[i[1]]=i[2];
            st.insert({-1*i[2],i[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]=userId;
        mp2[taskId]=priority;
        st.insert({-1*priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        st.erase({-1*mp2[taskId],taskId});
        mp2[taskId]=newPriority;
        st.insert({-1*newPriority,taskId});
    }
    
    void rmv(int taskId) {
        st.erase({-1*mp2[taskId],taskId});
        mp2.erase(taskId);
        mp.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;
        int taskId=(*st.begin()).second;
        cout<<taskId<<endl;
        int ans=mp[taskId];
        st.erase({-1*mp2[taskId],taskId});
        mp.erase(taskId);
        mp2.erase(taskId);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
