#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

namespace hua_9_4 {
	static size_t COUNT = 0;
	void program(size_t user_input, string box);
}



int main() {
	size_t input;
	cout << "How many unnumbered boxes can you see?" << endl;
	cin >> input;
	hua_9_4::program(input, "");
	cout << hua_9_4::COUNT << endl;
	return 0;
}

namespace hua_9_4 {
	void program(size_t user_input, string box) {
		COUNT += user_input;
		if (user_input > 0) {
			//
			for (size_t i = 1; i <= user_input; ++i) {
				string tempBox = box;
				tempBox += char('0' + i);
				tempBox += '.';
				size_t input;
				cout << "How many unnumbered boxes can you see in box number " << tempBox << " ?" << endl;
				cin >> input;
				program(input, tempBox);
			}
		}
		else {
			cout << box << endl;
		}
	}
}