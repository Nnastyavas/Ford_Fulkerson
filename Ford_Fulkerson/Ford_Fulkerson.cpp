#include <iostream>
#include<fstream>
#include "Map.h"
#include"Flows.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Ru");
	ifstream input("input.txt");
	Flows* flow = new Flows(input);
	// Выводим максимальный поток
	int max = flow->max_flow();
	input.close();
	delete flow;
	cout <<"Максимальный поток в транспортной сети: "<< max << endl;
	return 0;
}