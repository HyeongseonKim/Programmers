# 여행 경로

## 문제 설명
주어진 항공권을 모두 이용, 여행 경로 제작. 항상 ICN에서 출발

항공권 정보 담긴 2차원 배열 tickets가 매개변수, 방문하는 공항 경로 배열에 담아 return 하는 solution 함수 작성

## Contraint
* 모든 공항은 알파벳 대문자 3글자 => compare를 써서 비교가 바로 가능해짐.
* 3 <= 공항 수 <= 10,000 => vertx의 최소 최대 개수
* tickets의 각 행 [a,b]는 a 공항에서 b 공항으로 가는 항공권 => 방향이 있는 그래프
* 주어진 항공권은 모두 사용해야 함. => 방향성이 있는데, 그러면 visited된 곳이여도 또 갈 수도 있다는 뜻이 된다.
* 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return
* 모든 도시를 방문할 수 없는 경우는 주어지지 않는다. => 모든 vertex는 visited 내로 들어와야 한다.

## Solution
adjacent를 나누는 기준이 해당 vertex에 인접한 리스트들을 가져오는 거였다. 
여기서는 해당 티켓의 start 부분을 search하여 vertex에 인접한 edge 쌍을 파악한다.

또한 adjacent를 찾았다 하더라도, visited ticket인지를 파악한 다음 dfs를 실행하면 된다.

지금 보면, edge 들의 정보만을 가지고 vertex를 유추해야 되는 상황들에 놓여있다.
물론 시작은 ICN으로 정의하고 있어 시작 vertex가 ICN인 것을 '추정'할 수 있는 상황이다.




### dfs sudo code
''' C++
void search(Node root) {
    if (root == null) return;
    // 1. root 노드 방문
    visit(root);
    root.visited = true; // 1-1 방문한 노드를 표시
    // 2. root 노드와 인접한 정점을 모두 방문
    for each (Node n in root.adjacent) {
        if (n.visited == false) { // 4. 방문하지 않은 정점을 찾는다.
            search(n); // 3. root 노드와 인접한 정점, 정점을 시작 정점으로 하여 DFS 시작
        }
    }
}

'''


