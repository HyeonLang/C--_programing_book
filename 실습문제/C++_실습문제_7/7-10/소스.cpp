//!, >>, <<, ~ 연산자 함수 작성
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
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
	
	int x[5];
	cout << "5개 정수 입력 >> ";
	for (int i = 0; i < 5; i++) cin >> x[i]; //x[i]에 정수 입력

	for (int i = 0; i < 5; i++) stat << x[i]; //x[i]값을 통계객체에 삽입
	stat << 100 << 200; // 100, 200을 통계 객체에 삽입
	~stat; //통계 데이터 모두 출력

	int avg;
	stat >> avg; // 평균 받기
	cout << "avg = " << avg << endl; // 평균 출력
}