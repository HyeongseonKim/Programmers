#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int d(int i, int j, vector<int>* status);

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    vector<int> *originStatus = new vector<int>(n,0);
    vector<int> *status = new vector<int>(n,0);
    vector<vector<int>> *DM = new vector<vector<int>>(n+1, vector<int> (n+1, 0));
    
    for (int i=0; i<lost.size(); i++) {
        (*status)[lost[i]-1] -= 1;
    }
    
    for (int i=0; i<reserve.size(); i++) {
        (*status)[reserve[i]-1] += 1;
    }
    
    copy((*status).begin(), (*status).end(), (*originStatus).begin());
    
    // Check for status
    for (int i=0; i<n; i++) {
        cout << (*status)[i] << " ";
    }
    cout << endl << endl;
    
    // Check for DM
    /*
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
            cout << (*DM)[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if ((*DM)[i][j-1] >= (*DM)[i-1][j])
            {
                (*DM)[i][j] = d(i-1, j-1, status) + (*DM)[i][j-1];
            }
            else
            {
                (*DM)[i][j] = d(i-1, j-1, status) + (*DM)[i-1][j];
            }
        }
    }
    
    
    // Check for DM
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
            cout << (*DM)[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i=0; i<n; i++) {
        cout << (*status)[i] << " ";
    }
    
    cout << endl;
    
    for (int i=0; i<n; i++) {
        
        if ((*originStatus)[i] == 0 ||  (*originStatus)[i] == 1)
            (*DM)[n][n] += 1;
    }
    
    
    int answer = (*DM)[n][n];
    return answer;
}


int d(int i, int j, vector<int>* status) {
    
    if (i != j){
        if (abs(i-j) != 1)
            return 0;
    }
    
    if ((*status)[j] == 0)
        return 0;
    
    if ((*status)[j] == 1){
        return 0;
    }
    
    if ((*status)[j] == -1)
    {
        if ((*status)[j-1] == 1) {
            (*status)[j-1] -= 1;
            (*status)[j] += 1;
            return 1;
        } else if ((*status)[j+1] == 1) {
            (*status)[j+1] -= 1;
            (*status)[j] += 1;
            return 1;
        } else {
            return 0;
        }
    }
}