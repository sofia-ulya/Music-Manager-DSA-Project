#include<iostream>
#include<iomanip>
#include"Music.h"
usingnamespace std;

inti = 1;

Music::Music()
{
	numItem = 0;
	pHead = pTail = pCur = NULL;
}

Music::~Music() {}

//masukkanlagubarudlm database
voidMusic::addMusic(strings, stringrd, stringa, floatl)
{
	Node* pNew = newNode;
	pNew->bil = i++;
	pNew->song =s;
	pNew->releasedate=rd;
	pNew->artist =a;
	pNew->length = l;
	pNew->link = NULL;
	if (empty())
	{
		pHead = pNew;
		pTail = pNew;
	}
	else
	{
		pTail->link = pNew;
		pTail = pTail->link;
	}
	numItem++;
}

//edit apa2 drpdlagutu
voidMusic::editMusic(stringx)
{
	Node* pTraverse = pHead;
	while (pTraverse->song !=x&&pTraverse->link != NULL)
	{
		pTraverse = pTraverse->link;
	}

	if (pTraverse->song ==x)
	{
		pCur = pTraverse;
		printSong(x);

		cout<<"\nWhat do you want to edit? (1-song/2-release date/3-artist/4-length) : ";
		int answer;
		cin>> answer;
		cin.ignore();
		if (answer == 1)
		{
			cout<<"Edit song name: ";
			string song;
			getline(cin, song);
			pTraverse->song = song;
		}
		elseif (answer == 2)
		{
			cout<<"Edit song release date: ";
			stringreleasedate;
			getline(cin, releasedate);
			pTraverse->releasedate=releasedate;
		}
		elseif (answer == 3)
		{
			cout<<"Edit song artist: ";
			string artist;
			getline(cin, artist);
			pTraverse->artist = artist;
		}
		elseif (answer == 4)
		{
			cout<<"Edit song length: ";
			float length;
			cin>> length;
			cin.ignore();
			pTraverse->length = length;
		}
		cout<<"\nSong edited : \n";
	}

	else
		cout<<"Song is not in the list.\n";

}

//delete lagudrpd database
voidMusic::deleteMusic(strings)
{
	Node* pBefore = newNode;
	Node* pTemp = pHead;
	while (pTemp->link != NULL&&pTemp->song !=s)
	{
		pBefore = pTemp;
		pTemp = pTemp->link;
	}

	if (pHead->song ==s)
	{
		pHead = pHead->link;
		numItem--;
		cout<<"One music is deleted."<<endl;
	}
	elseif (pTemp->song ==s)
	{
		pBefore->link = pTemp->link;
		deletepTemp;
		numItem--;
		cout<<"One music is deleted."<<endl;
	}
	else
	{
		cout<<"Music not found."<<endl;
	}
}

//carilagudlm database
voidMusic::searchMusic(stringx)
{
	//traverse
	Node* pTraverse = newNode;
	pTraverse = pHead;
	bool found;
	int index = pTraverse->bil;
	Node* temp = newNode;
	while ((pTraverse->song !=x) && (pTraverse->link != NULL))
	{
		pTraverse = pTraverse->link;
	}
	if (pTraverse->song ==x)
	{
		if (index > 0)
		{
			pCur = pTraverse;
			printSong(x);
		}
	}
	else
		cout<<"Song is not in the list.\n";

}

//susunnamaartisikuturutan(A~Z)
voidMusic::sortMusic(boolx)
{
	pCur = pHead;
	if (x == true)
	{
		while (pCur != NULL)
		{
			Node* min = pCur;
			Node* next = pCur->link;
			while (next)
			{
				if (min->artist > next->artist)
					min = next;
				next = next->link;
			}
			int b = pCur->bil;
			string s = pCur->song;
			string d = pCur->releasedate;
			string a = pCur->artist;
			float l = pCur->length;
			pCur->bil = min->bil;
			pCur->song = min->song;
			pCur->releasedate= min->releasedate;
			pCur->artist = min->artist;
			pCur->length = min->length;
			min->bil = b;
			min->song = s;
			min->releasedate= d;
			min->artist = a;
			min->length = l;
			pCur = pCur->link;
		}
	}
	else
	{
		while (pCur != NULL)
		{
			Node* max = pCur;
			Node* next = pCur->link;
			while (next)
			{
				if (max->artist < next->artist)
					max = next;
				next = next->link;
			}
			int b = pCur->bil;
			string s = pCur->song;
			string d = pCur->releasedate;
			string a = pCur->artist;
			float l = pCur->length;
			pCur->bil = max->bil;
			pCur->song = max ->song;
			pCur->releasedate= max ->releasedate;
			pCur->artist = max ->artist;
			pCur->length = max ->length;
			max ->bil = b;
			max ->song = s;
			max ->releasedate= d;
			max ->artist = a;
			max ->length = l;
			pCur = pCur->link;
		}
	}
}

//susuntajuklaguikuturutan(A~Z)
voidMusic::sortMusic(charx)
{
	pCur = pHead;
	if ((x == 'A') || (x == 'a'))
	{
		while (pCur != NULL)
		{
			Node* min = pCur;
			Node* next = pCur->link;
			while (next)
			{
				if (min->song > next->song)
					min = next;
				next = next->link;
			}
			int b = pCur->bil;
			string s = pCur->song;
			string d = pCur->releasedate;
			string a = pCur->artist;
			float l = pCur->length;
			pCur->bil = min->bil;
			pCur->song = min->song;
			pCur->releasedate= min->releasedate;
			pCur->artist = min->artist;
			pCur->length = min->length;
			min->bil = b;
			min->song = s;
			min->releasedate= d;
			min->artist = a;
			min->length = l;
			pCur = pCur->link;
		}
	}
	else
	{
		while (pCur != NULL)
		{
			Node* max = pCur;
			Node* next = pCur->link;
			while (next)
			{
				if (max ->song < next->song)
					max = next;
				next = next->link;
			}
			int b = pCur->bil;
			string s = pCur->song;
			string d = pCur->releasedate;
			string a = pCur->artist;
			float l = pCur->length;
			pCur->bil = max ->bil;
			pCur->song = max ->song;
			pCur->releasedate= max ->releasedate;
			pCur->artist = max ->artist;
			pCur->length = max ->length;
			max ->bil = b;
			max ->song = s;
			max ->releasedate= d;
			max ->artist = a;
			max ->length = l;
			pCur = pCur->link;
		}
	}
}

//susunlaguikuturutan(Nombor)
voidMusic::sortMusic(intx)
{
	pCur = pHead;
	if (x == 1)
	{
		while (pCur != NULL)
		{
			Node* min = pCur;
			Node* next = pCur->link;
			while (next)
			{
				if (min->bil> next->bil)
					min = next;
				next = next->link;
			}
			string s = pCur->song;
			string d = pCur->releasedate;
			string a = pCur->artist;
			float l = pCur->length;
			pCur->song = min->song;
			pCur->releasedate= min->releasedate;
			pCur->artist = min->artist;
			pCur->length = min->length;
			min->song = s;
			min->releasedate= d;
			min->artist = a;
			min->length = l;
			pCur = pCur->link;
		}
	}
	else
	{
		while (pCur != NULL)
		{
			Node* max = pCur;
			Node* next = pCur->link;
			while (next)
			{
				if (max ->bil< next->bil)
					max = next;
				next = next->link;
			}
			int b = pCur->bil;
			string s = pCur->song;
			string d = pCur->releasedate;
			string a = pCur->artist;
			float l = pCur->length;
			pCur->bil = max ->bil;
			pCur->song = max ->song;
			pCur->releasedate= max ->releasedate;
			pCur->artist = max ->artist;
			pCur->length = max ->length;
			max ->bil = b;
			max ->song = s;
			max ->releasedate= d;
			max ->artist = a;
			max ->length = l;
			pCur = pCur->link;
		}
	}
}

//display one the latest song
voidMusic::printSong()
{
	cout<<"\nId: "<<pTail->bil;
	cout<<"\nSong: "<<pTail->song;
	cout<<"\nRelease date: "<<pTail->releasedate;
	cout<<"\nArtist: "<<pTail->artist;
	cout<<"\nLength: "<<pTail->length <<"\n\n";
}

//display one certain song
voidMusic::printSong(strings)
{
	cout<<"\nId: "<<pCur->bil;
	cout<<"\nSong: "<<pCur->song;
	cout<<"\nRelease date: "<<pCur->releasedate;
	cout<<"\nArtist: "<<pCur->artist;
	cout<<"\nLength: "<<pCur->length <<"\n\n";
}

//display list of musicss
voidMusic::printMusic()
{
	cout<<"Bil"<<setw(20) <<setfill(' ') <<"Song"<<setw(15) <<setfill(' ') <<"Release date"<<setw(20) <<setfill(' ') <<"Artist "<<setw(7) <<setfill(' ') <<"Length"<<endl;
	pCur = pHead;
	while (pCur != NULL)
	{
		cout<<"["<<pCur->bil<<"]";
		cout<<setw(20) <<setfill(' ') <<pCur->song <<setw(15) <<setfill(' ') <<pCur->releasedate<<setw(20) <<setfill(' ') <<pCur->artist <<setw(7) <<setfill(' ') <<pCur->length <<endl;
		pCur = pCur->link;
	}
	cout<<"\n";
}

Music* Music::getMusic(strings)
{
	Music* m = newMusic;
	(*m).pCur = pHead;
	while (((*m).pCur->link != NULL) && ((*m).pCur->song !=s))
		(*m).pCur = (*m).pCur->link;
	if ((*m).pCur->song ==s)
	{
		return m;
	}
	else
		cout<<"Song not found in list"<<endl;
}

boolMusic::empty()
{
	return (numItem == 0);
}
