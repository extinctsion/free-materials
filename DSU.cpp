#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vll vector<ll>

// Define a class for Disjoint Set data structure
class DisjointSet {
vll rank, parent, size;
public:
    // Constructor to initialize the Disjoint Set with 'n' elements
    DisjointSet(ll n) {
        rank.resize(n + 1, 0ll);   // Initialize rank array with zeros
        parent.resize(n + 1);      // Initialize parent array
        size.resize(n + 1);        // Initialize size array

        // Initialize each element as a separate set with a parent of itself
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;   // Initialize the size of each set as 1
            rank[i] = 1;   // Initialize the rank of each set as 1
        }
    }

    // Function to find the ultimate parent of a set containing 'node'
    ll findUPar(ll node) {
        if (node == parent[node])
            return node;
        // Path compression: Update the parent of 'node' to its ultimate parent
        return parent[node] = findUPar(parent[node]);
    }

    // Function to perform union by rank to merge two sets 'u' and 'v'
    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // If they already belong to the same set, no need to merge

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v; // Merge 'u' into 'v' and update the parent
        else {
            parent[ulp_v] = ulp_u; // Merge 'v' into 'u' and update the parent
            if (rank[ulp_v] == rank[ulp_u])
                rank[ulp_u]++; // If both sets have the same rank, increment the rank of the new parent
        }
    }

    // Function to perform union by size to merge two sets 'u' and 'v'
    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // If they already belong to the same set, no need to merge

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;     // Merge 'u' into 'v' and update the parent
            size[ulp_v] += size[ulp_u]; // Update the size of 'v'
        } else {
            parent[ulp_v] = ulp_u;     // Merge 'v' into 'u' and update the parent
            size[ulp_u] += size[ulp_v]; // Update the size of 'u'
        }
    }
};

int main() {
    // Create an instance of the DisjointSet with 8 elements
    DisjointSet dsu(8);

    // Perform union operations 
    dsu.unionByRank(1, 2);
    dsu.unionByRank(3, 4);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(3, 6);
    dsu.unionByRank(5, 7);

    if (dsu.findUPar(2) == dsu.findUPar(7)) {
        cout << "Same Parent" << endl;
    } else {
        cout << "Different Parent" << endl;
    }
    dsu.unionByRank(1, 4);

    if (dsu.findUPar(2) == dsu.findUPar(7)) {
        cout << "Same Parent" << endl;
    } else {
        cout << "Different Parent" << endl;
    }
    return 0;
}
