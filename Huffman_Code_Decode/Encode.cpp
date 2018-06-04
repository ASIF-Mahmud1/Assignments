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

class B
{
public:

    int cfrequency;
    string interesting;
};
void Checker(string Dic, char pus, Ad mainArray[], int saze)
{
    int length= Dic.length();

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<saze;j++)
        {
            if(Dic[i]== mainArray[j].letters)
            {
               mainArray[j].s= mainArray[j].s+ pus;
            }
        }

    }
}

void BubbleSort(B copyArray[], int saze)
{
    for (int i=saze-1;i>=0;i--)
    {
        for(int j=i-1; j>=0;j--)
        {
            if(copyArray[i].cfrequency>copyArray[j].cfrequency)
            {
                int temp= copyArray[j].cfrequency;
                string e =copyArray[j].interesting;
                copyArray[j].cfrequency=copyArray[i].cfrequency;
                copyArray[j].interesting=copyArray[i].interesting;
                copyArray[i].cfrequency=temp;
                copyArray[i].interesting=e;
            }
        }
    }
}

void writeToFile(string L ,string &carrier_to_file)
{
    ofstream out;
    out.open(L.c_str(),ios::out);
    out<<carrier_to_file;
    out.close();
}

void writeToDictionary(string L ,string &words)
{
    ofstream out;
    out.open(L.c_str(),ios::out);
    out<<words<<endl;
    out.close();
}

void read( string B, Ad mainArray[], int saze ,string &cod)
{
    ifstream in;
    string mod;
    Ad A[54];
    char asex; asex='A';int j=0;int k=0;
    in.open(B.c_str());
    if(! in){cout<<"Error";}
    else
    {
    while(! in.eof())
    {
        getline(in,mod);
        cod=cod+mod;
    }
    in.close();
    }

    for(int i=0;i<58;i++)
   {
       if(i<26 || i>31)
      {
            A[j].letters=asex;
            A[j].frequency =0;  j++;
      }
      asex= asex+1;
   }

    A[52].letters=' ';
    A[52].frequency=0;
    A[53].letters='.';
    A[53].frequency=0;

    for(int i=0;i<cod.length();i++)
  {
      int p;
      p=cod[i]-'A';
      if(cod[i]==' ')
      {

          A[52].frequency=(A[52].frequency)+1;
      }

      if((cod[i]!='.'))
      {
          if(p<26)
          {A[p].frequency=(A[p].frequency)+1;}

          if(p>31)
          {A[p-6].frequency=(A[p-6].frequency)+1;}
      }
      if((cod[i]=='.'))
      {
          A[53].frequency=(A[53].frequency)+1;
      }
  }

    for(int j=0;j<54;j++)
    {

      mainArray[j].letters=A[j].letters;
      mainArray[j].frequency=A[j].frequency;
    }
}

string reverse_a_string(string& s)
{
    int saze =s.length();
    string temp="";
    int j=0;
    for(int i=saze-1;i>=0;i--)
    {
        temp=temp+s[i];
    }
    s=temp;
    return s;
}

int main()
{
    Ad countArray[54];
    string filename;
    string cod;
    int count_non_zero_freq=0;
    cout <<"Write The Name of Your File  : ";
    getline(cin,filename);
    //filename="writehere.txt";
    read(filename, countArray,54, cod);

    for(int j=0;j<54;j++)
    {
        if(countArray[j].frequency!=0)
        {
       //  cout<<countArray[j].letters<<" "<<countArray[j].frequency<<endl;
         count_non_zero_freq++;
        }
    }

    Ad mainArray[count_non_zero_freq];

    B copyArray[count_non_zero_freq];
    int i=0;

    for(int j=0;j<54;j++)
    {
     if(countArray[j].frequency !=0)
      {

         mainArray[i].letters=countArray[j].letters;
         mainArray[i].frequency=countArray[j].frequency;

         copyArray[i]. interesting=countArray[j].letters;
         copyArray[i].cfrequency=countArray[j].frequency;
         i++;
      }
    }


    BubbleSort(copyArray,count_non_zero_freq);

     for(int i=count_non_zero_freq-1; i>0;i--)
    {
        Checker(copyArray[i].interesting, '1', mainArray, count_non_zero_freq);
        Checker(copyArray[i-1].interesting, '0', mainArray, count_non_zero_freq);

        copyArray[i-1].interesting=copyArray[i-1].interesting+copyArray[i].interesting;
        copyArray[i-1].cfrequency=copyArray[i-1].cfrequency+copyArray[i].cfrequency;

        if(i-1 !=0)
        {
            BubbleSort(copyArray,i);
        }
    }

    for(int i=0;i<count_non_zero_freq;i++)
    {
         string temp =reverse_a_string( mainArray[i].s);
         mainArray[i].s=temp;
         cout<<mainArray[i].letters<<" "<<mainArray[i].s<<endl;
    }

      string carrier_to_dictionary;
      string dictionary ="Dictionary.txt";
      for(int p=0;p<count_non_zero_freq;p++)
      {
        carrier_to_dictionary= carrier_to_dictionary+mainArray[p].letters+mainArray[p].s+"\n";
      }
      writeToDictionary(dictionary,carrier_to_dictionary);

     int length= cod.length();
     string carrier_to_file;
     string Huffman_codes="HuffmanCodes.txt";

    for(int k=0;k<length;k++)
    {
      for(int l=0;l<count_non_zero_freq;l++)
      {
        if(mainArray[l].letters==cod[k])
        {
           carrier_to_file=carrier_to_file+mainArray[l].s;
        }
      }
    }

    writeToFile(Huffman_codes,carrier_to_file);

    cout<<"Your Dictionary is saved in a text file"<<endl;
}

