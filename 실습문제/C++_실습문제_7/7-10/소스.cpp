//!, >>, <<, ~ ������ �Լ� �ۼ�
#include <iostream>

using namespace std;

class Statistics {
	int* arr;
	int size;
public:
	Statistics() {
		this->size = 0;
		this->arr = new int[this->size];
	}

	bool operator!();
	void operator>>(int& avg);
	Statistics& operator<<(int num);
	void operator~();
};

bool Statistics::operator!() {
	if (this == 0)
		return false;
	return true;
}

void Statistics::operator>>(int& avg) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum = sum + this->arr[i];
	avg = sum / size;
}
Statistics& Statistics::operator<<(int num) {
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = this->arr[i];
	}
	newArr[size] = num;
	size++;
	delete[] this->arr;
	this->arr = new int[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = newArr[i];
	}
	delete[] newArr;
	return *this;
}

void Statistics::operator~() {
	for (int i = 0; i < size; i++)
		cout << this->arr[i] << " ";
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;
	
	int x[5];
	cout << "5�� ���� �Է� >> ";
	for (int i = 0; i < 5; i++) cin >> x[i]; //x[i]�� ���� �Է�

	for (int i = 0; i < 5; i++) stat << x[i]; //x[i]���� ��谴ü�� ����
	stat << 100 << 200; // 100, 200�� ��� ��ü�� ����
	~stat; //��� ������ ��� ���

	int avg;
	stat >> avg; // ��� �ޱ�
	cout << "avg = " << avg << endl; // ��� ���
}