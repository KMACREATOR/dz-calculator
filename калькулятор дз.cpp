#include <iostream>
#include <string>

using namespace std;

setlocale(LC_ALL, "Russian");

float calculator(expression, p1, p2){
    string temp_expression = expression;
    int p1, p2; //первый и второй индекс вхождения подвыражения в выражения
    int t; // переменная приоритета операторов
    int k1 = 0, k2 = 0; //счетчики для открытых и закрытых скобок
    if (temp_expression.find("(") != 0){ //в этом куске проверяем выражение на скобки
        for (int i = 0; i <= temp_expression.length(); ++i){
            if temp_expression[i] == "("{
                k1 = k1 + 1;
            }
            if temp_expression[i] == ")"{
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
        for (int i = 0; i <= temp_expression.length(); ++ i){
            if (temp_expression_find("^") != 0){
                for
            }
        }


    }
    }

}

int main()
{
    string expression;
    cout << "Введите математическое выражение: " << endl;
    cin >> expression;
    calculator(expression);
    return 0;
}



//                while ((temp_expression.find("+") != -1) || (temp_expression.find("-") != -1) (temp_expression.find("*") != -1) (temp_expression.find("/") != -1) (temp_expression.find("^") != -1)){
//
//
//                }
