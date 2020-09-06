#include<bits/stdc++.h>//=+
#include <iostream>

using namespace std;

bool isplaced(int board[8][8],int n,int curr_row,int curr_col,int move_no)
{
    if(board[curr_row][curr_col]==0 && curr_col>=0 &&curr_row>=0 && curr_col<n && curr_row<n)
    {
    return true;
    }
    return false;

}

 bool  solveknight(int board[8][8],int n,int curr_row,int curr_col,int move_no)
{
            if(move_no==n*n)
         {
             return true;
         }
       int row_dir[]={2,1,-1,-2,-2,-1,1,2};
       int col_dir[]={1,2,2,1,-1,-2,-2,-1};

        for(int i=0;i<8;i++)
       {
            int next_row=curr_row+row_dir[i];
            int next_col= curr_col+col_dir[i];
           if(isplaced(board,n,next_row,next_col,move_no)==true)
          {
              board[next_row][next_col]=move_no+1;
            bool issuccesful=solveknight(board,n,next_row,next_col,move_no+1);
            if(issuccesful==true) return true;
            else
            board[next_row][next_col]=0;
        }
        }
        return false;
   }
   void print(int board[8][8],int n)
   {
       for(int i=0;i<8;i++)
       {

        for(int j=0;j<8;j++)
       {
           cout<<board[i][j]<<" ";

       }
       cout<<endl;

       }

   }

int main()
{
    int board[8][8]={0};
    int n;
    cin>>n;
    board[0][0]=1;
    bool ans=solveknight(board,n,0,0,1);
    if(ans==true)
    {
        print(board,n);
    }
}
