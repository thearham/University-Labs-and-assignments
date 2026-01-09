#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int size;
public:
	Array() {
		size = 0;
		arr = new int[0];
	}

	void resize() {
		int newSize = size + 1;
		int* newArray = new int[newSize];


	}

	void add_to_head() {

	}

};

int main() {
	Array arr;


	return 0;
}