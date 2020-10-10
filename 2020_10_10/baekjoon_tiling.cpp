#include <iostream>

//2 X N 크기의 직사각형을 1 X 2 , 2X1타일로 채우는 방법의수

//DP 문제이다.

//DP문제 특징 우선 답을 구하고 그에 따른 규칙 찾아내기

//N == 1 -> 1
//N == 2 -> 2
//N == 3 -> 3
//N == 4 -> 5		//fibonacci 수열이다.... 
//하지만 딴 방법도 찾아볼것.....

using namespace std;

int fibonacci(int);

//답을 10007로 나눈 나머지값을 구할것
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
