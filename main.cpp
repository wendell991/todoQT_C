#include <QCoreApplication>
#include<QTextStream>
#include<todo.h>
#include<QProcess>
#include<QDir>

int main(int argc, char *argv[])
{
    QString str1 = " ";
    QTextStream qtcin(stdin);
    QTextStream qtcout(stdout);
    QString filename = "Todos.txt";
    Todos todolist;
    QFile file(filename);
    if(!file.exists()){
        file.open(QIODevice::ReadWrite);
        file.close();
    }
    while(str1 != ""){
        system("CLS");
        if(todolist.HasTasks(filename)){
            qtcout<<"Todo Lists"<<endl;
            todolist.DisplayTodos(filename);
        }
        int choice;
        QString choiceString;
        qtcout<<"[1]Add Todo"<<endl<<"[2]Remove Todo"<<endl<<"To Exit Add a blank todo"<<endl;
        choiceString = qtcin.readLine();
        choice = choiceString.toInt();
        switch (choice) {
            case 1:
                qtcout<<"Add Todo:"<<endl;
                str1 = qtcin.readLine();
                if(str1!=""){
                    todolist.AddTodo(str1,filename);
                }
                break;
            case 2:
                qtcout<<"Remove Todo:"<<endl;
                str1 = qtcin.readLine();
                if(str1=="")
                    str1=" ";
                else
                    todolist.RemoveTodo(str1,filename);
                break;
            default:
                break;
        }
    }
    return 0;
}
