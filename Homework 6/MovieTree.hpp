#include <string>

using namespace std;

struct MovieNode{
    int ranking;
    string title;
    int year;
    float rating;

    MovieNode* left = NULL;
    MovieNode* right = NULL;

};

class MovieTree{
    private:
        MovieNode* root;

    public:
        MovieTree();
        ~MovieTree();
        void printMovieInventory();
        void addMovieNode(int ranking, std::string title, int year, float rating);
        void findMovie(std::string title);
        void queryMovies(float rating, int year);
        void averageRating();
        void printLevelNodes(int k);
};
