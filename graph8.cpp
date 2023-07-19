//graph last lecture 8th
//sunday 2/7/2023


//important topics
//1st algorithm
//SCC
//1 strongly connected components means
//kisibhi ek vertex se hum kisibhi vertex pr pohch skte hai
//prerequisite
//1 reverse adjlist 
//2 topological sort
//3 dfs

//question on this is either count SCC or print SCC
//approach
//starting kaha se kre src konsa hoga SCC nyi kahase shuru ho rhi hai

// 3 steps process
//1 find out ordering in which we should traverse the graph //topo order
//2 reverse edges (all) qki hme individually hr ek SCC ko access kr payenge
//agr reverse hi kiya to sara graph   traverse hoga or SCC cnt pta bhi nhi chlega
//3 cout components
//KosaRaju algorithm


//2 Bridge in graph (bridge yani edge)
///second algorithm
//ye algorithm tumne pehle se pdha hua hona chahia tbhi tumhe aayega
//tarjan algorithm
//try removing each edge agr count increase kr gya to edge bridge this
//agr bridge remove hau to more graph ke components bnegnge

//tin -> insertion time
//low-> low insertion time
//vaps aate vkt check kro ki ye bridge hai ya nhi
//parent ko dekh ke low ko update nhi krne vaise hi krna update
//path possible hai and visited hai then update low
//agr parent to child only 1 path hai to O bridge hai simple

//d->c
//low[child]>low[parent]
//iska mtlb c tak sirf d se poch ske hai then c-d is bridge
//and
//low[child]<low[parent]
//c se kahi or se bhi pohcha ja skta hai so c-d is not bridge

//and low ka comparison parent se kbhi mt krna
//nbr mila koi not visited to call krde dfs ka
//call se vaps aayoge to low ko update jrdo
//and low update hone ke baad check kro ki bridge hai ya nhi
//bnr visited hai to low update

//new node pe dono time same rkhenge 1/1
//waps jana call se then low ko update kro  yani tumtk pohchna ka koi chota rasta hai
//and check for bridge kro 4 sirf 3 ke dwara pocha hai to ye bridge hai










#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class Graph {
	public:
	unordered_map<int, list<int>  > adjList;

	void addEdge(int u, int v, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back(v);
		if(direction == 1) {
			adjList[v].push_back(u);
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






 void dfs1(int src, stack<int>& s, unordered_map<int,bool>& vis) {
        vis[src] = true;

        for(auto nbr: adjList[src]) {
            if(!vis[nbr]) {
                dfs1(nbr, s, vis);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int> >& adjNew) {
        visited[src] = true;
        cout << src << ", ";

        for(auto nbr: adjNew[src]) {
            if(!visited[nbr] ) {
                dfs2(nbr, visited, adjNew);
            }
        }
    }
    
    int countSCC(int n) {
        stack<int> s;
        unordered_map<int,bool> visited;

        //find topo ordering
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs1(i,s,visited);
            }
        }

        //reverse all edges
        unordered_map<int,list<int> > adjNew;
        
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr;
                //v-> u insert
                adjNew[v].push_back(u);
            }
        }

        //traversse using DFS
        int count = 0;
        unordered_map<int,bool> visited2;

        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited2[node]) {
                cout << "Printing "<< count+1 << "th SCC: ";
                dfs2(node,visited2, adjNew);
                cout << endl;
                count++;
            }

            
        }

        

        return count;
    }




//2 Bridge in graph (bridge yani edge)
///second algorithm
//ye algorithm tumne pehle se pdha hua hona chahia tbhi tumhe aayega
//tarjan algorithm
//try removing each edge agr count increase kr gya to edge bridge this
//agr bridge remove hau to more graph ke components bnegnge

//tin -> insertion time
//low-> low insertion time
//vaps aate vkt check kro ki ye bridge hai ya nhi
//parent ko dekh ke low ko update nhi krne vaise hi krna update
//path possible hai and visited hai then update low
//agr parent to child only 1 path hai to O bridge hai simple

//d->c
//low[child]>low[parent]
//iska mtlb c tak sirf d se poch ske hai then c-d is bridge
//and
//low[child]<low[parent]
//c se kahi or se bhi pohcha ja skta hai so c-d is not bridge

//and low ka comparison parent se kbhi mt krna
//nbr mila koi not visited to call krde dfs ka
//call se vaps aayoge to low ko update jrdo
//and low update hone ke baad check kro ki bridge hai ya nhi
//bnr visited hai to low update

//new node pe dono time same rkhenge 1/1
//waps jana call se then low ko update kro  yani tumtk pohchna ka koi chota rasta hai
//and check for bridge kro 4 sirf 3 ke dwara pocha hai to ye bridge hai



//problem
//1 critical connections in server



    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool> vis) {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr: adjList[src]) {
            if(nbr == parent)
                continue;
            if(!vis[nbr]) {
                //dfs call
                findBridges(nbr, src, timer, tin, low, vis);
                //low update
                low[src] = min(low[src], low[nbr]);
                //check for bridge
                if(low[nbr] > low[src]) {
                    cout << nbr<<"--"<<src <<" is a bridge" << endl;
                }
            }
            else{
                //node is visited and not a parent
                //low update
                low[src] = min(low[src], low[nbr]);
            }
        }
        
        
    }












};


int main() {
	Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,0,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,6,0);
    g.addEdge(6,4,0);
    g.addEdge(6,7,0);

    int ans=g.countSCC(8);
    cout<<"Number of SCC"<<ans<<endl;
    



	return 0;
}




//problem
//1 critical connections in server leetcode
class Solution {
public:

    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, vector<vector<int>>& ans, unordered_map<int, list<int> >& adjList) {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr: adjList[src]) {
            if(nbr == parent)
                continue;
            if(!vis[nbr]) {
                //dfs call
                findBridges(nbr, src, timer, tin, low, vis, ans, adjList);
                //low update
                low[src] = min(low[src], low[nbr]);
                //check for bridge
                
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else{
                //node is visited and not a parent
                //low update
                low[src] = min(low[src], low[nbr]);
            }
        }
        
        
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int> > adjList;


        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
                    int timer = 1;
                vector<int> tin(n);
                vector<int> low(n);
                unordered_map<int,bool> vis;
        findBridges(0, -1,timer, tin, low, vis, ans,adjList);

        return ans;

    }
};




 




