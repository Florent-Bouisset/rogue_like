#include "include/article.h"

#include <typeinfo>
#include <memory>
#include <iostream>

using namespace std;

Article::Article(int p_price, shared_ptr<Item> p_item){
    price = p_price;
    item = p_item;
}


void Article::printArticle(){
    cout << "Item: " << item->getName() << " prix : " << price << endl;
}


Article Article::createArticle(ArticleType type){
    switch (type)
    {
    case ArticleType::RELIC:
        return Article(35, Relic::createRelic());

    case ArticleType::POTION:
        return Article(15, Potion::createPotion());

    default:
        return Article(15, Potion::createPotion());
    }
}

Article Article::createArticle(){
    ArticleType randomType = static_cast<enum ArticleType> (rand() % ARTICLE_TYPE_MAX_VALUE);
    return createArticle(randomType);
}

int Article::getPrice(){
    return price;
}

shared_ptr<Item> Article::getItem(){
    return item;
}