#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int totalgas = 0;
    int totalcost = 0;
    int starti = 0, curri = 0;
    int count = 0;
    
    int sumgas = 0;
    int sumcost = 0;
    
    for(int i=0;i<A.size();i++)
        sumgas += A[i], sumcost += B[i];
    
    if(sumgas < sumcost) return -1;
    int n = A.size();
    while(count < n)
    {
        totalgas += A[curri%n];
        totalcost += B[curri%n];
        
        cout << starti <<" " << curri << " "  << endl;
        cout << totalcost << " " << totalgas << endl;
        while(totalcost > totalgas && curri >= starti)
        {
            totalgas -= A[starti%n];
            totalcost -= B[starti%n];
            cout << "in" << endl;
            starti++;
            count--;
        }
        
        count++;
        curri++;
        cout << totalcost << " " << totalgas << endl;
        cout << starti <<" " << curri << " "  << endl;
        cout << "***************" << endl;
    }
    
    return starti%n;
}

int main()
{
    vector<int> A = {204,918,18,17,35,739};
    vector<int> B = {273,790,131,367,914,140};

    cout << canCompleteCircuit(A,B) << endl; 

    return 0;
}