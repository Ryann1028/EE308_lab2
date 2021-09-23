#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stack>
using namespace std;

string keyword[32] = {
	"auto","break","case","char","const","continue","default","double",
	"do","else","enum","extern","float","for","goto","if","int","long",
	"register","return","short","signed","sizeof","static","struct",
	"switch","typedef","union","unsigned","void","volatile","while"
	};
	
//variables	
int keyword_num = 0;
int switch_num = 0;
int case_num[100] = {0};
int ifelse_num = 0;
int if_elseif_else_num = 0;
int mark = 0;

//functions
int Verify(string str, string keyword1);	
int Judge_letter(char str);			
void Lv1(string word);		
void Lv2(string word);		
void Lv34(string word);	 
	
int main ()
{
	string file_name;
	int lv;
	string temp;
	cout << "Please enter the address of the file: ";				
	cin >> file_name;						
	cout << "Please enter the level: ";
	cin >> lv;
	ifstream file(file_name.c_str(), ios::in);		
	
	
	while(getline(file, temp))			//Read line by line
	{
		istringstream is(temp);	
		string s;
		if(lv >= 3)                    
			Lv34(temp);
			
		while(is >> s){				//Determine if each word in each line is a keyword	
			if(lv >= 1)
				Lv1(s);
			if(lv >= 2)
				Lv2(s);
		}
	}
	
	if(lv >= 1)
		cout << endl << "total num = " << keyword_num << endl;
		
	if(lv >= 2){
		cout << "switch num = " << switch_num << endl;
		for(int j = 1; j <= switch_num; j++)
			cout << "case num of switch " << j << " = " << case_num[j] << endl;
	}
	
	if(lv >= 3){
		cout << "if-else num = " << ifelse_num << endl;
	}
	
	if(lv >= 4){
		cout << "if-elseif-else num = " << if_elseif_else_num;
	}
	
}


int Verify(string str, string keyword1)	
{
	int Judge_letter(char str);
	int location = str.find(keyword1, 0);
	int len = keyword1.length();	
	if(location != string::npos)
		return 1;
	else
		return 0;
}


void Lv1(string word)		
{
	for(int j = 0; j < 32; j++)			
	{
		if(Verify(word, keyword[j])){
			keyword_num++;
			break;
		}
	}
}
	
	
void Lv2(string word)		
{
	if(Verify(word, "switch") == 1)	{
		switch_num++;
	}
	
	if(Verify(word, "case") == 1){
		case_num[switch_num]++;
	}

}


void Lv34(string word)		
{
	if(Verify(word, "else if")){
		mark = 2;
	}
	else
	{
		if(Verify(word, "if")){
			mark = 1;
		}
		if(Verify(word, "else"))
		{
			if(mark == 1){
				ifelse_num++;
			}
			else	
			{
				if(mark == 2){
					if_elseif_else_num++;
				}
			}
		}
	}
}
