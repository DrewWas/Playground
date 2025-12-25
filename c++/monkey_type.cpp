#include <array>
#include <string>
#include <iostream>
#include <thread>



int main() {

   //std::string inputs;
   //std::cout << "Type now: \n";
   //std::getline(std::cin, inputs);

    for (int i = 5; i > 0; i--)  {
        std::cout << "\rCountdown: " << i << " " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

   std::cout << "\nDone!\n";



   return 0;
}

// Instead of this just keep a master timer that prints at certain intervals or ends program when time is up





