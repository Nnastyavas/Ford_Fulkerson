#pragma once
#include<fstream>
#include<string>
#include "Map.h"
#include "Used_function.h"
class Flows {
private:
	int numOfVertex;
	int numOfEdge;
	int sourceVertex;
	int destinationVertex;

	int* capacity;
	int* onEnd;
	int* nextEdge;
	int* firstEdge;
	int* visited;

	int INF = INT_MAX;
public:
	~Flows() {
		if (this != NULL) {
			delete[] capacity;
			delete[] onEnd;
			delete[] nextEdge;
			delete[] firstEdge;
			delete[] visited;
		}
	}
	Flows(ifstream& file) {
		Map<char, int>* Map_from_char_to_number = new Map<char, int>();

		int edgeCount = 0;
		numOfEdge = 0;
		numOfVertex = 0;
		CheckInput(file, Map_from_char_to_number);
		visited = new int[numOfVertex];
		firstEdge = new int[numOfVertex * 2];
		capacity = new int[numOfEdge * 2];
		onEnd = new int[numOfEdge * 2];
		nextEdge = new int[numOfEdge * 2];
		for (int i = 0; i < numOfVertex; ++i) {
			firstEdge[i] = -1;
			visited[i] = 0;
		}


		file.clear();
		file.seekg(ios::beg);

		while (!file.eof()) {
			string s1;
			int vert1, vert2, cap;
			getline(file, s1);
			vert1 = Map_from_char_to_number->find(s1[0]);
			vert2 = Map_from_char_to_number->find(s1[2]);
			cap = stoi(s1.substr(4));
			addEdge(vert1, vert2, edgeCount, cap);

		}
		Map_from_char_to_number->clear();
	}
	int max_flow() {
		int maxFlow = 0;
		int iterationResult = 0;
		while ((iterationResult = findFlow(sourceVertex, INF)) > 0) {
			for (int i = 0; i < numOfVertex; ++i)
				visited[i] = 0;
			maxFlow += iterationResult;
		}
		return maxFlow;
	}

	void addEdge(int edge, int vertex, int& edgeCount, int cap) {
		// Прямое ребро
		onEnd[edgeCount] = vertex;
		nextEdge[edgeCount] = firstEdge[edge];
		firstEdge[edge] = edgeCount;
		capacity[edgeCount++] = cap;
		// Обратное ребро
		onEnd[edgeCount] = edge;
		nextEdge[edgeCount] = firstEdge[vertex];
		firstEdge[vertex] = edgeCount;
		capacity[edgeCount++] = 0;
	}

	int findFlow(int edge, int flow) {
		if (edge == destinationVertex)
			return flow;
		visited[edge] = true;
		for (int edges = firstEdge[edge]; edges != -1; edges = nextEdge[edges]) {
			int to = onEnd[edges];
			if (!visited[to] && capacity[edges] > 0) {
				int minResult = findFlow(to, min(flow, capacity[edges]));
				if (minResult > 0) {
					capacity[edges] -= minResult;
					capacity[edges ^ 1] += minResult;
					return minResult;
				}
			}
		}
		return 0;
	}

	void CheckInput(ifstream& file, Map<char, int>*& Map_from_char_to_number) {
		int str_num = 1;
		while (!file.eof()) {
			string s1;
			getline(file, s1);
			if (s1.size() >= 5) {
				if (!((s1[0] >= 'A' || s1[0] <= 'Z') && (s1[1] == ' '))) {
					throw std::exception(string(("Error entering the first character in the string. Check the correctness of the input in the file and correct these errors in the line under the number: " + to_string(str_num))).c_str());
				}
				if (!((s1[2] >= 'A' || s1[2] <= 'Z') && (s1[3] == ' '))) {
					throw std::exception(string(("Error entering the second character in the string. Check the correctness of the input in the file and correct these errors in the line under the numbe: " + to_string(str_num))).c_str());
				}
				string cur;

				for (int i = 4; i < s1.size(); ++i) {
					if (s1[i] >= '0' || s1[i] <= '9')
						cur += s1[i];
					else {
						throw std::exception(string(("Error entering bandwidth in the string or the presence of a space after it. Check the correctness of the input in the file and correct these errors in the line under the number:" + to_string(str_num))).c_str());
					}
				}
				if (!Map_from_char_to_number->find_is(s1[0])) {
					Map_from_char_to_number->insert(s1[0], numOfVertex);
					++numOfVertex;
				}
				if (!Map_from_char_to_number->find_is(s1[2])) {
					Map_from_char_to_number->insert(s1[2], numOfVertex);
					++numOfVertex;
				}

			}
			else
			{
				throw std::exception(string(("A data-entry error. Check the correctness of the input in the file and correct these errors in the line under the number: " + to_string(str_num))).c_str());
			}
			++str_num;
			++numOfEdge;
		}

		if (Map_from_char_to_number->find_is('S'))
			sourceVertex = Map_from_char_to_number->find('S');
		else {
			throw std::exception("Source is missing");
		}

		if (Map_from_char_to_number->find_is('T'))
			destinationVertex = Map_from_char_to_number->find('T');
		else {
			throw std::exception("Sink is missing");
		}
	}
};