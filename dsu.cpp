// DSU BY RANK

 class dsu{
private:
    vector<int> parent;
    vector<int> rank;

public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
            rank[i] = 0; 
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; 

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

//DSU BY SIZE

class dsu{
private:
    vector<int> parent;
    vector<int> size;

public:
    dsu(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unite(int u, int v) {
       int ulpu=find(u);
        int ulpv=find(v);
        if(ulpu==ulpv)
         return;
        if(size[ulpu]<size[ulpv]){
            size[ulpv]+=size[ulpu];
            parent[ulpu]=ulpv;
        }
        else{
            size[ulpu]+=size[ulpv];
            parent[ulpv]=ulpu;
        }
    }
    int getsize(int x){
        return size[find(x)];
    }
};
