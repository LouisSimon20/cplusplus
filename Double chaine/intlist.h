#include <iostream>

class IntCell { 
   friend class IntList;
private:
   IntCell(int valeur)
   {
     value = valeur;
   }

   int value;
   IntCell* next_cell=0;
   IntCell* previous_cell=0;
};


class IntList {
public:    
   IntList(){

   }

   ~IntList(){
      //a modifier
      IntCell* pcell = last_cell;
      while(pcell!=first_cell){
         delete pcell->next_cell;
         pcell = pcell->previous_cell;
      }
      delete pcell;
   }

   void add_front (int valeur) {
      IntCell* pcell = new IntCell(valeur);
      //std::cout << pcell /*<< "  "<< *(pcell->pvalue) << " " << pcell->pvalue */<< std::endl;

      if (first_cell!=0){
         pcell->next_cell = first_cell; // lien vers la queue de liste
         first_cell->previous_cell = pcell;  //lien vers la tête de liste
      }
      if (first_cell == 0 and last_cell!=0){
         pcell->next_cell = last_cell; // lien retour
         last_cell->previous_cell = pcell;  //lien avant
      }
      if (first_cell == 0 and last_cell == 0){
         last_cell = pcell;
      }
      first_cell = pcell; //actualisation liste
   }

   void add_back (int valeur) {
      IntCell* pcell = new IntCell(valeur);

      if (last_cell != 0){
         pcell->previous_cell = last_cell;
         last_cell->next_cell = pcell;
      }
      if (last_cell == 0 and first_cell!=0){
         pcell->previous_cell = first_cell; // lien retour
         first_cell->next_cell = pcell;  //lien avant
      }
      if (first_cell == 0 and last_cell == 0){
         first_cell = pcell;
      }
      last_cell = pcell; //actualisation liste
   }

   void remove_front () {
      if (first_cell !=0){
         first_cell = first_cell->next_cell;
         delete first_cell->previous_cell;
      }
   }
   
   void remove_back () {
      if (last_cell !=0){
         last_cell = last_cell->previous_cell;
         delete last_cell->next_cell;
      }
   }

   void remove (int valeur) {
         IntCell* pcell = last_cell;

         while(pcell->previous_cell != 0){
            if (valeur == pcell->value){

               if (pcell == first_cell){
                  (pcell->next_cell)->previous_cell = 0;
                  first_cell = pcell->next_cell;
               }

               if (pcell == last_cell){
                  (pcell->previous_cell)->next_cell = 0;
                  last_cell = pcell->previous_cell;
               }
               else{
                  (pcell->previous_cell)->next_cell = pcell->next_cell;
                  (pcell->next_cell)->previous_cell = pcell->previous_cell;
               }
               
               delete pcell;
               break;
            }
            pcell = pcell->previous_cell;
         }
      }

   bool search (int value) {
      bool result = false;
      IntCell* pcell = last_cell;

      while((pcell->previous_cell != 0) and result == false){
         if (value == pcell->value){
            result = true;
         }
         pcell = pcell->previous_cell;
      }
      return result;
   }

   void print () {
      std::cout << '{';
      IntCell* pcell = last_cell;

      while(pcell!= first_cell)
      {
         std::cout << pcell->value << " ";
         pcell = pcell->previous_cell;
      }
      std::cout << first_cell->value << "}" << std::endl;

    }
private:
   IntCell* first_cell=0;
   IntCell* last_cell=0;
};