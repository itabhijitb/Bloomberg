#include<string>
#include<unordered_set>
#include<iostream>
#include<array>
using namespace std;
#define LENGTH  'Z' - 'A' + 1

string BuildExpression(char root, std::array<std::array<bool, LENGTH>, LENGTH> graph) {
	string left = "", right = ""; //if no children, left and right should be empty
	for (int i = 0; i < LENGTH; i++) {
		if (graph[root - 'A'][ i]) {
			left = BuildExpression((char)(i + 'A'), graph);
			for (int j = i + 1; j < LENGTH; j++) {
				if (graph[root - 'A'][j]) {
					right = BuildExpression((char)(j + 'A'), graph);
					break;
				}
			}
			break;
		}
	}
	return std::string() + "(" + root + left + right + ")";
}

bool IsCycle(char node, std::array<std::array<bool, LENGTH>, LENGTH> graph, bool visited[]) {
	if (visited[node - 'A'])
		return true;
	visited[node - 'A'] = true;
	for (int i = 0; i < LENGTH; i++) {
		if (graph[node - 'A'][i]) {
			if (IsCycle((char)(i + 'A'), graph, visited))
				return true;
		}
	}
	return false;
}

string SExpression(string s) {
	std::array<std::array<bool, LENGTH>, LENGTH> graph = { false };
	std::unordered_set<char> nodes;
	bool E2 = false;
	for (int i = 1; i < s.size(); i += 6) {
		int x = s[i] - 'A', y = s[i + 2] - 'A';
		if (graph[x][y]) //duplicate edge
			E2 = true;
		graph[x][y] = true;
		nodes.insert(s[i]);
		nodes.insert(s[i + 2]);
	}
	//check error E1: more than 2 children
	bool E1 = false;
	for (int i = 0; i < LENGTH; i++) {
		int count = 0; //number of child
		for (int j = 0; j < LENGTH; j++) {
			if (graph[i][ j])
				count++;
		}
		if (count > 2)
			return "E1";
	}
	if (E2) return "E2"; //return E2 after checking E1

						 //check E3: cycle present and E4: multiple roots
	int numOfRoots = 0;
	char root = ' ';
	for (auto node : nodes) {
		for (int i = 0; i < LENGTH; i++) {
			if (graph[i][node - 'A'])
				break;
			if (i == 25) {
				numOfRoots++;
				root = node;
				bool visited[LENGTH] = { false };
				if (IsCycle(node, graph, visited))
					return "E3";
			}
		}
	}
	if (numOfRoots == 0) return "E3"; //if no root, must be a cycle
	if (numOfRoots > 1) return "E4"; //if more than one roots
	if (root == ' ') return "E5"; //if no edge in input string, invalid input error
	return BuildExpression(root, graph);

}

/*
int main()
{
	std::cout << SExpression("(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)") << std::endl;
}*/
