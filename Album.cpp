#include "Album.h"
#include <iostream>
#include <iomanip>

Album::Album(){
    title = "";
    artist = "";
    genre = "";
    //songName.clear();
    year = 0;
    price = 0.0;
}

void Album::set_title(string t){
    title = t;
}

void Album::set_artist(string a){
    artist = a;
}

void Album::set_genre(string g){
    genre = g;
}

//void Album::set_songName(vector<char> s){
    //for(unsigned i = 0; i < s.size(); i++)
        //songName.push_back(s[i]);
//}

void Album::set_year(unsigned y){
    year = y;
}

void Album::set_price(double p){
    price = p;
}

string Album::get_title() const{
    return title;
}

string Album::get_artist() const{
    return artist;
}

string Album::get_genre() const{
    return genre;
}

//vector<char> Album::get_songName() const{
	//return songName;
//}

unsigned Album::get_year() const{
    return year;
}

double Album::get_price() const{
    return price;
}

bool Album::operator==(const Album &a){
	return (title == a.get_title());
}

bool Album::operator!=(const Album &a){
	return (artist == a.get_artist());
}



bool Album::operator<(const Album &a){
	return (title < a.get_title());
}

bool Album::operator>(const Album &a){
	return (artist < a.get_artist());
}

void Album::displayAlbum(ostream& out) const{
    out << "Album title: " << get_title() << endl;
    out << "Artist: " << get_artist() << endl;
    out << "Genre: " << get_genre() << endl;
    //out << "Song Names: ";
    //for(unsigned i = 0; i < get_songName().size(); i++)
    	//out << get_songName()[i];
    //out << endl;
    out << "Release Year: " << get_year() << endl;
    out << "Price: $" << setprecision(2) << fixed << get_price() << endl;
}

ostream& operator<<(ostream& out, const Album& Album){
    out << "Album title: " << Album.get_title() << endl;
    out << "Artist: " << Album.get_artist() << endl;
    out << "Genre: " << Album.get_genre() << endl;
    //out << "Song Names: ";
    //for(unsigned i = 0; i < Album.get_songName().size(); i++)
        //out << Album.get_songName()[i];
    //out << endl;
    out << "Release Year: " << Album.get_year() << endl;
    out << "Price: $" << setprecision(2) << fixed << Album.get_price() << endl;
    return out;
}
