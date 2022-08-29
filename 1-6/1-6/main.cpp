#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 変数
	int n = 4;	// 棒の本数
	vector<int> a{4,5,10,20};	// 棒の長さ

	int max_length = 0;	// 最大の周長

	// 3^n通りチェックする
	for (auto x = 0; x < n; x++) {
		for (auto y = 0; y < n; y++) {
			// ダブり回避
			if (y == x) { continue; }

			for (auto z = 0; z < n; z++) {
				// ダブり回避
				if (z == x) { continue; }
				if (z == y) { continue; }
				
				// 選んだ三本で三角形が作れないならスキップ 2辺を足しても残り1辺の方が大きいようなら三角形は成立しない（境界値を含む場合は線分になるのでそれもダメ）
				if (a.at(x) + a.at(y) <= a.at(z)) { continue; }
				if (a.at(z) + a.at(x) <= a.at(y)) { continue; }
				if (a.at(y) + a.at(z) <= a.at(x)) { continue; }

				// 今回の三角形がなす周長
				int current_length = a.at(x) + a.at(y) + a.at(z);

				// より大きい場合は更新
				if (current_length > max_length) {
					max_length = current_length;
				}
			}
		}
	}

	// 結果表示
	cout << max_length;

	return 0;
}