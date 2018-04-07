#include <todo.h>
#include <QString>
#include <QTextStream>
#include <QFile>

Todos::Todos(){
}

bool Todos::AddTodo(QString todo, QString file){
    QFile todosFile(file);
    if(todosFile.open(QIODevice::ReadWrite)){
        QString allTodos = "";
        QTextStream stream(&todosFile);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            allTodos.append(line + "\n");
        }
        allTodos.append(todo + "\n");
        todosFile.resize(0);
        stream<<allTodos;
        todosFile.close();
        return true;
    }else
        return false;
}

bool Todos::RemoveTodo(QString todo, QString file){
    QFile todosFile(file);
    if(todosFile.open(QIODevice::ReadWrite)){
        QString allTodos;
        QTextStream stream(&todosFile);
        bool found = false;
        while(!stream.atEnd()){
            QString line = stream.readLine();
            if(line != todo)
                allTodos.append(line + "\n");
            else
                found = true;
        }
        todosFile.resize(0);
        stream<<allTodos;
        todosFile.close();
        return found;
    }
    else
        return false;
}

void Todos::DisplayTodos(QString file){
    QFile todosFile(file);
    QTextStream cout(stdout);
    if(todosFile.open(QIODevice::ReadWrite)){
        QTextStream stream(&todosFile);
        while(!stream.atEnd()){
            cout<<stream.readLine()<<endl;
        }
        todosFile.close();
    }
}

bool Todos::HasTasks(QString file){
    QFile todosFile(file);
    QString allTodos = "";
    if(todosFile.open(QIODevice::ReadWrite)){
        QTextStream stream(&todosFile);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            allTodos.append(line + "\n");
        }
    }
    return !(allTodos == "");
}
