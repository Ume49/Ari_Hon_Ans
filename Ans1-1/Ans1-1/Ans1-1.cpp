#include <iostream>
#include <vector>

using namespace std;

int main(){
	// 変数
	int n = 3;	// n枚の紙
	int m = 10;	// 合計m
	vector<int> cards {1,3,5};	// 紙に書かれてる数字
	
	// 試行回数
	const int try_num = 4;

	// 結果
	bool result = false;	// true -> Yes false -> No

	// n^4通りチェック
	for (auto a = 0; a < n; a++) {
		for (auto b = 0; b < n; b++) {
			for (auto c = 0; c < n; c++) {
				for (auto d = 0; d < n; d++) {
					// 今回の和
					int r = cards.at(a) + cards.at(b) + cards.at(c) + cards.at(d);

					// 紙選びきったのでmと一致するか判定
					if (r == m) {
						result = true;
					}

					//cout << "Debug: " << a << b << c << d << ", " << r << endl;
				}
			}
		}
	}

	// 結果を表示する
	if (result) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}
