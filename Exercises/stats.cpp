#include "stats.h"
#include <cstdlib>
#include <iostream>

namespace hua_2C {
	//CONSTRUCTOR
	statistician::statistician() {
		count = 0;
		total = 0.0;
		tinyest = 0.0;
		largest = 0.0;
	}

	//MODIFICATION MEMBER FUNCTIONS
	void statistician::next(double r) {
		count += 1;
		total += r;
		if (r < tinyest) { tinyest = r; }
		if (r > largest) { largest = r; }
	}

	void statistician::reset() {
		count = 0;
		total = 0.0;
		tinyest = 0.0;
		largest = 0.0;
	}

	//CONSTANT MEMBER FUNCTIONS
	int statistician::length() const {
		return count;
	}

	double statistician::sum() const {
		return total;
	}

	double statistician::mean() const {
		return (sum() / double(length()));
	}

	double statistician::minimum() const {
		return tinyest;
	}

	double statistician::maximum() const {
		return largest;
	}

	//NON MEMBER FUNCTIONS
	statistician operator +(const statistician& s1, const statistician& s2) {

	}

}