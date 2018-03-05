#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;
#include"pq.h"

int main()
{
	ifstream fin("file_list.txt",ios::in);
	int i=0;
	while(!fin.eof())
	{
		string s;
		getline(fin,s);
		int len=s.size();
		if(s[len-1]!='/'&&(s[0]=='/'||s[0]=='.'))
		{
			if(s[len-1]=='/'||s[len-1]=='*'||s[len-1]=='|'||s[len-1]=='>'||s[len-1]=='=')
			{
				
				s[len-1]='\0';
				len--;
			}
			
			
			char fname[200];
			strcpy(fname,s.c_str());
			int last=0;
			for(int i=0;fname[i];i++)
			{
				if(fname[i]=='/')
					last=i;
			}
			char newname[200];
			int ilen;
			for(ilen=0;fname[ilen+last];ilen++)
			{
				newname[ilen]=fname[ilen+last];
			}
			newname[ilen]=0;
			char genfile[101];
			strcpy(genfile,"../../indexed_pages");
			strcat(genfile,newname);
			
			
			
			int flag=0;
			
			ifstream filein(fname,ios::in);
//			cout<<fname<<endl;
			ofstream fout;
			if(!filein)
			{
				cout<<"Can't open file "<<s<<"\n";
				flag=1;
			}
			else
			{
				fout.open(genfile,ios::out);
				if(!fout)
				{
					cout<<"Couldn't create file "<<genfile<<endl;
					flag=1;
				}

			}

			PriorityQueue P;
			if(filein&&!flag)
				fout<<fname<<endl;
			while(filein&&!flag)
			{
				string ssin;
				getline(filein,ssin);
				stringstream ss(ssin);
				string temp;
				while(ss>>temp)
				{
					int l=temp.size();
					char t[101];
					strcpy(t,temp.c_str());
					while(!isalpha(t[l-1]))
					{
						t[l-1]='\0';
						l--;
					}
	
					if(!isalpha(t[0]))
					{
						continue;
					}
//					cout<<temp<<" ";
					P.push(t);
				}
			}
//			cout<<"File "<<fname<<" ends.\n";
//			P.display();
			if(!P.isEmpty()&&!flag)
			{
//				cout<<"NON Empty file "<<genfile<<"\n";
//				P.display(fout);
			}
			else if(!flag||P.isEmpty())
			{
				cout<<"Empty file "<<fname<<"\n";
				P.display();


				fout.close();
				flag=1;
				char delfile[200];
				strcpy(delfile,"rm ");
				strcat(delfile,genfile);
				system(delfile);

			}
			cout<<"Written in "<<genfile<<" successfully!! ";
			while(!P.isEmpty())
				P.pop();
			if(filein.is_open())
				filein.close();
			if(fout.is_open())
				fout.close();
			cout<<"And also closed it.\n";
		}
		i++;
		if(!(i%10000))
			cout<<i<<endl;
	}
	fin.close();
}
