#include<iostream>
#include<vector>

using namespace std;

void printBranch(vector<int> branch){
    cout<<"current branch: "<<endl;
    for (int i = 0; i < branch.size(); i++){
        cout<<branch[i]<<endl;
    }

    cout<<endl;
}
vector<vector<int>> backtrackingBranches(vector<int> arr, vector<int> branch, vector<vector<int>> branches){
    if (arr.empty()){
        branches.push_back(branch);
        printBranch(branch);
        return branches;
    }
    for (int i = 0; i < arr.size(); i++){
        int pop = arr[i];
        arr.erase(arr.begin() + i);
        branch.push_back(pop);
        cout<<"building: "<<endl;
        printBranch(branch);
        branches = backtrackingBranches(arr, branch, branches);
        arr.push_back(pop);
        branch.pop_back();
    }

    return branches;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> empty;
    vector<vector<int>> branches;
    branches = backtrackingBranches(arr, empty, branches);
    return 0;
}