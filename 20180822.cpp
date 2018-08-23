#if 1 
//바이러스
/*
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자.
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다.
하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.
어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다.컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때,
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에는 컴퓨터의 수가 주어진다.컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번부터 차례대로 번호가 매겨진다.둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수(100개 이하)가 주어진다.이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

입력 예시
7
6
1 2
2 3
1 5
5 2
5 6
4 7


출력 예시
4
*/

#pragma warning (disable : 4996)

#include <stdio.h>

struct myQ {
	int x;//, y, v;
};


struct myQ q[100 + 10];

int rd, wr;
int Count, Pair, t1, t2;

int a[100 + 10][100 + 10];
int sol, visit[100 + 10];

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int bfs()
{
	struct myQ in, out;
	int k, cnt = 0;//ni, nj;
	//1. 시작 위치를 큐에 In	
	in.x = 1;
	//in.y = 1; //사용안함
	//in.v = 0; //사용안함

	q[wr++] = in;	
	visit[1] = 1;

	//2. 방문 표시(꼭)
	//a[1][1] = 0;	

	while (wr > rd) //큐에 데이터가 있으면
	{
		//3. 큐에서 Out
		out = q[rd++];
		//4. 이동(상하좌우)
		for (k = 2; k <= Count; k++) {
			
			//연결되어 있지 않으면 Continue
			if (a[out.x][k] == 0) continue;

			//이미 방문했으면 Continue
			if (visit[k] == 1) continue;
			
			//ni = out.y + di[k];
			//nj = out.x + dj[k];

			//5. 범위를 벗어나면 Continue(반드시 매우 중요)
			//if (ni < 1 || ni > Count || nj < 1 || nj > Count) continue;

			//6. 길이 아니면 Continue
			//if (a[ni][nj] == 0) continue;

			//7.목적지이면 return 
			//if (ni == Count && nj == Count) return out.v + 1;

			//8. 방문(== 큐에 in한다)
			in.x = k;
			//in.y = ni;
			//in.v = out.v + 1;
			q[wr++] = in;
			visit[k] = 1;
			cnt++;

			
		}

	}
	//답을 리턴
	return cnt;
	//return -1;

}

int main(void)

{

	// 여기서부터 작성
	int i;
	scanf("%d", &Count);
	scanf("%d", &Pair);


	for (i = 1; i <= Pair; i++) {		
		scanf("%d %d", &t1, &t2);		
		a[t1][t2] = 1;
		a[t2][t1] = 1;
	}

	sol = bfs();	
	
	printf("%d\n", sol);

	return 0;
}

#endif

#if 0 
//단지 번호 붙이기 
/*
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우,
혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지 내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

입력 예시
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000


출력 예시
3
7
8
9
*/
#pragma warning (disable : 4996)

#include <stdio.h>

struct myQ {
	int x, y, v;
};


struct myQ q[25 * 25 + 10];

int rd, wr;
int N;

int a[25 + 10][25 + 10];
int sol[25 * 25 + 10];

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int bfs(int si, int sj)
{
	struct myQ in, out;
	int k, ni, nj, count = 0;	
	//1. 시작 위치를 큐에 In	
	in.x = sj;
	in.y = si;
	in.v = 0;

	q[wr++] = in;
	count++;

	//2. 방문 표시(꼭)
	a[si][sj] = 0;


	while (wr > rd) //큐에 데이터가 있으면
	{
		//3. 큐에서 Out
		out = q[rd++];		
		//4. 이동(상하좌우)
		for (k = 0; k < 4; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. 범위를 벗어나면 Continue(반드시 매우 중요)
			if (ni < 1 || ni > N || nj < 1 || nj > N) continue;

			//6. 길이 아니면 Continue
			if (a[ni][nj] == 0) continue;

			//7.목적지이면 return 
			//if (ni == N && nj == N) return out.v + 1;

			//8. 방문(== 큐에 in한다)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. 방문 표시
			a[ni][nj] = 0;
			count++;
		}

	}	
	//답을 리턴
	return count;
	
}

int main(void)

{

	// 여기서부터 작성
	int i, j;
	scanf("%d", &N);


	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	int cnt = 0;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if(a[i][j] == 1)
				sol[cnt++] = bfs(i, j);
		}
	}	
	
	for (i = 0; i < cnt-1; i++) {
		for (j = i+1; j < cnt; j++) {
			if (sol[i] > sol[j]) {
				int temp = sol[i];
				sol[i] = sol[j];
				sol[j] = temp;
			}
				
		}
	}

	printf("%d\n", cnt);
	for (int result = 0; result < cnt; result++)
	{
		printf("%d\n", sol[result]);
	}


	return 0;

}

#endif


#if 0 
//토마토(고}
#pragma warning (disable : 4996)

#include <stdio.h>

struct myQ {
	int x, y, v;
};


struct myQ q[1000 * 1000 + 10];

int rd, wr;
int X, Y;
//int sx, sy, ex, ey;
int a[1000 + 10][1000 + 10];
int sol, day;
//
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1};

int bfs(void)
{
	struct myQ in, out;
	int k, ni, nj;
	int i, j;
	//1. 시작 위치를 큐에 In
	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			
			if (a[i][j] == 1) {
				in.x = j;
				in.y = i;
				in.v = 0;				

				q[wr++] = in;

				//2. 방문 표시
				//a[i][j] = 1; //불필요
			} 
			
		}
	}		



	while (wr > rd) //큐에 데이터가 있으면
	{
		//3. 큐에서 Out
		out = q[rd++];
		day = out.v;
		//4. 이동(상하좌우)
		for (k = 0; k < 4; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. 범위를 벗어나면 Continue(반드시 매우 중요)
			if (ni < 1 || ni > Y || nj < 1 || nj > X) continue;

			//6. 벽이면 Continue
			if (a[ni][nj] != 0) continue;			

			//7.목적지이면 return 
			//if (ni == Y && nj == X) return out.v + 1;

			//8. 방문(== 큐에 in한다)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. 방문 표시
			a[ni][nj] = 1;
		}

	}
	//안익은 토마토를 검색

	//토마도가 모두 익어있으면 0, 모두가 익지 못하는 상황이면 -1	

	// (1) 안익은 토마토가 1개라도 있으면 -1 리턴
	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			if (a[i][j] == 0) {
				return -1;
			}			
		}
	}
	
	// (2) 안익은 토마토가 없으면 답을 리턴
	return day;
}

int main(void)

{

	// 여기서부터 작성
	int i, j;
	scanf("%d %d", &X, &Y);


	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	sol = bfs();

	printf("%d", sol);


	return 0;

}

#endif

#if 0
//장기
#pragma warning (disable : 4996)

#include <stdio.h>

struct myQ {
	int x, y, v;
};


struct myQ q[100 * 100 + 10];

int rd, wr;
int X, Y;
int sx, sy, ex, ey;
int a[100 + 10][100 + 10];
int sol;
//
int di[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dj[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int bfs(void)
{
	struct myQ in, out;
	int k, ni, nj;

	//1. 시작 위치를 큐에 In
	in.x = sx;
	in.y = sy;
	in.v = 0;

	q[wr++] = in;

	//2. 방문 표시
	a[sy][sx] = 1;

	while (wr > rd) //큐에 데이터가 있으면
	{
		//3. 큐에서 Out
		out = q[rd++];

		//4. 이동(상하좌우)
		for (k = 0; k < 8; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. 범위를 벗어나면 Continue(반드시 매우 중요)
			if (ni < 1 || ni > Y || nj < 1 || nj > X) continue;

			//6. 벽이면 Continue
			if (a[ni][nj] == 1) continue;

			//7.목적지이면 return 
			if (ni == ey && nj == ex) return out.v + 1;

			//8. 방문(== 큐에 in한다)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. 방문 표시
			a[ni][nj] = 1;
		}

	}

	//여기에 진입 불가능

	return 0;
}

int main(void)

{

	// 여기서부터 작성
	int i, j;
	scanf("%d %d", &X, &Y);

	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);


	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			//scanf("%1d", &a[i][j]);
			a[i][j] = 0;
		}
	}

	sol = bfs();

	printf("%d", sol);


	return 0;

}

#endif

#if 0
//미로 탈출 로봇
#pragma warning (disable : 4996)

#include <stdio.h>

struct myQ{
	int x, y, v;
};


struct myQ q[100 *100+10];

int rd, wr;
int X, Y;
int sx, sy, ex, ey;
int a[100+10][100+10]; 
int sol;
//상,하,좌,우
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int bfs(void)
{
	struct myQ in, out;
	int k, ni, nj;
	            
	//1. 시작 위치를 큐에 In
	in.x = sx;
	in.y = sy;
	in.v = 0;

	q[wr++] = in;

	//2. 방문 표시
	a[sy][sx] = 1;

	while (wr > rd) //큐에 데이터가 있으면
	{
		//3. 큐에서 Out
		out = q[rd++];

		//4. 이동(상하좌우)
		for (k = 0; k < 4; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. 범위를 벗어나면 Continue(반드시 매우 중요)
			if (ni < 1 || ni > Y || nj < 1 || nj > X) continue;

			//6. 벽이면 Continue
			if (a[ni][nj] == 1) continue;

			//7.목적지이면 return 
			if (ni == ey && nj == ex) return out.v + 1;

			//8. 방문(== 큐에 in한다)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. 방문 표시
			a[ni][nj] = 1;
		}

	}

	//여기에 진입 불가능

	return 0;
}

int main(void)

{

	// 여기서부터 작성
	int i, j;
	scanf("%d %d", &X, &Y);
	
	scanf("%d %d %d %d", &sx, &sy, &ex,& ey);

	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	sol = bfs();

	printf("%d", sol);
	

	return 0;

}

#endif




















































































/*
#include <iostream>
#include <deque>

using namespace std;

int a[5000 + 10];

//리턴이 양수이면 교체, 0이나 음수이면 아무일 없음
int mysort(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main(void)
{
	int TC, tcase;
	cin >> TC;
	for (tcase = 0; tcase < TC; tcase++) {
		//여기서부터 작성
		cin >> a[tcase];
	}

	qsort(a, TC, sizeof(a[0]), mysort);

	for (tcase = 0; tcase < TC; tcase++) {
		//여기서부터 작성
		cout << a[tcase] << ' ';
	}

	return 0;
}
*/
/*

int a[100+10][100+10];
int X, Y, sol;
int sx, sy, ex, ey;

void BFS()
{
deque<int> x, y, l;
y.push_back(sx);
x.push_back(sy);
l.push_back(1);

//마지막 좌표 X-1, Y-1에 도달하지 않은 동안 반복
while (!x.empty() && (x.front() != X - 1 || y.front() != Y - 1)) {
//현재 방문하는 노드를 0으로 하여 다시 방문하지 않도록 한다.
a[y.front()][x.front()] = 0;

//상하좌우 사방으로 갈수 있는 좌표 삽입
if (y.front() > 0 && a[y.front() - 1][x.front()] == 1)
{
x.push_back(x.front());
y.push_back(y.front() - 1);
l.push_back(l.front() + 1);
}

if (y.front() < Y - 1 && a[y.front() + 1][x.front()] == 1)
{
x.push_back(x.front());
y.push_back(y.front() + 1);
l.push_back(l.front() + 1);
}

if (x.front() > 0 && a[y.front()][x.front() - 1] == 1)
{
x.push_back(x.front() - 1);
y.push_back(y.front());
l.push_back(l.front() + 1);
}

if (x.front() < X - 1 && a[y.front()][x.front() + 1] == 1)
{
x.push_back(x.front() + 1);
y.push_back(y.front());
l.push_back(l.front() + 1);
}

//큐에서 현재 사용한 좌표 제거
x.pop_front();
y.pop_front();
l.pop_front();
}


//큐에 아직 남아 있는 경우
if (!x.empty()) sol = l.front();

};


int main()
{
cin >> X >> Y;
cin >> sx >> sy >> ex >> ey;


int x, y;

for (y = 0; y < Y; y++) {
for (x = 0; x < X; x++) {
cin >> a[y][x];
}
}

BFS();

cout << sol << endl;

return 0;
}

*/