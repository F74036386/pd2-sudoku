#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Sudoku{
	public:
		void GiveQuestion();

		void ReadIn();
		int Solve();
		void possibletest(int& locate);
		void possible_ans_test(int& locate);
		int darktest(int& locate);
		void backtracking(int locate);
		void output();		
		int  questiontest();
		void qtest();         //
		void makehole(int n ,int *qmap);    //
		int testnothole();
	private:
		int question[144];
		int answer[144];
		bool darktable[16];
		int answer_num;
		bool possible_answer[144][10];
		int possible_ans_num[144];
		int out[144];
		int smallnothole;
		int nothole;

};
int main (){
	Sudoku ss;
//	ss.ReadIn();
	//printf("start slove\n");

//	ss.Solve();
	//system("pause");
ss.qtest();
	return 0;
}

void Sudoku::qtest(){
	int qmap[144]={9,1,8,3,2,7,5,6,4,-1,-1,-1,6,7,3,5,4,8,1,9,2,-1,-1,-1,4,5,2,6,1,9,8,7,3,-1,-1,-1,1,2,5,-1,-1,-1,9,4,7,3,8,6,7,6,9,-1,-1,-1,3,8,5,2,4,1,8,3,4,-1,-1,-1,6,2,1,5,9,7,-1,-1,-1,1,3,6,7,5,8,4,2,9,-1,-1,-1,7,9,4,2,3,6,1,5,8,-1,-1,-1,2,8,5,4,1,9,7,6,3,5,4,7,9,6,3,-1,-1,-1,8,1,2,3,9,1,8,5,2,-1,-1,-1,6,7,4,2,8,6,4,7,1,-1,-1,-1,9,3,5};
	smallnothole=144;
	nothole=0;
for(int i=0;i<144;i++){
question[i]=qmap[i];
}




cout<<"a"<<endl;
	makehole(143,qmap);
}
int Sudoku::testnothole(){
	int k=0;
	for(int i=0;i<144;i++){
		if(question[i]!=0)k++;
	}
	return k;




}
void Sudoku::makehole(int n,int* qmap){
if(n<0)return;

cout<<"n="<<n<<endl;	
if(qmap[n]==-1){question[n]=-1;
cout<<"-1"<<endl;
makehole(n-1,qmap);
return;
}
	for(int i=1;i>-1;i--){
		if(i==1){

//cout<<"ha"<<endl;
			question[n]=qmap[n];
			makehole(n-1,qmap);
		}
		else if(i==0){           cout<<"sm="<<smallnothole<<endl;
			question[n]=0;
			int k=Solve();
			if(k==1){
cout<<"question[n]="<<question[n]<<endl;
//cout<<'b'<<endl;
				nothole=testnothole();
cout<<"nothole="<<nothole<<endl;
				if(nothole<smallnothole){
//cout<<'c';
					smallnothole=nothole;
					for(int l=0;l<144;l++){
						out[l]=question[l];

					}
					cout<<"smallhole="<<smallnothole<<endl;

					output();
				}

				makehole(n-1,qmap);

			}

			question[n]=qmap[n];	
		}
	}
}


void Sudoku::GiveQuestion(){
	printf(" 0 0 6 8 0 3 9 5 1 -1 -1 -1\n0 7 0 0 5 0 0 0 4 -1 -1 -1\n9 0 1 0 2 0 8 0 0 -1 -1 -1\n-1 -1 -1 1 0 2 0 0 0 9 0 6\n-1 -1 -1 0 8 0 1 0 0 0 2 0\n-1 -1 -1 0 0 6 0 0 0 0 7 1\n1 0 0 0 4 0 -1 -1 -1 0 9 0\n0 0 4 0 6 0 -1 -1 -1 1 0 7\n0 9 0 0 1 0 -1 -1 -1 0 8 0\n0 0 2 -1 -1 -1 0 4 0 5 0 0\n7 0 8 -1 -1 -1 0 0 9 0 0 2\n0 6 0 -1 -1 -1 0 1 0 7 0 0\n");
	return ;

}




void Sudoku::ReadIn(){
	int num=0;
	for(int i=0;i<144;i++){
		cin>>num;
		question[i]=num;

	}

	//output();

}
int Sudoku:: questiontest(){

	for(int j=0;j<144;j++){
		if(question[j]<=0)continue;


		int x=j%12;
		int y=j/12;
		int a=x/3;
		int b=y/3;

		//cout<<"j="<<j<<endl;
		for(int i=0;i<12;i++){
			if((12*y+i)==j)continue;
			if (question[12*y+i]==-1)continue;
			if(question[12*y+i]==0)continue;
			if(question[12*y+i]==question[j])return -1;    // row test;
		}

		//cout<<"j1="<<j<<endl;

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



void Sudoku::possibletest(int &locate){


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

int Sudoku::Solve(){
	for(int i=0;i<16;i++){
		darktable[i]=0;
	}

	for(int i=0;i<144;i++){      //test for dark;
		if(question[i]==-1){
			int tem=darktest(i);
			if(tem==-1){
				//	cout<<'0'<<endl;
				return 0;
			}
		}
	}
	/* 
	   for(int i=0;i<16;i++){
	   if(i%4==0)cout<<endl;
	   cout<<darktable[i]<<' ';


	   } */  
	//	cout<<'a'<<endl;
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
			//	cout<<'0'<<endl;
			return 0;
		}	
		//		printf("count1=%d\ncount2=%d\n",count1,count2);



	}

	//	cout<<'b'<<endl;
	/*
	   for(int i=0;i<16;i++){
	   if(i%4==0)cout<<endl;
	   cout<<darktable[i]<<' ';
	   }
	 */


	int iiii=questiontest();
	if(iiii==-1){
		//	cout<<'0'<<endl;
		return 0;
	}



/*

	//	cout<<'c'<<endl;
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




	}

*/
	answer_num=0;

	for(int i=0;i<144;i++){
		answer[i]=question[i];}
	//	printf("\nbeforback\n");
	backtracking(143);
	if(answer_num==1){return 1;
		cout<<'1'<<endl;
		output();}
	if(answer_num==0)return 0;cout<<'0'<<endl;
	if(answer_num>1)return 2;//cout<<'2'<<endl;

	

}





void Sudoku::backtracking(int locate){
	if(locate==0){
		if(question[locate]!=0){
			answer[locate]=question[locate];
			answer_num++;
			if(answer_num>=2)return;

			//	for(int i=0;i<144;i++){
			//		out[i]=answer[i];
			//	}
			//	output();



		}

		else if(question[locate]==0){
			possible_ans_test(locate);

			for(int i=1;i<10;i++){

				if(possible_answer[locate][i]==0){
					answer[locate]=i;
					answer_num++;
					//	cout<<answer_num<<endl;
					if(answer_num>=2)return ;
					//for(int i=0;i<144;i++){

					//	out[i]=answer[i];
					//	}
					//		output();


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




void Sudoku::output(){
	for( int i=0;i<144;i++){
		if(i%12==0)cout<<endl;
		cout<<out[i]<<' ';


	}
	cout<<endl;

}

