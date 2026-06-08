// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. Chau Ying Jia A23CS0213
// 2. Poh Lok Yee A23CS0262

#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];

   	string n;
   	int cw, fe;  
   	int student = 0;
	     
    fstream inFile ("Marks.txt", ios::in);
    fstream resultFile ("Results.txt", ios::out);
    
    if(inFile){
    	cout << "Student mark info: " << endl;
    	
    	while(!inFile.eof()){   		
    		inFile >> n;
			inFile >> cw >> fe;
			

			studList[student] = new Student(n, cw, fe);
			studList[student]->printInfo();
			student++;			
		} 	
		
		inFile.close();
				
	}else
		cout << "File is not running." << endl;
    
    if(resultFile){
    	cout << "Print and save results to file: " << endl;
    	
    	for(student=0; student<LIST_SIZE; student++){   		

			studList[student]->printResult();
			studList[student]->printResultFile(resultFile);
			delete studList[student];
		} 	
		
		resultFile.close();
				
	}else
		cout << "File is not running." << endl;   
    
    return 0;
}
