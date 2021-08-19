#include <iostream>
using namespace std;

//����
struct Node
{
    char data;
    
    Node* link; //��������� ���� Node �� ��������� �������
};

//��������� ��� ������������ ������� �����
Node* top = NULL;

//������� ��� �������� ������� �����
bool isempty()
{
    if (top == NULL)
        return true; 
    else
        return false;
}

//���������� �������� � ����
void push(char value)
{
    Node* comp = new Node();//������� ����� ��������� ���� ��������� Node � �������� ������ ��� ������ ��������
    comp->data = value;
    comp->link = top; //�������� ����� �� ������ �������� � �������.
    top = comp; //�������� ������ �������� ����� �������
}

//�������� ��������
void pop()
{
    if (isempty())
        cout << "\n���� ������\n";
    else
    {
        Node* comp = top;
        top = top->link;
        delete(comp);
    }
}

// ����� �������� �������� �����
void showTop()
{
    if (isempty())
        cout << "\n���� ������\n";
    else
        cout << "\n������� ������� : " << (char)top->data<<endl;
}

// ������ �����
void displayStack()
{
    if (isempty())
        cout << "\n���� ������\n";
    else
    {
        Node* temp = top;
        for (int i = 0; temp != NULL;i++)
        {
            cout << i+1<<"."<<(char)temp->data << " ";
            temp = temp->link;
        }
        cout << "\n";
    }
}

// ������� �����
void clearStack()
{
    if (isempty())
        cout << "\n���� ������\n";
    else
    {
        while(top != NULL)
        {
            Node* comp = top;
            top = top->link;
            delete(comp);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice, flag = 1;
    char value;

    while (flag == 1)
    {
        cout << "\n1.�������� ������ \n2.������� ������ \n3.������� ������� ������ \n4.������� ���� \n5.������� ����� \n6.�����\n";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << "\n������� ������:\n";
            cin >> value;
            push(value);
            cout << "\n����:";
            displayStack();
            break;
        case 2: pop();
            cout << "\n����:";
            displayStack();
            break;
        case 3: showTop();
            break;
        case 4:cout << "\n����:";
            displayStack();
            break;
        case 5: clearStack();
            displayStack();
            break;
        case 6: flag = 0;
            break;
        }
    }
    return 0;
}