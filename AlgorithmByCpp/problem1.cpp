#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main_fake1() {
	int n;
	string str;
	while (cin >> n) {
		cin >> str;
		if (str.find("0") == string::npos || str.find("2") == string::npos) {
			cout << 0 << endl;
			continue;
		}
		vector<bool> used(n, false);
		vector<bool> found(n, false);
		for (int i=0; i<n; i++){
			if (str[i] == '2' and !used[i]) {
				for (int j = i + 1; j < n; j++) {
					if (str[j] == '0' and !used[j]) {
						for (int k = j + 1; k < n; k++) {
							if (str[k] == '2' and !used[k]) {
								for (int m = k + 1; m < n; m++) {
									if (str[m] == '0' and !used[m]) {
										cout << i << j << k << m << endl;
										found[i] = true;
										used[i] = true;
										used[j] = true;
										used[k] = true;
										used[m] = true;
										goto Flag;
									}
								}
							}
						}
					}
				}
			}
		Flag:
			continue;
		}
		int result = 0;
		for (int i = 0; i < n; i++) {
			if (found[i]) {
				result ++;
			}
		}
		cout << result << endl;
	}
	return 0;
}