// 虽然题目中说到了“掉头”问题，但是其实不必考虑
// 因为要掉头的蚂蚁向反方向走到头，和对面的蚂蚁“穿过”它走到头的时间是一样的
// 因此无需考虑掉头问题，而只需考虑每一只蚂蚁走到头的最长/最短时间
// 总时间只取决于所需时间最长的蚂蚁，因此无论求总时间最长还是总时间最短，都要对所有的蚂蚁取一个max
#include <iostream>
using namespace std;
int L, N;

int main()
{
    cin >> L >> N;
    int minn = 0, maxx = 0;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        // 总时间最长是每只蚂蚁的最长时间的最大值（max的max）
        maxx = max(maxx, max(tmp, L + 1 - tmp));
        // 总时间最短是每只蚂蚁的最短时间的最大值（min的max）
        minn = max(minn, min(tmp, L + 1 - tmp));
    }
    cout << minn << ' ' << maxx << endl;
}
