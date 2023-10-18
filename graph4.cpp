// graph fouth lecture
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

// shortest path shortest distance
// ye yaaaaaad rkhna
//  kya me ye likh skta  hu ki BFS ke dwara jb bhi mai kisi node ko visit krta hu
// for the first time O hi uska shortest path hota hai

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction =0 -> directed graph
        // direction =1 undirected graph
        adjList[u].push_back({v, wt});

        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "}";
            }
            cout << endl;
        }
    }

    // only for graph with same weights for every edge
    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial steps for src
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;
        // q ki source ka parent -1 hai to src pe pohchne ke baar hum ruk jayenge
        while (node != -1) // dest se node tk travel krunga jb tk -1 nhi aata to ye ulta aayega islia niche hum reverse kr rhe hai
        {
            ans.push_back(node);
            node = parent[node]; // node se parent jate rhenge
        }

        reverse(ans.begin(), ans.end());

        cout << "printing answer" << endl;
        for (auto i : ans)
        {
            cout << i << " , ";
        }
        cout << endl;
    }

    // topological sort
    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
            {
                topoSortDfs(neighbour.first, visited, ans);
            }
        }

        // while returning , store node in the stack
        ans.push(src);
    }

    // for diffent weights between the edges
    // steps
    // 1 find the topological sorting order jo ki ek stack ke andar pdi hogi linear ordering
    // 2 for each node in stack update the distance array if distance is minimum than INT_MAX
    // using DFS
    void shortestPathDfs(int dest, stack<int> topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        // agr me koi bhi node pop krta hu stack me se uska distance muze yhi pr update krna hoga
        for (auto nbr : adjList[0])
        {
            // distance update krna hai agr km hai to
            if (dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {

            int topElem = topoOrder.top();
            topoOrder.pop();

            if (dist[topElem] != INT_MAX)
            { // agr yha hi nhi poch skte to aage kaise jaoge
                for (auto nbr : adjList[topElem])
                {
                    // distance update krna hai agr km hai to
                    if (dist[topElem] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElem] + nbr.second;
                    }
                }
            }
        }

        cout << "printing ans " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << dist[i] << endl;
        }
    }

    // Dijkstra Algorithm.........................
    // minheap ya set se solve kro O(1) me minimum element mil jayega
    void shortestDistDijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        // initial stages
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // fetch the smallest or first eklement from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin()); // like q.pop()  krte the vaise

            // neighbour ke upr traverse krte hai
            for (auto nbr : adjList[node])
            {
                // kya jo distance bn rha hai wo update krne yogya hai ya nhi
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // muze distance update krna hai
                    // iski enrty set me pdi hai ya nhi check kro
                    // ye set ke andar and distnace wale array ke andr bhi update kro

                    // finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found, then remove
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    // very important
                    //  updation in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        cout << "printing ans:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << ", ";
        }
        cout << endl;
    }
    // output shortest distances for nodes
    //     printing ans:
    // 2147483647, 11, 12, 2, 13, 9, 0,
};

int main()
{
    // Graph g;
    // // //for undirected
    // g.addEdge(0, 1, 1, 0);
    // g.addEdge(1, 2, 1, 0);
    // g.addEdge(2, 3, 1, 0);

    // g.addEdge(3, 4, 1, 0);
    // g.addEdge(0, 5, 1, 0);
    // g.addEdge(5, 4, 1, 0);

    // g.addEdge(0, 6, 1, 0);
    // g.addEdge(6, 7, 1, 0);
    // g.addEdge(7, 8, 1, 0);
    // g.addEdge(8, 4, 1, 0);

    //     int src = 0;
    //     int dest = 4;
    //    //jisme total number of weight kum aa rha hai O shortest path hoga
    //     g.shortestPathBFS(src, dest);

    // output
    //     8->{4,1}
    // 7->{8,1}
    // 6->{7,1}
    // 5->{4,1}
    // 0->{1,1}{5,1}{6,1}
    // 1->{2,1}
    // 2->{3,1}
    // 3->{4,1}
    // printing answer
    // 0 , 5 , 4 ,

    // for directed
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(2, 1, 2, 1);

    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);

    // g.addEdge(4, 3, 1, 1);

    // g.printAdjList();

    // shortest pathdfs

    // stack<int> topoOrder;  //topological order store krne ke lia
    // unordered_map<int, bool> visited;
    // g.topoSortDfs(0, visited, topoOrder);

    // g.shortestPathDfs(3,topoOrder,5);

    // dijkstra algo
    Graph g;

    g.addEdge(6, 3, 2, 1);
    g.addEdge(6, 1, 14, 1);
    g.addEdge(3, 1, 9, 1);
    g.addEdge(3, 2, 10, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(2, 4, 15, 1);
    g.addEdge(4, 3, 11, 1);

    g.addEdge(6, 5, 9, 1);
    g.addEdge(4, 5, 6, 1);

    g.printAdjList();

    g.shortestDistDijkstra(6, 7);

    return 0;
}
