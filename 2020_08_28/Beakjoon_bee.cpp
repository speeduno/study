#include <iostream>

using namespace std;

int main()
{
	int Nroom;	
	int answer = 0;

	cin >> Nroom;	

	int temp = 1;
	int idx = 0;

	while (true)
	{
		if (temp >= Nroom)
		{
			answer = idx + 1;
			break;
		}

		idx++;
		temp += (idx * 6);
	}

	cout << answer << endl;

	return 0;
}