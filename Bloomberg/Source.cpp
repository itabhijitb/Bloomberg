#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


int getScore(std::string s) {
	size_t length = s.size();
	if (length<1) return 0;
	std::vector<std::vector<std::size_t> > data(length, std::vector<std::size_t>(length));
	std::vector<std::vector<std::size_t> > data1(length, std::vector<std::size_t>(length));
	int res = 1;
	
	for (int i = 0; i< length; i++) {
		data[i][i] = 1;
		data1[i][i] = 1;
	}
	for (int i = length - 1; i >= 0; i--) {
		for (int j = i + 1; j<length; j++) {
			if (s[i] == s[j]) {
				data[i][j] = std::max(std::max(data[i + 1][j], data[i][j - 1]), data[i + 1][j - 1] + 2);
			}
			else {
				data[i][j] = std::max(std::max(data[i + 1][j], data[i][j - 1]), data[i + 1][j - 1]);
			}
		}
	}

	reverse(s.begin(), s.end());
	for (int i = length - 1; i >= 0; i--) {
		for (int j = i + 1; j<length; j++) {
			if (s[i] == s[j]) {
				data1[i][j] = std::max(std::max(data1[i + 1][j], data1[i][j - 1]), data1[i + 1][j - 1] + 2);
			}
			else {
				data1[i][j] = std::max(std::max(data1[i + 1][j], data1[i][j - 1]), data1[i + 1][j - 1]);
			}
		}
	}
	int n = length;
	for (int i = 0; i<length - 1; i++) {
		res = data[0][i] * data1[0][n - i - 2] > res ? data[0][i] * data1[0][n - i - 2] : res;
	}
	return res;
}

/*
int main() {
	std::cout << getScore("acdapmpomp") << std::endl;
	return 0;
}*/