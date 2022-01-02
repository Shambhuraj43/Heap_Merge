/*
	Shambhuraj Wadghule
	Data Strutures
	Assignment Heap Merge
*/


#include<iostream>
#include<cassert>
#include<cstdlib>

using namespace std;


//Heap class
class Heap
{
public:
	//properties of a heap
	int key;
	Heap* left = NULL;
	Heap* right = NULL;

	//Constructor
	Heap()
	{
		key = 0;
		right = NULL;
		left = NULL;
	}



	/***** Funtion to merge two heaps *****/
	// Compare two heaps' keys and merge them recursively //
	Heap* mergeHeaps(Heap* root1, Heap* root2)
	{
		Heap* temp;

		if (root1 == NULL)
		{
			return root2;
		}
		else if (root2 == NULL)
		{
			return root1;
		}
		else
		{
			if (root1->key < root2->key)
			{
				//swapping roots by stiring one in a temp variable
				temp = root1;
				root1 = root2;
				root2 = temp;
			}

			//merging recursively 
			temp = root1->left;
			root1->left = root1->right;
			root1->right = temp;
			root1->left = mergeHeaps(root2, root1->left);
		}
		//return the new root
		return root1;
	}

	/***** Funtion to Traverse th Heap using preorder traversal *****/
	// Print the keys on the console by using preorder traversal //
	void preorderTraversal(Heap* root)
	{


		if (root == NULL)
		{
			return;
		}
		else
		{
			cout << root->key << " ,";
			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		//cout << root->key << endl;
		return;
	}

	/***** Funtion to create the heap *****/
	// Create the heap from the array of the keys //
	// Merge the consecutive key by using the merge method //
	Heap* createHeap(Heap* root, int numKeys, int keys[]) {

		Heap* temp;

		for (int i = 0; i < numKeys; i++) {
			temp = new Heap;
			temp->key = keys[i];

			//merging the root and the new heap element that 
			//is created by using the key from the array of keys
			root = mergeHeaps(root, temp);
		}
		return root;
	}

};



int main() {

	//Heap keys sored in the array from the course slides 
	int heap1Array[] = { 43, 27,19,20, 4, 15, 12, 25, 8 };
	int heap2Array[] = { 14, 8, 6, 7 };

	Heap* root = NULL;
	Heap* heap1 = NULL;
	Heap* heap2 = NULL;
	Heap* temp = NULL;

	//Create the two heaps using the array of keys
	heap1 = root->createHeap(heap1, 9, heap1Array);
	heap2 = root->createHeap(heap2, 4, heap2Array);

	//print heaps
	cout << endl << "Heap 1 " << endl;
	heap1->preorderTraversal(heap1);

	cout << endl << "Heap 2 " << endl;
	heap2->preorderTraversal(heap2);

	//Merge Heap1 and Heap2
	heap1 = temp->mergeHeaps(heap1, heap2);

	//Print merged Heaps
	cout << endl << "After merging " << endl;
	heap1->preorderTraversal(heap1);
	cout << endl;

	//system("pause");
	return 0;
}


