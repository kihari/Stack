#include <iostream>
using namespace std;

//Узел
struct Node
{
    char data;
    
    Node* link; //Указатель типа Node на следующий элемент
};

//Указатель для отслеживания вершины стека
Node* top = NULL;

//Функция для проверки пустоты стека
bool isempty()
{
    if (top == NULL)
        return true; 
    else
        return false;
}

//Добавление элемента в стек
void push(char value)
{
    Node* comp = new Node();//Создаем новый указатель типа структуры Node и выделяем память для нового элемента
    comp->data = value;
    comp->link = top; //Проводим связь от нового элемента к вершине.
    top = comp; //Вершиной теперь является новый элемент
}

//Удаление элемента
void pop()
{
    if (isempty())
        cout << "\nСтек пустой\n";
    else
    {
        Node* comp = top;
        top = top->link;
        delete(comp);
    }
}

// Вывод верхнего элемента стека
void showTop()
{
    if (isempty())
        cout << "\nСтек пустой\n";
    else
        cout << "\nВерхний элемент : " << (char)top->data<<endl;
}

// Печать стека
void displayStack()
{
    if (isempty())
        cout << "\nСтек пустой\n";
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

// Очистка стека
void clearStack()
{
    if (isempty())
        cout << "\nСтек пустой\n";
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
        cout << "\n1.Добавить символ \n2.Удалить символ \n3.Вывести верхний символ \n4.Вывести стек \n5.Очистка стека \n6.Выход\n";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << "\nВведите символ:\n";
            cin >> value;
            push(value);
            cout << "\nСтек:";
            displayStack();
            break;
        case 2: pop();
            cout << "\nСтек:";
            displayStack();
            break;
        case 3: showTop();
            break;
        case 4:cout << "\nСтек:";
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