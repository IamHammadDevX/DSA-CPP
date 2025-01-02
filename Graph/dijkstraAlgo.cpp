#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// dijkstra's Algo
vector<int> dijkStraAlgo(vector<vector<int>> &vec, int edges, int vert, int src)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wieght = vec[i][2];

        adj[u].push_back(make_pair(v, wieght));
        adj[v].push_back(make_pair(u, wieght));
    }
    // distance array with max value initially
    vector<int> dist(vert);
    for (int i = 0; i < vert; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[src] = 0;
    st.insert(make_pair(0, src));

    while (!st.empty())
    {
        // fetch the record from top of set
        auto top = *(st.begin());

        int Nodedistance = top.first;
        int topNode = top.second;

        // remove top
        st.erase(st.begin());

        // look for neighbours
        for (auto neighbour : adj[topNode])
        {
            if (Nodedistance + neighbour.second < dist[neighbour.first])
            {
                auto rec = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // record found
                if (rec != st.end())
                {
                    st.erase(rec);
                }

                dist[neighbour.first] = Nodedistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main()
{
    // Number of vertices and edges
    int vertices = 5;
    int edges = 7;

    // Edge list: {u, v, weight}
    vector<vector<int>> edgeList = {
        {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 2}, {3, 0, 6}};

    // Source vertex
    int source = 0;

    // Call the function
    vector<int> distances = dijkStraAlgo(edgeList, edges, vertices, source);

    // Output the distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
