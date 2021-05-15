#include<iostream>
#include<string>
#include"Music.h"
#include"Playlist.h"
usingnamespace std;

//declare global variables
string song;
stringreleasedate;
string artist;
float length;
intans;

template<classT>
voidsortList(T);				//sort list (by title song or bil)
voidaddSong();				//add new song to list of music
voiddeleteSong();			//delete song from list of music
voideditSong();				//edit details of song
voiddisplaySong();			//display list of music
voidaddPlaylist();			//add song to playlist (enqueue)
voiddeletePlaylist();			//delete song from playlist (dequeue)
voidprintPlaylist();			//display playlist song (QueueFront,QueueRear)
voidsearchSong();			//search for a song

//global object
Music M;		//create object music baru
Playlist P;		//create object playlist

int main() {
	system("cls");
	int answer;	//declare variable

	cout<<"***********WELCOME TO MUSIC MANAGER***********";
	cout<<"\n\nPlease choose your function by entering the number.";
	cout<<"\n[1] Add new song to library";
	cout<<"\n[2] Delete song from library";
	cout<<"\n[3] Edit song details";
	cout<<"\n[4] Display list of songs in library";
	cout<<"\n[5] Add song to playlist";
	cout<<"\n[6] Delete song from playlist";
	cout<<"\n[7] Display song playlist";
	cout<<"\n[8] Search song";
	cout<<"\n[0] Exit program";

	//input dari user
	cout<<"\n\nYour choice : "; cin>> answer; cin.ignore();

	switch (answer)
	{
	case 1:
		addSong();
		break;
	case 2:
		deleteSong();
		break;
	case 3:
		editSong();
		break;
	case 4:
		displaySong();
		break;
	case 5:
		addPlaylist();
		break;
	case 6:
		deletePlaylist();
		break;
	case 7:
		printPlaylist();
		break;
	case 8:
		searchSong();
		break;
	case 0:
	exitMenu:
		intans;
		cout<<"Are you sure want to exit Music Manager? (1-Yes/0-No) : ";
		cin>>ans;
		cin.ignore();
		if (ans == 1)
			exit(1);
		elseif (ans == 0)
			main();
		else
		{
			cout<<"Character does not recognise"<<endl;
			system("pause");
			exit(1);
		}
		break;
	default:
		cout<<"Character does not recognise"<<endl;
		cout<<"Please choose between 0-8."<<endl;
		exit(1);
		break;
	}
	return 0;
}

//sorting list by title of song or bil
template<classT>
voidsortList(Tsequence)
{
	//sort song by title of bil
	M.sortMusic(sequence);
	M.printMusic();
}

//add details of song to list of music
voidaddSong()
{
	system("cls");
	cout<<"\n***********ADD NEW SONG***********"<<endl;

	cout<<"\nAdd the song details:"<<endl;
	//Input dari user
	cout<<"Insert song name: ";
	getline(cin, song);
	cout<<"Insert song release date: ";
	getline(cin, releasedate);
	cout<<"Insert song artist: ";
	getline(cin, artist);
	cout<<"Insert song length: ";
	cin>> length;
	cin.ignore();

	M.addMusic(song, releasedate, artist, length);			//add song to list

	cout<<"\nSong details entered: "<<endl;
	M.printSong();												//print latest song added

	cout<<"\nDo you want to add more song? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		addSong();
	else
		main();
}

//delete song from list of music
voiddeleteSong()
{
	system("cls");
	cout<<"\n***********DELETE SONG***********"<<endl;
	M.printMusic();						//print list before delete
	//if list empty, skip to display code
	if (M.empty())
	{
		cout<<"\nNo song can be deleted"<<endl;
		goto display;
	}
	//Input dari user
	cout<<"\nWhich music you want to delete : ";
	getline(cin, song);
	M.deleteMusic(song);										//delete from list music
	cout<<endl;
	M.printMusic();												//print list after delete 

display:
	cout<<"Do you want to delete more music? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		deleteSong();
	else
		main();
}

//edit details of song in list
voideditSong()
{
	system("cls");
	cout<<"\n***********EDIT SONG***********"<<endl;

	//if list empty, skip to display code
	M.printMusic();
	if (M.empty())
	{
		cout<<"\nNo song can be editted"<<endl;
		goto display;
	}
	//edit process//
	cout<<"\nWhich song you want to edit : ";
	getline(cin, song);
	M.editMusic(song);
	M.printMusic();

display:
	cout<<"\nDo you want to edit more song? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		editSong();
	else
		main();
}

//display list of music
voiddisplaySong()
{
	system("cls");
	cout<<"\n***********LIST OF SONGS***********"<<endl;
	M.printMusic();		//print list of music
	//if list empty, skip to display code
	if (M.empty())
	{
		cout<<"\nNo song listed"<<endl;
		goto display;
	}

chooseType:
	int type;
	//ask user choose type of sorting
	cout<<"\nHow do you want to sort list? (By 1-Number/2-Title song/3-Artist Name/4-Skip Sorting) : ";
	cin>>type;cin.ignore();
	if (type == 1)
	{
		int sequence;

	sortNumber:
		cout<<"\nSort by sequence number song added (1-Ascending 0-Descending) : ";
		cin>>sequence;cin.ignore();
		if ((sequence != 1) && (sequence != 0))
			gotosortNumber;		//repeat code sortNumber
		else
			sortList(sequence);		//do sort process
	}
	elseif (type == 2)
	{
		char answer;

	sortTitle:
		cout<<"\nSort title song by Alphabet (A-Ascending Z-Descending) : ";
		cin>>answer;cin.ignore();
		if ((answer == 'A') || (answer == 'a') || (answer == 'Z') || (answer == 'z'))
		{
			bool sequence;
			if ((answer == 'A') || (answer == 'a'))sequence = true;
			else sequence = false;
			sortList(sequence);	//do sort process
			goto display;		//after get result, skip to display code
		}
		else
			gotosortTitle;		//repeat code sortTitle
	}
	elseif (type == 3)
	{
		char sequence;

	sortArtist:
		cout<<"\nSort artist name by Alphabet (A-Ascending Z-Descending) : ";
		cin>>sequence;cin.ignore();
		if ((sequence == 'A') || (sequence == 'a') || (sequence == 'Z') || (sequence == 'z'))
		{
			sortList(sequence);	//do sort process
			goto display;		//after get result, skip to display code
		}
		else
			gotosortArtist;	//repeat code sortArtist
	}
	elseif (type == 4)
		goto display;
	else
		gotochooseType;		//repeat code chooseType

display:
	cout<<"\nDo you want to back to menu? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		main();
	else
		displaySong();
}

//enqueue song to playlist queue
voidaddPlaylist()
{
	Music* temp = newMusic;
	system("cls");
	cout<<"\n***********ADD SONG TO PLAYLIST***********"<<endl;
	M.printMusic();			//print list of music
	//if list empty, skip to display code
	if (M.empty())
	{
		cout<<"\nNo song listed"<<endl;
		goto display;
	}
	//ask which song to add
	cout<<"\nwhich song do you want to add in playlist  : ";
	getline(cin, song);

	//enqueue playlist process//
	temp = M.getMusic(song);		//get object from music class
	P.enqueuePlaylist(temp);

	cout<<"\nSongs in playlist queue: "<<endl;
	P.displayPlaylist();			//print playlist after enqueue

display:
	cout<<"Do you want add more song to your playlist? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
	{
		(*temp).~Music();
		addPlaylist();
	}
	else
		main();
}

//dequeue song from playlist
voiddeletePlaylist()
{
	system("cls");
	cout<<"\n***********DELETE SONG FROM PLAYLIST***********"<<endl;
	P.displayPlaylist();					//print playlist before dequeue
	cout<<"\nDo you want to remove song from playlist queue? 1-Yes 0-No : "<<endl;
	cin>>ans;
	cin.ignore();

	//dequeue playlist process//
	if (ans == 1)
	{
		P.dequeuePlaylist();
		P.displayPlaylist();				//print playlist after dequeue
	}

	cout<<"\nDo you want to delete more songs in this playlist? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		deletePlaylist();
	else
		main();
}

//display playlist queue
voidprintPlaylist()
{
	system("cls");
	cout<<"\n***********YOUR PLAYLIST***********"<<endl;
	//display full playlist queue//
	P.displayPlaylist();

	cout<<"\nFirst song in playlist queue : ";
	//QueueFront process//
	P.queueFront();
	cout<<"\nLast song in playlist queue : ";
	//QueueRear process//
	P.queueRear();

	cout<<"\nDo you want to back to menu? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		main();
	else
		printPlaylist();
}

//search for a song from list of music
voidsearchSong()
{
	system("cls");
	cout<<"\n***********SEARCH SONG***********"<<endl;

	cout<<"\nSearch : ";
	string search;
	getline(cin, search);
	M.searchMusic(search);

	cout<<"\nDo you want to search another songs? 1-Yes 0-No : ";
	cin>>ans;
	cin.ignore();

	if (ans == 1)
		searchSong();
	else
		main();
}
