#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = -2e5 + 15;
int ar[N], MX, ans, mx[4 * N];
std::vector<int> node[4 * N] ;
void merge_sort(int vertex, int l, int r) {
	if (l == r) {
		mx[vertex] = ar[l];
		node[vertex].push_back(ar[l]);
		return;
	}
	int mid = (l + r) >> 1;
	merge_sort(vertex * 2, l, mid);
	merge_sort(vertex * 2 + 1, mid + 1, r);
	mx[vertex] = max(mx[vertex * 2], mx[vertex * 2 + 1]);
	merge(node[vertex * 2].begin(), node[vertex * 2].end(), node[vertex * 2 + 1].begin(), node[vertex * 2 + 1].end(), back_inserter(node[vertex]));

}
void find_query(int vertex, int left, int right, int l, int r) {
	if (left > r || right < l)return;
	if (left >= l && right <= r) {
		MX = max(MX, mx[vertex]);
		return;
	}
	int mid = (left + right) >> 1;
	find_query(vertex * 2, left, mid, l, r);
	find_query(vertex * 2 + 1, mid + 1, right, l, r);

}
int find_cnt(int vertex, int left, int right, int l, int r) {
	if (left > r || right < l)return 0;
	if (left >= l && right <= r) {
		ans = (upper_bound(node[vertex].begin(), node[vertex].end(), MX) - node[vertex].begin())
		      - (lower_bound(node[vertex].begin(), node[vertex].end(), MX) - node[vertex].begin());
		return ans;
	}
	int mid = (left + right) >> 1;
	int one = find_cnt(vertex * 2, left, mid, l, r);
	int two = find_cnt(vertex * 2 + 1, mid + 1, right, l, r);
	return one + two;
}
int main() {
	int n, test, query;
	scanf("%d", &test);
	for (int cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &query);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ar[i]);
		}
		merge_sort(1, 1, n);
		/*for(int i=0;i<node[2].size();i++){
			cout<<node[2][i]<<" ";
		}*/
		int l, r;
		printf("Case %d:\n", cs);
		for (int i = 1; i <= query; i++) {
			scanf("%d %d", &l, &r);
			MX = M; l += 1, r += 1;
			//cout<<MX<<" ";
			find_query(1, 1, n, l, r);
			printf("%d\n", find_cnt(1, 1, n, l, r));

		}
		for (int i = 0; i <= 4 * N; i++) {
			node[i].clear(), mx[i] = 0;
		}
	}
	return 0;
}