#include "include/marchand.h"

#include <vector>

using namespace std;

void Merchant::init(){
    fillShopWithNewArticles(6);
    printArticleList();
}

void Merchant::printArticleList(){
    std::vector<Article>::iterator it = articleList.begin();
    for ( ; it != articleList.end(); it++){
        it->printArticle();
    }
}


void Merchant::fillShopWithNewArticles(int nbOfArticles){
    while (articleList.size() > 0 ){
        articleList.pop_back();
    }

    for (int i = 0; i < nbOfArticles ; i++){
        articleList.push_back(Article::createArticle());
    }
}
