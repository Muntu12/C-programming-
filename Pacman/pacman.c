#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//universal variables
  char pre_input;//stores the previous input from the user
  int pac_pos_x = 1;//x position of pac man
  int pac_pos_y = 1;//ya position of pac man
  int player_life=1;//player life
  int player_point=0;//total points
 //x and y location of the ghost
  int blinky_x=8;
  int blinky_y=1;
  int pinky_x=28;
  int pinky_y=7;
  int inky_x=35;
  int inky_y=5;
  //The game board intilization
  char board[21][72]= {
"#######################################################################",
"#C......G.............................................................#",
"########..#.....#..#######.###...#####...###.#######..#.....#..########",
"       #..#.....#..#.....#.#...............#.#.....#..#.....#..#       ",
"       #..#.....#..#.....#.#...............#.#.....#..#.....#..#       ",
"       #..#.....#..#.....#.#.......G.......#.#.....#..#.....#..#       ",
"       #..#.....#..#.....#.#...............#.#.....#..#.....#..#       ",
"       #..#.....#..#.....#.#G..............#.#.....#..#.....#..#       ",
"########..#######..#.....#.###...#####...###.#.. ..#..#######..########",
"#.....................................................................#",
"#................#######.....#############.....#######................#",
"#..........#.....#.....#.....#...........#.....#.....#.....#..........#",
"########...#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#...########",
"       #...#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#...#       ",
"       #...#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#...#       ",
"       #...#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#...#       ",
"       #...#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#...#       ",
"       #...#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#..#...#       ",
"########......#..#..#..#..#..#..#..#..#..#..#..#..#..#..#......########",
"#.............#.....#.....#.....#.....#.....#.....#.....#.............#",
"#######################################################################"};
// function for the display of map and character movement
char map(char pac_move){
  char temp;
  int x,y;
  switch (pac_move)
      { case 'w':{
         system("cls");
         x = 0;
         y =-1;}
         break;
       case 'a':{
         system("cls");
         x =-1;
         y = 0;}
         break;
       case 's':{
         system("cls");
         x = 0;
         y = 1;}
         break;
       case 'd':{
        system("cls");
         x = 1;
         y = 0;}
        break;
       default:{}
     }
   // swaping of two variables
    if (board[pac_pos_y+y][pac_pos_x+x]!='#')// to check if the position mosved to is a wall or not
    { if (board[pac_pos_y+y][pac_pos_x+x]!='G'){// to check if the pac man has collided with the ghost
        if (board[pac_pos_y+y][pac_pos_x+x]!='.'){//to check if the pac man has collected any coins
     temp =board[pac_pos_y+y][pac_pos_x+x];
     board[pac_pos_y+y][pac_pos_x+x]=board[pac_pos_y][pac_pos_x];
     board[pac_pos_y][pac_pos_x]=temp;
     pac_pos_y=pac_pos_y+y;
     pac_pos_x=pac_pos_x+x;}
     else{player_point++;
        temp =' ';
        board[pac_pos_y+y][pac_pos_x+x]=board[pac_pos_y][pac_pos_x];
        board[pac_pos_y][pac_pos_x]=temp;
        pac_pos_y=pac_pos_y+y;
        pac_pos_x=pac_pos_x+x;

          }}
     else{player_life--;}
     }
     // simple matrix print
  for (int y=0;y<21;y++)
 {
   printf("\n");
     for(int x=0;x<72;x++)
     {
       printf("%c",board[y][x]);
     }
  }
   printf("\nCURRENT LIFE:%d,TOTAL POINTS:%d",player_life,player_point);
  pre_input=pac_move;
    return'0';
}
// movement of the first ghost
// movement type:set path
char blinky_mov(){
int x,y;
char temp;
if (blinky_y != 19&&blinky_x==8){
    x=0;
    y=1;
}
 else if (blinky_y == 19 && blinky_x!=13&&blinky_x!=19&&blinky_x!=25&&blinky_x!=31&&blinky_x!=37&&blinky_x!=43&&blinky_x!=49&&blinky_x!=55&&blinky_x!=62){
      x=1;
      y=0;}
 else if (blinky_y != 11&&(blinky_x==13||blinky_x==19||blinky_x==25||blinky_x==31||blinky_x==37||blinky_x==43||blinky_x==49||blinky_x==55))
 {
     x=0;
     y=-1;
 }
  else if (blinky_y==11&& blinky_x!=16&&blinky_x!=22&&blinky_x!=28&&blinky_x!=34&&blinky_x!=40&&blinky_x!=46&&blinky_x!=52&&blinky_x!=58&&blinky_x!=62){
      x=1;
      y=0;
  }
  else if (blinky_y != 19&&(blinky_x==16||blinky_x==22||blinky_x==28||blinky_x==34||blinky_x==40||blinky_x==46||blinky_x==52||blinky_x==58))
 {   x=0;
     y=1;}
 else if (blinky_y!=1&&blinky_x==62){
     x=0;
     y=-1;}
   if(blinky_y==1&& blinky_x!=8){
    x=-1;
    y=0;}

 if (board[blinky_y+y][blinky_x+x]!='#')//check if the position moved to is a wall or not
   {if (board[blinky_y+y][blinky_x+x]=='C')// check if the ghost has collided with the pac man
   {player_life=player_life-1;}
     temp =board[blinky_y+y][blinky_x+x];
     board[blinky_y+y][blinky_x+x]=board[blinky_y][blinky_x];
     board[blinky_y][blinky_x]=temp;
     blinky_y=blinky_y+y;
     blinky_x=blinky_x+x;}}
// movement of the second ghost
//movement type:set path
char pinky_mov(){
int x,y;
int temp;
if(pinky_y!=3&&pinky_x==28){
    x=0;
    y=-1;}
 else if(pinky_y==3&&pinky_x!=42){
    x=1;
    y=0;
 }
 else if (pinky_y !=7&&pinky_x==42){
    x=0;
    y=1;
 }
 else if (pinky_y == 7&& pinky_x!=28){
 x=-1;
 y=0;}
  if (board[pinky_y+y][pinky_x+x]!='#') //check if the position moved to is a wall or not
   {if (board[pinky_y+y][pinky_x+x]=='C')// check if the ghost has collided with the pac man
    {player_life=player_life-1;}
     temp =board[pinky_y+y][pinky_x+x];
     board[pinky_y+y][pinky_x+x]=board[pinky_y][pinky_x];
     board[pinky_y][pinky_x]=temp;
     pinky_y=pinky_y+y;
     pinky_x=pinky_x+x;}
}
//movement of the third ghost
// movement type chase pac man
char inky_mov(int i){
int x,y,is_even;
char temp;
if(i%2==0){is_even=1;}//checking is the current time frame is even or not
else{is_even=0;}
 x=pac_pos_x-inky_x; // finding the difference between the x position of ghost and pac man
 y=pac_pos_y-inky_y;// finding the difference between the y position of ghost and pac man
if(is_even==0) // moving in x axis if interval is odd
{if(x<0){x=-1;}// setting x to 1 or -1
 else{x=1;}}
else{x=0;}
if(is_even==1){//moving in y axis if interval is even
 if(y<0){y=-1;}//setting y to 1 or -1
 else{y=1;}}
 else{y=0;}
  if (board[inky_y][inky_x+x]!='#'){ // checking for wall
    temp =board[inky_y][inky_x+x];
     board[inky_y][inky_x+x]=board[inky_y][inky_x];
     board[inky_y][inky_x]=temp;
     inky_y=inky_y;
     inky_x=inky_x+x;
     if(temp=='C'){player_life--;} // detecting player collision
  if (board[inky_y+y][inky_x]!='#'){ // checking of wall
     temp =board[inky_y+y][inky_x];
     board[inky_y+y][inky_x]=board[inky_y][inky_x];
     board[inky_y][inky_x]=temp;
     inky_y=inky_y+y;
     inky_x=inky_x;
     if(temp=='C'){player_life--;}//detecting player collision
  }}}
char ghost_mov(int i){ // calling all movement function in a singular place
   blinky_mov();
   pinky_mov();
   inky_mov(i);}
int win(){
    char win_p[9][66]={ {"######                  ######      ######      #######    #######"},
                      {" ######                ######        ####       ########   #######"},
                      {"  ######              ######          ##        #########  #######"},
                      {"   ######     ##     ######                     ########## #######"},
                      {"    ######   ####   ######          ######      ##################"},
                      {"     ###### ###### ######           ######      #######  #########"},
                      {"      ########  ########            ######      #######   ########"},
                      {"       ######    ######             ######      #######    #######"},
                      {"        ####      ####              ######      #######    #######"}};

    system("cls");
    for (int y=0;y<9;y++) //printing win
 {
   printf("\n");
     for(int x=0;x<66;x++)
     {
       printf("%c",win_p[y][x]);
     }
  }}
int lose(){
    char lose_p[10][66]={{"######        ########## ############ ###############"},
                        {"######        ########## ###########  ###############"},
                        {"######        ########## #####        #####          "},
                        {"######        ##      ## #####        #####          "},
                        {"######        ##      ## ###########  ###############"},
                        {"######        ##      ## ###########  ###############"},
                        {"######        ##      ##       #####  ######         "},
                        {"############# ##########       #####  ######         "},
                        {"############# ########## ###########  ###############"},
                        {"############# ########## ###########  ###############"}};

     system("cls");
     for (int y=0;y<11;y++)
 {
   printf("\n");   // printing lose
     for(int x=0;x<53;x++)
     {
       printf("%c",lose_p[y][x]);
     }

    }}

int main(){
  // declarration of the variables
  int index=0; //interval variable
  char pac_mov;//input variable
  map('w'); //map initilization
  while(1)//game loop
  { sleep(0.9);//lag for better game play
  ghost_mov(index);//calling the ghost movement the the interval
   if (kbhit()){//checking if an input has been made
   pac_mov=getch();//if yes then using it to move the pac man
  //user input w,a,s,d
    map(pac_mov);
    }
    else {map(pre_input);} // if no then moving the pac man using the old input
  if (player_point>=815){ // checking if player has won the game
        win();
        goto end;
    }
   if(player_life<=0){ //checking if player has lost the game
        lose();
        goto end;
    }
    index++;
  }
  end:
  return 0;
  }
