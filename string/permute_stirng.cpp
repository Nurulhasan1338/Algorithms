
// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.
// Example 1:
// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBAprivate:


        void perH(int index , string S , set<string>&st){
            st.insert(S);
            
            for(int i = index; i< S.length(); i++){
                swap(S[index],S[i]);
                perH(index+1 , S , st);
                swap(S[index],S[i]);
            }
        }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>str;
		    set<string>st;
		    perH(0 , S ,st);
		    for(auto it : st){
		        str.push_back(it);
		    }
		    return str;
		}