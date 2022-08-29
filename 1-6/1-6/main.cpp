#include <iostream>
#include <vector>

using namespace std;

int main() {
	// �ϐ�
	int n = 4;	// �_�̖{��
	vector<int> a{4,5,10,20};	// �_�̒���

	int max_length = 0;	// �ő�̎���

	// 3^n�ʂ�`�F�b�N����
	for (auto x = 0; x < n; x++) {
		for (auto y = 0; y < n; y++) {
			// �_�u����
			if (y == x) { continue; }

			for (auto z = 0; z < n; z++) {
				// �_�u����
				if (z == x) { continue; }
				if (z == y) { continue; }
				
				// �I�񂾎O�{�ŎO�p�`�����Ȃ��Ȃ�X�L�b�v 2�ӂ𑫂��Ă��c��1�ӂ̕����傫���悤�Ȃ�O�p�`�͐������Ȃ��i���E�l���܂ޏꍇ�͐����ɂȂ�̂ł�����_���j
				if (a.at(x) + a.at(y) <= a.at(z)) { continue; }
				if (a.at(z) + a.at(x) <= a.at(y)) { continue; }
				if (a.at(y) + a.at(z) <= a.at(x)) { continue; }

				// ����̎O�p�`���Ȃ�����
				int current_length = a.at(x) + a.at(y) + a.at(z);

				// ���傫���ꍇ�͍X�V
				if (current_length > max_length) {
					max_length = current_length;
				}
			}
		}
	}

	// ���ʕ\��
	cout << max_length;

	return 0;
}