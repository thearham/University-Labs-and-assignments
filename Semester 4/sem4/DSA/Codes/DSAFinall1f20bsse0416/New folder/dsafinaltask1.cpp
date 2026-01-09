#include<iostream>
using namespace std;

class Studentnode
{
	int rollno;
	string name;
	double CGPA;
	Studentnode*left;
	Studentnode*right;

public:
	Studentnode()
	{
		left = NULL;
		right = NULL;

	}
	void setrollno(int rollno)
	{
		this->rollno = rollno;

	}
	void setname(string name)
	{
		this->name = name;
	}
	void setCGPA(double CGPA)
	{
		this->CGPA = CGPA;
	}
	Studentnode*setleft(Studentnode*left)
	{
		this->left = left;
	}
	Studentnode*setright(Studentnode*right)
	{
		this->right = right;
	}
	int getrollno()
	{
		return rollno;
	}
	string name()
	{
		return name;
	}
	double CGPA()
	{
		return CGPA;
	}
	Studentnode*getleft()
	{
		return left;
	}
	Studentnode*getright()
	{
		return right;
	}

};
class StudentBST
{
	Studentnode*root;
public:

	StudentBST()
	{
		root = NULL;
	}
	void printroot(int r)
	{
		if (r->getright == NULL)
		{
			cout << r->getdata << endl;
			return root;
		}
		else
		{
			cout << root->getdata << endl;
			printrr->getright;
		}
	}

};
void BST<T>::insert(node<T>*r, node<T>*p, T x)
{
	if (r == 0)
	{
		r = new node<T>(x);
		no_nodes++;
		if (this->root == 0){
			root = r;
		}
		else{
			if (x < p->data){
				p->left = r;
			}
			else{
				p->right = r;
			}
		}
	}
	else{
		if (x >= r->data){
			insert(r->right, r, x);
		}
		else{
			insert(r->left, r, x);
		}
	}
}
template<class T>
bool BST<T>::search(node<T>*r, T x)const
{
	if (r == 0){
		return false;
	}
	else{
		if (x == r->data){
			return true;
		}
		else if (x > r->data){
			return search(r->right, x);
		}
		else{
			return search(r->left, x);
		}
	}
}
int main()
{
	StudentBST t;
	t.insert a new student;
	t.Search for a student;
	t.See the list of Student;
	t.Quit;

	count << enter your choice << endl;

	system("pause");
		return 0;
	
}














