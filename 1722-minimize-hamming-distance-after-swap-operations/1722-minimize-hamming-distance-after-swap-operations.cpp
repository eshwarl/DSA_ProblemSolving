class Solution {
public:
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB)
            parent[rootB] = rootA;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

     
     
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

      
      
        for (auto &swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }

     
     
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int distance = 0;

       
       
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

           
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    distance++;
                }
            }
        }

        return distance;
    }
};