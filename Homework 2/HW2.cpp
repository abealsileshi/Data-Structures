#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include <iomanip>

struct wordRecord{
    string word;
    int count;
};

bool isIgnoreWord(string word, string ignoreWords[])
{
    for(int i=0; i < 50; i++){
        if(ignoreWords[i] == word){
            return true;
        }
        
    }
    return false;
    //function returns whether word is in the ignoreWords array
}

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{
       ifstream in_file;
       in_file.open(ignoreWordFileName);
       string line;
       int i = 0;
       while(getline(in_file, line)){
           ignoreWords[i] = line;
           i++;

       }
         
}



int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
//counts distinctive words
    int total = 0;
    int x = 0;
    for(int i = 0; i < length; i++)
    {
        x = distinctWords[i].count;
        total+=x;
    }
    return total;   

}

void sortArray(wordRecord distinctWords[], int length)
{
//sort the most frequently used words
  wordRecord temp;
   for(int i=0;i<length;i++)
	{		
		for(int j=i+1;j<length;j++)
		{
			if(distinctWords[i].count <distinctWords[j].count)
			{
			temp = distinctWords[i];
            distinctWords[i] = distinctWords[j];
            distinctWords[j] = temp;

			}
		}
	}
            
            
      
}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords) {
    for (int q = N; q < N+10; q++) {
        cout << fixed << setprecision(5) <<  (float) distinctWords[q].count / totalNumWords << " - " << distinctWords[q].word
             << endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    }

    string ignoreWords[50];
    wordRecord *distinctWords;
    int capacity = 100;
    distinctWords = new wordRecord[capacity];
    int numDoubles = 0;
    int numRead = 0;
    
    string filename = argv[3];
	ifstream wordFile;
	wordFile.open(filename.c_str());

    getIgnoreWords(argv[2], ignoreWords);
    
    while(!wordFile.eof()){
        int flag = 0; //to flag if words have already been read
        string currentWord;

        wordFile >> currentWord;
        if(!isIgnoreWord(currentWord, ignoreWords)){
            for(int i =0; i < numRead; i++){
                if(currentWord == distinctWords[i].word)
                {
                    distinctWords[i].count +=1;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                if(numRead == capacity)
                {
                    wordRecord *temp = new wordRecord[capacity*2];
                    for(int i = 0; i < capacity; i++){
                        temp[i] = distinctWords[i];
                    }
                    delete distinctWords;
                    distinctWords = temp;
                    numDoubles++;
                }
                distinctWords[numRead].word = currentWord;
                distinctWords[numRead].count = 1;
                numRead++;
            }
        }
    }
    int numWords = getTotalNumberNonIgnoreWords(distinctWords, numRead);
cout << "Whole Program Executed";

std :: cout << "Array Doubled: " << numDoubles << std::endl;

    std :: cout << "#" << std:: endl;

    std :: cout << "Unique non-common words: " << numRead << std :: endl;

    std :: cout << "#" << std:: endl;

    std :: cout << "Total non-common words: "

    << numWords << std :: endl;

    std :: cout << "#" << std:: endl;

    std::cout << "Probabilities of top "

    << stoi(argv[2])

    << " most frequent words" << std::endl;

    std :: cout << "----------------------------------------" << std :: endl;

   

    sortArray(distinctWords, numRead);

    printTenFromN(distinctWords, stoi(argv[2]), numWords);

    return 0;
	

}