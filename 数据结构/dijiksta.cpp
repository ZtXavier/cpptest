#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int n, m;
int st, ed;

int **G;
int *dis;
bool *vis;
int *path;

struct node {
	int id, data;
};

node make_node(int x, int y) {
	node cc;
	cc.id = x;
	cc.data = y;
	return cc;
}

typedef vector<node>NODE;
NODE *graph;

void initlization() {
    cout << "请输入边的个数和结点个数" << endl;
	scanf("%d %d", &n, &m);

	graph = new NODE[n + 5];
	G = new int*[n + 5];
	dis = new int[n + 5];
	vis = new bool[n + 5];
	path = new int[n + 5];

	for (int i = 1; i <= n; i++) {
		path[i] = i;
		G[i] = new int[n + 5];
		for (int j = 1; j <= n; j++)
			G[i][j] = INF;
		G[i][i] = 0;
	}

	int x, y, z;
	for (int i = 0; i < m; i++) {
        cout << "分别输入两结点和其权值" << endl;
		scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back(make_node(y,z));
		graph[y].push_back(make_node(x,z));
		G[x][y] = G[y][x] = min(z, G[x][y]);
	}

}

void dijkstra(int st) {
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		dis[i] = INF;
		path[i] = (i != st ? -1 : st);
		dis[st]=0;
	}
	int min_dis = INF,x;

	for (int i = 1; i <= n; i++) {
		x=0;
		min_dis = INF;
		for (int j = 1; j <= n; j++) {
			if (dis[j] < min_dis && !vis[j]) {
				min_dis = dis[j];
				x = j;
			}
		vis[x] = 1;
		NODE::iterator it = graph[x].begin();
		for (; it != graph[x].end(); it++) {
			int y = it->id;
			if(!vis[y] && dis[x] + it->data) {
				dis[y] = dis[x] + it->data;
				path[y] = x;
			}
		}
	}
}
}

void print(int st,int ed) 
{
	stack<int> ans;
    ans.push(ed);
	// while (!ans.empty()){
	// 	ans.pop();
	// 	ans.push(ed);
		for (int i = path[ed]; i != st ;i = path[i]) {
			ans.push(i);
		}
	// 	printf("%d",st);
	// }
    printf("%d",st);
	while(!ans.empty()) {
		printf("->%d",ans.top());
		ans.pop();
	}
	printf("\n");
}

int main() {
	initlization();
	cout << "起点和终点" << endl;
	scanf("%d %d",&st,&ed);
	
	dijkstra(st);

	printf("%d\n",dis[ed]); 
	print(st, ed);

	return 0;
}
