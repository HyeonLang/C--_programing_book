#include <iostream>

using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	if (size == 0) return NULL;
	int* concatArr = new int[size];
	for (int i = 0; i < size/2; i++) {
		concatArr[i] = s1[i];
	}
	for (int j = 0; j < size/2; j++) {
		concatArr[j + size/2] = s2[j];
	}
	return concatArr;
}


int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* removeArr = new int[size/2];
	for (int i = 0; i < sizeof(s1); i++) {
		int k = 0;
		for (int j = 0; j < sizeof(s2); j++) {
			if (s1[i] == s2[j]) break;
			k = j;
		}
		if (k == sizeof(s2) - 1) {
			removeArr[retSize] = s1[i]; 
			retSize++;
		}
	}
	if (retSize == 0) return NULL;
	return removeArr;
}

int main() {
	ArrayUtility2 arr;
	int x[5];
	int y[5];
	int size = (sizeof(x) + sizeof(y)) / sizeof(int);
	int retSize = 0;
	cout << "정수 5개 입력, 배열 x에 삽입: ";
	cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
	cout << endl;

	cout << "정수 5개 입력, 배열 y에 삽입: ";
	cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
	cout << endl;

	int* p;

	p = ArrayUtility2::concat(x, y, size);
	cout << "합친 정수배열 출력" << endl;
	for (int i = 0; i < size; i++)
		cout << p[i] << " ";
	cout << endl;
	p = ArrayUtility2::remove(x, y, size, retSize);
	cout << "배열 x에서 배열 y를 뺀 결과 출력. 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++)
		cout << p[i] << " ";
	cout << endl;

}