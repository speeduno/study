#include <string>
#include <vector>

using namespace std;

// ³Êºñ ¿ì¼± Å½»ö
// ±íÀÌ ¿ì¼± Å½»ö

int solution(string s)
{
    int answer = s.size();

for (int cutsize = 1; cutsize <= s.size() / 2; cutsize++)
{
    int tempans = s.size();

    for (int idx = 0; idx < s.size(); idx++)
    {
        int count = 0;  
     
        for (int cutstart = cutsize; cutstart + idx < s.size(); cutstart += cutsize)
        {        
            if (s.substr(idx, cutsize) == s.substr(idx + cutstart, cutsize))
            {
                count++;    
            }

            else
            {
                tempans -= count * cutsize;

                if (count > 0)
                {
                    tempans += to_string(count + 1).size();
                }

                idx += (cutstart - 1);
                break;
            }
                    
            if (cutsize + idx + cutstart >= s.size())
            {                             
                tempans -= count * cutsize;
                tempans += to_string(count + 1).size();
                idx += cutstart;
               
            }
        }
   
        if (answer > tempans)
            answer = tempans;

    }
}
return answer;
}