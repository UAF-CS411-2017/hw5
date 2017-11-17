#ifndef _CS_411_HW2_CPP_
#define _CS_411_HW2_CPP_

#include "build.h"
#include <algorithm>
using std::max;
#include <unordered_map>
using std::unordered_map;

/*#include <iostream>
using std::cout;
using std::endl;*/

inline const bool bridgesCross(const vector<int> & a, const vector<int> & b) {
	return ((a[0] <= b[0] && a[1] >= b[1]) || (a[0] >= b[0] && a[1] <= b[1]));
}

/*inline const bool vectorContains(const vector<int> & a, const int & b) {
	auto contains = false;

	for(auto i : a) {
		if(i == b) {
			contains = true;
			break;
		}
	}

	return contains;
}

inline const bool semiEqual(const vector<int> & a, const vector<int> & b) {
	if(a.size() != b.size())
		return false;

	auto equal = true;

	for(auto i : b) {
		if(!vectorContains(a, i)) {
			equal = false;
			break;
		}
	}

	return equal;
}

class Bridge {
	public:
		Bridge(const int & a, const int & b, const int & weight) :
		_a(a), _b(b), _weight(weight) {
			Bridge::instances++;
		}

		~Bridge() {
			Bridge.instances--;
		}

		const bool crosses(const Bridge & other) {
			return ((this->_a <= other._a && this->_b >= other._b) || (this->_a >= other._a && this->_b <= other._b));
		}

	private:
		const int & _a, _b, _weight;
		static int instances;
};

int Bridge::instances = 0;*/

const unsigned int getMax(const vector<vector<int>> & initialSet, vector<vector<int>> & currentSet, const unsigned int index) {
	if(index < initialSet.size()) {
		auto item = initialSet[index];
		auto valid = true;

		for(auto curr : currentSet)
			if(bridgesCross(item, curr))
				valid = false;

		if(valid) {
			currentSet.push_back(item);
			auto withMe = getMax(initialSet, currentSet, index + 1);

			currentSet.pop_back();
			auto withoutMe = getMax(initialSet, currentSet, index + 1);

			return max(withMe, withoutMe);
		}
		else {
			return getMax(initialSet, currentSet, index + 1);
		}
	}
	else {
		unsigned int max = 0;
		
		for(auto item : currentSet)
			max += item[2];

		return max;
	}
}

const int build(const int & w, const int & e, const vector<vector<int>> & cbs) {
	vector<vector<int>> workingSet;
	return getMax(cbs, workingSet, 0);
}

#endif
