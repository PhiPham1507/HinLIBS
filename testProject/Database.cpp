#include "Database.h"
#include <vector>
#include "fictionBook.h"
#include "nonFictionBook.h"
#include "magazine.h"
#include "videoGame.h"
#include "movie.h"
#include "patron.h"
#include "librarian.h"
#include "admin.h"
Database::Database(){
    items.push_back(new FictionBook("Catcher in the Rye", "J.D. Salinger", 1951, 9780316769488));
    items.push_back(new FictionBook("To Kill a Mockingbird", "Harper Lee", 1960, 9780061120084));
    items.push_back(new FictionBook("1984", "George Orwell", 1949, 9780451524935));
    items.push_back(new FictionBook("Brave New World", "Aldous Huxley", 1932, 9780060850524));
    items.push_back(new FictionBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, 9780743273565));
    items.push_back(new NonFictionBook("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "303", 2011, 9780062316097));
    items.push_back(new NonFictionBook("Educated", "Tara Westover", "371.4", 2018, 9780399590504));
    items.push_back(new NonFictionBook("The Immortal Life of Henrietta Lacks", "Rebecca Skloot", "616.0276", 2010, 9781400052189));
    items.push_back(new NonFictionBook("Thinking, Fast and Slow", "Daniel Kahneman", "153.4", 2011, 9780374533557));
    items.push_back(new NonFictionBook("Guns, Germs, and Steel", "Jared Diamond", "909", 1997, 9780393317558));
    items.push_back(new Magazine("National Geographic", "Various Authors", 2025, 3, Date(15,3,2025), 9781426217782));
    items.push_back(new Magazine("Time", "Various Authors", 2025, 7, Date(1,7,2025), 9781618935763));
    items.push_back(new Magazine("The New Yorker", "Various Authors", 2025, 20, Date(20,10,2025), 9781640970902));
    items.push_back(new Movie("The Shawshank Redemption", "Frank Darabont", 1994, "Drama", 9, 9780786012672));
    items.push_back(new Movie("Inception", "Christopher Nolan", 2010, "Sci-Fi", 8, 9780812997392));
    items.push_back(new Movie("The Godfather", "Francis Ford Coppola", 1972, "Crime", 10, 9780451205766));
    items.push_back(new VideoGame("The Legend of Zelda: Breath of the Wild", "Nintendo", 2017, "Action-Adventure", 10, 9781770150457));
    items.push_back(new VideoGame("The Witcher 3: Wild Hunt", "CD Projekt", 2015, "RPG", 9, 9781785291212));
    items.push_back(new VideoGame("Minecraft", "Mojang Studios", 2011, "Sandbox", 8, 9780692335976));
    items.push_back(new VideoGame("God of War", "Santa Monica Studio", 2018, "Action", 9, 9781506716439));

    accounts.push_back(new Patron("john323", "littlejohn"));
    accounts.push_back(new Patron("dane113", "dane"));
    accounts.push_back(new Patron("littlehenry", "henry16"));
    accounts.push_back(new Patron("harry9", "hair"));
    accounts.push_back(new Patron("moneylover", "$$"));
    accounts.push_back(new Librarian("lib1", "lib1"));
    accounts.push_back(new Admin("admin1", "admin1"));

}
Database::~Database(){
    for(Item* item: items){
        delete item;
    }
    for(Account* acc: accounts){
        delete acc;
    }
}

Item* Database::getItem(int i){
    return items.at(i);
}
int Database::itemSize(){
    return items.size();
}

Account* Database::findUser(const string &username){
    for(Account* acc: accounts){
        if(acc->getAccountName() == username){
            return acc;
        }
    }
    return nullptr;
}

Item* Database::findItem(int id) const{
    for(Item* item : items){
        if(item->getId() == id) return item;
    }
    return nullptr;
}

