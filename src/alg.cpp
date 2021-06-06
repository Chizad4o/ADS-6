// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
BST<std::string>Tree;
std::string result = "";
char symbol;
std::ifstream file(filename);
if (!file) {
std::cout << "File error!" << std::endl;
return Tree;
}
while (!file.eof()) {
symbol = file.get();
if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
if (symbol >= 'A' && symbol <= 'Z') {
symbol += 32;
}
result += symbol;
} else if (result !="") {
Tree.add(result);
result = "";
}
}
file.close();
return Tree;
}
