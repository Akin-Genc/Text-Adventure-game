#include "StartScreen.hpp"

void StartScreen::Display() {
    std::cout << "\033[38;2;194;178;128m"; // RGB values for desert sand color

    std::cout << "Welcome to the vast deserts of Arabia!\n";
    std::cout << "\nEmbark on a perilous journey through the shifting sands and ancient ruins to retrieve a legendary artifact.\n";
    std::cout << "In a land where mirages deceive and the sun scorches the earth, a brave explorer named Amir rises.\n";
    std::cout << "With determination in his heart, Amir sets out to uncover the fabled Diamond of the Desert.\n";
    std::cout << "Join Amir on his quest to traverse the unforgiving terrain and unlock the secrets hidden within Arabia's sands.\n";
 

    std::cout << "\033[38;2;0;255;0m"; // RGB values for light green color
    std::cout << "\nPress 'S'";

    std::cout << "\033[0m"; // Reset text color

    std::cout << " to begin the adventure or ";

    std::cout << "\033[38;2;255;100;100m"; // RGB values for light red color
    std::cout << "'Q'";
    std::cout << "\033[0m"; // Reset text color

    std::cout << " to quit.\n";

 
    std::cout << "  \n";
     
    // Reset text color
    std::cout << "\033[0m";

}

char StartScreen::GetInput() {
    char choice;
    std::cin >> choice;
    return choice;
}