#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string expression;
string numbers("0123456789"); //набор цифр для проверки
string ops("^*/+-");
string d;
//float a, b, c; // переменные для записи членов арифмитических выражений и их результатов
int p1, p2; //первый и второй индекс вхождения подвыражения в выражения
//, int p1, int p2
//, p1, p2
void calculator(string expression){
    string temp_expression = expression;
    while((expression.find("^") != expression.npos) || (expression.find("*") != expression.npos) || (expression.find("/") != expression.npos) || (expression.find("+") != expression.npos) || (expression.find("-") != expression.npos)){
        int k1 = 0;
        int k2 = 0; //счетчики для открытых и закрытых скобок
        if (temp_expression.find("(") != expression.npos){ //в этом куске проверяем выражение на скобки
            for (int i = 0; i < temp_expression.length(); ++i){
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
            temp_expression = temp_expression.substr(p1, p2 - p1 + 1);
            calculator(temp_expression);
        }
        else{ //здесь обрабатываем выражения без скобок
            //(уже сделано)нужно добавить проверку на отрицательные числа в начале строки
            // if ((i != 0) && (i == "-"));
            cout << "обрабатываемое выражение: " << temp_expression << endl;
            int g1, g2; //выделение подстрок для работы с операторами
            for (int f = 0; f < ops.length(); ++f){
                cout << "оператор: " << ops[f] << endl;
                int flag = 0;
                while (temp_expression.find(ops[f]) != temp_expression.npos){ // здесь ищем числа, окружающие нужный нам оператор
                                    flag = 0;
                                    int a = 0, b = 0;
                                    float c = 0;
                                    string n("");
                                    string m(""); //строки для записи членов
                                    cout << "длина: " << temp_expression.length() << endl;
                                    for (int i = 0; i < temp_expression.length(); ++i){
                                            cout << "i: " << i << endl;
                                            cout << "флаг: " << flag << endl;
                                            cout << "положение каретки: " << temp_expression[i] << endl;
                                            if (flag == 1){
                                                flag = 2;
                                                cout << "флаг: " << flag << endl;
                                            }
                                            if (flag == 0){
                                                if ((numbers.find(temp_expression[i]) != numbers.npos) || ((i == 0) && (temp_expression[i] == '-')) ){
                                                    n = n.append(1, temp_expression[i]);
                                                    cout << "n: " << n << endl;
                                                    }
                                                if ((ops.find(temp_expression[i]) != ops.npos) && (temp_expression[i] != ops[f])){
                                                    n = "1";
                                                    cout << "n очищен" << endl;
                                                    }
                                                if (temp_expression[i] == ops[f]){
                                                    flag = 1;
                                                    a = stoi(n);
                                                    cout << "сохраненный n: " << n << endl;
                                                    }
                                            }
                                            if (flag == 2){
                                                if (i == (temp_expression.length() - 1)){
                                                                m = m.append(1, temp_expression[i]);
                                                                b = stoi(m);
                                                                cout << "сохраненный m: " << m << endl;
                                                                g2 = i;
                                                            }
                                                else{
                                                    if (numbers.find(temp_expression[i]) != numbers.npos){
                                                            m = m.append(1, temp_expression[i]);
                                                            cout << m << endl;

                                                    }
                                                    if ((ops.find(temp_expression[i]) != ops.npos)){
                                                        b = stoi(m);
                                                        cout << m << endl;
                                                        g2 = i;
                                                        break;
                                                        }

                                            }
                                        }
                                            // сюда можно вставить свитч с операцией в зависимости от опертора.
                                            }
                cout << "a = " << a << endl;
                cout << "b = " << b << endl;
                switch(ops[f]){
                case '^':{
                c = pow(a, b);
                }
                case '*':{
                c = a * b;
                }
                case '/':{
                c = a / b;
                }
                case '+':{
                c = a + b;
                }
                case '-':{
                c = a - b;
                }
                }
                cout << "c = " << c << endl;
                string d = to_string(c);
                a = 0;
                b = 0;
                c = 0;
                expression.replace(0, g2+1, d);
                cout << "выражение после замены: " << expression << endl;
                temp_expression = expression;


                    }
            }


        }
        cout << expression << endl;
}
}



int main()
{

    setlocale(LC_ALL, "Russian");

    cout << "Введите математическое выражение: " << endl;
    cin >> expression;
    calculator(expression);
    return 0;
}


//    int t; // переменная приоритета операторов
//                            a = 0;
//                            b = 0;
//                            c = 0;
