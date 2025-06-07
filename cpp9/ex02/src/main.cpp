#include "../includes/PmergeMe.hpp"

int main (int argc, char **argv) {

   if (argc < 2) {
      std::cerr << "Usage: ./PmergeMe [positive integers]" << std::endl;
      return (1);
   }   

   try {
      PmergeMe pmerge;
      pmerge.processArgs(argv);
      pmerge.displayElapsedTime();
      pmerge.checkSorting();
   } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return (2);
   }

   return 0;
}
