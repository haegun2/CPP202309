#include <iostream>
#include <string>
using namespace std;

int main() {

	const int STUDENT = 5;
	const int SUBJECT = 3; //������� �л����� ����� ����
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT] //�л��̸� �迭�� ���� �̸��� ����
		= { "����", "����", "ö��", "�̹�", "����" };
	string subjectNames[SUBJECT] //����� �迭�� ������� ����
		= { "����", "����", "CPP" };

	for (int i = 0; i < STUDENT; i++) { //for���� ���ؼ� �л� ���� ���ʴ�� ����ϸ鼭
		cout << studentNames[i]
			<< "�� ������ �ϳ��� �Է��ϼ���." << endl;
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":"; //����� �ϳ��� ����ϰ� �Է¹޾Ƽ�
			cin >> scores[i][j]; // ���� �迭�� ����
		}
	}

	for (int i = 0; i < STUDENT; i++) { //�л����� ������� ���
		cout << studentNames[i] << "�� ��� ������ ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++) {//�л��� ���� j�� �� ���������� ������� �ջ�
			sum += scores[i][j];
		}
		average = sum / SUBJECT;//����� ���� average������ ����
		cout << average << "�Դϴ�" << endl;//��������� ���
	}
	return 0;
}