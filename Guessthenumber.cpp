#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lower,upper;
    cout<<"Enter the lower_bound and upper_bound numbers"<<endl;
    cin>>lower>>upper;
    int random_num=rand()%(upper-lower+1);
    cout<<"the number to be guessed by the player is"<<random_num<<endl;
    cout<<"There are three levels in this game"<<endl
        <<"1st level is easy , you'll have 15 chances to guess the number"<<endl
        <<"2nd level is medium , you'll have 10  chances to guess the number"<<endl
        <<"3rd level is hard , you'll have only 5 chances to guess the number"<<endl<<endl<<endl
        <<"Enter the number 1 to play easy game or"<<endl
        <<"Enter the number 2 to play medium game or"<<endl
        <<"Enter the number 3 to play the hard game"<<endl<<endl;
    int level,guess_number;
    cin>>level;
    if(level==1)
    {
    	cout<<"Hey! player Guess the number"<<endl;
    	cin>>guess_number;
    	for(int i=1;i<=15;i++){
    		if(i>=15)
			{
				cout<<"Chance are completed , you lost the game"<<endl;
				break;
			}
    		else if(guess_number==random_num){
    			cout<<"You Won The Game!"<<endl;
    			break;
			}
    		else if(guess_number>random_num){
    			cout<<"The  number is less than the guess_number\n"
    				<<"Again Guess the number"<<endl;
				cin>>guess_number;
			}
			else if(guess_number<random_num){
    			cout<<"The  number is greater than the guess_number\n"
    				<<"Again Guess the number"<<endl;
    			cin>>guess_number;
			}
		}
	}
	
	else if(level==2)
    {
    	cout<<"Hey! player Guess the number"<<endl;
    	cin>>guess_number;
    	for(int i=1;i<=10;i++){
    		if(i>=10)
			{
				cout<<"Chance are completed , you lost the game"<<endl;
				break;
			}
    		else if(guess_number==random_num){
    			cout<<"You Won The Game!"<<endl;
    			break;
			}
    		else if(guess_number>random_num){
    			cout<<"The  number is less than the guess_number\n"
					<<"Again Guess the number"<<endl;
				cin>>guess_number;
			}
			else if(guess_number<random_num){
    			cout<<"The  number is greater than the guess_number\n"
					<<"Again Guess the number"<<endl;
				cin>>guess_number;
			}
			
		}
	}
	
	else if(level==3)
    {
    	cout<<"Hey! player Guess the number"<<endl;
    	cin>>guess_number;
    	for(int i=1;i<=5;i++){
    		if(i>=5)
			{
				cout<<"Chance are completed , you lost the game"<<endl;
				break;
			}
    		else if(guess_number==random_num){
    			cout<<"You Won The Game!"<<endl;
    			break;
			}
    		else if(guess_number>random_num){
    			cout<<"The  number is less than the guess_number\n"
					<<"Again Guess the number"<<endl;
				cin>>guess_number;
			}
			else if(guess_number<random_num){
    			cout<<"The  number is greater than the guess_number\n"
    				<<"Again Guess the number"<<endl;
    			cin>>guess_number;
			}
		}
	}
    
}