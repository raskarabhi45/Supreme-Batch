// graph second lecture
//#########################################
//Doneeeeeeeeeeeeeeeeeeeeeeeeeee
//#################################

// cycle detection 4 trike se sikhenge
// directed BFS DFS
// undirected BFS DFS

// undirected graphs me cycle hai ya nhi pta lgana hai

// BFS se krenge
// if you found any node which is already visited and not a parent then cycle is there
// or you can say
//  bhaiya in simple words if a node already has a parent and
//  if we are trying to modify the parent then there is a cycle

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
public:
	unordered_map<T, list<T>> adjList;

	void addEdge(T u, T v, bool direction)
	{
		// direction = 0 -> undirected graph
		// direction = 1 -> directed graph
		// create an edge from u to v
		adjList[u].push_back(v);
		if (direction == 0)
		{
			// undirected edge
			// create an edge from v to u
			adjList[v].push_back(u);
		}
	}

	void printAdjacencyList()
	{
		for (auto node : adjList)
		{
			cout << node.first << "-> ";
			for (auto neighbour : node.second)
			{
				cout << neighbour << ", ";
			}
			cout << endl;
		}
	}

	void bfs(int src, unordered_map<int, bool> &visited)
	{

		queue<int> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty())
		{
			int frontNode = q.front();
			q.pop();
			cout << frontNode << ", ";

			// insert neighbours
			for (auto neighbour : adjList[frontNode])
			{
				if (!visited[neighbour])
				{
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfs(int src, unordered_map<int, bool> &visited)
	{
		cout << src << ", ";
		visited[src] = true;

		for (auto neighbour : adjList[src])
		{
			if (!visited[neighbour])
			{
				dfs(neighbour, visited);
			}
		}
	}

	// for undirected graph chech cycle using BFS
	bool checkCyclicUsingBfs(int src, unordered_map<int, bool> &visited)
	{
		queue<int> q;
		unordered_map<int, int> parent; // to store parent ki kiska parent kon hai ye pta chle hme
    //initial steps
		q.push(src);
		visited[src] = true;
		parent[src] = -1;// qki src ka to koi parent nhi hoga n

		while (!q.empty())
		{
			int frontNode = q.front();
			q.pop();

			for (auto nbr : adjList[frontNode])
			{
				if (!visited[nbr]) //agr visited nhi hai
				{ 
					q.push(nbr); //q me push kro
					visited[nbr] = true; //visited true kro
					parent[nbr] = frontNode; //parent mark  krdo iska // frontnode hi to parent hogi neighbour ki
				}
				//already visisted
				// agr koi node visited hai and jis node pe tum aa rhe hai o parent nhi hai
				if (visited[nbr] && nbr != parent[frontNode])
				{
					// cycle present
					return true;
				}
			}
		}
		return false;
	}

// SAME LOGIC BROOOO 
	// for undirected graph chech cycle using DFS
	bool checkCyclicUsingDfs(int src, unordered_map<int, bool> &visited, int parent)
	{
     //source ko visited kr denge
		visited[src] = true;

		for (auto nbr : adjList[src]) //jitne src ke neighbour hai
		{
			if (!visited[nbr]) //agr neioghbour visited nhi hai
			{
				bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src); // src hi parent hoga aage ke lia
				if (checkAageKaAns == true)
					return true;
			}
			//neighbour already visited hai and pareent bhi nhi hai
			if (visited[nbr] && nbr != parent)  //means cycle mil gyi
			{ /// same logic as above
				// cycle present
				return true;
			}
		}
		return false;
	}


	//FOR DIRECTED GRAPH
//muze track rkhna pdega ki kon kon si calls stack me pdi hai
	// for directed graph cycle detection using DFS
	bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited,
										  unordered_map<int, bool> dfsVisited)
	{

		visited[src] = true;	// it cannot change we visited true
		//call stack to store calls
		dfsVisited[src] = true; // it can change again true or false that is signicant  difference
		// is bande ki call recursion me pehle se hi pdi hai
		// hmne dfsvisited kiya hai qki hme sare recursiom call stack chahia taki pta chle kona firse aaya hai call for cycle detection

		for (auto nbr : adjList[src])
		{
			if (!visited[nbr])
			{
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
				if (aageKaAnswer == true)
					return true;
			}
			//agr visited hai nrighbour and dfsvisited me O call pehle se hi pdi hai
			if (visited[nbr] == true && dfsVisited[nbr] == true) // loop present condition  
			{
				return true;
			}
		}
		// yaha hi galti hoti h  return aate vakta visited htana hai dfsvisited se
		dfsVisited[src] = false; // dfsvisited change ho jayega jb aap recursive call stack se ht jaoge
		return false;
	}
};

//ye badd me sikhayenge
// BFS is remaining for  directed graph

int main()
{

	Graph<int> g;
	// n -> number of nodes in graph
	int n = 5;
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);
	g.addEdge(4, 0, 1);

	g.printAdjacencyList();
	cout << endl;

	bool ans = false;
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisited;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			ans = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
			if (ans == true)
				break;
		}
	}

	if (ans == true)
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

	return 0;
}