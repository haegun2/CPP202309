#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL)); //���� �Լ� ���� ����

	int answer = rand() % 100; //����
	int tries = 0; // �õ� Ƚ�� �����ϴ� ����

	int usertry = 0; //����� �Է°� ����


	while (usertry != answer) { //���� �ƴҶ����� ��� ����
		cout << "������ �����Ͽ� ���ʽÿ�:" << endl;
		cin >> usertry;
		tries++; //�� ȸ������ �õ�Ƚ�� �ö�

		if (usertry > answer)//������ ���
			cout << "������ ������ �����ϴ�." << endl;
		if (usertry < answer)//������ ���
			cout << "������ ������ �����ϴ�." << endl;
	
	}//���̸� Ż��
	cout << "�����մϴ�. �õ�Ƚ��=" << tries << endl;
	return 0;
}