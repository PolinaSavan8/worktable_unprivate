#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>

// *** Добавление функции для перевода Русской строки в Английскую для внутренней логики ***
std::string translateToEnglish(const std::string& russianChoice) {
    if (russianChoice == "камень") return "rock";
    if (russianChoice == "ножницы") return "scissors";
    if (russianChoice == "бумага") return "paper";
    return ""; // Вернет пустую строку для невалидного ввода
}
// *****************************************************************************************

/**
 * @brief Plays one round of Rock, Paper, Scissors game.
 * * @param userChoice The choice made by the user (must be "rock", "paper", or "scissors").
 * @param computerChoice The choice made by the computer.
 * @return std::string The result of the game: "You won!", "You lost.", or "It's a draw.".
 */
std::string playGame(const std::string& userChoice, const std::string& computerChoice) {
    // Define winning rules: key (player's choice) beats value (opponent's choice)
    static const std::map<std::string, std::string> winningRules = {
        {"rock", "scissors"},
        {"scissors", "paper"},
        {"paper", "rock"}
    };

    if (userChoice == computerChoice) {
        return "It's a draw.";
    }

    // Check if the user's choice is a winning key and if it beats the computer's choice.
    auto it = winningRules.find(userChoice);
    if (it != winningRules.end() && it->second == computerChoice) {
        return "You won!";
    }

    // If it's not a draw and not a win, it must be a loss.
    return "You lost.";
}

/**
 * @brief Main function for the Rock, Paper, Scissors game.
 * * Handles user input, computer choice generation, and outputs the result.
 */
int main() {
    // Setting up for random choice generation (C++11 standard way)
    std::random_device rd;
    std::mt19937 gen(rd());
    // *** Теперь choices используются только для генерации компьтера, что корректно ***
    const std::vector<std::string> choices = { "rock", "paper", "scissors" };

    // Create a distribution to pick an index from the choices vector
    std::uniform_int_distribution<> distrib(0, choices.size() - 1);

    std::string userInputStr; // Считываем ввод в строковую переменную

    // Вектор допустимых русских слов для валидации ввода
    const std::vector<std::string> validRussianChoices = { "камень", "ножницы", "бумага" };

    std::cout << "Введите ваш выбор (камень, ножницы, бумага): ";
    std::cin >> userInputStr;

    // Convert input to lowercase (might not work well for Cyrillic without special locale settings)
    std::transform(userInputStr.begin(), userInputStr.end(), userInputStr.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // Simple validation to check if the input is valid (against Russian words)
    auto it = std::find(validRussianChoices.begin(), validRussianChoices.end(), userInputStr);
    if (it == validRussianChoices.end()) {
        std::cerr << "Ошибка: Недопустимый ввод. Пожалуйста, введите 'камень', 'ножницы' или 'бумага'." << std::endl;
        return 1; // Exit with error code
    }

    // --- Game Logic ---
    // 1. Computer makes a choice (in English)
    std::string computerChoice = choices[distrib(gen)];

    // 2. *** Преобразуем ввод пользователя в английский перед передачей в playGame ***
    std::string userChoice = translateToEnglish(userInputStr);

    // 3. Translate the computer's choice for output in Russian
    std::string compDisplay;
    if (computerChoice == "rock") compDisplay = "камень";
    else if (computerChoice == "paper") compDisplay = "бумага";
    else compDisplay = "ножницы";

    std::cout << "Компьютер выбрал: " << compDisplay << std::endl;

    // 4. Get the result using the dedicated function
    std::string result = playGame(userChoice, computerChoice);

    std::cout << result << std::endl;

    return 0;
}