#ifndefPLAYLIST_H
#define PLAYLIST_H
#include"Music.h"
#include<iostream>
#include<string>
usingnamespace std;

class Music;

class Playlist {

private:
	class Node
	{
	public:
		Music* song;
		Node* link;
	};
	Node* front;
	Node* rear;
	intnumItem;

public:
	Playlist();					//constructor
	~Playlist();					//destuctor
	voidenqueuePlaylist(Music*);		//tambahkanlagukedalam playlist	
	voiddequeuePlaylist();			//keluarkanlagudari playlist
	voiddisplayPlaylist();				//display semualagudlm playlist
	voidqueueFront();				//papar first song dalam playlist
	voidqueueRear();				//paparlaguterakhirdalam playlist
	boolemptyPlaylist();				//check samaada playlist empty
};
#endif// !PLAYLIST_H