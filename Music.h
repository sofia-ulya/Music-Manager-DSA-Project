#ifndefMUSIC_H
#define MUSIC_H
#include<string>
#include<iostream>
#include"Playlist.h"
usingnamespace std;

class Music
{
private:
	class Node
	{
	public:
		intbil;
		string song;
		stringreleasedate;
		string artist;
		float length;
		Node* link;
	};
	Node* pHead;
	Node* pCur;
	Node* pTail;
	intnumItem;

public:
	Music();
	~Music();
	voidaddMusic(string, string, string, float);	//masukkanlagubarudlm list
	voideditMusic(string);					//edit apa2 drpdlagutu
	voiddeleteMusic(string);				//delete lagudrpd list
	voidsearchMusic(string);				//carilagudlm list
	voidsortMusic(bool);					//susunnamaartisikuturutan(A~Z)
	voidsortMusic(char);					//susuntajuklaguikuturutan(A~Z)
	voidsortMusic(int);					//susunnomborikuturutan(bil)
	voidprintSong();					//display satulagu yang barutambah
	voidprintSong(string);				//display satulagu yang dicari
	voidprintMusic();					//display list lagu
	Music* getMusic(string);				//get object of music
	bool empty();

	friendclass Playlist;
};
#endif
