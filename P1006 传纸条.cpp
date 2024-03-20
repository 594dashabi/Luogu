// 和P1004方格取数异曲同工
#include <iostream>
using namespace std;
int m, n;
int map[55][55];
int dp[55][55][55][55];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    int tmp1 = max(dp[i][j - 1][k][l - 1], dp[i - 1][j][k - 1][l]);
                    int tmp2 = max(dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1]);
                    dp[i][j][k][l] = max(tmp1, tmp2) + map[i][j] + map[k][l];
                    if (i == k && j == l)
                    {
                        dp[i][j][k][l] -= map[i][j];
                    }
                }
            }
        }
    }

    cout << dp[m][n][m][n] << endl;
}
