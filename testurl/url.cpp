#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main(){
    int num = 20000;
    string url = "http://127.0.";
    fstream ofs;
    ofs.open("urilist.txt",ios::out);
    for(int i = 0;i <255;i++){
        if(num <= 0){
            break;
        }
        for(int j = 0;j < 255;j++){
            ofs << url << i << "." << j <<"/metrics"<< endl;
            num--;
        }
    }

    return 0;
}