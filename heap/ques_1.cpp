
// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
// Example 1:

// Input:
// K = 3
// arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation:Above test case has 3 sorted
// arrays of size 3, 3, 3
// arr[][] = [[1, 2, 3],[4, 5, 6], 
// [7, 8, 9]]
// The merged list will be 
// [1, 2, 3, 4, 5, 6, 7, 8, 9].


// approch is efficient
// In the Efficient solution I have kept the track of three 
// elements → value , position of array, position of value in array.
// Firstly insert all the 0th indexed elements of each array.
// After that, run a loop until priority queue becomes empty
// and then extract min and insert next item of same array as
//  soon as this condition goes true (vp+1<K).

typedef pair<int,pair<int,int>>triplet;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    
        //code here
        vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet,vector<triplet>,greater<triplet>>pq;
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,0}});
        }
        vector<int>res;
        while(!pq.empty()){
            triplet curr=pq.top();
            pq.pop();
            res.push_back(curr.first);
            int ap=curr.second.first;
            int vp=curr.second.second;
            if(vp+1<K){
                pq.push({arr[ap][vp+1],{ap,vp+1}});
            }
        }
        return res;
    
         
    }
};