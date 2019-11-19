#include "phonebook.hpp"

Phonebook::Phonebook()
{
  bookmarks_["current"] = entries_.end();
}
Phonebook::Phonebook(const Phonebook &other)
{
  *this = other;
}
Phonebook& Phonebook::operator=(const Phonebook &other)
{
  if(this != &other)
  {
    entries_ = other.entries_;
    bookmarks_.clear();
    for(auto it = other.bookmarks_.cbegin(); it != other.bookmarks_.cend(); it++)
    {
      std::list<EntryElem>::const_iterator bookmarked = it->second;
      bookmarks_[it->first] = std::next(entries_.begin(), std::distance(other.entries_.cbegin(), bookmarked));
    }
  }
  return *this;
}
void Phonebook::addElement(const PhonebookElement &Element)
{
  EntryElem newElement;
  newElement.element = Element;

  if(entries_.empty())
  {
    newElement.bookmarks.insert("current");
    entries_.push_back(newElement);
    bookmarks_["current"] = entries_.begin();
  }
  else
  {
    entries_.push_back(newElement);
  }
}
void Phonebook::addBookmark(const std::string &currentBookmark, const std::string &newBookmark)
{
  auto it = getIterator(currentBookmark);
  bookmarks_[newBookmark] = it->second;

  if(it->second != entries_.end())
  {
    it->second->bookmarks.insert(newBookmark);
  }
}
void Phonebook::insertBefore(const std::string &bookmark, const PhonebookElement &Element)
{
  if(entries_.empty())
  {
    addElement(Element);
    return;
  }
  auto it = getIterator(bookmark);
  if(it->second != entries_.end())
  {
    entries_.insert(it->second, EntryElem{ Element, });
  }
  else
  {
    entries_.push_back(EntryElem{ Element, });
  }
}
void Phonebook::insertAfter(const std::string &bookmark, const PhonebookElement &entry)
{
  if(entries_.empty())
  {
    addElement(entry);
    return;
  }
  auto it = getIterator(bookmark);
  if(it->second != entries_.end())
  {
    entries_.insert(std::next(it->second), EntryElem{ entry, });
  }
  else
  {
    entries_.push_back(EntryElem{entry, });
  }
}
void Phonebook::deleteElement(const std::string &bookmark)
{
  auto it = getIterator(bookmark);
  if(it->second != entries_.end())
  {
    auto clistElem = it->second;
    for(auto j = clistElem->bookmarks.begin(); j != clistElem->bookmarks.end(); j++)
    {
      if((std::next(clistElem) == entries_.end()) && (entries_.size() > 1))
      {
        bookmarks_[*j] = std::prev(clistElem);
        std::prev(clistElem)->bookmarks.insert(*j);
      }
      else
      {
        bookmarks_[*j] = std::next(clistElem);
        if(std::next(clistElem) != entries_.end())
        {
          std::next(clistElem)->bookmarks.insert(*j);
        }
      }
    }
    entries_.erase(clistElem);
  }
}
void Phonebook::showElementName(const std::string &bookmark, std::ostream &out)
{
  auto it = getIterator(bookmark);
  if(it->second == entries_.end())
  {
    out << "<EMPTY>" << std::endl;
  }
  else
  {
    out << it->second->element.number << " " << it->second->element.name << std::endl;
  }
}
void Phonebook::replaceElement(const std::string &bookmark, const PhonebookElement &Element)
{
  auto it = getIterator(bookmark);
  it->second->element = Element;
}
void Phonebook::moveBoomark(const std::string &bookmark, int steps)
{
  auto it = getIterator(bookmark);

  if(it->second != entries_.end())
  {
    it->second->bookmarks.erase(bookmark);
  }

  std::advance(it->second, steps); //prodvizenie

  if(it->second != entries_.end())
  {
    it->second->bookmarks.insert(bookmark);
  }

}
void Phonebook::moveBoomark(const std::string &bookmark, const std::string &location)
{
  auto it = getIterator(bookmark);
  if(location == "first")
  {
    if(it->second != entries_.end())
    {
      it->second->bookmarks.erase(bookmark);
    }

    if(!entries_.empty())
    {
      it->second = entries_.begin();
      it->second->bookmarks.insert(bookmark);
    }
    else
    {
      it->second = entries_.end();
    }
  }
  else if(location == "last")
  {
    if(it->second != entries_.end())
    {
      it->second->bookmarks.erase(bookmark);
    }
    if(!entries_.empty())
    {
      it->second = std::prev(entries_.end());
      it->second->bookmarks.insert(bookmark);
    }
    else
    {
      it->second = entries_.end();
    }
  }
  else
  {
    throw std::invalid_argument("<INVALID STEP>");
  }
}
void Phonebook::moveToNext(const std::string &bookmark)
{
  moveBoomark(bookmark, 1);
}
void Phonebook::moveToPrev(const std::string &bookmark)
{
  moveBoomark(bookmark, -1);
}
Phonebook::bookmarksIt_type Phonebook::getIterator(const std::string &bookmark)
{
  auto it = bookmarks_.find(bookmark);
  if(it == bookmarks_.end())
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
  return it;
}

