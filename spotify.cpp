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
void swap1(Songs *s,Songs *s1)
{
    Songs s2;
    s2=*s;
    *s=*s1;
    *s1=s2;
}
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
        cout<<"Playlist name: "<<pname<<endl<<endl;
        for(i=0;i<this->counter;i++)
        {
            cout<<i+1<<". "<<s[i].sName<<"\t"<<s[i].time<<" mins"<<endl;
            cout<<"Artist Name:"<<s[i].a.aName<<"\tGenre:"<<s[i].g.gName<<endl<<endl;
            cout<<"Artist points: "<<s[i].a.aPoints<<"\t Genre points: "<<s[i].g.gPoints<<endl<<endl;
        }
    }
    void play(int n)
    {
        char ch;
        system("CLS");

        for(i=0;i<n;i++)
        {

            cout<<"We are currently playing PLaylist"<<this->pname<<endl<<endl;
            cout<<"     Currently Playing Song: "<<this->s[i].sName<<endl;
            cout<<"     Artist: "<<this->s[i].a.aName<<"\t Genre: "<<this->s[i].g.gName<<endl<<endl;
            cout<<"Press Y if you like the song N if you dont or any other key to not rate the song"<<endl;
            ch=getch();
            if((ch=='n')||(ch=='N'))
            {
                review(s,n,i,-1);
            }
            else if((ch=='y')||(ch=='Y'))
            {
                review(s,n,i,1);
            }
            else{}
            system("CLS");
        }
    }
    void review(Songs s[],int n,int i,int num)
    {
        string art,gen;
        art=s[i].a.aName;
        gen=s[i].g.gName;
        for(int j=0;j<n;j++)
        {
            if(s[j].a.aName == art)
            {
                s[j].a.aPoints+=num;
            }
            if(s[j].g.gName == gen)
            {
                s[j].g.gPoints+=num;
            }
        }
    }
    void sort1(int n)
    {
        int i,j;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (s[j].g.gPoints+s[j].a.aPoints < s[j+1].g.gPoints+s[j+1].a.aPoints)
                    swap1(&s[j], &s[j+1]);
            }
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
    p.play(y);
    p.sort1(y);
    p.print();
    cout<<"\nPress any key to exit\n";
    getch();
}
