#include<iostream>
using namespace std;
#include<cstdlib>

class IntArray {
private:
	int* a;
	int len;
public:
	IntArray() {
		a = new int[10];
		len = 0;
	}
	IntArray(int n) {
		a = new int[n];
		len = 0;
	}
	IntArray(IntArray &arr)
	{
		this->a = new int[arr.len];

		for (int i = 0; i < arr.len; i++) {
			this->a[i] = arr.a[i];
			this->len = arr.len;
		}
	}

	//Îö¹¹º¯Êý
	~IntArray() {
		if (a != NULL) {
			delete[] a;
			a = NULL;
		}
	}
	int GetLen();
	int GetE(int index);
	int GetIndex(int E);
	void setE(int E, int index);
	void sort(bool b);
};

int IntArray::GetLen()
{
	return len;
}

int IntArray::GetE(int index) {
	return a[index];
}

int IntArray::GetIndex(int E)
{
	int index = 0;
	while (a[index] != E) {
		index++;
	}
	return index;
}

void IntArray::setE(int E, int index)
{
	a[index] = E;
	len++;
}

void IntArray::sort(bool b)
{
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[j] > a[i]) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int main()
{
	IntArray arr;
	arr.setE(2, 0);
	arr.setE(3, 1);
	arr.setE(7, 2);
	arr.setE(4, 3);
	arr.setE(1, 4);
	for (int i = 0; i < arr.GetLen(); i++) {
		cout << arr.GetE(i) << " ";
	}
	cout << endl;
	//ÅÅÐò
	arr.sort(1);
	for (int i = 0; i < arr.GetLen(); i++) {
		cout << arr.GetE(i) << " ";
	}

	cout <<endl<<"arr2"<< endl;
	IntArray arr2(arr);
	for (int i = 0; i < arr2.GetLen(); i++) {
		cout << arr2.GetE(i) << " ";
	}
	return 0;
}