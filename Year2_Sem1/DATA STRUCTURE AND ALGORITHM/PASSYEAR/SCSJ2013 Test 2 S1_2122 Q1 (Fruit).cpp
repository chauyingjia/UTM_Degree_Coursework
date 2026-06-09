 //Program 1

#include <iostream>
#include <iomanip>
using namespace std;
class FruitNode{
	private:
		string name; 
        float price;
    public: 
        FruitNode *next; 
        FruitNode(string n, float p) { 
            name = n;
            price = p; }
        void getFruitInfo() { 
        cout << name << " = RM" << price; }
};
class List{
	private:
		FruitNode *headNode;
	public: 
        List() { 
        headNode = NULL; }
        void task1(string, float);
        void task2();
        void task3(int, string, float);
        void task4();
};

void List :: task1(string n, float p){
	FruitNode *nn = new FruitNode(n,p);
	
	if(!headNode){
		headNode = nn;
		nn->next = headNode;
	
	}else{
		FruitNode* temp = headNode;
		while (temp->next != headNode) {
        temp = temp->next; // Find the last node
        }
        
        nn->next = headNode;
		temp->next = nn;
		headNode = nn;
		
	}
}

void List :: task2(){
	
	if(!headNode){
		cout << "Fruit list is empty" << endl;
		return;
	}
	
	FruitNode *temp = headNode;
	
	while(temp != headNode){
		temp->getFruitInfo(); 
		temp = temp->next;
		cout << ">>";
		temp->getFruitInfo();
		temp = temp->next;
	}
	
	cout << endl;
}

void List :: task3(int num, string n, float p){
	FruitNode *nn=new FruitNode(n,p);
	FruitNode *temp=headNode;
	int number = 1;
	
	if(headNode == NULL){
		cout << "List is empty" << endl;
	
	}else{
		while(temp->next != headNode){
			if(number == num){
				nn->next = temp->next;
				temp->next = nn;
				
			}
			number ++;
			temp = temp->next;
		}
	}
}

void List :: task4(){

	FruitNode *temp = headNode;
	
	if(!headNode){
		cout << "List is empty!" << endl;
		
	}else{
		while(temp!=headNode){
			if(temp->next->next == headNode){
				FruitNode *lastNode = temp->next;
				temp->next = headNode;
	
			}
			
			temp = temp->next;
		}
	}

}

int main()
{
	List fruitList;
	//Incomplete main function definition
	fruitList.task1("Kiwi",21.89);
	fruitList.task2();
	fruitList.task1("Apple",11.95);
	fruitList.task2();
	fruitList.task1("Orange",16.50);
	fruitList.task2();
	fruitList.task3(2,"Grape",19.95);
	fruitList.task2();
	fruitList.task4();
	fruitList.task2();
	fruitList.task4();
	fruitList.task2();
	return 0;
}

