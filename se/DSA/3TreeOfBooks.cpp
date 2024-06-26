/*
Author : Kaustubh Kolhe
Problem Statement:
A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a
tree and print the nodes. Find the time and space requirements of your method.
*/
#include <iostream>

using namespace std;

struct node{
	char label[20];           
	int ch_count;              
	struct node *child[10];            
}*root;                        

class BST{
    public:
        void createBookTree();
        void displayBookTree();
        BST(){
            root = nullptr;
        }
};

void BST::createBookTree(){
    int i, j , k;
    root = new node();
    cout<<"Enter the name of the Book: "<<endl;
    cin>>root->label;
    cout<<"Enter the no. of chapters in the Book: "<<endl;
    cin>>root->ch_count;
    for(i = 0 ; i< root->ch_count; i++){
        root->child[i] = new node;
        cout<<"Enter the chapters name: "<<endl;
        cin>>root->child[i]->label;
        cout<<"Enter the no. of sections in this chapter: "<<endl;
        cin>>root->child[i]->ch_count;
        for(j = 0 ; j < root->child[i]->ch_count  ; j++){
            root->child[i]->child[j] = new node;
            cout<<"Enter the name of the section: "<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter the no. of subsections in this section: "<< endl;
            cin>>root->child[i]->child[j]->ch_count;
            for(k = 0 ; k < root->child[i]->child[j]->ch_count; k++){
                root->child[i]->child[j]->child[k] = new node;
                cout<<"Enter the name of the sub-section: "<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
            }   
        }
    }
}

void BST::displayBookTree(){
    cout<<"Book : " <<root->label<<endl;
    for(int i = 0  ; i <root->ch_count; i++){
        cout<<"l_____Chapter: "<<root->child[i]->label<<endl;
        for(int j = 0 ; j <root->child[i]->ch_count ; j++){
            cout<<"l\tl_____Section: "<<root->child[i]->child[j]->label<<endl;
            for(int k = 0 ; k <root->child[i]->child[j]->ch_count; k ++){
                cout<<"l\tl\tl_____Sub-section: "<<root->child[i]->child[j]->child[k]->label<<endl;
            }
        }
    }
}

int main(){
    BST bst ;
    int choice;
    do{
		cout<<"\n-----------------"<<endl;
		cout<<"Book Tree Creation"<<endl;
		cout<<"-----------------\n"<<endl;
        cout<<"1. Create a book Tree. \n2. Display a Book Tree. \n3. Exit"<<endl;
        cout<<"Enter your choice: " <<endl;
        cin>>choice;
        switch (choice){
        case 1 :
            cout<<"Taking input from user: \n\n" <<endl;
            bst.createBookTree();
            cout<<"\n\n";
            break;
        case 2 : 
            cout << "\n-----Book Hierarchy---\n "<<endl;
            bst.displayBookTree();
            break;
        case 3 :
            break;
        default:
            cout<<"[ERROR] Enter a valid input.\n"<<endl;
            break;
        }
    }while(choice != 3);
    return 0;
};
