//graph 6th lecture 
//26/6/2023 wednesday
//questionssssss on shortest path 

//1 Course Schedule leetcode
//kya me sare course khatm kr skta hu ya nhi ye btana hai
//ek course dusre course pe depend hai to 
//topological sort valid tb aata hai cycle detection dag
class Solution {

    private:
    bool topoSortBfs(int n, unordered_map<int,list<int>> &adjList)
	{
		vector<int>ans;
		queue<int> q;
		unordered_map<int, int> indegree; // to store the indegree that is connected number of graphs

		// indegree calculate
		for (auto i : adjList)
		{
			int src = i.first;
			for (auto nbr : i.second)
			{ // i.second means list hogi
				indegree[nbr]++;
			}
		}

		// put all nodes inside queue, which has indegree=0
		for (int i = 0; i < n; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}

		// bfs logic
		while (!q.empty())
		{
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			// or we can do count++

			for (auto nbr : adjList[fNode])
			{
				indegree[nbr]--;
				// check for zero again
				if (indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
		}

        if(ans.size()==n){
            return true; //valid topo sort
        }
        else
        {  //invalid
            return false;
        }
	}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,list<int>>adjList;

        //created adjencency list
        for(auto task:prerequisites){
            int u=task[0];
            int v=task[1];
            adjList[v].push_back(u);
            
        }
				bool ans=topoSortBfs(numCourses,adjList);
            return ans;
    }

};


//2 course schedule 2
//same as above just array return krna hai
class Solution {
    private:
    vector<int> topoSortBfs(int n, unordered_map<int,list<int>> &adjList)
	{
		vector<int>ans;
		queue<int> q;
		unordered_map<int, int> indegree; // to store the indegree that is connected number of graphs

		// indegree calculate
		for (auto i : adjList)
		{
			int src = i.first;
			for (auto nbr : i.second)
			{ // i.second means list hogi
				indegree[nbr]++;
			}
		}

		// put all nodes inside queue, which has indegree=0
		for (int i = 0; i < n; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}

		// bfs logic
		while (!q.empty())
		{
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			// or we can do count++

			for (auto nbr : adjList[fNode])
			{
				indegree[nbr]--;
				// check for zero again
				if (indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
		}

        if(ans.size()==n){
            return ans; //valid topo sort
        }
        else
        {  //invalid
            return {};
        }
	}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;

        //created adjencency list
        for(auto task:prerequisites){
            int u=task[0];
            int v=task[1];
            adjList[v].push_back(u);
            
        }
				vector<int> ans=topoSortBfs(numCourses,adjList);
                return ans;
    }
};





//3 Word ladder
///hit se jana hai cog ke upr and during conversion there are certain conditions
//agli string pe jane pe only 1 charcater chnage kr skte hai hum
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        //wordlist ki copy kr di hai set me
        //jo bhi word q mu insert krunga to usko set me se remove kr dunga 
        st.erase(beginWord);

        while(!q.empty()){
            pair<string,int> fNode=q.front();
            q.pop();

            string currString=fNode.first;
            int currCount=fNode.second;

            //check kahi destination tk toh nahi poch gye
            if(currString==endWord){
                return currCount;
            }

            for(int index=0;index<currString.length();index++){
                //hr index pr jo val hai usko mai 'a' to 'z' se replace krunga
                char originalCharacter=currString[index];  //taki niche change honi wale val na bdle

                for(char ch='a';ch<='z';ch++){
                    currString[index]=ch;
                    //check in wordlist  that is in the set
                    if(st.find(currString)!=st.end()){
                        //agr set me present hai to q me insert jro
                        q.push({currString,currCount+1});
                        st.erase(currString);  //erase islia ki visited wala data structure nhi banaya

                    }
                }
                //bringinbg back the currstring to its original ststa
                currString[index]=originalCharacter;            }
        }
        return 0;
    }

};



//4 Path With Minimum Effort
//initail steps
//prioritry queue me kuch push krna hoga and distance 0 as source location
//q me distance ,location udate kro priority_queue<int,pair<int,int>>;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //initail stages
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;;//distance and coordinates
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;

        while(!pq.empty()){
            auto fNode=pq.top();
            pq.pop();
            int frontNodeDiff=fNode.first;
            int x=fNode.second.first;
            int y=fNode.second.second;

            //check ans tak toh nhi poch gye
            if(x==heights.size()-1 && y==heights[0].size()-1){
                return dist[x][y];
            }

           //directions
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];

                if(newX >=0 && newY>=0 && newX<heights.size() && newY<heights[0].size()){
                    int currDiff=abs(heights[x][y]-heights[newX][newY]);
                    int newMax=max(frontNodeDiff,currDiff);
                    if(newMax<dist[newX][newY]){
                        dist[newX][newY]=newMax;
                        pq.push({newMax,{newX,newY}});
                    }

                }
            }
        }

        return 0;
    }
};

