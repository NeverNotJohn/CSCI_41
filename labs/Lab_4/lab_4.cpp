#include <iostream>
#include <string>

using namespace std;

class movie {

    public:

    // CONSTRUCTOR AND DEFAULT CONSTRUCTOR

    movie(int w, string x, string y) {
        year = w;
        title = x;
        genre = y;
    }

    movie() {
        year = 0;
        title = "Empty";
        genre = "";
    }



    // GETTER FUNCTIONS

    string get_title() {
        return title;
    }

    int get_year() {
        return year;
    }

    string get_genre() {
        return genre;
    }

    // SETTER FUNCTIONS

    void set_title(string x) {
        title = x;
    }

    void set_year(int x) {
        year = x;
    }

    void set_genre(string x) {
        genre = x;
    }

    // ADD AND DELETE MOVIES    

    void add_movie(movie array[], int &size, movie movie) {
        array[size] = movie;
        size++;
    }

    void delete_movie(movie array[], int &size, movie movie) {

        int index;

        // find array element tryna be deleted
        for(int i = 0; i < size; i++) {
            if (array[i].get_title() == movie.get_title()) {
                index = i;
            }
        }

        // copy next element left
        for (int i = index; i < size-1; i++) {
            array[i] = array[i + 1];
        }

        size--;
    }

    // SEARCH FUNCTIONS

    void search_event(movie movies[], int &size, string event, string input) {

        if (event == "title") {
            cout << "Movies with " << input << " as a title: " << endl;
            for (int i = 0; i < size; i++) {

                if (movies[i].title == input) {
                    cout << movies[i].get_title() << ", ";
                }
            }
        }

        else if (event == "year") {
            cout << "Movies made in the year " << input << ": " << endl;

            for (int i = 0; i < size; i++) {

                auto temp = to_string(movies[i].get_year());    // .year in int... need str comparison
                
                if (temp == input) {
                    cout << movies[i].get_title() << ", ";
                }
            }
        }

        else if (event == "genre") {
            cout << input << " movies: " << endl;

            for (int i = 0; i < size; i++) {
                
                if (movies[i].get_genre() == input) {
                    cout << movies[i].get_title() << ", ";
                }
            }
        }

        cout << endl << endl;        
    }    

    // INSERTION AND DELETION

    void insert(movie array[], int &size, movie movie, int index) {

        for (int i = size - 1; i >= index; i--) { // shift right
            array[i + 1] = array[i];
        }
        array[index] = movie;
        size++;
    }

    void del(movie array[], int &size, int index) {
        
        for (int i = index + 1; i < size; i++) { // shift left
            array[i - 1] = array[i];
        }

        size--;

    }


    void sort_year(movie movies[], int &size) {
        movie temp[1000];

        for (int i = 0; i < size; i++) { // copies og movies to temp movies... for convenience
            temp[i] = movies[i];        
        }

        for (int i = 0; i < size - 1; i++) { // comparison time!
            movie og = temp[i+1];
            movie point = movies[i];

            if (og.get_year() >= point.get_year()) {
                append(movies, i+1, og);
            }

            else {
                appbegin(movies, size, og);
            }
        }
    }

    void sort_title(movie movies[], int &size) {
        movie temp[1000];

        for (int i = 0; i < size; i++) {
            temp[i] = movies[i];
        }

        for (int i = 0; i < size - 1; i++) {
            movie og = temp[i+1];
            movie point = movies[i];

            if (og.get_title() >= point.get_title()) {
                append(movies, i+1, og);
            }

            else {
                appbegin(movies, size, og);
            }
        }
    }

    void sort_genre(movie movies[], int &size) {
        movie temp[1000];

        for (int i = 0; i < size; i++) {
            temp[i] = movies[i];
        }

        for (int i = 0; i < size - 1; i++) {
            movie og = temp[i+1];
            movie point = movies[i];

            if (og.get_genre() >= point.get_genre()) {
                append(movies, i+1, og);
            }

            else {
                appbegin(movies, size, og);
            }
        }
    }

    // OTHER STUFF

    void display(movie movies[], int movies_size) {
        for (int i = 0; i < movies_size; i++) {
            cout << movies[i].get_title() << endl;
        }
    }

    void append(movie array[], int index, movie movie) {
        array[index] = movie;
    }

    void appbegin(movie array[], int &size, movie movie) {

        for (int i = size - 1; i > -1; i--) { // shift right
            array[i + 1] = array[i];
        }
        array[0] = movie;
    }

    ~movie(){}

    private:

    // DATA
    int year;
    string title = "";
    string genre = "";

};




int main() {

    movie lalaLand(2019, "Lala Land", "romance");
    movie topGun(2019, "Top Gun", "action");
    movie onePiece(1999, "One Piece", "anime");
    movie aot(1776, "Attack on Titan", "anime");
    movie the_bible(0, "The Bible", "comedy");
    int movies_size = 5;

    movie movies[1000] = {lalaLand, topGun, onePiece, aot, the_bible}; // MAX 1000 MOVIES... allocates memory for array

    // add and delete movies

    movie plutoNash(-1926, "Pluto Nash 3D", "anime");

    cout << "add_movie: " << endl;
    plutoNash.add_movie(movies, movies_size, plutoNash);
    lalaLand.display(movies, movies_size);
    cout << endl;

    cout << "delete_movie: " << endl;
    aot.delete_movie(movies, movies_size, aot);
    lalaLand.display(movies, movies_size);

    cout << endl << endl << endl;

    // SORT

    cout << "sort_year: " << endl;
    aot.sort_year(movies, movies_size);
    aot.display(movies, movies_size);

    cout << endl;

    cout << "sort_title: " << endl;
    aot.sort_title(movies, movies_size);
    aot.display(movies, movies_size);

    cout << endl;

    cout << "sort_genre: " << endl;
    aot.sort_genre(movies, movies_size);
    aot.display(movies, movies_size);

    cout << endl << endl << endl;

    // SEARCH

    lalaLand.search_event(movies, movies_size, "title", "The Bible");
    the_bible.search_event(movies, movies_size, "year", "2019");
    topGun.search_event(movies, movies_size, "genre", "anime");

    cout << endl << endl << endl;

    // INSERTION and DELETION

    cout << "Insert: " << endl;
    topGun.insert(movies, movies_size, the_bible, 3);
    lalaLand.display(movies, movies_size);

    cout << endl;

    cout << "Pop: " << endl;
    topGun.del(movies, movies_size, movies_size);
    lalaLand.display(movies, movies_size);
    cout << endl << endl << endl;

    // SETTER AND GETTER
    
    cout << "Set and Get title: " << endl;
    cout << "Before: " << lalaLand.get_title() << endl;
    lalaLand.set_title("Not Lala Land");
    cout << "After: " << lalaLand.get_title() << endl << endl;

    cout << "Set and Get year: " << endl;
    cout << "Before: " << lalaLand.get_year() << endl;
    lalaLand.set_year(9999);
    cout << "After: " << lalaLand.get_year() << endl << endl;

    cout << "Set and Get genre: " << endl;
    cout << "Before: " << lalaLand.get_genre() << endl;
    lalaLand.set_genre("NOT ROMANCE");
    cout << "After: " << lalaLand.get_genre() << endl << endl;

}