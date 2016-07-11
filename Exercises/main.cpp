#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

namespace hua_9_9 {
	static unsigned int n_reverse = 1;

	void print_asterisk(unsigned int n);
	void print_blank(unsigned int n);
	void main(unsigned int n);
}



int main() {
	hua_9_9::main(2);
	return 0;
}

namespace hua_9_9 {
	void print_asterisk(unsigned int n) {
		for (unsigned int i = 0; i < n; ++i) {
			if (i < n / 2) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	void print_blank(unsigned int n) {
		for (unsigned int i = 0; i < n; ++i) {
			if (i < n / 2)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}

	void main(unsigned int n) {
		if (n >= 1) {
			n_reverse = n_reverse * 2;
			print_asterisk(n_reverse);
			main(n / 2);
			print_blank(n_reverse);
			n_reverse = n_reverse / 2;
		}
	}
}