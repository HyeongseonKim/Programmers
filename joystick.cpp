#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    char ch[name.size()];
    int count = 0;
    char prev;
    int answer = 0;
    
    strcpy(ch, name.c_str());
    
    for (char c: ch) {
        if (count == 0) { // 첫 글자 'A'
            answer += (int)(min(c - 'A', 'Z' - c + 1));
            count += 1;
            cout << c;
        } else {
            if (prev > c) {
                cout << c << ":";
                cout << (int)(min(c - 'A' + 1, prev - c));
                answer += (int)(min(c - 'A' + 1, prev - c));
            } else if (prev < c) {
                cout << c << "$";
                cout << (int)(min('Z'-c+1, c-prev));
                answer += (int)(min('Z'-c+1, c-prev));
            }
        }
        
        prev = c;
    }
    
    return answer;
}