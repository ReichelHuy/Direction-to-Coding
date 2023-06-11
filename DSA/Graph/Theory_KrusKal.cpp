#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, parent[MAXN], rank[MAXN];
double adj[MAXN][MAXN];

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<Edge> edges;

void make_set(int v) {
    parent[v] = v;
    ::rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (::rank[a] < ::rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (::rank[a] == ::rank[b]) {
            ::rank[a]++;
        }
    }
}

void kruskal() {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            union_sets(e.u, e.v);
            sum += e.w;
        }
    }
    ofstream fout("Kruskal.txt");
    fout << fixed << setprecision(2) << sum << endl;
}

int main() {
    ifstream fin("Graph.txt");
    fin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
            if (i < j && adj[i][j] > 0) {
            Edge e;
            e.u = i;
            e.v = j;
            e.w = adj[i][j];
            edges.push_back(e);
            }
        }
    }
    kruskal();
    return 0;
}