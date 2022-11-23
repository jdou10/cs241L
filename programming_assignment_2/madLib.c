/* Dou Jingru
cs 241L this program is madLib to print out what I have typed
*/
#include <stdio.h>

int main(void) {
   char firstName[50];
   char genericLocation[50];
   int  wholeNumber;
   char pluralNoun[50];
   
   scanf("%s %s %d %s", firstName, genericLocation, &wholeNumber, pluralNoun);
   printf("%s went to %s to buy %d different types of %s.\n", firstName, genericLocation, wholeNumber, pluralNoun);

   return 0;
}
