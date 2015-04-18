#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;
void Sudoku::GiveQuestion(){
int qmap[144]={0,0,6,0,0,0,9,5,0,-1,-1,-1,0,7,0,0,5,0,0,0,4,-1,-1,-1,9,0,1,0,0,0,8,0,0,-1,-1,-1,-1,-1,-1,0,0,2,0,0,0,9,0,6,-1,-1,-1,0,8,0,1,0,0,0,2,0,-1,-1,-1,0,0,6,0,0,0,0,7,0,1,0,0,0,4,0,-1,-1,-1,0,9,0,0,0,4,0,6,0,-1,-1,-1,1,0,7,0,9,0,0,1,0,-1,-1,-1,0,8,0,0,0,2,-1,-1,-1,0,4,0,5,0,0,7,0,0,-1,-1,-1,0,0,9,9,0,2,0,6,0,-1,-1,-1,0,1,0,0,0,0};
srand((unsigned)time(NULL));
int table[9]={1,2,3,4,5,6,7,8,9};   //  use random to change the number
for(int i=0;i<18;i++){
int b=rand()%9;
int tem=table[b];
table[b]=table[i%9];
table[i%9]=tem;
}


for(int i=0;i<144;i++){
if(qmap[i]==0||qmap[i]==-1){out[i]=qmap[i];}  //use table to change 
else{
out[i]=table[qmap[i]-1];
}
}
cout<<endl;
output();


}




void Sudoku::ReadIn(){
        int num=0;
        for(int i=0;i<144;i++){
                cin>>num;
                question[i]=num;

        }


}
int Sudoku:: questiontest(){

        for(int j=0;j<144;j++){        //test the question is solveable or not
                if(question[j]<=0)continue;


                int x=j%12;
                int y=j/12;
                int a=x/3;
                int b=y/3;
                for(int i=0;i<12;i++){
                        if((12*y+i)==j)continue;
                        if (question[12*y+i]==-1)continue;
                        if(question[12*y+i]==0)continue;
                        if(question[12*y+i]==question[j])return -1;    // row test;
                }

           

                for(int i=0;i<12;i++){
                        if((x+12*i)==j)continue;
                        if(question[x+12*i]==-1)continue;
                        if(question[x+12*i]==0)continue;
                        if(question[x+12*i]==question[j])return -1;       //clumn test;
                }


                for(int i=0;i<3;i++){
                        for(int k=0;k<3;k++){
                                if(((36*b+3*a)+(i+12*k))==j)continue;
                                if(question[(36*b+3*a)+(i+12*k)]==-1)continue;
                                if(question[(36*b+3*a)+(i+12*k)]==0)continue;
                                if(question[(36*b+3*a)+(i+12*k)]==question[j])
                                        return -1;
                        }

                }



        }
        return 0;



}

int Sudoku::darktest(int &locate){
        int x=locate%12;
        int y=locate/12;

        int a=x/3;		//test the dark(-1) is ok or not
        int b=y/3;

        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){

                        if(question[(36*b+3*a)+(i+12*j)]!=-1){
                                return -1;

                        }


                }


        }
        darktable[4*b+a]=1;
        return 0;

}



void Sudoku::possibletest(int &locate){


        int x=locate%12;	//test the possible num for each 
        int y=locate/12;
        int a=x/3;
        int b=y/3;
        if(question[locate]==0){
                for(int j=0;j<10;j++){
                        possible_answer[locate][j]=0;

                }
        }
        else {
                for(int j=1;j<10;j++)
                        possible_answer[locate][j]=1;

        }



        for(int i=0;i<12;i++){
                if (question[12*y+i]==-1)continue;
                int tem=question[12*y+i];
                possible_answer[locate][tem]=1;    // row test;
        }


        for(int i=0;i<12;i++){
                if(question[x+12*i]==-1)continue;
                int tem=question[x+12*i];
                possible_answer[locate][tem]=1;      //clumn test;
        }


        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){			//cube test
                        if(question[(36*b+3*a)+(i+12*j)]==-1)continue;
                        int tem=question[(36*b+3*a)+(i+12*j)];
                        possible_answer[locate][tem]=1;

                }

        }


}


void Sudoku::possible_ans_test(int& locate){


        int x=locate%12;		//like possibletest but for backtracking
        int y=locate/12;
        int a=x/3;
        int b=y/3;
        if(answer[locate]==0&&question[locate]==0){
                for(int j=0;j<10;j++){
                        possible_answer[locate][j]=0;

                }
        }
        else {
                for(int j=1;j<10;j++)
                        possible_answer[locate][j]=1;

        }



        for(int i=0;i<12;i++){
                if (answer[12*y+i]==-1)continue;
                int tem=answer[12*y+i];
                possible_answer[locate][tem]=1;    // row test;
                if (question[12*y+i]==-1)continue;
                int temp=question[12*y+i];
                possible_answer[locate][temp]=1;



        }



        for(int i=0;i<12;i++){
                if(answer[x+12*i]==-1)continue;
                int tem=answer[x+12*i];
                possible_answer[locate][tem]=1;      //clumn test;

                if(question[x+12*i]==-1)continue;
                int temp=question[x+12*i];
                possible_answer[locate][temp]=1;


        }


        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){ 		//cube test
                        if(answer[(36*b+3*a)+(i+12*j)]==-1)continue;
                        int tem=answer[(36*b+3*a)+(i+12*j)];
                        possible_answer[locate][tem]=1;
                        if(question[(36*b+3*a)+(i+12*j)]==-1)continue;
                        int temp=question[(36*b+3*a)+(i+12*j)];
                        possible_answer[locate][temp]=1;





                }


        }


}

void Sudoku::Solve(){
        for(int i=0;i<16;i++){
                darktable[i]=0;
        }

        for(int i=0;i<144;i++){      //test for dark;
                if(question[i]==-1){
                        int tem=darktest(i);
                        if(tem==-1){
                                cout<<'0'<<endl;
                                return;
                        }
                }
        }
        
        for(int i=0;i<4;i++){
                int count1=0;
                int count2=0;         //test for darktable
                for(int j=0;j<4;j++){

                        if(darktable[i*4+j]==1)count1++;
                        if(darktable[i+4*j]==1)count2++;
                }
                if(count1!=1||count2!=1){
                        cout<<'0'<<endl;
                        return ;
                }



        }

     
        int iiii=questiontest();// test the question
        if(iiii==-1){
                cout<<'0'<<endl;
                return ;
        }


        int slonum=1;
        while(slonum>0){     //test for smart    chose the block only one possible answer 
                slonum=0;


                for(int i=0;i<144;i++){     //smart
                        possibletest(i);

                }




                for(int i=0;i<144;i++){
                        possible_ans_num[i]=0;
                        for(int j=1;j<10;j++){
                                if(possible_answer[i][j]==0)possible_ans_num[i]++;
                        }
                        if(possible_ans_num[i]==1){
                                for(int j=1;j<10;j++){
                                        if(possible_answer[i][j]==0){
                                                question[i]=j;
                                                slonum++;


                                        }
                                }

                        }

                }




        }


answer_num=0;

        for(int i=0;i<144;i++){
                answer[i]=question[i];}
        backtracking(143);
        if(answer_num==1){
                cout<<'1'<<endl;
                output();}
        if(answer_num==0)cout<<'0'<<endl;
        if(answer_num>1)cout<<'2'<<endl;

        return;

}





void Sudoku::backtracking(int locate){
        if(locate==0){
                if(question[locate]!=0){
                        answer[locate]=question[locate];
                        answer_num++;
                        if(answer_num>=2)return;

                        for(int i=0;i<144;i++){
                                out[i]=answer[i];
                        }
              



                }

                else if(question[locate]==0){
                        possible_ans_test(locate);

                        for(int i=1;i<10;i++){

                                if(possible_answer[locate][i]==0){
                                        answer[locate]=i;
                                        answer_num++;        //to know how many answer
                                
                                        if(answer_num>=2)return ;
                                        for(int i=0;i<144;i++){

                                                out[i]=answer[i];
                                        }
                               


                                }

                        }
                        answer[locate]=0;

                }
        }


        else if(question[locate]!=0){
                answer[locate]=question[locate];
                backtracking(locate-1);
        }
        else if(question[locate]==0){
                possible_ans_test(locate);

                for(int i=1;i<10;i++){

                        if(possible_answer[locate][i]==0){
                                answer[locate]=i;
                                backtracking(locate-1);
                        }
                        if(answer_num>=2)return;

                }
                answer[locate]=0;


        }

}




void Sudoku::output(){     //use to output
        for( int i=0;i<144;i++){
                if(i%12==0)cout<<endl;
                cout<<out[i]<<' ';


        }
        cout<<endl;

}

