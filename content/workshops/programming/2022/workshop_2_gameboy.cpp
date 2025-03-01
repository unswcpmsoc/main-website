#include <algorithm>
#include <iostream>
#include <vector>
#include "gameboy.h"

using namespace std;

void remember(int a) {
	// partitioned in to [0, 100), [100, 200), ...
	// only considering mods 6, 8, 10, 12
	for (int a_ = a, m = 6; m <= 12; m += 2) {
		bit_set(m * 100 + a_ % m);
		a_ /= m;
	}
}

int compare(int b) {
	vector<int> pos;
	for (int b_ = b, m = 6; m <= 12; m += 2) {
		pos.push_back(b_ % m);
		b_ /= m;
	}
	for (int m = 12; m >= 6; m -= 2) {
		if (!bit_get(m * 100 + pos.back())) {
			if (pos.back() < m - 1 - pos.back()) { // go from left to right
				for (int i = 0; i < pos.back(); ++i) {
					if (bit_get(m * 100 + i)) return 1;
				}
				return -1;
			}
			else { // go from right to left
				for (int i = m - 1; i > pos.back(); --i) {
					if (bit_get(m * 100 + i)) return -1;
				}
				return 1;
			}
			for (int i = 0; i < m; ++i) {
				if (bit_get(m * 100 + i)) return (i < pos.back()) * 2 - 1;
			}
		}
		pos.pop_back();
	}
	return 0;
}