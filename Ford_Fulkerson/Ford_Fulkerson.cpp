#include <iostream>
#include<fstream>
#include "Map.h"
#include"Flows.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Ru");
	ifstream input("input.txt");
	Flows* flow = new Flows(input);
	// ������� ������������ �����
	int max = flow->max_flow();
	input.close();
	delete flow;
	cout <<"������������ ����� � ������������ ����: "<< max << endl;
	return 0;
}