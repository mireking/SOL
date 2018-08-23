#if 1 
//���̷���
/*
���� ���̷����� �� ���̷����� ��Ʈ��ũ�� ���� ���ĵȴ�. �� ��ǻ�Ͱ� �� ���̷����� �ɸ��� �� ��ǻ�Ϳ� ��Ʈ��ũ �󿡼� ����Ǿ� �ִ� ��� ��ǻ�ʹ� �� ���̷����� �ɸ��� �ȴ�.
���� ��� 7���� ��ǻ�Ͱ� <�׸� 1>�� ���� ��Ʈ��ũ �󿡼� ����Ǿ� �ִٰ� ����.
1�� ��ǻ�Ͱ� �� ���̷����� �ɸ��� �� ���̷����� 2���� 5�� ��ǻ�͸� ���� 3���� 6�� ��ǻ�ͱ��� ���ĵǾ� 2, 3, 5, 6 �� ���� ��ǻ�ʹ� �� ���̷����� �ɸ��� �ȴ�.
������ 4���� 7�� ��ǻ�ʹ� 1�� ��ǻ�Ϳ� ��Ʈ��ũ�󿡼� ����Ǿ� ���� �ʱ� ������ ������ ���� �ʴ´�.
��� �� 1�� ��ǻ�Ͱ� �� ���̷����� �ɷȴ�.��ǻ���� ���� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ������ �־��� ��,
1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ��� ��ǻ���� ���� �־�����.��ǻ���� ���� 100 �����̰� �� ��ǻ�Ϳ��� 1������ ���ʴ�� ��ȣ�� �Ű�����.��° �ٿ��� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ��(100�� ����)�� �־�����.�̾ �� ����ŭ �� �ٿ� �� �־� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ���� ��ȣ ���� �־�����.
���
1�� ��ǻ�Ͱ� �� ���̷����� �ɷ��� �� 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ù° �ٿ� ����Ѵ�.

�Է� ����
7
6
1 2
2 3
1 5
5 2
5 6
4 7


��� ����
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
	//1. ���� ��ġ�� ť�� In	
	in.x = 1;
	//in.y = 1; //������
	//in.v = 0; //������

	q[wr++] = in;	
	visit[1] = 1;

	//2. �湮 ǥ��(��)
	//a[1][1] = 0;	

	while (wr > rd) //ť�� �����Ͱ� ������
	{
		//3. ť���� Out
		out = q[rd++];
		//4. �̵�(�����¿�)
		for (k = 2; k <= Count; k++) {
			
			//����Ǿ� ���� ������ Continue
			if (a[out.x][k] == 0) continue;

			//�̹� �湮������ Continue
			if (visit[k] == 1) continue;
			
			//ni = out.y + di[k];
			//nj = out.x + dj[k];

			//5. ������ ����� Continue(�ݵ�� �ſ� �߿�)
			//if (ni < 1 || ni > Count || nj < 1 || nj > Count) continue;

			//6. ���� �ƴϸ� Continue
			//if (a[ni][nj] == 0) continue;

			//7.�������̸� return 
			//if (ni == Count && nj == Count) return out.v + 1;

			//8. �湮(== ť�� in�Ѵ�)
			in.x = k;
			//in.y = ni;
			//in.v = out.v + 1;
			q[wr++] = in;
			visit[k] = 1;
			cnt++;

			
		}

	}
	//���� ����
	return cnt;
	//return -1;

}

int main(void)

{

	// ���⼭���� �ۼ�
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
//���� ��ȣ ���̱� 
/*
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�,
Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.
������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ���� �� ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

�Է� ����
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000


��� ����
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
	//1. ���� ��ġ�� ť�� In	
	in.x = sj;
	in.y = si;
	in.v = 0;

	q[wr++] = in;
	count++;

	//2. �湮 ǥ��(��)
	a[si][sj] = 0;


	while (wr > rd) //ť�� �����Ͱ� ������
	{
		//3. ť���� Out
		out = q[rd++];		
		//4. �̵�(�����¿�)
		for (k = 0; k < 4; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. ������ ����� Continue(�ݵ�� �ſ� �߿�)
			if (ni < 1 || ni > N || nj < 1 || nj > N) continue;

			//6. ���� �ƴϸ� Continue
			if (a[ni][nj] == 0) continue;

			//7.�������̸� return 
			//if (ni == N && nj == N) return out.v + 1;

			//8. �湮(== ť�� in�Ѵ�)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. �湮 ǥ��
			a[ni][nj] = 0;
			count++;
		}

	}	
	//���� ����
	return count;
	
}

int main(void)

{

	// ���⼭���� �ۼ�
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
//�丶��(��}
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
	//1. ���� ��ġ�� ť�� In
	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			
			if (a[i][j] == 1) {
				in.x = j;
				in.y = i;
				in.v = 0;				

				q[wr++] = in;

				//2. �湮 ǥ��
				//a[i][j] = 1; //���ʿ�
			} 
			
		}
	}		



	while (wr > rd) //ť�� �����Ͱ� ������
	{
		//3. ť���� Out
		out = q[rd++];
		day = out.v;
		//4. �̵�(�����¿�)
		for (k = 0; k < 4; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. ������ ����� Continue(�ݵ�� �ſ� �߿�)
			if (ni < 1 || ni > Y || nj < 1 || nj > X) continue;

			//6. ���̸� Continue
			if (a[ni][nj] != 0) continue;			

			//7.�������̸� return 
			//if (ni == Y && nj == X) return out.v + 1;

			//8. �湮(== ť�� in�Ѵ�)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. �湮 ǥ��
			a[ni][nj] = 1;
		}

	}
	//������ �丶�並 �˻�

	//�丶���� ��� �;������� 0, ��ΰ� ���� ���ϴ� ��Ȳ�̸� -1	

	// (1) ������ �丶�䰡 1���� ������ -1 ����
	for (i = 1; i <= Y; i++) {
		for (j = 1; j <= X; j++) {
			if (a[i][j] == 0) {
				return -1;
			}			
		}
	}
	
	// (2) ������ �丶�䰡 ������ ���� ����
	return day;
}

int main(void)

{

	// ���⼭���� �ۼ�
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
//���
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

	//1. ���� ��ġ�� ť�� In
	in.x = sx;
	in.y = sy;
	in.v = 0;

	q[wr++] = in;

	//2. �湮 ǥ��
	a[sy][sx] = 1;

	while (wr > rd) //ť�� �����Ͱ� ������
	{
		//3. ť���� Out
		out = q[rd++];

		//4. �̵�(�����¿�)
		for (k = 0; k < 8; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. ������ ����� Continue(�ݵ�� �ſ� �߿�)
			if (ni < 1 || ni > Y || nj < 1 || nj > X) continue;

			//6. ���̸� Continue
			if (a[ni][nj] == 1) continue;

			//7.�������̸� return 
			if (ni == ey && nj == ex) return out.v + 1;

			//8. �湮(== ť�� in�Ѵ�)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. �湮 ǥ��
			a[ni][nj] = 1;
		}

	}

	//���⿡ ���� �Ұ���

	return 0;
}

int main(void)

{

	// ���⼭���� �ۼ�
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
//�̷� Ż�� �κ�
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
//��,��,��,��
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int bfs(void)
{
	struct myQ in, out;
	int k, ni, nj;
	            
	//1. ���� ��ġ�� ť�� In
	in.x = sx;
	in.y = sy;
	in.v = 0;

	q[wr++] = in;

	//2. �湮 ǥ��
	a[sy][sx] = 1;

	while (wr > rd) //ť�� �����Ͱ� ������
	{
		//3. ť���� Out
		out = q[rd++];

		//4. �̵�(�����¿�)
		for (k = 0; k < 4; k++) {
			ni = out.y + di[k];
			nj = out.x + dj[k];

			//5. ������ ����� Continue(�ݵ�� �ſ� �߿�)
			if (ni < 1 || ni > Y || nj < 1 || nj > X) continue;

			//6. ���̸� Continue
			if (a[ni][nj] == 1) continue;

			//7.�������̸� return 
			if (ni == ey && nj == ex) return out.v + 1;

			//8. �湮(== ť�� in�Ѵ�)
			in.x = nj;
			in.y = ni;
			in.v = out.v + 1;
			q[wr++] = in;

			//9. �湮 ǥ��
			a[ni][nj] = 1;
		}

	}

	//���⿡ ���� �Ұ���

	return 0;
}

int main(void)

{

	// ���⼭���� �ۼ�
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

//������ ����̸� ��ü, 0�̳� �����̸� �ƹ��� ����
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
		//���⼭���� �ۼ�
		cin >> a[tcase];
	}

	qsort(a, TC, sizeof(a[0]), mysort);

	for (tcase = 0; tcase < TC; tcase++) {
		//���⼭���� �ۼ�
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

//������ ��ǥ X-1, Y-1�� �������� ���� ���� �ݺ�
while (!x.empty() && (x.front() != X - 1 || y.front() != Y - 1)) {
//���� �湮�ϴ� ��带 0���� �Ͽ� �ٽ� �湮���� �ʵ��� �Ѵ�.
a[y.front()][x.front()] = 0;

//�����¿� ������� ���� �ִ� ��ǥ ����
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

//ť���� ���� ����� ��ǥ ����
x.pop_front();
y.pop_front();
l.pop_front();
}


//ť�� ���� ���� �ִ� ���
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