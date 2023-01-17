// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
// Output: 3
// Explanation: We can divide the intervals into the following groups:
// - Group 1: [1, 5], [6, 8].
// - Group 2: [2, 3], [5, 10].
// - Group 3: [1, 10].
// It can be proven that it is not possible to divide the intervals into fewer than 3 groups.


// code 

    int minGroups(vector<vector<int>>& inte) {
        // first the array
        sort(inte.begin(),inte.end());
        
       priority_queue<int, vector<int>, greater<int>> pq;
        
        for(const auto i : inte){
            if(!pq.empty() && pq.top()<i[0]){
                pq.pop();
            }
            pq.push(i[1]);
        }
        return pq.size();

// expalnation
// first these intevals will be in the min heap 
// right part of interval
// - Group 1: [5]
// - Group 2: [3]
// - Group 3: [10]

// now minimum will come and if it is smaller than incoming element the it will pop and the element will bw push
// - Group 1: [5]
// - Group 2: [10]
// - Group 3: [10]

// ans so on.......

// at last size of minheap will be ans

