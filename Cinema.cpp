#include <iostream>
#include<string>
#include <memory>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;



class Movie final {
   private:
      string name;
      string genre;
      double rating;
      int views;

    public:
      Movie(string name, string genre, double rating, int views) : name{name}, genre{genre}, rating{rating}, views{views} {}

      string getName() const {
        return name;
      }

      string getGenre() const {
        return genre;
      }

      double getRating() const {
        return rating;
      }

      int getViews() const {
        return views;
      }

      void showInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Genre: " << genre << "\n";
        cout << "Rating: " << rating << "\n";
        cout << "Views: " << views << "\n";
        cout << endl;
      }
};



class MovieGenerator final {
    public:
     static vector<unique_ptr<Movie>> getMovies()  {
        auto movieOne {make_unique<Movie>("Barbie", "Comedy", 4.5, 1500000)};
        auto movieTwo {make_unique<Movie>("Interstellar", "Fantasy", 3.0, 4500000)};
        auto movieThree {make_unique<Movie>("Godfather", "Crime", 9.7, 4300000)};
        auto movieFour {make_unique<Movie>("12 Angry Men", "Crime", 4.9, 12000000)};
        auto movieFive {make_unique<Movie>("Kung Fu Panda", "Animation", 5.5, 7332000)};

       

        vector<unique_ptr<Movie>> movies;
        movies.push_back(std::move(movieOne));
        movies.push_back(std::move(movieTwo));
        movies.push_back(std::move(movieThree));
        movies.push_back(std::move(movieFour));
        movies.push_back(std::move(movieFive));

        return movies;
      }
};


class Helper {
    public:
      static void showSortedMoviesByUserPreference(vector<unique_ptr<Movie>>& movies, int userInput) {
         
         switch(userInput) {
            case 1:
              std::sort(movies.begin(), movies.end(), [](const unique_ptr<Movie>& a, const unique_ptr<Movie>& b) {
                      return a->getName() < b->getName();
              });
              Helper::showAllMovies(movies);
              break;

            case 2:
              std::sort(movies.begin(), movies.end(), [](const unique_ptr<Movie>& a, const unique_ptr<Movie>& b) {
                  return a->getGenre() < b->getGenre();
              });
              Helper::showAllMovies(movies);
              break;

            case 3:
              std::sort(movies.begin(), movies.end(), [](const unique_ptr<Movie>& a, const unique_ptr<Movie>& b) {
                return a->getRating() < b->getRating();
              });
              Helper::showAllMovies(movies);
              break;

            case 4:
              std::sort(movies.begin(), movies.end(), [] (const unique_ptr<Movie>& a, const unique_ptr<Movie>& b) {
                  return a->getViews() < b->getViews();
              });
              Helper::showAllMovies(movies);
              break;

              default:
                cout <<"NO valid choice";
              
         }
      }


      static void showAllMovies(const vector<unique_ptr<Movie>>& movies) {
             for(const auto& movie : movies) {
                movie->showInfo();
             }
      }
       

      static int getInput(int inputRange) {
         int userInput = 0;
        
         cout <<"Enter you choice \n"; 
         cin >> userInput;

         while(userInput < 1 || userInput > inputRange) { {
            cout <<"Enter valid number \n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin >> userInput;
         }
           
         }

         return userInput;
      }
};




int main() {
    
    // The programm shows a list of movies.
    // The the user is required to enter an option to see movies sorted by differnet options.
    // Options are provided.
    
     vector<unique_ptr<Movie>>movies = MovieGenerator::getMovies();
     cout << "\t\t\t Befor sorting" << endl;
     Helper::showAllMovies(movies);

     cout <<"Enter the options you want \n";
     cout << "By name: press 1 \n";
     cout << "By genre: press 2 \n";
     cout << "By rating: press 3 \n";
     cout << "By views: press 4 \n";
     int userInput = Helper::getInput(4);
     cout << "\t\t\t After Sorting" <<endl;
     Helper::showSortedMoviesByUserPreference(movies,userInput);

     

     
    

    return 0;
}
