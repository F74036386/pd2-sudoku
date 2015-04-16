#ifndef Sudoku_h
#define Sudoku_h
class Sudoku{
        public:
                void GiveQuestion();

                void ReadIn();
                void Solve();
                void possibletest(int& locate);
                void possible_ans_test(int& locate);
                int darktest(int& locate);
                void backtracking(int locate);
                void output();
                int  questiontest();
        private:
                int question[144];
                int answer[144];
                bool darktable[16];
                int answer_num;
                bool possible_answer[144][10];
                int possible_ans_num[144];
                int out[144];

};
#endif

