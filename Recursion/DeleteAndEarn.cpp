#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int Recursive(vector <int> nums, int score){
        if(nums.size() == 0){
            return 0;
        }
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            vector <int> temp;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] != nums[i]-1 && nums[j] != nums[i]+1 && j!=i){
                    temp.push_back(nums[j]);
                }
            }
            score = nums[i] + Recursive(temp, score);
            maxi = max(maxi, score);
        }
        return maxi;
    }
    
    int main()
    {
        vector <int> v{8,3,4,7,6,6,9,2,5,8,2,4,9,5,9,1,5,7,1,4};
        int ans = Recursive(v, 0);
        cout << ans << endl;
        
        return 0;
    }