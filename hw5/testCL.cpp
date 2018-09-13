#include "CircleList.h"
#include <iostream>
using namespace std;

int main() {
    CircleList<string> playList;
  
    if (playList.empty())
        cout << "You successfully made an empty list!" << endl;
  
    playList.add("Stayin Alive"); // [Stayin Alive*]
    cout << playList.front() << endl; // print Stayin Alive
    cout << playList.back() << endl; // print Stayin Alive

    playList.add("Le Freak"); // [Le Freak, Stayin Alive*]
    cout << playList.front() << endl; // print Le Freak
    cout << playList.back() << endl; // print Stayin Alive

    playList.add("Jive Talkin"); // [Jive Talkin, Le Freak, Stayin Alive*]
    cout << playList.front() << endl; // print Jive Talkin
    cout << playList.back() << endl; // print Stayin Alive

    playList.advance(); // [Le Freak, Stayin Alive, Jive Talkin*]
    cout << playList.front() << endl; // print Le Freak
    cout << playList.back() << endl; // print Jive Talkin

    playList.advance(); // [Stayin Alive, Jive Talkin, Le Freak*]
    cout << playList.front() << endl; // print Stayin Alive
    cout << playList.back() << endl; // print Le Freak

    playList.remove(); // [Jive Talkin, Le Freak*]
    cout << playList.front() << endl; // print Jive Talkin
    cout << playList.back() << endl; // print Le Freak

    playList.add("Disco Inferno"); // [Disco Inferno, Jive Talkin, Le Freak*]
    cout << playList.front() << endl; // print Disco Inferno
    cout << playList.back() << endl; // print Le Freak

    return 0;
}
