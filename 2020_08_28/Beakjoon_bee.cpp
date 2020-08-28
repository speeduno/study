#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    int tempans = (n - lost.size());

    bool* reserveswitch = new bool[reserve.size()];
    for (int i = 0; i < reserve.size(); i++)
    {
        reserveswitch[i] = false;
    }

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (reserveswitch[j] == true)
                continue;

            if (lost[i] == reserve[j])
            {
                tempans++;
                reserveswitch[j] = true;
                break;
            }
        }

        for (int j = 0; j < reserve.size(); j++)
        {
            if (reserveswitch[j] == true)
                continue;     

            if (lost[i] == reserve[j] - 1)
            {
                tempans++;
                reserveswitch[j] = true;
                break;
            }

            if (lost[i] == reserve[j] + 1)
            {
                tempans++;
                reserveswitch[j] = true;
                break;
            }
        }
    }

    answer = tempans;

    return answer;
}