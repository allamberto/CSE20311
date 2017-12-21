//Ana Lamberto
//Purpose: interface for Life class - lifeboard.h

class Life{
        public:
                Life();
                void set(int, int, char);
                void reset();
                void print();
                void advance();
                void upload(Life&);
        private:
                int row;
                int column;
                char board[40][40];
};
