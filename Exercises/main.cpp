#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

namespace hua_9_3{
	void print(string first, string second);
}

int main() {
	hua_9_3::print("CAT", "MAN");
	return 0;
}

namespace hua_9_3 {
	void print(string first, string second) {
		if (first.size() > 0) {
			for (size_t i = 0; i < first.size(); ++i) {
				string tempFirst = first;
				string tempSecond = second;
				tempSecond.insert(0, 1, first.at(i));
				tempFirst.erase(i, 1);
				print(tempFirst, tempSecond);
			}
		}
		else {
			cout << second << endl;
		}
	}
}