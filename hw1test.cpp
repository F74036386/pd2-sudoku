#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Sudoku{
	public:
		void GiveQuestion();
		void ReadIn();
		void Solve();
		void possibletest(int locate);
		void possible_ans_test(int& locate);
		int darktest(int locate);
		void backtracking(int locate);
		void output();		

	private:
		int question[144];
		int answer[144];
		bool darktable[16];
		int answer_num;
		bool possible_answer[144][10];
		int possible_ans_num[144];

};
int main (){
	Sudoku ss;
	ss.ReadIn();
	//printf("start slove\n");

	ss.Solve();
	//system("pause");

	return 0;
}

void Sudoku::ReadIn(){
	int num=0;
	for(int i=0;i<144;i++){
		cin>>num;
		question[i]=num;

	}

	//output();

}




int Sudoku::darktest(int locate){
	int x=locate%12;
	int y=locate/12;

	int a=x/3;
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



void Sudoku::possibletest(int locate){


	int x=locate%12;
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
		for(int j=0;j<3;j++){
			if(question[(36*b+3*a)+(i+12*j)]==-1)continue;
			int tem=question[(36*b+3*a)+(i+12*j)];
			possible_answer[locate][tem]=1;

		}

	}


}


void Sudoku::possible_ans_test(int& locate){


	int x=locate%12;
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
		for(int j=0;j<3;j++){
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
	/* 
	   for(int i=0;i<16;i++){
	   if(i%4==0)cout<<endl;
	   cout<<darktable[i]<<' ';


	   } */  
	cout<<endl;
	for(int i=0;i<4;i++){
		int count1=0;
		int count2=0;         //test for darktable
		for(int j=0;j<4;j++){

			//printf("\naa\n");
			//		cout<<darktable[i*4+j]<<endl<<darktable[i+4*j];
			if(darktable[i*4+j]==1)count1++;
			if(darktable[i+4*j]==1)count2++;
		}
		if(count1!=1||count2!=1){
			return ;
		}	
		//		printf("count1=%d\ncount2=%d\n",count1,count2);



	}


	/*
	   for(int i=0;i<16;i++){
	   if(i%4==0)cout<<endl;
	   cout<<darktable[i]<<' ';
	   }
	 */




	int slonum=1;
	while(slonum>0){     //test for smart

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

		/*			for(int i=0;i<144;i++){
					if(i%12==0)cout<<endl;
					cout<<possible_ans_num[i]<<' ';
					}

		 */

	}



	output();
	printf("\nbeforback\n");
	backtracking(143);

	if(answer_num==0)cout<<'0'<<endl;
	if(answer_num>1)cout<<'2'<<endl;

	return;

}

void Sudoku::backtracking(int locate){
	if(locate==0){
		if(question[locate]!=0){
			answer[locate]=question[locate];
			answer_num++;	
		}

		else if(question[locate]==0){
			for(int i=1;i<10;i++){
				if(i==1)possible_ans_test(locate);
				if(possible_answer[locate][i]==0){
					answer[locate]=i;
					answer_num++;

					//		if(answer_num>=2)return ;
					for(int i=0;i<144;i++){
						if((i)%12==0)cout<<endl;
						cout<<answer[i]<<' ';
					}
					cout<<endl;

				}

			}

		}
	}


	else if(question[locate]!=0){
		answer[locate]=question[locate];
		backtracking(locate-1);
	}
	else if(question[locate]==0){
		for(int i=1;i<10;i++){
			if(i==1)possible_ans_test(locate);
			if(possible_answer[locate][i]==0){
				answer[locate]=i;
				backtracking(locate-1);
			}
			if(i==9)answer[locate]=0;
		}

	}

}




void Sudoku::output(){
	for( int i=0;i<144;i++){
		if(i%12==0)cout<<endl;
		cout<<question[i]<<' ';


	}
	cout<<endl;

}
