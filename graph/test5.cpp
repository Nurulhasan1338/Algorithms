#include <bits/stdc++.h>
using namespace std;

int countOperations(string& series) {
    int operations = 0;
    char prevChar = '\0'; // Initialize previous character with a null character

    for (char c : series) {
        if (c != prevChar) {
            operations++;
            cout<<"Sdfs"<<endl;
            prevChar = c;
        }
    }

    return operations;
}


int main()
{
    
	string s;
    cin>>s;
    int ans=countOperations(s);
  cout<<ans;
return 0;
}