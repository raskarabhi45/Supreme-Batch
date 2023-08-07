// 17/6/2023 saturday
//#########################################
//Doneeeeeeeeeeeeeeeeeeeeeeeeeee
//#################################

// graph started
// the most important the bang topic
// areeee ye to aasssaaaan hai mzak hai.......................!!!

// graph is DS which is combination of Nodes(to store data) and edges(to connect nodes)
// complex data structure facebook and google map
// real world applications of the graph
// Bus system project in c++ routing system type (Djesktra algorithm)
// connections in Linked in and instagram

// types of graph
// 1 directed graph(when there is arrow in edges then it is directed) only A-C
// 2 undirected graph (no arrow between edges )  (A-C or C-A)

// weighted graph  if direction pe weight given then weighted directed graph
// agr kisi edge ke upr maginitude likha hota hai to O us edge ka weight hota hai

// weighted undirected  graph

// degree (kitni edges us node se judi hua hai)
// in case of directed graph
// Indegree  number arrow(pointed edges) towards that node
// outdegree number of arrow going aways from that node

// path (sequence of nodes ) but that node should be visited only once

// cyclic graph (edges that making circle )
//  A->B->C->D->A weighted cyclic directed graph
// weighted acyclic directed graph

// jroori nhi hai ki graph ki edges ek dusre se connected ho
// use disconnectd graph kehte hai

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

// implementaion of graph
// 1 using adjancency matrix (2D array)
// 2 adjecency List (Map/ Vector/ set se) //will use this mostly

template <typename T> // for generic graph
class Graph
{
public:
    // ek integer ke coresponds vector of map hai qki hme pta lgana hai ki yaha se hum kaha kaha ja skte
    unordered_map<T, list<T>> adjList;
    // unordered_map<int, list<pair<int,int>>> adjList;  for storing weight we made pair over here

    // void addEdge(int u, int v ,bool direction)
    // {
    //     // direction =0 undirected graph
    //     // direction =1 directed graph or edge
    //     adjList[u].push_back(v); // create edge from u top v
    //     if (direction == 0)
    //     {
    //         // undirected edge
    //         // means edge in both direction
    //         adjList[v].push_back(u); // create edge from v top u
    //     }
    // }

    void addEdge(T u, T v, bool direction)
    {
        // direction =0 undirected graph
        // direction =1 directed graph or edge
        adjList[u].push_back(v); // create edge from u top v
        if (direction == 0)
        {
            // undirected edge
            // means edge in both direction
            adjList[v].push_back(u); // create edge from v top u
        }
    }

    // with weight
    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction =0 undirected graph
        // direction =1 directed graph or edge
        adjList[u].push_back({v, weight}); // create edge from u top v
        if (direction == 0)
        {
            // undirected edge
            // means edge in both direction
            adjList[v].push_back({u, weight}); // create edge from v top u
        }
    }

    void printAdjacencyList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto neighbour : i.second) // i ke corresponding mapping jo ki lost me pdi hai
            {
                cout << neighbour << ",";
            }
            cout << endl;
        }
    }

    // for weighted graph
    //       void printAdjacencyList()
    //      {
    //          for (auto node : adjList)
    //          {
    //              cout << node.first << "->";
    //              for (auto neighbour : node.second)
    //              {
    //                  cout << neighbour.first << ",";  //here pair node val node.first and its weight that node.second
    //                  cout<<neighbour.second<<" ";
    //              }
    //              cout << endl;
    //          }
    //      }

    // BFS (Breadth first search)  (same as level order traversal)

    void bfs(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            // insert neighbour
            for (auto neighbour : adjList[frontNode])
            { // frontnode ke list me se neighbour nikalo
                if (!visited[neighbour])
                { // agr neighbour visited nhi hai to hi queue me push kro
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    // DFS (depth first search)  (same as inorder preorder and postorder)
    void dfs(int scr, unordered_map<int, bool> &visited)
    {
        cout << src << " ,";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited); // recursive call again
            }
        }
    }
};

int main()
{
    // Adjacency matrix

    // int n;
    // cout<<"Enter number of nodes "<<endl;
    // cin>>n;
   //2d matrix
    // vector<vector<int>> adj(n,vector<int>(n,0));

    // int e;
    // cout<<"Enter number od edges "<<endl;
    // cin>>e;
    // for(int i=0;i<e;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     //mark 1
    //     adj[u][v]=1;
    // }

    // //printing
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // Enter number of nodes
    // 3
    // Enter number od edges
    // 6
    // 0 1
    // 1 0
    // 1 2
    // 2 1
    // 0 2
    // 2 0
    // 0 1 1
    // 1 0 1
    // 1 1 0

    // Adjacency List
    // just list lelo ki 1 jgh se hum kaha kaha ja skte hai
    // for weighted graph pair store krenge node,distance otherwise node

    // // undirected graph
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // g.printAdjacencyList();
    // 2->1,0,
    // 1->0,2,
    // 0->1,2,

    // weighted directed graph
    // Graph G;
    // G.addEdge(0, 1,5, 1);
    // G.addEdge(1, 2,4, 1);
    // G.addEdge(0, 2, 4,1);
    // G.printAdjacencyList();
    // 1->2,
    // 0->1,2,
    // 1->2,4
    // 0->1,5 2,4

    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'c', 0);
    g.printAdjacencyList();

    // c->b,a,
    // b->a,c,
    // a->b,c,

    return 0;
}

// BFS (Breadth first search)  (same as level order traversal)
// DFS (depth first search)  (same as inorder preorder and postorder)