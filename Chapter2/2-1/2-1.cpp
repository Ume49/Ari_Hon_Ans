// 2-1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 再帰関数
void Shori(int counta, int n, int k, list<int>& choiced, bool& result) {
	// 脱出条件
	if (counta <= 0) {
		return;
	}

	for (auto i = 0; i < n; i++) {
		// ダブりチェック
		{
			bool check_flag = false;
			for (auto w : choiced) {
				check_flag |= (i == w);
			}
			// 既に選ばれたものと一個でも一致してたらスキップ
			if (check_flag == true) { continue; }
		}

		choiced.push_back(i);

		// 結果チェック
		{
			int sum = 0;
			for (auto w : choiced) { sum += w; }	// 今まで選ばれた数字の合計値を出す

			if (sum == k) {
				result = true;
				// 結果出たら中断していい
				return;
			}
		}

		// 次の値を選ぶ
		Shori(counta, n, k, choiced, result);
	}
}

int main() {
	// 入力
	int n = 4;
	vector<int> a{ 1,2,4,7 };
	int k = 13;

	// 結果
	bool result = false;

	list<int> choiced;	// 既に選ばれた数字 順列用


	// 最大n回ループ
	Shori(n, n, k, choiced, result);
	

	// 結果表示
	cout << (result ? "Yes" : "No");
}