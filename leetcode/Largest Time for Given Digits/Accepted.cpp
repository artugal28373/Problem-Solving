/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 00:05                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 9.5 MB                               
*  problem: https://leetcode.com/problems/largest-time-for-given-digits
****************************************************************************************/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int hh=-1,mm=-1;
        do
        {
            int h=arr[0]*10+arr[1];
            int m=arr[2]*10+arr[3];
                        if(h<=23 && m<=59)
            {
                if(h>hh)hh=h,mm=m;
                else if(h==hh)mm=max(mm,m);
            }
                    }while(next_permutation(arr.begin(),arr.end()));
                if(hh==-1)return "";
        string s;
        s.push_back(hh/10 +'0');
        s.push_back(hh%10 +'0');
        s.push_back(':');
        s.push_back(mm/10 +'0');
        s.push_back(mm%10 +'0');
                return s;
    }
};