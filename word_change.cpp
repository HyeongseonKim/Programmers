#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> words;
vector<int> visited;
vector<int> st;
int least_count;
string beg;
string tar;

vector<int> adjacents(int vertex, string word) {
    int check_sum = 0;
    vector<char> b(word.begin(), word.end());
    vector<int> adjArr;
    
    for (int i=0; i < words.size(); i++) {
        check_sum = 0;
        // word와 w가, component간에 하나만 차이가 있어야 한다.
        // string을 쪼개서, character들로 표현됬을 때, -로 감하여 총합이 절댓값 1이되면 통과
        vector<char> w(words[i].begin(), words[i].end());
        
        //cout << words[i] << endl;
        
        for (int j=0; j<w.size();j++)
        {
            check_sum += (abs(w[j] - b[j]) == 0 ? 0 : 1);
            //cout << check_sum << endl;
        }
        
        
        if (check_sum == 1)
        {
            //cout << "added: " << i << endl;
            adjArr.push_back(i);
        }
    }
    
    
    return adjArr;
}

void dfs(int vertex, string word, int count) {
    // stack 쌍 초기화, 시작 셀을 스텍에 넣는다.
    st.push_back(vertex);
    vector<int> neighbors = adjacents(vertex, word);
    
    
    if (tar.compare(word) == 0)
        if (least_count >= count){
            cout << count << endl;
            least_count = count;
        }
            
    
    // 인접한 vertex를 탐색한다.
    for (int neighbor: neighbors)
        if (find(st.begin(), st.end(), neighbor) == st.end()){
            dfs(neighbor, words[neighbor], count+1);
        }
}

int solution(string begin, string target, vector<string> words) {
    int count = 0;
    least_count = 2147483647;
    ::words = words;
    ::beg = begin;
    ::tar = target;
    
    // words 내에, target이 없으면 return 0
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    // begin 또한 graph의 요소로 편입시켜 준다.
    ::words.insert(::words.begin(), begin);
    
    // begin을 root로 하여 dfs search를 실행시킨다.
    dfs(0, begin, 0);   
    
    
    return least_count;
}