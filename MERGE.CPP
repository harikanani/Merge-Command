#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
void main(int n,char *data[])
{
	fstream fout;
	char ch;
	int f = 1;

	fout.open(data[n-1],ios::out);
	fout.close();
	fout.open(data[n-1],ios::app);

	cout<<"For more information on a specific command, type --help Command-name"<<endl;
/* ---------------------- Check if Same name or not.
	for(int j=1;j<n-1;j++)
	{
		for(int k=0;k<n-1;k++)
		{
			if(!(strcmp(data[j],data[j+1])))
			{
				f = 1;
			}
		}
	}
*/
	if(n==2 && strcmp(data[1],"--help")==0)
	{
		cout<<"------------ HELP -------------"<<endl;
		cout<<"Documentation of Merge Command Created By Harikrushn Kanani.";
		cout<<endl;
		cout<<"Commands: "<<endl<<endl;
		cout<<"--help    : To get Help Menu."<<endl;
		cout<<"--version : To get the Version of the Software."<<endl;
		cout<<"--formate : To get the Formate of the Command."<<endl;
	}
	else if(n==2 && strcmp(data[1],"--version")==0)
	{
		cout<<"Merge Command."<<endl;
		cout<<"Version V1.0"<<endl;
	}
	else if(n==2 && strcmp(data[1],"--formate")==0)
	{
		cout<<"Formate : merge [source file names...] [destination file name]";
		cout<<endl;
	}
	else if(n<=1)
	{
		cout<<"Insufficient Number of Arguments."<<endl;
		cout<<"Please Provide Source File and Destination File names."<<endl;
		cout<<"Formate : merge [source file names...] [destination file name]";
		cout<<endl;
	}
	else if(n<=2)
	{
		cout<<"Insufficient Number of Arguments."<<endl;
		cout<<"Please Provide Destination File name."<<endl;
		cout<<"Formate : merge [source file names...] [destination file name]";
		cout<<endl;
	}
	else
	{
		for(int i=1;i<n-1;i++)
		{
// ------------- Open File and Check if Exists or Not -----------------------
			ifstream* fin = new ifstream[n-2];
			fin[i-1].open(data[i]);
			if(!fin[i-1].good())
			{
				cout<<fin[i-1]<<" File is not Exists."<<endl;
				cout<<"Please Provide Existing File name."<<endl;
 //				f = 0;
				break;
			}

			fin[i-1].get(ch);
			while(!fin[i-1].eof())
			{
				fout<<ch;
				fin[i-1].get(ch);
			}
			cout<<data[i]<<" File Copied into "<<data[n-1]<<" File.";
			cout<<endl;
			fin[i-1].close();
			fout<<" : ";
		}
	}
/*	if(f)
		cout<<"Copied Successfully."<<endl;
	else
		cout<<"ERROR in Opening Some Files Please Check the Files Names.";
*/
	getch();
}

/* -------------------------------------------------------------------------
			Copy All Files One By One into Destination File
			my First Logic
   -------------------------------------------------------------------------

/*			for(i=0;i<n-2;i++)
			{
				fin[i].get(ch);
				while(!fin[i].eof())
				{
					fout<<ch;
					fin.get(ch);
				}
				fin[i].close();
				fin[i+1].open(data[i+1]);
			}
*/
