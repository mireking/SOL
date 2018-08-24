#if 1
/*
중소기업인 K 회사에서 직원들에게 보너스를 지급하려고 한다.
그런데 직원들의 자존심이 강해서 상급자들이 직급이 낮은 사람보다는 한 푼이라도 더 받기를 원한다.
단, 자기랑 직접적 관련이 없는 사람의 보너스 금액에는 관심 없다.
중소기업 특성상 정확한 직급이 존재하지 않고 누가 누구 상급자고 하급자인지만 정해져 있는 상황에서 사장은 골치가 아프다.
예를 들어 아래와 같은 조직인 경우에는 아래와 같다.
편의상 이름은 숫자로 대체한다.
1은 언제나 사장이다.
5명이 있고 보너스 금액은 51, 30, 35, 30, 31 일 경우 1번부터 51, 35, 31, 30, 30으로 배정하면 된다.
중소기업 사장을 도와서 모두가 만족할 수 있는 보너스 금액을 배정하자

입력
첫 줄에 N과 M이 입력된다. N은 직원 수 (3≤N≤10), M은 상하관계의 개수(2≤M≤100) 이다.
다음 줄부터 M줄에 걸쳐 상하관계가 입력된다. 각 줄에는 상급자 하급자 순으로 입력되며 공백으로 구분된다. (상하관계 오류가 발생하는 입력은 없음)
마지막 줄에는 보너스 금액이 N개만큼 공백으로 구분되어 입력된다. 보너스 금액은 1이상 1,000,000 이하 이다.

출력
1번부터 N번까지 순서대로 공백으로 구분하여 보너스 금액을 출력한다. (답이 여러 개일 경우 그 중 한가지만 출력하면 됨)

입력 예시
5 6
1 2
2 3
1 4
2 4
1 5
3 5
51 30 35 30 31


출력 예시
51 35 31 30 30

1. 파라미터
. pos : 보너스 받을 직원번호

2. 리턴 : int
. 0이면 실패, 1이면 성공

3. 종료조건
. pos == N+1 : return 1;

4. 가지치기
. 이미 지급한 보너스이면 
. 상하관계에 따라서 줄수 없으면...for문을 만들고 check함수 만들어야 함


*/
#pragma warning (disable : 4996)
#include <stdio.h>

int N, M;
int B[10 + 10]; //보너스
int a[10 + 10][10 + 10];
int V[10 + 10]; //지급될 보너스
int visit[10 + 10]; //방문한 장소

int check(int pos, int bonus) {
	int i;
	//pos에게 bonus를 줄수 있으면 1, 아니면 0 리턴	
	for (i = 1; i < pos; i++)
	{
		// i는 이미 보너스 지급된 직원의 번호
		//1. pos가 i보다 상급자인 경우 a[pos][i] ==1-> V[i] >= bonus 이면 return 0
		if (a[pos][i] == 1 && V[i] >= bonus) return 0;
		
		
		//2. pos가 i보다 하급자인 경우a[i][pos] ==1 -> V[i] <= bonus 이면 return 0
		if (a[i][pos] ==1 &&  V[i] <= bonus) return 0;
				
	}
	return 1;

}

int DFS(int pos) {
	int i;

	//종료조건
	if (pos == N + 1) return 1;	

	for (i = 1; i <= N; i++) {	
		//i는 보너스 번호
		//가지치기
		if (check(pos, B[i]) == 0) continue;
		if (visit[i] == 1) continue;
		//전역변수 v, visit 설정
		V[pos] = B[i];
		visit[i] = 1;
		if (DFS(pos + 1) == 1) return 1;		
		//전역변수 v, visit 복구
		V[pos] = 0;
		visit[i] = 0;
	}

	return 0;
}

int main(void)
{
	// 여기서부터 작성
	int i, t1, t2;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= M; i++) {
	
		scanf("%d %d", &t1, &t2);
		a[t1][t2] = 1;
	}

	for (i = 1; i <= N; i++) {
		scanf("%d", &B[i]);		
	}

	DFS(1);

	for (i = 1; i <= N; i++) {
		printf("%d ", V[i]);
	}

	return 0;
}

#endif

#if 0
/*
양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 주어진 구슬의 무게를 확인할 수 있는지를 결정하려고 한다.
무게가 각각 1g과 4g인 두 개의 추가 있을 경우, 주어진 구슬과 1g 추 하나를 양팔 저울의 양쪽에 각각 올려놓아 수평을 이루면 구슬의 무게는 1g이다.
또 다른 구슬이 4g인지를 확인하려면 1g 추 대신 4g 추를 올려놓으면 된다.
구슬이 3g인 경우 아래 <그림 1>과 같이 구슬과 추를 올려놓으면 양팔 저울이 수평을 이루게 된다.
따라서 각각 1g과 4g인 추가 하나씩 있을 경우 주어진 구슬이 3g인지도 확인해 볼 수 있다.
<그림 2>와 같은 방법을 사용하면 구슬이 5g인지도 확인할 수 있다. 구슬이 2g이면 주어진 추를 가지고는 확인할 수 없다.
추들의 무게와 확인할 구슬들의 무게가 입력되었을 때, 주어진 추만을 사용하여 구슬의 무게를 확인 할 수 있는지를 결정하는 프로그램을 작성하시오.

입력
첫째 줄에는 추의 개수가 자연수로 주어진다. 추의 개 수는 12 이하이다.
둘째 줄에는 추의 무게들이 자연수로 가벼운 것부터 차례로 주어진다.
같은 무게의 추가 여러 개 있을 수도 있다. 추의 무게는 500g이하이며,
입력되는 무게들 사이에는 빈칸이 하나씩 있다. 세 번째 줄에는 무게를 확인하고자 하는 구슬들의 개수가 주어진다.
확인할 구슬의 개수는 7이하이다. 네 번째 줄에는 확인하고자 하는 구슬들의 무게 Gi( 0 <= Gi <=40000)가 정수로 주어지며,
입력되는 무게들 사이에는 빈 칸이 하나씩 있다.

출력
주어진 각 구슬의 무게에 대하여 확인이 가능하면 Y, 아니면 N을 차례로 출력한다.
한 개의 줄로 이루어지며, 각 구슬에 대한 답 사이에는 빈칸을 하나씩 둔다.

입력 예시
2
1 4
2
3 2


출력 예시
Y N

1. 파라미터
 . pos : 사용할 추의 번호
 . left : 왼쪽 무게
 . right : 오른쪽 무게

2. 리턴 : int
 . 0 : 실패
 . 1 : 성공(찾았음)

3. 종료조건
 . left == right return 1;
 . pos == N+1 return 0;

4. 가지치기 
 . |left - right| > 남은 추의 합
*/
#pragma warning (disable : 4996)

#include <stdio.h>

int N; //추의 개수
int a[12 + 10]; //추의 무게
int r[12 + 10]; //남은추의 무게
int M; //구슬의 개수
int b[7 + 10];//구슬의 무게


int abs(int x) {
	if (x < 0)  return -x;
	return x;
}

int DFS(int pos, int left, int right) {
	//가지치기
	if (abs(left - right) > r[pos]) return 0;

	//종료조건
	if (left == right) return 1;
	if (pos == N + 1) return 0;

	//재귀호출1 : 왼쪽
	if (DFS(pos + 1, left + a[pos], right) == 1) return 1;
	//재귀호출2 : 오른쪽
	if (DFS(pos + 1, left, right + a[pos]) == 1) return 1;
	//재귀호출3 : X
	if (DFS(pos + 1, left, right) == 1) return 1;			
		
		
	return 0;
}

int main(void)
{

	// 여기서부터 작성
	int i;
	scanf("%d", &N); //추의 개수
	for (i = 1; i <= N; i++) {
		scanf("%d ", &a[i]); //추의 무게 입력
	}
	r[N] = a[N];

	for (i = N-1; i >= 1; i--) {
		r[i] = a[i] + r[i + 1];
	}


	scanf("%d", &M); //구슬의 개수
	for (i = 1; i <= M; i++) {
		scanf("%d", &b[i]); //구슬의 무게 입력

		if (DFS(1, b[i], 0) == 1) printf("Y ");
		else printf("N ");
	}

	return 0;
}

#endif

#if 0
/*
기업투자

어떤 투자가가 여러 기업들에게 돈을 투자해서 최대의 이익을 얻고자 한다. 단, 투자는 만원 단위로 할 수 있으며
각 기업은 많이 투자할수록 많은 이익을 투자가에게 돌려준다.
돈을 투자하지 않은 경우는 당연히 얻게 되는 이익도 없다.
예를 들어서, 한 투자가가 4만원을 갖고 두 개의 기업들에
각각 만원 단위로 투자했을 경우 얻을 수 있는 이익은 다음과 같다.
위의 경우 만일, 기업 A에 1만원, 기업 B에 3만원을 투자하는 경우
투자가가 얻는 이익은 14만원(5만원+9만원)이다. 4만원을 투자해서 가장 많은 이익을 얻을 경우
기업 B에만 4만원을 투자하는 경우로서 이때의 이익은 15만원이다.
여기서 투자가는 한 기업에 돈을 나누어 투자할 수는 없다.
투자액이 정해져 있고, 기업의 개수와 각 기업에 투자했을 경우에 얻게 되는 이익이 주어졌을 때
가장 많은 이익을 얻을 수 있는 투자방식과 이때의 이익금을 구하는 프로그램을 작성하라.

입력
첫 줄은 투자 금액과 투자 가능한 기업들의 개수이며, 둘째 줄부터 각 줄은 투자액수 및 각 기업이 투자가에게 주는 이익이다.
단, 총 투자금액은 30만원을 넘지 않으며, 투자 가능한 기업의 개수는 최대 7개이다.

출력
첫 줄에 얻을 수 있는 최대 이익을 출력하고, 둘째 줄에는 각 기업에 투자한 액수를 출력한다.

입력 예시
4 2
1 5 1
2 6 5
3 7 9
4 10 15

출력 예시
15
0 4


1. 파라미터
 . pos : 기업번호
 . r : 투자 가능 금액
 . p : 이익금

2. 리턴 : void(o)...최대값을 구하는거니 다 돌아야 함

3. 종료조건
 . pos == N+1 ----> 이익금중에 최대값을 찾아라...
   1) p를 참조하여 sol을 업데이트
   2) sol 업데이트시 v를 백업
   3) return 

4. 가지치기
 . 투자금이 부족하면...

*/

#pragma warning (disable : 4996)

#include <stdio.h>

int money, prod; //투자금액과 업체
int a[30 + 10][7 + 10];
int sol; //답
int V[7 + 10];
int sol_v[7 + 10];

void DFS(int pos, int r, int p) { // r은 돈, p는 이익금
	int i;

	if (pos == prod + 1 || r == 0) //종료조건, 가지치기 추가
	{
		if (p > sol)
		{
			sol = p;
			for (i = 1; i <= prod; i++) {
				sol_v[i] = V[i];
			}
				
		}
		return;
		
	}

	

	for (i = 0; i <= money; i++) { //가지치기 1
		//재귀 호출 1, i는 투자금

		//가지치기 2
		if (i > r) break;

		V[pos] = i; //전역변수 set
		DFS(pos + 1, r - i, p + a[i][pos]);
		V[pos] = 0; //전역변수 복구
	}
	
	
}



int main(void)
{

	// 여기서부터 작성
	int i, j;
	scanf("%d %d", &money, &prod);

	for (i = 1; i <= money; i++) {
		for (j = 0; j <= prod; j++) {
			scanf("%d", &a[i][j]);		
		}
	}

	DFS(1, money, 0);
	printf("%d\n", sol);
	
	for (i = 1; i <= prod; i++) {
		printf("%d ", sol_v[i]);
	}
	
	return 0;

}


#endif 


