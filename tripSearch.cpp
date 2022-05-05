#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> visitedTickets; // push_back으로 관리되어야 한다.
vector<int> visitedIndexTickets;  
vector<vector<string>> tickets;
vector<string> answer;
int RootCount = 0;

void print_fnc(vector<string> v_str);
bool alphabetically(string a, string b);

void print_fnc(vector<string> v_str) {
    cout << v_str[0] << ", " << v_str[1] << endl;
}

bool alphabetically(string a, string b) {
    return a<b;
}

vector<vector<string>> adjacents(string airport) {
    // start의 airport가 담긴 vector<string> 을 찾는다.
    // auto pr = for_each(tickets.begin(), tickets.end(), print_fnc);
    vector<vector<string>> adjAirportTickets;
    
    for (int i=0; i<tickets.size(); i++) {
        if (tickets[i][0].compare(airport) == 0)    // airport(출발지점)이 적힌 ticket 모두를 adj라 취급한다.
            adjAirportTickets.push_back(tickets[i]);
    }
    
    sort(adjAirportTickets.begin(), adjAirportTickets.end());
    
    
    return adjAirportTickets;
}

vector<int> adjacentsIndex(string airport) {
    // start의 airport가 담긴 vector<string> 을 찾는다.
    // auto pr = for_each(tickets.begin(), tickets.end(), print_fnc);
    vector<int> adjIndexAirportTickets;
    
    for (int i=0; i<tickets.size(); i++) {
        if (tickets[i][0].compare(airport) == 0)    // airport(출발지점)이 적힌 ticket 모두를 adj라 취급한다.
        {
            adjIndexAirportTickets.push_back(i);
        }
    }
    
    
    return adjIndexAirportTickets;
}

void dfs(string airport, int count) {
    bool isContinue;
    
    // cout << airport << endl;
    vector<vector<string>> adjAirportTickets = adjacents(airport);
    vector<int> adjIndexAirportTickets = adjacentsIndex(airport);

    // sort 기능 추가
    
    
    // airport의 출발지에서 시작하여, 다른 도착지들이 있는 티켓들의 도착지로 dfs search를 실행한다.
    for(int adjIndexAirportTicket: adjIndexAirportTickets ) {
        isContinue = false;
        // cout << adjAirportTicket[0] << ", " << adjAirportTicket[1] << endl;
        
        if (find(visitedIndexTickets.begin(), visitedIndexTickets.end(), adjIndexAirportTicket) != visitedIndexTickets.end())
            continue;
       
        visitedIndexTickets.push_back(adjIndexAirportTicket); // 티켓 사용기록 저장
        
        if (count == tickets.size() && RootCount == 0)
        {
            answer.push_back("ICN");
            for (int visitedIndexTicket : visitedIndexTickets){
                answer.push_back(tickets[visitedIndexTicket][1]);
            }
            RootCount++;
        }
        
        dfs(tickets[adjIndexAirportTicket][1], count + 1);
        visitedIndexTickets.pop_back(); // 티켓 사용기록 저장
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    ::tickets = tickets;
    
    dfs("ICN", 1);
    
    
        
    // visitedTickets의 end 부분만 extract하여 path 생성.  
    
    return answer;
}