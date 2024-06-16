#include <iostream>
#include <cstdlib>
using namespace std ;

int count ;

class Node{
public:
	string task ;
	Node *prev ;
	Node *next ;
	
	Node( string task){
		this->task = task ;
		this->prev = NULL ;
		this->next = NULL ;
	}
};

class dbLinkList{
public:
	Node *head ;
	Node *tail ;
	
	dbLinkList(){
		this->head = NULL ;
		this->tail = NULL ;
	}
	
	void pushHead(string task) ;
	void pushTail(string task) ;
	void pushMid(int position , string task) ;
	void popHead() ;
	void popTail() ;
	void popMid(int position) ;
	void display() ;
	string gettingTask(int position) ;
};

void dbLinkList::pushHead(string task){
	Node *node = new Node(task) ;
	
	if (head == NULL){
		head = node ;
		tail = node ;
		return ;
	}
	else{
		node->next = head ;
		head->prev = node ;
		head = node ;
	}
}

void dbLinkList::pushTail(string task){
	Node *node = new Node(task) ;
	
	if (tail == NULL){
		tail = node ;
		head = node ;
		return ;
	}
	else{
		node->prev = tail ;
		tail->next = node ;
		tail = node ;
	}
}

void dbLinkList::pushMid(int position , string task){
	Node *node = new Node(task) ;
	
	if (position == 1 ){
		pushHead(task) ;
		return ;
	}
	
	Node *temp ;
	temp = head ;
	int counter = 1 ;
	
	while (counter != position-1){
		temp = temp->next ;
		counter++ ;
	}
	
	if (!temp){
		delete node ;
		cout << "\n\t\t ERROR \n\t This position does not exsits " ;
		return ;
	}
	
	node->prev = temp ;
	node->next = temp->next ;
	
	if(temp->next){
	temp->next->prev = node ;
	}
	
	temp->next = node ;
}

void dbLinkList::popHead(){
	if (head == NULL){
		cout << "\n\t\t ERROR \n\t Your TO-DO List is empty" ;
		return ;
	}
	
	Node *temp ;
	temp = head->next ;
	
	cout<< "This task is removed from the list = " << head->task ;
	delete head ;
	head = temp ;
	
	if(head) {
		head->prev = NULL ;
	}
	else{
		head = NULL ;
	}
}

void dbLinkList::popTail(){
	if(tail == NULL){
		cout << "\n\t\t ERROR \n\t Your TO-DO List is empty" ;
		return ;
	}
	
	Node *temp ;
	temp = tail->prev ;
	
	cout<< "This task is removed from the list =  " <<tail->task ;
	delete tail ;
	tail = temp ;
	
	if(tail){
	tail->next = NULL ;
	}
	else{
		head = NULL ;
	}
}

void dbLinkList::popMid(int position){
	if (head == NULL){
		cout << "\n\t\t ERROR \n\t Your TO-DO List is empty" ;
		return  ;
	}
	
	Node *temp ;
	temp = head ;
	int counter = 1 ;
	
	while (counter != position){
		temp = temp->next ;
		counter++ ;
	}
	
	if(!temp){
		return ;
	}
	
	temp->next->prev = temp->prev ;
	temp->prev->next = temp->next ;
	cout << "The task "<< temp->task << " at the position "<< position <<" has been removed from the list" ;

	delete temp ;
	return ;

}

void dbLinkList::display(){
	if (head == NULL){
		cout << "\n\t\t ERROR \n\t List is empty" ;
		return ;
	}
	
	cout << "\n\t This is the current list (from head to tail):\n" ;
	Node *temp = head ;
	
	int x = 1 ;
	
	while(temp){
		cout <<"\n\t Task no. "<<x<<": " << temp->task ;
		temp = temp->next ;
		x++ ;
	}
}

string dbLinkList::gettingTask(int position){
	string task ;
	
	if (head == NULL){
		cout << "\n\t\t ERROR \n\t Your TO-DO List is empty" ;
		return NULL ;
	}
	
	Node *temp ;
	temp = head ;
	int counter = 1 ;
	
	while (counter != position){
		temp = temp->next ;
		counter++ ;
	}
	
	if(!temp){
		return NULL ;
	}
	
	temp->next->prev = temp->prev ;
	temp->prev->next = temp->next ;
	
	task = temp->task ;
	
	delete temp ;
	return task ;
}

string getTask(string task){

	cin.ignore() ;
	cout << "\n\t Write your task = " ;
	getline(cin , task) ;
	return task ;
}

int getPosition(int position){
	cout << "\n\t Write the position of the data = " ;
	cin >> position ;
	return position ;
}

int main(){
	
	dbLinkList dll1 ;
	
	int data , position , choice , length , num , position1 , choice2 ;
	string task ;
	bool flag , flag2 , flags;
	num = 0 ;
	
	flag = true ;
	
while(flag){
	cout << "\n\n\tWhat do you want to do :\n\n\t 1: Insert task in list \n\t 2: Delete task from list \n\t 3: Display list \n\t 4: Further options \n\n\t 0: Terminate the programe \n\n\t\t->" ;
	cin >> choice ;
	
	switch(choice){
		
		case 1 :
			dll1.pushTail(getTask(task)) ;
			count ++ ;
			system("cls") ;	
			cout << "\n\n\t TASK HAS BEEN ADDED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
		break ;
		
		case 2 :
			dll1.popHead() ;
			count-- ;
			system("cls") ;
			cout << "\n\n\t TASK HAS BEEN REMOVED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
		break ;
		
		case 3 :
			system("cls") ;
			dll1.display() ;
		break ;
		
		case 4 :
			system("cls") ;
			flag2 = true ;
		while(flag2){
				cout << "\n\n\tWhat do you want to do :\n\n\t 1: Write task at the start of TO-DO list \n\t 2: Write task at the end of TO-DO list \n\t 3: Write task in the middle of TO-DO list \n\t 4: Remove first task \n\t 5: Remove last task \n\t 6: Remove task from the mid \n\t 7: Display my TO-DO list \n\t 8: Sorting my TO-DO list \n\t 9: To clear List \n\t 10: Back to main menu \n\n\t\t->" ;
				cin >> choice2 ;
			switch(choice2){
				case 1 :
					dll1.pushHead(getTask(task)) ;
					count ++ ;
					system("cls") ;
					cout << "\n\n\t TASK HAS BEEN ADDED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
				continue ;
				
				case 2 :
					dll1.pushTail(getTask(task)) ;
					count ++ ;
					system("cls") ;
					cout << "\n\n\t TASK HAS BEEN ADDED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
				continue ;
				
				case 3 :
					int size ;
					count ++ ;
					cout << "\n\n\tHow many elements you want to insert in the list = " ;
					cin >> size ;
					
					dll1.display() ;
					
					for(int x=0 ; x<size ; x++){
						dll1.pushMid(getPosition(position) , getTask(task)) ;
						cout << "\n\n\t TASK HAS BEEN ADDED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
					}		
					
					system("cls") ;
				continue ;
				
				case 4 :
					dll1.popHead() ;
					count-- ;
					system("cls") ;
					cout << "\n\n\t TASK HAS BEEN REMOVED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
				continue ;
				
				case 5 :
					dll1.popTail() ;
					count-- ;
					system("cls") ;
					cout << "\n\n\t TASK HAS BEEN REMOVED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
				continue ;
				
				case 6 :
					dll1.popMid(getPosition(position)) ;
					count-- ;
					system("cls") ;
					cout << "\n\n\t TASK HAS BEEN REMOVED! \n\t TOTALL NUMBER OF TASKS = "<< count ;
				continue ;
				
				case 7 :
					system("cls") ;
					dll1.display() ;
				continue ;
				
				case 8 :
					flags = true ;
					while (flags){
						system("cls") ;
						dll1.display() ;
						
						cout << "\n\n\t Write a task number you want to sort (Type 0 to Exit Sorting)= " ;
						cin >> position1 ;
						
						if(position1 == 0){
							system("cls") ;
							flags = false ;
						}
						else{
						task = dll1.gettingTask(position1) ;
						
						cout << "\n\n\t Write the index number where to put this task = ";
						cin >> num ;
						
						dll1.pushMid(num , task) ;

						}
					}
				continue ;
				
				case 9 :
					for(int x=0 ; x<count ; x++){
						dll1.popHead() ;
						system("cls") ;
					}
					cout << "\n\n\t LIST HAS BEEN CLEARED" ;
				continue ;
				
				case 10 :
					system("cls") ;
					flag2 = false ;
				continue ;
				
					if(!(choice >= 1 && choice <=10)){
						cout << "\n\n\t Error \n\t Invalid command" ;
					}
				}	
				
			case 0 :
				flag = false ;
			break ;	
				
			if(!(choice >= 0 && choice <=4)){
				cout << "\n\n\t Error \n\t Invalid command" ;
			}
		  }
		}
	}
	return 0 ;
}
