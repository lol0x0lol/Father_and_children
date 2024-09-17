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

