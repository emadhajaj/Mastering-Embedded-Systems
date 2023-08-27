#include <stdio.h>
#include <string.h>

int main() {
   char str[100], temp;
   int i=0, j;
   
   printf("Enter a string to reverse: ");
   gets(str);
   
   j = strlen(str) - 1;
   
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
   
   printf("Reverse of the string: %s", str);
   
   return 0;
}