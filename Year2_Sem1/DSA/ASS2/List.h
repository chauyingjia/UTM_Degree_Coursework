#include <iostream>
#include <string>

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;
        
    public:
        List() { 
            cout << "Create list...\n";
            head = NULL; last = NULL;
        }
        
        void insertNode(Student *newStud) {
        	cout << "Insert " << newStud->getName() << "\n";
        	
        	if(!head || newStud->getName() < head->getName()){		//need !head meh???
        		newStud->setNext(head);
        		head = newStud;
        		
				if (!last) {       // This ensures last is set when adding the first node
				        last = newstud;
				    }
				    
				    return;           // Exit because there's nothing more to do
				}

        	
			Student* currNode = head;
			Student* prevNode = NULL;
        	
        	while(currNode && currNode->getName() < newStud->getName()){
        		prevNode = currNode;
				currNode = currNode->getNext();
			}
			
			newStud->setNext(currNode);
			prevNode->setNext(current);
			
			if(!currNode{
					last = newStud;
			}	
        }
        
        Student *findNode(string name) {
        	Student *curr = head;
        	
        	while(curr){
        		if(curr->getName() == name){
        			
        			return curr;
				}
				
				curr = curr->getNext();
			}
        	
            return NULL;
        }
        
        void deleteNode(string name) {
            Student *stud, *prev;
			stud = head;
			
			if(!head){
				return;
		
			}else if(head->getName() == name){
				head = head->getNext();
				
				if(!head){
					last = NULL;			//when list has only one node at this time
				}
				
				delete stud;
				return;
				
			}
			
			prev = head;
			while(prev->getNext() && prev->getNext()->getName() != name){
				prev = prev->getNext();
			}
			
			if(prev->getNext()){
				stud = prev->getNext();
				prev->setNext(stud->getNext());
				
				if(!prev->getNext()){
					last = prev;
				}
				
				delete stud;
			}
			
			
			
		
        }
        
        void displayList() {
        	Student *stud = head;
        	
        	while (stud != NULL) {
        		stud->printResult();
        		stud = stud->getNext();
			}
        }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        ~List() {
        	Student *stud = head;
        	cout << "Destroy list...\n";
        	while (stud != NULL) {
        		Student *prevStud = stud;
        		stud = stud->getNext();
        		delete prevStud;
			}
		}
};
