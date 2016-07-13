#include "stats.h"
#include <cstdlib>
#include <iostream>
#include <assert.h>

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
		assert(length() > 0);
		return (sum() / double(length()));
	}

	double statistician::minimum() const {
		assert(length() > 0);
		return tinyest;
	}

	double statistician::maximum() const {
		assert(length() > 0);
		return largest;
	}

	//NON MEMBER FUNCTIONS
	statistician operator +(const statistician& s1, const statistician& s2) {
		statistician s;
		s.count = s1.length() + s2.length();
		s.total = s1.sum() + s2.sum();
		if (s1.minimum() < s2.minimum()) {
			s.tinyest = s1.minimum();
		}
		else {
			s.tinyest = s2.minimum();
		}

		if (s1.maximum() > s2.maximum()) {
			s.largest = s1.maximum();
		} else {
			s.largest = s2.maximum();
		}
	
	return s;
	}

	statistician operator *(double scale, const statistician& s) {
		statistician _s;
		_s.count = s.length();
		_s.total = scale * s.sum();
		_s.tinyest = scale * s.minimum();
		_s.largest = scale * s.maximum();
		return _s;
	}

	bool operator ==(const statistician& s1, const statistician& s2) {
		if (s1.length() == s2.length()
			&& s1.sum() == s2.length()
			&& s1.minimum() == s2.minimum()
			&& s1.maximum() == s2.maximum()) {
			return true;
		}
		else {
			return false;
		}
	}
}