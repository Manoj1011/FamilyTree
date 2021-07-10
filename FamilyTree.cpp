#include<stdio.h>

/*This class Node contains element of node,parent node pointer,children linked list pointer,siblings node pointer which is nxt*/
class Node{
private:
	int elem;	
	class Node* parent;
	class linkedlist* children;
	class Node* nxt;
	friend class linkedlist;
	friend class FamilyTree;
};
class linkedlist{
public:
	linkedlist();
	class Node* head;
	void add(Node* x);
};
linkedlist::linkedlist(){
	head=NULL;		//intialising the head node pointer
}
/*This add function adds elements to linkedlist in addfront manner by creating new nodes*/
void linkedlist::add(Node* x){
	class Node* temp=head;
	head=new Node;
	head=x;
	head->nxt=temp;
}
class FamilyTree{
public:
	class Node* root;
	FamilyTree(int x);
	Node* search(int z);
	Node* recursive_search(Node* main,int z);
	void insertChild(int x,int y);
	void relationship(int i,int j);
};
/*It is a constructor for family tree which adds root node to the tree and intialises parent and children pointer to NULL*/
FamilyTree::FamilyTree(int x){  
	root->elem=x;
	root->parent=NULL;
	root->children=NULL;
}
/*This function search calls recursive_search functions with input root node and int z and returns its node pointer*/
Node* FamilyTree::search(int z){
	return recursive_search(root,z);
}
/*This function recursive_search works mainly on recursion with input node pointer with node and element and returns respective output by going into if-else conditions and returns NULL if node is not present*/
Node* FamilyTree::recursive_search(Node* main,int z){
	class Node *temp;
	if(main->elem==z) return main;
	if(main->children==NULL) return NULL;
	main=main->children->head;
	while(main != NULL){
		temp=recursive_search(main,z);
		if(temp != NULL) return temp;
		main=main->nxt;
	}
	return NULL;
}
/*This function insertChild inserts elem y to elem x first by searching the node if it is NULL it returns No Node Found otherwise it adds new Node and inserts elem y to it and add linkedlist of children also into children node pointer using add function in linkedlist*/
void FamilyTree::insertChild(int x,int y){ 
	Node* temp=search(x);
	if(temp==NULL) printf("No Node Found\n");
	else{
		Node* temp1=new Node();
		temp1->elem=y;
		temp1->parent=temp;
		if(temp->children==NULL) temp->children=new linkedlist();
		temp->children->add(temp1);
	}
}
void FamilyTree::relationship(int i,int j){
	int count=0;		//intialising different count variables to increase the generation and to know the value of dummy count
	int count1=0;		//variables in each while loop
	int count2=0;
	int count3=0;
	int count4=0;
	int count5=0;
	int count6=0;
	int count7=0;
	class Node* temp=search(j);
	class Node* temp1=search(i);
	if(search(j)==NULL || search(i)==NULL){  //this if conditions returns unrelated if search function returns NULL
		printf("UNRELATED\n");
		return;
	}
	class Node* dummy=temp;		//this dummy temp pointers are created to resolve errors i.e segmentation core error.
	class Node* dummy1=temp;	//because when we use repeatedly they are becoming NULL in one while loop hence used multiple
	class Node* dummy2=temp;	//dummy pointers.
	class Node* dummy3=temp;
	class Node* dummy4=temp;
	class Node* dummy5=temp;
	class Node* dummy6=temp;
	class Node* dummy_1=temp1;
	while(dummy_1 != NULL){    //this while loop goes until dummy_1 becomes NULL and prints the child,grandchild,great grand 					     child,great great grand child,ith great grand child
            if(dummy6->elem==dummy_1->elem){
		if(count7==1){
		    printf("%d is child of %d\n",i,j);
                }else if(count7==2){
                    printf("%d is grand child of %d\n",i,j);
                }else if(count7==3){
                    printf("%d is great grand child  of %d\n",i,j);
                }else if(count7==4){
                    printf("%d is great great grand child of %d\n",i,j);
                }else if(count7>4){
		    printf("%d is %dth great grand child of %d\n",i,count7-2,j);
	        }
	        return;
	    }
	    count7=count7+1;	
	    dummy_1=dummy_1->parent;	//it is incrementing the dummy_1 node to its parent node until reaching root node
	}
        while(temp != NULL){	//this while loop goes until temp becomes NULL and prints relationship of parent,grand parent,great grand 					  parent,ith great grand parent
             if(temp->elem==i){
		if(count==1){
		    printf("%d is parent of %d\n",i,j);
                }else if(count==2){
                    printf("%d is grand parent of %d\n",i,j);
                }else if(count==3){
                    printf("%d is great grand parent of %d\n",i,j);
                }else if(count==4){
                    printf("%d is great great grand parent of %d\n",i,j);
                }else if(count>4){
		    printf("%d is %drd great grand parent of %d\n",i,count-2,j);
	        }
	        return;
	    }
	    count=count+1;	
	    temp=temp->parent;  //it is incrementing the temp node to its parent until reaching root node
	}
	while(dummy != NULL){  //this while loop goes until dummy node reaches to NULL and in b/w prints relationship of sibling,great 					 aunt/uncle,great grand aunt/uncle,ith great grand aunt/uncle
             if(dummy->elem==temp1->parent->elem){
		if(count1==1){
		    printf("%d is sibling of %d\n",i,j);
                }else if(count1==2){
                    printf("%d is aunt/uncle of %d\n",i,j);
                }else if(count1==3){
                    printf("%d is great aunt/uncle of %d\n",i,j);
                }else if(count1==4){
                    printf("%d is great grand aunt/uncle of %d\n",i,j);
		}else if(count1==5){
		    printf("%d is great great grand aunt/uncle of %d\n",i,j);
		}else if(count1==6){
		    printf("%d is 3rd great grand aunt/uncle of %d\n",i,j);
                }else if(count1>6){
		    printf("%d is %dth great grand aunt/uncle of %d\n",i,count1-3,j);
	        }
	        return;
	    }
	    count1=count1+1;	
	    dummy=dummy->parent; //incrementing dummy node to its parent node until coming root node
	}
	while(dummy1 != NULL){  //this while goes until dummy1 node becomes NULL and prints relationship of nephew,1st cousin,1st cousin 					  once removed,1st cousin jth times removed
             if(dummy1->elem==temp1->parent->parent->elem){
		if(count2==1){
		    printf("%d is nephew/niece of %d\n",i,j);
                }else if(count2==2){
                    printf("%d is 1st cousin of %d\n",i,j);
                }else if(count2==3){
                    printf("%d is 1st cousin once removed of %d\n",i,j);
                }else if(count2==4){
                    printf("%d is 1st cousin twice removed of %d\n",i,j);
		}else if(count2==5){
		    printf("%d is 1st cousin thrice removed %d\n",i,j);
                }else if(count2>5){
		    printf("%d is 1st cousin %d times removed %d\n",i,count2-2,j);
	        }
	        return;
	    }
	    count2=count2+1;	
	    dummy1=dummy1->parent;	//incrementing dummy1 node to its parent node until coming root node
	}
	while(dummy2 != NULL){	//this while goes until dummy2 node becomes NULL and prints relationship of grand nephew,1st cousin 					  once removed,2nd cousin,2nd cousin jth times removed
             if(dummy2->elem==temp1->parent->parent->parent->elem){
		if(count3==1){
		    printf("%d is grand nephew/niece of %d\n",i,j);
                }else if(count3==2){
                    printf("%d is 1st cousin once removed of %d\n",i,j);
                }else if(count3==3){
                    printf("%d is 2nd cousin of %d\n",i,j);
                }else if(count3==4){
                    printf("%d is 2nd cousin once removed of %d\n",i,j);
                }else if(count3>4){
		    printf("%d is 2nd cousin %d times removed %d\n",i,count3-3,j);
	        }
	        return;
	    }
	    count3=count3+1;	
	    dummy2=dummy2->parent;	//incrementing dummy2 node to its parent node until coming root node
	}
	while(dummy3 != NULL){	//this while goes until dummy3 node becomes NULL and prints relationship of great grand nephew,1st cousin 					  twice removed,2nd cousin once removed,3rd cousin,3rd cousin jth times removed
             if(dummy3->elem==temp1->parent->parent->parent->parent->elem){
		if(count4==1){
		    printf("%d is great grand nephew of %d\n",i,j);
                }else if(count4==2){
                    printf("%d is 1st cousin twice removed of %d\n",i,j);
                }else if(count4==3){
                    printf("%d is 2nd cousin once removed of %d\n",i,j);
                }else if(count4==4){
                    printf("%d is 3rd cousin of %d\n",i,j);
                }else if(count4==5){
		    printf("%d is 3rd cousin once removed %d\n",i,j);
		}else if(count4>5){
		    printf("%d is 3rd cousin %d times removed %d\n",i,count4-4,j);
	        }
	        return;
	    }
	    count4=count4+1;	
	    dummy3=dummy3->parent;	//incrementing dummy3 node to its parent node until coming root node
	}
	while(dummy4 != NULL){	//this while goes until dummy4 node becomes NULL and prints relationship of great great grand nephew,1st 				  	  cousin thrice removed,2nd cousin twice removed,3rd cousin once removed,4th cousin,4th cousin jth times 					  removed
             if(dummy4->elem==temp1->parent->parent->parent->parent->parent->elem){
		if(count5==1){
		    printf("%d is great great grand nephew/niece of %d\n",i,j);
                }else if(count5==2){
                    printf("%d is 1st cousin thrice removed of %d\n",i,j);
                }else if(count5==3){
                    printf("%d is 2nd cousin twice removed of %d\n",i,j);
                }else if(count5==4){
                    printf("%d is 3rd cousin once removed of %d\n",i,j);
                }else if(count5==5){
		    printf("%d is 4th cousin %d\n",i,j);
		}else if(count5>5){
		    printf("%d is 4th cousin %d times removed %d\n",i,count5-5,j);
	        }
	        return;
	    }
	    count5=count5+1;	
	    dummy4=dummy4->parent;	//incrementing dummy4 node to its parent node until coming root node
	}
	while(dummy5 != NULL){	//this while goes until dummy5 node becomes NULL and prints relationship of 3rd great grand nephew,1st 				  	  cousin 4 times removed,2nd cousin thrice removed,3rd cousin twice removed,4th cousin,4th cousin 					  once removed,5th cousion,5th cousin jth times removed
             if(dummy5->elem==temp1->parent->parent->parent->parent->parent->parent->elem){
		if(count6==1){
		    printf("%d is 3rd great grand nephew/niece of %d\n",i,j);
                }else if(count6==2){
                    printf("%d is 1st cousin 4 times removed of %d\n",i,j);
                }else if(count6==3){
                    printf("%d is 2nd cousin thrice removed of %d\n",i,j);
                }else if(count6==4){
                    printf("%d is 3rd cousin twice removed of %d\n",i,j);
                }else if(count6==5){
		    printf("%d is 4th cousin once removed %d\n",i,j);
		}else if(count6==6){
		    printf("%d is 5th cousin %d\n",i,j);
		}else if(count6>6){
		    printf("%d is 5th cousin %d times removed %d\n",i,count6-6,j);
	        }
	        return;
	    }
	    count6=count6+1;	
	    dummy5=dummy5->parent;	//incrementing dummy5 node to its parent node until coming root node
	}

}
int main(){
    class FamilyTree ft(100);
    ft.insertChild(100,2);
    ft.insertChild(100,6);
    ft.insertChild(100,1112);
    ft.insertChild(2,5);
    ft.insertChild(2,3);
    ft.insertChild(2,7);
    ft.insertChild(6,9);
    ft.insertChild(1112,112);
    ft.insertChild(1112,4);
    ft.insertChild(1112,4);
    ft.insertChild(5,76);
    ft.insertChild(7,48);
    ft.insertChild(3,99);
    ft.insertChild(112,56);
    ft.insertChild(112,65);
    ft.insertChild(4,22);
    ft.insertChild(4,25);
    ft.insertChild(76,1);
    ft.insertChild(76,199);
    ft.insertChild(199,227);
    ft.insertChild(227,245);
    ft.insertChild(245,178);
    ft.insertChild(48,106);
    ft.insertChild(48,11);
    ft.insertChild(99,104);
    ft.insertChild(99,111);
    ft.insertChild(99,110);
    ft.relationship(100,110);
    ft.relationship(6,3);
    ft.relationship(1112,65);
    ft.relationship(4,48);
    ft.relationship(3,178);
    ft.relationship(1112,178);
    ft.relationship(100,178);
    ft.relationship(56,65);
    ft.relationship(25,106);
    ft.relationship(1,4);
    ft.relationship(22,227);
    ft.relationship(227,178);
    ft.relationship(2,106);
    ft.relationship(100,111);
    ft.relationship(2,245);
    ft.relationship(2,104);
    ft.relationship(100,227);
    ft.relationship(100,106);
    ft.relationship(100,11);
    ft.relationship(1000,11);
    ft.relationship(48,5);
}
