#include <iostream>
#include <string>

using namespace std;

int​ ​main​ ( ​int​ argc, ​char​ c​onst​ *argv[]) {
    ​cout​ << ​"Number of arguments: "​ ;
    ​cout​ << argc << ​endl​;
    ​cout​ << ​"Program arguments: "​ << ​endl​; 
    ​for​ ( ​int​ i= ​0​ ;i<argc;i++){
        ​cout​ << ​"Argument #"​ << i << "​ : "​ ;
        ​cout​ << argv[i] << ​​endl​ ; 
        }
}