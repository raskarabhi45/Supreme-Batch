//graph 5th lecture
//veryyyy veryyy important questionsssssssss
//interview for sureeeeeeeeeeeeeeeeeeeeeeeee
//questions

//1 Number of provinces(component) leetcode
//province means directly or indirectly connected ex cities
//yapar adjlist nhi hai matrix hai to hme sare ke sare col pe jana pdega
class Solution {
    private:
    void dfs(unordered_map<int,bool>& vis, int src, vector<vector<int>>& isConnected) {
        //cout << "received a call for src: " << src << endl;
        vis[src] = true;
        //row -> src
        //col -> we will write a loop
        int size = isConnected[src].size();
        for(int col=0; col<size; col++) {
            if(src != col && isConnected[src][col] == 1) {
                //col is a nbr
                if(!vis[col] ) {
                    dfs(vis,col, isConnected);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int count = 0;
        int n = isConnected.size();
        //i represents nodes here
        for(int i=0; i< n; i++)  {
            if(!visited[i]) {
                //cout << "calling for src: "<< i << endl;
                dfs(visited, i, isConnected);
                count++;
            }
        }
        return count;
    }
};


//2  Number of islands
//island vhi hota hai jiske charo trf pani hota hai
//anddd yahapr 1 yani jmeen and 0 yani panii inn the matrix
//queue empty ho gyi hai yani ki ek island mil gya hai simple it is
//directions
//                    (row-1,col) //row me -1 add kr rhe hai
// yha 0(row,col-1) <- (row,col) -> (row,col+1)   ya pe 0
//                    row,col+1  yaha pe +1
//dx(-1,0,1,0)
//dy(0,1,0,1)

class Solution {
    private: 
    void bfs(map< pair<int,int> , bool >& visited, int row, int col, vector<vector<char>>& grid) {
        queue<pair<int,int> > q;
        //initial steps
        q.push({row,col});
        visited[{row,col}] = true;

        while(!q.empty()) {
            pair<int,int> fNode = q.front();
            q.pop();
            int x = fNode.first;
            int y = fNode.second;

            //i can move in 4 directions
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if( newX >=0 && newX < grid.size() && newY>=0 && newY < grid[0].size() &&
                    !visited[{newX, newY}] && grid[newX][newY] == '1') {
                        q.push({newX, newY});
                        visited[{newX, newY}] = true;
                }

            } 
    }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        map< pair<int,int> , bool > visited;
        int count = 0;

        for(int row=0; row<grid.size(); row++) {
            int n = grid[row].size();
            for(int col=0; col<n; col++) {
                //tum yha glti kroge
                if(!visited[{row,col}] && grid[row][col] == '1') //hum call sirf tbhi krnege jb us location pe 1 hoga{
                    bfs(visited, row, col,grid);
                    count++;
                }
            }
        }
        return count;
    }
};


//flood fill algorithm
//3 Flood fill 

class Solution {
private:
void dfs(int x,int y,int oldColor,int newColor,map<pair<int,int>,bool> & visited,vector<vector<int>> &image,vector<vector<int>>&arr){

visited[{x,y}]=true;
arr[x][y]=newColor;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
for(int i=0;i<4;i++){
    int newX=x+dx[i];
    int newY=y+dy[i];

//check boundary conditions  and other
    if(newX>=0 && newY>=0 && newX<arr.size() && newY<arr[0].size() &&
    !visited[{newX,newY}] && arr[newX][newY]==oldColor){
        dfs(newX,newY,oldColor,newColor,visited,image,arr);
        
    }
}


}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

         //using dfs
         int oldColor=image[sr][sc];
         map<pair<int,int>,bool>visited;
         //sr source column and sc source destination
         vector<vector<int>> ans=image;
        dfs(sr,sc,oldColor,newColor,visited,image,ans);
        return ans;
        
    }
};


//reviseeeeeeeeeeeeeeeeeeeeeeeeeeeee
//4 Rorring oranges
//sare ka sare oranges ko sdane ke lia kitna minimum time lgaega btao
//using bfs qki level wise rotten honge and order matter kra hai yahape
//algo
//queue me sare rotten orgamne
// and then bfs

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int> , int > > q;
        vector<vector<int>> arr = grid;
        int count = 0;
        int ansTime = 0;
        //insert all rotten oranges in queue
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[row].size(); col++ ) {
                if(grid[row][col] ==2) {
                    //rotten orange found
                    pair<int,int> coordinate = make_pair(row, col);
                    q.push({coordinate,0});
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int,int> , int > fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() &&
                 arr[newX][newY] == 1) { //1 yani fresh orange aaya to rott kro
                     pair<int,int> newCoordinates = make_pair(newX, newY);
                     ansTime = max(ansTime, time+1);
                     q.push({newCoordinates, time + 1});
                     //mark rotten
                     arr[newX][newY] = 2;
                 }
            }


        }

        //chec for fresh orange
        for(int i=0;i<arr.size(); i++) {
            for(int j=0;j<arr[0].size();j++) {
                if(arr[i][j] == 1) {
                    return -1;
                }
            }
        }
       return ansTime;

    }
};