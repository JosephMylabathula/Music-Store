#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
#include <fstream>
#include "Album.h"
#include "BST1.h"
#include "BST2.h"
using namespace std;

class Product{
private:
    BST1<Album> bst1;
    BST2<Album> bst2;
    void insert();
    //inserts albums into two BSTs
public:
    Album searchByTitle(string t);
    Album searchByArtist(string a);
    void printByTitle(ostream& out);
    void printByArtist(ostream& out);
    void insertAlbum(Album a);
    void removeAlbum(Album a);
};

void Product::insert(){
	ifstream fin;
	string title,artist,genre,s;
	unsigned year;
	double price;
	fin.open("Albums.txt");
	while(getline(fin,title)){
		Album entry;
		entry.set_title(title);
		getline(fin,artist);
		entry.set_artist(artist);
		getline(fin,genre);
		entry.set_genre(genre);
		//vector<vector<char>> k;
		//int i=0;
		//int j=0;
		//while(getline(fin,s) && !isdigit(s[j])){
			//if(!(fin >> ws)){
				//while(j < s.length()){
	    			//k[i].push_back(s[j]);
	    			//j++;
	    		//}
				//entry.set_songName(k[i]);
				//i++;
			//}
		//}
	fin >> year;
	entry.set_year(year);
	fin >> price;
	entry.set_price(price);
	fin >> ws;
	bst1.insert(entry);
	bst2.insert(entry);
	}
	fin.close();
}

Album Product::searchByTitle(string t){
	insert();
	Album album;
	album.set_title(t);
	if(bst1.search(album).get_year() != 0)
		return bst1.search(album);
	else{
		Album dummy;
		return dummy;
	}
}

Album Product::searchByArtist(string a){
	insert();
	Album album;
	album.set_artist(a);
	if(bst2.search(album).get_year() != 0)
		return bst2.search(album);
	else{
		Album dummy;
		return dummy;
	}
}

void Product::printByTitle(ostream& out){
	insert();
	bst1.inOrderPrint(out);
}

void Product::printByArtist(ostream& out){
	insert();
	bst2.inOrderPrint(out);
}

void Product::insertAlbum(Album a){
	ifstream fin;
	ofstream fout;
	string l;
	fin.open("Albums.txt");
	fout.open("temp.txt");
	while(getline(fin,l))
		fout << l << endl;
	fout << a.get_title() << endl;
	fout << a.get_artist() << endl;
	fout << a.get_genre() << endl;
	fout << a.get_year() << endl;
	fout << a.get_price() << endl;
	fout << endl;
	fin.close();
	fout.close();
	remove("Albums.txt");
	rename("temp.txt","Albums.txt");
}

void Product::removeAlbum(Album a){
	ifstream fin;
	ofstream fout;
	string l;
	fin.open("Albums.txt");
	fout.open("temp.txt");
	while(getline(fin,l)){
		if(l != a.get_title())
			fout << l << endl;
		else{
			for(int i=0; i<5; i++)
				getline(fin,l);
		}
	}
	fin.close();
	fout.close();
	remove("Albums.txt");
	rename("temp.txt","Albums.txt");
	bst1.remove(a);
	bst2.remove(a);
}
#endif /* PRODUCT_H_ */
