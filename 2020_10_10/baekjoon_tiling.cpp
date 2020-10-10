#include <iostream>

//2 X N ũ���� ���簢���� 1 X 2 , 2X1Ÿ�Ϸ� ä��� ����Ǽ�

//DP �����̴�.

//DP���� Ư¡ �켱 ���� ���ϰ� �׿� ���� ��Ģ ã�Ƴ���

//N == 1 -> 1
//N == 2 -> 2
//N == 3 -> 3
//N == 4 -> 5		//fibonacci �����̴�.... 
//������ �� ����� ã�ƺ���.....

using namespace std;

int fibonacci(int);

//���� 10007�� ���� ���������� ���Ұ�
int main()
{
    int answer = 0;

	int N;
	cin >> N;

    answer = fibonacci(N);

    cout << answer << endl;

	return 0;
}

int fibonacci(int n)
{
    int temp = 0;
    int exans = 1;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        temp = ans;
        ans = (ans + exans) % 10007;
        exans = temp;  
    }    

    return ans;
}
