#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}
/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}
/* ------------------------------------------------------ */

void LLhelper(TreeNode *& root, string title);

void DestroyNode(TreeNode * ptr){
	if(ptr){
		DestroyNode(ptr->leftChild);
		DestroyNode(ptr->rightChild);

		LLhelper(ptr, ptr->head->title);
		delete ptr;
		ptr = NULL;
		}
}


MovieTree:: ~MovieTree(){
	DestroyNode(root);
}

void _grader_inorderTraversal(TreeNode * root){
		if (root == NULL) {
			return;
		}
		_grader_inorderTraversal(root->leftChild);
		cout << root->titleChar << " ";
		_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}


void showMovieCollectionHelper(TreeNode * root){
	
	if(root == NULL){
		return;
	}
	showMovieCollectionHelper(root->leftChild);
	cout << "Movies starting with letter: " << root->titleChar << endl;
	if(root->head){
		LLMovieNode * temp = root->head;
		while(temp){
			cout << " >> " << temp->title << " " << temp->rating << endl;
			temp = temp->next;
		}
	}
	showMovieCollectionHelper(root->rightChild);
}

void MovieTree:: showMovieCollection(){
	showMovieCollectionHelper(root);
}

TreeNode * insertMovieHelper(TreeNode *& root, TreeNode * node, LLMovieNode * movie){
	if(root == NULL){
		root = node;
		//If this charNode doesn't have any LL nodes, we'll create some
		root->head = movie;
	}
	else if(node->titleChar < root->titleChar){ //if less than zero, temp->title starts with a letter that is before root->title	
		root->leftChild = insertMovieHelper(root->leftChild, node, movie);
		if(root->leftChild != NULL){
			root->leftChild->parent = root;
		}		 
  	}
    else if(node->titleChar > root->titleChar){ //if greater than zero, temp->title starts with a letter that is after root->title
    	root->rightChild = insertMovieHelper(root->rightChild, node, movie); 
		if(root->rightChild != NULL){
			root->rightChild->parent = root;
		} 
    }
	//else if condition when the tree node exists and it's equal to the root
	else if(node->titleChar == root->titleChar){ 
		//insert the LL
			LLMovieNode * temp = root->head;
			LLMovieNode * toBeInserted = movie;
			LLMovieNode * prev = NULL; //have a previous pointer
			while(temp!= NULL && toBeInserted->title > temp->title){
					prev = temp;
					temp = temp->next;
			}
			toBeInserted->next = temp; //case where we have to go in between nodes
			if(prev){
				prev->next = toBeInserted;
			}
			else{
				root->head = toBeInserted;
			}

    }
	return root;
}

void MovieTree:: insertMovie(int ranking, std::string title, int year, float rating){
	
	LLMovieNode * movie = getLLMovieNode(ranking, title, year, rating); 
	TreeNode * node = searchCharNode(title[0]);
	if(node == NULL){
		TreeNode * charNode = new TreeNode; //creating a dynamic node with the character if one doesn't already exist
		charNode->titleChar = title[0];
		root = insertMovieHelper(root, charNode, movie);
	}
	else{
		root = insertMovieHelper(root, node, movie);
	}
}

TreeNode * getMaxValueNode(TreeNode * currNode){
    if(currNode->rightChild == NULL){
        return currNode;
    }
    return getMaxValueNode(currNode->rightChild);
}
TreeNode * getMinValueNode(TreeNode * currNode){
    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}

void LLhelper(TreeNode *& root, string title){
			LLMovieNode * curr = root->head;
			LLMovieNode * prev = NULL;
			LLMovieNode * forw = NULL;
			while(curr && curr->title != title){
				prev = curr;
				curr = curr->next;
			}
      if(curr==NULL)
      {
        return;
      }
      forw = curr->next;
      
     if(curr == root->head){
        root->head = forw;
      }
      else{
        prev->next = forw;
      }
      delete curr;
      return;	
}

TreeNode * removeMovieRecordHelper(TreeNode * root, TreeNode * node, string title){
	if(root == NULL){
		return NULL;
	}
	else if(node->titleChar < root->titleChar)
    {
		  root->leftChild = removeMovieRecordHelper(root->leftChild, node, title);
      
    }
   else if(node->titleChar > root->titleChar)
    {
		root->rightChild = removeMovieRecordHelper(root->rightChild, node, title);
    }
	else{
				//cout << "Made it here (1) " << endl;
				if(root->leftChild == NULL && root->rightChild == NULL){
					//cout << "Leaf node (1)" << endl;
					delete root;
					root = NULL;
				}
				else if(root->leftChild == NULL){
					//cout << "leftChild NULL" << endl;
 					TreeNode * temp = root; 
        			root = root->rightChild;
              		root->parent = temp->parent;//Chnage
        			delete temp;
				}
				else if(root->rightChild == NULL){
					//cout << "rightChild NULL" << endl;
 					TreeNode * temp = root; 
        			root = root->leftChild;
              		root->parent = temp->parent;//Chnage
        			delete temp;
				}
				else{
					//cout << "leftChild and rightChild exist" << endl;
					 ///Replace with Minimum from right subtree
			      	TreeNode * temp = getMinValueNode(root->rightChild);
      				root->titleChar = temp->titleChar;
             		root->head = temp->head; //Chnage
              		temp->head = NULL;//Chnage
      				root->rightChild = removeMovieRecordHelper(root->rightChild, temp, title); 
				}		
	}
	return root;
}


void MovieTree:: removeMovieRecord(string title){
	TreeNode * finder = searchCharNode(title[0]); //this finds the tree node if it exists
	if(finder == NULL){
		cout << "Movie not found." << endl;
		return;
	}
	LLhelper(finder, title);
	if(finder->head == NULL){
		//cout << "Made it" << endl;
		root = removeMovieRecordHelper(root, finder, title);
	}
}


void MovieTree:: leftRotation(TreeNode *curr){
	TreeNode * y = curr->rightChild;
	curr->rightChild = y->leftChild;
	if(y->leftChild != NULL){
		y->leftChild->parent = curr;
	}
	y->parent = curr->parent;
	if(curr->parent == NULL){
		root = y;
	}
	else{
		if(curr == curr->parent->leftChild){
			curr->parent->leftChild = y;
		}
		else{
			curr->parent->rightChild = y;
		}
	}
	y->leftChild = curr;
	curr->parent = y;	
}
//make a recursive helper function 
//that deletes node from LL
// then check after deletion if the LL is empty, delete the treenode 
//1)find the tree node, then delete

//TreeNode * removeMovieRecordHelper(TreeNode *& root, TreeNode * node, string title){
// 	if(node == NULL){
// 		return NULL;
// 	}
// 	else if(node->titleChar < root->titleChar)
//     {
// 		root->leftChild = removeMovieRecordHelper(root->leftChild, node, title);
//     }
//    else if(node->titleChar > root->titleChar)
//     {
// 		root->rightChild = removeMovieRecordHelper(root->rightChild, node, title);
//     }
// 	else{
// 			LLMovieNode * curr = root->head;
// 			LLMovieNode * prev = NULL;
// 			LLMovieNode * forw = NULL;
// 			while(curr->title != title){
// 				prev = curr;
// 				curr = curr->next;
// 			}
// 			 cout << "This is the movie we found " << curr->title << endl;
			
// 			// if (prev){
// 			// 	cout << "This is the (prev) movie we found " << prev->title << endl;
// 			// }
// 			if(curr->next){
// 				forw = curr->next;
// 				//cout << "This is the (forw) movie we found " << forw->title << endl;
// 			}
// 			if(prev == NULL){ //the case where we only have one movie
// 				//cout << "Made it here (1) " << endl;
// 				if(root->leftChild == NULL && root->rightChild == NULL){
// 					//cout << "Leaf node (1)" << endl;
					
// 					root->parent->leftChild = NULL //how to know if the deleted leaf node is left/rightChild?
// 					root->parent->rightChild = NULL
// 					delete curr;
// 					curr = NULL;
// 					delete root;
// 					root = NULL;
					
// 				}
// 				else if(root->leftChild == NULL){
// 					//cout << "leftChild NULL" << endl;
// 					TreeNode * temp = root;
// 					root = root->rightChild;
// 					root->parent = temp->parent;
// 					delete curr;
// 					delete temp; 
// 				}
// 				else if(root->rightChild == NULL){
// 					//cout << "rightChild NULL" << endl;
// 					TreeNode * temp = root;
// 					root = root->leftChild;
// 					root->parent = temp->parent;
// 					delete curr;
// 					delete temp;
// 				}
// 				else{
// 					//cout << "leftChild and rightChild exist" << endl;
// 					 ///Replace with Minimum from right subtree
// 					TreeNode * temp = getMinValueNode(root->rightChild);
// 					//if statement minvalnode has children to account for the case if it has children
// 					if(temp->rightChild){
// 						TreeNode * connector = temp->parent;
// 						connector->rightChild = temp->rightChild;
						
// 					}
// 					//cout << "The temp's titleChar is: " << temp->titleChar << endl;
// 					root->titleChar = temp->titleChar;
// 					root->parent = temp->parent;
// 					//need to copy all of the LL too
// 					delete temp;
// 				}
// 			}
// 			else{
// 				//cout << "testing....." << endl; 
// 				//prev is not equal to null
// 				//there is more than one movie in the LL
// 				if(forw){
// 					//cout << "testing....." << endl;
// 					prev->next = forw;
// 					delete curr;
// 				}
// 				else{
// 					delete curr;
// 					prev->next = NULL;
// 				}
				
// 			}
// 	}
// 	return root;
// }


// void MovieTree:: removeMovieRecord(string title){
// 	TreeNode * finder = searchCharNode(title[0]); //this finds the tree node if it exists
// 	root = removeMovieRecordHelper(root, finder, title);
// 	if(root == NULL){
// 		cout << "Movie not found." << endl;
// 		return;
// 	}

// }


//SECOND DRAFT
// TreeNode * getMinValueNode(TreeNode * currNode){

//     if(currNode->leftChild == NULL){
//       return currNode;
//     }
//     return getMinValueNode(currNode->leftChild);
// }

// void LLhelper(TreeNode *& root, string title){
// 			LLMovieNode * curr = root->head;
// 			LLMovieNode * prev = NULL;
// 			LLMovieNode * forw = NULL;
// 			while(curr->title != title){
// 				prev = curr;
// 				curr = curr->next;
// 				if(curr == NULL){
// 					return;
// 				}
// 			}
// 			//if root head title is equal to the title
// 			if(root->head->title == title){
// 				root->head =root->head->next;
// 				delete curr;
// 				return;
// 			}
// 			cout << "This is the movie we found: " << curr->title << endl;
			
// 			// if (prev){
// 			// 	cout << "This is the (prev) movie we found " << prev->title << endl;
// 			// }
// 			if(curr->next){
// 				forw = curr->next;
// 				//cout << "This is the (forw) movie we found " << forw->title << endl;
// 			}
			
// 			//cout << "testing....." << endl;
// 			prev->next = forw;
// 			delete curr;
			
				
// 			// else{
// 			// 	cout << "HERE" << endl;
// 			// 		delete curr;
// 			// 		curr = NULL;
// 			// 	}
// }

// TreeNode * removeMovieRecordHelper(TreeNode *& root, TreeNode * node, string title){
// 	if(node == NULL){
// 		return NULL;
// 	}
// 	else if(node->titleChar < root->titleChar)
//     {
// 		root->leftChild = removeMovieRecordHelper(root->leftChild, node, title);
//     }
//    else if(node->titleChar > root->titleChar)
//     {
// 		root->rightChild = removeMovieRecordHelper(root->rightChild, node, title);
//     }
// 	else{
			
// 				//cout << "Made it here (1) " << endl;
// 				if(root->leftChild == NULL && root->rightChild == NULL){
// 					//cout << "Leaf node (1)" << endl;
// 					delete root;
// 					root = NULL;
// 				}
// 				else if(root->leftChild == NULL){
// 					//cout << "leftChild NULL" << endl;
//  					TreeNode * temp = root; 
//         			root = root->rightChild;
//         			delete temp;
// 				}
// 				else if(root->rightChild == NULL){
// 					//cout << "rightChild NULL" << endl;
//  					TreeNode * temp = root; 
//         			root = root->leftChild;
//         			delete temp;
// 				}
// 				else{
// 					//cout << "leftChild and rightChild exist" << endl;
// 					 ///Replace with Minimum from right subtree
// 			      	TreeNode * temp = getMinValueNode(root->rightChild);
//       				root->titleChar = temp->titleChar;
// 					root->head = temp->head;
//       				root->rightChild = removeMovieRecordHelper(root->rightChild, temp, title); 
// 				}		
// 	}
// 	return root;
// }


// void MovieTree:: removeMovieRecord(string title){
// 	TreeNode * finder = searchCharNode(title[0]); //this finds the tree node if it exists
// 	if(finder == NULL){
// 		cout << "Movie not found." << endl;
// 		return;
// 	}
// 	LLhelper(finder, title);
// 	if(finder->head == NULL){
// 		//cout << "Made it" << endl;
// 		root = removeMovieRecordHelper(root, finder, title);
// 	}
// }