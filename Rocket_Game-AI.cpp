#include<bits/stdc++.h>
using namespace std;
struct Move
{
    int R,C;
};
class Board
{
private:
    vector<vector<string>> arr;
    string lst_move;
    Move lastMoveRC;
    int step;
    string umove;
    int Size;
public:
    Board(){}
    Board(int sz)
    {
        Size = sz;
        fill(sz);
    }
    void fill(int sz)
    {
        Size = sz;
        arr.resize(pow(2,sz));
        for (int i=0 ; i<sz ; i++)
        {
            for (int j=0 ; j<sz ; j++)
            {
                arr[i].push_back("  ");
            }
        }
        for (int i=0 ; i<sz ; i++)
        {
            for (int j=0 ; j<sz ; j++)
            {
                if (i == 0 && j != 0 && j!= sz-1 )
                {
                    //arr[i].insert(j,"a"+to_string(j))
                    arr[i][j] = "a"+to_string(j);
                }
                else if (j == 0 && i != 0 && i!= sz-1 )
                {
                    arr[i][j] = "b"+to_string(i);

                }

            }
        }
    }
    void printB()
    {
        for (int i=0;i<Size;i++)
        {
            for (int j=0;j<Size;j++)
            {
                cout << "|" <<arr[i][j] << "|" ;
            }
            cout <<endl;
        }
        cout << endl;
    }
    string element(int i, int j)
    {
        return arr[i][j];
    }
    void Move(string s)
    {
        string a = s;
        umove = s;
        if (valid_move(s))
        {
            if (a[0]=='a')
            {
                for (int i=0;i<Size-1;i++)
                {
                    for (int j=1;j<Size-1;j++)
                    {
                        if (arr[i][j]==a)
                        {
                            if (arr[i+1][j]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i+1][j]=a;
                                lst_move="i"+to_string(i+1);
                                step =1;
                                lastMoveRC.R = i+1;
                                lastMoveRC.C = j;
                                a="d";
                                break;
                            }
                            else if (arr[i+1][j]!="  " && arr[i+2][j]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i+2][j]=a;
                                lst_move="i"+to_string(i+2);
                                step = 2;
                                lastMoveRC.R = i+2;
                                lastMoveRC.C = j;
                                a="d";
                                break;
                            }
                            else
                            {
                                step =0;
                                continue;
                            }
                        }
                    }
                    if (a=="d")
                    {
                        break;
                    }
                }
            }
            else if (a[0]=='b')
            {
                for (int i=1;i<Size-1;i++)
                {
                    for (int j=0;j<Size-1;j++)
                    {
                        if (arr[i][j]==a)
                        {
                            if (arr[i][j+1]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i][j+1]=a;
                                lst_move="j"+to_string(j+1);
                                step = 1;
                                lastMoveRC.R = i;
                                lastMoveRC.C = j+1;
                                a="d";
                                break;
                            }
                            else if (arr[i][j+1]!="  " && arr[i][j+2]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i][j+2]=a;
                                lst_move="j"+to_string(j+2);
                                step = 2;
                                lastMoveRC.R = i;
                                lastMoveRC.C = j+2;
                                a="d";
                                break;
                            }
                            else
                            {
                                step =0;
                                continue;
                            }
                        }
                    }
                    if (a=="d")
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "Invalid Move!\n";
        }
    }

    void Undo()
    {
        if (lst_move[0]=='i')
        {
            arr[lastMoveRC.R][lastMoveRC.C] = "  ";
            arr[lastMoveRC.R-step][lastMoveRC.C] =umove ;
        }
        else if (lst_move[0]=='j')
        {
            arr[lastMoveRC.R][lastMoveRC.C] = "  ";
            arr[lastMoveRC.R][lastMoveRC.C-step] =umove;
        }
    }

    bool Point()
    {
        if (lst_move=="j"+to_string(Size-1)||lst_move=="i"+to_string(Size-1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool valid_move(string a)
    {
        if (a[0]=='a'||a[0]=='b')
        {
            for (int i=0;i<Size;i++)
            {
                for (int j=0;j<Size;j++)
                {
                    if (arr[i][j]==a)
                    {
                        if (i==Size-1||j==Size-1)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }

    }

    int check_end()
    {
        int c1=0,c2=0;
        for (int j=1;j<Size;j++)
        {
            if (arr[Size-1][j]!="  ")
            {
                c1++;
            }
        }
        for (int i=1;i<Size;i++)
        {
            if (arr[i][Size-1]!="  ")
            {
                c2++;
            }
        }
        if (c1==Size-2)
        {
            return 1;
        }
        else if (c2==Size-2)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    bool Awin()
    {
        int c1=0;
        for (int j=1;j<Size;j++)
        {
            if (arr[Size-1][j]!="  ")
            {
                c1++;
            }
        }
        if (c1==Size-2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool Bwin()
    {
        int c1=0;
        for (int i=1;i<Size;i++)
        {
            if (arr[i][Size-1]!="  ")
            {
                c1++;
            }
        }
        if (c1==Size-2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int sz()
    {
        return Size;
    }
    bool valid_for_A(string s)
    {
        for (int i=0;i<Size ;i++ )
        {
            for (int j=0 ;j<Size ;j++ )
            {
                if (arr[i][j]==s)
                {
                    if (arr[i+1][j]!="  " && arr[i+2][j]!="  ")
                    {
                        return false;
                    }
                    else if (arr[i+1][j]=="  ")
                    {
                        return true;
                    }
                    else if (arr[i+2][j]=="  ")
                    {
                        return true;
                    }
                }
            }
        }

    }

};

class Player
{
private:
    string name;
    int score;
public:
    Player()
    {
        score=0;
    }
    Player(string n)
    {
        name = n;
        score = 0;
    }
    void set_name(string n)
    {
        name = n;
    }
    void inc_score()
    {
        score++;
    }
    string get_name()
    {
        return name;
    }
    int get_score()
    {
        return score;
    }
};

class PvsP
{
private:

    int turn;
public:
    PvsP()
    {
        turn=1;
    }
    void Turn()
    {
        if (turn==1)
        {
            turn=2;
        }
        else
        {
            turn=1;
        }

    }
    void interface()
    {
        int sz;
        Player one("Player1");
        Player two("Player2");
        string name1,name2;
        //cout << "       Welcome to Rocket game\n\n";
        cout << "Player 1, Enter your name : ";
        cin >> name1;
        one.set_name(name1);
        cout << "Player 2, Enter your name : ";
        cin >> name2;
        two.set_name(name2);
        cout << "Enter the size of the board : ";
        cin >> sz;
        Board  b(sz);
        string mv;
        b.printB();
        while(true)
        {
            while(true)
            {
                cout << name1 << " you want to move (a1/2/...): ";
                cin >> mv;
                //int x=stoi(mv[1]);
                if (mv[0] == 'a' && /*x>0 && x<b.sz()-1 &&*/ b.valid_move(mv) )
                {
                    b.Move(mv);
                    if (b.Point())
                    {
                        one.inc_score();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            b.printB();
            cout << name1 << " score : " << one.get_score() << endl;
            cout << name2 << " score : " << two.get_score() << endl << endl;
            if (b.check_end()==1)
            {
                cout << name1 << " Win!!\n\n";
                break;
            }
            Turn();
            while(true)
            {
                cout << name2 << " you want to move (b1/2/...): ";
                cin >> mv;
                if (mv[0] == 'b' && /*mv[1]-'0'>0 && mv[1]-'0'<b.sz()-1 &&*/ b.valid_move(mv) )
                {
                    b.Move(mv);
                    if (b.Point())
                    {
                        two.inc_score();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            b.printB();
            cout << name1 << " score : " << one.get_score() << endl;
            cout << name2 << " score : " << two.get_score() << endl << endl;
            if (b.check_end()==2)
            {
                cout << name2 << " Win!!\n\n";
                break;
            }
            Turn();
        }
    }
};

class AI
{
private:
    Board b;
    int turn;
public:
    AI()
    {
        turn = 1;
    }
    void Turn()
    {
        if (turn==1)
        {
            turn=2;
        }
        else
        {
            turn=1;
        }
    }
    void interface()
    {
        int sz=0;
        Player A("Player 1");
        Player B("AI");
        string name;

        cout << "Enter your Name : ";
        cin >> name;
        A.set_name(name);
        while(sz>5||sz<3)
        {
            cout << "Enter the size of the board(3/4/5) : ";
            cin >> sz;
        }

        Board  b(sz);
        string mv;
        b.printB();
        while(true)
        {

            //Player Turn ...............
            while(true)
            {
                cout << name << " you want to move (b1/2/...): ";
                cin >> mv;
                if (mv[0] == 'b' && /*mv[1]-'0'>0 && mv[1]-'0'<b.sz()-1 &&*/ b.valid_move(mv) )
                {
                    b.Move(mv);
                    if (b.Point())
                    {
                        A.inc_score();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            b.printB();
            cout << name << " score : " << A.get_score() << endl;
            cout << "AI" << " score : " << B.get_score() << endl;
            if (b.check_end()==2)
            {
                cout << name << " Win!!\n\n";
                break;
            }
            Turn();

            //Computer Turn ...............

            Move bm = findBestMove(b);
            mv = b.element(bm.R, bm.C);
            b.Move(mv);
            if (b.Point())
            {
                B.inc_score();
            }
            b.printB();
            cout << name << " score : " << A.get_score() << endl;
            cout << "AI" << " score : " << B.get_score() << endl;
            if (b.check_end()==1)
            {
                cout << "AI" << " Win!!\n\n";
                break;
            }



        }
    }

    int Evaluate(Board b)
    {
        if (b.Awin())
        {
            return 10;
        }
        else if (b.Bwin())
        {
            return -10;
        }
        else
        {
            return 0;
        }
    }
    int MIN = -1000;
    int MAX =  1000;
    int minimax(Board b, int depth, bool ismax, int alpha, int beta)
    {

        int score = Evaluate(b);

        //BASE CASE

        // If Maximizer has won the game return his/her
        // evaluated score
        if (score == 10)
        {
            return score;
        }

        // If Minimizer has won the game return his/her
        // evaluated score
        if (score == -10)
        {
            return score;
        }

        // If this maximizer's move
        if (ismax)
        {
            int best = -1000;
            int c=1;
            // Traverse all cells
            for (int i = 0; i<b.sz()-1; i++)
            {
                for (int j = 0; j<b.sz()-1; j++)
                {
                    if (b.element(i,j)[0]=='a')
                    {
                        // Check if cell is empty
                        if (b.element(i+1,j)=="  ")
                        {
                            if (b.valid_move("a"+to_string(j)))
                            {
                                if (b.valid_for_A("a"+to_string(j)))
                                {
                                    // Make the move
                                    b.Move("a"+to_string(j));

                                    // Call minimax recursively and choose
                                    // the maximum value
                                    best = max( best,
                                        minimax(b, depth+1, !ismax, alpha, beta) );
                                    alpha = max(alpha,best);
                                    // Undo the move
                                    b.Undo();

                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                continue;
                            }
                        }

                        else if (b.element(i+2,j)=="  ")
                        {
                            if (b.valid_move("a"+to_string(j)))
                            {
                                if (b.valid_for_A("a"+to_string(j)))
                                {
                                    // Make the move
                                    b.Move("a"+to_string(j));

                                    // Call minimax recursively and choose
                                    // the maximum value
                                    best = max( best,
                                        minimax(b, depth+1, !ismax, alpha, beta) );
                                    alpha = max(alpha,best);
                                    // Undo the move
                                    b.Undo();
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                        {
                            continue;
                        }


                    }
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
                if (beta <= alpha)
                {
                    break;
                }
            }
            return best;
        }

        // If this minimizer's move
        else if (!ismax)
        {
            int best = 1000;
            static int c=1;
            // Traverse all cells
            for (int i = 1; i<b.sz()-1; i++)
            {
                for (int j = 0; j<b.sz()-1; j++)
                {
                    if (b.element(i,j)[0]=='b')
                    {
                        // Check if cell is empty
                        if (b.element(i,j+1)=="  ")
                        {
                            if (b.valid_move("b"+to_string(i)))
                            {
                                // Make the move
                                b.Move("b"+to_string(i));

                                // Call minimax recursively and choose
                                // the maximum value
                                best = min( best,
                                    minimax(b, depth+1, ismax, alpha, beta) );
                                beta = min(beta, best);
                                // Undo the move
                                b.Undo();

                            }
                            else
                            {
                                continue;
                            }
                        }

                        else if (b.element(i,j+2)=="  ")
                        {
                            if (b.valid_move("b"+to_string(i)))
                            {
                                // Make the move
                                b.Move("b"+to_string(i));

                                // Call minimax recursively and choose
                                // the maximum value
                                best = min( best,
                                    minimax(b, depth+1, ismax,alpha, beta) );
                                beta = min(beta, best);
                                // Undo the move
                                b.Undo();
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                        {
                            continue;
                        }

                    }
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
                if (beta <= alpha)
                {
                    break;
                }
            }
            return best;
        }
    }

    Move findBestMove(Board b)
    {
        int bestVal = -1000;
        Move bestMove;
        bestMove.R = -1;
        bestMove.C = -1;
        int c=1;
        // Traverse all cells, evaluate minimax function for
        // all empty cells. And return the cell with optimal
        // value.
        for (int i = 0; i<b.sz()-1; i++)
        {
            for (int j = 0; j<b.sz()-1; j++)
            {

                if (b.element(i,j)[0]=='a')
                {
                    if (b.valid_move("a"+to_string(j)))
                    {
                        if (b.valid_for_A("a"+to_string(j)))
                        {
                            // Make the move
                            b.Move("a"+to_string(j));

                            // compute evaluation function for this
                            // move.
                            int moveVal = minimax(b, 0, true,MIN,MAX);

                            // Undo the move
                            b.Undo();

                            // If the value of the current move is
                            // more than the best value, then update
                            // best/
                            if (moveVal > bestVal)
                            {
                                bestMove.R = i;
                                bestMove.C = j;
                                bestVal = moveVal;
                            }
                        }
                        else
                        {
                            continue;
                        }

                    }
                    else
                    {
                        continue;
                    }
                    c++;
                }
                /*else if (b.element(i,j)[0]=='b')
                {
                    if (b.valid_move("b"+to_string(c)))
                    {
                        // Make the move
                        b.Move("b"+to_string(c));

                        // compute evaluation function for this
                        // move.
                        int moveVal = minimax(b, 0, false,MIN, MAX);

                        // Undo the move
                        b.Undo();

                        // If the value of the current move is
                        // more than the best value, then update
                        // best/
                        if (moveVal > bestVal)
                        {
                            bestMove.R = i;
                            bestMove.C = j;
                            bestVal = moveVal;
                        }

                    }
                    c++;
                }*/
                else
                {
                    continue;
                }
            }
        }

        printf("The value of the best Move is : %d\n\n",
                bestVal);

        return bestMove;
    }
};


int main()
{
    cout << "       Welcome to Rocket game\n\n";
    AI m2;
    PvsP m1;
    int c;
    while (true)
    {
        cout << "1.Player vs Player\n2.AI\n";
        cin>>c;
        if (c==1)
        {
            m1.interface();
            break;
        }
        else if (c==2)
        {
            m2.interface();
        }
        else
        {
            cout << "Invalid input!!\n";
            continue;
        }
    }
    m1.interface();
    return 0;
}
