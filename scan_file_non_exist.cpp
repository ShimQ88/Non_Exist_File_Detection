//g++ scan_file_non_exist.cpp -o scan_file_non_exist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <glob.h>
#include <cstring>
using namespace std;

int main(){
	glob_t glob_result;
	int delimiter=0;
	string line;
	ofstream final_output;
	final_output.open("final_output_rodents.txt");//output file
    char *path=new char[50];

    strcat(path,"/home/kyu/Desktop/rodents_data/*");//the folder path needs to scan (absolute path need to change)

	glob(path,GLOB_TILDE,NULL,&glob_result);
	int the_number_of_files=glob_result.gl_pathc-1;
	cout<<"the_number_of_files: "<<the_number_of_files<<endl;
    ifstream load;
	load.open("rodents_NACTI_ListofImages.txt");//The path of list file (absolute path need to change)
	bool isfound=false;
	
	if (load.is_open()){
		string line;
		while ( getline (load,line) ){
			// cout<<"going"<<endl;
			string temp_line=line;
			while(delimiter!=-1){
		    	delimiter = temp_line.find('/');
		    	temp_line = temp_line.substr(delimiter+1);
		    }
			for(unsigned int j=0; j<the_number_of_files; j++){
				string temp=glob_result.gl_pathv[j];
				delimiter=0;
				while(delimiter!=-1){
			    	delimiter = temp.find('/');
			    	temp = temp.substr(delimiter+1);
			    }
			    delimiter=0;
			    // cout<<"temp: "<<temp<<endl;
			    // cout<<"temp_line: "<<temp_line<<endl;
			    // getchar();
				if(temp.compare(temp_line)==0){
					isfound=true;
				}
			}
			// cout<<"line: "<<line<<endl;
			if(isfound==true){
				
			}else{
				cout<<"fine the list which does not exist"<<endl;
				// getchar();
				final_output<<line;
				final_output<<endl;	
			}
			isfound=false;
			
		}
	}
	load.close();
	    
	    // cout<<"temp: "<<temp<<endl;
		// cout<<"glob_result.gl_pathv[j]: "<<glob_result.gl_pathv[j]<<endl;
	


 //    if (load.is_open()){
	//     while ( getline (load,line) ){
	//     	while(delimiter!=-1){
	//     		delimiter = line.find('/');
	//     		line = line.substr(delimiter+1);
	//     	}
	//     	delimiter=0;
	//     	save<<line;
	//     	save<<"\n";
	//     }
	//     load.close();
	// }

}