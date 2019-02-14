#include "pch.h"

using namespace std;

int pos;
vector<int> pre, in, post;

void Reconst (int left, int right) {
	if (left >= right) {
		return;
	}

	int root = pre[pos++];
	int m = distance(in.begin(), find(in.begin(), in.end(), root));

	Reconst(left, m);
	Reconst(m + 1, right);

	post.push_back(root);
}

void Solve (int n) {
	pos = 0;
	Reconst(0, pre.size());

	for (int i = 0; i < n; i++) {
		if(i) cout << " ";
		cout << post[i];
	}

	cout << endl;
}



void ReconstTree () {
	int n, k;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		pre.push_back(k);
	}

	for (int i = 0; i < n; i++) {
		cin >> k;
		in.push_back(k);
	}

	Solve(n);

	return;
}