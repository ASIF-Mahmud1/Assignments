#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;
class Revenue
{
protected:
    int total;
public:
    Revenue()
    {
        total=0;
    }
    virtual void inputIncomeSourceOfGovernment()=0;
    virtual int calculationOfRevenue()=0;
    virtual int calculationOfRevenue(int a)=0;
    virtual void printTotalIncomeOfGovernment()=0;
};
class NonTaxIncome : public Revenue
{
private:
    int numberOfSource;
    int* sourceOfIncome;
public:
     void inputIncomeSourceOfGovernment()
     {
         cout<<"How Many Sources of Non-Tax Income do you have? Reply : ";cin>>numberOfSource;

         sourceOfIncome= new int[numberOfSource];
         for(int i=0;i<numberOfSource;i++)
         {
            cout<<" Income Source "<<i+1<<" : $ ";
            cin>>sourceOfIncome[i];
         }
     }
     int calculationOfRevenue()
     {
       for(int i=0;i<numberOfSource;i++)
         {
            total= total+ sourceOfIncome[i];
         }
         {
    ofstream out;
    out.open("NONTAX.txt",ios::out | ios::app);
    out<<endl<<total;
    out.close();

}
         return total;
     }
     int calculationOfRevenue(int sum)
     {
        total=sum;
        return total;
     }
     void printTotalIncomeOfGovernment()
     {
        cout<<" Total Non-Tax Revenue :                     $ "<<total;
     }
};
class Tax : public Revenue
{
private:
    int incomeTax;
    int corporateTax;
public:
    void inputIncomeSourceOfGovernment()
    {
        cout<<"Total Income-Tax Collected : $ ";cin>>incomeTax;
        cout<<"Total Corporate-Tax Collected : $ ";cin>>corporateTax;
    }
    int calculationOfRevenue()
    {
        total= incomeTax+corporateTax;
        {
    ofstream out;
    out.open("TAX.txt",ios::out | ios::app);
    out<<endl<<total;
    out.close();

}
        return total;
    }
    int calculationOfRevenue(int sum)
     {
        total=sum;
        return total;
     }

    void printTotalIncomeOfGovernment()
    {
        cout<<" Total Tax Collected :                       $ "<<total;
    }
};
class Expenditure
{
protected:
    int total;
public:Expenditure()
    {
        total=0;
    }
    virtual void inputExpenseSourceOfGovernment()=0;
    virtual int calculationOfExpense()=0;
    virtual int calculationOfExpense(int sum)=0;
    virtual void printTotalExpenseOfGovernment()=0;

};
class FinalConsumerExpenditure : public Expenditure
{
private:
    int numberOfSource;
    int* sourceOfExpense;
public:
    void inputExpenseSourceOfGovernment()
    {
        cout<<"How Many Categories of Consumer Expense do you have? Reply : ";cin>>numberOfSource;

         sourceOfExpense= new int[numberOfSource];
         cout<<"Consumer Expenditures : "<<endl;
         for(int i=0;i<numberOfSource;i++)
         {
            cout<<" Consumer Expense  "<<i+1<<" : $ ";
            cin>>sourceOfExpense[i];
         }
    }
    int calculationOfExpense()
    {
        for(int i=0;i<numberOfSource;i++)
         {
            total= total+ sourceOfExpense[i];
         }
         {
    ofstream out;
    out.open("FINAL.txt",ios::out | ios::app);
    out<<endl<<total;
    out.close();

}
         return total;
    }
    int calculationOfExpense(int sum)
    {
        total=sum;
        return total;
    }

    void printTotalExpenseOfGovernment()
    {
        cout<<"Total Final Consumer Expenditure :          $ "<<total;
    }

};
class InfraStructureAndResearch : public Expenditure
{
  protected:
      int* sourceOfExpense;
  public:
    virtual void inputExpenseSourceOfGovernment()=0;
    virtual int calculationOfExpense()=0;
    virtual void printTotalExpenseOfGovernment()=0;

};
class PhysicalInfraStructureExpenditure : public InfraStructureAndResearch
{
private:
public:
    void inputExpenseSourceOfGovernment()
    {
        sourceOfExpense= new int[4];
        cout<<"Physical Infra-Structure Expenditures : "<<endl;

        for(int i=0;i<4;i++)
        {
            if(i==0)
            {
                cout<<"Research : $ ";
            }
            else if(i==1)
            {
                cout<<"Transportation : $ ";
            }
            else if(i==2)
            {
                cout<<"Bridge : $ ";
            }
            else
            {
                cout<<"Power Grid : $ ";
            }
            cin>>sourceOfExpense[i];
        }
    }
    int calculationOfExpense()
    {
        for(int i=0;i<4;i++)
         {
            total= total+ sourceOfExpense[i];
         }
         {
    ofstream out;
    out.open("PHYSICAL.txt",ios::out | ios::app);
    out<<endl<<total;
    out.close();

}
         return total;
    }
    int calculationOfExpense(int sum)
    {
        total=sum;
        return total;
    }
    void printTotalExpenseOfGovernment()
    {
        cout<<"Total Physical InfraStructure Expenditure : $ "<<total;
    }
};
class SocialInfraStructureExpenditure :  public InfraStructureAndResearch
{
private:
    int numberOfSource;
public:
    void inputExpenseSourceOfGovernment()
    {
        cout<<"How Many Categories of Social Expense do you have? Reply : ";cin>>numberOfSource;

         sourceOfExpense= new int[numberOfSource];
         cout<<"Social Expenditures : "<<endl;
         for(int i=0;i<numberOfSource;i++)
         {
            cout<<" Social Expense  "<<i+1<<" : $ ";
            cin>>sourceOfExpense[i];
         }
    }
    int calculationOfExpense()
    {
        for(int i=0;i<numberOfSource;i++)
         {
            total= total+ sourceOfExpense[i];
         }
         {
    ofstream out;
    out.open("SOCIAL.txt",ios::out | ios::app);
    out<<endl<<total;
    out.close();

         }
         return total;
    }
    int calculationOfExpense(int sum)
    {
        total=sum;
        return total;
    }
    void printTotalExpenseOfGovernment()
    {
        cout<<"Total Social Expense :                      $ "<<total;
    }
};
class FinancialStatement
{
protected:
    string yearBeg, yearEnd;
public:
    virtual void inputStatementInfo()=0;
    virtual void calculationOfStatementInfo()=0;
    virtual void outputStatementInfo()=0;
};
class IncomeStatement : public FinancialStatement
{
private:
    int netIncome;
    NonTaxIncome nonTaxIncome;
    Tax tax;
    PhysicalInfraStructureExpenditure physicalExpenditure;
    SocialInfraStructureExpenditure  socialExpenditure;
    FinalConsumerExpenditure finalExpenditure;
public:
      void inputStatementInfo()
      {
        cout<<"Enter Starting Date of Fiscal Year : "; getline(cin,yearBeg);
        cout<<"Enter Ending Date of Fiscal Year : "; getline(cin,yearEnd);

        {
    ofstream out;
    out.open("YEAR.txt",ios::out | ios::app);
    out<<endl<<yearEnd;
    out.close();

         }


        nonTaxIncome.inputIncomeSourceOfGovernment();
        tax.inputIncomeSourceOfGovernment();
        physicalExpenditure.inputExpenseSourceOfGovernment();
        socialExpenditure.inputExpenseSourceOfGovernment();
        finalExpenditure.inputExpenseSourceOfGovernment();
      }
      void calculationOfStatementInfo()
      {

        netIncome=(nonTaxIncome.calculationOfRevenue()+tax.calculationOfRevenue())- (physicalExpenditure.calculationOfExpense() +socialExpenditure.calculationOfExpense()+ finalExpenditure.calculationOfExpense());
             ofstream in;
    in.open("PROFIT.txt",ios::out | ios::app);
    in<<endl<<netIncome;
    in.close();

      }
      void calculationOfStatementInfo(int a, int b, int c, int d, int e ,string f )
      {
         yearEnd=f;
        netIncome=(nonTaxIncome.calculationOfRevenue(a)+tax.calculationOfRevenue(b))- (physicalExpenditure.calculationOfExpense(c) +socialExpenditure.calculationOfExpense(d)+ finalExpenditure.calculationOfExpense(e));


      }
      void outputStatementInfo()
      {
          cout<<endl<<endl<<"           INCOME STATEMENT as of date "<<yearEnd<<endl;
          cout<<"---------------------------------------------------------"<<endl;
          cout<<"|   ";nonTaxIncome.printTotalIncomeOfGovernment();cout<<endl;
          cout<<"|   ";tax.printTotalIncomeOfGovernment();cout<<endl;
          cout<<"|    ";finalExpenditure.printTotalExpenseOfGovernment();cout<<endl;
          cout<<"|    ";physicalExpenditure.printTotalExpenseOfGovernment();cout<<endl;
          cout<<"|    ";socialExpenditure.printTotalExpenseOfGovernment();cout<<endl;
          if(netIncome>=0)
          {
          cout<<"|    ";cout<<"SURPLUS :                                   $ "<<netIncome;cout<<endl;
          cout<<"---------------------------------------------------------"<<endl;
          }
          else
          {
           cout<<"|    ";cout<<"DEFICIT :                                   $ "<<-netIncome<<endl;
          cout<<"---------------------------------------------------------"<<endl;
          }
      }



};

void writeToFile(string L ,int total)
{
    {
    ofstream out;
    out.open(L.c_str(),ios::out | ios::app);
    out<<endl<<total;
    out.close();

         }
}
int StringToInteger(string A)
{
    int n=0;
    int length= A.size();
    if(A[0]=='-')
    {
        for(int i=1;i<length;i++)
        {
          n=10*n + (A[i]-'0');
        }
        return -n;
    }
    else
    {

    for(int i=0;i<length;i++)
    {
        n=10*n + (A[i]-'0');
    }
    return n;
    }
}
void choose( string A,int saze,int* &B)
{
    string s;
    B=new int[saze];

    ifstream in;
   in.open(A.c_str());

  int j=0;
  while(! in.eof())
{
    getline(in,s); int b=StringToInteger(s);
    B[j]=b; j++;
}
in.close();
}

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
return counter;
}

void choose( string A,int saze,string* &D)
{
    D= new string[saze];
    ifstream in;string s;
    in.open(A.c_str());
    if(! in){cout<<"Error";}
    else{
    int i=0;
    while(! in.eof())
    {
        getline(in,s);
        D[i]=s;
        i++;
    }
    in.close();
    }
}
void readFromFile()
{
    int saze, arraySize;

      string A[6];
      A[0]="NONTAX.txt";
      A[1]="TAX.txt";
      A[2]="PHYSICAL.txt";
      A[3]="SOCIAL.txt";
      A[4]="FINAL.txt";
      A[5]="YEAR.txt";

    saze=calculateFileSize(A[3]);
     arraySize=saze;
    IncomeStatement I[arraySize];
    int** B;

    string* year;
    choose(A[5],saze,year);
   B=new int*[5];


 for( int i=0;i<5;i++)
   {
       choose(A[i],saze,B[i]);
   }


   for(int i=0;i<arraySize;i++)
   {
       I[i].calculationOfStatementInfo(B[0][i],B[1][i],B[2][i],B[3][i],B[4][i],year[i]);

   }



 for(int i=0;i<arraySize;i++)
   {
       I[i].outputStatementInfo();
   }
   cout<<" INCOME STATEMENT OF Last "<<arraySize<<" years"<<endl;



}
void userInput()
{
    IncomeStatement S;
    S.inputStatementInfo();
    S.calculationOfStatementInfo();
    S.outputStatementInfo();
}
class S_Tool
{
public:
    int saze; int* netProfit_List ;
    string A;
    int** table;

    float sum_xy, sum_x, sum_y, sum_x2;
    float a,b;
    float c,y;
public:
    S_Tool()
    {
        sum_xy=0; sum_x=0; sum_y= 0;sum_x2=0;
        Set();processData();
    }
    void Set()
    {
     A="PROFIT.txt";
     saze=calculateFileSize(A);
    choose(A,saze,netProfit_List);
    table= new int*[saze];
    for(int i=0;i<saze;i++)
      {
         table[i]= new int[2];
      }
    }
    void processData()
    {
        int x=1;
        for(int i=0;i<saze;i++)
        {
            table[i][0]= x*netProfit_List[i];
            table[i][1]= x*x; x++;
        }
        x=1;
        for(int i=0;i<saze;i++)
        {
           sum_x =sum_x+ x; x++;
           sum_y=sum_y+ netProfit_List[i];
           sum_xy= sum_xy+ table[i][0];
           sum_x2= sum_x2+ table[i][1];

        }

        b= ((saze*sum_xy)-(sum_x*sum_y))/((saze*sum_x2)-(sum_x*sum_x));
        a=(sum_y- (b*sum_x))/saze;
        {

            cout<<"Enter Value of X : ";cin>>c;y=a+ (b*c);
            cout<<"Prediction : "<<y<<endl;
        }

    }
};

class Asset

{
    int cash, advance, investment, land, inventory,total;
    public:
    void inputAssetInfo()
    {
        cout<<"Fixed Assets : "<<endl;

        cout<<"Cash : $ ";cin>>cash;writeToFile("CASH.txt",cash);
        cout<<"Advance Paid : $ ";cin>>advance;writeToFile("ADVANCEPAID.txt",advance);
        cout<<"Investment : $ ";cin>>investment;writeToFile("INVESTMENT.txt",investment);
        cout<<"Land : $ ";cin>>land;writeToFile("LAND.txt",land);
        cout<<"Inventory : $ ";cin>>inventory;writeToFile("INVENTORY.txt",inventory);

    }

    int calculationOfAsset()
    {
        total= cash+advance+investment+land+inventory;
        return total;
    }
    int calculationOfAsset(int C,int Adv ,int IN, int LA, int INV)
    {
        cash=C; advance=Adv;
        investment=INV; inventory= INV; land=LA;
        total= cash+advance+investment+land+inventory;
        return total;

    }

    void Print()
    {
         cout<<"|   Assets"<<endl<<"|   ------"<<endl;
        cout<<"|   Cash :                                            $ "<<cash<<endl;
        cout<<"|   Advance Paid :                                    $ "<<advance<<endl;
        cout<<"|   Investment :                                      $ "<<investment<<endl;
        cout<<"|   Land :                                            $ "<<land<<endl;
        cout<<"|   Inventory :                                       $ "<<inventory;

    }
};

class Liability

{
    int deposit, advanceReceived,loan, total;
    public:
    void inputLiabilityInfo()
    {
        cout<<"Current Liabilities : "<<endl;

         cout<<"Deposit Held : $ ";cin>>deposit;writeToFile("DEPOSITHELD.txt",deposit);
         cout<<"Advance Received : $ ";cin>>advanceReceived;writeToFile("ADVANCERECEIVED.txt",advanceReceived);
         cout<<"Loan : $ ";cin>>loan;writeToFile("LOAN.txt",loan);

    }
    int calculationOfLiability()
    {
        total= deposit+advanceReceived+loan;
        return total;
    }
    int calculationOfLiability(int Dep, int ADR, int LO)
    {
        deposit=Dep;
        advanceReceived= ADR;
        loan=LO;
        total= deposit+advanceReceived+loan;
        return total;
    }

    void Print()
    {
        cout<<"|   Liabilities"<<endl<<"|   -----------"<<endl;
        cout<<"|   Deposit Held :                                    $ "<<deposit<<endl;
        cout<<"|   Advance Received :                                $ "<<advanceReceived<<endl;
        cout<<"|   Loan :                                            $ "<<loan<<endl;
    }
};

class BalanceSheet: public FinancialStatement
{
private:
    Asset fixedAsset;
    Liability allLiability;
    int capital;  string yearEnd;
public:
    void inputStatementInfo()
    {
        fixedAsset.inputAssetInfo();
        allLiability.inputLiabilityInfo();

    }
    void calculationOfStatementInfo()
    {
        capital= fixedAsset.calculationOfAsset()- allLiability.calculationOfLiability();
    }
    void calculationOfStatementInfo(int a, int b, int c, int d, int e ,int f, int g, int h ,string i )
    {
     yearEnd= i;
     capital= fixedAsset.calculationOfAsset(a,b,c,d,e)- allLiability.calculationOfLiability(f,g,h);

    }

void outputStatementInfo()
    {
          cout<<endl<<endl<<"          BALANCE SHEET as of date "<<yearEnd<<endl;
          cout<<"-----------------------------------------------------------"<<endl;
         fixedAsset.Print();;cout<<endl;
          allLiability.Print();cout<<endl;

          {
          cout<<"|   ";cout<<"Net Worth :                                       $ "<<capital;cout<<endl;
           cout<<"|   Equity   "<<endl<<"|   ------"<<endl;
          cout<<"|   ";cout<<"Capital :                                         $ "<<capital;cout<<endl;
          cout<<"-----------------------------------------------------------"<<endl;
          }
      }

};

void readBalanceSheetFromFile()
{
{
    int saze, arraySize;

      string A[9];
      A[0]="CASH.txt";
      A[1]="ADVANCEPAID.txt";
      A[2]="INVESTMENT.txt";
      A[3]="LAND.txt";
      A[4]="INVENTORY.txt";
      A[5]="DEPOSITHELD.txt";
      A[6]="ADVANCERECEIVED.txt";
      A[7]="LOAN.txt";
      A[8]="YEAR.txt";

    saze=calculateFileSize(A[0]);
     arraySize=10;
    BalanceSheet I[arraySize];
    int** B;

    string* year;
    choose(A[8],saze,year);
   B=new int*[8];


 for( int i=0;i<8;i++)
   {
       choose(A[i],saze,B[i]);
   }


   for(int i=0;i<arraySize;i++)
   {
       I[i].calculationOfStatementInfo(B[0][i],B[1][i],B[2][i],B[3][i],B[4][i],B[5][i],B[6][i],B[7][i],year[i]);

   }



 for(int i=0;i<arraySize;i++)
   {
       I[i].outputStatementInfo();
   }

   cout<<" Balance Sheet OF Last "<<arraySize<<" years"<<endl;



}
}
 void userInputForBalanceSheet()
 {
     BalanceSheet S;
    S.inputStatementInfo();
    S.calculationOfStatementInfo();
    S.outputStatementInfo();
 }

int main()
{
  int choice=0;

  cout<<"          PRESS 1 To See Past Income Statements "<<endl
  <<setw(10)<<"          PRESS 2 To Generate New Income Statement"<<endl;
   cout<<"          PRESS 3 To See Past Balance Sheet "<<endl
  <<setw(10)<<"          PRESS 4 To Generate Balance Sheet"<<endl
<<setw(10)<<"          PRESS 5 To Generate Statistical Analysis"
<<endl;
 cout<<setw(10)<<"          Reply:   "; cin>>choice;cin.ignore();
  if(choice==1)
  {
      readFromFile();
  }
  if(choice==2)
  {
      userInput();
  }
  if(choice==3)
  {
      readBalanceSheetFromFile();
  }
  if(choice==4)
  {
      userInputForBalanceSheet();
  }
  if(choice==5)
  {
      S_Tool S;
  }
}
