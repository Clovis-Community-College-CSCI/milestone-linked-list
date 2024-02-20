#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

//Compile the program like this: g++ -o generator generator.cc
//Run the program like this: generator 200000 > input_rem_search200k
int main(int argc, char **argv) {
	int size = 1000;
	if (argc <= 1) {
		cout << "Run the program like this: generator 100000 > insert100k\n";
		exit(1);
	}
	if (argc > 1) size = atoi(argv[1]);
	cerr << "Size is " << size << endl;

	srand(time(NULL));
	//for (int size = 10000; size <= 100000; size += 10000) {
		vector<int> vec;
		for (int i = 0; i < (size * 3) / 10; i++) {
			int x = rand();
			vec.push_back(x);
			cout << "INSERT " << x << endl;
		}
	// 	for (int i = 0; i < size/2; i++) {
	// 		cout << "REMOVE " << vec.at(rand() % vec.size()) << endl;
	// 	}
	// 	for (int i = 0; i < size; i++) {
	// 		cout << "SEARCH " << vec.at(rand() % vec.size()) << endl;
	// 	}
	//}
}
