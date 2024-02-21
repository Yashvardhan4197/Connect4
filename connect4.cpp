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
    int winCond=0;
    public:
    ManageGame()
    {
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                arr[i][j]='0';
            }
        }
    }
    char playGame()
    {
        if(currentStat==false){
            printArray();
            currentStat=true;
            full=checkArray();
        }
    while(full==false&&winCond==0)
    {
        if(whoseTurn==1){
            cout<<"\nPlayer 1 :\nEnter Column number"<<endl;
            cin>>location;
            if(location<7&&location>=0)
            {
            changeArray(location-1);
            whoseTurn=2;
            printArray();
            winCond=WinningStatus();
            if(winCond==1){break;}
            }
            else{
                cout<<"\n___Invalid Move/Column___ Try Again"<<endl;
            }
        }
        if(whoseTurn==2){
            cout<<"\nPlayer 2 :\nEnter Column number"<<endl;
            cin>>location;
            if(location<7&&location>=0)
            {
            changeArray(location-1);
            whoseTurn=1;
            printArray();
            winCond=WinningStatus();
            if(winCond==2){break;}
            }
            else{
                 cout<<"\n___Invalid Move/Column___ #Try Again"<<endl;
            }
        }
        full=checkArray();
    }
    if(full==true){
        cout<<"This is a draw";
    }
    else if(winCond==1){
        cout<<"Player 1 Won"<<endl;
    }
    else if(winCond==2){
        cout<<"Player 2 won"<<endl;
    }
    else if(winCond==0){
        cout<<"Game Quit"<<endl;
    }
    cout<<"----To Play Again Press Y or anything else to end game----"<<endl;
    char playAgain;
    cin>>playAgain;
    return playAgain;

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


    int WinningStatus(){
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                int stat=WinningStatInterior(i,j);
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

    int WinningStatInterior(int i,int j){
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
            if(j<6){
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
                cout<<"Status of winning is: 1"<<endl;
                return 1;
            }
            else{
                cout<<"Status of winning is: 1"<<endl;
                return 2;
            }
        }

        //vertical
        temp=true;
        num=1;
        k=1;
        while(temp==true||num<4){
            if(arr[i+k][j]==pos){
                num++;
            }
            else{
                temp=false;
                break;
            }
            k++;
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
        
        // temp=true;
        // num=1;
        // k=1;
        // while(temp==true||num<4){
        //     if(arr[i+k][j+k]==pos){
        //         num++;
        //     }
        //     else{
        //         temp=false;
        //         break;
        //     }
        //     k++;
        // }
        // if(num==4){
        //     if(pos=='R'){
        //         return 1;
        //     }
        //     else{
        //         return 2;
        //     }
        // }

        //diagonal right to left
        temp=true;
        k=1;
        num=1;
        while(temp==true||num<4){
            if(arr[i+k][j-k]==pos){
                num++;
            }
            else{
                temp=false;
                break;
            }
            k++;
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
            while(playing=='y'||playing=='Y'){
            ManageGame gameManager;
            playing=gameManager.playGame();
            }
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
    return 0;
}