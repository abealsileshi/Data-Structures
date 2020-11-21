#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include <cmath>


using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
  this->root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
  //if (node == NULL) return;

    //deleteTree(node->left);
    //deleteTree(node->right);

    /* TODO then delete the node */
    //cout<<"\n Deleting node:"<< node->data;
    //delete node;
}

void printMovieInventoryHelper(MovieNode * curr){ //helper function to print movie inventory
  if(curr != NULL){
    printMovieInventoryHelper(curr->left);
    cout << "Movie: " << curr->title << " " << curr->rating << endl;
    printMovieInventoryHelper(curr->right);
  }
}

void MovieTree::printMovieInventory(){
   MovieNode * curr = root;
   if(root == NULL){
     cout << "Tree is Empty. Cannot print" << endl;
     return;
   }
   else{
     printMovieInventoryHelper(curr);
   }
}

//add a helper function, that returns a movieNode pointer
//call the function from the addMovieNode function

MovieNode * addMovieHelper(MovieNode * root, int ranking, string title, int year, float rating){ 
 MovieNode * temp = getMovieNode(ranking, title, year, rating);  
  
  if(root == NULL){
    root = getMovieNode(ranking, title, year, rating);
  }
  else if(temp->title.compare(root->title) < 0){ //if less than zero, temp->title starts with a letter that is before root->title
    root->left = addMovieHelper(root->left, ranking, title, year, rating);
  }
  else if(temp->title.compare(root->title) > 0){ //if greater than zero, temp->title starts with a letter that is after root->title
    root->right = addMovieHelper(root->right,ranking, title, year, rating); 
  }
  return root;
}


void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
  root = addMovieHelper(root, ranking, title, year, rating);
}


bool global; //this variable helps findMovieHelper & findMovie know if we found the title or not

MovieNode * findMovieHelper(MovieNode * root, string title){ 
  if(root == NULL){ //base case
    return NULL;
  }
  if(root->title == title){ 
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << root->ranking << endl;
    cout << "Title  :" << root->title << endl;
    cout << "Year   :" << root->year << endl;
    cout << "rating :" << root->rating << endl;
    global = true;
    return root;
  }
  root->left = findMovieHelper(root->left, title);
  root->right = findMovieHelper(root->right, title);
  return root;
}


void MovieTree::findMovie(string title){
  root = findMovieHelper(root, title);
  if (global== false){
    cout << "Movie not found." << endl;
  }
}  


MovieNode * queryMoviesHelper(MovieNode * root, float rating, int year){
  if (root!= NULL)
  {
    if(root->rating >= rating && root->year > year){
      cout << root->title  << "(" << root->year << ") " << root->rating << endl;
    }
    root->left = queryMoviesHelper(root->left, rating, year);
    root->right = queryMoviesHelper(root->right, rating, year);
  }
  return root;
}

void MovieTree::queryMovies(float rating, int year) {
  cout << "Movies that came out after " << year << " with rating at least " << rating << ": "  << endl;
  root = queryMoviesHelper(root, rating, year);
}

void averageRatingHelper(MovieNode *& curr, float &avg, float &counter, float &number){ //inorder re-implemented
  if(curr != NULL){
    averageRatingHelper(curr->left, avg, counter, number);
    number += curr->rating;
    counter++;
    averageRatingHelper(curr->right, avg, counter, number);
  }
}

void MovieTree::averageRating(){
  MovieNode * temp = root;
  float avg = 0;
  float number = 0; 
  float counter = 0;
  averageRatingHelper(temp, avg, counter, number);
  if(counter > 0){
      avg = number/counter;
      cout << "Average rating:" << avg << endl;
  }
  else {
      cout << "Average rating:0.0" << endl;
  }
}

//we need to have a level-1 parameter, and decrement it until it gets to zero
void printLevelNodesHelper(MovieNode * curr, int level){ //helper function to print movie inventory
  if(curr != NULL){
    printLevelNodesHelper(curr->left, level-1);
    if(level == 0){
      cout << "Movie: " << curr->title << " " << curr->rating << endl;
    } 
    printLevelNodesHelper(curr->right, level-1);
  }
}

void MovieTree::printLevelNodes(int k){
   MovieNode * curr = root;
   if(root == NULL){
     return;
   }
   else if(k == 0){
     cout << "Movie: " << curr->title << " " << curr->rating << endl;
   }
   else{
     printLevelNodesHelper(curr, k);
   }
}

TreeNode * insertMovieHelper(TreeNode *& root, TreeNode * node, int ranking, string title, int year, float rating, ){
	if(root == NULL){
		root = node;
		//If this charNode doesn't have any LL nodes, we'll create some
		root->head = getLLMovieNode(ranking, title, year, rating);
	}
	else if(node->titleChar < root->titleChar){ //if less than zero, temp->title starts with a letter that is before root->title	
		root->leftChild = insertMovieHelper(root->leftChild, node, ranking, title, year, rating);
		if(root->leftChild != NULL){
			root->leftChild->parent = root;
		}
		 
  	}
    else if(node->titleChar > root->titleChar){ //if greater than zero, temp->title starts with a letter that is after root->title
    	root->rightChild = insertMovieHelper(root->rightChild, node, ranking, title, year, rating); 
		if(root->rightChild != NULL){
			root->rightChild->parent = root;
		} 
    }
	//else if condition when the tree node exists and it's equal to the root
	else if(node->titleChar == root->titleChar){ 
		//insert the LL
			LLMovieNode * temp = root->head;
			LLMovieNode * toBeInserted = getLLMovieNode(ranking, title, year, rating);
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
		root = insertMovieHelper(root, charNode, ranking, title, year, rating);
	}
	else{

	}
	// TreeNode * newNode = new TreeNode;
	// root = insertMovieHelper(root, TreeNode * newNode, ranking, title, year, rating);
}
