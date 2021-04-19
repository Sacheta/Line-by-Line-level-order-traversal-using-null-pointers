//Program generating a whole binary tree at run time. Supporting Level order traversal using efficient solution of complexity O(n) and auxiliary space of  O(w),w=width of tree. It uses queue DS to implement the required traversal. we push a node into queue. while removing it, we add its left and right children too.So, by te end of one level, next level is already in the queue

#include<iostream>
#include<queue>
using namespace std;

class node{  //node class
public:
    int data;
    node *left,*right;
    static node *spare;
    node(){  //default constructor
        data=0;
        right=left=nullptr;
    }
    node(int n){  //parameterized constructor
        data=n;
        right=left=nullptr;
    }

    node* create(node *root){  //function to create root
        if(root!=nullptr){ //if root already created
            cout<<"Already Created!"<<endl;
            return root;
        }
        node *curr=new node();
        cout<<"Enter value of root: ";
        cin>>curr->data;
        return curr;
    }

    void searchn(node *root,int n,int a){  //function for searching node by n key and if node by value a exists, printing it already exists, so no such more node can be added
        if(root==nullptr)
            return;
        if(root->data==a){
            cout<<"Value already exists!"<<endl;
            spare=root;
            return;
        }
        if(root->data==n)  //if required node found, save it in spare
            spare=root;
        searchn(root->left,n,a);
        searchn(root->right,n,a);
    }

    void leftn(node *root){  //function to add left child of root
        if(root==nullptr){  //if no tree created
            cout<<"No tree created!"<<endl;
            return;
        }
        int n,a;
        cout<<"Enter value of parent node: ";
        cin>>n;
        cout<<"Enter value to be inserted: ";
        cin>>a;
        searchn(root,n,a); //calling search() to find if required node exists and if node with value a already eixists
        if(spare==nullptr){ //if no required node exists with key n
            cout<<"No such node Exists!"<<endl;
            return;
        }
        if(spare->data==a){ //if node already exists
            spare=nullptr;
            return;}
        if(spare->left!=nullptr){ //if left child already exists
            cout<<"Left Child already Exists!"<<endl;
        spare=nullptr;
            return;
        }
        node *curr=new node(a);
        spare->left=curr;
        spare=nullptr;

    }

    void rightn(node *root){  //similar as leftn()
        if(root==nullptr){
            cout<<"No tree created!"<<endl;
            return;
        }
        int n,a;
        cout<<"Enter value of parent node: ";
        cin>>n;
        cout<<"Enter value to be inserted: ";
        cin>>a;
        searchn(root,n,a);
        if(spare==nullptr){
            cout<<"No such node Exists!"<<endl;
            return;
        }
        if(spare->data==a){
            spare=nullptr;
            return;}
        if(spare->right!=nullptr){
            cout<<"Right Child already Exists!"<<endl;
            spare=nullptr;
            return;
        }
        node *curr=new node(a);
        spare->right=curr;
        spare=nullptr;

    }

    void preOrder(node* root){  //function for recursive preorder traversal
        if(root==nullptr)
            return;
        cout<<root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(node* root){  //post order traversal
        if(root==nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"\t";
    }

    void inOrder(node* root){  //inorder traversal
        if(root==nullptr)
            return;
        inOrder(root->left);
        cout<<root->data<<"\t";
        inOrder(root->right);

    }
    void levelOrder(node *);

};

node* node::spare=nullptr;  //declaring static variable outside the class

void node::levelOrder(node *root){  //function for level order traversal of queue
    if(root==nullptr){  //if tree is empty
        cout<<"Tree's empty!"<<endl;
        return;
    }
    queue<node*>q;  //queue to push and pop elements from
    q.push(root);  //pushing root of tree first
    q.push(nullptr);
    while(q.size()>1){
        node *curr=q.front();
        if(curr==nullptr){
            q.pop();
            cout<<endl;
            q.push(nullptr);
            continue;
        }
        q.pop();
        cout<<curr->data<<"\t";
        if(curr->left!=nullptr)  //if left child is not null
            q.push(curr->left);
        if(curr->right!=nullptr)  //if right child is not null
            q.push(curr->right);
    }
}

int main(){
    node* root=nullptr;
    cout<<"Make selection: "<<endl;
    cout<<"1. Create a new tree"<<endl;
    cout<<"2. Add left child to a node"<<endl;
    cout<<"3. Add right child to a node"<<endl;
    cout<<"4. Display tree in pre-order fashion"<<endl;
    cout<<"5. Display tree in post-order fashion"<<endl;
    cout<<"6. Display tree in in-order fashion"<<endl;
    cout<<"7. Print level-order traversal"<<endl;
    int n;
    while(cin>>n){
        switch(n){
        case 1:
            root=root->create(root);  //assigning created root to root
            break;
        case 2:
            root->leftn(root);  //calling left child insert on tree having root as root
            break;
        case 3:
            root->rightn(root);
            break;
        case 4:
            root->preOrder(root);
            cout<<endl;
            break;

        case 5:
            root->postOrder(root);
            cout<<endl;
            break;

        case 6:
            root->inOrder(root);
            cout<<endl;
            break;
        case 7:
            root->levelOrder(root);
            cout<<endl;
            break;
        }

    }

}
