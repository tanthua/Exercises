#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

namespace hua_9_3{
	void print();
}

int main() {
	hua_9_3::print();
	cout << "Hello Git" << endl;
	return 0;
}

namespace hua_9_3 {
	void print() {
		string test = "Hello World";
		cout << test << endl;
		test.insert(4, 2, '!');
		cout << test << endl;
		test.erase(4, 3);
		cout << test << endl;
	}
}