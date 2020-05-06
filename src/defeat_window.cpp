#include "include/defeat_window.h"

#include <QVBoxLayout>

using namespace std;

DefeatWindow::DefeatWindow()
{
    title = new QLabel("Vous êtes mort");
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(40);
    title->setFont(font);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(title);
    setLayout(layout);
}

DefeatWindow::~DefeatWindow()
{
    delete title;
}