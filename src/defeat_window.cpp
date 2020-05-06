#include "include/defeat_window.h"

#include <QVBoxLayout>
#include <QMovie>

using namespace std;

DefeatWindow::DefeatWindow()
{
    title = new QLabel("Vous êtes mort");
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(40);
    title->setFont(font);

    image = new QLabel();
    QMovie *movie = new QMovie("image/screen/death_dance.gif");
    image->setMovie(movie);
    movie->start();
    image->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(title);
    layout->addWidget(image);
    setLayout(layout);
}

DefeatWindow::~DefeatWindow()
{
    delete title;
}