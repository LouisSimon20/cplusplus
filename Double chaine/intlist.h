#ifndef INTLIST_H
#define INTLIST_H

class IntCell { 
   friend class IntList;
private:
   IntCell(int valeur);
   int value;
   IntCell* next_cell=nullptr;
   IntCell* previous_cell=nullptr;
};

class IntList {
public:    
   ~IntList();
   void add_front (int valeur);
   void add_back (int valeur);
   void remove_front ();
   void remove_back ();
   void remove (int valeur);
   bool search (int value);
   void print ();

private:
   IntCell* first_cell=nullptr;
   IntCell* last_cell=nullptr;
};
#endif