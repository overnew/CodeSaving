class Solution {
public:
	int total_sub_cnt = 0;
	unordered_map<int, vector<int>> links;
	bool visited[30001];

	long long dfs( int curr_node_idx, vector<int>& values, int k) {
		visited[curr_node_idx] = true;

		long long ret = -1;	//부모에게 줄 값
		long long sum = 0;	//subTree의 합

		int vistied_cnt = 0;
		for (int next_node : links[curr_node_idx]) {
			if (visited[next_node])
				continue;

			sum += dfs( next_node, values, k);
			++vistied_cnt;
		}

		sum += values[curr_node_idx];

		if(sum % k == 0) {
			total_sub_cnt++;
			ret = 0;
		}

		if (ret == -1)	//sub tree가 완성되지 않은 경우
			ret = sum;

		return ret;
	}

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

		memset(visited, 0, sizeof(visited));

		int curr_node = 0;
		for (vector<int>& edge: edges) {	//edge 저장
			links[edge[0]].push_back(edge[1]);
			links[edge[1]].push_back(edge[0]);
		}

		dfs(0, values, k);
		return total_sub_cnt;
    }
};
