#pragma once

class IntCell
{
  friend class IntList;

private:
  IntCell(int value,
          IntCell *prev = nullptr,
          IntCell *next = nullptr) : value(value),
                                     prev(prev),
                                     next(next) {}

  int value;
  IntCell *prev;
  IntCell *next;
};

class IntList
{

public:
  IntList() : head(nullptr),
              tail(nullptr) {}

  void add_front(int e)
  {
    IntCell *front = new IntCell(e, nullptr, head);
    head->prev = front;
    head = front;
  }

private:
  IntCell *head;
  IntCell *tail;
};