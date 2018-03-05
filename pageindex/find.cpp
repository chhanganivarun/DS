#include<fstream>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;


/*
int bSearch(vector<string> a ,long long l,long long r,string key)
{
	if(r<l)
		return -1;
	if(a[(l+r)/2]==key)
		return (l+r)/2;
	if(a[(l+r)/2]>key)
		return bSearch(a,l,(l+r)/2-1,key);
	return bSearch(a,(l+r)/2+1,r,key);
}

int binSearch(vector<string> v,long long size,string key)
{
	if(!v.size())
		return 0;
//	cout<<"Trying..."<<v.size()<<"\n";
	return bSearch(v,0,v.size(),key)!=-1;
}
*/
int main(int argc, char *argv[])
{
//	cout<<"Enter Search Query:";
	vector<string> query;
	vector<long long> total_count;
	long long total_all_found=0;
//	cin>>query;
	for(int i=1;i<argc;i++)
	{
//		string s=argv[i];
		query.push_back(argv[i]);
		total_count.push_back(0);
	}
	cout<<"Input taken\n";
	clock_t start,end;
	start=clock();
	ifstream fin("list_indexed.txt",ios::in);

	if(!fin)
	{
		cout<<"Input file not found!!\nPlease run the complete process again!\n";
		return -1;
	}
	string temp;
	getline(fin,temp);
	while(fin && getline(fin,temp))	
	{
		string curr_filein=temp,curr_filename;
		;

		ifstream filein(curr_filein.c_str(),ios::in);
		if(!filein)
		{
//			cout<<"Input File corrupted!\ncant open"<<curr_filein.c_str()<<endl;
//			return -2;
		}
		getline(filein,curr_filename);
		string s;
		vector<string> svect;
		while(getline(filein,s))
		{
			svect.push_back(s);
//			cout<<s<<endl;
		}
//		cout<<"Processing binSearch for file "<<curr_filename<<"\n";
		int flag=1;
		for(int i=0;i<argc-1;i++)
		{
			if(binary_search(svect.begin(),svect.end(),query[i]))
			{
//				cout<<curr_filename<<endl;
				total_count[i]++;
//				cout<<"Current Count:"<<total_count[i]<<endl;
			}
			else
				flag=0;
		}
		if(flag)
			total_all_found++;
		filein.close();
	}
	cout<<"Successfull\n";
	fin.close();
	end=clock();
	for(int i=0;i<argc-1;i++)
	{
		cout<<"For input String "<<query[i]<<"\n";
		cout<<"Found in "<<total_count[i]<<" files\n";
	}
	cout<<"All inputs found in "<<total_all_found<<" files!\n";
	cout<<"Done.\nThe Query took "<<((double)end-start)/(CLOCKS_PER_SEC)<<" seconds!\n";
}
