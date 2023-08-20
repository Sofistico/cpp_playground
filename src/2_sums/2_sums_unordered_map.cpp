
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map = {};
    for(int i = 0; i < nums.size(); i++){
        if(map.find(target - nums[i]) != map.end())
            return {map[target - nums[i]], i};
        else
            map.insert({nums[i], i});
    }
    return {};
}


int main(){
    cout<<"Hello World"<<endl;
    vector<int> vec = vector<int>{3,2,4};
    auto sol = twoSum(vec, 6);
    for(auto i: sol){
        cout<<i<<endl;
    }

    return 0;
}