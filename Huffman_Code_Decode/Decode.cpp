#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Ad
{
public:
    char letters;
    int frequency;
    string s;
};
int calculateFileSize(string &P)
{
    string s;
    int counter=0;
    ifstream in;
   in.open(P.c_str());
  while(! in.eof())
{
    getline(in,s);
    counter++;
}
in.close();
return counter-2;
}

void readDictionary( string A,Ad Dictionary[], int siize)
{
    ifstream in;string sp;
    in.open(A.c_str());
    Dictionary[siize];int i=0;int counter;
    if(! in){cout<<"Error";}
    else{

    while(! in.eof())
    {
        getline(in,sp);
        counter=sp.length();
        for(int j=0;j<counter;j++)
        {
            if(j==0)
            {
                Dictionary[i].letters=sp[0];
            }
            else
            {
                Dictionary[i].s=Dictionary[i].s+sp[j];
            }
        }
        i++;


    }
    in.close();
    }
}
readHuffmanCodes(string A, string & reader)
{
    ifstream in;string sp;
    in.open(A.c_str());

    if(! in){cout<<"Error";}
    else
    {
     while(! in.eof())
         {
         getline(in,sp);
         reader=reader+sp;
         }
    }
}
int main()
{

    string dic="Dictionary.txt";
    int no_of_entries=calculateFileSize(dic);
    Ad Dictionary[no_of_entries];

    readDictionary( dic ,Dictionary,no_of_entries);
    string huff="HuffmanCodes.txt";
    string reader;
    string decrypt;

    readHuffmanCodes(huff,reader);
    int siize=reader.length();
    string prefix;

    for(int i=0;i<siize;i++)
    {
        prefix=prefix+reader[i];
        for(int j=0;j<no_of_entries;j++)
        {
            if(prefix==Dictionary[j].s)
            {
                decrypt=decrypt+ Dictionary[j].letters;
                prefix="";
            }
        }
    }
    cout<<decrypt;

}



