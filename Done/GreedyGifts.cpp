/*
ID: dhairya6
TASK: gift1
LANG: C++
*/



#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

unordered_map<string, int> umap;


void updateGifts(string gifter, int totalAmount, int numRecipients, vector<string>recipients){
    int giftAmount = round(totalAmount / numRecipients);
    int remainder = totalAmount % numRecipients;
    umap[gifter] += remainder;
    umap[gifter] -= totalAmount;
    for (int i = 0; i < numRecipients; i++){
        string recipient = recipients[i];
        umap[recipient] += giftAmount;
    }
    
}

int main(){
    ifstream input("file.txt");
    int peopleAmount = 0;
    vector<string> peopleOrder;
    string str; 
    getline(input, str);
    peopleAmount = stoi(str);
    for(int i = 0;i < peopleAmount; i++){
        getline(input, str);
        umap[str] = 0;
        peopleOrder.push_back(str);
    }
    string gifter;
    int amount;
    int numPeople;
    vector<string> peopleList;  
    while(!input.eof()){
        getline(input, str);
        gifter = str;
        input >> amount >> numPeople;
        getline(input, str);
        for(int i = 0;  i < numPeople; i++){
            getline(input, str);
            peopleList.push_back(str);
        }
        if (numPeople > 0){
            updateGifts(gifter,amount,numPeople, peopleList); peopleList.clear();
        }
    }
    for(auto i : peopleOrder){
        cout << i << " " << umap[i] << endl;
    }
    input.close();
    
    return 0;
}