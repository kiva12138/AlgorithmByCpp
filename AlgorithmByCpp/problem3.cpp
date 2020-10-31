#include <iostream>
#include <string>
#include <vector>

using namespace std;


int determinant(vector<vector<long> > vec, int n) {
	if (n == 1) return vec[0][0];
	else {
		long sum = 0;
		for (int j = 0; j < n; j++) {
			vector<vector<long> > s;
			for (int r = 1; r < n; r++) {
				vector<long> temp;
				for (int c = 0; c < n; c++) {
					if (c != j) temp.push_back(vec[r][c]);
				}
				s.push_back(temp);
			}
			sum += pow(-1, 0 - j) * vec[0][j] * determinant(s, n - 1);
		}
		return sum;
	}
}

int main_fake3() {
	int n, x;
	long tmp;
	while (cin >> n >> x) {
		vector<long> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a[i] = (tmp);
		}		
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			b[i] = (tmp);
		}
		vector<vector<long>> mat(n);
		for (int i = 0; i < n; i++) {
			mat[i].resize(n);
			for (int j = 0; j < n; j++) {
				if (i == j) {
					mat[i][j] = (x + a[i] * b[j]);
				}
				else {
					mat[i][j] = (a[i] * b[j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << determinant(mat, n) << endl;
	}
	return 0;
}