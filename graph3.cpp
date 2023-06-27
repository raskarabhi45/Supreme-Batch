// graph 3rd lecture
// /special class very important 
//topological sort..............
//konse question me topological sort lgaoge isme dimak lgega baki ye aasaan hai
//questions very important
//rotton oranges
//number of irland
//burning tree
//bridge in graph
//snake and ladder problme

//ek baaat dhyan me rkho interviwer tumhe yhi sare concept puchecha but
//wo ek kahani bnake puchega taki tumhe lge kuch nya puch liya


#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;



//topological sort..............
//linear ordering of vertices such that
// for every edge u->v u comes before v in that ordering 
// O node ordering me pehle aayeji jiski dependency khatm ho gyi hai
//dag  q ki isme cycle pe her ek node ki degree 1 hoti hai
//directed acyclic graph pe topological sort lgate hai sirf

//vvvimp
// cyclic graph ke andar  topological sort ke andar kbhi ki topologica sort ki length number of nodes ke equal nhi holgi
//length !=nodes

template <typename T>
class Graph {
public:
	unordered_map<T, list<T > > adjList;

	void addEdge(T u, T v, bool direction) {
		//direction = 0 -> undirected graph
		//direction = 1 -> directed graph
		//create an edge from u to v
		adjList[u].push_back(v);
		if(direction == 0)
		{
			//undirected edge
			//create an edge from v to u
			adjList[v].push_back(u);
		}
	}

	void printAdjacencyList() {
		for(auto node: adjList) {
			cout << node.first << "-> " ;
			for(auto neighbour: node.second) {
				cout <<neighbour<<", ";
			}
			cout << endl;
		}
	}

	void bfs(int src, unordered_map<int, bool>& visited) {
		queue<int> q;
		
		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			int frontNode= q.front();
			q.pop();
			cout << frontNode << ", ";

			//insert neighbours
			for(auto neighbour: adjList[frontNode]) {
				if(!visited[neighbour] ) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfs(int src, unordered_map<int, bool>& visited) {
		cout << src << ", ";
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour] ) {
				dfs(neighbour, visited);
			}
		}
	}

   //topological sort
	void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour] ) {
				topoSortDfs(neighbour, visited, ans);
			}
		}

		//while returning, store the node in stack //only change
		ans.push(src);
	}


//kahns lagorithm
//queue ke andar vahi aayega jo independega hoga jiski indegree 0 hogi
	void topoSortBfs(int n, vector<int>& ans) {
		queue<int> q;
		unordered_map<int, int> indegree;

		//indegree calculate
		for(auto i: adjList ) {
			int src = i.first;
			for(auto nbr:i.second) {
				indegree[nbr]++;
			}
		}

		//put all nodes inside queue, which has indegree=0
		for(int i=0; i<n; i++) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}

		//bfs logic
		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			//or we can do count++

			for(auto nbr: adjList[fNode]) {
				indegree[nbr]--;
				//check for zero again
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}	
			}
			
		}
		
	}


};




int main() {

	Graph<int> g;
	//n -> number of nodes in graph
	int n = 8;
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,1,1);

	// g.addEdge(3,7,1);
	// g.addEdge(6,7,1);
	// g.addEdge(7,0,1);
	// g.addEdge(7,1,1);

	g.printAdjacencyList();
	cout << endl;

	vector<int> ans;
	//connected or disconnected 
	g.topoSortBfs(n, ans);

	if(ans.size() == n) {
		cout << "It is a valid topo sort" << endl;
	}
	else {
		cout << "Cycle Present or Invalid topo sort " << endl;
	}

	
	cout << "Printing Topological Sort using BFS: " << endl;
	for(auto i: ans) {
		cout << i << ", ";
	}cout << endl;

    // unordered_map<int,bool> visited;
	// stack<int> ans;
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i] ){
	// 		g.topoSortDfs(i,visited,ans);
	// 	}
	// }

	// cout << "Top Sort: " << endl;
	// while(!ans.empty()) {
	// 	cout << ans.top();
	// 	ans.pop();
	// }




	return 0;
}