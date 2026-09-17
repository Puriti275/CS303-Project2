#include <iostream>
#include <fstream>
#include <string>

// create files for input testing!
int main (int argc, char** argv){
	if (argc != 2){ std::cout << "uh oh!" << std::endl; return -1; }
	std::string n_s = argv[1];
	int n = std::stoi(n_s);
	std::ofstream fout(n_s);
	for(int i = 0; i < n; ++i){
		fout << i << std::endl;
	}
	fout.close();
	return 0;
}
