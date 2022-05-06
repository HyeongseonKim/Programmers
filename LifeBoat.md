# Life Boat

## 문제 설명
무인도에 갇힌 사람들을 구명보트를 이용해 구출하려고 한다.
구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고 무게 제한도 있다.

예를 들어, 사람들의 몸무게가 [70,50,80,50]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만, 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 한다.

[매개변수]
사람들의 몸무게를 담은 배열: people
구명보트의 무게 제한: limit
모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값: return

## Contraint
* 1 <= length(people) <= 50,000
* 40 <= weight of people <= 240
* 40 <= weight of life boat <= 240
* the weight of lifeboat >= heavist person -> No case for saving no one.

## Example
|people|limit|return|
|------|---|---|
|[70, 50, 80, 50]|100|3|
|[70, 80, 50]|100|3|

## Solution
그리디[탐욕법] 알고리즘
 



