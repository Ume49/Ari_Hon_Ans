// Ants.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>

using namespace std;

// for文を動的に入れ子にするための再帰関数
void For_Tenkai(int for_count, vector<int>& right_or_left) {
    // 脱出条件 脱出前に処理
    if (for_count == 0) {
        // アリの向きが決まったので時間を求める
        
        // 衝突をするたびループ
        while (true) {

        }

        // 
        return;
    }

    for (auto i = 0; i < 2; i++) { // 0->右 1->左 とする
        // 向きを保存 頭から書くのめんどいので逆順に入れる
        right_or_left.at(for_count-1) = i;

        For_Tenkai(for_count - 1,right_or_left);
    }
}

int main()
{
    // 変数
    int L = 10; // 竿の長さ
    int n = 3;  // アリの数
    vector<int> x{ 2, 6, 7 };   // 左端からの距離

    // 移動速度
    const int speed = 1;

    // 2^n通りチェック
    vector<int> right_or_left(n);

    For_Tenkai(n, right_or_left);

    return 0;
}