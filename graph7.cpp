//graph 7th lecture

/////////////////
//Algorithms................
//kya baaat smz mai aati hai
//1 Dijkstra Algorithm tumhee aanahi chahia interviewr ye puchega hi puchega
//TC e(log(v)) e=edges and v vertex
//ye algo negative cycle ke upr nhi chltaa

//pending dijkstra -ve weight or negative cycle  ke lia kaam nhi kregi
//isko implement nested for loop and
// priority queue and set se implement kr skte hai 


#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class graph {
	public:
	unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}


//used in google map for storing minimum distance betwwen 2 cities 
 //floyedWarshal path
//multiple source shortest path (MSSP)
//yahape hr node se hr node pe distance calculate hota hai

//step1 
//diagonal pe 0 and rest pe infinity dalo
//step2
//aur 1 node se sare path  (explore kro) check krenge and unse minimum distance path store krenge
//helper loop ,source loop and destionation loop


	void floydWarshal(int n) {
		vector<vector<int> > dist(n , vector<int>(n,1e9));
		//diagnol pr zero mark krdo
		for(int i=0; i<n; i++) {
			dist[i][i] = 0;
		}
		//graph k according dist insert krdia h
		for(auto t: adjList) {
			for(auto nbr: t.second) {
				int u = t.first;
				int v = nbr.first;
				int wt = nbr.second;
				dist[u][v] = wt;
			}
		}

		for(int helper=0; helper<n; helper++) {
			for(int src =0; src<n; src++) {
				for(int dest=0; dest<n; dest++) {
					dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
				}
			}
		}

		cout << "Printing distance array: " << endl;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << dist[i][j]<< ", ";
			}
			cout << endl;
		}
		
	}


    //bellman ford algorithm
    //steps   when graph has n nodes
    //1 relaxation n-1 times krni hoti hai qki 1st source node ka dist  to 0 hi hota hai na
    //fir aapko aapki shortest path milte hai
    //relaxation condition
    // dist[i]+wt <dist[v]  
    //yahape order matter nhi krta

      //to find negative cycle n times chlao 
     //agr tumne n bar passes chlaye and distance update hua 
     //to fir smjna ki negative cycle present hai
     //agr distance  update nhi hua to negative cycle present nhi hai


	void bellmanFordAlgo(int n, int src) {
		//assuming directed weightted graph
		vector<int> dist(n, INT_MAX);
		dist[src] = 0;
		//n-1 relaxation step
		for(int i=0; i<n-1; i++) {
			//for all edges
			for(auto t: adjList) {
				for(auto nbr: t.second) {
					int u = t.first;
					int v = nbr.first;
					int wt = nbr.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
						dist[v] = dist[u] + wt;
					}
				}
			}
		} 

		//to check for -ve cycle
		bool negativeCycle = false;
		for(auto t: adjList) {
				for(auto nbr: t.second) {
					int u = t.first;
					int v = nbr.first;
					int wt = nbr.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) { //relaxation step
						negativeCycle = true;
						break;
					}
				}
			}

		if(negativeCycle == true) 
			cout << "-ve cycle present";
		else
			cout << "-ve cycle absent";

		cout << "printing dist array: ";
		for(auto i : dist)
			cout << i << " ";
		
	}



	void shortestDistDijkstra(int src, int n) {
		vector<int> dist(n,INT_MAX);
		set<pair<int,int> > st;
		//intiial steps
		dist[src] = 0;
		st.insert(make_pair(0,src));

		while(!st.empty() ) {
			//fetch the smallest or first eklement from set
			auto topElement = *(st.begin());
			int nodeDistance = topElement.first;
			int node = topElement.second;

			//pop from set
			st.erase(st.begin());

				//neighbour traverse
			for(auto nbr: adjList[node]) {
				if(nodeDistance + nbr.second < dist[nbr.first]) {
					//mujhe distance update krna h 
					//finding entry in set
					auto result = st.find(make_pair(dist[nbr.first], nbr.first));
					//if found, then remove
					if(result != st.end()) {
						st.erase(result);
					}
					//updation in dist array and set
					dist[nbr.first] = nodeDistance + nbr.second;
					st.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}
			
		}

		cout << "printing ans:" << endl;
		for(int i=0; i<n; i++) {
			cout << dist[i] <<", ";
		}cout << endl;
		
	}

};

int main() {
	graph g;

	g.addEdge(0,1,3,0);
	g.addEdge(0,3,5,0);
	g.addEdge(1,0,2,0);

	g.addEdge(1,3,4,0);
	g.addEdge(2,1,1,0);
	g.addEdge(3,2,2,0);
	
	// g.addEdge(3,2,5,0);
	// g.addEdge(4,3,-3,0);
	// g.addEdge(3,1,1,0);
	// g.addEdge(6,3,2,1);
	// g.addEdge(6,1,14,1);
	// g.addEdge(3,1,9,1);
	// g.addEdge(3,2,10,1);
	// g.addEdge(1,2,7,1);
	// g.addEdge(2,4,15,1);
	// g.addEdge(4,3,11,1);

	// g.addEdge(6,5,9,1);
	// g.addEdge(4,5,6,1);
 

	g.printAdjList();
	g.floydWarshal(4);
	//g.bellmanFordAlgo(5, 0);
	//g.shortestDistDijkstra(0,3);

	// stack<int> topoOrder;
	// unordered_map<int, bool> visited;
	// g.topoSortDfs(0, visited, topoOrder);

	

	// g.shortestpathDfs(3, topoOrder,5);
	
	

	// int src = 0;
	// // int dest = 4;

	// g.shortestPathBfs(src, dest);


	return 0;
}




 




