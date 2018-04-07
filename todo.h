#ifndef TODO_H
#define TODO_H

#include<QString>
#include<QFile>

class Todos{
public:
    Todos();
    bool AddTodo(QString todo, QString file);
    void DisplayTodos(QString file);
    bool RemoveTodo(QString todo, QString file);
    bool HasTasks(QString file);
    QFile todosFile;
};

#endif // TODO_H
