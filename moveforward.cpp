#include <iostream>
using namespace std;

class list{
	public:
		list();
		bool empty();
		int size();
		void add(int k,int x);
		int get(int k);
		void remove(int k);
		void printList();
		int searchMF(int x,int size);
};

struct Node{
		int data;
		Node* next;
};

struct Node* list_head;

list::list(){
	list_head=NULL;
}

bool list::empty(){
	if(list_head==NULL){
		return true;
	}
	else{
		return false;
	}
}

int list::size(){
	int size=0;
	Node* temp=new Node();
	temp=list_head;
	while(temp!=NULL){
		size++;
		temp=temp->next;
	}
	delete temp;
	return size;
}

int list::get(int k){
	Node* temp=new Node();
	int count=0;
	temp=list_head;
	while(temp!=NULL){
		if(count==k-1){
			cout<<temp->data<<endl;
			return 0;
		}
		count++;
		temp=temp->next;
	}
}

void list::add(int k,int x){
	Node* temp1=new Node();
	temp1->data=x;
	temp1->next=NULL;
	if(k==1){
		temp1->next=list_head;
		list_head=temp1;
		return;
	}
	Node* temp2=list_head;
	for(int i=0;i<k-2;i++){
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}

void list::remove(int k){
	Node* temp1=new Node();
	temp1=list_head;
	if(k==1){
		list_head=temp1->next;
		delete temp1;
		return;
	}
	for(int i=0;i<k-2;i++){
		temp1=temp1->next;
	}
	struct Node* temp2=new Node();
	temp2=temp1->next;
	temp1->next=temp2->next;
	delete temp2;
}

void list::printList(){
	Node* temp;
	temp=list_head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
	cout<<endl;
}

//Additional Function
int list::searchMF(int x,int size){
	int position=2;
	Node* temp=new Node();
	temp=list_head;
	if(temp->data==x){
		return 1;
	}
	//Find Position of Node with data=x
	while(temp->next->data!=x){
		//If no Node has data=x , return 0
		temp=temp->next;
		position++;
		if(position>size){
			return 0;
		}
	}
	Node* temp2=new Node();
	temp2=temp->next;
	temp->next=temp->next->next;
	temp2->next=list_head;
	list_head=temp2;

	return position;
}

int main(){
  int K,X,N,M;
	list obj;
	list_head=NULL;
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>K>>X;
		obj.add(K,X);
	}
  
	int sum=0;
  
	cin>>M;
  
	for(int j=0;j<M;j++){
		cin>>X;
		sum+=obj.searchMF(X,N);
	}

  cout<<sum<<endl;
	return 0;
}
