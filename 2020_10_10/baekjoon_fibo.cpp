#include <iostream>

using namespace std;

void fibonacci(int, int&, int&);

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        int answer[2] = { 1 , 1};
        

        fibonacci(N, answer[0], answer[1]);

        if(N > 1)
            cout << answer[0] << " " << answer[1] << endl;
    }
    
	return 0;
}

void fibonacci(int n, int& ans1, int& ans2)
{ 
    int temp = 0;
    int ans = 2;
    
    if (n == 0)
    {
        cout << 1 << " " << 0 << endl;
    }

    if (n == 1)
    {
        cout << 0 << " " << 1 << endl;
    }


    for (int i = 2; i < n; i++)
    {       
        temp = ans;
        ans1 = ans2;
        ans2 = temp;
      
        ans = ans1 + ans2;
    }
}


//int fibonacci(int n, int &ans1, int &ans2) 
//{
//    if (n == 0) 
//    {
//       ans1 ++;
//        return 0;
//    }
//    else if (n == 1)
//    {
//        ans2 ++;
//        return 1;
//    }
//    else 
//    {
//        return fibonacci(n - 1, ans1, ans2) + fibonacci(n - 2, ans1, ans2);
//    }
//}