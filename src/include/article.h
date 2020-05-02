#ifndef ARTICLE_H
#define ARTICLE_H

#include "relic.h"
#include "potion.h"
#include "item.h"
#include <memory>

enum ArticleType
{
    RELIC,
    POTION,
    ARTICLE_TYPE_MAX_VALUE
};

class Article
{
public:
    Article(int price, std::shared_ptr<Item> item);
    void printArticle();
    int getPrice() const;
    std::shared_ptr<Item> getItem();
    static Article createArticle();
    static Article createArticle(ArticleType);

protected:
    int price;
    std::shared_ptr<Item> item;
};

#endif