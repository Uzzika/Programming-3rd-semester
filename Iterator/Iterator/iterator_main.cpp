//Copyright (c) 2023 Dudchenko Olesya

#include "../Iterator/iterator.h"

int main() {
	TVector<int> v1(7);
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TFill(3);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TFill_n(1, 1);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TReplace(2, 9);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}
	v1.TReplace_n(4, 5, 4);
	std::cout << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it;
	}

}