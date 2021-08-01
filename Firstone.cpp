#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
void play(string ans,int max_score){
   int score=0; 
   if(ans=="N"||ans=="n"){
       cout<<"Cool, See you later"<<endl<<"Bye"<<endl;
       if(max_score==0)
       cout<<"You didn't play the game so no score to show"<<endl;
       else
       cout<<"Your best score is"<<" "<<max_score<<"."<<endl<<"See you later.";
   }
   else if(ans=="Y"||ans=="y"){
       int rand_num,input,range;
       cout<<"Choose the range of numbers you want"<<endl;
       cin>>range;
       srand(time(0));
       rand_num=(rand()%range)+1;
       cout<<"Choose a number between 1 & "<<range<<"."<<endl;
       cin>>input;
       while(input<1||input>range){
        cout<<"Choose a valid number in the given range."<<endl;
        cout<<"Choose a number between 1 &"<<range<<"."<<endl;
        cin>>input;
       }
       score++;
       while(input!=rand_num){
           score++;
           if(input<rand_num){
            cout<<"Choose Larger Number"<<endl;
            cin>>input;
           }
           else{
            cout<<"Choose Smaller Number"<<endl;
            cin>>input;
           }
       }
       if(input==rand_num){
            cout<<"Congratulation! You got it right in "<<score<<" attempts"<<endl;
            if(max_score==0)
            max_score=score;
            else
            max_score=min(score,max_score);
            // cout<<"Your best score is"<<" "<<max_score<<"."<<endl;
            cout<<"Do you wanna play some more?"<<endl;
            cin>>ans;
            play(ans,max_score);
           }
   }
   else{
        cout<<"Answer in Y or N only"<<endl;
        cout<<"You wanna play?"<<endl;
        cin>>ans;
        play(ans,max_score);
   }
}
int main(){
    string name,ans;
    int max_score=0;
    cout<<"What's Your Name"<<endl;
    cin>>name;
    cout<<"Hello"<<" "<<name<<"!";
    cout<<"You Want to play the game? (Y/N)"<<endl;
    cin>>ans;
    play(ans,max_score);
    return 0;
}