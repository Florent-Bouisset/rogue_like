#ifndef DEFEAT_WINDOW_H
#define DEFEAT_WINDOW_H

#include <QWidget>
#include <QLabel>

class DefeatWindow : public QWidget
{
public:
    DefeatWindow();
    ~DefeatWindow();

private:
    QLabel *title;
};

#endif
