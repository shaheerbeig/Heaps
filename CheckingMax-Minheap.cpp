#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

template  <class T>
//this node class is for queue
class NodeQueue{
    public:
    T data;
    NodeQueue<T> *next;

    NodeQueue(T data){
        this->data = data;
        next = NULL;
    }
};

template <class T>
class Queue{
	public:
		NodeQueue<T> *rear;
		NodeQueue<T> *front;
		
	Queue(){
		rear = NULL;
		front = NULL;
	}
	
	//to insert in the queue
	void push(T data){
		NodeQueue<T> *tempnode = new NodeQueue<T>(data);
		
		if(front==NULL){
			front = rear = tempnode;
		}
		else{
			rear->next = tempnode;
			rear = tempnode;
		}
	}
	
	//to remove from the queue
	T pop(){
		if(front==NULL){
			cout<<"Queue is empty: "<<endl;
			return 0;
		}
		else{
			NodeQueue<T> *temp = front;
			front = front->next;
			temp->next = NULL;
			return temp->data;
			delete temp;
		}
	}
	
	//to check if queue is empty
	bool isempty(){
		if(front==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	T peek(){
		if(!isempty()){
			return front->data;
		}
		else{
			cout<<"Empty Queue."<<endl;
		}
	}

};

class Heap{
    public:

    Node* insertioninheap(Node* root) {
        Queue<Node*> q;
        int data, rightdata, leftdata;
        cout << "Enter the root data: ";
        cin >> data;
        root = new Node(data);
        q.push(root);

        while (!q.isempty()) {
            Node* temp = q.peek();
            q.pop();

            if (temp->left == NULL) {
                cout << "Enter data for the left node " << temp->data << endl;
                cin >> leftdata;
                if (leftdata != -1) {
                    temp->left = new Node(leftdata);
                    temp->left->parent = temp;
                    q.push(temp->left);
                }
            }

            if (temp->right == NULL) {
                cout << "Enter data for the right node " << temp->data << endl;
                cin >> rightdata;
                if (rightdata != -1) {
                    temp->right = new Node(rightdata);
                    temp->right->parent = temp;
                    q.push(temp->right);
                }
            }
        }
        return root;
    }

    void maxheapify(Node* root) {
        if(root->parent != NULL && root->parent->data < root->data){
            swap(root->parent->data,root->data);
            maxheapify(root->parent);
        }
    }

    void minheapify(Node *root){
        if(root->parent != NULL && root->parent->data > root->data){
            swap(root->parent->data,root->data);
            minheapify(root->parent);
        }
    }

    void orderleveltraversalprint(Node* root) {
        Queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while (!q.isempty()) {
            Node* temp = q.peek();
            q.pop();

            if (temp == NULL) {
                cout << endl;
                if (!q.isempty()) {
                    q.push(NULL);
                }
            }
            else {
                cout << temp->data << " ";
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
    }

    bool checkmaxheap(Node *root){

        //checking for max heap
        Queue<Node*>q;
        q.push(root);
        while(!q.isempty()){
            Node *temp = q.peek();
            q.pop();
            if(temp->left !=NULL){
                if(temp->left->data > temp->data){
                    return false;
                    break;
                }
                q.push(temp->left);
            }

            if(temp->right != NULL){
                if(temp->right->data > temp->data){
                    return false;
                    break;
                }
                q.push(temp->right);
            }
        }
        return true;
    }

    bool checkminheap(Node *root){
        //checking for min heap
        Queue<Node*>q;
        q.push(root);
        while(!q.isempty()){
            Node *temp = q.peek();
            q.pop();
            if(temp->left !=NULL){
                if(temp->left->data < temp->data){
                    return false;
                    break;
                }
                q.push(temp->left);
            }

            if(temp->right != NULL){
                if(temp->right->data < temp->data){
                    return false;
                    break;
                }
                q.push(temp->right);
            }
        }
        return true;
    }

};

int main(){
    Heap h;
    Node *root = NULL;
    root = h.insertioninheap(root);
    h.orderleveltraversalprint(root);
    if(h.checkmaxheap(root)==true){
        cout<<"The tree is a max heap";
    }
    else if(h.checkmaxheap(root) != true){
        if(h.checkminheap(root)){
            cout<<"the tree is min heap";
        }
        else{
            cout<<"Neither max nor min heap";
        }
    }
}
