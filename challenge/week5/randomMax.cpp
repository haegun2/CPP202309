#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10; //��� ����
	int numList[numCell][numCell]; //10x10�� �迭�� ����

	
	for (int i = 0; i < numCell ; i++) { //i�� j���� ���������� ������Ű�� �ش� �迭��
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000;//0~999 ������ ���� ���� ���� ����
			numList[i][j] = elem;
			cout << i << ", " << j << " : " << elem << endl; //�ش� ���� ���ʴ�� ���
		}
	}
	cout << endl;

	int max=0; //�ִ밪 ����
	int maxI=0; //�ִ밪�� i �� ����
	int maxJ=0; // �ִ밪�� j�� ����
	for (int i = 0; i < numCell; i++) { //i�� ������Ŵ
		int j = 0; // j�� ���� ���� �� �ʱ�ȭ
		for (auto var : numList[i]) { // numlist i �߿��� ���� ���������� var�� ��
			if (var > max) { // var ���� max���� ũ��
				max = var; //max���� var�� �ٲ�!!
				maxI = i; //�׸��� �׶��� i,j ���� ����
				maxJ = j;
			}
			j++; //�µ� �ƴϵ� �� ȸ�� ���������� j���� �ϳ��� ����
		}
	}

	cout << "���� ū ����" << max << "�̰�,";
	cout << "i�� j�� ����" << maxI << ", " << maxJ << "�Դϴ�." << endl; //��� �ִ밪�� i,j��
	cout << "�������: " << numList[maxI][maxJ] << endl; //��ǥ�� Ȯ���ϸ鼭 ����

	return 0;
}