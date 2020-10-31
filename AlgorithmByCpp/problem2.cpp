#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct
{
	int left;
	int top;
	int right;
	int bottom;
} Rect;

int isRectOverlap(const Rect& r1, const Rect& r2)
{
	// Overlap
	if ((r1.right <= r2.right) && (r1.bottom <= r2.bottom) && (r1.left >= r2.left) && (r1.top >= r2.top) || 
		(r2.right <= r1.right) && (r2.bottom <= r1.bottom) && (r2.left >= r1.left) && (r2.top >= r1.top)
		) {
		return 0;
	}
	// Inter
	if (!(((r1.right < r2.left) && (r1.bottom > r2.top)) || (r1.right < r2.left) && (r1.top < r2.bottom)) || 
		((r2.right < r1.left) && (r2.bottom > r1.top)) || ((r2.right < r1.left) && (r2.top > r1.bottom))
		) {
		return 1;
	}
	// No
	return 0;
}

int main_fake2() {
	int n, m, temp;
	unordered_set<int> A;
	unordered_map<int, Rect> B;
	while (cin >> n >> m) {
		A.clear();
		B.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> temp;
				A.insert(temp);
				if (B.find(temp) == B.end()) {
					Rect rect;
					rect.bottom = i;
					rect.top = i; 
					rect.left = j;
					rect.right = j;
					B.insert(make_pair(temp, rect));
				}
				else {
					Rect rect = B.find(temp)->second;
					rect.bottom = max(rect.bottom, i);
					rect.top = min(rect.top, i);
					rect.right = max(rect.right, j);
					rect.left = min(rect.left, j);
					B.erase(temp); 
					B.insert(make_pair(temp, rect));
				}

			}
		}


		int all_result = 0;
		for (unordered_set<int>::iterator it = A.begin(); it != A.end(); it++) {
			int result = 0;
			for (unordered_set<int>::iterator it2 = A.begin(); it2 != A.end(); it2++) {
				if (*it == *it2) {
					continue;
				}
				int fxy = isRectOverlap(B.find(*it)->second, B.find(*it2)->second);
				result += fxy * (*it2);
			}
			all_result += (*it ^ result);
		}
		cout << all_result << endl;
	}
	return 0;
}