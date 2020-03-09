#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int i;
class Artist
{
    public:
    string aName;
    int aPoints;
    Artist()
    {
        this->aName="";
        this->aPoints=0;
    }
    readA(string name)
    {
        this->aName=name;
        this->aPoints=0;
    }
};
class Genre
{
    public:
    string gName;
    int gPoints;
    readG(string name)
    {
        this->gName=name;
        this->gPoints=0;
    }
};

class Songs
{
    public:
    string sName;
    int time;
    Artist a;
    Genre g;
    Songs()
    {
        sName="";
        time=0;
    }
    void read(string name,int t,Artist a,Genre g)
    {
        sName=name;
        time=t;
        this->a=a;
        this->g=g;
    }
    void Genpoint();
    void Artpoint();
};
class Playlist
{
    public:
    string pname;
    Songs s[10];
    int counter;
    Playlist(string name,Songs x[],int y)
    {
        this->pname=name;
        this->counter=y;
        for(i=0;i<this->counter;i++)
        {
            this->s[i]=x[i];
        }
    }
    void print()
    {
        cout<<"Playlist name: "<<pname<<endl;
        for(i=0;i<this->counter;i++)
        {
            cout<<i+1<<". "<<s[i].sName<<"\t"<<s[i].time<<" mins"<<endl;
            cout<<"Artist Name:"<<s[i].a.aName<<"\tGenre:"<<s[i].g.gName<<endl<<endl;
            cout<<"Artist points: "<<s[i].a.aPoints<<"\t Genre points: "<<s[i].g.gPoints<<endl<<endl;
        }
    }
};
int nullcounter(Songs x[],int y)
{
    int c=0;
    for(i=0;i<y;i++)
    {
        if(x[i].sName=="")
            {
                c++;
            }
    }
    return y-c;
}
void Songs::Artpoint()
{
    this->a.aPoints=this->a.aPoints+1;
}
void Songs::Genpoint()
{
    this->g.gPoints+=1;
}
void play(Playlist P,int n)
{
    char ch;
    system("CLS");

    for(i=0;i<n;i++)
    {

        cout<<"We are currently playing PLaylist"<<P.pname<<endl<<endl;
        cout<<"     Currently Playing Song: "<<P.s[i].sName<<endl;
        cout<<"     Artist: "<<P.s[i].a.aName<<"\t Genre: "<<P.s[i].g.gName<<endl<<endl;
        cin>>ch;
        if((ch=='n')||(ch=='N'))
        { }
        else
        {
            cout<<"Yo"<<endl;
            P.s[i].Artpoint();
            P.s[i].Genpoint();
        }
        getch();
        system("CLS");
    }
}
int main()
{
    Songs s[9];
    int j=0,c=0;
    Artist a;
    Genre g;
    string nam,num,artn,genn;
    cout<<"Welcome to Spotify Application.\n"<<endl;
    getch();
    system("CLS");
    ifstream fp("songs.txt",ifstream::in);
    ifstream fa("Artist.txt",ifstream::in);
    ifstream fg("genre.txt",ifstream::in);
    cout<<"Songs in your Playlist:"<<endl;
    if(fp.good())
    {
        while(!fp.eof())
        {
            getline(fp,nam);
            getline(fp,num);
            std::istringstream(num)>>j;
            getline(fa,artn);
            getline(fg,genn);
            a.readA(artn);
            g.readG(genn);
            s[c].read(nam,j,a,g);
            c++;
        }
    }
    fp.close();
    int y=sizeof(s)/sizeof(Songs);
    y=nullcounter(s,y);
    Playlist p("Utkarsh's Playlist",s,nullcounter(s,y));
    p.print();
    getch();
    play(p,y);
    p.print();
}
