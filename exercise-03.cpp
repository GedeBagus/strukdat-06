/*
Nama Program	: tugas 3
Nama    		: gede bagus darmagita
NPM		        : 140810180068
Tanggal Buat	: 15-april-2019
Deskripsi	    : tugas 3 praktikum strukdat
*/
#include<iostream>
using namespace std;

struct node{
	char data;
	node* next;
	node* prev;
};

void createNode(node* &newNode);
void insertFirst(node* &head, node* newNode);
void insertLast(node* &head, node* newNode);
void deleteFirst(node* &head, node* &delNode);
void deleteLast(node* &head, node* &delNode);
void traversal(node* head);

int main(){
	node *list=NULL,*p;
	int pil;char loop;
	do{
		system("CLS");
		cout<<"1.Insert First\t3.Delete First\t5.Traversal"<<endl
		<<"2.Insert Last\t4.Delete Last"<<endl;
		do{
			cin>>pil;
		}while(pil<1||pil>5);
		switch(pil){
			case 1:
				createNode(p);
				insertFirst(list,p);
				break;
			case 2:
				createNode(p);
				insertLast(list,p);
				break;
			case 3:
				deleteFirst(list,p);
				break;
			case 4:
				deleteLast(list,p);
				break;
			case 5:
				traversal(list);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y'&&loop!='y'&&loop!='N'&&loop!='n');
	}while(loop=='Y'||loop=='y');
}

void createNode(node* &newNode){
	newNode = new node;
	cout<<"data : ";cin>>newNode->data;
	newNode->next=NULL;
	newNode->prev=NULL;
}
void insertFirst(node* &head, node* newNode){
	if(head==NULL){
		head=newNode;
		head->next=head;
		head->prev=head;
	}else{
		newNode->next=head;
		newNode->prev=head->prev;
		head->prev->next=newNode;
		head->prev=newNode;
		head=newNode;
	}
	cout<<endl<<"insertFirst berhasil!"<<endl;
}
void insertLast(node* &head, node* newNode){
	if(head==NULL){
		head=newNode;
		newNode->next=head;
		newNode->prev=head;
	}else{
		node *last=head;
		while(last->next!=head){
			last=last->next;
		}
		last->next=newNode;
		newNode->prev=last;
		newNode->next=head;
		head->prev=newNode;
	}
	cout<<endl<<"insertLast berhasil!"<<endl;
}
void deleteFirst(node* &head, node* &delNode){
	delNode=head;
	if(head==NULL){
		delNode=NULL;
		cout<<endl<<"Tidak ada yang didelete."<<endl;
	}else if(head->next==head){
		head->next=NULL;
		head->prev=NULL;
		head=NULL;
		cout<<endl<<"deleteFirst berhasil!"<<endl;
	}else{
		head->next->prev=head->prev;
		head->prev->next=head->next;
		head=head->next;
		delNode->next=NULL;
		delNode->prev=NULL;
		delNode=NULL;
		cout<<endl<<"deleteFirst berhasil!"<<endl;
	}
}
void deleteLast(node* &head, node* &delNode){
	delNode=head;
	if(head==NULL){
		delNode=NULL;
		cout<<endl<<"Tidak ada yang didelete."<<endl;
	}else if(head->next==head){
		head->next=NULL;
		head->prev=NULL;
		head=NULL;
		cout<<endl<<"deleteLast berhasil!"<<endl;
	}else{
		node *prevLast;
		while(delNode->next!=head){
			prevLast=delNode;
			delNode=delNode->next;
		}
		prevLast->next=head;
		delNode->prev=NULL;
		delNode->next=NULL;
		delNode=NULL;
		cout<<endl<<"deleteLast berhasil!"<<endl;
	}
}
void traversal(node* head){
	if(head!=NULL){
		node *trav=head;
		cout<<"...<-->";
		do{
			cout<<"'"<<trav->data<<"'";
			if(trav->next!=head){
				cout<<"<-->";
			}
			trav=trav->next;
		}while(trav!=head);
		cout<<"<-->...";
	}else{
		cout<<"List Kosong!"<<endl;
	}
}
