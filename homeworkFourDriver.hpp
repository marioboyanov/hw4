#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book{
    //Protected so the friend function can access the variables
 protected:
    string name;
    string author;
    int pages;
    
 public:
    Book(){
        name = "";
        author = "";
        pages = 0;
    };
    Book(string n, string a, int p){
        name = n;
        author = a;
        pages = p;
    };
    virtual void type() const = 0;//
    
    void setName(string name){
        if(name.length()<= 0){
            this->name = "Default name";
        } else this->name = name;
    };
    string getName()const{
        return name;
    };
    void setAuthor(string author){
        if(author.length() <= 0){
            this->author = "Default author";
        } else this->author = author;
        
    };
    string getAuthor()const{
        return author;
    };
    void setPages(int pages){
        if(pages < 0){
            this->pages = 0;
        }else{
            this->pages = pages;
        }
    };
    int getPages()const{
        return pages;
    };
    //Overloaded equality operatot
    bool operator==(const Book& other) const {
           return (name == other.name) && (author == other.author);//
       }
    
    virtual ~Book() {}
    
};
//Inheriting from Book
class ChildrenBook : public Book{
private:
    int ageAppropriate;
    
public:
    ChildrenBook(){
        ageAppropriate = 0;
    };
    ChildrenBook(string n, string a, int p, int age):Book(n,a,p){
        ageAppropriate = age;
    };
    
    void setAgeAppropriate(int ageAppropriate){
        if(ageAppropriate < 5){
            cout << "This book is not appropriate for this age!" << endl;
        }else{
            this -> ageAppropriate = ageAppropriate;
        }
    };
    int getAgeAppropriate()const{
        return ageAppropriate;
    };
    //Implementing the type() method for ChildrenBook class
    void type()const override{
        cout << "Children book for " << ageAppropriate << " and older" << endl;
    }
    //friend function overloading >>
    friend istream& operator>>(istream& input, ChildrenBook& book){
        cout << "Enter name: ";
        input >> book.name;
        
        cout << "Enter author: ";
        input >> book.author;
        
        cout << "Enter pages: ";
        input >> book.pages;
        
        cout << "Enter appropriate age: ";
        input >> book.ageAppropriate;
        
        return input;
        
    }
};

class SeriousBook : public Book{
private:
    string genre;
    
public:
    SeriousBook():Book(){
        genre = "";
    }
    SeriousBook(string n, string a, int p, string g): Book(n,a,p){
        genre= g;
    }
    void setGenre(string genre){
        if(genre != "Fiction" and genre != "Romance" and genre != "Fiction"){
            cout << "Invalid genre!";
        }else{
            this->genre = genre;
        }
    }
    string getGenre()const{
        return genre;
    }
    //Implementing the type() method for SeriousBook class
    void type()const override{
        cout << "Serious book, genre: " << genre << endl;
    }
};

