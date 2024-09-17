#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;



void borders(int number_of_borders) {
    for (number_of_borders;number_of_borders > 0;number_of_borders--) {
        cout << "_";
    }
    cout << endl;
}
void error_check(int thing_for_check) {
    if (thing_for_check < 1 || thing_for_check>4) {
        cout << "Попробуйте ещё раз.Вводите коректные данные" << endl;
        while (thing_for_check < 1 || thing_for_check>4) {
            cin >> thing_for_check;
            system("cls");
            cout << "Попробуйте ещё раз.Вводите коректные данные" << endl;
            if (thing_for_check > 1 && thing_for_check < 4) {
                system("cls");
                break;
            }
        }
    }

}
void zaglushka() {

}

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
﻿
void check(map <string, int> question, int diff_choise, int& count) {
    cout << "Выбранный вами уровень сложности: " << diff_choise << "." << endl << "Для ответа на вопрос напишите с клавиатуры номер выбранного варианта." << endl;

    for (const auto& i : question) {
        cout << i.first << endl;
        int answer;
        cin >> answer;
        if (i.second == answer) {
            count += 1 * diff_choise;
            cout << "Вы ответили верно! +" << 1 * diff_choise << " баллов" << endl;
        }
        else
            cout << "Вы ответили неверно!" << endl;
    }
    cout << "Игра окончена! \nНабранное вами количество баллов: " << count << endl;
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


void musik_quiz(int diff_choise, int& score) {
    cout << "Добро пожаловать в викторину МУЗЫКА!" << endl;
    map <string, int> question_easy = { {"\tКак называется создатель музыкальных произведений?\n1. Дирижер\n2. Композитор\n3.Режиссер\n4. Исполнитель", 2}, {"\tКак называется жанр тяжелой музыки?\n1. Поп\n2.Рок\n3. Классика\n4. Хип-хоп", 2}, {"\tКак называется группа поющих людей?\n1. Хор\n2. Трио \n3. Квартет\n4. Дуэт", 1}, {"\tДля какого инструмента нужен медиатор?\n1. Скрипка\n2. Балалайка \n3. Кларнет\n4. Гитара", 4} };
    map <string, int> question_average = { {"\tСколько струн у гитары?\n1. 4\n2. 5\n3. 6\n4. 3 ", 3}, {"\tК какой группе инструментов принадлежит труба?\n 1. Медные духовые\n2. Ударные\n3.Струнные\n4. Деревянные духовые", 1}, {"\tКакой музыкальный инструмент является самым большим?\n1.Огран\n2. Труба\n3. Октобас\n4. Рояль", 1}, {"\tКак называют человека, котрый отвечает за разучивание и исполнение музыки?\n1.Режиссер\n2. Дирижер\n3. Композитор\n4. Управляющий", 2} };
    map <string, int> question_average1 = { {"\tНазвание древнейшего жанра музыки\n1. Песня\n2. Классика\n3. Вокальная музыка\n4. Опера", 1}, {"\tКто был глухим композитором?\n1. Моцарт\n2. Бах\n3. Бетховен\n4. Шуберт", 3}, {"\tКак называется пение без музыкального сопровождения?\n1. Романс\n2. Акапелла\n3. Хорал\n4. Речитатив", 2}, {"\tСоздатель балета Лебединое озеро\n1.Чайковский \n2. Корсаков\n3. Рубинштейн\n4. Глинка", 1} };
    map <string, int> question_hard = { {"\tКак называется музыкальный ансамбль, состоящий из 4х человек?\n1. Октет\n2. Квинтет\n3.Нотет\n4. Квартет", 4}, {"\tЧем натирают смычок для скрипки?\n1.Мелом\n2. Канифолью\n3. Жиром\n4. Тальком", 2}, {"\tСколько человек исполняет арию?\n1. 1\n2. 2\n 3. 3\n4. 4", 1}, {"\tИз скольки нот состоит классический нотный стан?\n1. 10\n2. 3\n3. 5\n4. 7", 3} };

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

﻿void travel_quiz(int diff_choise, int& score) {
    cout << "Добро пожаловать в викторину ПУТЕШЕСТВИЯ!" << endl;
    map <string, int> question_easy = { {"\tКакая столица Сербии? \n1.Белград\t2. Вена \n3. Будапешт\t4. Прага", 1}, {"\tКакая столица Японии? \n1. Токио\t2. Пхеньян\n3. Сеул\t4. Дублин", 1}, {"\tКакой страны денежная еденица - Кордоба?\n1. ОАЭ\t2. Никарагуа\n3. Румыния\t4. Турция", 2}, {"\tВ скольких странах на 2023 год официальной валютой является евро?\n1. 9\t2. 12\n3. 20\t4. 6", 3} };
    map <string, int> question_average = { {"\tКакое место в мире по площади занимает Аргентина? \n1. 5\t2. 15\n3. 3\t4. 8", 4}, {"\tС какими странами США граничат своей южной границей?\n1.Муксика, Венесуэла \t2. Мексика\n3.Мексика, Гондурас\t4. Мексика, Аргентина", 2}, {"\t Что занимает большую часть территории Австралии? \n1.моря \t2. леса\n3.пустыни \t4. горы", 3}, {"\tКак называется самое крупное озеро в Германии?\n1. Боденское озеро\t2.Мюриц\n3. Штарнберг-3е\t4. Кимзе", 1} };
    map <string, int> question_average1 = { {"\tКакому государству принадлежит Суэцкий канал? \n1.Сирии\t2. Китаю\n3.ОАЭ\t4. Египту", 4}, {"\tЧто необходимо для прогулки на гондоле? \n1.Весло \t2. Бензин\n3.Педали\t4. Крылья", 1}, {"\tВ какой стране находится самый длинный мост в Европе?\n1.Финляндия\t2. Португалия\n3. Франция\t4. Германия", 2}, {"\tКакой водопад считается самым крупным в мире?\n1.Виктория(Южная Африка) \t2.Анхель (Венесуэлла) \n3.Ниагарский (Америка) \t4. Мраморный водопад (Италия)", 1} };
    map <string, int> question_hard = { {"\tНазовите город, на который претендуют представители трех религий: иудеи, христиане и мусульмане:\n1.Дамаск (Сирия) \t2.Багдад (Ирак) \n3.Иерусалим (Израиль) \t4.Иерихон (Палестина) ", 3}, { "\t Где находится знаменитый Гранд-Базар? \n1.турция \t2. иран\n3. египет\t4. морокко", 1 }, { "\tВ озеро Байкал впадает несколько сотен рек, а вытекает только...\n1. 5\t2. 7 \n3. 2\t4. 1", 1}, {"\t \n1. Название канала, соединяющего Индию и о.Шри-Ланка\t2. Самое глубокое место Марианской впадины\n3.Кратер вулкана в Индонезии \t4.Местные ветры с суточной периодичностью ", 2} };

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

void cinema_quiz(int diff_choice, int& score) {
    cout << "Добро пожаловать в викторину КИНО!" << endl;
    map <string, int> question_easy = { {"\t Что из этого НЕ является жанром кино?\n1. Драмма\t2. Детектив\n3. Представление\t4. Вестерн", 3 }, {"\tЧего не было в первых фильмах?\n1. Актёров\t2. Цвета\n3. Картинки\t4. Сюжета",2 }, {"\tКакой фильм считается самым кассовым фильмом в мире?\n1. Мстители:финал.\t2. Гарри Поттер и Дары смерти: Часть 2.\n3. Титаник.\t4. Аватар.",4 }, {"\tКакой человек ответственнен за написание сценария к фильму?\n1. Сценарист\t2. Режисёр\n3. Оператор\t4. Композитор",1 } };
    map <string, int> question_average = { {"\tКакая американская корпорация была основана в 1923 году?\n1. DreamWorks.\t2. Disney.\n3. Illumination.\t4. Pixar",2 }, {"\tКак называется премия которую ежегодно вручают создателям лучшего кинематографического произведния?\n1. Премия Оскара.\t2. Премия Дарвина.\n3. Премия Гэвина.\t4. Нобелевская премия.",1 }, {"\tПорядок выхода фильмов Звёздные войны:\n1. 7,8,9, - 1,2,3 - 4,5,6. \t2. 1,2,3 - 4,5,6 - 7,8,9.\n3. 4,5,6 - 1,2,3 - 7,8,9.\t4. 1,4,7 - 2,5,8 - 3,6,9.",3 }, {"\tКак называется вымышленный мир какой-либо серии кинофильмов?\n1. Мультивселенная.\t2. Киновселенная.\n3. Кинолента.\t4. Серия фильмов. ",2 } };
    map <string, int> question_average1 = { {"\tНа какую из перечисленных видеоигр существует киноадаптация?\n1. Battlefield.\t2. Uncharted.\n3. Batman: Arkham.\t4. Ghost of Tsushima.",2 }, {"\tКакое произведение выиграло премию оскар в 2023 году?\n1. Аватар: Путь воды.\t2. Король Ричард.\n3. Всё везде и сразу.\t4. Топ Ган: Мавэрик.",3 }, {"Назовите режисёра фильма Волк с Уолл Стрит\n1. Мартин Скорсезе.\t2. Стивен Спилберг.\n3. Дэвид Финчер.\t4. Вууди Аллен.",1 }, {"Сколько длится фильм Интерстеллар?\n1. 2 ч 36 мин.\t2. 2 ч 23 мин.\n3. 2 ч 49 мин.\t4. 2 ч 51 мин.",3 } };
    map <string, int> question_impossible = { {"\tКак звали художника и аниматора, который cоздал тестовый вариант фильма Человек-паук: Через вселенные\n\t и снял эпизод \"Свидетель\" для сериала Любовь. Смерть. Роботы?\n1. Рут Де Йонг.\t2. Альберто Миэльго.\n3. Питер Ламонт.\t4. Оливер Томас.",2 }, {"\tКак зовут главного героя в фильме \"Первому Игроку Приготовиться\"?\n1. Кайл Крэйн\t2. Кевин Джейкобс.\n3. Огден Морроу.\t4. Уэйд Уоттс.",4 }, {"\tВыберите самый провальный фильм 2024 года(на текущий момент)\n1. Мадам Паутина.\t2. Девушка Миллера.\n3. Borderlands.\t4. История зла.", 4}, {"\tКакие кассовые сборы у фильма аватар?\n1. 2 567 123 381 долларов.\t2. 3 146 784 295 долларов.\n3. 2 789 679 794 долларов.\t4. 1 000 000 000долларов.",3 } };

    switch (diff_choice) {
    case 1: {
        check(question_easy, diff_choice, score);
        break;
    }
    case 2: {
        check(question_average, diff_choice, score);
        break;
    }
    case 3: {
        check(question_average1, diff_choice, score);
        break;
    }
    case 4: {
        check(question_impossible, diff_choice, score);
        break;
    }
    default: {
        cout << "Такого уровня сложности нет(" << endl;
        break;
    }
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

int main()
{
    string nicknames;
    int player_choice;
    int diff_choice;
    int score = 0;
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color 0B");

    while (1){
        borders(20);
        cout << "Добро пожаловать!" << endl;
        cout << "введите имя: ";
        cin >> nicknames;


        cout << "Выберите категорию: ""\n" << "1-кино 2-музыка 3-игры 4-путешествия" << endl;
        cin >> player_choice;

        error_check(player_choice);

        cout << "Выберите сложность: ""\n" << "1 - x1 2 - x2 3 - x3 4 - x4" << endl;
        cin >> diff_choice;
        error_check(diff_choice);
        switch (player_choice) {
        case 1: {
            cinema_quiz(diff_choice, score);
            break;
        }
        case 2: {
            musik_quiz(diff_choice, score);
            break;
        }
        case 3: {
            game_quiz(diff_choice, score);
            break;
        }
        case 4: {
            travel_quiz(diff_choice, score);
            break;
        }
        default:
            cout << "Такого уровня сложности нет(" << endl;
            break;
        }
       

        int retry;
        cout << "хотите сыграть ещё?""\n""1 - да. 2 - нет" << endl;
        cin >> retry;
        if (retry == 1) {
            retry = 0;
            score = 0;
            player_choice = 0;
            diff_choice = 0;
        }
        else {
            break;
        }

    }

}
