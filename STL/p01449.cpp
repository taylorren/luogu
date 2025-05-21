#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> calc;
    int operand=0, x, y;
    char op;
    
    do
    {
        cin >> op;
        if (op>= '0' &&op<='9')
        {
            operand = operand * 10 + op - '0';
        }
        else if(op=='.')
        {
            calc.push(operand);
            operand = 0;
        }
        else if(op!='@')
        {
            x = calc.top();
            calc.pop();
            y = calc.top();
            calc.pop();
            switch(op) {
                case '+':
                    calc.push(x+y);
                    break;
                case '-':
                    calc.push(y-x);
                    break;
                case '*':
                    calc.push(x*y);
                    break;
                case '/':
                    calc.push(y/x);
                    break;
            }
        }
    } while (op != '@');
    
    cout << calc.top();

    return 0;
}