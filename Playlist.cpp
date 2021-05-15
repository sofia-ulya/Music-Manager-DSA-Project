#include<iostream>
#include"Playlist.h"
#include"Music.h"
usingnamespace std;

//constructor
Playlist::Playlist() { front = rear = NULL; numItem = 0; }

//destuctor
Playlist::~Playlist() { }

//function nimasukkanlagukedlm playlist
voidPlaylist::enqueuePlaylist(Music* m)
{
	//enqueue process//
	Node* newM = newNode;
	newM->song = m;
	newM->link = NULL;
	if (!emptyPlaylist())
		rear->link = newM;
	else
		front = newM;
	rear = newM;
	numItem++;
}

//function ni delete lagudari playlist
voidPlaylist::dequeuePlaylist()
{
	//dequeue process//
	if (emptyPlaylist())
		cout<<"No song in playlist queue!!"<<endl;
	else
	{
		Node* temp = front;
		if (numItem == 1)
			rear = front = NULL;
		else
			front = front->link;
		numItem--;
		delete temp;
	}
}

//function ni display semualagudlm playlist
voidPlaylist::displayPlaylist()
{
	if (emptyPlaylist())
		cout<<"Queue is empty"<<endl;
	Node* pCur = front;						//start from front of queue
	Music* m = newMusic;					//music object
	intbil = 1;
	while (pCur != NULL)					//until the end of queue
	{
		m = pCur->song;					//hold object song in pCur node to access member of music node
		cout<<"["<<bil<<"]";
		cout<< m->pCur->song;
		cout<<"\t"<< m->pCur->releasedate;
		cout<<"\t"<< m->pCur->artist;
		cout<<"\t"<< m->pCur->length <<endl;
		pCur = pCur->link;					//continue to next node
		bil++;
	}
	cout<<endl;
}

//display first node in queue
voidPlaylist::queueFront()
{
	Music* m = front->song;			//object m hold object song in front node
	//queueFront process//
	if (emptyPlaylist())
		cout<<"No data";
	else
		cout<< m->pCur->song <<" by "<< m->pCur->artist;			//access music node member using object m
	cout<<endl;
}

//display last node in queue
voidPlaylist::queueRear()
{
	Music* m = rear->song;			//object m hold object song in rear node
	//queueRear process//
	if (emptyPlaylist())
		cout<<"No data";
	else
		cout<< m->pCur->song <<" by "<< m->pCur->artist;			//access music node member using object m
	cout<<endl;
}





boolPlaylist::emptyPlaylist()
{
	return(numItem == 0);
}
