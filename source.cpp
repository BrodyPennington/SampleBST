#include "BST.h"
#include <iostream>

int main() {
  BST b;
  
  b.insert(56); 
  b.insert(34);  
  b.insert(70);  
  b.insert(5);  
  b.insert(1);  
  b.insert(42);  
  b.insert(40);  
  b.insert(52);  
  b.insert(62);  
  b.insert(57);  
  b.insert(89);  
  b.insert(90);     
 

  std::cout << b.find(44) << std::endl; 
  std::cout << b.find(34) << std::endl; 


  b.remove(34);    
  std::cout << b.find(34) << std::endl; 

  b.insert(44);    
  std::cout << b.find(44) << std::endl;  

  b.remove(57);    
  std::cout << b.find(57) << std::endl; 

 
  b.postorder(std::cout);
  b.preorder(std::cout);
  b.inorder(std::cout);
  
}   