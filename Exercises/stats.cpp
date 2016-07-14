#include "stats.h"
#include <cstdlib>
#include <iostream>
#include <assert.h>

namespace hua_2C {
	//CONSTRUCTOR
	statistician::statistician() {
		count = 0;
		total = 0.0;
		//tinyest = 0.0;
		//largest = 0.0;
	}

	//MODIFICATION MEMBER FUNCTIONS
	void statistician::next(double r) {
		count += 1;
		total += r;
		if (count == 1) {
			tinyest = r;
			largest = r;
		} else {
			if (r < tinyest) { tinyest = r; }
			if (r > largest) { largest = r; }
		}
		
	}

	void statistician::reset() {
		count = 0;
		total = 0.0;
		//tinyest = 0.0;
		//largest = 0.0;
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

	void statistician::print() const {
		std::cout << "\ncount: " << count
			<< "\ntotal: " << total
			<< "\nsmallest: " << tinyest
			<< "\nlargest: " << largest
			<< "\nmean: " << mean();
	}

	//NON MEMBER FUNCTIONS
	statistician operator +(const statistician& s1, const statistician& s2) {
		statistician s;
		s.count = s1.count + s2.count;
		s.total = s1.total + s2.total;

		if (s1.count != 0 && s2.count != 0) {
			if (s1.tinyest < s2.tinyest) {
				s.tinyest = s1.tinyest;
			}
			else {
				s.tinyest = s2.tinyest;
			}

			if (s1.largest > s2.largest) {
				s.largest = s1.largest;
			}
			else {
				s.largest = s2.largest;
			}
		} else if (s1.count == 0 && s2.count != 0) {
			s.tinyest = s2.tinyest;
			s.largest = s2.largest;
		} else if (s1.count != 0 && s2.count == 0) {
			s.tinyest = s1.tinyest;
			s.largest = s1.largest;
		} 
		
	return s;
	}

	statistician operator *(double scale, const statistician& s) {
		statistician _s;
		if (s.count != 0) {
			if (scale >= 0) {
				_s.count = s.count;
				_s.total = scale * s.total;
				_s.tinyest = scale * s.tinyest;
				_s.largest = scale * s.largest;
			} else {
				_s.count = s.count;
				_s.total = scale * s.total;
				_s.tinyest = scale * s.largest;
				_s.largest = scale * s.tinyest;
			}
			
		}

		return _s;
	}

	bool operator ==(const statistician& s1, const statistician& s2) {
		if (s1.length() == 0 || s2.length() == 0) {
			if (s1.length() == s2.length()) {
				return true;
			}
			else {
				return false;
			}
		} else {
			if (s1.length() == s2.length()
				&& s1.sum() == s2.sum()
				&& s1.mean() == s2.mean()
				&& s1.minimum() == s2.minimum()
				&& s1.maximum() == s2.maximum()) {
				return true;
			}
			else {
				return false;
			}
		}
		
		
	}
}