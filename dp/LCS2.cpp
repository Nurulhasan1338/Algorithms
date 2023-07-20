// Dynamic Programming C++ implementation
// of LCS problem

// print the LCS 

#include <bits/stdc++.h>
using namespace std;


string lcs(string X, string Y, int m, int n)
{
      string ans = "";
	int L[m + 1][n + 1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1]){
				L[i][j] = L[i - 1][j - 1] + 1;
}
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

    ans = "";

    int i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j-1]){
            ans =  X[i-1] + ans; 
            i--;
            j--;
            ; 
        }
 

        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }



	return ans;
}

// Driver code
int main()
{
	string S1;
	string S2 ;
  cin>>S1>>S2;
  
  
	int m = S1.size();
	int n = S2.size();

	// Function call
	cout << lcs(S1, S2, m, n)<<endl;

	return 0;
}
