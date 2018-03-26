#include "PolyShape.h"
#include "DelLnkList.h"
#include "CharCount.h"
#include "removeDup.h"
#include "Bomb.h"
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>
//#include "StreamCounter.h"
#include "copyList.h"
template <typename T> std::string type_name();


auto ex1() -> int {
	std::initializer_list<class std::unique_ptr<class Shape > > shapes = {
		std::make_unique<Circle>(10),
		std::make_unique<Square>(10),
		std::make_unique<Triangle>(10),
	};
	for (auto& shape : shapes) {
		shape->Draw();
	}
	return 0;
}

auto ex2() -> int {
	{
		std::list<int> pi = { 3, 1, 4, 1, 5, 9, 2, 6 };
		delElem(pi, 1);
		std::copy(std::begin(pi), std::end(pi),
			std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}
	{
		std::list<int> pi = { 3, 1, 4, 1, 5, 9, 2, 6 };
		pi.erase(std::remove(std::begin(pi), std::end(pi), 1),
			     std::end(pi));
		std::copy(std::begin(pi), std::end(pi),
			std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}
	return 0;
}

auto ex3() {
	std::string st = "The quick brown fox, jumped over the little dog";
	std::cout<< findmaxoccur(st).first << std::endl;
}

auto ex4() {
	std::string st = "bbccdddaaba";
	std::cout << removeDup(st) << std::endl;

}

auto ex5() {
	Main();
}
/*
auto ex6() {
	StreamCounter sc;
	std::string words[] = { "Hi",  "there,",  "I",  "need",  "some",  "help",  "with",  "my",  "code.",
		"It",  "is",  "a",  "random",  "string",  "generator",  "which",  "works",  "perfect.",  "However",
		"there",  "is",  "one",  "problem.",  "I",  "want",  "to",  "get",  "the",  "string",  "in",  "my",
		"memory",  "using",  "cin,",  "getline,",  "scanf,",  "or",  "whatever,",  "but",  "that",  "doesn't",
		"work.",  "Can",  "someone",  "tell",  "me",  "how",  "to",  "get",  "the",  "string",  "I",  "generated",
		"and",  "how",  "to",  "store",  "it",  "in",  "a"};
	for (auto& word : words) {
		sc += word;
	}
	sc.print();
}
*/
auto ex7() {
	CopyList::Main();
}
int main() {
	ex7();
}