#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string expression;
string numbers("0123456789"); //набор цифр для проверки
string ops("^*/+-");
string d;
int p1, p2; //первый и второй индекс вхождения подвыражения в выражения

float calculator(string expression, int p1, int p2){
    string temp_expression = expression;
    string n(""), m(""); //строки для записи членов
    float a, b, c; // переменные для записи членов арифмитических выражений и их результатов

    int t; // переменная приоритета операторов
    int k1 = 0, k2 = 0; //счетчики для открытых и закрытых скобок
    if (temp_expression.find("(") != 0){ //в этом куске проверяем выражение на скобки
        for (int i = 0; i <= temp_expression.length(); ++i){
            if (temp_expression[i] == '('){
                k1 = k1 + 1;
            }
            if (temp_expression[i] == ')'){
                k2 = k2 + 1;
            }
            if (k1 == k2){
                p1 = temp_expression.find("(") + 1; //берем выражение уже без скобок
                p2 = i - 1;
                break;
            }
        }
        temp_expression = temp_expression.substr(p1, p2 - p1);
        calculator(temp_expression, p1, p2);
    }
    else{ //здесь обрабатываем выражения без скобок
        //(уже сделано)нужно добавить проверку на отрицательные числа в начале строки
        // if ((i != 0) && (i == "-"));
        for (int f = 0; f < ops.length(); ++f){
            if (temp_expression.find(ops[f]) != 0){ // здесь ищем числа, окружающие нужный нам оператор
                    for (int i = 0; i <= temp_expression.length(); ++ i)
                        {
                            int flag = 0;
                            if (flag == 0){
                            if ((numbers.find(temp_expression[i]) != -1) || ((i == 0) && (i == '-')) ){
                                n = n + temp_expression[i];
                            }
                            if ((ops.find(temp_expression[i]) != -1) && (i != ops[f])){
                                n = "";
                            }
                            if (i == ops[f]){
                                flag = 1;
                                a = stof(n);
                                }
                            }
                            if (flag == 1){
                                if (numbers.find(temp_expression[i]) != -1){
                                    m = m + temp_expression[i];
                                }
                                if (ops.find(temp_expression[i]) != -1){
                                    b = stof(m);
                                    break;
                                }
                                }
                        }
                            // сюда можно вставить свитч с операцией в зависимости от опертора.

                            switch(ops[f]){
                            case '^':
                                {
                                c = pow(a, b);
                                string d = to_string(c);
                                break;
                                }

                            case '*':
                                {
                                c = a * b;
                                string d = to_string(c);
                                break;
                                }

                            case '/':
                                {
                                c = a / b;
                                string d = to_string(c);
                                break;
                                }

                            case '+':
                                {
                                c = a + b;
                                string d = to_string(c);
                                break;
                                }

                            case '-':
                                {
                                c = a + b;
                                string d = to_string(c);
                                break;
                                }
                            }
                            a = 0;
                            b = 0;
                            c = 0;
                            temp_expression.replace(p1, p2 - p1, d);
                            cout << temp_expression;
                    }
                }
        }


    }




int main()
{

    setlocale(LC_ALL, "Russian");

    cout << "Введите математическое выражение: " << endl;
    cin >> expression;
    calculator(expression, 0, 0);
    return 0;
}
