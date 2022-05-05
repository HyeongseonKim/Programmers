#include <string>
#include <vector>
#include <iostream>
#include <stack>


using namespace std;

int dRow[] = {0, 1, 0, -1};
int dCol[] = {-1, 0, 1, 0};

int answer = 0;
int COL; int ROW;
vector< vector< bool > > visited( 200, vector<bool>( 200, false ));
vector<vector<int>> computers;

bool isValid(int row, int col) {
    // 셀이 넘어가면 false
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;
    // 이미 방문했다면 false
    if (visited[row][col])
        return false;

    return true;
}

void dfs(int row, int col) {
    
    // 스택 쌍 초기화, 시작 셀을 스텍에 넣는다.
    stack<pair<int, int>> st;
    st.push({row, col});
    
    while (!st.empty()) {
        // 상위 pair를 pop한다.
        pair<int, int> curr = st.top();
        st.pop();
        int row = curr.first;
        int col = curr.second;
        
        // 현재 pop된 것을 valid 한지 안한지 확인한다.
        if(!isValid(row, col))
            continue;

        if((computers[row][col] == 1 ? false : true))
            continue;
        
        visited[row][col] = true;
        visited[col][row] = true;

        
        // 인접한 vertex를 모두 push한다.
        for (int i=0; i < 4; i++){
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];
            st.push({adjx, adjy});
        }
    }
    
    
    
}

int solution(int n, vector<vector<int>> computers) {
    answer = 0;
    ::computers = computers;
    COL = n; ROW = n;
    
    // N개의 component들에 대하여, 각각 dfs를 실행한다.
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++){
            if (visited[i][j])
            {
                cout << "already visited" << i << endl;
                continue;
            }
        
            if (computers[i][j] == 1)
            {
                cout << i << ", " << j << endl;
                dfs(i, j);
                answer++;
            }
        }
        cout << "------" << endl;
    }
    cout << answer << endl;
    return answer;
}


int main (void) {
    vector<vector<int>> computers {
        {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}
    };

    solution(3, computers);
}