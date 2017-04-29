#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


class cstrlist{
private:
	string mStr; 
	vector<string> mstrlist;
	char mDelimiter;
	bool mIsReady;
	int error;
	string errorText;
private:
	void split();
public:
	int getError();
	void printError();
	void getDelimiter(char delimiter);
	void getDelimiterText(const string sDelimiterText);
	void printString();

public:
	cstrlist(){mIsReady = false;errorText ="";error =0;}
};

int cstrlist::getError(){
	if(error)
		return 1;
	return 0;
}

void cstrlist::printError(){
	cout<<errorText<<endl;
}
void cstrlist::getDelimiter(const char delimiter){
	mDelimiter = delimiter;
	mIsReady = true;
}

void cstrlist::getDelimiterText(const string sDelimiterText){
	mStr = sDelimiterText;
	if(mIsReady){
		split();
	}
}

void cstrlist::split(){
	int index =0;
	string tstr;
	if(mStr.size() <=0){
		error = 1;
		errorText = "error:text size < 0;";
	}
	for(auto cnt : mStr){

		if(cnt != mDelimiter){
			tstr += cnt;
		}else{
			mstrlist.push_back(tstr);
			tstr ="";
		}
	}
}

void cstrlist::printString(){
	for(auto cnt: mstrlist){
		cout<<cnt<<endl;
	}
}
int main(int argc,char** argv){
	cstrlist str1;
	str1.getDelimiter(';');
	str1.getDelimiterText("hello;world;");
	if(str1.getError())
	{
		str1.printError();
	}
	str1.printString();
	return 1;
}