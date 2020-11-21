/*
** Name: Abeal Sileshi
** Assighment 1
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct studentData {
   string studentName;
   int homework;
   int recitation;
   int quiz;
   int exam;
   double average;
};

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length){ 
        students[length].studentName = studentName; 
        students[length].homework = homework; 
        students[length].recitation = recitation;
        students[length].quiz = quiz;
        students[length].exam = exam;
        students[length].average = (homework + recitation + quiz + exam)/4.0; //calculating the student average
        
}
char calcLetter(double avg)
{
    char str[]={'A', 'B', 'C', 'D', 'F', '\0'};
    if(avg >= 90){
        return str[0];
        }
        else if(avg >= 80 && avg <90){
            return str[1];
            }
            else if(avg >= 70 && avg <80){
                return str[2];
                } 
                else if(avg >= 60 && avg <70){
                    return str[3];
                    }
                    else
                    {
                        return str[4];
                        }
}

double calcNum(string avg)
{
    if(avg == "A"){
        return 100;
        }
        else if(avg == "B"){
            return 80;
            }
            else if(avg == "C"){
                return 70;
                } 
                else if(avg == "D"){
                    return 60;
                    }
                    else
                    {
                        return 0;
                        }
}


void printList(const studentData students[], int length) 
{
    
    for(int i=0; i < length; i++){
      cout << students[i].studentName << " earned " << students[i].average << " which is an " << calcLetter(students[i].average) << endl;
      

    }
}

int main(int argc, char* argv[]) 
{
    
   studentData students[10];// File of 10 students
   
   int length = 0;
       ifstream in_file;
       string filename = argv[1]; 
       string name; 
       int homework;
       int recitation;
       int quiz;
       int exam;
       
       string line;
       in_file.open(filename);
   while (getline(in_file, line)){ 
       istringstream ss(line);

    getline(ss, name, ',');

    getline(ss, line, ',');
       homework = stoi(line);

         getline(ss, line, ',');

        recitation = stoi(line);
        getline(ss, line, ',');

        quiz = stoi(line);
        getline(ss, line, ',');

        exam = stoi(line);
           
        addStudentData(students, name, homework, recitation, quiz, exam, length);
          length++;   
      }
      in_file.close();
   
   ofstream out_file;
   string output = argv[2];
   out_file.open(output);
   if(argv[3] && argv[4]){
      
      string lower = argv[3];
      string upper = argv[4];

   
       for(int i= 0; i < length; i++){
       if(calcLetter(students[i].average) <= lower[0] && calcLetter(students[i].average) >= upper[0]){ //converting into ASCII and comparing opposite ways
        
        out_file << students[i].studentName << "," << students[i].average << "," << calcLetter(students[i].average) << endl;
       
        
        }
         if(i==length-1){ //we only want printList to print one time
            printList(students, length);
       }

      }
  }
   else {
        cout << "Argv3 and Argv4 have not been detected";
        }
          
   out_file.close();
   return 0;
}