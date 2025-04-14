#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <map>

void array() {
    //Creating array
    const std::array<std::string, 7> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    //Getting its length.
    std::cout << days.size() << std::endl;

    //List the array.
    for (const std::string& day : days) {
        std::cout << day << std::endl;
    }
}

void vector() {
    //Create a vector
    std::vector<int> newVector {1,2,3,4,5};
    //Add 6 and 7 to the end of the array.
    newVector.push_back(6);
    newVector.push_back(7);
    //Print the current vectors.
    for (const int& num : newVector) {
        std::cout << num << std::endl;
    }
    std::cout << "===========================" << std::endl;
    //Remove the vector at the very end.
    newVector.pop_back();
    //Print the current vectors.
    for (const int& num : newVector) {
        std::cout << num << std::endl;
    }
}

void list() {
    //Create a new list.
    std::list<std::string> myList = {"Apple", "Banana", "Cherry"};
    //Append orange to the very end.
    myList.push_back("Orange");
    //Append Pear to the very start.
    myList.push_front("Pear");
    //Remove one of the elements.
    myList.remove("Banana");
    for (const std::string& fruit : myList) {
        std::cout << fruit << std::endl;
    }
}

void map() {
    //Create a new map.
    std::map<std::string, int> myMap = {{"Apples", 10}, {"Bananas", 5}, {"Cherries", 3}};
    //Insert a new key-value pair.
    myMap.insert({"Oranges", 15});
    //Edit the apples key value pair to remove one apple.
    myMap["Apples"] = myMap["Apples"] - 1;
    //Print out every entry.
    for (const std::pair<std::string, int> pair : myMap) {
        //.first - key || .second - value
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {

    array();
    std::cout << "===========================" << std::endl;
    vector();
    std::cout << "===========================" << std::endl;
    list();
    std::cout << "===========================" << std::endl;
    map();
}
