#ifndef ALBUM_H_
#define ALBUM_H_

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class Album {
private:
    string title;
    string artist;
    string genre;
    //vector<char> songName;
    unsigned year;
    double price;

public:

    /**Constructors*/
    Album();



    /**Manipulation Procedures*/
    void set_title(string t);

    void set_artist(string a);

    void set_genre(string g);

    //void set_songName(vector<char> s);

    void set_year(unsigned y);

    void set_price(double p);

    /**Access Functions*/
    string get_title() const;
    //returns title of the album

    string get_artist() const;
    //returns name of the artist

    string get_genre() const;
    //returns genre of the album

    //vector<char> get_songName() const;

    unsigned get_year() const;
    //returns release year of the album

    double get_price() const;
    //returns price of the album

    /**Additional Functions*/
    bool operator==(const Album &a);
    bool operator!=(const Album &a);
    bool operator<(const Album &a);
    bool operator>(const Album &a);

    void displayAlbum(ostream& out) const;
    //prints each album with its details to an output

    friend ostream& operator<<(ostream& out, const Album& Album);
};

#endif /* ALBUM_H_ */
