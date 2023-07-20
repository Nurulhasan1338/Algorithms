#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        vector<vector<int>> cir;
        vector<vector<int>> gh(Y + 2);

        for (int i = 0; i < Y; i++)
        {
            vector<int> temp(3);
            cin >> temp[0] >> temp[1] >> temp[2];

            if (temp[0] - temp[2] <= 0)
            {
                gh[0].push_back(i + 2);
                gh[i + 2].push_back(0);
            }

            if (temp[0] + temp[2] >= X)
            {

                gh[1].push_back(i + 2);
                gh[i + 2].push_back(1);
            }

            for (int j = 0; j < cir.size(); j++)
            {  float left = pow((cir[j][0]-temp[0]),2)+pow((cir[j][1]-temp[1]),2);
               float right = pow((cir[j][2]+temp[2]),2);
                bool check = left<=right?true:false;
                if (check)
                {
                
                    gh[i + 2].push_back(j + 2);
                    gh[j + 2].push_back(i + 2);
                }
            }
            cir.push_back(temp);
        }
        vector<int> vis(Y + 2, 0);
        vector<int> dis(Y + 2, -1);
        vis[0] = 1;
        dis[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            for (auto x : gh[a])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    dis[x] = dis[a] + 1;
                    q.push(x);
                }
            }
        }

        if (dis[1] == -1)
            cout<<"NO"<<endl;

        else
            cout<<"Yes"<<endl;
    }

    return 0;
}