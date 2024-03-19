#include <iostream>
using namespace std;
int N;
int map[10][10];
int dp[10][10][10][10];

int main()
{
    cin >> N;
    int a, b, c;
    while (cin >> a >> b >> c && a && b && c) // 保证输入合法就一直输入
    {
        map[a][b] = c;
    }
    // 做两遍单次dp求出来的可能不是全局最优
    // 因此将两次合在一起。dp[i][j][k][l]表示第一次走到（i，j），第二次走到（k，l）的最优值。
    // 每一次都各自只有两种可能性到（i，j）或（k，l），因此就是四个dp求最大值
    // 这四个dp到原点的“距离”相等“，因此相当于在相同步数条件下，能够达到的最大值
    // 当前格子的最大值就是四个上一次的最大值（走两遍都包括进去了）加上它本身的值
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                for (int l = 1; l <= N; l++)
                {
                    int tmp1 = max(dp[i][j - 1][k][l - 1], dp[i - 1][j][k - 1][l]);
                    int tmp2 = max(dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1]);
                    dp[i][j][k][l] = max(tmp1, tmp2) + map[i][j] + map[k][l];
                    if (i == k && j == l) // 如果两次走到了同一点，则不能反复累加
                    {
                        dp[i][j][k][l] -= map[i][j];
                    }
                }
            }
        }
    }

    cout << dp[N][N][N][N] << endl;
}