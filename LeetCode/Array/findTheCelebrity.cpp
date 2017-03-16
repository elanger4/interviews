// Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

// Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

// You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

// Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return 0.

/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

#include <iostream>
#include "assert.h"

int knowsPerson[5][5] = {0};

int knows(int celeb, int person) {
    // 1 if celeb knows person
    
    // 0 if celeb does not knows person
    
    // Returns 1 for tesing
    return knowsPerson[celeb][person];
}

int findCelebrity(int n) {

    // 'i' is the potential celebrity
    int celebCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            std::cout << i << " " << j << std::endl;
            if (knows(j,i)) {
                if (!knows(i,j)) {
                    celebCount += 1;
                } else {
                    celebCount = 0;
                    break;
                }
            } else {
                celebCount = 0;
                break;
            }
        }

        if (celebCount == n-1) {
            return 1;
        }

        celebCount = 0;
    }
    return 0;
}


int main() {


    // 4 is the celebrity
    knowsPerson[0][0] = 0;
    knowsPerson[0][1] = 0;
    knowsPerson[0][2] = 1;
    knowsPerson[0][3] = 1;
    knowsPerson[0][4] = 1;
    knowsPerson[1][0] = 1;
    knowsPerson[1][1] = 1;
    knowsPerson[1][2] = 1;
    knowsPerson[1][3] = 1;
    knowsPerson[1][4] = 1;
    knowsPerson[2][0] = 0;
    knowsPerson[2][1] = 1;
    knowsPerson[2][2] = 0;
    knowsPerson[2][3] = 0;
    knowsPerson[2][4] = 1;
    knowsPerson[3][0] = 1;
    knowsPerson[3][1] = 0;
    knowsPerson[3][2] = 0;
    knowsPerson[3][3] = 1;
    knowsPerson[3][4] = 1;
    knowsPerson[4][0] = 0;
    knowsPerson[4][1] = 0;
    knowsPerson[4][2] = 0;
    knowsPerson[4][3] = 0;
    knowsPerson[4][4] = 0;

    assert(findCelebrity(5) == 1);

    std::cout << "\n Passed Test Case!" << std::endl;
}
