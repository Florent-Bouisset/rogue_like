#ifndef MARCHAND_H
#define MARCHAND_H

#include <vector>
#include "article.h"

class Merchant
{

public:
    void init();

protected:
    void printArticleList();
    std::vector<Article> articleList;
    void fillShopWithNewArticles(int nbOfArticle);
};

#endif
