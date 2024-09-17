#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int diff_choise;

bool compare_scores(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

void addNickname(string*& array, int& size, string newName) {
    size++;
    string* newArr = new string[size];

    for (int i = 0; i < size - 1; i++)
    {
        newArr[i] = array[i];
    }
    newArr[size - 1] = newName;
    delete[] array;
    array = newArr;
}

void check(map <string, int> question, int diff_choise, int& score) {
    cout << "Выбранный вами уровень сложности: " << diff_choise << "." << endl << "Для ответа на вопрос напишите с клавиатуры номер выбранного варианта." << endl;

    for (const auto& i : question) {
        cout << i.first << endl;
        int answer;
        cin >> answer;
        if (i.second == answer) {
            score += 1 * diff_choise;
            cout << "Вы ответили верно! +" << 1 * diff_choise << " баллов" << endl;
        }
        else
            cout << "Вы ответили неверно!" << endl;
    }
    cout << "Игра окончена! \nНабранное вами количество баллов: " << score << endl;
}

void game_quiz(int diff_choise, int& score) {
    cout << "Добро пожаловать в викторину ИГРЫ!" << endl;
    map <string, int> question_easy = { {"\tВ какой игре был город - Сити 17? \n1. F.E.A.R. 3\t2. TimeShift\n3. Bioshock\t4. Half Life 2", 4}, {"\tСколько частей Fallout +(спин-оффы)? \n1. 5\t2. 9\n3. 4\t4. 6", 2}, {"\tКакая студия разработала The Last of Us?\n1. Quantic: Dream\t2. Bend Studio\n3. SCE Santa Monica Studio\t4. Naughty Dog", 4}, {"\tСколько было выпущено частей The Elder Scrolls? (+ спин - оффы,для мобилок)\n1. 14\t2. 9\n3. 16\t4. 6", 1} };
    map <string, int> question_average = { {"\tПервый выпуск Стима \n1. 1999 г.\t2. 2003 г.\n3. 2000 г.\t4. 2005 г.", 2}, {"\tСамая прибыльная условно-бесплатная игра 2020 года \n1. Honor of Kings\t2. Peacekeeper Elite\n3. Pokemon GO\t4. League of Legends", 1}, {"\tВ какой игре можно использовать кошачих за место глушителя ?\n1. Hatred\t2. Bulletstorm\n3. Carmageddon\t4. Postal 2", 4}, {"\tЛучшая игра за все время по версии metacritic ? на PS4 \n1. The Last of Us\t2. God of War\n3. Grand Theft Auto V\t4. Red Dead Redemption 2", 4} };
    map <string, int> question_average1 = { {"\tСамая долго разрабатываемая игра ? \n1. GTA 5 (2013)\t2. Cyberpunk 2077 (2020)\n3. Prey (2006)\t4. Mount & Blade II Bannerlord (2020)", 3}, {"\tУбери лишнее \n1. Counter-Strike: Global Offensive\t2. Dota 2\n3. Team Fortress 2\t4. Payday 2", 4}, {"\tДата выхода Аmong us ? \n1. в июне 2018 г.\t2. в сентябре 2020 г.\n3. в августе 2016 г.\t4. в июне 2019 г.", 1}, {"\tЛучшая игра за все время по версии metacritic ? на PC \n1. Half Life 2\t\t2. Grand Theft Auto V\n3. Disco Elysium\t4. Mass Effect 2", 3} };
    map <string, int> question_hard = { {"\tЛучшая игра за все время по версии metacritic ? на всех платформах \n1. The Legend of Zelda: Ocarina of Time\t2. Grand Theft Auto IV\n3. Super Mario Galaxy\t4. Soulcalibur", 1}, { "\tКогда была выпущена первая Fifa ? \n1. 1993 г.\t2. 2000 г.\n3. 1999 г.\t4. 1990 г.", 1 }, { "\tКампания Valve сообщила, сколько % всех приобретенных игр\n\tв сервисе Steam никогда не запускалась. \n1. 4\t2. 49\n3. 37\t4. 12", 3 }, { "\tВ какой стране находится студия ,которая выпустила Disco Elysium ? \n1. Исландия\t2. Эстония\n3. Италия\t4. Франция", 2} };

    switch (diff_choise) {
    case 1: {
        check(question_easy, diff_choise, score);
        break;
    }
    case 2: {
        check(question_average, diff_choise, score);
        break;
    }
    case 3: {
        check(question_average1, diff_choise, score);
        break;
    }
    case 4: {
        check(question_hard, diff_choise, score);
        break;
    }
    default:
        cout << "Такого уровня сложности нет(" << endl;
        break;
    }
}

void countLeaderboard(map<string, int>& leaderboard, string nickname, int count, string*& array, int& size) {
    remove("leaderboard.txt");
    ofstream out("leaderboard.txt", ios::app);
    if (leaderboard.find(nickname) == leaderboard.end()) {
        leaderboard.emplace(nickname, count);
    }
    else { leaderboard[nickname]=count; }
    
    
    int maxCount = 0;
    string maxNickname;

    vector<pair<string, int>> rankings;
    for (const auto& kv : leaderboard) {
        rankings.push_back({ kv.first, kv.second });
    }

    sort(rankings.begin(), rankings.end(), compare_scores);

    if (out.is_open()) {
        for (const auto& r : rankings) {
            out << r.first << " - " << r.second << endl;
        }
    }

    out.close();
}