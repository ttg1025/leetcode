#include <iostream>
#include <stdio.h>
#include <vector>
#include <windows.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res;
        if (A.empty()) return res;
        int m = A.size(),n = A[0].size();
        for (int i = 0; i < n; ++i) {
            vector<int> vec;
            for(int j = 0; j < m; ++j) {
                vec.push_back(A[j][i]);

            }
            res.push_back(vec);
        } 
        return res;

    }
};

int main() {
    Solution solu;
    int a[3] = {1,2,3};
    int b[3] = {4,5,6};
    int c[3] = {7,8,9};

    vector<int> Arow;
    vector<int> Brow;
    vector<int> Crow;
    Arow.push_back(a[0]);
    Arow.push_back(a[1]);
    Arow.push_back(a[2]);
    Brow.push_back(b[0]);
    Brow.push_back(b[1]);
    Brow.push_back(b[2]);
    Crow.push_back(c[0]);
    Crow.push_back(c[1]);
    Crow.push_back(c[2]);

    vector<vector<int>> row;
    row.push_back(Arow);
    row.push_back(Brow);
    row.push_back(Crow);

    vector<vector<int>> rowTest = solu.transpose(row);
    for (vector<vector<int>>::iterator it=rowTest.begin(); it != rowTest.end(); it++){
        for(vector<int>::iterator it2=(*it).begin(); it2 != (*it).end(); it2++){
            cout << *it2 <<" ";
        }
        cout << endl;
    }
    
   system("pause");
   return 0;
    
}