#include<bits/stdc++.h>
using namespace std;

class qPair {

	public:

	int value;
	int rowIdx;
	int colIdx;

	qPair() {

	}
	 
	qPair(int value, int rowIdx, int colIdx) {

		this->value = value;
		this->rowIdx = rowIdx;
		this->colIdx = colIdx;
	}

};

class comp {

	public: 

	bool operator () (const qPair &a, const qPair &b) {
		return (a.value > b.value);
	}
};

vector<int> mergeKSortedList(vector<vector<int>> &arr) {

	vector<int> ans;

	int rowSize = arr.size();

	// min pq

	priority_queue<qPair, vector<qPair>, comp> pq;

	for (int idx=0; idx<rowSize; idx++) {
		pq.push(qPair(arr[idx][0], idx, 0));
	}

	while(!pq.empty()) {

		qPair p = pq.top();
		pq.pop();
		int rIdx = p.rowIdx;
		int val = p.value;
		int col = p.colIdx;

		ans.push_back(val);
		col++;

		if (col< arr[rIdx].size())
		pq.push(qPair(arr[rIdx][col], rIdx, col));
	}

  return ans;
}




int main() {

	int size;

	cin >> size;
	vector<vector<int>> arr;

	for (int idx=0; idx<size; idx++) {

		vector<int> temp;
		int tp;
		cin >> tp;

		for (int idx1=0; idx1<tp; idx1++)
		{
			int inp;
			cin >> inp;

			temp.push_back(inp);
		}
		

		arr.push_back(temp);
	}


    vector<int> ptr = mergeKSortedList(arr);

    for (auto it: ptr) {
      cout << it << " ";
    }
	return 0;

}