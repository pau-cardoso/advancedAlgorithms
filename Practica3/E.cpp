#include<bits/stdc++.h>
#include <math.h>
using namespace std;

typedef pair <int, int> pi;

priority_queue <pair <int, pi>> pq;
vector <pair <pi, int>> edges;
vector <int> dads;
vector <int> rango;
int mst_weight;

int parent(int i) {
    if(dads[i] != i) {
        dads[i] = parent(dads[i]);
    }

    return dads[i];
}

bool sameTree(int i, int j) {
    return (parent(i) == parent(j));
}

void Union (int i, int j) {
    i = parent(i);
    j = parent(j);

    if(i == j) {
        return;
    }

    if (rango[i] > rango[j]) {   
        dads[j] = i;
    } 
    else {
        dads[i] = j;
        if(rango[i] == rango[j]) rango[j]++;
    }

    return;
}

//Fills edges vector
void buildMST() {
    while(!pq.empty()) {
        int cost = -1 * pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if(!sameTree(u,v)) {
            mst_weight += cost;
            Union(u, v);
            edges.push_back({{u,v}, cost}); 
        }
    }

    return;
}

//Initialize function to fill the priority queue
void fillPQ(int m) {
    int u, v, costo;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> costo;
        costo = pow(2, costo);
        cout << "costo " << costo << endl;
        //To have a min heap, I multiply -1 to the cost
        pq.push({-1*costo, {u,v}}); 
    }

    return;
}


int main() {
    int n, m;
    mst_weight = 0;

    cin >> n >> m;
    
    dads.resize(n+5);
    rango.assign(n+5, 1);

    for(int i=0; i<n+5; i++) {
        dads[i] = i;
    }

    fillPQ(m);

    //Build the MST
    buildMST();

    cout << "The Minimum Spanning Tree cost is: " << mst_weight << endl; 
    
    cout << "The mdges (and their cost) in the Minimum Spanning Tree are: " << endl;
    for(int i=0; i<edges.size(); i++) {
        cout << edges[i].first.first << " ";
        cout << edges[i].first.second << " ";
        cout << edges[i].second << endl;
    }

    return 0;
}