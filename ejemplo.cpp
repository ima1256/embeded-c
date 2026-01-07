#include <iostream>
#include <vector>
using namespace std;

void duplicate(int &x) {
  x *= 2;
}

void printSize(int v[]) {
    std::cout << "Size: " << sizeof(v) << std::endl;
}

int main() {

  int x = 2;

  int v1[3] = {1, 2, 3};

  for (int i = 0; i < 5; i++)
    duplicate(x);

  cout << x <<endl;

  vector<int> sensores = {1, 2, 3, 10}; 

  printSize()

  for (int sensor : sensores) {
    cout << sensor << endl;
  }

  for (int i = 0; i < sensores.size(); i++) {
    duplicate(sensores[i]);
  }

  for (int sensor : sensores) {
    cout << sensor << endl;
  }

  double suma = 0.0;

  string mytext = "Hola que tal estamos";

  cout << "Hello World!" << "Hola \"HHH\" \t que tal " << suma << "\n\n\n";

  cout << mytext;

  return 0;

}
