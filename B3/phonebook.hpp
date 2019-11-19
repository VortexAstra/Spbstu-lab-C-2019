#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>

struct PhonebookElement
{
  std::string number;
  std::string name;
};
class Phonebook
{
public:

  Phonebook();
  Phonebook(const Phonebook &phb);
  Phonebook(Phonebook &&phb) = default;

  Phonebook& operator=(const Phonebook &phb);
  Phonebook& operator=(Phonebook &&phb) = default;

  void addElement(const PhonebookElement &element);
  void deleteElement(const std::string &bookmark);
  void replaceElement(const std::string &bookmark, const PhonebookElement &element);
  void showElementName(const std::string &bookmark, std::ostream &out);

  void addBookmark(const std::string &currentBookmark, const std::string &newBookmark);
  void insertBefore(const std::string &boomark, const PhonebookElement &element);
  void insertAfter(const std::string &bookmark, const PhonebookElement &element);
  void moveBoomark(const std::string &bookmark, int steps);
  void moveBoomark(const std::string &bookmark, const std::string &location);
  void moveToNext(const std::string &bookmark);
  void moveToPrev(const std::string &bookmark);

private:

  struct EntryElem
  {
    PhonebookElement element;
    std::set<std::string> bookmarks;
  };

  typedef std::list<EntryElem> entries_type;
  typedef std::map<std::string, entries_type::iterator> bookmarks_type;
  typedef bookmarks_type::iterator bookmarksIt_type;

  entries_type entries_; //zapisi
  bookmarks_type bookmarks_;

  bookmarksIt_type getIterator(const std::string & bookmark);
};


#endif
