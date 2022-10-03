#include<iostream>
#include<vector>

using namespace std;

void printBranch(vector<int> branch){
    for (int i = 0; i < branch.size(); i++){
        cout<<branch[i]<<endl;
    }

    cout<<endl;
}
vector<int> bactrackingBranches(vector<int> arr, vector<int> branch){
    if (arr.empty()){
        return branch;
    }
    vector<vector<int>> branches;
    for (int i = 0; i < arr.size(); i++){
        int pop = arr[i];
        arr.erase(arr.begin() + i);

        branch.push_back(pop);
        cout<<"branch: "<<pop<<endl;
        printBranch(branch);
        branch = bactrackingBranches(arr, branch);
        branches.push_back(branch);
        branch.pop_back();
        arr.push_back(pop);
        // cout<<"array now: "<<endl;
        // printBranch(arr);
        // return branch;
    }
    return branch;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> empty;
    bactrackingBranches(arr, empty);
    return 0;
}