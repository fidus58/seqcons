//
//  main.cpp
//  seqcons
//
//  Created by Klaus Ahrens on 22.06.21.
//

#include <iostream>
#include <thread>

int x,y;
int r1,r2;

void t1f(){
    x = 1;
    r1 = y;
}

void t2f(){
    y = 1;
    r2 = x;
}

int main() {
    while(true) {
        std::cout<<".";
        x=y=r1=r2=0;
        std::thread t1{t1f};
        std::thread t2{t2f};
        t1.join();
        t2.join();
        if(!r1 && !r2) {
            std::cout<<r1<<r2<<"\n";
            return 1;
        }
    }
}
