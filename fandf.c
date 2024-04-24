// #include <iostream>
// #include <set>
// #include <vector>
// #include <map>

// using namespace std;

// // Define a structure for grammar rules
// struct Production {
//     char nonTerminal;
//     string production;
// };

// // Function to compute First set for a given non-terminal
// set<char> computeFirst(char nonTerminal, vector<Production>& productions, map<char, set<char>>& firstSets) {
//     if (firstSets.find(nonTerminal) != firstSets.end()) {
//         return firstSets[nonTerminal];
//     }

//     set<char> firstSet;

//     for (const auto& prod : productions) {
//         if (prod.nonTerminal == nonTerminal) {
//             if (isupper(prod.production[0])) { // If the first symbol is a non-terminal
//                 set<char> tempFirstSet = computeFirst(prod.production[0], productions, firstSets);
//                 firstSet.insert(tempFirstSet.begin(), tempFirstSet.end());
//             } else { // If the first symbol is a terminal
//                 firstSet.insert(prod.production[0]);
//             }
//         }
//     }

//     firstSets[nonTerminal] = firstSet;
//     return firstSet;
// }

// // Function to compute Follow set for a given non-terminal
// set<char> computeFollow(char nonTerminal, vector<Production>& productions, map<char, set<char>>& firstSets) {
//     set<char> followSet;

//     for (const auto& prod : productions) {
//         size_t pos = prod.production.find(nonTerminal);
//         if (pos != string::npos) { // Non-terminal found in production
//             if (pos == prod.production.size() - 1) { // Non-terminal is at the end
//                 if (prod.nonTerminal != nonTerminal) { // Avoid left recursion
//                     set<char> tempFollowSet = computeFollow(prod.nonTerminal, productions, firstSets);
//                     followSet.insert(tempFollowSet.begin(), tempFollowSet.end());
//                 }
//             } else { // Non-terminal is followed by a symbol
//                 if (isupper(prod.production[pos + 1])) { // If the next symbol is a non-terminal
//                     set<char> tempFirstSet = computeFirst(prod.production[pos + 1], productions, firstSets);
//                     followSet.insert(tempFirstSet.begin(), tempFirstSet.end());
//                     if (tempFirstSet.find('@') != tempFirstSet.end()) { // If @ is in First(next_symbol)
//                         set<char> tempFollowSet = computeFollow(prod.nonTerminal, productions, firstSets);
//                         followSet.insert(tempFollowSet.begin(), tempFollowSet.end());
//                     }
//                 } else { // If the next symbol is a terminal
//                     followSet.insert(prod.production[pos + 1]);
//                 }
//             }
//         }
//     }

//     return followSet;
// }

// int main() {
//     // Define the grammar rules
//     vector<Production> productions = {
//         {'S', "aAB"},
//         {'A', "@Bc"},
//         {'B', "d"}
//     };

//     // Map to store First sets
//     map<char, set<char>> firstSets;

//     // Compute First sets for each non-terminal
//     for (const auto& prod : productions) {
//         computeFirst(prod.nonTerminal, productions, firstSets);
//     }

//     // Map to store Follow sets
//     map<char, set<char>> followSets;

//     // Compute Follow sets for each non-terminal
//     for (const auto& prod : productions) {
//         followSets[prod.nonTerminal] = computeFollow(prod.nonTerminal, productions, firstSets);
//     }

//     // Print First sets
//     cout << "First sets:\n";
//     for (const auto& pair : firstSets) {
//         cout << pair.first << ": ";
//         for (char terminal : pair.second) {
//             cout << terminal << " ";
//         }
//         cout << endl;
//     }

//     // Print Follow sets
//     cout << "\nFollow sets:\n";
//     for (const auto& pair : followSets) {
//         cout << pair.first << ": ";
//         for (char terminal : pair.second) {
//             cout << terminal << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

//Follow
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n,m=0,p,i=0,j=0;
char a[10][10],followResult[10];
void follow(char c);
void first(char c);
void addToResult(char);
int main()
{
 int i;
 int choice;
 char c,ch;
 printf("Enter the no.of productions: ");
scanf("%d", &n);
 printf(" Enter %d productions\nProduction with multiple terms should be give as separate productions \n", n);
 for(i=0;i<n;i++)
  scanf("%s%c",a[i],&ch);
    // gets(a[i]);
 do
 {
  m=0;
  printf("Find FOLLOW of -->");
  scanf(" %c",&c);
  follow(c);
  printf("FOLLOW(%c) = { ",c);
  for(i=0;i<m;i++)
   printf("%c ",followResult[i]);
  printf(" }\n");
  printf("Do you want to continue(Press 1 to continue....)?");
 scanf("%d%c",&choice,&ch);
 }
 while(choice==1);
}
void follow(char c)
{
    if(a[0][0]==c)addToResult('$');
 for(i=0;i<n;i++)
 {
  for(j=2;j<strlen(a[i]);j++)
  {
   if(a[i][j]==c)
   {
    if(a[i][j+1]!='\0')first(a[i][j+1]);
    if(a[i][j+1]=='\0'&&c!=a[i][0])
     follow(a[i][0]);
   }
  }
 }
}
void first(char c)
{
      int k;
      if(!(isupper(c)))
         //f[m++]=c;
        addToResult(c);
        for(k=0;k<n;k++) {
            if(a[k][0]==c) {
                if(a[k][2]=='$') follow(a[i][0]);
                else if(islower(a[k][2]))
                  //f[m++]=a[k][2];
                  addToResult(a[k][2]);
                else first(a[k][2]);
        }
    }
}
void  addToResult(char c)
{
    int i;
    for( i=0;i<=m;i++)
        if(followResult[i]==c)
            return;
   followResult[m++]=c;
}