#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void findMinMax();
void constructor(int a, int b);
int getIndex(int data);
void printSortData();

static int MIN, MAX, lastIndex, SIZE;
static int BucketAry[1], myArray[1];
static string inputTxt, outputTxt;

    int main(int argc, char** argv){
	
	inputTxt = argv[1];
	outputTxt = argv[2];

	findMinMax();
	constructor(MIN, MAX);	
	ifstream myFile;
	myFile.open(inputTxt);
	
	string line;
	int index = 0;
	int data = 0;

	
	for(int i=0; i < SIZE; i++){
 	    BucketAry[i]=0; 
	}
	
	if (myFile.is_open()){
	    while(getline(myFile, line)){
		int input = atoi(line.c_str());
		data = input;
		index = getIndex(data);
		BucketAry[index]++;
	    }//while
	}//if
	
	printSortData();
	cout<<"he"<<endl;
	return 0;
	

}


    void findMinMax(){ 
	ifstream inFile;
	inFile.open(inputTxt);
	string line;
	int index = 0;
	int input;
	
	if (inFile.is_open()){
	    while(getline(inFile,line)){	
		input = atoi(line.c_str());		
	
		if (input < 0){
		    cout << "ERROR: INPUT LESS THAN ZERO" << endl;
		    exit(0);
		}//if		

		myArray[index] = input;		
		index++;
		}
		
	}//if 
	inFile.close();
   	
	int maximum = myArray[0];
	int minimum = myArray[0];

	for(int i = 0; i < index; i++){
	    if (myArray[i] > maximum){
		maximum = myArray[i];
	    }else if (myArray[i] < minimum){
		minimum = myArray[i];
	    }
	}//for

	MAX = maximum;
	MIN = minimum;

	}

    void constructor(int min, int max){
	int size1 = max - min + 1;
	BucketAry[size1];
	lastIndex = size1;
	SIZE = size1;
    }

    int getIndex(int data){
	return data - MIN;
    }

    void printSortData(){
	ofstream file;
	file.open(outputTxt);

	file << "Project01 in C++\n Written from cp1.cpp \n By Kyeongmin Ha(23085422)" << endl;

	for (int i = 0; i < SIZE; i++ ){
	    if(BucketAry[i] != 0){
		while(BucketAry[i] != 0){
		    int output = i+MIN;
		    file << output<< endl;
                   BucketAry[i]--;
		}//while
	    }//if
	}//for
	file.close();
    }


