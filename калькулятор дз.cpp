#include <iostream>
#include <string>

using namespace std;

setlocale(LC_ALL, "Russian");

float calculator(expression, p1, p2){
    string temp_expression = expression;
    int p1, p2; //������ � ������ ������ ��������� ������������ � ���������
    int t; // ���������� ���������� ����������
    int k1 = 0, k2 = 0; //�������� ��� �������� � �������� ������
    if (temp_expression.find("(") != 0){ //� ���� ����� ��������� ��������� �� ������
        for (int i = 0; i <= temp_expression.length(); ++i){
            if temp_expression[i] == "("{
                k1 = k1 + 1;
            }
            if temp_expression[i] == ")"{
                k2 = k2 + 1;
            }
            if (k1 == k2){
                p1 = temp_expression.find("(") + 1; //����� ��������� ��� ��� ������
                p2 = i - 1;
                break;
            }
        }
        temp_expression = temp_expression.substr(p1, p2 - p1);
        calculator(temp_expression, p1, p2);
    }
    else{ //����� ������������ ��������� ��� ������
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
    cout << "������� �������������� ���������: " << endl;
    cin >> expression;
    calculator(expression);
    return 0;
}



//                while ((temp_expression.find("+") != -1) || (temp_expression.find("-") != -1) (temp_expression.find("*") != -1) (temp_expression.find("/") != -1) (temp_expression.find("^") != -1)){
//
//
//                }
