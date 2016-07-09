#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

namespace hua_9_6 {
	unsigned int factorial(unsigned int n);
	double C(unsigned int n, unsigned int r);
}



int main() {
	cout << hua_9_6::factorial(9) << endl;
	cout << hua_9_6::C(10, 3) << endl;
	return 0;
}

namespace hua_9_6 {
	unsigned int factorial(unsigned int n) {
		if (n == 0)
			return 1;
		else
			return n * factorial(n - 1);
	}

	double C(unsigned int n, unsigned int r) {
		return (double(factorial(n)) / double(factorial(r) * factorial(n - r)));
	}
}