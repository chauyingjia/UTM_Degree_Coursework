// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. Chau Ying Jia A23CS0213
// 2. Poh Lok Yee A23CS0262

#define STUDENT_H
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

// Class defintion
class Student {
	private:
    	string name;
   		int cwMark, feMark;

	public:
		
		Student (string n, int cw, int fe){
			name = n;
			cwMark = cw;
			feMark = fe;
		}
		
		int getTotalMark(){
			return cwMark + feMark;
		}
		
		string getGrade(){
			int totMark = getTotalMark();
			
			if(totMark >= 75 && totMark <= 100)
				return "A";
				
			else if(totMark >= 65)
				return "B";
				
			else if(totMark >= 50)
				return "C";
				
			else if(totMark >= 35)
				return "D";
				
			else if(totMark >= 0)
				return "E";		
			
			else
				return "Error";	
		}
		
		void printInfo(){
		 	cout << "Name: " << name << endl;
			cout << "Coursework: " << cwMark << endl;
			cout << "Final Exam: " << feMark << endl << endl;
		}
		
		void printResult(){
			cout << name << " " << getTotalMark() << " " << getGrade() << endl;
		}
		
		void printResultFile(fstream &resultFile){
			resultFile << name << " " << getTotalMark() << " " << getGrade() << endl;
		}
	
		~Student(){
			cout << "Destroy student object - " << name << endl;
		}
};
