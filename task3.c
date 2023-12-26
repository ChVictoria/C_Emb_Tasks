#define TITLE_LENGTH 50
#define LANG_LENGTH 20
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char title[TITLE_LENGTH];
    float price;
    unsigned int numberOfPages;
    char lang [LANG_LENGTH];
    float weight;
    unsigned int year;
} book;


typedef struct item
{
    book harryPotterBook;
    struct item *nextBook;
}item;



void insertEnd(book book, item **head) {
    item *lastBook = (item *) malloc(sizeof(item));
    lastBook->harryPotterBook = book;
    lastBook->nextBook = NULL;
    struct item *catalog = *head;
    if (*head != NULL) {
        while (catalog->nextBook != NULL) {
            catalog = catalog->nextBook;
        }
        catalog->nextBook = lastBook;
    }else{
        *head = lastBook;
    }
}

void deleteList(item *head){
    item *currentItem;
    item *nextItem = head;
    while(nextItem != NULL) {
        currentItem = nextItem;
        nextItem = currentItem->nextBook;
        free(currentItem);
    }
}

void printCatalog(item *head){
    item *currentBook = head;
    unsigned int i = 1;
    while(currentBook != NULL) {
        printf("-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n"
               "%d. %s\n"
               "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n"
               "price: %.3f $\n"
               "pages: %u\n"
               "language: %s\n"
               "weight: %.3f g\n"
               "year: %u\n"
               "-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n",
               i,
               currentBook->harryPotterBook.title,
               currentBook->harryPotterBook.price,
               currentBook->harryPotterBook.numberOfPages,
               currentBook->harryPotterBook.lang,
               currentBook->harryPotterBook.weight,
               currentBook->harryPotterBook.year);
        currentBook  = currentBook->nextBook;
        i++;
    }
}

int main(){
    item *head = NULL;
    book book1 = {"Philosopher's Stone", 10.35,223,"english",379.884,2014};
    book book2 = {"Chamber of Secrets", 21.98,341,"english",1587.57,2016};
    book book3 = {"Prisoner of Azkaban", 27.285,383,"ukrainian",370,2017};
    insertEnd(book1, &head);
    insertEnd(book2, &head);
    insertEnd(book3, &head);
    printCatalog(head);
    deleteList(head);
}
