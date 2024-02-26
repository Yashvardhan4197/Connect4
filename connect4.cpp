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

class PrintBoard{
public:

void printArray(char arr[][7]){
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



};

class CheckArray{

public:
bool check(char arr[][7]){
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


};



class WinCondition{

private:
public:

int WinningStatus(char arr[][7]){
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                int stat=WinningStatInterior(i,j,arr);
                if(stat==1){
                    return 1;
                }
                else if(stat==2){
                    return 2;
                }
            }
        }
        return 0;
    }

    int WinningStatInterior(int i,int j,char arr[][7]){
        int num=1;
        int k=1;
        bool temp=true;
        char pos;
        //set pos value
        if(arr[i][j]=='R'){
            pos=arr[i][j];
        }
        else if(arr[i][j]=='B'){
            pos=arr[i][j];
        }
        else{ return 0;}
        //horizontal
        temp=true;
        num=1;
        k=1;
        while(temp==true||num<4){
            //I AM CHECKING THE OUT OF BOUNDS CONDITION HERE
            if(j+k<7){
            if(arr[i][j+k]==pos){
                num++;
            }
            else if(arr[i][j+k]!=pos){
                temp=false;
                break;
            }
            k++;
            }else{
                break;
            }
        }
        //check if win then return
        if(num==4){
            if(pos=='R'){
                return 1;
            }
            else{
                return 2;
            }
        }

        //vertical
        temp=true;
        num=1;
        k=1;
        while(temp==true||num<4){
            //I AM CHECKING THE OUT OF BOUNDS CONDITION HERE
            if(i+k<6){
            if(arr[i+k][j]==pos){
                num++;
            }
            else{
                temp=false;
                break;
            }
            k++;
            }
            else{
                break;
            }
        }
        //check if win then return
        if(num==4){
            if(pos=='R'){
                return 1;
            }
            else{
                return 2;
            }
        }

        //diagnol left to right

        temp=true;
        num=1;
        k=1;
        while(temp==true||num<4){
            //I AM CHECKING THE OUT OF BOUNDS CONDITION HERE
            if(i+k<6&&j+k<7){
            if(arr[i+k][j+k]==pos){
                num++;
            }
            else{
                temp=false;
                break;
            }
            k++;
            }else
            {
                break;
            }
        }
        if(num==4){
            if(pos=='R'){
                return 1;
            }
            else{
                return 2;
            }
        }

        //diagonal right to left
        temp=true;
        k=1;
        num=1;
        while(temp==true||num<4){
            //I AM CHECKING THE OUT OF BOUNDS CONDITION HERE
            if(i+k<6&&j-k>-1){
            if(arr[i+k][j-k]==pos){
                num++;
            }
            else{
                temp=false;
                break;
            }
            k++;
            }else
            {
                break;
            }
        }
        if(num==4){
            if(pos=='R'){
                return 1;
            }
            else{
                return 2;
            }
        }
        return 0;
    }

};


class ChangeArray{
public:

int Refresh(char (&arr)[6][7],int j,int whoseTurn){
     for(int i=0;i<5;i++){
            if(arr[i+1][j]!='0'){
                if(whoseTurn==1&&arr[i][j]!='B')
                {
                    if(arr[i][j]!='0')
                    {
                        cout<<"\n---Retry Already Full---"<<endl;
                         return 1;
                    }
                    else
                    {
                    arr[i][j]='R';
                    return 2;
                    break;
                    }
                    return 2;
                }
                else if(whoseTurn==2&&arr[i][j]!='A')
                {
                    if(arr[i][j]!='0')
                    {
                        cout<<"\n---Retry Already Full---"<<endl;
                        return 2;
                    }
                    else{
                    arr[i][j]='B';
                    return 1;
                    break;
                    }
                    return 1;
                }
            }
            else if((i+1==5)&& (arr[i+1][j]=='0')){
                if(whoseTurn==1)
                {
                    arr[i+1][j]='R';
                    return 2;
                    break;
                }
                else
                {
                    arr[i+1][j]='B';
                    return 1;
                    break;
                }
            }
        }


}
};

class GameManager{
    private:
    //Objects-
    PrintBoard printBoard;
    CheckArray checkArray;
    ChangeArray changeArray;
    WinCondition isWin;


    char arr[6][7];
    bool full=false;
    bool currentStat=false;
    int whoseTurn=1;
    int location=0;
    int winCond=0;
    public:
    GameManager()
    {
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                arr[i][j]='0';
            }
        }
    }

    //Game Manager only manages the play Game-
    char playGame()
    {
        int done=0 ;
        if(currentStat==false){
            printBoard.printArray(arr);
            currentStat=true;
            full=checkArray.check(arr);
        }
    while(full==false&&winCond==0)
    {
        if(whoseTurn==1){
            cout<<"\nPlayer 1 :\nEnter Column number"<<endl;
            cin>>location;
            //Removed Bugs-
            if(location<8&&location>0)
            {
            done=changeArray.Refresh(arr,location-1,whoseTurn);
            if(done==2){
            whoseTurn=2;
            }
            printBoard.printArray(arr);
            winCond=isWin.WinningStatus(arr);
            if(winCond==1){break;}
            }
            else{
                cout<<"\n___Invalid Move/Column___ Try Again"<<endl;
            }
        }
        if(whoseTurn==2){
            cout<<"\nPlayer 2 :\nEnter Column number"<<endl;
            cin>>location;
            if(location<8&&location>0)
            {
            done=changeArray.Refresh(arr,location-1,whoseTurn);
            if(done==1){
            whoseTurn=1;
            }
            printBoard.printArray(arr);
            winCond=isWin.WinningStatus(arr);
            if(winCond==2){break;}
            }
            else{
                 cout<<"\n___Invalid Move/Column___ #Try Again"<<endl;
            }
        }
        full=checkArray.check(arr);
    }
    if(winCond==1){
        cout<<"\n\t--Player 1 Won--"<<endl;
    }
    else if(winCond==2){
        cout<<"\n\t--Player 2 won--"<<endl;
    }
    else if(winCond==0){
        cout<<"Game Quit"<<endl;
    }
    else if(full==true){
        cout<<"\n\t--This is a draw--\n";
    }
    cout<<"----To Play Again Press Y or anything else to end game----"<<endl;
    char playAgain;
    cin>>playAgain;
    return playAgain;

    }

};


class Game{
    private:
        //ManageGame gameManager;
    public:
    desc des;
    char choose;
    Game(){
        choose=des.wannaPlay();
    }
    void startGame(){
        char playing='y';
        if(choose=='y'||choose=='Y')
        {
            cout<<"\nPlaying Game\n";
            while(playing=='y'||playing=='Y')
            {
                GameManager gameManager;
                playing=gameManager.playGame();
            }
        }
        //Ending game
        cout<<"\t---------------------"<<endl
        <<"\t|   Ended Game Bye!  |\t   "<<endl
        <<"\t---------------------"<<endl;
    }

};

int main()
{
    Game game;
    game.startGame();
    return 0;
}