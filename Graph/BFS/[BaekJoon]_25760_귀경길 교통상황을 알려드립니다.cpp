#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<memory.h>
using namespace std;

int N;
vector<int> adj[200001];
map<int, int> levelMap;
int levelCarCount[200001];
int deepestLevel = 0;

void bfsLevelSetter(vector<int>& children, int level) {
	vector<int> nextLevels; 

	for (long unsigned int i = 0; i < children.size(); i++)
	{
		int childIdx = children[i];
		if (levelMap.find(childIdx) != levelMap.end())
			continue;

		levelMap[childIdx] = level;
		nextLevels.insert(nextLevels.end(), adj[childIdx].begin(), adj[childIdx].end());
	}

	if (nextLevels.empty()) {
		deepestLevel = level -1;
		return;
	}

	bfsLevelSetter(nextLevels, level + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(levelCarCount, 0, sizeof(levelCarCount));

	cin >> N;

	int first, second;
	for (int i = 0; i < N-1; i++)	//인접 행렬 생성
	{
		cin >> first >> second;
		adj[first].push_back(second);
		adj[second].push_back(first);
	}

	levelMap[1] = 0;	//1번은 root(level 0)
	bfsLevelSetter(adj[1],1);

	int exist;
	for (int i = 1; i <= N; i++) {
		cin >> exist;
		if(exist)
			levelCarCount[levelMap[i]] += 1;
	}

	int answer = 1;
	int frontCarNum = 0;
	for (int lev = deepestLevel; lev >=0; lev--)
	{
		if (levelCarCount[lev] == 0)
			continue;

		frontCarNum += levelCarCount[lev];
		answer = max(lev + frontCarNum, answer);
	}
	
	cout << answer;
	return 0;
}
