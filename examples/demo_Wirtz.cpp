#include <../src/Stack.cpp>
#include <../src/HashMap.cpp>
#include <../src/LinkedList.cpp>
#include <../include/MeasurementHelper/randomString.hpp>
#include <../include/MeasurementHelper/timer.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <list>

using namespace ProjektAlpha;

int main() {
    // ProjektAlpha::Stack<int> stack;

    // stack.push(3);
    // stack.push(1);
    // stack.push(5);
    // stack.push(4);
    // stack.push(10);

    // stack.print();

    // int test = stack.pop();
    // stack.print();

    /*ProjektAlpha::HashMap<std::string> map(32);

    map.add(std::string("Test_String1"));
    map.add(std::string("Test_String2"));

    std::cout << ("Test_String1" == *map.begin());

    map.print();

    std::cout << map.get_size() << std::endl;

    for (auto it : map) {
        std::cout << it << std::endl;
    }*/

    Stack<std::string> own_stack;
    std::stack<std::string> cpp_stack;
    HashMap<std::string> own_hashmap(32);
    std::map<int, std::string> cpp_hashmap;
    LinkedList<std::string> own_linkedlist;
    std::list<std::string> cpp_linkedlist;

    RandomString rand_str(32);
    std::string random_string;

    int ticker;

    std::ofstream measurement_stack;
	measurement_stack.open("C:/Users/tiliw/OneDrive/Desktop/Uni/2. Semester/POOSE/projektalpha/measurement_stack.csv"); //Only works with absolut path
	measurement_stack << "Number of values in datastructure; own Stack; cpp Stack\n";

    ticker = 1;
	for (int i = 0; i < 1000000; i++) {
		if (i % 3922 == 0) { //* Excel kann nur 255 Spalten, daher in 79 Schritten bei 20000 Einträgen maximal (20000/79 = etwa 255)

            random_string = rand_str.generate();
            //std::cout << random_string <<std::endl;

			//* Timer for all measurements
			Timer timer_own_stack;
			Timer timer_cpp_stack;

			//* measurement own Stack
			timer_own_stack.start();
            own_stack.push(random_string);
			timer_own_stack.stop();

			//* measurement cpp Stack
			timer_cpp_stack.start();
            cpp_stack.push(random_string);
			timer_cpp_stack.stop();

			measurement_stack << ticker << ";" << timer_own_stack.get_nanoseconds() << ";"
									<< timer_cpp_stack.get_nanoseconds() << "\n";

			std::cout <<  ticker << std::endl;
            ticker++;
		}
	}

    measurement_stack.close();
    std::cout << "Fertig mit stack!" << std::endl;

    std::ofstream measurement_hashmap;
	measurement_hashmap.open("C:/Users/tiliw/OneDrive/Desktop/Uni/2. Semester/POOSE/projektalpha/measurement_hashmap.csv"); //Only works with absolut path
	measurement_hashmap << "Number of values; own hashmap; cpp hashmap\n";

    ticker = 1;
	for (int i = 0; i < 1000000; i++) {
		if (i % 3922 == 0) { //* Excel kann nur 255 Spalten, daher in 79 Schritten bei 20000 Einträgen maximal (20000/79 = etwa 255)

            random_string = rand_str.generate();
            //std::cout << random_string <<std::endl;

			//* Timer for all measurements
			Timer timer_own_hashmap;
			Timer timer_cpp_hashmap;

			//* measurement own hashmap
			timer_own_hashmap.start();
            own_hashmap.add(random_string);
			timer_own_hashmap.stop();

			//* measurement cpp hashmap
			timer_cpp_hashmap.start();
            cpp_hashmap.insert(std::pair<int, string>(i, random_string));
			timer_cpp_hashmap.stop();

			measurement_hashmap << ticker << ";" << timer_own_hashmap.get_nanoseconds() << ";"
									<< timer_cpp_hashmap.get_nanoseconds() << "\n";

			std::cout <<  timer_cpp_hashmap.get_nanoseconds() << std::endl;
            ticker++;
		}
	}

    measurement_hashmap.close();
    std::cout << "Fertig mit hashmap!" << std::endl;

    /*
    std::ofstream measurement_linkedlist;
	measurement_linkedlist.open("C:/Users/tiliw/OneDrive/Desktop/Uni/2. Semester/POOSE/projektalpha/measurement_linkedlist.csv"); //Only works with absolut path
	measurement_linkedlist << "Number of values; own linkedlist; cpp linkedlist\n";

    ticker = 1;
	for (int i = 0; i < 1000000; i++) {
		if (i % 3922 == 0) { //* Excel kann nur 255 Spalten, daher in 79 Schritten bei 20000 Einträgen maximal (20000/79 = etwa 255)

            random_string = rand_str.generate();
            //std::cout << random_string <<std::endl;

			//* Timer for all measurements
			Timer timer_own_linkedlist;
			Timer timer_cpp_linkedlist;

			//* measurement own linkedlist
			timer_own_linkedlist.start();
            own_linkedlist.add_back(random_string);
			timer_own_linkedlist.stop();

			//* measurement cpp linkedlist
			timer_cpp_linkedlist.start();
            cpp_linkedlist.push_back(random_string);
			timer_cpp_linkedlist.stop();

			measurement_linkedlist << ticker << ";" << timer_own_linkedlist.get_nanoseconds() << ";"
									<< timer_cpp_linkedlist.get_nanoseconds() << "\n";

			std::cout <<  timer_cpp_linkedlist.get_nanoseconds() << std::endl;
            ticker++;
		}
	}

    measurement_linkedlist.close();
    std::cout << "Fertig mit linkedlist!" << std::endl;*/

}