#include<iostream>
using namespace std;

class desc{
public:
desc(){
    cout<<"\n\t\t   ---WELCOME TO---"<<endl;                                       
    cout<< "\t,---.                         |        |  |" <<endl
    <<"\t|    ,---.,---.,---.,---.,---.|---     `--|"<<endl
    <<"\t|    |   ||   ||   ||---'|    |           |"<<endl
    <<"\t`---'`---'`   '`   '`---'`---'`---'       `"<<endl;

    cout<<endl<<endl;
    cout<<"---Rules---\n"<<endl;
    cout<<"1-Two Players:(Red-R  and Blue-B)"<<endl
    <<"2-Board Size is 6 rows and 7 columns"<<endl
    <<"3-A player wins if he/she is able to connect 4 dots successfully"<<endl
    <<"4-They can connect horizontally or diagonally or vertically"<<endl
    <<"5-The match is a draw if the matrix is filled completely"<<endl<<endl<<endl;

    cout<<"---How to Play---\n"<<endl
    <<"1- Game always starts with the player - 1 i.e. Red(R)."<<endl
    <<"2- In each step, each player can choose the column number in which they want to drop the ball."<<endl
    <<"3- Rows will be filled from bottom to top in any column"<<endl;

}

char wannaPlay(){
    cout<<"\n\n\tIF you want to Play Press Y/y or press anything else to exit"<<endl;
    char choose;
    cin>>choose;
    return choose;
}


};



class ManageGame{
    private:
    char arr[6][7];
    bool full=false;
    bool currentStat=false;
    int whoseTurn=1;
    int location=0;
    public:
    ManageGame()
    {
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                arr[i][j]='0';
            }
        }
    }
    void playGame()
    {
        if(currentStat==false){
            printArray();
            currentStat=true;
            full=checkArray();
        }
    while(full==false)
    {
        if(whoseTurn==1){
            cout<<"\nPlayer 1 :\nEnter Column number"<<endl;
            cin>>location;
            changeArray(location-1);
            whoseTurn=2;
            printArray();
        }
        if(whoseTurn==2){
            cout<<"\nPlayer 2 :\nEnter Column number"<<endl;
            cin>>location;
            changeArray(location-1);
            whoseTurn=1;
            printArray();
        }
        full=checkArray();
    }
    if(full==true){
        cout<<"This is a draw";
    }


    }
    //Print the array on screen
    void printArray(){
        for(int i=0;i<6;i++)
            {
                cout<<"----------------"<<endl;
                for(int j=0;j<7;j++)
                {
                    if(j==0){
                        cout<<"|";
                    }
                    if(arr[i][j]!='0'){
                        cout<<arr[i][j];
                    }
                    else{ cout<<" ";}
                    cout<<"|";
                }
                cout<<endl;

            }
    }

    //checks whether the array is full or not
    bool checkArray(){
        int numbers=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                if(arr[i][j]!='0'){
                    numbers++;
                }
            }
        }
        if(numbers==42){
            return true;
        }
        else{
            return false;
        }
    }


    //adds changes to array
    void changeArray(int j)
    {
        for(int i=0;i<5;i++){
            if(arr[i+1][j]!='0'){
                if(whoseTurn==1&&arr[i][j]!='B')
                {
                    arr[i][j]='R';
                    break;
                }
                else if(whoseTurn==2&&arr[i][j]!='A')
                {
                    arr[i][j]='B';
                    break;
                }
            }
            else if((i+1==5)&& (arr[i+1][j]=='0')){
                if(whoseTurn==1)
                {
                    arr[i+1][j]='R';
                    break;
                }
                else
                {
                    arr[i+1][j]='B';
                    break;
                }
            }
        }
    }



};


class Game{
    private:
        ManageGame gameManager;
    public:
    desc des;
    char choose;
    Game(){
        choose=des.wannaPlay();
    }
    void startGame(){
        if(choose=='y'||choose=='Y')
        {
            cout<<"\nPlaying Game\n";
            gameManager.playGame();

        }
        else
        {
            cout<<"ended game bye";
        }
    }

};

int main()
{
    Game game;
    game.startGame();
    // char choose=des.wannaPlay();
    // if(choose=='y'||choose=='Y'){
    //     cout<<"\nPlaying Game";
    // }else{
    //     cout<<"ended game bye";
    // }
    return 0;
}